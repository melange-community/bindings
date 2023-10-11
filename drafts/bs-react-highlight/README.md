# bs-react-highlight

## Introduction

ReasonReact bindings for [react-highlight](https://github.com/akiran/react-highlight).

**State**: Published

```reason
let component = ReasonReact.statelessComponent("App");

let code = "
  function helloWorld() {
    console.log('Hello, world!')
  }
";

let make = _children => {
  ...component,
  render: _self => <Highlight> ...code </Highlight>
};
```

![Example](/pictures/helloWorldJs.png?raw=true "Hello World JS")

## Installation

### 1

* With `yarn`

```yarn add @cnguy/bs-react-highlight```

* With `npm`

```npm install --save @cnguy/bs-react-highlight```

### 2

Add `@cnguy/bs-react-highlight` to `bsconfig.json` `bs-dependencies`.

### 3

Add a `highlight.js` theme.

For example:
```html
<html>
<head>
  <link
    rel="stylesheet"
    type="text/css"
    href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/atom-one-dark.min.css"
  />
</head>
<body>
  <div id="root" />
  <script src="bundle.js"></script>
</body>
</html>
```

## Usage

Implicit:

```reason
let component = ReasonReact.statelessComponent("App");

let code = "
  function helloWorld() {
    console.log('Hello, world!')
  }
";

let make = _children => {
  ...component,
  render: _self => <Highlight> ...code </Highlight>
};
```

Explicit:

```reason
let component = ReasonReact.statelessComponent("App");

let code = "
    print(\"Hello, world!\")
  ";

let make = _children => {
  ...component,
  render: _self => <Highlight className="python"> ...code </Highlight>,
};
```

innerHTML:

```reason
let component = ReasonReact.statelessComponent("App");

let code = "
    <h1>Hello, world!</h1>
  ";

let make = _children => {
  ...component,
  render: _self => <Highlight innerHTML=true> ...code </Highlight>,
};
```

## Changes

### 0.1.0

Release

## Contributing

All contributions are welcome!

### Development

```sh
yarn start # npm run start
```