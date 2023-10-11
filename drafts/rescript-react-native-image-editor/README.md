# `@rescript-react-native/image-editor`

[![Build Status](https://github.com/rescript-react-native/image-editor/workflows/Build/badge.svg)](https://github.com/rescript-react-native/image-editor/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/image-editor.svg)](https://www.npmjs.com/@rescript-react-native/image-editor)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/image-editor`](https://github.com/react-native-image-editor/react-native-image-editor).

Exposed as `ReactNativeImageEditor` module.

`@rescript-react-native/image-editor` X.y.\* means it's compatible with
`@react-native-community/image-editor` X.y.\*

## Installation

When
[`@react-native-community/image-editor`](https://github.com/react-native-image-editor/react-native-image-editor)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/image-editor
# or
yarn add @rescript-react-native/image-editor
```

`@rescript-react-native/image-editor` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/image-editor"
  ],
  //...
}
```

## Methods

### `cropImage`

`cropImage` takes arguments of type `source` and `cropData` and, if the image is
successfully cropped, returns path of the resulting image as a `string`, wrapped
in a Promise. If a remote image cannot be downloaded or an image cannot be
cropped, the Promise will be rejected.

```rescript
cropImage: (source, cropData) => Js.Promise.t(string)
```

### `fromRequired`

To convert a `ReactNative.Packager.required` object into [`source`](#source).

```rescript
fromRequired: ReactNative.Packager.required => source
```

### `fromUriSource`

To convert a URI given as a `string` into [`source`](#source).

```rescript
fromUriSource: string => source
```

## Types

### `source`

An abstract type created using the [`fromRequired`](#fromrequired) and
[`fromUriSource`](#fromurisource) methods.

### `offset`

An abstract type created using the constructor of the same name which takes
named arguments `x` and `y` of type `int`.

```rescript
offset: (~x: int, ~y: int) => offset
```

### `size`

An abstract type created using the constructor of the same name which takes
named arguments `width` and `height` of type `int`.

```rescript
size: (~width: int, ~height: int) => size
```

### `cropData`

An abstract type created using the constructor of the same name which takes
named arguments `offset` (of type `offset`) and `size` (of type `size`) and
optional arguments `displaySize` (of type `size`) and `resizeMode` (one of
polymorphic variants `` `contain ``, `` `cover ``, `` `stretch ``).

```rescript
cropData: (
  ~offset: offset,
  ~size: size,
  ~displaySize: size=?,
  ~resizeMode=[ | `contain | `cover | `stretch]=?,
  unit
) => cropData
```

## Example

```rescript
open ReactNative;

// hardcoding actual image dimensions
let imageWidth = 3396.;
let imageHeight = 2388.;

let windowWidth = Dimensions.get(`window)##width;
let windowHeight = Dimensions.get(`window)##height;

let displayWidth = windowWidth *. 0.9;
let displayHeight = windowWidth *. 0.9 *. imageHeight /. imageWidth;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~width=windowWidth->dp,
          ~height=windowHeight->dp,
          ~flexDirection=`column,
          ~alignItems=`center,
          ~justifyContent=`center,
          (),
        ),
      "frame":
        style(
          ~width=displayWidth->dp,
          ~height=displayHeight->dp,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~borderWidth=StyleSheet.hairlineWidth,
          (),
        ),
    })
  );

type state = {
  path: option(string),
  imageLoaded: bool,
};

type action =
  | SetPath(option(string))
  | SetImageLoaded;

let imageUri = "https://images.unsplash.com/photo-1520453803296-c39eabe2dab4";
let uri = ReactNativeImageEditor.fromUriSource(imageUri);

let handleCropImage = (cropData, send, handler) =>
	Js.Promise.(
		ReactNativeImageEditor.cropImage(uri, cropData)
		|> then_(successURI => resolve(send(handler(successURI))))
    |> catch(err => resolve(Js.Console.warn(err)))
    |> ignore
  );

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetPath(p) => {...state, path: p}
        | SetImageLoaded => {...state, imageLoaded: true}
        },
      {path: None, imageLoaded: false},
    );

  let size =
    ReactNativeImageEditor.size(
      ~width=(imageWidth *. 0.5)->floor->truncate,
      ~height=(imageHeight *. 0.5)->floor->truncate,
    );

  let cropData = offset =>
    ReactNativeImageEditor.cropData(
      ~offset,
      ~size,
      ~resizeMode=`cover,
      (),
    );

  <View style=styles##container>
      <Text>
        "Click on a quadrant of the image to crop it."->React.string
      </Text>
      <View style=styles##frame>
        <TouchableOpacity
          onPress={e =>
            handleCropImage(
              ReactNativeImageEditor.offset(
                ~x=
                  {e##nativeEvent##locationX /. displayWidth < 0.5
                     ? 0 : (0.5 *. imageWidth)->floor->truncate},
                ~y=
                  {e##nativeEvent##locationY /. displayHeight < 0.5
                     ? 0 : (0.5 *. imageHeight)->floor->truncate},
              )
              ->cropData,
              dispatch,
              link =>
              SetPath(Some(link))
            )
          }>
          <Image
            source={Image.Source.fromUriSource(
              Image.uriSource(
                ~uri=
                  Belt.Option.getWithDefault(
                    state.path,
                    imageUri,
                  ),
                ~width=displayWidth,
                ~height=
                  if (state.imageLoaded) {
                    displayHeight;
                  } else {
                    0.;
                  },
                (),
              ),
            )}
            resizeMode=`contain
            onLoadEnd={() => dispatch(SetImageLoaded)}
          />
        </TouchableOpacity>
        {state.imageLoaded
           ? React.null
           : <Text> "Please wait while image is loaded."->React.string </Text>}
      </View>
      <Button title="Reset Image" onPress={_ => dispatch(SetPath(None))} />
    </View>;
};
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
