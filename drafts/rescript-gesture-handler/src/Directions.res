type directions = {
  @as("RIGHT") right: int,
  @as("LEFT") left: int,
  @as("UP") up: int,
  @as("DOWN") down: int,
}

@module("react-native-gesture-handler")
external directions: directions = "Directions"

module type Direction = {
  type t
  let make: int => t
}

module Direction = {
  type t = int
  let make = direction => direction
}
