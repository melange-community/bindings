[@bs.module "react-admin"]
external dateField : ReasonReact.reactClass = "DateField";

type locales = [ | `Str(string) | `List(list(string))];

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~label: string=?,
    ~locales: locales=?,
    ~options: 'a=?,
    ~record: 'b=?,
    ~showTime: bool=?,
    ~sortBy: string=?,
    ~source: string,
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
      ~label=?,
      ~locales=?,
      ~options=?,
      ~record=?,
      ~showTime=?,
      ~sortBy=?,
      ~source,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=dateField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~label?,
        ~locales?,
        ~options?,
        ~record?,
        ~showTime?,
        ~sortBy?,
        ~source,
        (),
      ),
    children,
  );
