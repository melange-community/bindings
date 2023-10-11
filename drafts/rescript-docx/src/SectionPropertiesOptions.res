type rec t = {
  page?: page,
  grid?: DocGridAttributesProperties.t,
  headerWrapperGroup?: Headers.headerFooterGroup<Headers.HeaderWrapper.t>,
  footerWrapperGroup?: Headers.headerFooterGroup<Headers.FooterWrapper.t>,
  lineNumbers?: LineNumberAttributes.t,
  titlePage?: bool,
  vertialAlign?: [#bottom | #center | #top],
  column?: Columns.attributes,
  @as("type") type_?: [#nextPage | #nextColumn | #continuous | #evenPage | #oddPage],
}
and page = {
  size?: PageSizeAttributes.t,
  margin?: PageMarginAttributes.t,
  pageNumbers?: PageNumberTypeAttributes.t,
  borders?: PageBorderAttributes.t,
  textDirection?: PageTextDirectionType.t,
}
