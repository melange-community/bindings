type t

external fling: Fling.t => t = "%identity"
external pan: Pan.t => t = "%identity"

@module("react-native-gesture-handler") @scope("Gesture")
external makeFling: unit => Fling.t = "Fling"

@module("react-native-gesture-handler") @scope("Gesture")
external makePan: unit => Pan.t = "Pan"
