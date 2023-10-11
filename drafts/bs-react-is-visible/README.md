# React Is Visible for ReasonReact

[![Actions Status](https://github.com/lessp/bs-react-is-visible/workflows/Master%20Release/badge.svg)](https://github.com/lessp/bs-react-is-visible/actions)
[![npm version](https://badge.fury.io/js/bs-react-is-visible.svg)](https://badge.fury.io/js/bs-react-is-visible)

A small library that lets you know whether a component is visible on screen or not.

Uses the [IntersectionObserver API](https://developer.mozilla.org/en-US/docs/Web/API/IntersectionObserver) which you may want to [polyfill](#polyfill).

This is a semi-port of my React-library [react-is-visible](https://github.com/lessp/react-is-visible) for ReasonReact.

### Live Examples

[https://lessp.github.io/bs-react-is-visible/](https://lessp.github.io/bs-react-is-visible/)

## Installation

```bash
npm install bs-react-is-visible
```

Add `bs-react-is-visible` to `bs-dependencies` in `bsconfig.json`

## Usage

### Basic

```reason
[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible();

  <h1 ref>
    {(isVisible ? "I'm visible!" : "I'm not visible") |> React.string}
  </h1>;
};
```

### With options

```reason
[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible(~options={once: true}, ());

  <h1 ref>
    {(isVisible ? "I'm triggered as visible once!" : "I'm not visible") |> React.string}
  </h1>;
};
```

## Polyfill

[Browser compatibility.](https://developer.mozilla.org/en-US/docs/Web/API/Intersection_Observer_API#Browser_compatibility)

In order to polyfill, install the [polyfill from W3C](https://github.com/w3c/IntersectionObserver/tree/master/polyfill)

```bash
npm install intersection-observer --save
```

... and import it somewhere before using `ReactIsVisible`

The easiest way would be by doing something like:

```reason
// App.re
[%bs.raw {| require("intersection-observer") |}];

[@react.component]
// ...
```
