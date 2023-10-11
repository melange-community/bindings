open Jest;

let compareArrays = (a, b) =>
  switch (Array.length(a) === Array.length(b)) {
  | false => false
  | true =>
    let equal = ref(true);
    for (i in 0 to Array.length(a) - 1) {
      equal := a[i] === b[i] && equal^;
    };
    equal^;
  };

let () =
  describe(
    "toString",
    ExpectJs.(
      () => {
        test("adds binary padding", () =>
          expect(
            Bn.fromFloat(0.)
            |> Bn.toString(~base=2, ~padding=256)
            |> Js.String.length
          )
          |> toBe(256)
        );
        test("adds hex padding, has length of 8 from leading 15", () =>
          expect(
            Bn.fromString(~base=16, "ffb9602")
            |> Bn.toString(~base=16, ~padding=2)
            |> Js.String.length
          )
          |> toBe(8)
        );
        test("adds hex padding, has length of 8 from leading zero", () =>
          expect(
            Bn.fromString(~base=16, "fb9604")
            |> Bn.toString(~base=16, ~padding=8)
            |> Js.String.length
          )
          |> toBe(8)
        );
        test("adds hex padding, has length of 8 from leading zeros", () =>
          expect(
            Bn.fromFloat(0.)
            |> Bn.toString(~base=16, ~padding=8)
            |> Js.String.length
          )
          |> toBe(8)
        );
        test("adds hex padding, has length of 64 from leading 15", () =>
          expect(
            Bn.fromString(
              ~base=16,
              "ffb96ff654e61130ba8422f0debca77a0ea74ae5ea8bca9b54ab64aabf01003"
            )
            |> Bn.toString(~base=16, ~padding=2)
            |> Js.String.length
          )
          |> toBe(64)
        );
        test("adds hex padding, has length of 64 from leading 15", () =>
          expect(
            Bn.fromString(
              ~base=16,
              "fb96ff654e61130ba8422f0debca77a0ea74ae5ea8bca9b54ab64aabf01003"
            )
            |> Bn.toString(~base=16, ~padding=64)
            |> Js.String.length
          )
          |> toBe(64)
        );
      }
    )
  );

let () =
  describe(
    "isNeg",
    ExpectJs.(
      () => {
        test("returns true for negative numbers", () =>
          expect(Bn.fromFloat(-1.) |> Bn.isNeg) |> toBe(true)
        );
        test("returns false for positive numbers", () =>
          expect(Bn.fromFloat(1.) |> Bn.isNeg) |> toBe(false)
        );
        test("returns false for positive numbers 2", () =>
          expect(Bn.fromFloat(0.) |> Bn.isNeg) |> toBe(false)
        );
        test("returns true for negative numbers 3", () =>
          expect(Bn.fromFloat(-0.) |> Bn.isNeg) |> toBe(false)
        );
      }
    )
  );

