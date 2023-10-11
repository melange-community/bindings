# Reason bindings for React Icons

[Reason](https://reasonml.github.io/) bindings for [React Icons](https://github.com/react-icons/react-icons).

## Installation

```
yarn add bs-react-icons
```

Then add `bs-react-icons` to `bs-dependencies` in your `bsconfig.json`. Remembber to make sure you use ES2015 modules so you don't wreak havoc with your bundle size.

```json
{
  "bs-dependencies": ["bs-react-icons"],
  "package-specs": [
    {
      "module": "es6"
    }
  ]
}
```

If you experience slow build times or large bundle sizes, alter the way webpack resolves files.
[See this issue](https://github.com/react-icons/react-icons/issues/154) for more information.

```js
// webpack.config.js
module.exports = {
  resolve: {
    extensions: ['.mjs', '.js', '.jsx']
  }
};
```

## Usage

```reason
let component = ReasonReact.statelessComponent("Example");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <>
      <ReactIcons.FaBeer />
      <ReactIcons.IoIosBeer />
      <ReactIcons.MdLocalDrink />
      <ReactIcons.TiBeer />
      <ReactIcons.GoKebabHorizontal>
      <ReactIcons.FiCodepen />
    </>
};
```
