[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `horizontal
  | [@bs.as "vertical"] `vertical
];

[@bs.deriving jsConverter]
type typeVariant = [
  | [@bs.as "default"] `default
  | [@bs.as "navigation"] `navigation
];

[@bs.deriving jsConverter]
type statusVariant = [
  | [@bs.as "wait"] `wait
  | [@bs.as "process"] `process
  | [@bs.as "finish"] `finish
  | [@bas.as "error"] `error
];

[@bs.deriving jsConverter]
type sizeVariant = [ | [@bs.as "default"] `default | [@bs.as "small"] `small];

[@bs.module "antd"] [@react.component]
external make:
  (
    ~className: string=?,
    ~_type: typeVariant=?,
    ~current: int=?,
    ~direction: orientation=?,
    ~labelPlacement: orientation=?,
    ~progressDot: bool=?,
    ~size: sizeVariant=?,
    ~status: statusVariant=?,
    ~initial: int=?,
    ~onChange: unit=?,
    ~children: React.element=?,
    unit
  ) =>
  React.element =
  "Steps";

module Step = {
  [@react.component] [@bs.module "antd"] [@bs.scope "Steps"]
  external make:
    (
      ~title: 'a=?,
      ~description: 'a=?,
      ~status: statusVariant=?,
      ~icon: 'a=?,
      ~subTitle: 'string=?,
      ~disabled: bool=?
    ) =>
    React.element =
    "Step";
};
