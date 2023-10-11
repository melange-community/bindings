[@bs.module "react-admin"]
external functionField : ReasonReact.reactClass = "FunctionField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~label: string=?,
    ~render: 'a,
    ~record: 'b=?,
    ~sortBy: string=?,
    ~source: string=?,
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
      ~render,
      ~record=?,
      ~sortBy=?,
      ~source=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=functionField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~label?,
        ~render,
        ~record?,
        ~sortBy?,
        ~source?,
        (),
      ),
    children,
  );
