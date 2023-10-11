open Util

type underline = {
  color?: string,
  @as("type") type_?: UnderlineType.t,
}

type emphasisMark = {@as("type") type_?: EmphasisMarkType.t}

type languageOptions = {
  value?: string,
  eastAsia?: string,
  bidirectional?: string,
}

type t = {
  noProof?: bool,
  bold?: bool,
  boldComplexScript?: bool,
  italics?: bool,
  italicsComplexScript?: bool,
  underline?: underline,
  effect?: TextEffect.t,
  emphasisMark?: emphasisMark,
  color?: string,
  kern?: Types.NumberOrPositiveUniversalMeasure.t,
  position?: Types.NumberOrUniversalMeasure.t,
  size?: Types.NumberOrPositiveUniversalMeasure.t,
  sizeComplexScript?: Types.BoolOrNumberOrUniversalMeasure.t,
  rightToLeft?: bool,
  smallCaps?: bool,
  allCaps?: bool,
  strike?: bool,
  doubleStrike?: bool,
  subScript?: bool,
  superScript?: bool,
  font?: Font.t,
  highlight?: string,
  highlightComplexScript?: Types.BoolOrString.t,
  characterSpacing?: float,
  shading?: ShadingAttributesProperties.t,
  emboss?: bool,
  imprint?: bool,
  language?: languageOptions,
  border?: BorderOptions.t,
  snapToGrid?: bool,
  vanish?: bool,
  specVanish?: bool,
  scale?: float,
  math?: bool,
  // TODO:
  // revision?: RunPropertiesChangeOptions.t,
}
