# rescript-chokidar

ReScript bindings for [chokidar](https://github.com/paulmillr/chokidar)

## Installation

```sh
npm i rescript-chokidar
```

In your `bsconfig.json` add it to `bs-dependencies`

```
{
  ...,
  "bs-dependencies": [..., "rescript-chokidar"],
}
```

## Examples

```rescript
// One-liner for current directory
Chokidar.watch(".")->Chokidar.on(#all((. event, path, _) => Js.log2(event, path)))->ignore
```

```rescript
// Example of a more typical implementation structure

// Initialize watcher.
let watcher = Chokidar.watch(
  ~options=Chokidar.options(
    ~ignored=[Anymatch.regex(%re("/(^|[\/\\])\../"))],
    ~persistent=true,
    (),
  ),
  "file, dir, glob, or array",
)

// Add event listeners.
watcher
->Chokidar.on(#add((. path, _) => Js.log(`File ${path} has been added`)))
->Chokidar.on(#change((. path, _) => Js.log(`File ${path} has been changed`)))
->Chokidar.on(#unlink((. path) => Js.log(`File ${path} has been removed`)))
->ignore

// More possible events.
watcher
->Chokidar.on(#addDir((. path, _) => Js.log(`Directory ${path} has been added`)))
->Chokidar.on(#unlinkDir((. path) => Js.log(`Directory ${path} has been removed`)))
->Chokidar.on(#error((. error) => Js.log(j`Watcher error: $error`)))
->Chokidar.on(#ready(() => Js.log("Initial scan complete. Ready for changes")))
->Chokidar.on(
  #raw(
    (event, path, details) => {
      // internal
      Js.log4("Raw event info:", event, path, details)
    },
  ),
)
->ignore

// 'add', 'addDir' and 'change' events also receive stat() results as second
// argument when available: https://nodejs.org/api/fs.html#fs_class_fs_stats
@get external size: Chokidar.stats => int = "size"
watcher
->Chokidar.on(
  #change(
    (. path, stats) =>
      switch stats {
      | None => ()
      | Some(val) => Js.log(`File ${path} changed size to ${val->size->Js.Int.toString}`)
      },
  ),
)
->ignore

// Watch new files.
watcher->Chokidar.add("new-file")->ignore
watcher->Chokidar.addMany(["new-file-2", "new-file-3", "**/other-file*"])->ignore

// Get list of actual paths being watched on the filesystem
let watchedPaths = watcher->Chokidar.getWatched

// Un-watch some files.
watcher->Chokidar.unwatch("new-file*")->ignore

// Stop watching.
// The method is async!
watcher->Chokidar.close->Js.Promise.then_(() => {
  Js.log("closed")
  Js.Promise.resolve()
}, _)->ignore

// Full list of options.
// Do not use this example!
Chokidar.watch(
  ~options=Chokidar.options(
    ~persistent=true,
    ~ignored=[Anymatch.glob("*.txt")],
    ~ignoreInitial=false,
    ~followSymlinks=true,
    ~cwd=".",
    ~disableGlobbing=false,
    ~usePolling=false,
    ~interval=100,
    ~binaryInterval=300,
    ~alwaysStat=false,
    ~depth=99,
    ~awaitWriteFinish=Chokidar.awaitWriteFinishCustom(
      ~stabilityThreshold=2000,
      ~pollInterval=100,
      (),
    ),
    ~ignorePermissionErrors=false,

    // or a custom 'atomicity delay' (Chokidar.atomicCustom), in milliseconds (default 100)
    ~atomic=Chokidar.atomicOn,
    (),
  ),
  "file",
)->ignore
```

## Caveats

- A `watcher` extends [`EventEmmiter`](https://nodejs.org/api/events.html#class-eventemitter) so it has more methods like `removeAllListeners()` etc. I didn't define them. If you need some of these methods, open an issue or a PR.

- Some listeners take an instance of [`fs.Stats`](https://nodejs.org/api/fs.html#class-fsstats) as an argument. Unfortunately, there're no official bindings that would define it. Maybe they'll appear at some point, but in meantime it's defined as an abstract type `Chokidar.stats`. You can define your own accesors, or use a library like [rescript-nodejs](https://github.com/TheSpyder/rescript-nodejs) with a converter defined as `external convertStats: Chokidar.stats => NodeJs.Fs.Stats.t = "%identity"`
