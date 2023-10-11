[@bs.module "react-admin"]
external chipField : ReasonReact.reactClass = "ChipField";

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~classes: 'a=?,
    ~elStyle: 'b=?,
    ~sortBy: string=?,
    ~source: string,
    ~record: 'c=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~className=?,
      ~classes=?,
      ~elStyle=?,
      ~sortBy=?,
      ~source,
      ~record=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=chipField,
    ~props=
      makeProps(
        ~className?,
        ~classes?,
        ~elStyle?,
        ~sortBy?,
        ~source,
        ~record?,
        (),
      ),
    children,
  );
