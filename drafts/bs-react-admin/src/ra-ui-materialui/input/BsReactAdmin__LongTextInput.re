[@bs.module "react-admin"]
external longTextInput : ReasonReact.reactClass = "LongTextInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd) = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  input: 'a,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  fullWidth: bool,
  [@bs.optional]
  meta: 'b,
  [@bs.optional]
  name: string,
  [@bs.optional]
  options: 'c,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  validate: 'd,
};

let make =
    (
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~fullWidth=?,
      ~meta=?,
      ~name=?,
      ~options=?,
      ~resource=?,
      ~source=?,
      ~validate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=longTextInput,
    ~props=
      props(
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~fullWidth?,
        ~meta?,
        ~name?,
        ~options?,
        ~resource?,
        ~source?,
        ~validate?,
        (),
      ),
    children,
  );
