let unary (fn: 'a) : 'a = [%raw "(a) => fn(a)" ];;
let (||>) f g x = g(f(x));;
let (<$>) option mapper = (
  match option with
  | None -> None
  | Some value -> Some (mapper value)
);;