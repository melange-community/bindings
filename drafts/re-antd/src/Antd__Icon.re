[@bs.module "@ant-design/icons"] [@react.component]
external make:
  (
    ~component: 'a=?,
    ~rorate: int=?,
    ~spin: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~twoToneColor: string=?
  ) =>
  React.element =
  "Icon";

module UploadOutlined = {
  [@react.component] [@bs.module "@ant-design/icons"]
  external make: (~height: 'a=?, ~width: 'b=?) => React.element =
    "UploadOutlined";
};

module SearchOutlined = {
  [@react.component] [@bs.module "@ant-design/icons"]
  external make: (~height: 'a=?, ~width: 'b=?) => React.element =
    "SearchOutlined";
};

module InfoCircleOutlined = {
  [@react.component] [@bs.module "@ant-design/icons"]
  external make: (~height: 'a=?, ~width: 'b=?) => React.element =
    "InfoCircleOutlined";
};
