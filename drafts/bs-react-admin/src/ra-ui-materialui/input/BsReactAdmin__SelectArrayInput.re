[@bs.module "react-admin"]
external selectArrayInput : ReasonReact.reactClass = "SelectArrayInput";

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
  meta: 'd,
  [@bs.optional]
  options: 'e,
  [@bs.optional]
  optionText: 'f,
  [@bs.optional]
  optionValue: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'g,
  [@bs.optional]
  translateChoice: bool,
};

let make =
    (
      ~choices=?,
      ~classes=?,
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~meta=?,
      ~options=?,
      ~optionText=?,
      ~optionValue=?,
      ~resource=?,
      ~source=?,
      ~translate=?,
      ~translateChoice=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=selectArrayInput,
    ~props=
      props(
        ~choices?,
        ~classes?,
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~meta?,
        ~options?,
        ~optionText?,
        ~optionValue?,
        ~resource?,
        ~source?,
        ~translate?,
        ~translateChoice?,
        (),
      ),
    children,
  );
