module MediaTypeOptions = {
  [@bs.module "expo-image-picker"] [@bs.scope "MediaTypeOptions"]
  external images: string = "Images";
  [@bs.module "expo-image-picker"] [@bs.scope "MediaTypeOptions"]
  external videos: string = "Videos";
  [@bs.module "expo-image-picker"] [@bs.scope "MediaTypeOptions"]
  external all: string = "all";
};

[@bs.deriving abstract]
type launchImageLibraryAsyncOptions = {
  mediaTypes: string,
  allowsEditing: bool,
  aspect: array(int),
  quality: float,
  base64: bool,
  exif: bool,
};

[@bs.deriving abstract]
type launchImageLibraryAsyncResult = {
  cancelled: bool,
  [@bs.optional]
  uri: string,
  [@bs.optional]
  width: float,
  [@bs.optional]
  height: float,
  [@bs.optional] [@bs.as "type"]
  _type: string,
  [@bs.optional]
  duration: float,
  [@bs.optional]
  base64: string,
  [@bs.optional]
  exif: string,
};

[@bs.module "expo-image-picker"]
external launchImageLibraryAsync:
  launchImageLibraryAsyncOptions => launchImageLibraryAsyncResult =
  "launchImageLibraryAsync";

[@bs.deriving abstract]
type launchCameraAsyncOptions = {
  allowsEditing: bool,
  aspect: array(int),
  quality: float,
  base64: bool,
  exif: bool,
};

[@bs.deriving abstract]
type launchCameraAsyncResult = {
  cancelled: bool,
  [@bs.optional]
  uri: string,
  [@bs.optional]
  width: float,
  [@bs.optional]
  height: float,
  [@bs.optional]
  duration: float,
  [@bs.optional]
  base64: string,
  [@bs.optional]
  exif: string,
};

[@bs.module "expo-image-picker"]
external launchCameraAsync: launchCameraAsyncOptions => launchCameraAsyncResult =
  "launchCameraAsync";