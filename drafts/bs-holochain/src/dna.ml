(** This module is currently not used but is meant to reflect the dna schema as
    usually defined in a dna.json (or yaml,toml) file.

    It could eventually be used to generate the json file with ocaml as a source
    definition, or to generate dna files at higher levels of abstraction and
    composition in OCaml.
*)

type properties =
  {
    description: string;
    language: string (* TODO make enum *)
  } [@@bs.deriving abstract]

type dht_config =
  {hashType:string (* TODO make enum *) } [@@bs.deriving abstract]

type zome_function =
  {name:string;callingTyping:string} (* TODO make enum *)
  [@@bs.deriving abstract]

type zome_entry =
  {
    name: string;
    dataFormat: string;
    sharing: string
  } [@@bs.deriving abstract]

type zome =
  {
    name: string;
    description: string;
    codeFile: string;
    ribosomeType: string (* TODO make enum *);
    entries: zome_entry list;
    functions : zome_function list
  } [@@bs.deriving abstract]

type t =
  {
    version: int;
    uuid: string;
    name: string;
    properties_schema_file: string [@bs.as "PropertiesSchemaFile"];
    requires_version: int [@bs.as "ReuiresVersion"];
    dht_config : dht_config [@bs.as "DHTConfig"];
    zomes: zome list [@bs.as "Zomes"];
  } [@@bs.deriving abstract]
