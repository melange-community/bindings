type configFile = {
  version: string,
  devToken: string,
  prodToken: string,
  owner: string,
  nameColor: string,
  nameColorPro: string,
  roleColor: string,
  embedColor: string,
  inviteMessage: string,
  oxfordId: string,
  oxfordKey: string,
  parseAppId: string,
  parseClientKey: string,
  parseJsKey: string,
  parseMasterKey: string,
  imgurKey: string,
  giphyKey: string,
  igdbKey: string,
  imgurClient: string,
  presenceMessages: array(string),
};

let parseInt = (defaultValue, str) => {
  let value = Js.Float.fromString(str);
  if (Js.Float.isNaN(value)) {
    defaultValue;
  } else {
    int_of_float(value);
  };
};

/* let truthy (value: 'a) : bool = Obj.magic(value) ? true : false; */
[@bs.val] external truthy: 'a => bool = "Boolean";

let promiseMap = f => Js.Promise.then_(x => Js.Promise.resolve(f(x)));

let promiseEnd = promise => {
  let _ =
    Js.Promise.catch(
      error => {
        Js.log(error);
        Js.Promise.resolve();
      },
      promise,
    );
  ();
};

[@bs.get] external exnCode: Js.Exn.t => Js.Undefined.t(string) = "code";

let exnCode = exn => Js.Undefined.toOption(exnCode(exn));

let parseJson = data =>
  try (Some(Js.Json.parseExn(data))) {
  | _ => None
  };

let memoize = fn => {
  let cache = ref(None);
  arg =>
    switch (cache.contents) {
    | None =>
      let result = fn(arg);
      cache := Some(result);
      result;
    | Some(x) => x
    };
};

let magicAsArray = (item: 'a): array('a) =>
  if (Js.Array.isArray(item)) {
    Obj.magic(item);
  } else {
    [|item|];
  };

let handleJson = (~response, ~failure, ~decoder, jsonString) => {
  switch (Json.parseOrRaise(jsonString)) {
  | json =>
    switch (json |> decoder) {
    | data => data |> response |> ignore
    | exception (Json.Decode.DecodeError(msg)) => failure(msg)
    }
  | exception (Json.ParseError(msg)) => failure(msg)
  };
};

let handleJsonWithErrorLog = handleJson(~failure=Js.log2("Error: ", _));

let nullableToString = string =>
  switch (string |> Js.Nullable.toOption) {
  | Some(string) => string
  | None => ""
  };

let arrMapReduce = (value, initial, f, f2) =>
  value |> Array.map(f, _) |> Array.fold_left(f2, initial, _);
let concat = (a, b) => a ++ b;

let markdownwrap = (string, markType) => {
  {j|
```$markType
$string
```
|j} |> Js.String.trim;
};
let wrapWithString = (wrapString, string) =>
  wrapString ++ string ++ wrapString;
let boldWrap = wrapWithString("**");
let italicizeWrap = wrapWithString("_");
let underlineWrap = wrapWithString("__");
let slashWrap = wrapWithString("~~");
let doubleQuoteWrap = wrapWithString("\"");
let singleQuoteWrap = wrapWithString("'");
let spoilerWrap = wrapWithString("||");

let spaceForWeb = str => {
  let re = Js.Re.fromStringWithFlags("\s", ~flags="ig");
  str |> Js.String.replaceByRe(re, "%20");
};

let shortenString = string =>
  string->Js.String.slice(~from=0, ~to_=350) |> Js.String.concat("...");
let nextElement = (~array, element) => {
  switch (Js.Array.indexOf(element, array)) {
  | (-1) => array[0]
  | value => Array.length(array) == value + 1 ? array[0] : array[value + 1]
  };
};

let reverse = string =>
  Js.String.split("", string)
  |> Js.Array.reverseInPlace
  |> Js.Array.joinWith("");

let readConfigFile = () => {
  let decoder = json =>
    Json.Decode.{
      version: json |> field("version", string),
      devToken: json |> field("devToken", string),
      prodToken: json |> field("prodToken", string),
      owner: json |> field("owner", string),
      nameColor: json |> field("nameColor", string),
      nameColorPro: json |> field("nameColorPro", string),
      roleColor: json |> field("roleColor", string),
      inviteMessage: json |> field("inviteMessage", string),
      embedColor: json |> field("embedColor", string),
      oxfordId: json |> field("oxfordId", string),
      oxfordKey: json |> field("oxfordKey", string),
      parseMasterKey: json |> field("parseMasterKey", string),
      imgurKey: json |> field("imgurKey", string),
      parseClientKey: json |> field("parseClientKey", string),
      parseAppId: json |> field("parseAppId", string),
      parseJsKey: json |> field("parseJsKey", string),
      igdbKey: json |> field("igdbKey", string),
      giphyKey: json |> field("giphyKey", string),
      imgurClient: json |> field("imgurClient", string),
      presenceMessages: json |> field("presenceMessages", array(string)),
    };
  let path = Node.Path.resolve(Path.dirname, "..");
  let filePath = Node.Path.join([|path, "config.json"|]);
  Node.Fs.readFileSync(filePath, `utf8) |> Json.parseOrRaise |> decoder;
};

let dictGetWithDefault = (~field, ~def, dict) => {
  Js.Dict.get(dict, field)->Belt.Option.getWithDefault(def);
};

let stringToTime = string =>
  switch (string) {
  | "days" => `days
  | "day" => `days
  | "d" => `days
  | "h" => `hours
  | "w" => `weeks
  | "weeks" => `weeks
  | "week" => `weeks
  | "hour" => `hours
  | "hours" => `hours
  | "minute" => `minutes
  | "minutes" => `minutes
  | "m" => `minutes
  | "ms" => `milliseconds
  | "millisecond" => `milliseconds
  | "milliseconds" => `milliseconds
  | "months" => `months
  | "month" => `months
  | "s" => `seconds
  | "seconds" => `seconds
  | "second" => `seconds
  | "y" => `years
  | "year" => `years
  | "years" => `years
  | "yrs" => `years
  | _ => `milliseconds
  };

let logErrorResolve = err => {
  Js.log2("Error: ", err) |> Js.Promise.resolve;
};

let isProd: bool = [%bs.raw "(process.env.NODE_ENV === 'production')"];