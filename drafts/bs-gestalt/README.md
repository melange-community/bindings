# Reason bindings for [Gestalt](https://github.com/pinterest/gestalt)

[![npm](https://img.shields.io/npm/v/bs-gestalt.svg)](https://www.npmjs.com/package/bs-gestalt)

The bindings are a work in progress, I'm adding things on the go. If you miss anything, or want to see something change, feel free to send me a PR.

## Installation
```
yarn add bs-gestalt
yarn add gestalt
```

Add `bs-gestalt` to your `bs-dependencies` in `bsconfig.json`.

```json
{
  "bs-dependencies": ["bs-gestalt"]
}
```

## Usage

```reason
open Gestalt;

[@react.component]
let make = () =>
  <Box display=`flex alignContent=`around>
    {React.string("Hello World!")}
  </Box>;
```

## Components

* [x] Avatar
* [x] Badge
* [x] Box
* [x] Button
* [x] Card
* [ ] Checkbox
* [ ] Collage
* [x] Column
* [x] Container
* [ ] Divider
* [x] Flyout
* [ ] GroupAvatar
* [x] Heading
* [x] Icon
* [x] IconButton
* [x] Image
* [x] Label
* [ ] Layer
* [ ] Letterbox
* [x] Link
* [x] Mask
* [ ] Masonry
* [x] Modal
* [ ] Pog
* [ ] Pulsar
* [ ] RadioButton
* [ ] SearchField
* [x] SegmentedControl
* [ ] SelectList
* [x] Spinner
* [ ] Sticky
* [ ] Switch
* [x] Tabs
* [x] Text
* [ ] TextArea
* [x] TextField
* [ ] Toast
* [x] Tooltip
* [x] Touchable
* [ ] Video
