let mapError: (result<'a, 'b>, 'b => 'c) => result<'a, 'c>
let fromTryCatch: (unit => 'a) => result<'a, exn>
let toOption: result<'a, 'b> => option<'a>
