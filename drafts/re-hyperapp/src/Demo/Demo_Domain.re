module Status = {
  type t = [`ToRead | `Reading | `Read];

  let fromString = fun
    | "to read" => Some(`ToRead)
    | "reading" => Some(`Reading)
    | "read" => Some(`Read)
    | _ => None;

  let toEmoji = fun
    | `ToRead => {j|📘|j}
    | `Reading => {j|📖|j}
    | `Read => {j|📗|j}
    | `All => {j|📚|j};

  let toString = fun
    | `ToRead => "to read"
    | `Reading => "reading"
    | `Read => "read"
    | `All => "all";
};

module Book = {
  type id = string;
  type t = {.
    "author": string,
    "description": string,
    "id": id,
    "title": string,
    "status": Status.t,
  };
};
