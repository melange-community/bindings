[@bs.module "react-admin"]
external autocompleteInput : ReasonReact.reactClass = "AutocompleteInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i, 'j, 'k) = {
  [@bs.optional]
  allowEmpty: bool,
  [@bs.optional]
  alwaysRenderSuggestions: bool, /* used only for unit tests */
  [@bs.optional]
  choices: list('a),
  [@bs.optional]
  classes: 'b,
  [@bs.optional]
  className: string,
  [@bs.optional] [@bs.as "InputProps"]
  inputProps: 'c,
  [@bs.optional]
  input: 'd,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  limitChoicesToValue: bool,
  [@bs.optional]
  meta: 'e,
  [@bs.optional]
  options: 'f,
  [@bs.optional]
  optionText: 'g,
  [@bs.optional]
  optionValue: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  setFilter: 'h,
  [@bs.optional]
  source: string,
  [@bs.optional]
  suggestionComponent: 'i,
  [@bs.optional]
  translate: 'j,
  [@bs.optional]
  translateChoice: bool,
  [@bs.optional]
  inputValueMatcher: 'k,
};

let make =
    (
      ~allowEmpty=?,
      ~alwaysRenderSuggestions=?,
      ~choices=?,
      ~classes=?,
      ~className=?,
      ~inputProps=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~limitChoicesToValue=?,
      ~meta=?,
      ~options=?,
      ~optionText=?,
      ~optionValue=?,
      ~resource=?,
      ~setFilter=?,
      ~source=?,
      ~suggestionComponent=?,
      ~translate=?,
      ~translateChoice=?,
      ~inputValueMatcher=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=autocompleteInput,
    ~props=
      props(
        ~allowEmpty?,
        ~alwaysRenderSuggestions?,
        ~choices?,
        ~classes?,
        ~className?,
        ~inputProps?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~limitChoicesToValue?,
        ~meta?,
        ~options?,
        ~optionText?,
        ~optionValue?,
        ~resource?,
        ~setFilter?,
        ~source?,
        ~suggestionComponent?,
        ~translate?,
        ~translateChoice?,
        ~inputValueMatcher?,
        (),
      ),
    children,
  );
