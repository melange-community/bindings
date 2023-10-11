module Dirent = {
  type t;
  [@bs.send] external isBlockDevice: t => bool = "isBlockDevice";
  [@bs.send] external isCharacterDevice: t => bool = "isCharacterDevice";
  [@bs.send] external isDirectory: t => bool = "isDirectory";
  [@bs.send] external isFIFO: t => bool = "isFIFO";
  [@bs.send] external isFile: t => bool = "isFile";
  [@bs.send] external isSocket: t => bool = "isSocket";
  [@bs.send] external isSymbolicLink: t => bool = "isSymbolicLink";
  [@bs.get] external name: t => string = "name";
};

module Dir = {
  type t;
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send]
  external closeWithCallback: (t, Js.nullable(Js.Exn.t) => unit) => unit =
    "close";
  [@bs.send] external closeSync: t => unit = "closeSync";
  [@bs.get] external path: t => string = "path";
  [@bs.send]
  external read: t => Js.Promise.t(Js.nullable(Dirent.t)) = "read";
  [@bs.send]
  external readWithCallback:
    (t, (Js.Exn.t, Js.nullable(Dirent.t)) => unit) => unit =
    "read";
  [@bs.send] external readSync: t => Js.nullable(Dirent.t) = "readSync";
};

module Stats = {
  type t = {
    dev: int,
    ino: int,
    mode: int,
    nlink: int,
    uid: int,
    gid: int,
    rdev: int,
    size: int,
    blksize: int,
    blocks: int,
    atimeMs: float,
    mtimeMs: float,
    ctimeMs: float,
    birthtimeMs: float,
    atime: string,
    mtime: string,
    ctime: string,
    birthtime: string,
  };

  /** `isFile(stats)` Returns true if the `stats` object describes a file. */
  [@bs.send]
  external isFile: t => bool = "isFile";
  /** `isDirectory(stats)` Returns true if the `stats` object describes a directory. */
  [@bs.send]
  external isDirectory: t => bool = "isDirectory";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a block device. */
  [@bs.send]
  external isBlockDevice: t => bool = "isBlockDevice";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a character device. */
  [@bs.send]
  external isCharacterDevice: t => bool = "isCharacterDevice";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a symbolic link. */
  [@bs.send]
  external isSymbolicLink: t => bool = "isSymbolicLink";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a first-in-first-out (FIFO) pipe. */
  [@bs.send]
  external isFIFO: t => bool = "isFIFO";
  /** `isBlockDevice(stats)` Returns true if the `stats` object describes a socket. */
  [@bs.send]
  external isSocket: t => bool = "isSocket";
};

module Constants = {
  type t = pri int;

  /** Bitwise 'or' i.e. JavaScript [x | y] */
  external (lor): (t, t) => t = "%orint";

  [@text "{1 File Access Constants}"];

  [@bs.module "fs"] [@bs.scope "constants"] external f_ok: t = "F_OK";
  [@bs.module "fs"] [@bs.scope "constants"] external w_ok: t = "W_OK";
  [@bs.module "fs"] [@bs.scope "constants"] external r_ok: t = "R_OK";
  [@bs.module "fs"] [@bs.scope "constants"] external x_ok: t = "X_OK";

  [@text "{1 File Copy Constants}"];

  [@bs.module "fs"] [@bs.scope "constants"] external copyfile_excl: t = "COPYFILE_EXCL";
  [@bs.module "fs"] [@bs.scope "constants"] external copyfile_ficlone: t = "COPYFILE_FICLONE";
  [@bs.module "fs"] [@bs.scope "constants"] external copyfile_ficlone_force: t = "COPYFILE_FICLONE_FORCE";

  [@text "{1 File Open Constants}"];

