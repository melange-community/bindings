[@bs.module "react-admin"] external show : ReasonReact.reactClass = "Show";

[@bs.obj]
external makeProps :
  (
    ~actions: 'a=?,
    ~className: string=?,
    ~id: 'b=?,
    ~resource: 'c=?,
    ~title: 'd=?,
    unit
  ) =>
  _ =
  "";

let make =
    (~actions=?, ~className=?, ~id=?, ~resource=?, ~title=?, ~props, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=show,
    ~props=
      Js.Obj.assign(
        makeProps(~actions?, ~className?, ~id?, ~resource?, ~title?, ()),
        props,
      ),
    children,
  );
