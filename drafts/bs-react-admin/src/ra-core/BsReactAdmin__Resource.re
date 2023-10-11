[@bs.module "react-admin"]
external resource : ReasonReact.reactClass = "Resource";

type matchType('a) =
  Js.t(
    {
      .
      "isExact": bool,
      "params": 'a,
      "path": string,
      "url": string,
    },
  );

[@bs.obj]
external makeProps :
  (
    ~context: [@bs.string] [ | `route | `registration]=?,
    ~match: matchType('a)=?,
    ~name: string,
    ~list: 'b=?,
    ~create: 'c=?,
    ~edit: 'd=?,
    ~show: 'e=?,
    ~icon: 'f=?,
    ~options: 'g=?,
    ~registerResource: 'h=?,
    ~unregisterResource: 'i=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~context=?,
      ~match=?,
      ~name,
      ~list=?,
      ~create=?,
      ~edit=?,
      ~show=?,
      ~icon=?,
      ~options=?,
      ~registerResource=?,
      ~unregisterResource=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=resource,
    ~props=
      makeProps(
        ~context?,
        ~match?,
        ~name,
        ~list?,
        ~create?,
        ~edit?,
        ~show?,
        ~icon?,
        ~options?,
        ~registerResource?,
        ~unregisterResource?,
        (),
      ),
    children,
  );
