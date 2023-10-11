[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~contentAspectRatio: int,
    ~height: int,
    ~width: int,
    ~children: React.element=?,
    unit
  ) =>
  React.element =
  "Letterbox";
