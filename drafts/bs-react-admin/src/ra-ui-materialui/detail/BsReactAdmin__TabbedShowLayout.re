[@bs.module "react-admin"]
external tabbedShowLayout : ReasonReact.reactClass = "TabbedShowLayout";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e) = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  location: 'b,
  [@bs.optional] [@bs.as "match"]
  match_: 'c,
  [@bs.optional]
  record: 'd,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  value: int,
  [@bs.optional]
  version: int,
  [@bs.optional]
  translate: 'e,
};

let make =
    (
      ~className=?,
      ~classes=?,
      ~location=?,
      ~match_=?,
      ~record=?,
      ~resource=?,
      ~basePath=?,
      ~value=?,
      ~version=?,
      ~translate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=tabbedShowLayout,
    ~props=
      props(
        ~className?,
        ~classes?,
        ~location?,
        ~match_?,
        ~record?,
        ~resource?,
        ~basePath?,
        ~value?,
        ~version?,
        ~translate?,
        (),
      ),
    children,
  );
