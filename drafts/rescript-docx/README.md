<div align="center">
  <h3 align="center">
	<big><code>rescript-docx</code></big>
  </h3>
  <p align="center">
   <a href="https://github.com/CatalaLang/rescript-docx/issues">Report Bug</a>
   •
   <a href="https://incubateur-ademe.github.io/publicodes-tools/">API docs</a>
   •
   <a href="https://github.com/CatalaLang/rescript-docx/blob/master/CONTRIBUTING.md">Contribute</a>
   •
   <a href="https://docx.js.org">docx.js</a>
  </p>

<!-- ![CI][ci-link] ![NPM][npm-link] -->

  A ReScript wrapper for the [`docx`](https://docx.js.org/) JS/TS library.

</div>

## Table Of Contents

<!-- vim-markdown-toc Marked -->

* [Usage](#usage)
    * [Examples](#examples)
        * [Local](#local)
        * [Real world](#real-world)
* [API coverage](#api-coverage)
* [Binding conventions](#binding-conventions)
    * [Primitives](#primitives)
    * [Enums](#enums)
    * [Polymorphic constructors](#polymorphic-constructors)
    * [Inline variant types](#inline-variant-types)
    * [Reserved keywords](#reserved-keywords)
    * [Interface inheritance](#interface-inheritance)
* [Sponsors](#sponsors)

<!-- vim-markdown-toc -->

## Usage

```
yarn add -D rescript-docx
```

### Examples

#### Local

Some examples are available in
[`examples/`](https://github.com/CatalaLang/rescript-docx/blob/main/examples).
To run them simply:

```bash
# Compile the project with the dependencies
yarn && yarn build

# Run the compiled JS file with Node
npx node examples/<fileName>.bs.js

# The result is stored in the root with the corresponding name: <fileName>.docx
```

#### Real world

- [`catala-explain`](https://github.com/CatalaLang/catala-explain) - _A module
for explicability from the trace of a catala program_

## API coverage

List of supported features:

* ✅ Document
* 🚧 Sections
* ✅ Paragraph
* 🚧 Text
* 🚧 Images (_Missing correct modelization of the `ImageRun.options.data` type_)
* ✅ Headers & Footers
* ✅ Bullet Points
* ✅ Hyperlinks
* ✅ Numbering
* ✅ Tables
* ✅ Tabs
* ✅ Table Of Contents
* ✅ Page Numbers
* ❌ Change Tracking
* ❌ Math
* ❌ Comments
* ❌ Footnotes
* ❌ Fields
* ✅ Packers

## Binding conventions

For the binding, several conventions has been used:

### Primitives

By default JavaScript `number` are converted to `float`, but if it's expected
to be integers then to `int`.

### Enums

Enums are bound to a polymorphic variant:

```typescript
// In TypeScript
enum AlignmentType = {
    START = "start",
    CENTER = "center",
    NUM_TAB = "numTab",
    ...
}
```

```rescript
// Corresponding AlignmentType.res file
type t = [
    | #start,
    | #center,
    | #numTab,
    ...
]
```

> 🔜 In the incoming ReScript 11.0, this could be done cleaner by using the new
> [tagged
> variants](https://rescript-lang.org/blog/improving-interop#binding-to-typescript-enums).

### Polymorphic constructors 

Each `docx` classes has its corresponding ReScript module.
> For example the `Paragraph` classes has its corresponding `Parapraph` module in the
`Paragraph.res` file.

To emulate polymorphic constructors call, the following convention has been taken:

```typescript
// In TypeScript
const p = new Paragraph("Lorem ipsum")
const q = new Paragraph({
    text: "Lorem ipsum",
    heading: HeadingLevel.HEADING_1,
})
```

```rescript
// In ReScript
let p = Paragraph.make("Lorem Ipsum")
let q = Paragraph.make'({
    text: "Lorem ipsum",
    heading: #Heading1,
})
```

### Inline variant types

TypeScript inline variant types are encoded in a dedicated module in `Util.Types` as:

```typescript
// TypeScript variant
type t = {
    value: number | string
}
```

```rescript
// In ReScript
open Util

type t = { value: Types.NumberOrString.t }

let float: t = { value: Types.NumberOrString.fromFloat(10.0) }

let string: t = { value: Types.NumberOrString.fromString("Hello") }
```

> 🔜 In the incoming ReScript 11, this could be done more simply by using the new
> [untagged
> variants](https://rescript-lang.org/blog/improving-interop#untagged-variants).

### Reserved keywords

Some used JavaScript attributes are reserved keywords in ReScript, consequently, they are
postfixed by `_`.

For example, the attribute `type` is `type_`.

### Interface inheritance

> 🔜 In the incoming ReScript 11.0, using [record type
> spread](https://rescript-lang.org/blog/enhanced-ergonomics-for-record-types#record-type-spread)
> will allows to factorizes interface inheritance.

## Sponsors

This library has been developed during a research project funded by the
[_mission logiciels libres et communs numériques_](https://www.code.gouv.fr/)
of the [_direction interministérielle du
numérique_](https://www.numerique.gouv.fr/) in collaboration with the
[Catala](https://catala-lang.org/) project.
