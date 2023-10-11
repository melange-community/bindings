# rescript-react-helmet

> [ReScript](https://rescript-lang.org) bindings for [React Helmet](https://github.com/nfl/react-helmet), a document head manager for React.

## Install

```console
yarn add react-helmet rescript-react-helmet
```

Note that you need `react`, `react-dom`, `@rescript/react` and `react-helmet`
as peer dependencies.

Adjust your `bsconfig.js` by adding this package:

```
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-helmet"
  ]
```

## Usage

```rescript
@react.component
let make = () =>
  <ReactHelmet defaultTitle="This is a title">
    <style>
      {j`
html {
  height: 100%;
  font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Ubuntu, "Helvetica Neue", sans-serif;
}
`->React.string}
    </style>
  </ReactHelmet>

```

### Server-side static rendering

```rescript
let helmet = ReactHelmet.renderStatic()
let title = helmet.title->ReactHelmet.toString
```

Follow official documentation for all methods available.

---

## [CHANGELOG](CHANGELOG.md)

## [LICENSE](LICENSE)
