[@bs.module "react-admin"]
external referenceArrayInput : ReasonReact.reactClass = "ReferenceArrayInput";

type sort =
  Js.t(
    {
      .
      "field": string,
      "order": string,
    },
  );

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e) = {
  [@bs.optional]
  allowEmpty: bool,
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  filter: 'a,
  [@bs.optional]
  filterToQuery: 'b,
  [@bs.optional]
  input: 'c,
  [@bs.optional]
  label: string,
  [@bs.optional]
  meta: 'd,
  [@bs.optional]
  perPage: int,
  [@bs.optional]
  reference: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  sort,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'e,
};

let make =
    (
      ~allowEmpty=?,
      ~basePath=?,
      ~className=?,
      ~filter=?,
      ~filterToQuery=?,
      ~input=?,
      ~label=?,
      ~meta=?,
      ~perPage=?,
      ~reference=?,
      ~resource=?,
      ~sort=?,
      ~source=?,
      ~translate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=referenceArrayInput,
    ~props=
      props(
        ~allowEmpty?,
        ~basePath?,
        ~className?,
        ~filter?,
        ~filterToQuery?,
        ~input?,
        ~label?,
        ~meta?,
        ~perPage?,
        ~reference?,
        ~resource?,
        ~sort?,
        ~source?,
        ~translate?,
        (),
      ),
    children,
  );
