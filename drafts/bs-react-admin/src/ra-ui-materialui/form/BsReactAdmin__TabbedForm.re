[@bs.module "react-admin"]
external tabbedForm : ReasonReact.reactClass = "TabbedForm";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i, 'j, 'k, 'l) = {
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  defaultValue: 'b,
  [@bs.optional]
  handleSubmit: 'c, /* passed by redux-form */
  [@bs.optional]
  invalid: bool,
  [@bs.optional]
  location: 'd,
  [@bs.optional] [@bs.as "match"]
  match_: 'e,
  [@bs.optional]
  pristine: bool,
  [@bs.optional]
  record: 'f,
  [@bs.optional]
  redirect: 'g,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  save: 'h, /* the handler defined in the parent, which triggers the REST submission */
  [@bs.optional]
  saving: 'i,
  [@bs.optional]
  submitOnEnter: bool,
  [@bs.optional]
  tabsWithErrors: list(string),
  [@bs.optional]
  toolbar: 'j,
  [@bs.optional]
  translate: 'k,
  [@bs.optional]
  validate: 'l,
  [@bs.optional]
  value: int,
  [@bs.optional]
  version: int,
};

let make =
    (
      ~basePath=?,
      ~className=?,
      ~classes=?,
      ~defaultValue=?,
      ~handleSubmit=?,
      ~invalid=?,
      ~location=?,
      ~match_=?,
      ~pristine=?,
      ~record=?,
      ~redirect=?,
      ~resource=?,
      ~save=?,
      ~saving=?,
      ~submitOnEnter=?,
      ~tabsWithErrors=?,
      ~toolbar=?,
      ~translate=?,
      ~validate=?,
      ~value=?,
      ~version=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabbedForm,
    ~props=
      props(
        ~basePath?,
        ~className?,
        ~classes?,
        ~defaultValue?,
        ~handleSubmit?,
        ~invalid?,
        ~location?,
        ~match_?,
        ~pristine?,
        ~record?,
        ~redirect?,
        ~resource?,
        ~save?,
        ~saving?,
        ~submitOnEnter?,
        ~tabsWithErrors?,
        ~toolbar?,
        ~translate?,
        ~validate?,
        ~value?,
        ~version?,
        (),
      ),
    children,
  );
