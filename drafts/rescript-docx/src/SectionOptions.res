type rec t = {
  properties?: SectionPropertiesOptions.t,
  headers?: Headers.headerFooterGroup<Headers.Header.t>,
  footers?: Headers.headerFooterGroup<Headers.Footer.t>,
  children: array<FileChild.t>,
}
