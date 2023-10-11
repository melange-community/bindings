type album = {
  title: string,
  count: int,
}

@module("@react-native-community/cameraroll")
external deletePhotos: array<string> => Js.Promise.t<unit> = "deletePhotos"

type getAlbumsParams

@obj
external getAlbumsParams: (~assetType: [#All | #Photos | #Videos]) => getAlbumsParams = ""

// multiple externals
@module("@react-native-community/cameraroll")
external getAlbums: unit => Js.Promise.t<array<album>> = "getAlbums"

// multiple externals
@module("@react-native-community/cameraroll")
external getAlbumsWithParams: getAlbumsParams => Js.Promise.t<array<album>> = "getAlbums"

type getPhotosParams

@obj
external getPhotosParams: (
  ~first: int,
  ~after: string=?,
  ~groupTypes: [
    | #Album
    | #All
    | #Event
    | #Faces
    | #Library
    | #PhotoStream
    | #SavedPhotos
  ]=?,
  ~groupName: string=?,
  ~assetType: [#All | #Videos | #Photos]=?,
  ~mimeTypes: array<string>=?,
  ~fromTime: float=?,
  ~toTime: float=?,
  ~include_: array<string>=?,
  unit,
) => getPhotosParams = ""

type rec photoIdentifier = {node: node}
and node = {
  \"type": string,
  group_name: string,
  image: image,
  timestamp: float,
  location: Js.Nullable.t<location>,
}
and image = {
  filename: Js.Nullable.t<string>,
  uri: string,
  height: Js.Nullable.t<float>,
  width: Js.Nullable.t<float>,
  fileSize: Js.Nullable.t<float>,
  playableDuration: Js.Nullable.t<float>,
}
and location = {
  latitude: Js.Nullable.t<float>,
  longitude: Js.Nullable.t<float>,
  altitude: Js.Nullable.t<float>,
  heading: Js.Nullable.t<float>,
  speed: Js.Nullable.t<float>,
}

type rec photoIdentifiersPage = {
  edges: array<photoIdentifier>,
  page_info: pageInfo,
}
and pageInfo = {
  has_next_page: bool,
  start_cursor: Js.Nullable.t<string>,
  end_curson: Js.Nullable.t<string>,
}

type saveOptions

@obj
external saveOptions: (~_type: [#auto | #photo | #video], ~album: string) => saveOptions = ""

// multiple externals
@module("@react-native-community/cameraroll")
external save: string => Js.Promise.t<string> = "save"

// multiple externals
@module("@react-native-community/cameraroll")
external saveWithOptions: (string, saveOptions) => Js.Promise.t<string> = "save"

// multiple externals
@module("@react-native-community/cameraroll")
external saveToCameraRoll: string => Js.Promise.t<string> = "saveToCameraRoll"

// multiple externals
@module("@react-native-community/cameraroll")
external saveToCameraRollWithType: (string, ~_type: [#photo | #video]) => Js.Promise.t<string> =
  "saveToCameraRoll"

@module("@react-native-community/cameraroll")
external getPhotos: getPhotosParams => Js.Promise.t<photoIdentifiersPage> = "getPhotos"
