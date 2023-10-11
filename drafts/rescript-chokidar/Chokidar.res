type atomicOption
let atomicCustom = (ms: int): atomicOption => Obj.magic(ms)
let atomicOn: atomicOption = Obj.magic(true)
let atomicOff: atomicOption = Obj.magic(false)

type awaitWriteFinishOption
let awaitWriteFinishOn: awaitWriteFinishOption = Obj.magic(true)
let awaitWriteFinishOff: awaitWriteFinishOption = Obj.magic(false)
@obj
external awaitWriteFinishCustom: (
  ~stabilityThreshold: int=?,
  ~pollInterval: int=?,
  unit,
) => awaitWriteFinishOption = ""

@deriving(abstract)
type options = {
  @optional persistent: bool,
  @optional ignored: array<Anymatch.matcher>,
  @optional ignoreInitial: bool,
  @optional followSymlinks: bool,
  @optional cwd: string,
  @optional disableGlobbing: bool,
  @optional usePolling: bool,
  @optional interval: int,
  @optional binaryInterval: int,
  @optional useFsEvents: bool,
  @optional alwaysStat: bool,
  @optional depth: int,
  @optional ignorePermissionErrors: bool,
  @optional atomic: atomicOption,
  @optional awaitWriteFinish: awaitWriteFinishOption,
}

type watcher

@module("chokidar") @val external watch: (string, option<options>) => watcher = "watch"
let watch = (~options=?, dir) => watch(dir, options)

@module("chokidar") @val external watchMany: (array<string>, option<options>) => watcher = "watch"
let watchMany = (~options=?, dirs) => watchMany(dirs, options)

@send external add: (watcher, string) => watcher = "add"
@send external addMany: (watcher, array<string>) => watcher = "add"

@send external unwatch: (watcher, string) => watcher = "unwatch"
@send external unwatchMany: (watcher, array<string>) => watcher = "unwatch"

@send external getWatched: watcher => Js.Dict.t<array<string>> = "getWatched"

@send external close: watcher => Js.Promise.t<unit> = "close"

@ocaml.doc("https://nodejs.org/api/fs.html#class-fsstats")
type stats

@ocaml.doc("No bindings as there's no documentation")
type rawDetails

@send
external on: (
  watcher,
  @string
  [
    | #add((. string, option<stats>) => unit)
    | #addDir((. string, option<stats>) => unit)
    | #change((. string, option<stats>) => unit)
    | #unlink((. string) => unit)
    | #unlinkDir((. string) => unit)
    | #all((. [#add | #addDir | #change | #unlink | #unlinkDir], string, option<stats>) => unit)
    | #error((. Js.Exn.t) => unit)
    | #ready(unit => unit)
    | #raw((string, string, rawDetails) => unit)
  ],
) => watcher = "on"

@send
external once: (
  watcher,
  @string
  [
    | #add((. string, option<stats>) => unit)
    | #addDir((. string, option<stats>) => unit)
    | #change((. string, option<stats>) => unit)
    | #unlink((. string) => unit)
    | #unlinkDir((. string) => unit)
    | #all((. [#add | #addDir | #change | #unlink | #unlinkDir], string, option<stats>) => unit)
    | #error((. Js.Exn.t) => unit)
    | #ready(unit => unit)
    | #raw((string, string, rawDetails) => unit)
  ],
) => watcher = "once"

@send
external off: (
  watcher,
  @string
  [
    | #add((. string, option<stats>) => unit)
    | #addDir((. string, option<stats>) => unit)
    | #change((. string, option<stats>) => unit)
    | #unlink((. string) => unit)
    | #unlinkDir((. string) => unit)
    | #all((. [#add | #addDir | #change | #unlink | #unlinkDir], string, option<stats>) => unit)
    | #error((. Js.Exn.t) => unit)
    | #ready(unit => unit)
    | #raw((string, string, rawDetails) => unit)
  ],
) => watcher = "removeListener"
