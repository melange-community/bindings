[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~name: string,
    ~icon: [@bs.string] [ | [@bs.as "check-circle"] `checkCircle | `pinterest]
             =?,
    ~outline: bool=?,
    ~size: [@bs.string] [ | `sm | `md | `lg]=?,
    ~src: string=?,
    ~verified: bool=?,
    unit
  ) =>
  React.element =
  "Avatar";
