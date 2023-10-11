type t

type fontOptions = {
  name: string,
  hint?: string,
}

type fontAttributesProperties = {
  ascii?: string,
  eastAsia?: string,
  hAnsi?: string,
  cs?: string,
}

external fromString: string => t = "%identity"
external fromOptions: fontOptions => t = "%identity"
external fromAttributesProperties: fontAttributesProperties => t = "%identity"
