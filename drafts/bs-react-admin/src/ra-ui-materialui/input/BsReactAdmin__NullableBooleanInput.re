[@bs.module "react-admin"]
external nullableBooleanInput : ReasonReact.reactClass =
  "NullableBooleanInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e) = {
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  className: string,
  [@bs.optional]
  input: 'b,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  meta: 'c,
  [@bs.optional]
  options: 'd,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'e,
};

let make =
    (
      ~classes=?,
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~meta=?,
      ~options=?,
      ~resource=?,
      ~source=?,
      ~translate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=nullableBooleanInput,
    ~props=
      props(
        ~classes?,
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~meta?,
        ~options?,
        ~resource?,
        ~source?,
        ~translate?,
        (),
      ),
    children,
  );
