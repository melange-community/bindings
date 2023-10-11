[@bs.module "react-admin"]
external arrayField : ReasonReact.reactClass = "ArrayField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~record: 'a=?,
    ~resource: string=?,
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
      ~record=?,
      ~resource=?,
      ~sortBy=?,
      ~source,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=arrayField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~record?,
        ~resource?,
        ~sortBy?,
        ~source,
        (),
      ),
    children,
  );
