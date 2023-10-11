[@bs.module "react-admin"]
external radioButtonGroupInput : ReasonReact.reactClass =
  "RadioButtonGroupInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g) = {
  [@bs.optional]
  choices: list('a),
  [@bs.optional]
  classes: 'b,
  [@bs.optional]
  className: string,
  [@bs.optional]
  input: 'c,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  options: 'd,
  [@bs.optional]
  optionText: 'e,
  [@bs.optional]
  optionValue: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'f,
  [@bs.optional]
  translateChoice: bool,
  [@bs.optional]
  meta: 'g,
};

let make =
    (
      ~choices=?,
      ~classes=?,
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~options=?,
      ~optionText=?,
      ~optionValue=?,
      ~resource=?,
      ~source=?,
      ~translate=?,
      ~translateChoice=?,
      ~meta=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=radioButtonGroupInput,
    ~props=
      props(
        ~choices?,
        ~classes?,
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~options?,
        ~optionText?,
        ~optionValue?,
        ~resource?,
        ~source?,
        ~translate?,
        ~translateChoice?,
        ~meta?,
        (),
      ),
    children,
  );
