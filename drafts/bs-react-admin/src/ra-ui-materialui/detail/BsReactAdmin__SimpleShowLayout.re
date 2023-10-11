[@bs.module "react-admin"]
external simpleShowLayout : ReasonReact.reactClass = "SimpleShowLayout";

[@bs.obj]
external makeProps :
  (
    ~basePath: string=?,
    ~className: string=?,
    ~classes: 'a=?,
    ~record: 'b=?,
    ~resource: string=?,
    ~version: int=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~basePath=?,
      ~className=?,
      ~classes=?,
      ~record=?,
      ~resource=?,
      ~version=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=simpleShowLayout,
    ~props=
      makeProps(
        ~basePath?,
        ~className?,
        ~classes?,
        ~record?,
        ~resource?,
        ~version?,
        (),
      ),
    children,
  );
