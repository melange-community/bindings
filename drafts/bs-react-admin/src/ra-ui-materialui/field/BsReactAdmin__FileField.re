[@bs.module "react-admin"]
external fileField : ReasonReact.reactClass = "FileField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~record: 'b=?,
    ~sortBy: string=?,
    ~source: string,
    ~src: string=?,
    ~title: string=?,
    ~target: string=?,
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
      ~record=?,
      ~sortBy=?,
      ~source,
      ~src=?,
      ~title=?,
      ~target=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=fileField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~record?,
        ~sortBy?,
        ~source,
        ~src?,
        ~title?,
        ~target?,
        (),
      ),
    children,
  );
