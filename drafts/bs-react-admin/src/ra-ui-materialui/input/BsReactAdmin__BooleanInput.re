[@bs.module "react-admin"]
external booleanInput : ReasonReact.reactClass = "BooleanInput";

[@bs.deriving abstract]
type props('a, 'b) = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  input: 'a,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  options: 'b,
};

let make =
    (
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~resource=?,
      ~source=?,
      ~options=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=booleanInput,
    ~props=
      props(
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~resource?,
        ~source?,
        ~options?,
        (),
      ),
    children,
  );
