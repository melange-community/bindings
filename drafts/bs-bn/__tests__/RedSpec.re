open Jest;

let testMethod = (name, fn) =>
  describe(
    name ++ " method",
    ExpectJs.(
      () => {
        [
          ((a, b) => a |> Bn.redAdd(b), "97"),
          ((a, b) => a |> Bn.redSub(b), "149"),
          ((a, b) => b |> Bn.redSub(a), "108"),
          (
            (a, b) => {
              a |> Bn.redIAdd(b);
              a;
            },
            "97"
          ),
          (
            (a, b) => {
              a |> Bn.redISub(b);
              a;
            },
            "149"
          ),
          (
            (a, b) => {
              b |> Bn.redISub(a);
              b;
            },
            "108"
          )
        ]
        |> List.iter(((op, r)) =>
             test("supports add, iadd, sub, isub operations", () => {
               let p = Bn.fromFloat(257.);
               let m = fn(p);
               let a = Bn.fromFloat(123.) |> Bn.toRed(m);
               let b = Bn.fromFloat(231.) |> Bn.toRed(m);
               expect(op(a, b) |> Bn.fromRed |> Bn.toString) |> toBe(r);
             })
           );
        [
          (m, a) => (
            a |> Bn.toRed(m) |> Bn.redPow(Bn.fromFloat(0.)) |> Bn.fromRed,
            Bn.fromFloat(1.)
          ),
          (m, a) => (
            a |> Bn.toRed(m) |> Bn.redPow(Bn.fromFloat(3.)) |> Bn.fromRed,
            a |> Bn.sqr |> Bn.mul(a)
          ),
          (m, a) => (
            a |> Bn.toRed(m) |> Bn.redPow(Bn.fromFloat(8.)) |> Bn.fromRed,
            a |> Bn.sqr |> Bn.sqr |> Bn.sqr
          ),
          (m, a) => (
            a |> Bn.toRed(m) |> Bn.redPow(Bn.fromFloat(9.)) |> Bn.fromRed,
            a |> Bn.sqr |> Bn.sqr |> Bn.sqr |> Bn.mul(a)
          ),
          (m, a) => (
            a |> Bn.toRed(m) |> Bn.redPow(Bn.fromFloat(17.)) |> Bn.fromRed,
            a |> Bn.sqr |> Bn.sqr |> Bn.sqr |> Bn.sqr |> Bn.mul(a)
          ),
          (m, a) => (
            a
            |> Bn.toRed(m)
            |> Bn.redPow(Bn.fromString(~base=16, "deadbeefabbadead"))
            |> Bn.fromRed,
            Bn.fromString(
              ~base=16,
              "3aa0e7e304e320b68ef61592bcb00341866d6fa66e11a4d6"
            )
          )
        ]
        |> List.iter(op =>
             test("supports pow and mul operations", () => {
               let p192 =
                 Bn.fromString(
                   ~base=16,
                   "fffffffffffffffffffffffffffffffeffffffffffffffff"
                 );
               let m = fn(p192);
               let a = Bn.fromFloat(123.);
               let (left, right) = op(m, a);
               expect(Bn.cmp(left, right)) |> toBe(Equality.Equal);
             })
           );
        {
          let p = Bn.fromFloat(263.);
          let m = fn(p);
          let q = Bn.fromFloat(11.);
          let qr = ref(Bn.redSqrt(q |> Bn.toRed(m)));
          test("supports sqrtm operations", () =>
            expect(qr^ |> Bn.redSqr |> Bn.fromRed |> Bn.cmp(q))
            |> toBe(Equality.Equal)
          );
          qr := Bn.redSqrt(q |> Bn.toRed(m));
          test("supports sqrtm operations 2", () =>
            expect(qr^ |> Bn.redSqr |> Bn.fromRed |> Bn.cmp(q))
            |> toBe(Equality.Equal)
          );
        };
        {
          let p =
            Bn.fromString(
              ~base=16,
              "fffffffffffffffffffffffffffffffeffffffffffffffff"
            );
          let m = fn(p);
          let q = Bn.fromFloat(13.);
          let qr = ref(Bn.redSqrt(q |> Bn.toRed(m)));
          test("supports sqrtm operations 3", () =>
            expect(qr^ |> Bn.redSqr |> Bn.fromRed |> Bn.cmp(q))
            |> toBe(Equality.Equal)
          );
          qr := Bn.redSqrt(q |> Bn.toRed(m));
          test("supports sqrtm operations 4", () =>
            expect(qr^ |> Bn.redSqr |> Bn.fromRed |> Bn.cmp(q))
            |> toBe(Equality.Equal)
          );
        };
        {
          /* // Tonelli-shanks */
          let p = Bn.fromFloat(13.);
          let m = fn(p);
          let q = Bn.fromFloat(10.) |> Bn.toRed(m);
          test("supports sqrtm operations 5", () =>
            expect(q |> Bn.redSqrt |> Bn.fromRed |> Bn.toString) |> toBe("7")
          );
        };
        test("supports invm operations", () => {
          let p = Bn.fromFloat(257.);
          let m = fn(p);
          let a = Bn.fromFloat(3.) |> Bn.toRed(m);
          let b = Bn.redInvm(a);
          expect(a |> Bn.redMul(b) |> Bn.fromRed |> Bn.toString(~base=16))
          |> toBe("1");
        });
        test("supports imul operations", () => {
          let p =
            Bn.fromString(
              ~base=16,
              "fffffffffffffffffffffffffffffffeffffffffffffffff"
            );
          let m = fn(p);
          let a = Bn.fromString(~base=16, "deadbeefabbadead");
          let b = Bn.fromString(~base=16, "abbadeadbeefdead");
          let c = a |> Bn.mul(b) |> Bn.mod_(p);
          let ar = a |> Bn.toRed(m);
          ar |> Bn.redIMul(b |> Bn.toRed(m));
          expect(ar |> Bn.fromRed |> Bn.toString(~base=16))
          |> toBe(c |> Bn.toString(~base=16));
        });
        test("supports pow(base, 0) == 1", () => {
          let base = Bn.fromFloat(256.) |> Bn.toRed(Bn.redWithPrime(`k256));
          let exponent = Bn.fromFloat(0.);
          let result = base |> Bn.redPow(exponent);
          expect(result |> Bn.fromRed |> Bn.toString) |> toBe("1");
        });
        test("supports shl numbers", () => {
          let base = Bn.fromFloat(256.) |> Bn.toRed(Bn.redWithPrime(`k256));
          let result = base |> Bn.redShl(1);
          expect(result |> Bn.fromRed |> Bn.toString) |> toBe("512");
        });
        test("reduces when converting to red", () => {
          let p = Bn.fromFloat(257.);
          let m = fn(p);
          let a = Bn.fromFloat(5.) |> Bn.toRed(m);
          expect(
            {
              a |> Bn.redISub(Bn.fromFloat(512.) |> Bn.toRed(m));
              a |> Bn.redISub(Bn.fromFloat(512.) |> Bn.toRed(m));
              a |> Bn.fromRed |> Bn.toString;
            }
          )
          |> toBe("9");
        });
        test("supports redNeg and zero value", () => {
          let a = Bn.fromFloat(0.) |> Bn.toRed(Bn.redWithPrime(`k256)) |> Bn.redNeg;
          expect(a |> Bn.fromRed |> Bn.isZero) |> toBe(true);
        });
        test("does not allow modulus <= 1 - test 1", () => {
          expect(() => Bn.red(Bn.fromFloat(0.))) |> toThrow;
        });
        test("does not allow modulus <= 1 - test 2", () => {
          expect(() => Bn.red(Bn.fromFloat(1.))) |> toThrow;
        });
      }
    )
  );

testMethod("Plain", Bn.red);

testMethod("Montgomery", Bn.mont);

/* TODO: Pseudo-Mersenne Primes tests */
