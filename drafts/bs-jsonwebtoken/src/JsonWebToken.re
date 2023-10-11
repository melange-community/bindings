open Json_encode;

type algorithm =
    HS256 | HS384 | HS512 | RS256 | RS384 | RS512 |
    ES256 | ES384 | ES512 | NoSignature;

let _algorithmToString = fun
    | HS256 => "HS256"
    | HS384 => "HS384"
    | HS512 => "HS512"
    | RS256 => "RS256"
    | RS384 => "RS384"
    | RS512 => "RS512"
    | ES256 => "ES256"
    | ES384 => "ES384"
    | ES512 => "ES512"
    | NoSignature => "none";

[@bs.deriving abstract]
type secretObject = {
  key: string,
  passphrase: string,
};

[@bs.module "jsonwebtoken"] external signWithOptions : (
  [@bs.unwrap][`json(Js.Json.t) | `buffer(Node_buffer.t)], 
  [@bs.unwrap][`string(string) | `buffer(Node_buffer.t) | `secret(secretObject)], 
  Js.Json.t
) => string = "sign"

[@bs.module "jsonwebtoken"] external signWithoutOptions : (
  [@bs.unwrap][`json(Js.Json.t) | `buffer(Node_buffer.t)], 
  [@bs.unwrap][`string(string) | `buffer(Node_buffer.t) | `secret(secretObject)]
) => string = "sign"

[@bs.module "jsonwebtoken"] external decode : (
  string
) => Js.Json.t = "decode"

[@bs.module "jsonwebtoken"] external _verify : (
  string, [@bs.unwrap][`string(string) | `buffer(Node_buffer.t) | `secret(secretObject)]
) => Js.Json.t = "verify"

type secret = [
  | `string(string) 
  | `buffer(Node_buffer.t) 
  | `secret(secretObject)
];

type signOptions = {
  algorithm: algorithm,
  keyid: string,
  /** expressed in seconds or a string describing a time span [zeit/ms](https://github.com/zeit/ms.js).  Eg: 60, "2 days", "10h", "7d" */
  expiresIn: string,
  /** expressed in seconds or a string describing a time span [zeit/ms](https://github.com/zeit/ms.js).  Eg: 60, "2 days", "10h", "7d" */
  notBefore: string,
  audience: list(string),
  subject: string,
  issuer: string,
  jwtid: string,
  noTimestamp: bool,
  header: Js_dict.t(string),
  encoding: string
};

let emptyOptions: signOptions = {
  algorithm: HS256,
  keyid: "",
  expiresIn: "",
  notBefore: "",
  audience: [],
  subject: "",
  issuer: "",
  jwtid: "",
  noTimestamp: false,
  header: Js_dict.empty(),
  encoding: ""
};

let encodeAlgorithm = (algo: algorithm) => {
    string(_algorithmToString(algo))
};

let encodeListToOptionalArray = (list: list(string)) => {
  let arr = Array.of_list(list);
  switch(Array.length(arr)){
  | 0 => None
  | _ => Some(arr)
  }
  |> nullable(array(string))
};

let encodeSignOptions = (signOptions: signOptions) => {
  [
    ("algorithm", encodeAlgorithm(signOptions.algorithm)),
    ("keyid", string(signOptions.keyid)),
    ("expiresIn", string(signOptions.expiresIn)),
    ("notBefore", string(signOptions.notBefore)),
    ("audience", encodeListToOptionalArray(signOptions.audience)),
    ("subject", string(signOptions.subject)),
    ("issuer", string(signOptions.issuer)),
    ("jwtid", string(signOptions.jwtid)),
    ("noTimestamp", bool(signOptions.noTimestamp)),
    ("header", signOptions.header |> dict(string)),
    ("encoding", string(signOptions.encoding)),
  ]
  |> List.filter(entry => snd(entry) != Js.Json.string("") && snd(entry) != Js.Json.null)
  |> object_
};

let sign = (~secret: secret, ~options: option(signOptions), payload: [`json(Js.Json.t) | `buffer(Node_buffer.t)]) => {
  switch(options) {
    | Some(option) => signWithOptions(payload, secret, encodeSignOptions(option))
    | None => signWithoutOptions(payload, secret);
  }
};

let verify = (token: string, secret: secret): Belt.Result.t(Js.Json.t, string) => {
  try(Belt.Result.Ok(_verify(token, secret))){
    | Js.Exn.Error(e) => 
      switch(Js.Exn.message(e)) {
        | Some(message) => Belt.Result.Error(message)
        | None          => Belt.Result.Error("An unknown error occured") 
      }
  }
};