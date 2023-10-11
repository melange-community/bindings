(** Validation callback api, but only for a specific entry type *)

module type S =
  sig
  (** The entry type being validated *)
  type t
  val validateCommit :
    header:Js.Json.t ->
    package:Js.Json.t ->
    sources: string array ->
    t ->
    bool
  val validatePut :
    header:Js.Json.t ->
    package:Js.Json.t ->
    sources:string array ->
    t ->
    bool
  val validateMod :
    header:Js.Json.t ->
    replaces:t HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    t ->
    bool
  val validateDel :
    hash:t HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    bool
  val validateLink :
    hash:t HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    links:Js.Json.t array ->
    bool

  val validatePutPkg :
    unit -> Js.Json.t
  val validateModPkg :
    unit -> Js.Json.t
  val validateDelPkg :
    unit -> Js.Json.t
  val validateLinkPkg :
    unit -> Js.Json.t
end

class type ['entry] validate =
  object
  method validateCommit :
    header:Js.Json.t ->
    package:Js.Json.t ->
    sources: string array ->
    'entry ->
    bool
  method validatePut :
    header:Js.Json.t ->
    package:Js.Json.t ->
    sources:string array ->
    'entry ->
    bool
  method validateMod :
    header:Js.Json.t ->
    replaces:'entry HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    'entry ->
    bool
  method validateDel :
    hash:'entry HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    bool
  method validateLink :
    hash:'entry HashString.t ->
    package:Js.Json.t ->
    sources:string array ->
    links:Js.Json.t array ->
    bool
  method validatePutPkg :
    unit -> Js.Json.t
  method validateModPkg :
    unit -> Js.Json.t
  method validateDelPkg :
    unit -> Js.Json.t
  method validateLinkPkg :
    unit -> Js.Json.t
end

class ['entry] acceptAll : ['entry] validate =
  object
  method validateCommit
    ~header:_
    ~package:_
    ~sources:_
    _entry = true

  method validatePut
    ~header:_
    ~package:_
    ~sources:_
    _entry =
    true

  method validateMod
    ~header:_
    ~replaces:_
    ~package:_
    ~sources:_
    _entry =
    true

  method validateDel
    ~hash:_
    ~package:_
    ~sources:_ =
    true

  method validateLink
    ~hash:_
    ~package:_
    ~sources:_
    ~links:_ =
    true
  method validatePutPkg () = Js.Json.null
  method validateModPkg () = Js.Json.null
  method validateDelPkg () = Js.Json.null
  method validateLinkPkg () = Js.Json.null
end

class ['entry] trace : ['entry] validate =
  object
  method validateCommit
    ~header
    ~package
    ~sources
    entry =
    Native.debug
      ("bs-holochain: validateCommit",
       header,
       entry,
       package,
       sources
      );
    true

  method validatePut
    ~header
    ~package
    ~sources
    entry =
    Native.debug
      ("bs-holochain: validatePut",
       entry,
       header,
       package,
       sources
      );
    true

  method validateMod
    ~header
    ~replaces
    ~package
    ~sources
    entry =
  Native.debug
      ("bs-holochain: validateMod",
       entry,
       header,
       replaces,
       package,
       sources
      );
  true

  method validateDel
    ~hash
    ~package
    ~sources =
    Native.debug
      ("bs-holochain: validateDel",
       hash,
       package,
       sources
      );
     true

  method validateLink
    ~hash
    ~package
    ~sources
    ~links =
    Native.debug
      ("bs-holochain: validateLink",
       hash,
       package,
       sources,
       links
      );
     true
  method validatePutPkg () =
    Native.debug
      ("bs-holochain: validatePutPkg");
    Js.Json.null
  method validateModPkg () =
    Native.debug
      ("bs-holochain: validateModPkg");
    Js.Json.null
  method validateDelPkg () =
    Native.debug
      ("bs-holochain: validateDelPkg");
    Js.Json.null
  method validateLinkPkg () =
    Native.debug
      ("bs-holochain: validateLinkPkg");
    Js.Json.null
end


let of_object (type entry) (obj:entry validate) =
let module V : S with type t = entry =
struct
  type t = entry

  let validateCommit
    ~header
    ~package
    ~sources
    entry =
    obj#validateCommit ~header ~package ~sources entry

  let validatePut
    ~header
    ~package
    ~sources
    entry =
    obj#validatePut ~header ~package ~sources entry

  let validateMod
    ~header
    ~replaces
    ~package
    ~sources
    entry =
    obj#validateMod ~header ~replaces ~package ~sources entry

  let validateDel
    ~hash
    ~package
    ~sources =
    obj#validateDel ~hash ~package ~sources

  let validateLink
    ~hash
    ~package
    ~sources
    ~links =
    obj#validateLink ~hash ~package ~sources ~links

  let validatePutPkg () = obj#validatePutPkg ()
  let validateModPkg () = obj#validateModPkg ()
  let validateDelPkg () = obj#validateDelPkg ()
  let validateLinkPkg () = obj#validateLinkPkg ()
end in
(module V : S with type t = entry)


module Trace(E:Entry.S0) : S with type t = E.t =
  struct
    let m = of_object (new trace)
    include (val m : S with type t = E.t)
  end

module Accept_all(E:Entry.S0) : S with type t = E.t =
struct
  let m = of_object (new acceptAll)
  include (val m : S with type t = E.t)
end
