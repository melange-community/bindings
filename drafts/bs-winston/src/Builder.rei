type t;

type level =
  | Error
  | Warn
  | Info
  | Verbose
  | Debug
  | Silly;

let create: unit => t;
let setLevel: t => level => t;
let setSilent: t => bool => t;
let addFormat: t => Format.t => t;
let addTransport: t => Transport.t => t;
let setErrorKey: t => string => t;
let build: t => Logger.t;
