[@bs.module "react-admin"]
external selectField : ReasonReact.reactClass = "SelectField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~choices: list('a)=?,
    ~label: string=?,
    ~optionText: 'b=?,
    ~optionValue: string=?,
    ~resource: string=?,
    ~record: 'c=?,
    ~sortBy: string=?,
    ~source: string,
    ~translate: 'd=?,
    ~translateChoice: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~addLabel=?,
      ~basePath=?,
      ~className=?,
      ~cellClassName=?,
      ~headerClassName=?,
      ~choices=?,
      ~label=?,
      ~optionText=?,
      ~optionValue=?,
      ~resource=?,
      ~record=?,
      ~sortBy=?,
      ~source,
      ~translate=?,
      ~translateChoice=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=selectField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~choices?,
        ~label?,
        ~optionText?,
        ~optionValue?,
        ~resource?,
        ~record?,
        ~sortBy?,
        ~source,
        ~translate?,
        ~translateChoice?,
        (),
      ),
    children,
  );
