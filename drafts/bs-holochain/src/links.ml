open Constants

(** Represents a link from an entry at [base] to hash [link]. [tag] is optional
    metadata for filtering and finding links.
*)
module Link = struct
  type ('base, 'link) t = {
    base : 'base HashString.t [@bs.as "Base"];
    link : 'link HashString.t [@bs.as "Link"];
    tag : string [@bs.as "Tag"] [@bs.optional];
    linkAction : System.LinkAction.t
        [@bs.as "LinkAction"] [@bs.optional]
  } [@@bs.deriving abstract]

  let tag t = tagGet t

  let linkAction t = linkActionGet t

end


(** Special entry type for links *)
type t =
  {links:([`Any], [`Any]) Link.t array [@bs.as "Links"]}
[@@bs.deriving abstract]

let t links : t =
  t ~links:
  (Belt_Array.map links
    (fun (l:('a, 'b) Link.t) ->
      Link.t
        (* TODO figure out better way to do this *)
       ~base:(Link.baseGet l :> [`Any] HashString.t)
       ~link:(Link.linkGet l :> [`Any] HashString.t)
       ?tag:(Link.tag l)
       ?linkAction:(Link.linkAction l)
       ()
    )
  )


(** Options for the getLinks function. If [load] is true
    a list of entrys is returned.

    If [load] is false (the default value),
    only the hash of the entries are provided in the list.

    [statusMask] allows filtering of entries according to their
    status. One of [`Live | `Deleted | `Rejected].
*)
module Options =
struct
  type t = {
    load : bool [@bs.as "Load"] [@bs.optional];
    statusMask : System.Status.t [@bs.as "StatusMask"] [@bs.optional]
  } [@@bs.deriving abstract]

  let default =
    t ~load:false ~statusMask:System.Status.live
end

external links :
  base:'entry HashString.t ->
  Js.Json.t array =
  "getLinks" [@@bs.val]

external getTag :
  base:'entry HashString.t ->
  tag:string ->
  Js.Json.t array =
  "getLinks" [@@bs.val]


external getTagOpt :
  base:'entry HashString.t ->
  tag:string Js.Null.t ->
  options:Options.t ->
  Js.Json.t array =
  "getLinks" [@@bs.val]

(** Retrieves a list of links tagged as tag on base from the DHT. If tag is an
 empty string it will return all the links on the baseand the list will also
 include the Tag property on entries. With options as {Load: false} (which is
 the default) returns a list of the form [{Hash:"QmY..."},..] With options as
 {Load: true} it will get the entry values of the links and return a list of
 the form [{Hash:"QmY...",EntryType:"<entry-type>",Entry:"<entry value
 here>",Source:"<source-hash>"},..]}. Use options.StatusMask to return only
 links with a certain status. Default is to return only Live links. You can
 use defined constants HC.Status.Live/Deleted/Rejected as the int value. *)
let links ?tag ?options ~base =
  match options,tag with
  | Some options, tag ->
    getTagOpt ~tag:(Js.Null.fromOption tag)
        ~options ~base
  | None, Some tag ->
    getTag ~tag ~base
  | None, None ->
    links ~base

type packed =
  {hash:string;
   entryType:string;
   entry:Js.Json.t;
   source:App0.Agent.hash
  }

let links
    ?(tag:string option)
    ?(options:Options.t option) base =
  let entries = links ?tag ?options ~base in
  Array.map
    (fun entryInfo ->
       match Js.Json.decodeObject entryInfo with
       | None ->
         Js.log2 "unexpected link info shape:" entryInfo;
         failwith "unexpected link info shape"
       | Some dict ->
         let hash =
           Belt_Option.getExn (Js.Dict.get dict "Hash") |>
           Js.Json.decodeString |> Belt_Option.getExn in
         (match Belt_Option.flatMap
                  (Js.Dict.get dict "EntryType") Js.Json.decodeString with
         | None -> `Hash hash
         | Some entryType ->
           let entry = Belt_Option.getExn
               (Js.Dict.get dict "Entry") in
           let source =
             Belt_Option.getExn (Js.Dict.get dict "Source") |>
             Js.Json.decodeString |> Belt_Option.getExn |>
             HashString.create in
           `Packed {hash; entryType; entry; source}
         )
    )
    entries

type 'entry unpacked =
  {entry:'entry;source:App0.Agent.hash;hash:'entry HashString.t}

let unpack
    (type entry)
    (module E : Entry.S with type t = entry)
    links : entry unpacked array =
  Belt_Array.keepMap links
    (function
      | `Hash (_hash:string) ->
        Js.log "unpack: just hash"; None
      | `Packed {hash;entryType;entry;source} ->
        match entryType = E.name with
        | true ->
          Js.log2 "unpack match:" entryType;
          Some {source;entry=E.ofJson entry;
                        hash=E.hashOfString hash}
        | false -> Js.log3 "unpack not match: " entryType E.name; None
    )


