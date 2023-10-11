exception UnexpectedAcyclicer(string);

type t =
  | Greedy
  | Lazy;

let toString = (acyclicer: t): option(string) =>
  switch (acyclicer) {
  | Greedy => Some("greedy")
  | Lazy => None
  };

let fromStringExn = (str: option(string)): t =>
  switch (str) {
  | Some("greedy") => Greedy
  | None => Lazy
  | Some(str) => raise(UnexpectedAcyclicer(str))
  };
