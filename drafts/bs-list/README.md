# bs-list

  Bucklescript bindings to [funkia/list](https://github.com/funkia/list)

  Currently compiles to function-application-style in javascript. 

## Install 
```
npm i -s bs-list
```
add `bs-list` to `bs-dependencies` in `bsconfig.json`

## Sample Usage 

``` OCaml
let () = 
  let open Flist in 
  lst [|1;2;3|]
  |> map ~f:(fun x -> x + 1)
  |> adjust 2 ~f:(fun x -> x * 2)
  |> foldl ~f:(fun x acc -> x * acc) 0
  |> Js.log
```

Please look at `list`'s [docs](https://github.com/funkia/list/README.md) for all the available functions.

## Why

In an ideal scenario, we should be able to write code using OCaml's `'a list` type in the usual way,using recursion and pattern matching, and then make `bsc` compile it down to whatever representation 
we want `'a list` to have in Javascript. In a way we are mapping idiomatic OCaml's `'a list` api to whatever is our preffered/efficient js representation. 

Unfortunately, `bsc` doesn't let us do that at the moment, it has it's own representation of `'a list` which is a two element array of `[head, tail]` where `tail` is another array, with empty list being `0`. It's not efficient, but you get to use pattern matching. The other option is to use Js.Array, but the api is lacking, doesn't have any of the nice things `'a list` has. 

Using `funkia/list` is a compromise, it has a pretty comprehensive api like `'a list` but can't use pattern matching, is very efficient like `Js.Array` but has a nicer api.