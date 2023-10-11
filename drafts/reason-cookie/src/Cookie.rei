let setJson: (string, Js.Json.t) => unit;

type config;

let makeConfig: (~expires: int=?, ~path: string=?, unit) => config;

let remove: string => unit;

let setJsonConfig: (string, Js.Json.t, config) => unit;

let setString: (string, string) => unit;

let setStringConfig: (string, string, config) => unit;

let getAsString: string => option(string);

let getAsJson: string => option(Js.Json.t);