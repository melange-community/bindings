[@bs.module "react-admin"]
external numberField : ReasonReact.reactClass = "NumberField";

type locales = [ | `Str(string) | `List(list(string))];

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~label: string=?,
    ~locales: locales=?,
    ~options: 'b=?,
    ~record: 'c=?,
    ~textAlign: string=?,
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
      ~classes=?,
      ~className=?,
      ~cellClassName=?,
      ~headerClassName=?,
      ~label=?,
      ~locales=?,
      ~options=?,
      ~record=?,
      ~textAlign=?,
      ~sortBy=?,
      ~source,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=numberField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~label?,
        ~locales?,
        ~options?,
        ~record?,
        ~textAlign?,
        ~sortBy?,
        ~source,
        (),
      ),
    children,
  );
