open Jest;

let () =
  describe(
    "add",
    ExpectJs.(
      () => {
        test("adds numbers", () =>
          expect(
            Bn.fromFloat(14.)
            |> Bn.add(Bn.fromFloat(26.))
            |> Bn.toString(~base=16)
          )
          |> toBe("28")
        );
        test("adds numbers case 2", () => {
          let k = Bn.fromFloat(float_of_int(0x1234));
          let r = ref(k);
          for (_ in 0 to 256) {
            r := Bn.add(k, r^);
          };
          expect(Bn.toString(~base=16, r^)) |> toBe("125868");
        });
        test("handles carry properly (in-place)", () => {
          let k = Bn.fromString(~base=16, "abcdefabcdefabcdef");
          let r = Bn.fromString(~base=16, "deadbeef");
          for (_ in 0 to 256) {
            Bn.iadd(k, r);
          };
          expect(Bn.toString(~base=16, r)) |> toBe("ac79bd9b79be7a277bde");
        });
        test("does positive + negative", () => {
          let a = Bn.fromString(~base=16, "abcd");
          let b = Bn.fromString(~base=16, "-abce");
          Bn.iadd(a, b);
          expect(b |> Bn.toString(~base=16)) |> toBe("-1");
        });
      }
    )
  );

let () =
  describe(
    "iaddn",
    ExpectJs.(
      () => {
        test("allows a sign change", () => {
          let a = Bn.fromFloat(-100.);
          Bn.iaddn(200., a);
          expect(a |> Bn.toString) |> toBe("100");
        });
        test("adds a negative number", () => {
          let a = Bn.fromFloat(-100.);
          Bn.iaddn(-200., a);
          expect(a |> Bn.toString) |> toBe("-300");
        });
        test("allows neg + pos with big number", () => {
          let a = Bn.fromFloat(~base=10, -1000000000.);
          Bn.iaddn(200., a);
          expect(a |> Bn.toString) |> toBe("-999999800");
        });
        test("carries limb", () => {
          let a = Bn.fromString(~base=16, "3ffffff");
          Bn.iaddn(1., a);
          expect(a |> Bn.toString(~base=16)) |> toBe("4000000");
        });
        test("throws error with num eq 0x4000000", () =>
          expect(() =>
            Bn.fromFloat(0.) |> Bn.iaddn(float_of_int(0x4000000))
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "sub",
    ExpectJs.(
      () => {
        test("subtracts small numbers", () => {
          let a = Bn.fromFloat(26.);
          expect(a |> Bn.sub(Bn.fromFloat(14.)) |> Bn.toString(~base=16))
          |> toBe("c");
        });
        test("subtracts small numbers 2", () => {
          let a = Bn.fromFloat(14.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("-c");
        });
        test("subtracts small numbers 3", () => {
          let a = Bn.fromFloat(26.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("0");
        });
        test("subtracts small numbers 4", () => {
          let a = Bn.fromFloat(-26.);
          expect(a |> Bn.sub(Bn.fromFloat(26.)) |> Bn.toString(~base=16))
          |> toBe("-34");
        });
        let a =
          Bn.fromString(
            ~base=16,
            "31ff3c61db2db84b9823d320907a573f6ad37c437abe458b1802cda041d6384a7d8daef41395491e2"
          );
        let b =
          Bn.fromString(
            ~base=16,
            "6f0e4d9f1d6071c183677f601af9305721c91d31b0bbbae8fb790000"
          );
        let r =
          Bn.fromString(
            ~base=16,
            "31ff3c61db2db84b9823d3208989726578fd75276287cd9516533a9acfb9a6776281f34583ddb91e2"
          );
        test("subtracts big numbers", () =>
          expect(a |> Bn.sub(b) |> Bn.cmp(r)) |> toBe(Equality.Equal)
        );
        test("subtracts numbers in place", () => {
          let c = Bn.clone(b);
          Bn.isub(a, c);
          expect(c |> Bn.neg |> Bn.cmp(r)) |> toBe(Equality.Equal);
        });
        test("subtracts with carry", () => {
          let a = Bn.fromString(~base=16, "12345");
          let b = Bn.fromString(~base=16, "1000000000000");
          Bn.isub(b, a);
          expect(a |> Bn.toString(~base=16)) |> toBe("-fffffffedcbb");
        });
      }
    )
  );

let () =
  describe(
    "isubn",
    ExpectJs.(
      () => {
        test("subtracts negative number", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681b"
            );
          Bn.isubn(-1., a);
          expect(a |> Bn.toString(~base=16))
          |> toBe(
               "7fffffffffffffffffffffffffffffff5d576e7357a4501ddfe92f46681c"
             );
        });
        test("works for positive numbers", () => {
          let a = Bn.fromFloat(-100.);
          Bn.isubn(200., a);
          expect(a |> Bn.toString) |> toBe("-300");
        });
        test("does not allow a sign change", () => {
          let a = Bn.fromFloat(-100.);
          Bn.isubn(-200., a);
          expect(a |> Bn.toString) |> toBe("100");
        });
        test("changes sign on small numbers at 0", () => {
          let a = Bn.fromFloat(0.);
          expect(a |> Bn.subn(2.) |> Bn.toString) |> toBe("-2");
        });
        test("changes sign on small numbers at 1", () => {
          let a = Bn.fromFloat(1.);
          expect(a |> Bn.subn(2.) |> Bn.toString) |> toBe("-1");
        });
        test("throws error with num eq 0x4000000", () => {
          let a = Bn.fromFloat(0.);
          expect(() =>
            Bn.isubn(float_of_int(0x4000000), a)
          ) |> toThrow;
        });
      }
    )
  );

let testMethod = (name, mul) =>
  describe(
    name,
    ExpectJs.(
      () => {
        let offsets = [
          (1, "smallMulTo"),
          (250, "comb10MulTo"),
          (1000, "bigMulTo"),
          (15000, "jumboMulTo")
        ];
        let mulTests = [
          (x => mul(x, x) |> Bn.isNeg, false),
          (x => mul(x, Bn.neg(x)) |> Bn.isNeg, true),
          (x => mul(Bn.neg(x), x) |> Bn.isNeg, true),
          (x => mul(Bn.neg(x), Bn.neg(x)) |> Bn.isNeg, false)
        ];
        List.iter2(
          ((offset, name), (mulTest, mulTestResult)) =>
            test(
              "multiplies numbers of different signs - " ++ name,
              () => {
                let a = Bn.fromFloat(1.);
                Bn.ishln(offset, a);
                expect(mulTest(a)) |> toBe(mulTestResult);
              }
            ),
          offsets,
          mulTests
        );
        test("multiplies with carry", () => {
          let n = Bn.fromFloat(float_of_int(0x1001));
          let r = ref(n);
          for (_ in 0 to 3) {
            r := Bn.mul(n, r^);
          };
          expect(r^ |> Bn.toString(~base=16)) |> toBe("100500a00a005001");
        });
        test("multiplies big numbers", () => {
          let n =
            Bn.fromString(
              ~base=16,
              "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"
            );
          expect(Bn.mul(n, n) |> Bn.toString(~base=16))
          |> toBe(
               "39e58a8055b6fb264b75ec8c646509784204ac15a8c24e05babc9729ab9"
               ++ "b055c3a9458e4ce3289560a38e08ba8175a9446ce14e608245ab3a9"
               ++ "978a8bd8acaa40"
             );
        });
        test("multiplies neg number on 0", () =>
          expect(
            Bn.mul(
              Bn.fromString("-100000000000"),
              Bn.fromString("3") |> Bn.div(Bn.fromString("4"))
            )
            |> Bn.toString(~base=16)
          )
          |> toBe("0")
        );
      }
    )
  );

testMethod("mul", Bn.mul);

testMethod("mulf", Bn.mulf);

let () =
  describe(
    "imul",
    ExpectJs.(
      () => {
        test("multiplies numbers in place", () => {
          let a = Bn.fromString(~base=16, "abcdef01234567890abcd");
          let b = Bn.fromString(~base=16, "abcdef01234567890abcd");
          let c = Bn.mul(b, a);
          Bn.imul(b, a);
          expect(a |> Bn.toString(~base=16))
          |> toBe(c |> Bn.toString(~base=16));
        });
        test("multiplies large numbers in place", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "abcdef01234567890abcd214a25123f512361e6d236"
            );
          let b =
            Bn.fromString(
              ~base=16,
              "deadbeefa551edebabba8121234fd21bac0341324dd"
            );
          let c = Bn.mul(b, a);
          Bn.imul(b, a);
          expect(a |> Bn.toString(~base=16))
          |> toBe(c |> Bn.toString(~base=16));
        });
        test("multiplies by 0", () => {
          let a = Bn.fromString(~base=16, "abcdef01234567890abcd");
          let b = Bn.fromString(~base=16, "0");
          let c = Bn.mul(b, a);
          Bn.imul(b, a);
          expect(a |> Bn.toString(~base=16))
          |> toBe(c |> Bn.toString(~base=16));
        });
        test("regresses mul big numbers in-place", () => {
          let qs = Fixtures.DhGroups.P17.qs;
          let q = Bn.fromString(~base=16, Fixtures.DhGroups.P17.q);
          Bn.isqr(q);
          expect(q |> Bn.toString(~base=16)) |> toBe(qs);
        });
      }
    )
  );

let () =
  describe(
    "muln",
    ExpectJs.(
      () => {
        test("multiplies number by small number", () => {
          let a = Bn.fromString(~base=16, "abcdef01234567890abcd");
          let b = Bn.fromString(~base=16, "dead");
          let c = Bn.mul(b, a);
          expect(Bn.muln(float_of_int(0xdead), a) |> Bn.toString(~base=16))
          |> toBe(c |> Bn.toString(~base=16));
        });
        test("throws with num eq 0x4000000", () =>
          expect(() =>
            Bn.fromFloat(0.) |> Bn.imuln(float_of_int(0x4000000))
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "pow",
    ExpectJs.(
      () =>
        test("raises number to the power", () => {
          let a = Bn.fromString(~base=16, "ab");
          let b = Bn.fromString(~base=10, "13");
          let c = Bn.pow(b, a);
          expect(c |> Bn.toString(~base=16))
          |> toBe("15963da06977df51909c9ba5b");
        })
    )
  );

let () =
  describe(
    "div",
    ExpectJs.(
      () => {
        [
          (256, 10, 25),
          ((-256), 10, (-25)),
          (256, (-10), (-25)),
          ((-256), (-10), 25)
        ]
        |> List.iter(((x, y, r)) =>
             test("divides small numbers (<=26 bits)", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               let c = Bn.div(b, a);
               expect(c |> Bn.toString(~base=10)) |> toBe(string_of_int(r));
             })
           );
        [
          ("1222222225255589", "611111124969028", "1"),
          ("-1222222225255589", "611111124969028", "-1"),
          ("1222222225255589", "-611111124969028", "-1"),
          ("-1222222225255589", "-611111124969028", "1"),
          ("611111124969028", "1222222225255589", "0"),
          ("-611111124969028", "1222222225255589", "0"),
          ("611111124969028", "-1222222225255589", "0"),
          ("-611111124969028", "-1222222225255589", "0")
        ]
        |> List.iter(((x, y, r)) =>
             test("divides large numbers (>53 bits)", () => {
               let a = Bn.fromString(x);
               let b = Bn.fromString(y);
               let c = Bn.div(b, a);
               expect(c |> Bn.toString(~base=10)) |> toBe(r);
             })
           );
        [
          ("69527932928", "16974594", "fff"),
          ("-69527932928", "16974594", "-fff")
        ]
        |> List.iter(((x, y, r)) =>
             test("divides dec numbers", () => {
               let a = Bn.fromString(x);
               let b = Bn.fromString(y);
               let c = Bn.div(b, a);
               expect(c |> Bn.toString(~base=16)) |> toBe(r);
             })
           );
        test("divides hex numbers", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "39e58a8055b6fb264b75ec8c646509784204ac15a8c24e05babc9729ab9"
              ++ "b055c3a9458e4ce3289560a38e08ba8175a9446ce14e608245ab3a9"
              ++ "978a8bd8acaa40"
            );
          let b =
            Bn.fromString(
              ~base=16,
              "79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"
            );
          expect(Bn.div(b, a) |> Bn.toString(~base=16))
          |> toBe(b |> Bn.toString(~base=16));
        });
      }
    )
  );

let () =
  describe(
    "idivn",
    ExpectJs.(
      () =>
        [
          ("10", 3., "5", 16),
          ("12", 3., "6", 16),
          ("10000000000000000", 3., "3333333333333333", 10),
          (
            "100000000000000000000000000000",
            3.,
            "33333333333333333333333333333",
            10
          )
        ]
        |> List.iter(((x, n, r, base)) =>
             test("divides numbers in-place", () => {
               let a = Bn.fromString(~base, x);
               Bn.idivn(n, a);
               expect(a |> Bn.toString(~base)) |> toBe(r);
             })
           )
    )
  );

let () =
  describe(
    "divRound",
    ExpectJs.(
      () => {
        [
          (9, 20, 0),
          (10, 20, 1),
          (150, 20, 8),
          (149, 20, 7),
          (149, 17, 9),
          (144, 17, 8),
          ((-144), 17, (-8))
        ]
        |> List.iter(((x, y, r)) =>
             test("divides numbers with rounding", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               expect(Bn.divRound(b, a) |> Bn.toString)
               |> toBe(string_of_int(r));
             })
           );
        test("returns 1 on exact division", () => {
          let a = Bn.fromFloat(144.);
          let b = Bn.fromFloat(144.);
          expect(Bn.divRound(b, a) |> Bn.toString) |> toBe("1");
        });
      }
    )
  );

let () =
  describe(
    "mod",
    ExpectJs.(
      () => {
        [
          (256, 10, 6),
          ((-256), 10, (-6)),
          (256, (-10), 6),
          ((-256), (-10), (-6)),
          (10, 256, 10),
          ((-10), 256, (-10)),
          (10, (-256), 10),
          ((-10), (-256), (-10))
        ]
        |> List.iter(((x, y, r)) =>
             test("modulos small numbers (<=26 bits)", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               expect(Bn.mod_(b, a) |> Bn.toString) |> toBe(string_of_int(r));
             })
           );
        [
          ("1222222225255589", "611111124969028", "611111100286561"),
          ("-1222222225255589", "611111124969028", "-611111100286561"),
          ("1222222225255589", "-611111124969028", "611111100286561"),
          ("-1222222225255589", "-611111124969028", "-611111100286561"),
          ("611111124969028", "1222222225255589", "611111124969028"),
          ("-611111124969028", "1222222225255589", "-611111124969028"),
          ("611111124969028", "-1222222225255589", "611111124969028"),
          ("-611111124969028", "-1222222225255589", "-611111124969028")
        ]
        |> List.iter(((x, y, r)) =>
             test("modulos large numbers (>53 bits)", () => {
               let a = Bn.fromString(x);
               let b = Bn.fromString(y);
               expect(Bn.mod_(b, a) |> Bn.toString) |> toBe(r);
             })
           );
        [("10", "256", "a"), ("69527932928", "16974594", "102f302")]
        |> List.iter(((x, y, r)) =>
             test("modulos numbers 1", () => {
               let a = Bn.fromString(x);
               let b = Bn.fromString(y);
               expect(Bn.mod_(b, a) |> Bn.toString(~base=16)) |> toBe(r);
             })
           );
        [
          (178, 10, 17, 8, 8),
          ((-178), 10, (-17), (-8), 2),
          (178, (-10), (-17), 8, 8),
          ((-178), (-10), 17, (-8), 2),
          ((-4), (-3), 1, (-1), 2)
        ]
        |> List.iter(((x, y, rDiv, rMod, rUmod)) => {
             let a = Bn.fromFloat(float_of_int(x));
             let b = Bn.fromFloat(float_of_int(y));
             test("modulos numbers 2 - div", () =>
               expect(Bn.div(b, a) |> Bn.toNumber) |> toBe(float_of_int(rDiv))
             );
             test("modulos numbers 2 - mod", () =>
               expect(Bn.mod_(b, a) |> Bn.toNumber) |> toBe(float_of_int(rMod))
             );
             test("modulos numbers 2 - umod", () =>
               expect(Bn.umod(b, a) |> Bn.toNumber)
               |> toBe(float_of_int(rUmod))
             );
           });
        test("carries the sign inside division", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "945304eb96065b2a98b57a48a06ae28d285a71b5"
            );
          let b =
            Bn.fromString(
              ~base=16,
              "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe"
            );
          expect(a |> Bn.mul(b) |> Bn.mod_(a) |> Bn.cmpn(0.))
          |> toBe(Equality.Equal);
        });
      }
    )
  );

