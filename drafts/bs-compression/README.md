# bs-compression
Bucklescript Bindings for [compression](https://github.com/expressjs/compression) express middleware.
`compression` is a Node.js compression middleware.

# Prerequisites

```
npm install --global bs-platform
yarn install
```

# How to compile

```
yarn build
```

# Usage 

This package can be used only with `bs-express`. Make sure you already have `bs-express` as a dependency in your project.

```
yarn add bs-compression
```
And add `bs-compression` to `dependencies` node of your `bsconfig.json`.

# Code snippets

For instance, here is the code to serve static files from `public` folder and compress them.
Remark: The compression middleware must be passed first in the array of middlewares.

```reason
let app = express();
App.useOnPathWithMany(
  app,
  ~path="/public",
  [|
  Compression.compression(),
  {
    let options = Static.defaultOptions();
    Static.make("public", options) |> Static.asMiddleware
  }
  |]
);
```
