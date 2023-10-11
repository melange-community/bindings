[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~children: React.element=?,
    ~height: string=?,
    ~shape: [@bs.string] [ | `circle | `rounded | `square]=?,
    ~wash: bool=?,
    ~width: string=?,
    ~willChangeTransform: bool=?,
    unit
  ) =>
  React.element =
  "Mask";
