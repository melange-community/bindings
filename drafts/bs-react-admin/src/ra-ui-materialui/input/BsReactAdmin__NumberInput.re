[@bs.module "react-admin"]
external numberInput : ReasonReact.reactClass = "NumberInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) = {
  [@bs.optional]
  className: string,
  [@bs.optional]
  input: 'a,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  meta: 'b,
  [@bs.optional]
  name: string,
  [@bs.optional]
  onBlur: 'c,
  [@bs.optional]
  onChange: 'd,
  [@bs.optional]
  onFocus: 'e,
  [@bs.optional]
  options: 'f,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  step: 'g,
  [@bs.optional]
  validate: 'h,
};

let make =
    (
      ~className=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~meta=?,
      ~name=?,
      ~onBlur=?,
      ~onChange=?,
      ~onFocus=?,
      ~options=?,
      ~resource=?,
      ~source=?,
      ~step=?,
      ~validate=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=numberInput,
    ~props=
      props(
        ~className?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~meta?,
        ~name?,
        ~onBlur?,
        ~onChange?,
        ~onFocus?,
        ~options?,
        ~resource?,
        ~source?,
        ~step?,
        ~validate?,
        (),
      ),
    children,
  );
