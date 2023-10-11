[@bs.module "react-admin"] external list_ : ReasonReact.reactClass = "List";

type sort =
  Js.t(
    {
      .
      "field": string,
      "order": string,
    },
  );

[@bs.obj]
external makeProps :
  (
    ~actions: 'a=?,
    ~bulkActions: 'b=?,
    ~classes: 'c=?,
    ~className: string=?,
    ~filter: 'd=?,
    ~filterDefaultValues: 'e=?,
    ~filters: 'f=?,
    ~pagination: 'g=?,
    ~perPage: int=?,
    ~sort: sort=?,
    ~title: 'h=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~actions=?,
      ~bulkActions=?,
      ~classes=?,
      ~className=?,
      ~filter=?,
      ~filterDefaultValues=?,
      ~filters=?,
      ~pagination=?,
      ~perPage=?,
      ~sort=?,
      ~title=?,
      ~props,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=list_,
    ~props=
      Js.Obj.assign(
        makeProps(
          ~actions?,
          ~bulkActions?,
          ~classes?,
          ~className?,
          ~filter?,
          ~filterDefaultValues?,
          ~filters?,
          ~pagination?,
          ~perPage?,
          ~sort?,
          ~title?,
          (),
        ),
        props,
      ),
    children,
  );
