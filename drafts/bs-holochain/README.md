[Holochain API](https://developer.holochain.org/) bindings via
[Bucklescript](https://bucklescript.github.io). This library allows
you to write a [holochain](https://holochain.org) application in pure
Ocaml/Reason.


# Dependencies

This project requires npm and bucklescript 4.0.1. To produce a real holochain app
you also need to unify the json into one big zome file. Rollup and babel are typical
choices.

# Build
```
make
```

# Install as a library

In your dependent project run

`npm install <this-project-directory>`


# How to use


## Define your zomes as usual

Create a dna.json and schema files as you would for any standard holochain app.
See their [DNA](https://developer.holochain.org/DNA) reference documentation
for further details on this step.


## Implement your zomes

For each zome you define a module that instantiates a builder style functor to
accumulate all the entry definitions.

```OCaml
(** Zome example *)
open Hc

(* Instantiate a new zome builder with name equal to "myzome" *)
module Builder = Zome.Builder(struct let name = "myzome" end)

(* Define a named data type "mydata" as an abstract json record.
   Your dna.json would require a zome entry defined as well with the same name
   and shape.
*)
module MyData = struct
  let name = "mydata"
  type t = {data:string} [@@bs.deriving abstract]
end

(* Add the MyData entry type to the zome with validation functions
   that simply accepts any input (eg. returns true or Null,
   as the callback would require).

   The return moduled is an [Entry.S] signature, giving the developer
   specialized commit, update, and get functions over the MyData entry.
*)
module MyDataEntry = Builder.Entry0(MyData)(Validate.Accept_all(MyData))


(** Define input type to a zome function as a zome hash string of [MyData.t] *)
type args = MyData.t HashString.t

(* Define a public zome function (this was defined in dna.json as
   function named "dataExists")
*)
let dataExists args =
  match MyDataEntry.get args with None -> false | Some _ -> true


(* Define a public zome function to add data to the DHT
  (this was defined in dna.json as function named "addData")
*)
let addData data =
  MyDataEntry.commit (MyData.t ~data)

(* This finalizes the zome and includes the validation functions so they now serve
   as javascript call back functions.

   Since a zome requires a genesis function and possibly a receiver function, so 
   does the below functor. In this example builtin modules are used for both. The
   [Genesis.Success] module just returns true and does no initialization. Similarly,
   the send and receive functions operate on the unit value.
*)
include Builder.Build(Genesis.Success)(SendReceive.Unit)
```

# Examples

See [NewCraigsList, ported to OCaml](https://github.com/struktured/NewCraigsList) 
for a more complex implementation.

# Notes

This library binds to the javascript api running on a *Go* server via Go's
Otto javascript interpreter. The holochain team is porting their stack from
Go to Rust/Web Assembly.

Thus, this binding is subject to drastic change in the future. My hope is that
the OCaml/Reason abstraction boundary will ease migration to the new javascript api
(or web assembly directly).