let () =
  describe(
    "mod",
    ExpectJs.(
      () =>
        test("carries the sign inside division", () => {
          let a =
            Bn.fromString(
              ~base=16,
              "945304eb96065b2a98b57a48a06ae28d285a71b5"
            );
          let b =
            Bn.fromString(
              ~base=16,
              "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe"
            );
          expect(a |> Bn.mul(b) |> Bn.mod_(a) |> Bn.cmpn(0.))
          |> toBe(Equality.Equal);
        })
    )
  );

let () =
  describe(
    "modrn",
    ExpectJs.(
      () =>
        [
          ("10", 256, "10"),
          ("100", 256, "0"),
          ("1001", 256, "1"),
          ("100000000001", 256, "1"),
          (
            "100000000001",
            257,
            Bn.fromString(~base=16, "100000000001")
            |> Bn.mod_(Bn.fromFloat(257.))
            |> Bn.toString(~base=16)
          ),
          (
            "123456789012",
            3,
            Bn.fromString(~base=16, "123456789012")
            |> Bn.mod_(Bn.fromFloat(3.))
            |> Bn.toString(~base=16)
          )
        ]
        |> List.iter(((x, y, r)) =>
             test("act like mod on small numbers", () => {
               let a = Bn.fromString(~base=16, x);
               expect(a |> Bn.modn(float_of_int(y)) |> Bn.toString(~base=16))
               |> toBe(r);
             })
           )
    )
  );

