[@bs.module "react-admin"]
external singleFieldList : ReasonReact.reactClass = "SingleFieldList";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd) = {
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  className: string,
  [@bs.optional]
  data: 'b,
  [@bs.optional]
  ids: list('c),
  [@bs.optional]
  linkType: 'd,
  [@bs.optional]
  resource: string,
};

let make =
    (
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~data=?,
      ~ids=?,
      ~linkType=?,
      ~resource=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=singleFieldList,
    ~props=
      props(
        ~basePath?,
        ~classes?,
        ~className?,
        ~data?,
        ~ids?,
        ~linkType?,
        ~resource?,
        (),
      ),
    children,
  );
