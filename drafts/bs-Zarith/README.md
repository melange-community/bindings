# bs-zarith

The API is stable, but there is not a lot of testing. Use with caution.

## Bigint

```OCaml
let x = Bigint.of_string "1000000000000000000000000000000000000000" in
let y = Bigint.of_int 1 in
let z = Bigint.(y + x) in
Js.log(Bigint.to_string(z));
```

## Z

```
let x = Z.Int64.of_string "230000232323322323" in
let y = Z.Int64.of_int 3 in
let z = Z.Int64.(x - y) in
Js.log(Z.Int64.to_string(z));
```

## Q

```
let x = Q.Int.of_string "1/2" in
let y = Q.Int.make (Z.Int.one) (Z.Int.of_int 2)
let z = Q.Int.sub x y
Js.log(Q.Int.to_string(z));
```
