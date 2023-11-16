type t = {
  begin: unit => unit,
  activate: unit => unit,
  fail: unit => unit,
  end: unit => unit,
}

type gestureStateManager = {create: int => t}

@module("react-native-gesture-handler")
external gestureStateManager: gestureStateManager = "GestureStateManager"
