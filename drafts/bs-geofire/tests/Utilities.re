module Jest = {
  [@bs.val] external afterEachPromise : (unit => Js.Promise.t(unit)) => unit = "afterEach";
  [@bs.val] external beforeEachPromise : (unit => Js.Promise.t(unit)) => unit = "beforeEach";
};

module Node = {
  include (Node: (module type of Node) with module Process := Node.Process);
  module Process = {
    include Node.Process;
    let getEnvVar = (key: string) : option(string) => Js.Dict.get(process##env, key);
  };
};

module Option = {
  let map = (f: 'a => 'b, option: option('a)) : option('b) =>
    switch option {
    | None => None
    | Some(value) => Some(f(value))
    };
};

module Promise = {
  include Js.Promise;
  let map = (f, promise) => promise |> then_((value) => f(value) |> resolve);
  let wait = (duration) =>
    Js.Promise.make(
      (~resolve as resolve_, ~reject as _) => {
        let unit = ();
        let resolve = () => [@bs] resolve_(unit);
        Js.Global.setTimeout(resolve, duration) |> ignore
      }
    );
};

let requiredEnvVar = (key: string) : string =>
  switch (Node.Process.getEnvVar(key)) {
  | None =>
    Js.log({j|"The environment variable $key is required."|j});
    raise(Not_found)
  | Some(value) => value
  };
