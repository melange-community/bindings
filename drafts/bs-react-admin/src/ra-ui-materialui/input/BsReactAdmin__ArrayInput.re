[@bs.module "react-admin"]
external arrayInput : ReasonReact.reactClass = "ArrayInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd) = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  defaultValue: 'a,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  resource: string,
  source: string,
  [@bs.optional]
  record: 'b,
  [@bs.optional]
  options: 'c,
  [@bs.optional]
  validate: 'd,
};

let make =
    (
      ~className=?,
      ~defaultValue=?,
      ~isRequired=?,
      ~label=?,
      ~resource=?,
      ~source,
      ~record=?,
      ~options=?,
      ~validate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=arrayInput,
    ~props=
      props(
        ~className?,
        ~defaultValue?,
        ~isRequired?,
        ~label?,
        ~resource?,
        ~source,
        ~record?,
        ~options?,
        ~validate?,
        (),
      ),
    children,
  );
