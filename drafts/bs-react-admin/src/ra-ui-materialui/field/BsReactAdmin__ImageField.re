[@bs.module "react-admin"]
external imageField : ReasonReact.reactClass = "ImageField";

[@bs.obj]
external makeProps :
  (
    ~addLabel: bool=?,
    ~basePath: string=?,
    ~className: string=?,
    ~cellClassName: string=?,
    ~headerClassName: string=?,
    ~classes: 'a=?,
    ~record: 'b=?,
    ~sortBy: string=?,
    ~source: string,
    ~src: string=?,
    ~title: string=?,
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
      ~classes=?,
      ~record=?,
      ~sortBy=?,
      ~source,
      ~src=?,
      ~title=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=imageField,
    ~props=
      makeProps(
        ~addLabel?,
        ~basePath?,
        ~className?,
        ~cellClassName?,
        ~headerClassName?,
        ~classes?,
        ~record?,
        ~sortBy?,
        ~source,
        ~src?,
        ~title?,
        (),
      ),
    children,
  );