let () =
  describe(
    "abs",
    ExpectJs.(
      () => {
        [(0x1001, "4097"), ((-0x1001), "4097")]
        |> List.iter(((x, r)) =>
             test("returns absolute value", () => {
               let a = Bn.fromFloat(float_of_int(x));
               expect(a |> Bn.abs |> Bn.toString) |> toBe(r);
             })
           );
        test("returns absolute value for long numbers", () => {
          let a = Bn.fromString(~base=16, "ffffffff");
          expect(a |> Bn.abs |> Bn.toString) |> toBe("4294967295");
        });
      }
    )
  );

let () =
  describe(
    "invm",
    ExpectJs.(
      () =>
        [
          ("257", "3"),
          ("fffffffffffffffffffffffffffffffeffffffffffffffff", "deadbeef"),
          ("872d9b030ba368706b68932cf07a0e0c", "65537"),
          ("5", "6")
        ]
        |> List.iter(((x, y)) =>
             test("inverts relatively-prime numbers", () => {
               let p = Bn.fromString(~base=16, x);
               let a = Bn.fromString(~base=16, y);
               let b = a |> Bn.invm(p);
               expect(a |> Bn.mul(b) |> Bn.mod_(p) |> Bn.toString(~base=16))
               |> toBe("1");
             })
           )
    )
  );

