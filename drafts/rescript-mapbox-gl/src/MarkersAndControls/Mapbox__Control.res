type t;
type position = @string [
  | @as("top-left") #topLeft 
  | @as("top-right") #topRight
  | @as("bottom-left") #bottomLeft
  | @as("bottom-right") #bottomRight
];
