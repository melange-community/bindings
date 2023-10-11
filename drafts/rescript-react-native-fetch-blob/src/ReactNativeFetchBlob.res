type t
@module("rn-fetch-blob") external fetchBlob: t = "default"

module Config = {
  @deriving({abstract: light})
  type t = {
    @optional
    fileCache: bool,
    @optional
    appendExt: string,
    @optional
    path: string,
    @optional
    key: string,
    @optional
    timeout: int,
    @optional
    wifiOnly: bool,
  }
}

module ResponseInfo = {
  type t
  @get external headers: t => Js.Dict.t<string> = "headers"
  @get external status: t => int = "status"
}

module Response = {
  type t
  @send external info: t => ResponseInfo.t = "info"
  @send external text: t => string = "text"
  @send external json: t => Js.Json.t = "json"

  /* For file downloads */
  @send external path: t => string = "path"
}

module Fetch = {
  type t
  @send
  external fetch: (
    t,
    ~method: string,
    ~url: string,
    ~headers: {.},
    ~body: 'a,
  ) => Js.Promise.t<Response.t> = "fetch"
}

module Fs = {
  module Stat = {
    @deriving({abstract: light})
    type t = {
      filename: string,
      path: string,
      size: int,
      @as("type")
      type_: string,
      lastModified: float,
    }
  }

  type dirs

  @get external documentDir: dirs => string = "DocumentDir"
  @get external cacheDir: dirs => string = "CacheDir"

  /* Can be used to access files embedded on iOS apps only */
  @get external mainBundleDir: dirs => string = "MainBundleDir"

  /* Android Only */
  @get external dcimDir: dirs => string = "DCIMDir"
  @get external downloadDir: dirs => string = "DownloadDir"
  @get external musicDir: dirs => string = "MusicDir"
  @get external pictureDir: dirs => string = "PictureDir"
  @get external movieDir: dirs => string = "MovieDir"
  @get external ringtoneDir: dirs => string = "RingtoneDir"
  @get external sdCardDir: dirs => string = "SDCardDir"

  type t

  @get external dirs: t => dirs = "dirs"
  @send
  external cp: (t, ~from: string, ~to_: string) => Js.Promise.t<unit> = "from"
  @send
  external unlink: (t, ~path: string) => Js.Promise.t<unit> = "unlink"
  @send
  external mkdir: (t, ~path: string) => Js.Promise.t<unit> = "mkdir"
  @send
  external exists: (t, ~path: string) => Js.Promise.t<bool> = "exists"
  @send
  external lstat: (t, ~path: string) => Js.Promise.t<array<Stat.t>> = "path"
  @send
  external stat: (t, ~path: string) => Js.Promise.t<Stat.t> = "stat"
  @send
  external readFile: (t, ~path: string, ~encoding: string) => Js.Promise.t<string> = "readFile"
  @send external asset: (t, ~path: string) => string = "asset"
}

@send external config: (t, Config.t) => Fetch.t = "config"
@get external fs: t => Fs.t = "fs"

type data

@send external wrap: (t, ~path: string) => data = "wrap"
