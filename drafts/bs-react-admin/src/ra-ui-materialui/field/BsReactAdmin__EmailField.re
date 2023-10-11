[@bs.module "react-admin"]
external emailField : ReasonReact.reactClass = "EmailField";

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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=emailField,
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
        (),
      ),
    children,
  );
