[@bs.module "react-admin"] external create : ReasonReact.reactClass = "Create";

[@bs.obj]
external makeProps :
  (
    ~actions: 'a=?,
    ~className: string=?,
    ~resource: string=?,
    ~title: 'b=?,
    ~record: 'c=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~actions=?,
      ~className=?,
      ~resource=?,
      ~title=?,
      ~record=?,
      ~props,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=create,
    ~props=
      Js.Obj.assign(
        makeProps(~actions?, ~className?, ~resource?, ~title?, ~record?, ()),
        props,
      ),
    children,
  );
