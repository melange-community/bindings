open Jest;
open Expect;
open Clearingnummer;

let intTest = (bankName, bank) =>
  expect(BankName.fromInt(bank)) |> toEqual(bankName);

describe("#bankName", () => {
  describe("Amfa Bank", () =>
    testAll("9660-9669", [9660, 9662, 9669], intTest("Amfa Bank"))
  );

  describe("Avanza Bank", () =>
    testAll("9550-9569", [9550, 9559, 9569], intTest("Avanza Bank"))
  );

  describe("Bank of China (Luxembourg)", () =>
    testAll(
      "9620-9629",
      [9620, 9626, 9629],
      intTest("Bank of China (Luxembourg)"),
    )
  );

  describe("Bankernas Automatbolag", () =>
    test("9952", () =>
      intTest("Bankernas Automatbolag", 9952)
    )
  );

  describe("Bluestep Finans", () =>
    testAll("9680-9689", [9680, 9681, 9689], intTest("Bluestep Finans"))
  );

  describe("Calyon Bank", () =>
    testAll("9080-9089", [9080, 9085, 9089], intTest("Calyon Bank"))
  );

  describe("Citibank", () =>
    testAll("9040-9049", [9040, 9045, 9049], intTest("Citibank"))
  );

  describe("DNB Bank", () => {
    let dnb = intTest("DNB Bank");

    testAll("9190-9199", [9190, 9196, 9199], dnb);
    testAll("9260-9269", [9260, 9265, 9269], dnb);
  });

  describe("Danske Bank", () => {
    let danske = intTest("Danske Bank");

    testAll("1200-1399", [1200, 1345, 1399], danske);
    testAll("2400-2499", [2400, 2457, 2499], danske);
    testAll("9180-9189", [9180, 9186, 9189], danske);
  });

  describe("Ekobanken", () =>
    testAll("9700-9709", [9700, 9704, 9709], intTest("Ekobanken"))
  );

  describe("Erik Penser Bankaktiebolag", () =>
    testAll(
      "9590-9599",
      [9590, 9593, 9599],
      intTest("Erik Penser Bankaktiebolag"),
    )
  );

  describe("Exchange Finans Europe", () =>
    testAll(
      "9580-9589",
      [9580, 9587, 9589],
      intTest("Exchange Finans Europe"),
    )
  );

  describe("Folkia", () =>
    testAll("9690-9699", [9690, 9696, 9699], intTest("Folkia"))
  );

  describe("Forex Bank", () =>
    testAll("9400-9449", [9400, 9432, 9449], intTest("Forex Bank"))
  );

  describe("Fortis Bank", () =>
    testAll("9470-9479", [9470, 9475, 9479], intTest("Fortis Bank"))
  );

  describe("GE Money Bank", () =>
    testAll("9460-9469", [9460, 9461, 9469], intTest("GE Money Bank"))
  );

  describe("Handelsbanken", () =>
    testAll("6000-6999", [6000, 6545, 6999], intTest("Handelsbanken"))
  );

  describe("ICA Banken", () =>
    testAll("9270-9279", [9270, 9272, 9279], intTest("ICA Banken"))
  );

  describe("IKANO Bank", () =>
    testAll("9170-9179", [9170, 9172, 9179], intTest("IKANO Bank"))
  );

  describe("JAK Medlemsbank", () =>
    testAll("9670-9679", [9670, 9674, 9679], intTest("JAK Medlemsbank"))
  );

  describe("Kommuninvest", () =>
    test("9955", () =>
      intTest("Kommuninvest", 9955)
    )
  );

  describe("Kortaccept Nordic", () =>
    test("9954", () =>
      intTest("Kortaccept Nordic", 9954)
    )
  );

  describe("Landshypotek", () =>
    testAll("9390-9399", [9390, 9391, 9399], intTest("Landshypotek"))
  );

  describe({j|Lån & Spar Bank|j}, () =>
    testAll(
      "9630-9639",
      [9630, 9638, 9639],
      intTest({j|Lån & Spar Bank|j}),
    )
  );

  describe({j|Länsförsäkringar Bank|j}, () => {
    let lans = intTest({j|Länsförsäkringar Bank|j});

    testAll("3400-3409", [3400, 3403, 3409], lans);
    testAll("9020-9029", [9020, 9025, 9029], lans);
    testAll("9060-9069", [9060, 9067, 9069], lans);
  });

  describe("Marginalen Bank", () =>
    testAll("9230-9239", [9230, 9231, 9239], intTest("Marginalen Bank"))
  );

  describe("MedMera Bank", () =>
    testAll("9650-9659", [9650, 9657, 9659], intTest("MedMera Bank"))
  );

  describe("Nasdaq-OMX", () =>
    testAll("9870-9879", [9870, 9871, 9879], intTest("Nasdaq-OMX"))
  );

  describe("Netfonds Bank (ub)", () =>
    testAll("9720-9729", [9720, 9722, 9729], intTest("Netfonds Bank (ub)"))
  );

  describe("Nordax Finans", () =>
    testAll("9640-9649", [9640, 9645, 9649], intTest("Nordax Finans"))
  );

  describe("Nordea", () => {
    let nordea = intTest("Nordea");

    testAll("1100-1199", [1100, 1154, 1199], nordea);
    testAll("1400-2099", [1400, 2018, 2099], nordea);
    testAll("3000-3399", [3000, 3268, 3399], nordea);
    testAll("3410-4999", [3410, 4578, 4999], nordea);
    testAll("9500-9549", [9500, 9532, 9549], nordea);
    testAll("9960-9969", [9960, 9963, 9969], nordea);
  });

  describe("Nordnet Bank", () =>
    testAll("9100-9109", [9100, 9108, 9109], intTest("Nordnet Bank"))
  );

  describe({j|Pareto Öhman|j}, () =>
    testAll("9380-9389", [9380, 9385, 9389], intTest({j|Pareto Öhman|j}))
  );

  describe("Privatgirot", () =>
    testAll("9860-9869", [9860, 9862, 9869], intTest("Privatgirot"))
  );

  describe("RBS", () =>
    testAll("9090-9099", [9090, 9098, 9099], intTest("RBS"))
  );

  describe("Resurs Bank", () =>
    testAll("9280-9289", [9280, 9282, 9289], intTest("Resurs Bank"))
  );

  describe({j|Riksgälden|j}, () =>
    testAll("9880-9899", [9880, 9888, 9899], intTest({j|Riksgälden|j}))
  );

  describe("SBAB Bank", () =>
    testAll("9250-9259", [9250, 9251, 9259], intTest("SBAB Bank"))
  );

  describe("SEB", () => {
    let seb = intTest("SEB");

    testAll("5000-5999", [5000, 5202, 5999], seb);
    testAll("9120-9124", [9120, 9121, 9124], seb);
    testAll("9130-9149", [9130, 9140, 9149], seb);
  });

  describe("Skandiabanken", () =>
    testAll("9150-9169", [9150, 9162, 9169], intTest("Skandiabanken"))
  );

  describe("Sparbanken Syd", () =>
    testAll("9570-9579", [9570, 9573, 9579], intTest("Sparbanken Syd"))
  );

  describe("Sveriges Riksbank", () =>
    testAll("1000-1099", [1000, 1050, 1099], intTest("Sveriges Riksbank"))
  );

  describe("Swedbank", () => {
    let swed = intTest("Swedbank");

    testAll("7000-8999", [7000, 8120, 8999], swed);
    testAll("9300-9349", [9300, 9324, 9349], swed);

    testAll(
      "Special numbers",
      [
        "8060-6",
        "8079-6",
        "8304-8",
        "8305-5",
        "8313-9",
        "8314-7",
        "8327-9",
        "8383-2",
        "8393-1",
        "8431-9",
        "8424-4",
      ],
      bank =>
      expect(BankName.fromString(bank)) |> toEqual("Swedbank")
    );

    test("Sparbanken Gotland", () =>
      expect(BankName.fromString("8055-6")) |> toEqual("Sparbanken Gotland")
    );

    test("Kinda-Ydre sparbank", () =>
      expect(BankName.fromString("8158-8"))
      |> toEqual("Kinda-Ydre sparbank")
    );

    test("Lekebergs sparbank", () =>
      expect(BankName.fromString("8164-6")) |> toEqual("Lekebergs sparbank")
    );

    test("Markaryds sparbank", () =>
      expect(BankName.fromString("8217-2")) |> toEqual("Markaryds sparbank")
    );

    test({j|Närs sparbank|j}, () =>
      expect(BankName.fromString("8250-3")) |> toEqual({j|Närs sparbank|j})
    );

    test("Sparbanken Skaraborg", () =>
      expect(BankName.fromString("8289-1"))
      |> toEqual("Sparbanken Skaraborg")
    );

    test("Skurups sparbank", () =>
      expect(BankName.fromString("8295-8")) |> toEqual("Skurups sparbank")
    );

    test({j|Häradssparbanken Mönsterås|j}, () =>
      expect(BankName.fromString("8331-1"))
      |> toEqual({j|Häradssparbanken Mönsterås|j})
    );

    test("Fryksdalens sparbank", () =>
      expect(BankName.fromString("8336-0"))
      |> toEqual("Fryksdalens sparbank")
    );

    test({j|Sölvesborg-Mjällby sparbank|j}, () =>
      expect(BankName.fromString("8321-2"))
      |> toEqual({j|Sölvesborg-Mjällby sparbank|j})
    );

    test("Varbergs sparbank", () =>
      expect(BankName.fromString("8388-1")) |> toEqual("Varbergs sparbank")
    );
  });

  describe("Teller Branch Norway", () =>
    test("9951", () =>
      intTest("Teller Branch Norway", 9951)
    )
  );

  describe("Teller Branch Sweden", () =>
    test("9953", () =>
      intTest("Teller Branch Sweden", 9953)
    )
  );

  describe("Volvofinans Bank", () =>
    testAll("9610-9619", [9610, 9616, 9619], intTest("Volvofinans Bank"))
  );

  describe("VP Securities A/S", () =>
    test("9956", () =>
      intTest("VP Securities A/S", 9956)
    )
  );

  describe({j|Ålandsbanken|j}, () =>
    testAll("2300-2399", [2300, 2354, 2399], intTest({j|Ålandsbanken|j}))
  );
});
