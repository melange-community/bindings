type levelStyle = {
  run?: RunStylePropertiesOptions.t,
  paragraph?: LevelParagraphStylePropertiesOptions.t,
}

type levelOptions = {
  level: int,
  format?: LevelFormat.t,
  text?: string,
  alignment?: AlignmentType.t,
  start?: float,
  suffix?: LevelSuffix.t,
  isLegalNumberingStyle?: bool,
  style?: levelStyle,
}

type numberingOption = {
  levels: array<levelOptions>,
  reference: string,
}

type t = {config: array<numberingOption>}