  [@bs.module "fs"] [@bs.scope "constants"] external o_rdonly: t = "O_RDONLY";
  [@bs.module "fs"] [@bs.scope "constants"] external o_wronly: t = "O_WRONLY";
  [@bs.module "fs"] [@bs.scope "constants"] external o_rdwr: t = "O_RDWR";
  [@bs.module "fs"] [@bs.scope "constants"] external o_creat: t = "O_CREAT";
  [@bs.module "fs"] [@bs.scope "constants"] external o_excl: t = "O_EXCL";
  [@bs.module "fs"] [@bs.scope "constants"] external o_noctty: t = "O_NOCTTY";
  [@bs.module "fs"] [@bs.scope "constants"] external o_trunc: t = "O_TRUNC";
  [@bs.module "fs"] [@bs.scope "constants"] external o_append: t = "O_APPEND";
  [@bs.module "fs"] [@bs.scope "constants"] external o_directory: t = "O_DIRECTORY";
  [@bs.module "fs"] [@bs.scope "constants"] external o_noatime: t = "O_NOATIME";
  [@bs.module "fs"] [@bs.scope "constants"] external o_nofollow: t = "O_NOFOLLOW";
  [@bs.module "fs"] [@bs.scope "constants"] external o_sync: t = "O_SYNC";
  [@bs.module "fs"] [@bs.scope "constants"] external o_dsync: t = "O_DSYNC";
  [@bs.module "fs"] [@bs.scope "constants"] external o_symlink: t = "O_SYMLINK";
  [@bs.module "fs"] [@bs.scope "constants"] external o_direct: t = "O_DIRECT";
  [@bs.module "fs"] [@bs.scope "constants"] external o_nonblock: t = "O_NONBLOCK";

  [@text "{1 File Type Constants}"];

  [@bs.module "fs"] [@bs.scope "constants"] external s_ifmt: t = "S_IFMT";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ifreg: t = "S_IFREG";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ifdir: t = "S_IFDIR";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ifchr: t = "S_IFCHR";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ifblk: t = "S_IFBLK";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ififo: t = "S_IFIFO";
  [@bs.module "fs"] [@bs.scope "constants"] external s_iflnk: t = "S_IFLNK";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ifsock: t = "S_IFSOCK";

  [@text "{1 File Mode Constants}"];

  [@bs.module "fs"] [@bs.scope "constants"] external s_irwxu: t = "S_IRWXU";
  [@bs.module "fs"] [@bs.scope "constants"] external s_irusr: t = "S_IRUSR";
  [@bs.module "fs"] [@bs.scope "constants"] external s_iwusr: t = "S_IWUSR";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ixusr: t = "S_IXUSR";
  [@bs.module "fs"] [@bs.scope "constants"] external s_irwxg: t = "S_IRWXG";
  [@bs.module "fs"] [@bs.scope "constants"] external s_irgrp: t = "S_IRGRP";
  [@bs.module "fs"] [@bs.scope "constants"] external s_iwgrp: t = "S_IWGRP";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ixgrp: t = "S_IXGRP";
  [@bs.module "fs"] [@bs.scope "constants"] external s_irwxo: t = "S_IRWXO";
  [@bs.module "fs"] [@bs.scope "constants"] external s_iroth: t = "S_IROTH";
  [@bs.module "fs"] [@bs.scope "constants"] external s_iwoth: t = "S_IWOTH";
  [@bs.module "fs"] [@bs.scope "constants"] external s_ixoth: t = "S_IXOTH";
};

module Flag: {
  type t = pri string;

  [@bs.inline "r"]
  let read: t;
  [@bs.inline "r+"]
  let readWrite: t;
  [@bs.inline "rs+"]
  let readWriteSync: t;
  [@bs.inline "w"]
  let write: t;
  [@bs.inline "wx"]
  let writeFailIfExists: t;
  [@bs.inline "w+"]
  let writeRead: t;
  [@bs.inline "wx+"]
  let writeReadFailIfExists: t;
  [@bs.inline "a"]
  let append: t;
  [@bs.inline "ax"]
  let appendFailIfExists: t;
  [@bs.inline "a+"]
  let appendRead: t;
  [@bs.inline "ax+"]
  let appendReadFailIfExists: t;
} = {
  type t = string;
  [@bs.inline "r"]
  let read = "r";
  [@bs.inline "r+"]
  let readWrite = "r+";
  [@bs.inline "rs+"]
  let readWriteSync = "rs+";
  [@bs.inline "w"]
  let write = "w";
  [@bs.inline "wx"]
  let writeFailIfExists = "wx";
  [@bs.inline "w+"]
  let writeRead = "w+";
  [@bs.inline "wx+"]
  let writeReadFailIfExists = "wx+";
  [@bs.inline "a"]
  let append = "a";
  [@bs.inline "ax"]
  let appendFailIfExists = "ax";
  [@bs.inline "a+"]
  let appendRead = "a+";
  [@bs.inline "ax+"]
  let appendReadFailIfExists = "ax+";
};

