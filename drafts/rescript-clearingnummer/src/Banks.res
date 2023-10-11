type banks =
  | Alandsbanken
  | Amfa
  | Avanza
  | BankernasAutomatbolag
  | BankOfChina
  | Bluestep
  | Calyon
  | Citibank
  | Danske
  | DNB
  | Ekobanken
  | ErikPenser
  | Exchange
  | Folkia
  | Forex
  | Fortis
  | GE
  | Handelsbanken
  | ICA
  | IKANO
  | JAK
  | Kommuninvest
  | Kortaccept
  | Landshypotek
  | LSB
  | Lansforsakringar
  | Marginalen
  | MedMera
  | Nasdaq
  | Netfonds
  | Nordax
  | Nordea
  | Nordnet
  | Pareto
  | Privatgirot
  | RBS
  | Resurs
  | Riksbanken
  | Riksgalden
  | SBAB
  | SEB
  | Skandia
  | Sparbanken
  | Swedbank
  | SWEDFryksdalen
  | SWEDGotland
  | SWEDKindra
  | SWEDLekeberg
  | SWEDMarkaryd
  | SWEDMonsteras
  | SWEDNars
  | SWEDSkaraborg
  | SWEDSkurup
  | SWEDSolvesborg
  | SWEDVarberg
  | TellerNorway
  | TellerSweden
  | Volvo
  | VP
  | Unknown

let getBankName = bank =>
  switch bank {
  | Alandsbanken => `Ålandsbanken`
  | Amfa => "Amfa Bank"
  | Avanza => "Avanza Bank"
  | BankernasAutomatbolag => "Bankernas Automatbolag"
  | BankOfChina => "Bank of China (Luxembourg)"
  | Bluestep => "Bluestep Finans"
  | Calyon => "Calyon Bank"
  | Citibank => "Citibank"
  | Danske => "Danske Bank"
  | DNB => "DNB Bank"
  | Ekobanken => "Ekobanken"
  | ErikPenser => "Erik Penser Bankaktiebolag"
  | Exchange => "Exchange Finans Europe"
  | Folkia => "Folkia"
  | Forex => "Forex Bank"
  | Fortis => "Fortis Bank"
  | GE => "GE Money Bank"
  | Handelsbanken => "Handelsbanken"
  | ICA => "ICA Banken"
  | IKANO => "IKANO Bank"
  | JAK => "JAK Medlemsbank"
  | Kommuninvest => "Kommuninvest"
  | Kortaccept => "Kortaccept Nordic"
  | Landshypotek => "Landshypotek"
  | LSB => `Lån & Spar Bank`
  | Lansforsakringar => `Länsförsäkringar Bank`
  | Marginalen => "Marginalen Bank"
  | MedMera => "MedMera Bank"
  | Nasdaq => "Nasdaq-OMX"
  | Netfonds => "Netfonds Bank (ub)"
  | Nordax => "Nordax Finans"
  | Nordea => "Nordea"
  | Nordnet => "Nordnet Bank"
  | Pareto => `Pareto Öhman`
  | Privatgirot => "Privatgirot"
  | RBS => "RBS"
  | Resurs => "Resurs Bank"
  | Riksbanken => "Sveriges Riksbank"
  | Riksgalden => `Riksgälden`
  | SBAB => "SBAB Bank"
  | SEB => "SEB"
  | Skandia => "Skandiabanken"
  | Sparbanken => "Sparbanken Syd"
  | Swedbank => "Swedbank"
  | SWEDGotland => "Sparbanken Gotland"
  | SWEDFryksdalen => "Fryksdalens sparbank"
  | SWEDKindra => "Kinda-Ydre sparbank"
  | SWEDLekeberg => "Lekebergs sparbank"
  | SWEDMarkaryd => "Markaryds sparbank"
  | SWEDMonsteras => `Häradssparbanken Mönsterås`
  | SWEDNars => `Närs sparbank`
  | SWEDSkaraborg => "Sparbanken Skaraborg"
  | SWEDSkurup => "Skurups sparbank"
  | SWEDSolvesborg => `Sölvesborg-Mjällby sparbank`
  | SWEDVarberg => "Varbergs sparbank"
  | TellerNorway => "Teller Branch Norway"
  | TellerSweden => "Teller Branch Sweden"
  | Volvo => "Volvofinans Bank"
  | VP => "VP Securities A/S"
  | Unknown => ""
  }

let all =
  [
    Amfa,
    Avanza,
    BankernasAutomatbolag,
    BankOfChina,
    Bluestep,
    Calyon,
    Citibank,
    Danske,
    DNB,
    Ekobanken,
    ErikPenser,
    Exchange,
    Folkia,
    Forex,
    Fortis,
    GE,
    Handelsbanken,
    ICA,
    IKANO,
    JAK,
    Kommuninvest,
    Kortaccept,
    Landshypotek,
    LSB,
    Lansforsakringar,
    Marginalen,
    MedMera,
    Nasdaq,
    Netfonds,
    Nordax,
    Nordea,
    Nordnet,
    Pareto,
    Privatgirot,
    RBS,
    Resurs,
    Riksbanken,
    Riksgalden,
    SBAB,
    SEB,
    Skandia,
    Sparbanken,
    Swedbank,
    SWEDFryksdalen,
    SWEDGotland,
    SWEDKindra,
    SWEDLekeberg,
    SWEDMarkaryd,
    SWEDMonsteras,
    SWEDNars,
    SWEDSkaraborg,
    SWEDSkurup,
    SWEDSolvesborg,
    SWEDVarberg,
    TellerNorway,
    TellerSweden,
    Volvo,
    VP,
    Alandsbanken,
  ]->Js.Array2.map(item => getBankName(item))
