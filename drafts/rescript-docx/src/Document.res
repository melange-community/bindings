type t

type features = {
  trackRevisions?: bool,
  updateFields?: bool,
}

type customPropertyOptions = {
  name: string,
  value: string,
}

type rec footnotes = Js.Dict.t<footnote>
and footnote = {children: array<Paragraph.t>}

type options = {
  sections: array<SectionOptions.t>,
  title?: string,
  subject?: string,
  creator?: string,
  keywords?: string,
  description?: string,
  lastModifiedBy?: string,
  revision?: float,
  externalStyles?: string,
  styles?: StylesOptions.t,
  numbering?: NumberingOptions.t,
  comments?: CommentsOptions.t,
  footnotes?: footnotes,
  background?: DocumentBackgroundOptions.t,
  features?: features,
  compatabilityModeVersion?: float,
  compatibility?: CompatibilityOptions.t,
  customProperties?: array<customPropertyOptions>,
  evenAndOddHeaderAndFooters?: bool,
}

@module("docx") @new
external make: options => t = "Document"