let () =
  describe(
    "gcd",
    ExpectJs.(
      () =>
        [
          (3, 2, "1"),
          (18, 12, "6"),
          ((-18), 12, "6"),
          ((-18), (-12), "6"),
          ((-18), 0, "18"),
          (0, (-18), "18"),
          (2, 0, "2"),
          (0, 3, "3"),
          (0, 0, "0")
        ]
        |> List.iter(((x, y, r)) =>
             test("returns GCD", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               expect(a |> Bn.gcd(b) |> Bn.toString) |> toBe(r);
             })
           )
    )
  );

let () =
  describe(
    "egcd",
    ExpectJs.(
      () => {
        [(3, 2, "1"), (18, 12, "6"), ((-18), 12, "6"), (0, 12, "12")]
        |> List.iter(((x, y, r)) =>
             test("returns EGCD", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               let result = a |> Bn.egcd(b);
               expect(result.gcd |> Bn.toString) |> toBe(r);
             })
           );
        test("does not allow 0 input", () =>
          expect(() =>
            Bn.fromString("1") |> Bn.egcd(Bn.fromString("0"))
          )
          |> toThrow
        );
        test("does not allow negative input", () =>
          expect(() =>
            Bn.fromString("1") |> Bn.egcd(Bn.fromString("-1"))
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "max",
    ExpectJs.(
      () =>
        [(3, 2, "3"), (2, 3, "3"), (2, 2, "2"), (2, (-2), "2")]
        |> List.iter(((x, y, r)) =>
             test("returns maximum", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               expect(a |> Bn.max(b) |> Bn.toString) |> toBe(r);
             })
           )
    )
  );

let () =
  describe(
    "min",
    ExpectJs.(
      () =>
        [(3, 2, "2"), (2, 3, "2"), (2, 2, "2"), (2, (-2), "-2")]
        |> List.iter(((x, y, r)) =>
             test("returns minimun", () => {
               let a = Bn.fromFloat(float_of_int(x));
               let b = Bn.fromFloat(float_of_int(y));
               expect(a |> Bn.min(b) |> Bn.toString) |> toBe(r);
             })
           )
    )
  );

let () =
  describe(
    "ineg",
    ExpectJs.(
      () =>
        test("does not change sign for zero", () => {
          let a = Bn.fromString("0");
          Bn.ineg(a);
          expect(a |> Bn.toString) |> toBe("0");
        })
    )
  );