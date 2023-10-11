[@bs.module "react-admin"]
external fileInput : ReasonReact.reactClass = "FileInput";

[@bs.deriving abstract]
type props('a, 'b, 'c, 'd, 'e) = {
  [@bs.optional]
  accept: string,
  [@bs.optional]
  classes: 'a,
  [@bs.optional]
  className: string,
  [@bs.optional]
  disableClick: bool,
  [@bs.optional]
  input: 'b,
  [@bs.optional]
  isRequired: bool,
  [@bs.optional]
  label: string,
  [@bs.optional]
  labelMultiple: string,
  [@bs.optional]
  labelSingle: string,
  [@bs.optional]
  maxSize: int,
  [@bs.optional]
  minSize: int,
  [@bs.optional]
  multiple: bool,
  [@bs.optional]
  options: 'c,
  [@bs.optional]
  resource: string,
  [@bs.optional]
  source: string,
  [@bs.optional]
  translate: 'd,
  [@bs.optional]
  placeholder: 'e,
};

let make =
    (
      ~accept=?,
      ~classes=?,
      ~className=?,
      ~disableClick=?,
      ~input=?,
      ~isRequired=?,
      ~label=?,
      ~labelMultiple=?,
      ~labelSingle=?,
      ~maxSize=?,
      ~minSize=?,
      ~multiple=?,
      ~options=?,
      ~resource=?,
      ~source=?,
      ~translate=?,
      ~placeholder=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=fileInput,
    ~props=
      props(
        ~accept?,
        ~classes?,
        ~className?,
        ~disableClick?,
        ~input?,
        ~isRequired?,
        ~label?,
        ~labelMultiple?,
        ~labelSingle?,
        ~maxSize?,
        ~minSize?,
        ~multiple?,
        ~options?,
        ~resource?,
        ~source?,
        ~translate?,
        ~placeholder?,
        (),
      ),
    children,
  );
