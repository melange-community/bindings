(******************************************************************************)
(** {2 Native Functions} *)
(******************************************************************************)
external property : string -> Js.Json.t (*or_error *) = "property" [@@bs.val]

(** Returns an application property, which are defined by the app developer. It
 * returns values from the DNA file that you set as properties of your
 * application (e.g. Name, Language, Description, Author, etc.). *)
let property = property

external makeHash :
  entryType:string -> entry:'entry ->
  'entry HashString.t (*or_error *) = "makeHash" [@@bs.val]

(** Use this function to make a hash of the given entry data. This is the same
 * hash value that would be returned if entryData were passed to commit and by
 * which an entry of this type would be retrievable from the DHT using get. The
 * type of the entryData parameter depends on the entry format of entry. If
 * it's a string entry format then the type must be string. If it's a JSON
 * entry format, then it can be any type, and the value will get appropriately
 * converted to JSON. If it is a links format entry, then the type must by a
 * JSON object. *)
let make = makeHash

external debug : 'a -> unit = "debug" [@@bs.val]

(** Sends output to the debugging log. The type of value is arbitrary and will
 * get converted to a string according toteh language conversion limitations.
 * *)
let debug = debug

external sign : string -> string = "" (* or_error *) [@@bs.val]

(** Use the agent's private key to sign some contents *)
let sign = sign

external verifySignature :
  signature:string ->
  data:string ->
  pubKey:string ->
  bool (* or_error *) =
  "" [@@bs.val]

(** Uses the signature, data and signatory's public key to verify the sign in
* contents of data. Result represents whether its a match or not. pubKeyshould
* be a public key. *)
let verifySignature = verifySignature


external commit :
  entryType:string ->
  entry:'entry ->
  'entry HashString.t (*or_error*) =
  "" [@@bs.val]

(** Attempts to commit an entry to your local source chain. It will cause
 * callbac to your validaneCommitfunction. Returns either an error or the hash
 * of the committed entry upon success. The type of the entryData parameter
 * depends on the entry format of entry. If it's a string entry format then the
 * type must be string. If it's a JSON entry format, then it can by any type,
 * and the value will get appropriately converted to JSON. If it is a links
 * format entry, then the type must by a JSON object.

    A links entry object looks like this

    { Links: [ { Base: "2bDja...", Link: "Fb4aXa...", Tag: "links to" } ] }
    Base and Linkmust both be type hash. Tagcan be any string, describing the
    relationship between Base and Link. Tagwill later be used in getLinks. It
    may optionally contain a 4th property LinkAction which should be set to
    HC.LinkAction.Del in order to mark the link as deleted. See the examples
    below.
*)
let commit = commit

external call : zomeName:string -> functionName:string -> 'args ->
  Js.Json.t = "call" [@@bs.val]

(** Calls an exposed function from another zome. [arguments] is a string or an
 * object depending on the [CallingType] that was specified in the function's
 * definition in the DNA. Returns the extern value that's returned by the given
 * function *)
let call = call

external bridge :
  appDnaHash:'entry HashString.t ->
  zomeName:string ->
  functionName:string ->
  'arguments ->
  Js.Json.t = "" [@@bs.val]

(** Calls a bridged function from another app. [app_dna_hash] is the
 * application being called. Note that the application must have explicitly
 * been bridged. In development use hcdev's -bridgeSpecs and a
 * bridge_specs.json file to setup bridging. Just like in send, the arguments
 * parameter is a string or an object/hash depending on the CallingType that
 * was specified in the function's definition. Returns the external value
 * that's returned by the given function on the other side of the bridge.
*)
let bridge = bridge


external getBridges :
  unit -> 'entry Bridge.t array = "getBridges" [@@bs.val]

(** This function allows your app to examine which bridges have been put in
* place. *)
let getBridges = getBridges

external remove : entry:Js.Json.t -> message:string -> 'entry HashString.t =
  "" [@@bs.val]


(** Commits a DelEntry to the local chain with given delete message, and, if
  * the entry type of entry is not private, moves the entry to the Deleted
  * status on the DHT. *)
let remove = remove

external update : entryType:string -> entry:'a ->
  Js.Json.t = "" [@@bs.val]

(** Attempts to commit an entry to your local source chain that "replaces" a
 * previous entry. If entryType is not private, update will movereplaces to a
 * Modifiedstatus on the DHT. Additionally the modification action will be
 * recorded in the entries' header in the local chain, which will be used by
 * validation routes. **)
let update = update

external query :
  options:'a -> Js.Json.t (* or error *) array =
  "" [@@bs.val]

(**
 * Keep in mind that you will want to retrieve most data from the DHT (shared
 * data space), so that you are seeing what the rest of the nodes on your
 * Holochain are seeing. However, there are times you will want to query
 * private data fields, or package up data from your source chain for sending.
 * In those cases you can use this function. query returns a list whose
 * contents depend on what was chosen in the Returns option. If a single option
 * was chosen, then it will be a bare list consisting of that item type. If
 * more than than one return option was chosen, then it will be a list of items
 * whose key will be the singular name of that option, i.e. Hash, Entry, or
 * Header. See the examples below for reference.

   options: object
   options.Return: object
   options.Return.Hashes: boolean
   options.Return.Entries: boolean (default: true)
   options.Return.Hashes: boolean
   options.Constrain: object
   options.Constrain.EntryTypes: array-of-string
   options.Constrain.Contains: string
   options.Constrain.Equals: string
   options.Constrain.Matches: regex
   options.Constrain.Count: int
   options.Constrain.Page: int
   options.Order.Ascending: boolean (default: false)
   options.Bundle: boolean
   Returns: array-of-Query-object OR error
   settings
   expand_less JS examples
   // Here is an example of choosing a single Return option:
   var result = query({
   Return: {
    Hashes: true
   },
   Constrain: {
    EntryTypes: ["posts"]
   }
   })
   debug(result)
   /*
   [
   "QmSwMfay3iCynzBFeq9rPzTMTnnuQSMUSe84whjcC9JPAo",
   "QmfMPAEdN1BB9imcz97NsaYYaWEN3baC5aSDXqJSiWt4e6"
   ]
 */

   // Here is an example of choosing multiple Return options:
   var result = query({
   Return: {
    Hashes: true,
    Entries: true
   },
   Constrain: {
    EntryTypes: ["posts"],
    Count:1
   }
   })
   debug(result)
   /*
   [
   {
    "Entry": {"message":"this is my test post"},
    "Hash": "QmSwMfay3iCynzBFeq9rPzTMTnnuQSMUSe84whjcC9JPAo"
   }
   ]
 */
 **)
let query = query

external updateAgent :
  options: 'a -> 'entry HashString.t (* or-error *) = "" [@@bs.val]

(** Commits a new agent entry to the chain, with either or both new identity
 * information or a new public key, while revoking the old key. If revoking a
 * key, also adds that key to the node blockedlist (which is also gossiped), as
 * it's no longer a valid peer address.

    options: object
    options.Revocation: Revocation-Data-string
    options.Identity: Identity-Info-string
    Returns: hash-string OR error
    settings
    expand_less JS example
    updateAgent({Identity:"newemail@example.com",Revocation:"sample revocation reason"})
*)
let updateAgent = updateAgent

external send : 'entry HashString.t -> message:'a -> options:'a ->
  Js.Json.t = "" [@@bs.val]

(** Sends a message to a node, using the App.Key.Hash of that node, its
 * permanent address in the DHT. The return value of this function will be
 * whatever is returned by the receive function on the receiving node.
 * Alternatively, you can indicate that this call should be made
 * asynchronously, and specify the callback function using these properties:

    options.Callback.Function: the name of a function to call back when the
    call completes or times out.

    options.Callback.ID: an id that will be passed to your callback function to
    identify the particular call

    to: hash-string (see App.Key.Hash)
    message: object
    options: object
    options.Callback: object (optional)
    options.Callback.Function: string
    options.Callback.ID: string
    Returns: any-type
*)
let send = send
