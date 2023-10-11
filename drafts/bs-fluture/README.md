# bucklescript-fluture

  Bucklescript bindings to [fluture-js/Fluture](https://github.com/fluture-js/Fluture)

  Currently contains only a small part of fluture's API with the rest added as needed. 

## Install
      npm instal --save bucklescript-fluture

## Usage
  Examples: 

```OCaml
let () = 
  Future.(
    10 
    |> resolve 
    |> map (fun x -> x + 1)
    |> chain (fun x -> resolve (x + 1))
    |> fork Js.log Js.log
  )
```

Node style callback to Future

```OCaml
module F = Future

external readFile: string -> string -> F.nodeback -> unit = "readFile"[@@bs.module "fs"]
    
let readFileF: string -> string -> (_, string) F.future = F.encaseN2 readFile

let () = 
  readFileF "utf-8" "package.json"
  |> Future.fork Js.log Js.log
```