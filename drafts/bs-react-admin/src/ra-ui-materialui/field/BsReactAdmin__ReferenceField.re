[@bs.module "react-admin"]
external referenceField : ReasonReact.reactClass = "ReferenceField";

type linkType = [ | `Str(string) | `Bool(bool)];

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~allowEmpty: bool=?,
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~label: string=?,
    ~record: 'b=?,
    ~reference: string=?,
    ~resource: string=?,
    ~sortBy: string=?,
    ~source: string,
    ~translateChoice: 'c=?,
    ~linkType: linkType=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~addLabel=?,
      ~allowEmpty=?,
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~cellClassName=?,
      ~headerClassName=?,
      ~label=?,
      ~record=?,
      ~reference=?,
      ~resource=?,
      ~sortBy=?,
      ~source,
      ~translateChoice=?,
      ~linkType=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=referenceField,
    ~props=
      makeProps(
        ~addLabel?,
        ~allowEmpty?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~label?,
        ~record?,
        ~reference?,
        ~resource?,
        ~sortBy?,
        ~source,
        ~translateChoice?,
        ~linkType?,
        (),
      ),
    children,
  );