type fd = pri int;

type writeFileOptions;
[@bs.obj]
external writeFileOptions:
  (~mode: int=?, ~flag: string=?, unit) => writeFileOptions;

type appendFileOptions;
[@bs.obj]
external appendFileOptions:
  (~mode: int=?, ~flag: Flag.t=?, unit) => appendFileOptions;

type readFileOptions;
[@bs.obj] external readFileOptions: (~flag: Flag.t=?, unit) => readFileOptions;

/**
 * `readdirSync(path)`
 * Reads the contents of a directory, returning an array of strings representing
 * the paths of files and sub-directories. **Execution is synchronous and blocking**.
 */
[@bs.module "fs"]
external readdirSync: string => array(string) = "readdirSync";

/**
 * `renameSync(~oldPath, ~newPath)
 * Renames/moves the file located at `~oldPath` to `~newPath`. **Execution is
 * synchronous and blocking**.
 */
[@bs.module "fs"]
external renameSync: (~from: string, ~to_: string) => unit = "renameSync";
[@bs.module "fs"] external ftruncateSync: (fd, int) => unit = "ftruncateSync";
[@bs.module "fs"]
external truncateSync: (string, int) => unit = "truncateSync";
[@bs.module "fs"]
external chownSync: (string, ~uid: int, ~gid: int) => unit = "chownSync";
[@bs.module "fs"]
external fchownSync: (fd, ~uid: int, ~gid: int) => unit = "fchownSync";
[@bs.module "fs"] external readlinkSync: string => string = "readlinkSync";
[@bs.module "fs"] external unlinkSync: string => unit = "unlinkSync";

/**
 * `rmdirSync(dirPath)
 * **Note: (recursive removal is experimental).**
 * Removes the directory at `dirPath`. **Execution is synchronous and blocking**.
 */
[@bs.module "fs"]
external rmdirSync: string => unit = "rmdirSync";

[@bs.module "fs"] external openSync: string => fd = "openSync";
[@bs.module "fs"]
external openSyncWith: (string, ~flag: Flag.t=?, ~mode: int=?) => fd =
  "openSync";

[@bs.module "fs"]
external readFileSync: (string, ~options: readFileOptions=?, unit) => Buffer.t =
  "readFileSync";
[@bs.module "fs"] external existsSync: string => bool = "existsSync";

type writeFileSyncOptions;
[@bs.obj]
external writeFileSyncOptions:
  (~mode: int=?, ~flag: Flag.t=?, unit) => writeFileSyncOptions;

[@bs.val] [@bs.module "fs"]
external writeFileSync: (string, Buffer.t) => unit = "writeFileSync";
[@bs.val] [@bs.module "fs"]
external writeFileSyncWith: (string, Buffer.t, writeFileSyncOptions) => unit =
  "writeFileSync";

module FileHandle = {
  type t;

  [@bs.send]
  external appendFile: (t, Buffer.t, appendFileOptions) => Js.Promise.t(unit) =
    "appendFile";
  [@bs.send]
  external appendFileWith: (t, Buffer.t) => Js.Promise.t(unit) = "appendFile";
  [@bs.send] external chmod: (t, int) => Js.Promise.t(unit) = "chmod";
  [@bs.send] external chown: (t, int, int) => Js.Promise.t(unit) = "chown";
  [@bs.send] external close: t => Js.Promise.t(unit) = "close";
  [@bs.send] external datasync: t => Js.Promise.t(unit) = "datasync";
  [@bs.get] external fd: t => fd = "fd";

  type readInfo = {
    bytesRead: int,
    buffer: Buffer.t,
  };

