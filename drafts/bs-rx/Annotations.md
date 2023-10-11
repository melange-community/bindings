
## Missing manual - Bucklescript language extensions

> Comprehensive documentation is currently missing for understanding bs/reason extensions. Thus, I have created this catalog of all the extensions I used for this library.

Extension points or annotations in OCaml/Reason tell the compiler to transform the parsed syntax tree in a particular way. - [@yawaramin](https://reasonml.chat/t/docs-about-annotations/666/4?u=mistyharsh)

They are used extensively when we are binding to external JavaScript libraries and data.

### `[@@bs.val]` - Bind to a global value
It binds existing JS value (function/primitive/object) to its counter-part.

```ocaml
external setTimeout: (unit -> unit) -> int -> float = "setTimeout" [[@@bs.val]
```

#### Shorthand
When the name you're using on the BS side matches the JS value you're modeling, you can use the empty string shorthand:

```ocaml
external setTimeout: (unit -> unit) -> int -> float = "" [[@@bs.val]
```

### `[@bs.module "ModuleName"]` - Bind to a ESM/Common.js module
It is used to bind to a value or a function supplied by the module. Depending upon `package-specs`, it is either ES module or Common.js module.

```ocaml
external dirname: string -> string = "dirname" [@@bs.module]

(* Shorthand *)
external dirname: string -> string = "" [@@bs.module]

(* Usage *)
let directory = dirname "/home/harshal/file.txt"

(* Output - package-specs: commonjs *)
var Path = require("path");
var root = Path.dirname("/home/harshal/file.txt");

(* Output - package-specs: es6 *)
import * as Path from 'path';

var root = Path.dirname("/home/harshal/file.txt");
```

#### Gotchas
While you can use relative paths with `@@bs.module` but be careful with it. It is not really recommended. The problem will happen when you create a binding with `external` and then use it in other module with `let`. [Read more here](https://github.com/BuckleScript/bucklescript/issues/3014).

### `[@@bs.scope]` - Bind to a value inside a global module/value
If you want to bind to a value inside a global module, you can use this extension.

```ocaml
external random: unit -> float = "random" [@@bs.val][@@bs.scope "Math"]
```

#### Trick 1: Arbitrarily deep object
If you wish to easily bind to `window.history.length`, you can do this.

```ocaml
external historyLen: int = "length" [@@bs.val][@@bs.scope "window", "history"]
```

#### Trick 2: Combine with `[@@bs.module]`
You can also bind to a value from an external module.

```ocaml
external create : ('a -> unit) -> 'b = ""
  [@@bs.val][@@bs.scope "Observable"] [@@bs.module "rxjs"]
```


### `[@@bs.variadic]` - Bind to a variadic function
Many JS libraries have functions that take multiple number of arguments. As long as they are homogeneous (same type), then this extension can be used:

```ocaml
external join: string array -> string = "" [@@bs.module "path"] [@@bs.variadic]
let v = join [| "a"; "b"|]
```

### `[@@bs.send]` - TODO

### `[@@bs.deriving abstract]`
Bucklescript compiles record types, variants to array as mentioned [here](https://bucklescript.github.io/docs/en/common-data-types.html#design-decisions). But it means record will be compiled as follows:

```ocaml
type person = {
  age: int;
  name: string;
}

let me = { age = 5; name = "Big Reason" }
```

The corresponding JS code is:

```javascript
var me = /* record */[
  /* age */5,
  /* name */"Big Reason"
];

exports.me = me;
```
The `bs.deriving abstract` annotation turns it into an "abstract type" (aka you don't know what the actual value's shape). This is when **Record Mode** feature of the Bucklescript can be used where it converts the record into plain JS object instead of array. Note that, since `bs.deriving` abstract hides the actual record shape, you can't access a field using e.g. `joe.age`. We remediate this by generating getter and setters.

Also note that, JS objects and OCaml records are diffferent - OCaml cares about the order while JS object does not. [Read here](https://github.com/BuckleScript/bucklescript/issues/1262).

```ocaml
type person = {
  age: int;
  name: string;
} [@@bs.deriving abstract]

let me = person ~name:"Joe" ~age:20
```

This will be compiled to plain JS object as:

```javascript
var me = {
  age: 20,
  name: "Joe"
};

exports.me = me;
```

Read more about this issue [issue here](https://github.com/BuckleScript/bucklescript/issues/2922).
