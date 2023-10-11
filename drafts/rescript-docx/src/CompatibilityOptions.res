type t = {
  version?: float,
  /** Use Simplified Rules For Table Border Conflicts */
  useSingleBorderforContiguousCells?: bool,
  /** Emulate WordPerfect 6.x Paragraph Justification */
  wordPerfectJustification?: bool,
  /** Do Not Create Custom Tab Stop for Hanging Indent */
  noTabStopForHangingIndent?: bool,
  /** Do Not Add Leading Between Lines of Text */
  noLeading?: bool,
  /** Add Additional Space Below Baseline For Underlined East Asian Text */
  spaceForUnderline?: bool,
  /** Do Not Balance Text Columns within a Section */
  noColumnBalance?: bool,
  /** Balance Single Byte and Double Byte Characters */
  balanceSingleByteDoubleByteWidth?: bool,
  /** Do Not Center Content on Lines With Exact Line Height */
  noExtraLineSpacing?: bool,
  /** Convert Backslash To Yen Sign When Entered */
  doNotLeaveBackslashAlone?: bool,
  /** Underline All Trailing Spaces */
  underlineTrailingSpaces?: bool,
  /** Don't Justify Lines Ending in Soft Line Break */
  doNotExpandShiftReturn?: bool,
  /** Only Expand/Condense Text By Whole Points */
  spacingInWholePoints?: bool,
  /** Emulate Word 6.0 Line Wrapping for East Asian Text */
  lineWrapLikeWord6?: bool,
  /** Print Body Text before Header/Footer Contents */
  printBodyTextBeforeHeader?: bool,
  /** Print Colors as Black And White without Dithering */
  printColorsBlack?: bool,
  /** Space width */
  spaceWidth?: bool,
  /** Display Page/Column Breaks Present in Frames */
  showBreaksInFrames?: bool,
  /** Increase Priority Of Font Size During Font Substitution */
  subFontBySize?: bool,
  /** Ignore Exact Line Height for Last Line on Page */
  suppressBottomSpacing?: bool,
  /** Ignore Minimum and Exact Line Height for First Line on Page */
  suppressTopSpacing?: bool,
  /** Ignore Minimum Line Height for First Line on Page */
  suppressSpacingAtTopOfPage?: bool,
  /** Emulate WordPerfect 5.x Line Spacing */
  suppressTopSpacingWP?: bool,
  /** Do Not Use Space Before On First Line After a Page Break */
  suppressSpBfAfterPgBrk?: bool,
  /** Swap Paragraph Borders on Odd Numbered Pages */
  swapBordersFacingPages?: bool,
  /** Treat Backslash Quotation Delimiter as Two Quotation Marks */
  convertMailMergeEsc?: bool,
  /** Emulate WordPerfect 6.x Font Height Calculation */
  truncateFontHeightsLikeWP6?: bool,
  /** Emulate Word 5.x for the Macintosh Small Caps Formatting */
  macWordSmallCaps?: bool,
  /** Use Printer Metrics To Display Documents */
  usePrinterMetrics?: bool,
  /** Do Not Suppress Paragraph Borders Next To Frames */
  doNotSuppressParagraphBorders?: bool,
  /** Line Wrap Trailing Spaces */
  wrapTrailSpaces?: bool,
  /** Emulate Word 6.x/95/97 Footnote Placement */
  footnoteLayoutLikeWW8?: bool,
  /** Emulate Word 97 Text Wrapping Around Floating Objects */
  shapeLayoutLikeWW8?: bool,
  /** Align Table Rows Independently */
  alignTablesRowByRow?: bool,
  /** Ignore Width of Last Tab Stop When Aligning Paragraph If It Is Not Left Aligned */
  forgetLastTabAlignment?: bool,
  /** Add Document Grid Line Pitch To Lines in Table Cells */
  adjustLineHeightInTable?: bool,
  /** Emulate Word 95 Full-Width Character Spacing */
  autoSpaceLikeWord95?: bool,
  /** Do Not Increase Line Height for Raised/Lowered Text */
  noSpaceRaiseLower?: bool,
  /** Use Fixed Paragraph Spacing for HTML Auto Setting */
  doNotUseHTMLParagraphAutoSpacing?: bool,
  /** Ignore Space Before Table When Deciding If Table Should Wrap Floating Object */
  layoutRawTableWidth?: bool,
  /** Allow Table Rows to Wrap Inline Objects Independently */
  layoutTableRowsApart?: bool,
  /** Emulate Word 97 East Asian Line Breaking */
  useWord97LineBreakRules?: bool,
  /** Do Not Allow Floating Tables To Break Across Pages */
  doNotBreakWrappedTables?: bool,
  /** Do Not Snap to Document Grid in Table Cells with Objects */
  doNotSnapToGridInCell?: bool,
  /** Select Field When First or Last Character Is Selected */
  selectFieldWithFirstOrLastCharacter?: bool,
  /** Use Legacy Ethiopic and Amharic Line Breaking Rules */
  applyBreakingRules?: bool,
  /** Do Not Allow Hanging Punctuation With Character Grid */
  doNotWrapTextWithPunctuation?: bool,
  /** Do Not Compress Compressible Characters When Using Document Grid */
  doNotUseEastAsianBreakRules?: bool,
  /** Emulate Word 2002 Table Style Rules */
  useWord2002TableStyleRules?: bool,
  /** Allow Tables to AutoFit Into Page Margins */
  growAutofit?: bool,
  /** Do Not Bypass East Asian/Complex Script Layout Code */
  useFELayout?: bool,
  /** Do Not Automatically Apply List Paragraph Style To Bulleted/Numbered Text */
  useNormalStyleForList?: bool,
  /** Ignore Hanging Indent When Creating Tab Stop After Numbering */
  doNotUseIndentAsNumberingTabStop?: bool,
  /** Use Alternate Set of East Asian Line Breaking Rules */
  useAlternateEastAsianLineBreakRules?: bool,
  /** Allow Contextual Spacing of Paragraphs in Tables */
  allowSpaceOfSameStyleInTable?: bool,
  /** Do Not Ignore Floating Objects When Calculating Paragraph Indentation */
  doNotSuppressIndentation?: bool,
  /** Do Not AutoFit Tables To Fit Next To Wrapped Objects */
  doNotAutofitConstrainedTables?: bool,
  /** Allow Table Columns To Exceed Preferred Widths of Constituent Cells */
  autofitToFirstFixedWidthCell?: bool,
  /** Underline Following Character Following Numbering */
  underlineTabInNumberingList?: bool,
  /** Always Use Fixed Width for Hangul Characters */
  displayHangulFixedWidth?: bool,
  /** Always Move Paragraph Mark to Page after a Page Break */
  splitPgBreakAndParaMark?: bool,
  /** Don't Vertically Align Cells Containing Floating Objects */
  doNotVerticallyAlignCellWithSp?: bool,
  /** Don't Break Table Rows Around Floating Tables */
  doNotBreakConstrainedForcedTable?: bool,
  /** Ignore Vertical Alignment in Textboxes */
  ignoreVerticalAlignmentInTextboxes?: bool,
  /** Use ANSI Kerning Pairs from Fonts */
  useAnsiKerningPairs?: bool,
  /** Use Cached Paragraph Information for Column Balancing */
  cachedColumnBalance?: bool,
}
