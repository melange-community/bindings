# bs-react-pdf [![npm version](https://img.shields.io/npm/v/bs-react-pdf.svg?style=flat-square)](https://www.npmjs.com/package/bs-react-pdf)

[react-pdf](https://github.com/diegomura/react-pdf) bindings for [bucklescript](https://bucklescript.github.io/bucklescript/)

## Installation

1. `$ npm i bs-react-pdf`
2. Add `bs-react-pdf` to `bs-dependencies` section of your `bsconfig.json`

## [Examples](https://github.com/meafmira/bs-react-pdf/tree/master/examples)
### Document

```reason
open ReactPdf.Core;

let styles =
  StyleSheet.create({
    "page": {"flexDirection": "row", "backgroundColor": "#fff"},
    "section": {"margin": 10, "padding": 10, "flexGrow": 1}
  });

let component = ReasonReact.reducerComponent("MyDocument");

let make = (_children) => {
  ...component,
  reducer: ((), _state: unit) => ReasonReact.NoUpdate,
  render: (_self) =>
    <Document>
      <Page size="A4" style=styles##page>
        <View style=styles##section>
          <Text key="hello"> (ReasonReact.stringToElement("Section #1")) </Text>
        </View>
        <View style=styles##section>
          <Text> (ReasonReact.stringToElement("Section #2")) </Text>
        </View>
      </Page>
    </Document>
};
```

### Save in a file

```reason
ReactPdfNode.render(<MyDocument />, "example.pdf")
|> Js.Promise.then_(() => Js.Promise.resolve @@ Js.log("Pdf created"));
```