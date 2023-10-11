[@bs.module "react-admin"]
external checkboxGroupInput : ReasonReact.reactClass = "CheckboxGroupInput";

type input('a) = Js.t({. "onChange": 'a});

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g) = {
  [@bs.optional]
  choices: list('a),
  [@bs.optional]
  classes: 'b,
  [@bs.optional]
  className: string,
  [@bs.optional]
  label: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  options: 'c,
  [@bs.optional]
  input: input('d),
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  optionText: 'e,
  [@bs.optional]
  optionValue: string,
  [@bs.optional]
  resource: string,
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
      ~label=?,
      ~source=?,
      ~options=?,
      ~input=?,
      ~isRequired=?,
      ~optionText=?,
      ~optionValue=?,
      ~resource=?,
      ~translate=?,
      ~translateChoice=?,
      ~meta=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=checkboxGroupInput,
    ~props=
      props(
        ~choices?,
        ~classes?,
        ~className?,
        ~label?,
        ~source?,
        ~options?,
        ~input?,
        ~isRequired?,
        ~optionText?,
        ~optionValue?,
        ~resource?,
        ~translate?,
        ~translateChoice?,
        ~meta?,
        (),
      ),
    children,
  );
