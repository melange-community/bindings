bs-react-fela
=============

Reason/BuckleScript bindings for
[react-fela](https://github.com/rofrischmann/fela/tree/master/packages/react-fela).
See also
[bs-react-fela-examples](https://github.com/astrada/bs-react-fela-examples).

From Fela [documentation](http://fela.js.org/):

Fela is a small, high-performant and framework-agnostic toolbelt to handle
state-driven styling in JavaScript. It is dynamic by design and renders your
styles depending on your application state.

It generates atomic CSS and supports all common CSS features such as media
queries, pseudo classes, keyframes and font-faces. Fela ships with a powerful
plugin API adding e.g. [vendor
prefixing](http://fela.js.org/packages/fela-plugin-prefixer) or [fallback
value](http://fela.js.org/packages/fela-plugin-fallback-value) support.

Fela can be used with
[React](https://github.com/rofrischmann/fela/tree/master/packages/react-fela)
or with any other view library. It even supports [React
Native](http://fela.js.org/docs/guides/UsageWithReactNative.html).

### Prerequisites

    yarn install

### How to compile

    yarn build

### How to use (in your projects)

Run:

    yarn add --dev @astrada/bs-react-fela

to add the library to your project dependencies. And add
`@astrada/bs-react-fela` to `dependencies` node of your `bsconfig.json`.
