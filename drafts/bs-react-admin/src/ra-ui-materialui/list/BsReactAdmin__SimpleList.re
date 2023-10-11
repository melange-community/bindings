[@bs.module "react-admin"]
external simpleList : ReasonReact.reactClass = "SimpleList";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i, 'j, 'k, 'l, 'm) = {
  [@bs.optional]
  basePath: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  className: string,
  [@bs.optional]
  data: 'b,
  [@bs.optional]
  hasBulkActions: bool,
  [@bs.optional]
  ids: list('c),
  [@bs.optional]
  leftAvatar: 'd,
  [@bs.optional]
  leftIcon: 'e,
  [@bs.optional]
  linkType: 'f,
  [@bs.optional]
  onToggleItem: 'g,
  [@bs.optional]
  primaryText: 'h,
  [@bs.optional]
  rightAvatar: 'i,
  [@bs.optional]
  rightIcon: 'j,
  [@bs.optional]
  secondaryText: 'k,
  [@bs.optional]
  selectedIds: list('l),
  [@bs.optional]
  tertiaryText: 'm,
};

let make =
    (
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~data=?,
      ~hasBulkActions=?,
      ~ids=?,
      ~leftAvatar=?,
      ~leftIcon=?,
      ~linkType=?,
      ~onToggleItem=?,
      ~primaryText=?,
      ~rightAvatar=?,
      ~rightIcon=?,
      ~secondaryText=?,
      ~selectedIds=?,
      ~tertiaryText=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=simpleList,
    ~props=
      props(
        ~basePath?,
        ~classes?,
        ~className?,
        ~data?,
        ~hasBulkActions?,
        ~ids?,
        ~leftAvatar?,
        ~leftIcon?,
        ~linkType?,
        ~onToggleItem?,
        ~primaryText?,
        ~rightAvatar?,
        ~rightIcon?,
        ~secondaryText?,
        ~selectedIds?,
        ~tertiaryText?,
        (),
      ),
    children,
  );
