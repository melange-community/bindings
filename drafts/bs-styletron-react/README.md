bs-styletron-react
==================

Reason/BuckleScript bindings for
[styletron-react](https://github.com/rtsao/styletron/tree/master/packages/styletron-react).
See also
[bs-styletron-react-examples](https://github.com/astrada/bs-styletron-react-examples).

From Styletron [documentation](http://styletron.js.org/):

Styletron is a universal CSS-in-JS engine built from the ground up for
high-performance. Features include:

##### Advanced critical rendering path optimization of server-rendered pages

 * Dynamic generation of inlineable critical stylesheets with minimum possible
   size and parse times
    * Automatic generation of maximally compressed "atomic" critical CSS via
      declaration-level deduplication
    * Automatic declaration-level dead CSS elimination - only actually used
      declarations get included in output
 * Native media query and pseudo selector support for full critical CSS
   without JavaScript

##### Efficient dynamic client-side styles

 * Hyper-granular memoization to avoid making unnecessary modifications to
   stylesheet
 * Fast cache hydration of server-rendered styles to prevent re-rendering of
   server-rendered styles
 * Use of `CSSStyleSheet` rule injection ensuring only new styles get parsed

### Prerequisites

    yarn install

### How to compile

    yarn build

### How to use (in your projects)

Run:

    yarn add --dev @astrada/bs-styletron-react

to add the library to your project dependencies. And add
`@astrada/bs-styletron-react` to `dependencies` node of your `bsconfig.json`.

