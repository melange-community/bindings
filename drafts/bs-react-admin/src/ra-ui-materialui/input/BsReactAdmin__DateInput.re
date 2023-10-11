[@bs.module "react-admin"]
external dateInput : ReasonReact.reactClass = "DateInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd) = {
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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=dateInput,
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
        (),
      ),
    children,
  );
