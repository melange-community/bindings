type t = [
  | #decimal
  | #upperRoman
  | #lowerRoman
  | #upperLetter
  | #lowerLetter
  | #ordinal
  | #cardinalText
  | #ordinalText
  | #hex
  | #chicago
  | #ideographDigital
  | #japaneseCounting
  | #aiueo
  | #iroha
  | #decimalFullWidth
  | #decimalHalfWidth
  | #japaneseLegal
  | #japaneseDigitalTenThousand
  | #decimalEnclosedCircle
  | #decimalFullWidth2
  | #aiueoFullWidth
  | #irohaFullWidth
  | #decimalZero
  | #bullet
  | #ganada
  | #chosung
  | #decimalEnclosedFullstop
  | #decimalEnclosedParen
  | #decimalEnclosedCircleChinese
  | #ideographEnclosedCircle
  | #ideographTraditional
  | #ideographZodiac
  | #ideographZodiacTraditional
  | #taiwaneseCounting
  | #ideographLegalTraditional
  | #taiwaneseCountingThousand
  | #taiwaneseDigital
  | #chineseCounting
  | #chineseLegalSimplified
  | #chineseCountingThousand
  | #koreanDigital
  | #koreanCounting
  | #koreanLegal
  | #koreanDigital2
  | #vietnameseCounting
  | #russianLower
  | #russianUpper
  | #none
  | #numberInDash
  | #hebrew1
  | #hebrew2
  | #arabicAlpha
  | #arabicAbjad
  | #hindiVowels
  | #hindiConsonants
  | #hindiNumbers
  | #hindiCounting
  | #thaiLetters
  | #thaiNumbers
  | #thaiCounting
  | #bahtText
  | #dollarText
  | #custom
]

// type t =[
//   | @as("decimal") DECIMAL
//   | @as("upperRoman") UPPER_ROMAN
//   | @as("lowerRoman") LOWER_ROMAN
//   | @as("upperLetter") UPPER_LETTER
//   | @as("lowerLetter") LOWER_LETTER
//   | @as("ordinal") ORDINAL
//   | @as("cardinalText") CARDINAL_TEXT
//   | @as("ordinalText") ORDINAL_TEXT
//   | @as("hex") HEX
//   | @as("chicago") CHICAGO
//   | @as("ideographDigital") IDEOGRAPH__DIGITAL
//   | @as("japaneseCounting") JAPANESE_COUNTING
//   | @as("aiueo") AIUEO
//   | @as("iroha") IROHA
//   | @as("decimalFullWidth") DECIMAL_FULL_WIDTH
//   | @as("decimalHalfWidth") DECIMAL_HALF_WIDTH
//   | @as("japaneseLegal") JAPANESE_LEGAL
//   | @as("japaneseDigitalTenThousand") JAPANESE_DIGITAL_TEN_THOUSAND
//   | @as("decimalEnclosedCircle") DECIMAL_ENCLOSED_CIRCLE
//   | @as("decimalFullWidth2") DECIMAL_FULL_WIDTH2
//   | @as("aiueoFullWidth") AIUEO_FULL_WIDTH
//   | @as("irohaFullWidth") IROHA_FULL_WIDTH
//   | @as("decimalZero") DECIMAL_ZERO
//   | @as("bullet") BULLET
//   | @as("ganada") GANADA
//   | @as("chosung") CHOSUNG
//   | @as("decimalEnclosedFullstop") DECIMAL_ENCLOSED_FULLSTOP
//   | @as("decimalEnclosedParen") DECIMAL_ENCLOSED_PARENTHESES
//   | @as("decimalEnclosedCircleChinese") DECIMAL_ENCLOSED_CIRCLE_CHINESE
//   | @as("ideographEnclosedCircle") IDEOGRAPH_ENCLOSED_CIRCLE
//   | @as("ideographTraditional") IDEOGRAPH_TRADITIONAL
//   | @as("ideographZodiac") IDEOGRAPH_ZODIAC
//   | @as("ideographZodiacTraditional") IDEOGRAPH_ZODIAC_TRADITIONAL
//   | @as("taiwaneseCounting") TAIWANESE_COUNTING
//   | @as("ideographLegalTraditional") IDEOGRAPH_LEGAL_TRADITIONAL
//   | @as("taiwaneseCountingThousand") TAIWANESE_COUNTING_THOUSAND
//   | @as("taiwaneseDigital") TAIWANESE_DIGITAL
//   | @as("chineseCounting") CHINESE_COUNTING
//   | @as("chineseLegalSimplified") CHINESE_LEGAL_SIMPLIFIED
//   | @as("chineseCountingThousand") CHINESE_COUNTING_THOUSAND
//   | @as("koreanDigital") KOREAN_DIGITAL
//   | @as("koreanCounting") KOREAN_COUNTING
//   | @as("koreanLegal") KOREAN_LEGAL
//   | @as("koreanDigital2") KOREAN_DIGITAL2
//   | @as("vietnameseCounting") VIETNAMESE_COUNTING
//   | @as("russianLower") RUSSIAN_LOWER
//   | @as("russianUpper") RUSSIAN_UPPER
//   | @as("none") NONE
//   | @as("numberInDash") NUMBER_IN_DASH
//   | @as("hebrew1") HEBREW1
//   | @as("hebrew2") HEBREW2
//   | @as("arabicAlpha") ARABIC_ALPHA
//   | @as("arabicAbjad") ARABIC_ABJAD
//   | @as("hindiVowels") HINDI_VOWELS
//   | @as("hindiConsonants") HINDI_CONSONANTS
//   | @as("hindiNumbers") HINDI_NUMBERS
//   | @as("hindiCounting") HINDI_COUNTING
//   | @as("thaiLetters") THAI_LETTERS
//   | @as("thaiNumbers") THAI_NUMBERS
//   | @as("thaiCounting") THAI_COUNTING
//   | @as("bahtText") BAHT_TEXT
//   | @as("dollarText") DOLLAR_TEXT
//   | @as("custom") CUSTOM
//   ]
