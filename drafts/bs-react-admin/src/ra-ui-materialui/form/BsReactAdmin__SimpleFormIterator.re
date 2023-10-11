[@bs.module "react-admin"]
external simpleFormIterator : ReasonReact.reactClass = "SimpleFormIterator";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f) = {
  [@bs.optional]
  defaultValue: 'a,
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  classes: 'b,
  [@bs.optional]
  className: string,
  [@bs.optional]
  fields: 'c,
  [@bs.optional]
  meta: 'd,
  [@bs.optional]
  record: 'e,
  [@bs.optional]
  source: string,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  translate: 'f,
  [@bs.optional]
  disableAdd: bool,
  [@bs.optional]
  disableRemove: bool,
};

let make =
    (
      ~defaultValue=?,
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~fields=?,
      ~meta=?,
      ~record=?,
      ~source=?,
      ~resource=?,
      ~translate=?,
      ~disableAdd=?,
      ~disableRemove=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=simpleFormIterator,
    ~props=
      props(
        ~defaultValue?,
        ~basePath?,
        ~classes?,
        ~className?,
        ~fields?,
        ~meta?,
        ~record?,
        ~source?,
        ~resource?,
        ~translate?,
        ~disableAdd?,
        ~disableRemove?,
        (),
      ),
    children,
  );
