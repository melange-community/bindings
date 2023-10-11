[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~alt: string,
    ~color: string,
    ~naturalHeight: int,
    ~naturalWidth: int,
    ~src: string,
    ~children: React.element=?,
    ~fit: [@bs.string] [ | `cover | `contain | `none]=?,
    ~onError: unit => unit=?,
    ~onLoad: unit => unit=?,
    ~sizes: string=?,
    ~srcSet: string=?,
    unit
  ) =>
  React.element =
  "Image";
