@deriving(abstract)
type action = {
  label: string,
  onPress: unit => unit,
}

type jsImageProps = {"size": float}

type imageProps = {size: float}

type renderImage = jsImageProps => React.element

let renderImage = (reRenderIcon: imageProps => React.element): renderImage =>
  (jsIconProps: jsImageProps) => reRenderIcon({size: jsIconProps["size"]})

@module("react-native-paper") @react.component
external make: (
  ~visible: bool,
  ~actions: array<action>,
  ~image: renderImage=?,
  ~style: ReactNative.Style.t=?,
  ~theme: Paper__ThemeProvider.Theme.t=?,
) => React.element = "Banner"
