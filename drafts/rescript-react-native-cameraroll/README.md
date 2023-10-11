# `@rescript-react-native/cameraroll`

[![Build Status](https://github.com/rescript-react-native/cameraroll/workflows/Build/badge.svg)](https://github.com/rescript-react-native/cameraroll/actions)
[![Version](https://img.shields.io/npm/v/@rescript-react-native/cameraroll.svg)](https://www.npmjs.com/@rescript-react-native/cameraroll)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`@react-native-community/cameraroll`](https://github.com/react-native-cameraroll/react-native-cameraroll).

Exposed as `ReactNativeCameraRoll` module.

`@rescript-react-native/cameraroll` X.y.\* means it's compatible with
`@react-native-community/cameraroll` X.y.\*

## Installation

When
[`@react-native-community/cameraroll`](https://github.com/react-native-cameraroll/react-native-cameraroll)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @rescript-react-native/cameraroll
# or
yarn add @rescript-react-native/cameraroll
```

`@rescript-react-native/cameraroll` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "@rescript-react-native/cameraroll"
  ],
  //...
}
```

## Methods

### `save`

Allows saving photos and videos to the Camera Roll or Photo Gallery, similar to
[`saveToCameraRoll`](#savetocameraroll).

The function will return the URI for the saved file as a string wrapped in a
Promise.

```rescript
save: string => Js.Promise.t(string)
```

### `saveWithOptions`

Allows saving photos and videos to the Camera Roll or Photo Gallery, similar to
[`saveToCameraRoll`](#savetocameraroll), however, a particular album may be
specified in a `saveOptions` object.

The function will return the URI for the saved file as a string wrapped in a
Promise.

```rescript
saveWithOptions: (string, saveOptions) => Js.Promise.t(string)
```

### `saveToCameraRoll`

Allows saving photos and videos to the Camera Roll or Photo Gallery. File to be
saved is specified as a tag (of type `string`) which can be

- on Android, a local image or video URI, such as "file:///sdcard/img.png"
- on iOS, a local video URI or any image URI (local, remote asset-library, or
  base64 data URIs)

Media type (photo or video) will be automatically inferred; any file will be
inferred to be a photo, unless the file extension is `mov` or `mp4`, then it
will be inferred to be a video.

The function will return the URI for the saved file as a string wrapped in a
Promise.

```rescript
saveToCameraRoll: string => Js.Promise.t(string)
```

### `saveToCameraRollWithType`

Allows saving photos and videos to the Camera Roll, where the tag will be
specified as above, overriding the automatically determined type by specifying
one of the polymorphic variants `` `photo `` or `` `video ``.

The function will return the URI for the saved file as a string wrapped in a
Promise.

```rescript
saveToCameraRollWithType: (string, [ | #photo | #video]) => Js.Promise.t(string)
```

### `deletePhotos`

To request deletion of photos (as `array(string)`) from the Camera Roll. Returns
`bool` wrapped in a Promise. The Promise will be rejected if deletion does not
succeed; on _Android_ that would imply a system error whereas on _iOS_ the user
may have cancelled the request to delete.

On _Android_, the uri must be a local image or video URI, such as
"file:///sdcard/img.png".

On _iOS_, the uri can be any image URI (including local, remote asset-library
and base64 data URIs) or a local video file URI. The user will be presented with
a dialog box that showing the asset(s) and asked for confirmation. This cannot
be bypassed as per Apple Developer guidelines.

```rescript
deletePhotos: array(string) => Js.Promise.t(bool)
```

### `getAlbums`

Returns a list of albums wrapped in a Promise.

```rescript
getAlbums: unit => Js.Promise.t(array(album))
```

### `getAlbumsWithParams`

Returns a list of albums of type specified in a `getAlbumsParams` object,
wrapped in a Promise.

```rescript
getAlbums: getAlbumsParams => Js.Promise.t(array(album))
```

### `getPhotos`

Allows searching for photos or videos matching given parameters.

Takes as argument `getPhotosParams` and returns a `photoIdentifiersPage` object
wrapped in a Promise. `edges` key of the `photoIdentifiersPage` object would be
of type `array(photoIdentifier)`, where each `photoIdentifier` object would
contain details of each photo or video matching parameters provided in the
`getPhotosParam` object.

```rescript
getPhotos: getPhotosParams => Js.Promise.t(photoIdentifiersPage)
```

## Types

### `album`

```rescript
type album = {
  title: string,
  count: int
};
```

### `getAlbumsParams`;

can be constructed with the constructor of the same name

```rescript
getAlbumsParams:
  (
    ~assetType: [
                   | #All
                   | #Photos
                   | #Videos
                 ]
  ) =>
  getAlbumsParams
```

### `getPhotosParams`

can be constructed with the constructor of the same name

- `first` takes an integer which specifies the number of files for which details
  will be returned. Files will match in reverse order (i.e. most recent first)
- `after` takes a string which should be obtained from `photoIdentifiersPage`
  returned in a previous `getPhotos` call, under the `end_cursor` key contained
  in turn under the `page_info` key.

```rescript
getPhotosParams:
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: [
                   | #Album
                   | #All
                   | #Event
                   | #Faces
                   | #Library
                   | #PhotoStream
                   | #SavedPhotos
                 ]
                   =?,
    ~groupName: string=?,
    ~assetType: [ | #All | #Videos | #Photos]=?,
    ~mimeTypes: array(string)=?,
    ~fromTime: float=?,
    ~toTime: float=?,
    ~include_: array(string)=?,
    unit
  ) => getPhotosParams
```

### `image`

```rescript
type image = {
  filename: Js.Nullable.t(string),
  uri: string,
  height: Js.Nullable.t(float),
  width: Js.Nullable.t(float),
  fileSize: Js.Nullable.t(float),
  playableDuration: Js.Nullable.t(float),
}
```

### `location`

```rescript
type location = {
  latitude: Js.Nullable.t(float),
  longitude: Js.Nullable.t(float),
  altitude: Js.Nullable.t(float),
  heading: Js.Nullable.t(float),
  speed: Js.Nullable.t(float),
};
```

### `node`

```rescript
type node = {
  \"type": string,
  \"group_name": string,
  image,
  timestamp: float,
  location: Js.Nullable.t(location),
}
```

### `pageInfo`

```rescript
type pageInfo = {
  \"has_next_page": bool,
  \"start_cursor": Js.Nullable.t(string),
  \"end_curson": Js.Nullable.t(string),
};

```

### `photoIdentifiersPage`

```rescript
type photoIdentifiersPage = {
  edges: array(photoIdentifier),
  \"page_info",
}
```

### `photoIdentifier`

```rescript
  type photoIdentifier = {node}
```

### `saveOptions`

can be constructed with the constructor of the same name

```rescript
saveOptions:
  (
    ~_type: [
      | #auto
      | #photo
      | #video
    ],
    ~album: string
  ) =>
  saveOptions
```

## Example

```rescript
open ReactNative;
open ReactNativeCameraRoll;

let windowWidth = Dimensions.get(`window)##width;
let windowHeight = Dimensions.get(`window)##height;

type state = {
  tag: string,
  path: option(string),
  photos: array(photoIdentifier),
};

type action =
  | SetTag(string)
  | SetPath(string)
  | SetPhotos(array(photoIdentifier));

let styles = Style.(
  StyleSheet.create({
    "container":
      style(
        ~flex=1.,
        ~flexDirection=`column,
        ~alignItems=`center,
        ~justifyContent=`spaceBetween,
        (),
      ),
    "getPhotosExample":
      style(
        ~height=(0.25 *. windowHeight)->dp,
        ~justifyContent=`spaceBetween,
        (),
      ),
    "saveToCameraRollExample":
      style(
        ~width=(0.8 *. windowWidth)->dp,
        ~height=(0.6 *. windowHeight)->dp,
        ~margin=(0.1 *. windowWidth)->dp,
        ~justifyContent=`spaceAround,
        (),
      ),
    "image":
      style(
        ~width=(0.8 *. windowWidth)->dp,
        ~height=(0.56 *. windowWidth)->dp,
        (),
      ),
    "imageContainer":
      style(
        ~width=(0.8 *. windowWidth)->dp,
        ~height=(0.56 *. windowWidth)->dp,
        ~borderWidth=1.,
        ~justifyContent=`center,
        (),
      ),
    "text": style(~textAlign=`center, ()),
    "textInput":
      style(
        ~textAlign=`center,
        ~borderRadius=8.,
        ~padding=4.->dp,
        ~borderWidth=1.,
        ~backgroundColor=Color.linen,
        (),
      ),
    "thumbnail":
      style(
        ~width=(0.21 *. windowHeight)->dp,
        ~height=(0.15 *. windowHeight)->dp,
        (),
      ),
    "thumbnails":
      style(
        ~height=(0.15 *. windowHeight)->dp,
        (),
      ),
  })
);

let styledText = s => {
  <Text style=styles##text> s->React.string </Text>;
};

let thumbnails = photos => {
  <View style=styles##thumbnails>
    <ScrollView horizontal=true>
      {photos
       ->Belt.Array.mapWithIndex((i, s) =>
           <Image
             style=styles##thumbnail
             source={Image.Source.fromUriSource(
               Image.uriSource(~uri=s.node.image.uri, ()),
             )}
             key={string_of_int(i)}
           />
         )
       ->React.array}
    </ScrollView>
  </View>;
};

let inputBox = (tag, dispatch) => {
  <TextInput
    style=styles##textInput
    multiline=true
    defaultValue="https://images.unsplash.com/photo-1520453803296-c39eabe2dab4"
    value=tag
    onChangeText={s => dispatch(SetTag(s))}
  />;
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetTag(uri) => {...state, tag: uri}
        | SetPath(uri) => {...state, path: Some(uri)}
        | SetPhotos(a) => {...state, photos: a}
        },
      {
        tag: "https://images.unsplash.com/photo-1520453803296-c39eabe2dab4",
        path: None,
        photos: [||],
      },
    );

  let getPhotos = () => {
    Js.Promise.(
      getPhotos(
        getPhotosParams(
          ~first=20,
          ~assetType=`Photos,
          ~groupTypes=`All,
          (),
        ),
      )
      |> then_(r => resolve(dispatch(SetPhotos(r.edges))))
      |> catch(err => resolve(Js.Console.warn(err)))
      |> ignore
    );
  };

  let savePhoto = uri => {
    Js.Promise.(
      saveToCameraRoll(uri)
      |> then_(r => resolve(dispatch(SetPath(r))))
      |> catch(err => resolve(Js.Console.warn(err)))
      |> ignore
    );
  };

  <View style=styles##container>
    <View style=styles##saveToCameraRollExample>
      <View style=styles##imageContainer>
        {switch (state.path) {
         | None =>
           // default view, before a photo is saved to the Camera Roll or Photo Library
           <View>
             {styledText("Press the Save Photo button")}
             {styledText("below to load photo")}
           </View>
         | Some(p) =>
           // Once a photo is saved to the Camera Roll or Photo Library, it will be displayed in this view
           <Image
             style=styles##image
             source={Image.Source.fromUriSource(Image.uriSource(~uri=p, ()))}
           />
         }}
      </View>
      <View>
        {styledText("Enter a path for a photo to save,")}
        {styledText("or try the example given below")}
        // TextInput box to try other photo sources
        {inputBox(state.tag, dispatch)}
        // An attempt will be made to save the photo file specified in the TextInput box to the Camera Roll or Photo Library once the button below is pressed
        <Button
          onPress={_ => savePhoto(state.tag)}
          title={js|Save a Photo|js}
        />
      </View>
    </View>
    <View style=styles##getPhotosExample>
      <View>
        {styledText("Saved photo will appear in the Camera Roll")}
        // An attempt will be made to get the most recent 20 photos from the Camera Roll or Photo Library
        <Button onPress={_ => getPhotos()} title={js|Open CameraRoll|js} />
      </View>
      {thumbnails(state.photos)}
    </View>
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
