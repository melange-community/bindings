[@bs.module "react-admin"]
external simpleForm : ReasonReact.reactClass = "SimpleForm";

[@bs.obj]
external makeProps :
  (
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~defaultValue: 'b=?,
    ~handleSubmit: 'c=?,
    ~invalid: bool=?,
    ~pristine: bool=?,
    ~record: 'd=?,
    ~resource: string=?,
    ~redirect: 'e=?,
    ~save: 'f=?,
    ~saving: 'g=?,
    ~submitOnEnter: bool=?,
    ~toolbar: 'h=?,
    ~validate: 'i=?,
    ~version: int=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~defaultValue=?,
      ~handleSubmit=?,
      ~invalid=?,
      ~pristine=?,
      ~record=?,
      ~resource=?,
      ~redirect=?,
      ~save=?,
      ~saving=?,
      ~submitOnEnter=?,
      ~toolbar=?,
      ~validate=?,
      ~version=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=simpleForm,
    ~props=
      makeProps(
        ~basePath?,
        ~classes?,
        ~className?,
        ~defaultValue?,
        ~handleSubmit?,
        ~invalid?,
        ~pristine?,
        ~record?,
        ~resource?,
        ~redirect?,
        ~save?,
        ~saving?,
        ~submitOnEnter?,
        ~toolbar?,
        ~validate?,
        ~version?,
        (),
      ),
    children,
  );
