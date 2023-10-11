[@bs.module "react-admin"] external edit : ReasonReact.reactClass = "Edit";

[@bs.obj]
external makeProps :
  (
    ~actions: 'a=?,
    ~className: string=?,
    ~resource: string=?,
    ~title: 'b=?,
    ~id: 'a=?,
    unit
  ) =>
  _ =
  "";

let make =
    (~actions=?, ~className=?, ~resource=?, ~title=?, ~id=?, ~props, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=edit,
    ~props=
      Js.Obj.assign(
        makeProps(~actions?, ~className?, ~resource?, ~title?, ~id?, ()),
        props,
      ),
    children,
  );
