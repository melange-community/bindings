# From https://github.com/DCKT/bs-fastify

🚧

Bucklescript bindings for [fastify](https://www.fastify.io/) (v`2.11.0`)

## Install

```
yarn add @dck/bs-node @dck/bs-fastify
```

Add it to `bs-dependencies` in your `bsconfig.json` :

```json
{
  "bs-dependencies": ["@dck/bs-node", "@dck/bs-fastify"]
}
```

## Usage

### Basic

```reason
open BsFastify;
open BsNode;

let app = createApp(AppOptions.make(~logger=true, ()));

app->get(baseEndpoint, (_req, res) =>
  res->Response.sendObject({"test": "test"})
);


let schemaProperties = Js.Dict.empty();
schemaProperties->Js.Dict.set("name", Schema.property(~type_="string"));

app->postWithSchema(
       baseEndpoint,
       Schema.createBodySchema(
         ~required=[|"name"|],
         ~properties=schemaProperties,
       ),
       (req, res) => {
         let name = req->Request.body##name;
         res->Response.sendString("Hello "++ name ++ " !");
       }
  );

app->listen(3333, (err, address) =>
  switch (Js.Nullable.toOption(err)) {
    | None => Js.log("Server listening on " ++ address)
    | Some(error) => Js.log(error)
  }
);
```

### Middleware

```reason
open BsFastify;
open BsNode;

let app = createApp(AppOptions.make(~logger=true, ()));

app->register([%raw "require('fastify-multipart')"]);
```

### Usage

```reason
open BsFastify;
open BsNode;

let app = createApp(AppOptions.make(~logger=false, ()));

app->use2("/medias", serveStatic("/assets));
```
