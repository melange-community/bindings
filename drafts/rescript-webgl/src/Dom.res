type elementT
type mouseEventT

@val @scope("window")
external requestAnimationFrame: (unit => unit) => unit = "requestAnimationFrame"

@val external setTimeout: (unit => unit, int) => unit = "setTimeout"

@val @scope("document") @return(nullable)
external querySelector: string => option<elementT> = "querySelector"

@get external getValue: elementT => string = "value"

@get external getWidth: elementT => int = "width"
@get external getHeight: elementT => int = "height"

@send external onClick: (elementT, @as("click") _, mouseEventT => unit) => unit = "addEventListener"
@send external onInput: (elementT, @as("input") _, unit => unit) => unit = "addEventListener"

@send
external onMouseMove: (elementT, @as("mousemove") _, mouseEventT => unit) => unit =
  "addEventListener"
@send
external onMouseDown: (elementT, @as("mousedown") _, mouseEventT => unit) => unit =
  "addEventListener"
@send
external onMouseUp: (elementT, @as("mouseup") _, mouseEventT => unit) => unit = "addEventListener"

@get external getOffsetX: mouseEventT => float = "offsetX"
@get external getOffsetY: mouseEventT => float = "offsetY"
