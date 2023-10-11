type t = Util.Types.paragraph

type bullet = {level: int}

type options = {
  /* -> To factorize with the v11 record spread notation */
  alignment?: AlignmentType.t,
  thematicBreak?: bool,
  contextualSpacing?: bool,
  rightTabStop?: float,
  leftTabStop?: float,
  indent?: IndentAttributesProperties.t,
  spacing?: SpacingProperties.t,
  keepNext?: bool,
  keepLines?: bool,
  outlineLevel?: float,
  numbering?: Util.Types.numbering,
  border?: BordersOptions.t,
  heading?: HeadingLevel.t,
  bidirectional?: bool,
  pageBreakBefore?: bool,
  tabStops?: array<TabStopDefinition.t>,
  shading?: ShadingAttributesProperties.t,
  widowControl?: bool,
  frame?: FrameOptions.t,
  suppressLineNumbers?: bool,
  wordWrap?: bool,
  scale?: float,
  autoSpaceEastAsianText?: bool,
  /* <- */
  text?: string,
  children?: array<ParagraphChild.t>,
}

@module("docx") @new
external make: string => t = "Paragraph"

@module("docx") @new
external make': options => t = "Paragraph"
