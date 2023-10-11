[@bs.module "react-admin"]
external disabledInput : ReasonReact.reactClass = "DisabledInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd) = {
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  className: string,
  [@bs.optional]
  label: string,
  [@bs.optional]
  input: 'b,
  [@bs.optional]
  options: 'c,
  [@bs.optional]
  record: 'd,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
};

let make =
    (
      ~classes=?,
      ~className=?,
      ~label=?,
      ~input=?,
      ~options=?,
      ~record=?,
      ~resource=?,
      ~source=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=disabledInput,
    ~props=
      props(
        ~classes?,
        ~className?,
        ~label?,
        ~input?,
        ~options?,
        ~record?,
        ~resource?,
        ~source?,
        (),
      ),
    children,
  );
