open Rx

(* Samples for bindNodeCallback operator *)
external readFile : string -> string nodeCallback -> unit = "readFile" [@@bs.module "fs"]
external readFile2 : string -> string -> string nodeCallback -> unit = "readFile" [@@bs.module "fs"]

let bnc1 = bindNodeCallback1(readFile)
let bnc2 = bindNodeCallback2(readFile2)

let z1 = bnc1 "/home/harshal/ub/bs-rx/README.md" [@bs]
let z2 = bnc2 "/home/harshal/ub/bs-rx/README.md" "utf-8" [@bs]

let _ = subscribe z1 (fun y -> Js.log y)
let _ = subscribe z2 (fun y -> Js.log y)
