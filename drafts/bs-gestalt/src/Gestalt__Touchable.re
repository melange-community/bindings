[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~onTouch: Gestalt__Event.t(ReactEvent.Mouse.t) => unit,
    ~children: React.element=?,
    ~fullHeight: bool=?,
    ~fullWidth: bool=?,
    ~mouseCursor: [@bs.string] [
                    | `copy
                    | `grab
                    | `grabbing
                    | `move
                    | `noDrop
                    | `pointer
                    | `zoomIn
                    | `zoomOut
                  ]
                    =?,
    ~onMouseEnter: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    ~onMouseLeave: Gestalt__Event.t(ReactEvent.Mouse.t) => unit=?,
    ~shape: [@bs.string] [
              | `square
              | `rounded
              | `pill
              | `circle
              | `roundedTop
              | `roundedBottom
              | `roundedLeft
              | `roundedRight
            ]
              =?,
    unit
  ) =>
  React.element =
  "Touchable";
