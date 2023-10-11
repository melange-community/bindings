type t =
  | AccessDeniedError
  | ValidationError;

let fromExn = (err: Js.Exn.t) => {
  let ty = Js.typeof(err);
  switch ty {
  | "AccessDeniedError" => AccessDeniedError
  | "ValidationError" => ValidationError
  | _ => failwith("unknown error")
  };
};