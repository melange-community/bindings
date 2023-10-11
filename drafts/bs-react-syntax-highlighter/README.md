# bs-react-syntax-highlighter

[![Build Status](https://travis-ci.com/erykpiast/bs-react-syntax-highlighter.svg?branch=master)](https://travis-ci.com/erykpiast/bs-react-syntax-highlighter)
[![dependencies Status](https://david-dm.org/erykpiast/bs-react-syntax-highlighter/status.svg)](https://david-dm.org/erykpiast/bs-react-syntax-highlighter)
[![devDependencies Status](https://david-dm.org/erykpiast/bs-react-syntax-highlighter/dev-status.svg)](https://david-dm.org/erykpiast/bs-react-syntax-highlighter?type=dev)
[![peerDependencies Status](https://david-dm.org/erykpiast/bs-react-syntax-highlighter/peer-status.svg)](https://david-dm.org/erykpiast/bs-react-syntax-highlighter?type=peer)
[![Greenkeeper badge](https://badges.greenkeeper.io/erykpiast/bs-react-syntax-highlighter.svg)](https://greenkeeper.io/)

ReasonML bindings for [react-syntax-highlighter](https://github.com/conorhastings/react-syntax-highlighter) library.

## Installation

```
npm i --save bs-react-syntax-highlighter react-syntax-highlighter
```

Then add `bs-react-syntax-highlighter` as a dependency to `bsconfig.json`.

## Usage

Unlike in the JavaScript counterpart, there is no default highlighter - you have to choose Hljs or Prism explicitly.

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Prism style={ReactSyntaxHighlighter.Prism.Style.darcula}>
    {"A code to highlight"}
  </ReactSyntaxHighlighter.Prism>;
};
```

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Hljs language={`JavaScript}>
    {"const foo = () => {};"}
  </ReactSyntaxHighlighter.Hljs>;
};
```

### Props spread

In JavaScript, there is a possibility to put any property you like on the root element rendered by the component,
by simply putting it on a component. It's called "props spread". `react-syntax-highlighter` supports that pattern as well.
ReasonML [simply can't do it](https://github.com/reasonml/reason-react/blob/master/docs/props-spread.md).

Quite nice escape hatch is wrapping the component you wish to spread props on in another
component (HOC or High-Order Component), which will inject all passed properties to its child in a not type-safe, but quite an efficient way. [source](https://twitter.com/yawaramin/status/1190120664830816256). There is a runtime cost for this operation, though, so I've decided to not include such code in this library. Pay the cost only when you need to.

```reasonml
module Spread = {
  [@react.component]
  let make = (~props, ~children) =>
    ReasonReact.cloneElement(children, ~props, [||]);
};

<Spread props={"id": "foobar"}>
  <ReactSyntaxHighlighter.Hljs language={`JavaScript}>
    {"const foo = () => {};"}
  </ReactSyntaxHighlighter.Hljs>;
</Spread>
```

For convenience I've included just one such a generic property in component bindings: `className`.

### JSX 2

The package provides fallback for projects using older version of JSX syntax.

```reasonml
[@react.component]
let make = () => {
  <ReactSyntaxHighlighter.Hljs.Jsx2 language={`JavaScript}>
    ...{"const foo = () => {};"}
  </ReactSyntaxHighlighter.Hljs.Jsx2>;
};
```

## Notes

An **async build** and a **light build** are not currently supported. PRs are welcome!
