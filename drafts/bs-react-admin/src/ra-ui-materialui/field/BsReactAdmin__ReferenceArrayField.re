[@bs.module "react-admin"]
external referenceArrayField : ReasonReact.reactClass = "ReferenceArrayField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~label: string=?,
    ~record: 'b=?,
    ~reference: string=?,
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
      ~classes=?,
      ~className=?,
      ~label=?,
      ~record=?,
      ~reference=?,
      ~resource=?,
      ~sortBy=?,
      ~source,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=referenceArrayField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~label?,
        ~record?,
        ~reference?,
        ~resource?,
        ~sortBy?,
        ~source,
        (),
      ),
    children,
  );
