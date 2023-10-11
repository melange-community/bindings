open Jest;

let () =
  describe(
    "from float",
    ExpectJs.(
      () => {
        test(
          "one limb number",
          () => expect(Bn.fromFloat(12345.) |> Bn.toString(~base=16)) |> toBe("3039")
        );
        test(
          "two-limb number",
          () =>
            expect(Bn.fromFloat(float_of_int(0x4123456)) |> Bn.toString(~base=16))
            |> toBe("4123456")
        );
        test(
          "accepts 52 bits of precision",
          () =>
            expect(
              Bn.fromFloat(~base=10, Js.Math.pow_float(~base=2., ~exp=52.))
              |> Bn.toString(~base=10)
            )
            |> toBe("4503599627370496")
        );
        test(
          "accepts max safe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.) -. 1.;
            expect(Bn.fromFloat(~base=10, num) |> Bn.toString(~base=10))
            |> toBe("9007199254740991")
          }
        );
        test(
          "does not accept unsafe value",
          () => {
            let num = Js.Math.pow_float(~base=2., ~exp=53.);
            expect(() => Bn.fromFloat(~base=10, num)) |> toThrow
          }
        );
        test(
          "accepts two-limb LE number",
          () =>
            expect(Bn.fromFloat(~endian=`le, float_of_int(0x4123456)) |> Bn.toString(~base=16))
            |> toBe("56341204")
        )
      }
    )
  );

let () =
  describe(
    "from string",
    ExpectJs.(
      () => {
        test(
          "accepts base-16",
          () =>
            expect(Bn.fromString(~base=16, "1A6B765D8CDF") |> Bn.toString(~base=16))
            |> toBe("1a6b765d8cdf")
        );
        test(
          "accepts base-16 ex 2",
          () =>
            expect(Bn.fromString(~base=16, "1A6B765D8CDF") |> Bn.toString)
            |> toBe("29048849665247")
        );
        test(
          "accepts no base",
          () =>
            expect(Bn.fromString("10000000000000000") |> Bn.toString) |> toBe("10000000000000000")
        );
        test(
          "accepts base-36",
          () => {
            let base36 = "zzZzzzZzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            expect(Bn.fromString(~base=36, base36) |> Bn.toString(~base=36))
            |> toBe(String.lowercase(base36))
          }
        );
        test(
          "accepts base-16 LE integer",
          () =>
            expect(Bn.fromString(~base=16, ~endian=`le, "1A6B765D8CDF") |> Bn.toString(~base=16))
            |> toBe("df8c5d766b1a")
        )
      }
    )
  );

let () =
  describe(
    "from array",
    ExpectJs.(
      () => {
        test("accepts empty array", () => expect(Bn.fromArray([||]) |> Bn.toString) |> toBe("0"));
        test(
          "imports/exports big endian case 1",
          () => expect(Bn.fromArray([|1, 2, 3|]) |> Bn.toString(~base=16)) |> toBe("10203")
        );
        test(
          "imports/exports big endian case 2",
          () => expect(Bn.fromArray([|1, 2, 3, 4|]) |> Bn.toString(~base=16)) |> toBe("1020304")
        );
        test(
          "imports/exports big endian case 3",
          () =>
            expect(Bn.fromArray([|1, 2, 3, 4, 5|]) |> Bn.toString(~base=16)) |> toBe("102030405")
        );
        test(
          "imports/exports big endian case 4",
          () =>
            expect(Bn.fromArray([|1, 2, 3, 4, 5, 6, 7, 8|]) |> Bn.toString(~base=16))
            |> toBe("102030405060708")
        );
        test(
          "imports/exports big endian case 5",
          () =>
            expect(Bn.fromArray([|1, 2, 3, 4|]) |> Bn.toArray |> Js.Array.joinWith(","))
            |> toBe("1,2,3,4")
        );
        test(
          "imports/exports big endian case 6",
          () =>
            expect(
              Bn.fromArray([|1, 2, 3, 4, 5, 6, 7, 8|]) |> Bn.toArray |> Js.Array.joinWith(",")
            )
            |> toBe("1,2,3,4,5,6,7,8")
        );
        test(
          "imports/exports little endian case 1",
          () =>
            expect(Bn.fromArray(~base=10, ~endian=`le, [|1, 2, 3|]) |> Bn.toString(~base=16))
            |> toBe("30201")
        );
        test(
          "imports/exports little endian case 2",
          () =>
            expect(Bn.fromArray(~base=10, ~endian=`le, [|1, 2, 3, 4|]) |> Bn.toString(~base=16))
            |> toBe("4030201")
        );
        test(
          "imports/exports little endian case 3",
          () =>
            expect(Bn.fromArray(~base=10, ~endian=`le, [|1, 2, 3, 4, 5|]) |> Bn.toString(~base=16))
            |> toBe("504030201")
        );
        test(
          "imports/exports little endian case 4",
          () =>
            expect(Bn.fromArray(~endian=`le, [|1, 2, 3, 4, 5, 6, 7, 8|]) |> Bn.toString(~base=16))
            |> toBe("807060504030201")
        );
        test(
          "imports/exports little endian case 5",
          () =>
            expect(
              Bn.fromArray([|1, 2, 3, 4|]) |> Bn.toArray(~endian=`le) |> Js.Array.joinWith(",")
            )
            |> toBe("4,3,2,1")
        );
        test(
          "imports/exports little endian case 6",
          () =>
            expect(
              Bn.fromArray([|1, 2, 3, 4, 5, 6, 7, 8|])
              |> Bn.toArray(~endian=`le)
              |> Js.Array.joinWith(",")
            )
            |> toBe("8,7,6,5,4,3,2,1")
        );
        test(
          "import little endian with implicit base",
          () =>
            expect(Bn.fromArray(~endian=`le, [|1, 2, 3, 4, 5|]) |> Bn.toString(~base=16))
            |> toBe("504030201")
        )
      }
    )
  );

let () =
  describe(
    "from buffer",
    ExpectJs.(
      () => {
        test(
          "does not fail on empty Buffer",
          () => expect(Bn.fromBuffer(Node.Buffer.fromString("")) |> Bn.toString) |> toBe("0")
        );
        test(
          "imports/exports big endian",
          /* TODO - Check if there's a way to set Buffer with 'hex' */
          () =>
            expect(Bn.fromBuffer(Node.Buffer.fromString("12345")) |> Bn.toString(~base=16))
            |> toBe("3132333435")
        );
        test(
          "imports/exports little endian",
          /* TODO - Check if there's a way to set Buffer with 'hex' */
          () =>
            expect(
              Bn.fromBuffer(~endian=`le, Node.Buffer.fromString("12345")) |> Bn.toString(~base=16)
            )
            |> toBe("3534333231")
        )
      }
    )
  );

let () =
  describe(
    "clone",
    ExpectJs.(
      () =>
        test(
          "clones an existing BN",
          () => {
            let num = Bn.fromFloat(12345.);
            expect(Bn.clone(num) |> Bn.toString(~base=10)) |> toBe("12345")
          }
        )
    )
  );