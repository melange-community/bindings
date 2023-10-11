[@bs.module "react-admin"]
external richTextField : ReasonReact.reactClass = "RichTextField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~label: string=?,
    ~record: 'a=?,
    ~sortBy: string=?,
    ~source: string,
    ~stripTags: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~addLabel=?,
      ~basePath=?,
      ~className=?,
      ~cellClassName=?,
      ~headerClassName=?,
      ~label=?,
      ~record=?,
      ~sortBy=?,
      ~source,
      ~stripTags=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=richTextField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~label?,
        ~record?,
        ~sortBy?,
        ~source,
        ~stripTags?,
        (),
      ),
    children,
  );
