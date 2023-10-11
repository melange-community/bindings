# bs-axios [![npm version](https://img.shields.io/npm/v/bs-axios.svg?style=flat-square)](https://www.npmjs.com/package/bs-axios)

[Axios](https://github.com/axios/axios) bindings for Bucklescript.

## Installation

1. Install bs-axios

```bash
$ yarn add bs-axios
```

or

```bash
$ npm install --save bs-axios
```

2. Add "bs-axios" to "bs-dependencies" section of `bsconfig.json`

## Examples

See usage examples in examples folder:

- [Request examples](./examples/request_examples.re) (GET, POST)
- [Instance example](./examples/instance_example.re)

### Simple request

```reason
Js.Promise.(
  Axios.get("/user?ID=12345")
  |> then_((response) => resolve(Js.log(response##data)))
  |> catch((error) => resolve(Js.log(error)))
);
```

### Post requests

```reason
Js.Promise.(
  Axios.post("/user")
  |> then_((response) => resolve(Js.log(response##data)))
  |> catch((error) => resolve(Js.log(error)))
);
```

```reason
let user = {
  "username": "michel",
  "password": "12345678"
};

Js.Promise.(
  Axios.postData("/auth", {user})
  |> then_((response) => resolve(Js.log(response##data)))
  |> catch((error) => resolve(Js.log(error)))
);
```

### Concurrency

```reason
Js.Promise.(
  Axios.all2((Axios.get("/users/1"), Axios.get("/users/1/friends")))
  |> then_(((user, friends)) => resolve(Js.log2(user##data, friends##data)))
  |> catch((error) => resolve(Js.log(error)))
);
```

### Creating an instance

You can create a new instance of axios with a custom config.

```reason
open Axios;

let inst = Instance.create(makeConfig(~baseURL="https://example.com", ()));
Js.Promise.(Instance.get(inst, "/") |> then_((resp) => resolve(Js.log(resp##data))));
```

### Error handling

```reason
external promiseErrorToJsObj : Js.Promise.error => Js.t('a) = "%identity";

Js.Promise.(
  Instance.get(inst, "/")
  |> then_(resp => resolve(Belt.Result.Ok(resp)))
  |> catch(error => {
       let error = error |> promiseErrorToJsObj;
       Js.log(error##response##status);
       resolve(Belt.Result.Error(error));
     })
);
```

### Headers

```reason
let headers = Axios.Headers.fromObj({"Content-type": "application/json"});
Axios.getc("https://example.com", Axios.makeConfig(~headers, ()));

let headersDict =
  Js.Dict.(
    {
      let dict = empty();
      dict->set("Content-type", "application/json");
      dict;
    }
  );
let headers = Axios.Headers.fromDict(headersDict);
Axios.getc("https://example.com", Axios.makeConfig(~headers, ()));
```

### Node.js HTTP/HTTPS Agent

Providing custom Node.js [`HTTP Agent`](https://nodejs.org/api/http.html#http_class_http_agent)
allows for configuring connection persistence and reuse. For secure connections,
[`HTTPS Agent`](https://nodejs.org/api/https.html#https_class_https_agent) allows security related
configuration to be provided.

```reason
let httpsAgent =
  Axios.Agent.Https.(config(~rejectUnauthorized=false, ()) |> create);

Axios.getc(
  "https://insecure-example.com",
  Axios.makeConfig(~httpsAgent, ()),
);
```
