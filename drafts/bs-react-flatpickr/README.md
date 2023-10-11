# bs-react-flatpickr

ReasonML bindings for [react-flatpickr](https://github.com/haoxins/react-flatpickr).

## Table of contents

- [Installation](#installation)
- [Usage](#usage)
- [Basic props](#basic-props)
- [Event handlers](#event-handlers)

## Installation

```sh
yarn add bs-react-flatpickr
```

Add `bs-react-flatpickr` to your `bsconfig.json`.

## Usage

Because accepting different types types for a single prop is not type safe these bindings use polymorphic
variants instead to represent each one of the possible types:

```reason
open BsReactFlatpickr;

[@react.component]
let make = () =>
  <Flatpickr value=`date(Js.Date.make()) />;
```

## Basic props

All props are optional

### defaultValue

`string` This will be passed to the inner input

### value

This can either be `string`, `array(string)`, `Js.Date.t` or `array(Js.Date.t)` you need to use
polymorphic variants for these to be typesafe:

- *`str* - When you need values to be a ```string```
- *`strs* - When you need values to be ```array(string)```
- *`date* - When you need Values to be ```Js.Date.t```
- *`dates* - When you need values to be ```array(Js.Date.t)```

You use them by wrapping your value in the right variant like this:

```reason
<Flatpickr value=`str("2020-06-12") />
```
### options

`Js.t({..})` we provide a function that will help you generate these options for you `FlatpickrOptions.make`
all argument are optional and those not set will be set to `flatpickr.js` defaults.

- `Flatpickr options`: you can pass all `Flatpickr parameters` here.
- All `Flatpickr` [hooks][hooks] can be passed within this option too.

_*Example*_:

```reason
open BsReactFlatpickr;

[@react.component]
let make = () => {
  let today = Js.Date.make();
  let daysAgo = today |> DateFns.subDays(3.0);
  let daysFromNow = today |> DateFns.addDays(3.0);

  <Flatpickr
    options={
      FlatpickrOptions.make(
        ~dateFormat="F j, Y",
        ~maxDate=`date(daysFromNow),
        ~minDate=`date(daysAgo),
        (),
      )
    }
    value=today
  />;
};
```

### children

`React.element` this prop is closely related with the [wrap option](https://flatpickr.js.org/examples/#flatpickr-external-elements) 
from `Flatpickr`, please refer to the former link for more information.

### className

`string` This class will be applied to the inner `<input />` element.

## Event handlers

`(Value.t, string) => unit` every event handler prop has this type.

- `Value.t` - first arugment is an `array(Js.Date.t)` representing selected dates, if
no dates have been selected array will be empty.
- `string` - second argument is a representation of the latest selected date as a string
formatted by the `dateFormat` (see options section).

The following `props` are provided in order to customize the `Flatpickr's functions` default behaviour.
Please refer to the [Events & Hooks section](https://flatpickr.js.org/events/) from `Flatpickr` library.

**Note:** Event handlers for `flatpickr.js` have a third argument which is a `flatpickr` instance we've
ommitted that since the idea is to handle everything via react, that said if a valid usecase for it arises
we can add it in the future.

- `onChange`
- `onClose`
- `onDayCreate`
- `onDestroy`
- `onMonthChange`
- `onOpen`
- `onReady`
- `onValueUpdate`

# Styling

Just import any of the already present `flatpickr.js` themes:

```reason
[%bs.raw {| require("flatpickr/dist/flatpickr.css") |}];
```

**Note:** Both `FlatpickrTypes.Hooks` and `FlatpickrTypes.Value` have a `classify` function for boxing
and a `reduce` function for `unboxing`. This is because both the [value](#value) and [options](#options)
prop can be of more than one type:

```reason
open BsReactFlatpickr;

[@react.component]
let make = () => {
  let (date, setDate) = React.useState(_ => `date(Js.Date.make()));
  FlatpickrTypes.(
    <Flatpickr
      value=date
      onChange={
        (value, _) => setDate(_ => Value.classify(value))
      }
    />
  );
};
```

# Build

```
yarn build
```

# Storybook

```
yarn storybook
```
