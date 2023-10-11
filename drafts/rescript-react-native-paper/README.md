# `@rescript-react-native/paper`

[![Build Status](https://github.com/rescript-react-native/paper/workflows/Build/badge.svg)](https://github.com/rescript-react-native/paper/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/paper.svg)](https://www.npmjs.com/@rescript-react-native/paper)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-native-paper`](https://github.com/callstack/react-native-paper).

Exposed as `Paper` module.

`@rescript-react-native/paper` X.y.\* means it's compatible with
`react-native-paper` X.y.\*

## Status

⚠️ Work in progress. These bindings are used successfully in several apps, but
are not complete yet and still subject to change.

[Checkout missing components](#implemented-components)

## Installation

When [`react-native-paper`](https://github.com/callstack/react-native-paper)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/paper
# or
yarn add @rescript-react-native/paper
```

`@rescript-react-native/paper` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/paper"
  ],
  //...
}
```

## Usage

### Components

```rescript
[@react.component]
let make = () => {
  let (visible, setVisible) = React.useState(() => false);

  <Paper.Portal>
    <Paper.Dialog visible onDismiss={_ => setVisible(_ => false)}>
      <Paper.Dialog.Title>
        {"Title"->React.string}
      </Paper.Dialog.Title>
      <Paper.Dialog.Description>
        {"Description"->React.string}
      </Paper.Dialog.Description>
    </Paper.Dialog>
  </Paper.Portal>
};
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.

## Implemented components

- [x] ActivityIndicator
- [x] Avatar
- [x] Appbar
- [x] BottomNavigation
- [x] Badge
- [x] Banner
- [x] Button
- [x] Checkbox
- [x] Card
- [x] Chip
- [x] Dialog
- [x] Divider
- [x] FAB
- [ ] DataTable
- [x] Drawer
- [x] List
- [x] IconButton
- [x] Modal
- [ ] Menu
- [x] RadioButton
- [x] Searchbar
- [x] PaperProvider
- [x] Portal
- [x] ProgressBar
- [x] Snackbar
- [x] Surface
- [x] TextInput
- [x] TouchableRipple
- [x] ToggleButton
- [x] HelperText
- [x] ThemeProvider
- [x] withTheme (HoC)
- Typography
  - [x] Title
  - [x] Subheading
  - [x] Headline
  - [x] Paragraph
  - [x] Caption
  - [x] Text
