[@bs.module "react-admin"]
external referenceManyField : ReasonReact.reactClass = "ReferenceManyField";

type sort =
  Js.t(
    {
      .
      "field": string,
      "order": string,
    },
  );

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~filter: 'b=?,
    ~label: string=?,
    ~perPage: int=?,
    ~record: 'c=?,
    ~reference: string=?,
    ~resource: string=?,
    ~sortBy: string=?,
    ~source: string,
    ~sort: sort=?,
    ~target: string=?,
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
      ~filter=?,
      ~label=?,
      ~perPage=?,
      ~record=?,
      ~reference=?,
      ~resource=?,
      ~sortBy=?,
      ~source,
      ~sort=?,
      ~target=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=referenceManyField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~filter?,
        ~label?,
        ~perPage?,
        ~record?,
        ~reference?,
        ~resource?,
        ~sortBy?,
        ~source,
        ~sort?,
        ~target?,
        (),
      ),
    children,
  );