let () =
  describe(
    "isOdd",
    ExpectJs.(
      () =>
        [
          (0, false),
          (1, true),
          (2, false),
          ((-0), false),
          ((-1), true),
          ((-2), false)
        ]
        |> List.iter(((x, r)) =>
             test("returns true for odd numbers", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.isOdd) |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "isEven",
    ExpectJs.(
      () =>
        [
          (0, true),
          (1, false),
          (2, true),
          ((-0), true),
          ((-1), false),
          ((-2), true)
        ]
        |> List.iter(((x, r)) =>
             test("returns true for odd numbers", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.isEven) |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "isZero",
    ExpectJs.(
      () =>
        [(0, true), (1, false), (0xffffffff, false)]
        |> List.iter(((x, r)) =>
             test("returns true for zero", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.isZero) |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "bitLength",
    ExpectJs.(
      () => {
        [
          (0, 0),
          (0x1, 1),
          (0x2, 2),
          (0x3, 2),
          (0x4, 3),
          (0x8, 4),
          (0x10, 5),
          (0x100, 9),
          (0x123456, 21)
        ]
        |> List.iter(((x, r)) =>
             test("returns proper bitLength", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.bitLength) |> toBe(r)
             )
           );
        [("123456789", 33), ("8023456789", 40)]
        |> List.iter(((x, r)) =>
             test("returns proper bitLength for long numbers", () =>
               expect(Bn.fromString(~base=16, x) |> Bn.bitLength) |> toBe(r)
             )
           );
      }
    )
  );

let () =
  describe(
    "byteLength",
    ExpectJs.(
      () => {
        [
          (0, 0),
          (0x1, 1),
          (0x2, 1),
          (0x3, 1),
          (0x4, 1),
          (0x8, 1),
          (0x10, 1),
          (0x100, 2),
          (0x123456, 3)
        ]
        |> List.iter(((x, r)) =>
             test("returns proper byteLength", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.byteLength)
               |> toBe(r)
             )
           );
        [("123456789", 5), ("8023456789", 5)]
        |> List.iter(((x, r)) =>
             test("returns proper byteLength for long numbers", () =>
               expect(Bn.fromString(~base=16, x) |> Bn.byteLength) |> toBe(r)
             )
           );
      }
    )
  );

let () =
  describe(
    "toArray",
    ExpectJs.(
      () => {
        test("returns [0] for `0`", () =>
          expect(
            compareArrays(Bn.toArray(~endian=`be, Bn.fromFloat(0.)), [|0|])
          )
          |> toBe(true)
        );
        test("returns [0] for `0` with le", () =>
          expect(
            compareArrays(Bn.toArray(~endian=`le, Bn.fromFloat(0.)), [|0|])
          )
          |> toBe(true)
        );
        test("zero pads to desired lengths", () =>
          expect(
            compareArrays(
              Bn.toArray(
                ~length=5,
                ~endian=`be,
                Bn.fromFloat(float_of_int(0x123456))
              ),
              [|0x00, 0x00, 0x12, 0x34, 0x56|]
            )
          )
          |> toBe(true)
        );
        test("zero pads to desired lengths with le", () =>
          expect(
            compareArrays(
              Bn.toArray(
                ~length=5,
                ~endian=`le,
                Bn.fromFloat(float_of_int(0x123456))
              ),
              [|0x56, 0x34, 0x12, 0x00, 0x00|]
            )
          )
          |> toBe(true)
        );
        test("throws when naturally larger than desired length", () =>
          expect(() =>
            Bn.toArray(
              ~length=2,
              ~endian=`be,
              Bn.fromFloat(float_of_int(0x123456))
            )
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "toBuffer",
    ExpectJs.(
      () =>
        test("returns Buffer", ()
          /* TODO: Add bs-node and check values inside buffer */
          =>
            expect(
              Bn.fromFloat(float_of_int(0x123456))
              |> Bn.toBuffer(~endian=`be, ~length=5)
              |> Node.Buffer.isBuffer
            )
            |> toBe(true)
          )
    )
  );

let () =
  describe(
    "toNumber",
    ExpectJs.(
      () => {
        [
          0x123456,
          0x3ffffff,
          0x4000000,
          0x10000000000000,
          0x10040004004000,
          (-0x123456),
          (-0x3ffffff),
          (-0x4000000),
          (-0x10000000000000),
          (-0x10040004004000)
        ]
        |> List.iter(x =>
             test("returns proper Number if below the limit", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.toNumber)
               |> toBe(float_of_int(x))
             )
           );
        test("throws when number exceeds 53 bits", () =>
          expect(() =>
            Bn.fromFloat(1.) |> Bn.ushln(54) |> Bn.toNumber
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "zeroBits",
    ExpectJs.(
      () =>
        [
          (0, 0),
          (0x1, 0),
          (0x2, 1),
          (0x3, 0),
          (0x4, 2),
          (0x8, 3),
          (0x10, 4),
          (0x100, 8),
          (0x1000000, 24),
          (0x123456, 1)
        ]
        |> List.iter(((x, r)) =>
             test("returns proper zeroBits", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.zeroBits) |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "toJSON",
    ExpectJs.(
      () =>
        test("returns hex string", () =>
          expect(Bn.fromFloat(float_of_int(0x123)) |> Bn.toJSON) |> toBe("123")
        )
    )
  );

let () =
  describe(
    "cmpn",
    ExpectJs.(
      () => {
        [
          (42, 42, Equality.Equal),
          (42, 43, Equality.Less),
          (42, 41, Equality.Greater),
          (0x3fffffe, 0x3fffffe, Equality.Equal),
          (0x3fffffe, 0x3ffffff, Equality.Less),
          (0x3fffffe, 0x3fffffd, Equality.Greater),
          (42, (-42), Equality.Greater),
          ((-42), 42, Equality.Less),
          ((-42), (-42), Equality.Equal)
        ]
        |> List.iter(((x, y, r)) =>
             test("returns equality value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x)) |> Bn.cmpn(float_of_int(y))
               )
               |> toBe(r)
             )
           );
        test("throws when number exceeds 53 bits", () =>
          expect(() =>
            Bn.fromFloat(float_of_int(0x3fffffe))
            |> Bn.cmpn(float_of_int(0x4000000))
          )
          |> toThrow
        );
      }
    )
  );

let () =
  describe(
    "cmp",
    ExpectJs.(
      () =>
        [
          (42, 42, Equality.Equal),
          (42, 43, Equality.Less),
          (42, 41, Equality.Greater),
          (0x3fffffe, 0x3fffffe, Equality.Equal),
          (0x3fffffe, 0x3ffffff, Equality.Less),
          (0x3fffffe, 0x3fffffd, Equality.Greater),
          (0x3fffffe, 0x4000000, Equality.Less),
          (42, (-42), Equality.Greater),
          ((-42), 42, Equality.Less),
          ((-42), (-42), Equality.Equal)
        ]
        |> List.iter(((x, y, r)) =>
             test("returns equality value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.cmp(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "gtn",
    ExpectJs.(
      () =>
        [(3, 2, true), (3, 3, false), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.gtn(float_of_int(y)))
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "gt",
    ExpectJs.(
      () =>
        [(3, 2, true), (3, 3, false), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.gt(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "gten",
    ExpectJs.(
      () =>
        [(3, 2, true), (3, 3, true), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x)) |> Bn.gten(float_of_int(y))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "gte",
    ExpectJs.(
      () =>
        [(3, 2, true), (3, 3, true), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.gte(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "ltn",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, false), (3, 4, true)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.ltn(float_of_int(y)))
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "lt",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, false), (3, 4, true)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.lt(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "lten",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, true), (3, 4, true)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x)) |> Bn.lten(float_of_int(y))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "lte",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, true), (3, 4, true)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.lte(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "eqn",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, true), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(Bn.fromFloat(float_of_int(x)) |> Bn.eqn(float_of_int(y)))
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "eq",
    ExpectJs.(
      () =>
        [(3, 2, false), (3, 3, true), (3, 4, false)]
        |> List.iter(((x, y, r)) =>
             test("returns value correctly", () =>
               expect(
                 Bn.fromFloat(float_of_int(x))
                 |> Bn.eq(Bn.fromFloat(float_of_int(y)))
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "fromTwos",
    ExpectJs.(
      () => {
        [
          ("00000000", 32, 0),
          ("00000001", 32, 1),
          ("7fffffff", 32, 2147483647),
          ("80000000", 32, (-2147483648)),
          ("f0000000", 32, (-268435456)),
          ("f1234567", 32, (-249346713)),
          ("ffffffff", 32, (-1)),
          ("fffffffe", 32, (-2)),
          ("fffffffffffffffffffffffffffffffe", 128, (-2)),
          (
            "ffffffffffffffffffffffffffffffff"
            ++ "fffffffffffffffffffffffffffffffe",
            256,
            (-2)
          ),
          (
            "ffffffffffffffffffffffffffffffff"
            ++ "ffffffffffffffffffffffffffffffff",
            256,
            (-1)
          )
        ]
        |> List.iter(((n, width, r)) =>
             test("converts from two's complement to numbers", () =>
               expect(
                 Bn.fromString(~base=16, n)
                 |> Bn.fromTwos(width)
                 |> Bn.toNumber
               )
               |> toBe(float_of_int(r))
             )
           );
        [
          (
            "7fffffffffffffffffffffffffffffff"
            ++ "ffffffffffffffffffffffffffffffff",
            256,
            "5789604461865809771178549250434395392663499"
            ++ "2332820282019728792003956564819967"
          ),
          (
            "80000000000000000000000000000000"
            ++ "00000000000000000000000000000000",
            256,
            "-578960446186580977117854925043439539266349"
            ++ "92332820282019728792003956564819968"
          )
        ]
        |> List.iter(((n, width, r)) =>
             test("converts from two's complement to large numbers", () =>
               expect(
                 Bn.fromString(~base=16, n)
                 |> Bn.fromTwos(width)
                 |> Bn.toString
               )
               |> toBe(r)
             )
           );
      }
    )
  );

let () =
  describe(
    "toTwos",
    ExpectJs.(
      () =>
        [
          ("0", 32, "0"),
          ("1", 32, "1"),
          ("2147483647", 32, "7fffffff"),
          ("-2147483648", 32, "80000000"),
          ("-268435456", 32, "f0000000"),
          ("-249346713", 32, "f1234567"),
          ("-1", 32, "ffffffff"),
          ("-2", 32, "fffffffe"),
          ("-2", 128, "fffffffffffffffffffffffffffffffe"),
          (
            "-2",
            256,
            "ffffffffffffffffffffffffffffffff"
            ++ "fffffffffffffffffffffffffffffffe"
          ),
          (
            "-1",
            256,
            "ffffffffffffffffffffffffffffffff"
            ++ "ffffffffffffffffffffffffffffffff"
          ),
          (
            "5789604461865809771178549250434395392663" ++
            "4992332820282019728792003956564819967",
            256,
            "7fffffffffffffffffffffffffffffff"
            ++ "ffffffffffffffffffffffffffffffff"
          ),
          (
            "-578960446186580977117854925043439539266" ++
            "34992332820282019728792003956564819968",
            256,
            "80000000000000000000000000000000"
            ++ "00000000000000000000000000000000"
          ),
          
        ]
        |> List.iter(((n, width, r)) =>
             test("converts from numbers to two's complement", () =>
               expect(
                 Bn.fromString(n)
                 |> Bn.toTwos(width)
                 |> Bn.toString(~base=16)
               )
               |> toBe(r)
             )
           )
    )
  );
