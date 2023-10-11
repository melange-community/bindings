# bs-typing

BuckleScript bindings for the [Typed.js](https://github.com/mattboldt/typed.js/) library.

## Install

First, install dependencies.

```shell
yarn add bs-typing typed.js
```

Lastly, add `bs-typing` to `bsconfig.json`.

```json
"bs-dependencies": [ "bs-typing" ]
```

## Usage

### `index.html`

```html
<html>
  <body>
    <span id="typing-example"></span>
    <script src="bundle.js" type="module"></script>
  </body>
</html>
```

### `Example.re`

```reasonml
let example =
  Typing.make(
    "#typing-example",
    Typing.options(
      ~strings=[|
        {j|Typing animation in ReasonML with the help of Typed.js|j},
      |],
      ~typeSpeed=50,
      ~typeDelay=30,
      ~loop=true,
      ~loopCount=5.0,
      (),
    ),
  );
```

Take a look at the [Example.re file](./example/Example.re) for more examples.

## Contribute

Please open an issue or submit a PR if you find something you would like to improve!
