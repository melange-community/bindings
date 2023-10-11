open Jest;

let () =
  describe(
    "shl",
    ExpectJs.(
      () =>
        [
          ("69527932928", 13, "2060602000000"),
          ("69527932928", 45, "206060200000000000000")
        ]
        |> List.iter(((x, bits, r)) =>
             test("shifts left numbers", () =>
               expect(
                 Bn.fromString(x) |> Bn.shln(bits) |> Bn.toString(~base=16)
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "ushl",
    ExpectJs.(
      () =>
        [
          ("69527932928", 13, "2060602000000"),
          ("69527932928", 45, "206060200000000000000")
        ]
        |> List.iter(((x, bits, r)) =>
             test("shifts left numbers", () =>
               expect(
                 Bn.fromString(x) |> Bn.ushln(bits) |> Bn.toString(~base=16)
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "shr",
    ExpectJs.(
      () =>
        [
          ("69527932928", 13, "818180"),
          ("69527932928", 17, "81818"),
          ("69527932928", 256, "0")
        ]
        |> List.iter(((x, bits, r)) =>
             test("shifts right numbers", () =>
               expect(
                 Bn.fromString(x) |> Bn.shrn(bits) |> Bn.toString(~base=16)
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "ushr",
    ExpectJs.(
      () =>
        [
          ("69527932928", 13, "818180"),
          ("69527932928", 17, "81818"),
          ("69527932928", 256, "0")
        ]
        |> List.iter(((x, bits, r)) =>
             test("shifts right numbers", () =>
               expect(
                 Bn.fromString(x) |> Bn.ushrn(bits) |> Bn.toString(~base=16)
               )
               |> toBe(r)
             )
           )
    )
  );

let () =
  describe(
    "bincn",
    ExpectJs.(
      () => {
        let twoToFour = Bn.fromFloat(2.);
        Bn.bincn(1, twoToFour);
        [
          (0, 1, "2"),
          (2, 1, "4"),
          (2, 1, twoToFour |> Bn.toString(~base=16)),
          (0xffffff, 1, "1000001"),
          (2, 63, "8000000000000002")
        ]
        |> List.iter(((x, bits, r)) =>
             test("increments bits", () => {
               let bn = Bn.fromFloat(float_of_int(x));
               Bn.bincn(bits, bn);
               expect(bn |> Bn.toString(~base=16)) |> toBe(r);
             })
           );
      }
    )
  );

let () =
  describe(
    "imaskn",
    ExpectJs.(
      () => {
        [
          ("0", 1, "0"),
          ("3", 1, "1"),
          ("123456789", 4, "9"),
          ("123456789", 16, "6789"),
          ("123456789", 28, "3456789")
        ]
        |> List.iter(((x, bits, r)) =>
             test("masks bits in place", () => {
               let bn = Bn.fromString(~base=16, x);
               Bn.imaskn(bits, bn);
               expect(bn |> Bn.toString(~base=16)) |> toBe(r);
             })
           );
        [(0xe3, 56, "e3"), (0xe3, 26, "e3")]
        |> List.iter(((x, bits, r)) =>
             test("does not mask when number is bigger than length", () => {
               let bn = Bn.fromFloat(float_of_int(x));
               Bn.imaskn(bits, bn);
               expect(bn |> Bn.toString(~base=16)) |> toBe(r);
             })
           );
      }
    )
  );

let () =
  describe(
    "testn",
    ExpectJs.(
      () => {
        [
          "ff",
          "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        ]
        |> List.iter(x => {
             let bn = Bn.fromString(~base=16, x);
             let bl = Bn.bitLength(bn);
             for (i in 0 to bl - 1) {
               test("masks bits in place", () =>
                 expect(Bn.testn(i, bn)) |> toBe(true)
               );
             };
             test("false if length is greater than bitLength", () =>
               expect(Bn.testn(bl, bn)) |> toBe(false)
             );
           });
        let xbits =
          "01111001010111001001000100011101"
          ++ "11010011101100011000111001011101"
          ++ "10010100111000000001011000111101"
          ++ "01011111001111100100011110000010"
          ++ "01011010100111010001010011000100"
          ++ "01101001011110100001001111100110"
          ++ "001110010111";
        let x =
          Bn.fromString(
            "23478905234580795234378912401239784125643978256123048348957342"
          );
        for (i in 0 to Bn.bitLength(x) - 1) {
          test("works with bit " ++ string_of_int(i), () =>
            expect(Bn.testn(i, x)) |> toBe(xbits.[i] === '1' ? true : false)
          );
        };
        test("has short-cuts", () => {
          let x = Bn.fromString(~base=16, "abcd");
          expect(Bn.testn(128, x)) |> toBe(false);
        });
      }
    )
  );

let () =
  describe(
    "and",
    ExpectJs.(
      () => {
        test("ands numbers", () =>
          expect(
            Bn.fromString(~base=2, "1010101010101010101010101010101010101010")
            |> Bn.and_(
                 Bn.fromString(
                   ~base=2,
                   "101010101010101010101010101010101010101"
                 )
               )
            |> Bn.toString(~base=2)
          )
          |> toBe("0")
        );
        test("ands numbers of different limb-length", () =>
          expect(
            Bn.fromString(~base=16, "abcd0000ffff")
            |> Bn.and_(Bn.fromString(~base=16, "abcd"))
            |> Bn.toString(~base=16)
          )
          |> toBe("abcd")
        );
      }
    )
  );

let () =
  describe(
    "iand",
    ExpectJs.(
      () => {
        test("iands numbers", () => {
          let bn =
            Bn.fromString(~base=2, "1010101010101010101010101010101010101010");
          Bn.iand(
            Bn.fromString(~base=2, "101010101010101010101010101010101010101"),
            bn
          );
          expect(bn |> Bn.toString(~base=2)) |> toBe("0");
        });
        test("iands numbers - 2", () => {
          let bn =
            Bn.fromString(~base=2, "1000000000000000000000000000000000000001");
          Bn.iand(Bn.fromString(~base=2, "1"), bn);
          expect(bn |> Bn.toString(~base=2)) |> toBe("1");
        });
        test("iands numbers - 3", () => {
          let bn = Bn.fromString(~base=2, "1");
          Bn.iand(
            Bn.fromString(~base=2, "1000000000000000000000000000000000000001"),
            bn
          );
          expect(bn |> Bn.toString(~base=2)) |> toBe("1");
        });
      }
    )
  );

let () =
  describe(
    "or",
    ExpectJs.(
      () => {
        test("ors numbers", () =>
          expect(
            Bn.fromString(~base=2, "1010101010101010101010101010101010101010")
            |> Bn.or_(
                 Bn.fromString(
                   ~base=2,
                   "101010101010101010101010101010101010101"
                 )
               )
            |> Bn.toString(~base=2)
          )
          |> toBe("1111111111111111111111111111111111111111")
        );
        test("ors numbers of different limb-length", () =>
          expect(
            Bn.fromString(~base=16, "abcd00000000")
            |> Bn.or_(Bn.fromString(~base=16, "abcd"))
            |> Bn.toString(~base=16)
          )
          |> toBe("abcd0000abcd")
        );
      }
    )
  );

let () =
  describe(
    "ior",
    ExpectJs.(
      () => {
        test("iors numbers", () => {
          let bn =
            Bn.fromString(~base=2, "1010101010101010101010101010101010101010");
          Bn.ior(
            Bn.fromString(~base=2, "101010101010101010101010101010101010101"),
            bn
          );
          expect(bn |> Bn.toString(~base=2))
          |> toBe("1111111111111111111111111111111111111111");
        });
        test("iors numbers - 2", () => {
          let bn =
            Bn.fromString(~base=2, "1000000000000000000000000000000000000000");
          Bn.ior(Bn.fromString(~base=2, "1"), bn);
          expect(bn |> Bn.toString(~base=2))
          |> toBe("1000000000000000000000000000000000000001");
        });
        test("iors numbers - 3", () => {
          let bn = Bn.fromString(~base=2, "1");
          Bn.ior(
            Bn.fromString(~base=2, "1000000000000000000000000000000000000000"),
            bn
          );
          expect(bn |> Bn.toString(~base=2))
          |> toBe("1000000000000000000000000000000000000001");
        });
      }
    )
  );

let () =
  describe(
    "xor",
    ExpectJs.(
      () => {
        test("xors numbers", () =>
          expect(
            Bn.fromString(~base=2, "11001100110011001100110011001100")
            |> Bn.xor(
                 Bn.fromString(~base=2, "1100110011001100110011001100110")
               )
            |> Bn.toString(~base=2)
          )
          |> toBe("10101010101010101010101010101010")
        );
        test("xors numbers of different limb-length", () =>
          expect(
            Bn.fromString(~base=16, "abcd0000ffff")
            |> Bn.xor(Bn.fromString(~base=16, "abcd"))
            |> Bn.toString(~base=16)
          )
          |> toBe("abcd00005432")
        );
      }
    )
  );

let () =
  describe(
    "ixor",
    ExpectJs.(
      () => {
        test("ixors numbers", () => {
          let bn = Bn.fromString(~base=2, "11001100110011001100110011001100");
          Bn.ixor(
            Bn.fromString(~base=2, "1100110011001100110011001100110"),
            bn
          );
          expect(bn |> Bn.toString(~base=2))
          |> toBe("10101010101010101010101010101010");
        });
        test("ixors numbers - 2", () => {
          let bn = Bn.fromString(~base=2, "11001100110011001100110011001100");
          Bn.ixor(Bn.fromString(~base=2, "1"), bn);
          expect(bn |> Bn.toString(~base=2))
          |> toBe("11001100110011001100110011001101");
        });
        test("ixors numbers - 3", () => {
          let bn = Bn.fromString(~base=2, "1");
          Bn.ixor(
            Bn.fromString(~base=2, "11001100110011001100110011001100"),
            bn
          );
          expect(bn |> Bn.toString(~base=2))
          |> toBe("11001100110011001100110011001101");
        });
      }
    )
  );

let () =
  describe(
    "setn",
    ExpectJs.(
      () => {
        test("allows single bits to be set", () => {
          let bn = Bn.fromFloat(0.);
          Bn.setn(2, true, bn);
          expect(bn |> Bn.toString(~base=2)) |> toBe("100");
        });
        test("allows single bits to be set - 2", () => {
          let bn = Bn.fromFloat(0.);
          Bn.setn(27, true, bn);
          expect(bn |> Bn.toString(~base=2))
          |> toBe("1000000000000000000000000000");
        });
        test("allows single bits to be set - 3", () => {
          let bn = Bn.fromFloat(0.);
          Bn.setn(63, true, bn);
          expect(bn |> Bn.toString(~base=16))
          |> toBe(Bn.fromFloat(1.) |> Bn.ushln(63) |> Bn.toString(~base=16));
        });
        test("allows single bits to be set - 4", () => {
          let bn = Bn.fromString(~base=2, "1000000000000000000000000001");
          Bn.setn(27, false, bn);
          expect(bn |> Bn.toString(~base=2)) |> toBe("1");
        });
        test("allows single bits to be set - 5", () => {
          let bn = Bn.fromString(~base=2, "101");
          Bn.setn(2, false, bn);
          expect(bn |> Bn.toString(~base=2)) |> toBe("1");
        });
      }
    )
  );

let () =
  describe(
    "notn",
    ExpectJs.(
      () =>
        [
          ("111000111", 9, "111000"),
          ("000111000", 9, "111000111"),
          ("111000111", 32, "11111111111111111111111000111000"),
          ("000111000", 32, "11111111111111111111111111000111"),
          (
            "111000111",
            68,
            "11111111111111111111111111111111"
            ++ "111111111111111111111111111000111000"
          ),
          (
            "000111000",
            68,
            "11111111111111111111111111111111"
            ++ "111111111111111111111111111111000111"
          )
        ]
        |> List.iter(((x, bitwidth, r)) =>
             test("allows bitwise negation", () =>
               expect(
                 Bn.fromString(~base=2, x)
                 |> Bn.notn(bitwidth)
                 |> Bn.toString(~base=2)
               )
               |> toBe(r)
             )
           )
    )
  );