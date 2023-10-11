# bs-chakra-ui 🚧

Bucklescript bindings for [chakra-ui](https://chakra-ui.com).

**Important note**, chakra-ui use the styled system but in order to avoid props bindings overhead, I decided to mainly use `<Box />` when I need to create space, etc.

## Install

```
yarn add @dck/bs-chakra-ui
```

Add it to `bs-dependencies` in your `bsconfig.json` :

```json
{
  "bs-dependencies": ["@dck/bs-chakra-ui"]
}
```

## Example

```reason
open BsChakra;

module App = {
  [@react.component]
  let make = () => {
    let (isChecked, setChecked) = React.useState(() => false);

    <ThemeProvider theme>
      <CSSReset />
      <Text fontSize={Responsive([|`center, `right, `left|])}>
        "Hello responsive"->React.string
      </Text>
      <Stack isInline=true align=`center spacing=2>
        <FormLabel htmlFor="toggle">
          <Text fontSize={All(`center)}>
            "Toggle"->React.string
          </Text>
        </FormLabel>
        <Switch
          id="toggle"
          size=`lg
          isChecked
          onChange={_ => setChecked(v => !v)}
        />
      </Stack>
    </ThemeProvider>
  };
};
```

### Todo

- [x] Accordion
- [x] Alert
- [ ] AspectRatioBox
- [x] Avatar
- [ ] Badge
- [x] Box 🚧
- [ ] Breadcrumb
- [x] Button 🚧
- [ ] Checkbox
- [x] CircularProgress
- [ ] CloseButton
- [ ] Code
- [ ] Collapse
- [ ] ControlBox
- [ ] Drawer
- [ ] Editable
- [x] Flex
- [x] FormControl
- [x] FormHelperText
- [x] FormErrorMessage
- [x] Heading
- [x] Icon
- [x] IconButton
- [x] Image
- [x] Input
- [x] Link
- [ ] List
- [x] Modal
- [x] Menu
- [x] NumberInput
- [ ] Popover
- [ ] Progress
- [ ] PseudoBox
- [ ] Radio
- [ ] Slider
- [x] Spinner
- [ ] Stat
- [x] Stack
- [x] Switch
- [ ] Tabs
- [ ] Tag
- [ ] Textarea
- [x] Text
- [ ] Toast
- [ ] Tooltip
- [x] useClipboard
- [x] useDisclosure
- [x] useTheme
