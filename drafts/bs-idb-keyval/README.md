# bs-idb-keyval

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [idb-keyval](https://github.com/jakearchibald/idb-keyval)

## Installation

```sh
npm install --save @tatchi/bs-idb-keyval
```

Then add `@tatchi/bs-idb-keyval` to `bs-dependencies` in your `bsconfig.json`:
```js
{
  ...
  "bs-dependencies": ["@tatchi/bs-idb-keyval"]
}
```

## Usage

### Create store:

```js
let store = IdbKeyVal.createStore("custom-db-name", "custom-store-name");
```

### set:

```js
IdbKeyVal.set("key", "value", store)
  |> Js.Promise.then_(() => {
       Js.log("It worked!");
       Js.Promise.resolve();
     })
  |> Js.Promise.catch(err => {
       Js.log2("It failed!!", err);
       Js.Promise.resolve();
     });
```

### get:

```js
IdbKeyVal.get("key", store)
|> Js.Promise.then_(value => {
     // logs: "value"
     Js.log(value);
     Js.Promise.resolve();
   });
```

### keys:

```js
IdbKeyVal.keys(store)
|> Js.Promise.then_(keys => {
     // logs: ["key"]
     Js.log(keys);
     Js.Promise.resolve();
   });
```

### delete:

```js
IdbKeyVal.delete("key", store)
|> Js.Promise.then_(keys => {
     Js.log("deleted");
     Js.Promise.resolve();
   });
```

### clear:

```js
IdbKeyVal.clear(store)
|> Js.Promise.then_(keys => {
     Js.log("cleared");
     Js.Promise.resolve();
   });
```

