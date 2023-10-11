[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~span: int,
    ~smSpan: int=?,
    ~mdSpan: int=?,
    ~lgSpan: int=?,
    ~children: React.element=?,
    unit
  ) =>
  React.element =
  "Column";