  [@bs.send]
  external read:
    (t, Buffer.t, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(readInfo) =
    "read";
  [@bs.send] external readFile: t => Js.Promise.t(Buffer.t) = "readFile";
  [@bs.send]
  external readFileWith: (t, ~encoding: string) => Js.Promise.t(string) =
    "readFile";

  [@bs.send] external stat: t => Js.Promise.t(Stats.t) = "stat";
  [@bs.send] external sync: t => Js.Promise.t(unit) = "sync";
  [@bs.send]
  external truncate: (t, ~length: int=?, unit) => Js.Promise.t(unit) =
    "truncate";

  type writeInfo = {bytesWritten: int};

  [@bs.send]
  external write: (t, Buffer.t) => Js.Promise.t(writeInfo) = "write";
  [@bs.send]
  external writeOffset: (t, Buffer.t, ~offset: int) => Js.Promise.t(writeInfo) =
    "write";
  [@bs.send]
  external writeRange:
    (t, Buffer.t, ~offset: int, ~length: int, ~position: int) =>
    Js.Promise.t(writeInfo) =
    "write";

  type writeFileOptions;
  [@bs.obj]
  external writeFileOptions:
    (~mode: int=?, ~flag: Flag.t=?, unit) => writeFileOptions;

  [@bs.send]
  external writeFile: (t, Buffer.t) => Js.Promise.t(unit) = "writeFile";
  [@bs.send]
  external writeFileWith:
    (t, Buffer.t, writeFileOptions) => Js.Promise.t(unit) =
    "writeFile";
};

[@bs.module "fs"] [@bs.scope "promises"]
external access: string => Js.Promise.t(unit) = "access";
[@bs.module "fs"] [@bs.scope "promises"]
external accessWithMode: (string, ~mode: int) => Js.Promise.t(unit) =
  "access";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFile: (string, string, appendFileOptions) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileWith:
  (string, string, appendFileOptions) => Js.Promise.t(unit) =
  "appendFile";

type appendFileBufferOptions;
[@bs.obj]
external appendFileBufferOptions:
  (~mode: int=?, ~flag: Flag.t=?, unit) => appendFileBufferOptions;

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileBuffer: (string, Buffer.t) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external appendFileBufferWith:
  (string, Buffer.t, appendFileBufferOptions) => Js.Promise.t(unit) =
  "appendFile";

[@bs.module "fs"] [@bs.scope "promises"]
external chmod: (string, ~mode: int) => Js.Promise.t(unit) = "chmod";

[@bs.module "fs"] [@bs.scope "promises"]
external chown: (string, ~uid: int, ~gid: int) => Js.Promise.t(unit) =
  "chown";

[@bs.module "fs"] [@bs.scope "promises"]
external copyFile: (string, ~dest: string) => Js.Promise.t(unit) = "copyFile";

[@bs.module "fs"] [@bs.scope "promises"]
external copyFileFlag:
  (string, ~dest: string, ~flags: Constants.t) => Js.Promise.t(unit) =
  "copyFile";

[@bs.module "fs"] [@bs.scope "promises"]
external lchmod: (string, ~mode: int) => Js.Promise.t(unit) = "lchmod";

[@bs.module "fs"] [@bs.scope "promises"]
external link: (~existingPath: string, ~newPath: string) => Js.Promise.t(unit) =
  "link";

[@bs.module "fs"] [@bs.scope "promises"]
external lstat: string => Js.Promise.t(Stats.t) = "lstat";

[@bs.module "fs"] [@bs.scope "promises"]
external lstatBigInt: (string, bool) => Js.Promise.t(Stats.t) = "lstat";

type mkdirOptions;
[@bs.obj]
external mkdirOptions:
  (~recursive: bool=?, ~mode: int=?, unit) => mkdirOptions;

[@bs.module "fs"] [@bs.scope "promises"]
external mkdir: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdirWith: (string, mkdirOptions) => Js.Promise.t(unit) = "mkdir";

type mkdtempOptions;
[@bs.obj] external mdktempOptions: unit => mkdtempOptions;

[@bs.module "fs"] [@bs.scope "promises"]
external mkdtemp: (string, mkdtempOptions) => Js.Promise.t(string) =
  "mkddtemp";

[@bs.module "fs"] [@bs.scope "promises"]
external mkdtempWith: (string, mkdtempOptions) => Js.Promise.t(string) =
  "mkddtemp";

[@bs.module "fs"] [@bs.scope "promises"]
external open_: (string, Flag.t) => Js.Promise.t(FileHandle.t) = "open";

[@bs.module "fs"] [@bs.scope "promises"]
external openWithMode:
  (string, Flag.t, ~mode: int) => Js.Promise.t(FileHandle.t) =
  "open";

module WriteStream = {
  type kind('w) = [ Stream.writable('w) | `FileSystem];
  type subtype('w, 'ty) = Stream.subtype([> kind('w)] as 'ty);
  type supertype('w, 'ty) = Stream.subtype([< kind('w)] as 'ty);
  type t = subtype(Buffer.t, [ kind(Buffer.t)]);
  module Impl = {
    include Stream.Writable.Impl;
    [@bs.send]
    external bytesWritten: subtype('w, [> kind('w)]) => int = "bytesWritten";
    [@bs.send] external path: subtype('w, [> kind('w)]) => string = "path";
    [@bs.send]
    external pending: subtype('w, [> kind('w)]) => bool = "pending";
    [@bs.send]
    external onOpen:
      (
        subtype('w, [> kind('w)]) as 'stream',
        [@bs.as "open"] _,
        [@bs.uncurry] (fd => unit)
      ) =>
      'stream =
      "on";
    [@bs.send]
    external onReady:
      (
        subtype('w, [> kind('w)]) as 'stream,
        [@bs.as "ready"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'stream =
      "on";
  };
  include Impl;
};

module ReadStream = {
  type kind('r) = [ Stream.readable('r) | `FileSystem];
  type subtype('r, 'ty) = Stream.subtype([> kind('r)] as 'ty);
  type supertype('r, 'ty) = Stream.subtype([< kind('r)] as 'ty);
  type t = subtype(Buffer.t, [ kind(Buffer.t)]);
  module Impl = {
    include Stream.Readable.Impl;
    [@bs.send]
    external bytesRead: subtype('r, [> kind('r)]) => int = "bytesWritten";
    [@bs.send] external path: subtype('r, [> kind('r)]) => string = "path";
    [@bs.send]
    external pending: subtype('r, [> kind('r)]) => bool = "pending";
    [@bs.send]
    external onOpen:
      (
        subtype('r, [> kind('r)]) as 'stream,
        [@bs.as "open"] _,
        [@bs.uncurry] (fd => unit)
      ) =>
      'stream =
      "on";
    [@bs.send]
    external onReady:
      (
        subtype('r, [> kind('r)]) as 'stream,
        [@bs.as "ready"] _,
        [@bs.uncurry] (unit => unit)
      ) =>
      'stream =
      "on";
  };
  include Impl;
};

type createReadStreamOptions;
[@bs.obj]
external createReadStreamOptions:
  (
    ~flags: string=?,
    ~fd: fd=?,
    ~mode: int=?,
    ~autoClose: bool=?,
    ~emitClose: bool=?,
    ~start: int=?,
    ~_end: int=?,
    ~highWaterMark: int=?,
    unit
  ) =>
  createReadStreamOptions;

[@bs.module "fs"]
external createReadStream: string => ReadStream.t = "createReadStream";
[@bs.module "fs"]
external createReadStreamWith:
  (string, createReadStreamOptions) => ReadStream.t =
  "createReadStream";

type createWriteStreamOptions;
[@bs.obj]
external createWriteStreamOptions:
  (
    ~flags: string=?,
    ~fd: fd=?,
    ~mode: int=?,
    ~autoClose: bool=?,
    ~emitClose: bool=?,
    ~start: int=?,
    ~fs: Js.t({..})=?,
    unit
  ) =>
  createReadStreamOptions;
[@bs.module "fs"]
external createWriteStream: string => WriteStream.t = "createWriteStream";

[@bs.module "fs"]
external createWriteStreamWith:
  (string, createWriteStreamOptions) => WriteStream.t =
  "createWriteStream";
