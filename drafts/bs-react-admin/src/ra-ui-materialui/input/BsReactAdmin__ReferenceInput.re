[@bs.module "react-admin"]
external referenceInput : ReasonReact.reactClass = "ReferenceInput";

type sort =
  Js.t(
    {
      .
      "field": string,
      "order": string,
    },
  );

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) = {
  [@bs.optional]
  allowEmpty: bool,
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  filter: 'b,
  [@bs.optional]
  filterToQuery: 'c,
  [@bs.optional]
  input: 'd,
  [@bs.optional]
  label: string,
  [@bs.optional]
  meta: 'e,
  [@bs.optional]
  onChange: 'f,
  [@bs.optional]
  perPage: int,
  [@bs.optional]
  record: 'g,
  [@bs.optional]
  reference: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  sort,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'h,
};

let make =
    (
      ~allowEmpty=?,
      ~basePath=?,
      ~className=?,
      ~classes=?,
      ~filter=?,
      ~filterToQuery=?,
      ~input=?,
      ~label=?,
      ~meta=?,
      ~onChange=?,
      ~perPage=?,
      ~record=?,
      ~reference=?,
      ~resource=?,
      ~sort=?,
      ~source=?,
      ~translate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=referenceInput,
    ~props=
      props(
        ~allowEmpty?,
        ~basePath?,
        ~className?,
        ~classes?,
        ~filter?,
        ~filterToQuery?,
        ~input?,
        ~label?,
        ~meta?,
        ~onChange?,
        ~perPage?,
        ~record?,
        ~reference?,
        ~resource?,
        ~sort?,
        ~source?,
        ~translate?,
        (),
      ),
    children,
  );
