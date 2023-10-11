type alignVariant = [ | `top | `middle | `bottom];

[@bs.deriving jsConverter]
type flexVariant = [
  | `start
  | [@bs.as "end"] `_end
  | `center
  | [@bs.as "space-around"] `spaceAround
  | [@bs.as "space-between"] `spaceBetween
];

[@bs.module "antd"] [@react.component]
external make:
  (
    ~align: alignVariant=?,
    ~gutter: 'a=?,
    ~justify: flexVariant=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Row";
