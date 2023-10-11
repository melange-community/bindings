module Value: {
  type t;
  type case = [
    | `str(string)
    | `strs(array(string))
    | `date(Js.Date.t)
    | `dates(array(Js.Date.t))
  ];

  let classify: t => case;
  let unpack: t => array(Js.Date.t);
  let reduce: case => t;
  let first: case => Js.Date.t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  type case = [
    | `str(string)
    | `strs(array(string))
    | `date(Js.Date.t)
    | `dates(array(Js.Date.t))
  ];

  let str = (v: string) => Any(v);
  let strs = (v: array(string)) => Any(v);
  let date = (v: Js.Date.t) => Any(v);
  let dates = (v: array(Js.Date.t)) => Any(v);

  let reduce = case =>
    switch (case) {
    | `str(v) => str(v)
    | `strs(v) => strs(v)
    | `date(v) => date(v)
    | `dates(v) => dates(v)
    };

  let classify = (Any(v): t): case =>
    if (Js.Array.isArray(v)) {
      let head = Obj.magic(v)[0];

      if (Js.typeof(head) == "string") {
        `strs(Obj.magic(v): array(string));
      } else {
        `dates(Obj.magic(v): array(Js.Date.t));
      };
    } else if (Js.typeof(v) == "string") {
      `str(Obj.magic(v): string);
    } else {
      `date(Obj.magic(v): Js.Date.t);
    };

  let unpack = t =>
    switch (t |> classify) {
    | `str(v) => [|Js.Date.fromString(v)|]
    | `date(v) => [|v|]
    | `strs(v) => Belt.Array.map(v, Js.Date.fromString)
    | `dates(v) => v
    };

  let first = c => reduce(c)->unpack[0];
};

module Hook: {
  type t;
  type handler = (Value.t, string) => unit;
  type case = [ | `hook(handler) | `hooks(array(handler))];

  let classify: t => case;
  let reduce: case => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  type handler = (Value.t, string) => unit;
  type case = [ | `hook(handler) | `hooks(array(handler))];

  let single = (v: handler): t => Any(v);
  let multi = (v: array(handler)): t => Any(v);

  let reduce = case =>
    switch (case) {
    | `hook(v) => single(v)
    | `hooks(v) => multi(v)
    };

  let classify = (Any(v): t): case =>
    if (Js.typeof(v) == "function") {
      `hook(Obj.magic(v): handler);
    } else {
      `hooks(Obj.magic(v): array(handler));
    };
};

type renderProps = {
  defaultValue: Value.t,
  value: Value.t,
};
