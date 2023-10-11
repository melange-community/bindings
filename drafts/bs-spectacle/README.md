# bs-spectacle 

## [BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Spectacle](https://github.com/FormidableLabs/spectacle)

[![npm (scoped)](https://img.shields.io/npm/v/bs-spectacle.svg?style=flat-square)](https://www.npmjs.com/package/bs-spectacle)
![CircleCI](https://img.shields.io/circleci/project/github/piotrdubiel/bs-spectacle.svg)

---

## Example

See `examples/full-spectacle`. It uses _almost_ all features of **Spectacle**.

`examples/extras` aims to showcase features not included in original Spectacle example.

```reason
open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {primary: "#26A0D1", secondary: "white", tertiary: "#505050", quarternary: "white"},
      {
        primary: {name: "Merriweather", googleFont: true, styles: [|"300"|]},
        secondary: {name: "Roboto", googleFont: true, styles: [|"100"|]},
        tertiary: simpleFont("monospace")
      }
    )
  );

let s = ReasonReact.string;

let component = ReasonReact.statelessComponent("Simple");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <Deck transition=[|Zoom, Slide|] theme>
      <Slide>
        <Heading textColor="secondary" textFont="secondary"> (s("Hello, world")) </Heading>
      </Slide>
      <Slide transition=[|Slide|] bgColor="secondary">
        <BlockQuote>
          <Quote> (s({js|It’s easy, see...|js})) </Quote>
          <Cite> (s("Unknown")) </Cite>
        </BlockQuote>
      </Slide>
    </Deck>
};
```

## Installation

Easiest way is:

1. use `create-react-app`
1. install this bindings and spectacle

        $ npm install --save bs-spectacle spectacle-scripts reason-react
        # or
        $ yarn add bs-spectacle spectacle-scripts reason-react
1. add `bs-spectacle` to `bs-dependencies` in your `bsconfig.json`

        {
        ...
        "bs-dependencies": ["bs-spectacle"]
        }
1. modify `package.json` scripts

        "scripts": {
            "build": "bsb -make-world && react-scripts build",
            "start": "bsb -make-world -w",
            "clean": "bsb -clean-world",
            "test": "echo \"Error: no test specified\" && exit 1"
        }

To run it in dev mode, run `npm start` in one shell and `react-scripts start` in another shell.


## Status

Every `spectacle` feature is supported.

### Components
- [x] Deck
- [x] Slide (Base)
- [x] Notes
- [x] Layout
- [x] Fit
- [x] Fill
- [x] Markdown
- [x] Magic
- [x] Appear
- [x] BlockQuote, Quote and Cite (Base)
- [x] CodePane (Base)
- [x] Code (Base)
- [x] ComponentPlayground
- [x] GoToAction (Base)
- [x] Heading (Base)
- [x] Image (Base)
- [x] Link (Base)
- [x] List & ListItem (Base)
- [x] S (Base)
- [x] Table, TableRow, TableBody, TableHeader, TableHeaderItem and TableItem (Base)
- [x] Text (Base)
- [x] Typeface

### APIs
- [x] Theme
- [x] Transition Function
- [x] MarkdownSlides
- [x] Preloader
- [x] History
