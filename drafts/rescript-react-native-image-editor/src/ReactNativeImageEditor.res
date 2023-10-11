type source

external fromRequired: ReactNative.Packager.required => source = "%identity"
external fromUriSource: string => source = "%identity"

type offset

@obj external offset: (~x: int, ~y: int) => offset = ""

type size

@obj external size: (~width: int, ~height: int) => size = ""

type cropData

@obj
external cropData: (
  ~offset: offset,
  ~size: size,
  ~displaySize: size=?,
  ~resizeMode: [#contain | #cover | #stretch]=?,
  unit,
) => cropData = ""

@module("@react-native-community/image-editor") @scope("default")
external cropImage: (source, cropData) => Js.Promise.t<string> = "cropImage"
