[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "List";

[@bs.obj]
external makeProps:
  (
    ~ordered: bool=?,
    ~reversed: bool=?,
    ~start: int=?,
    ~_type: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~italic=?,
      ~bold=?,
      ~caps=?,
      ~margin=?,
      ~padding=?,
      ~textColor=?,
      ~textSize=?,
      ~textAlign=?,
      ~textFont=?,
      ~bgColor=?,
      ~bgImage=?,
      ~bgSize=?,
      ~bgPosition=?,
      ~bgRepeat=?,
      ~bgDarken=?,
      ~overflow=?,
      ~height=?,
      /* List specific props */
      ~ordered=?,
      ~reversed=?,
      ~start=?,
      ~type_=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      BaseProps.extendProps(
        makeProps(~ordered?, ~reversed?, ~start?, ~_type=?type_, ()),
        ~italic?,
        ~bold?,
        ~caps?,
        ~margin?,
        ~padding?,
        ~textColor?,
        ~textSize?,
        ~textAlign?,
        ~textFont?,
        ~bgColor?,
        ~bgImage?,
        ~bgSize?,
        ~bgPosition?,
        ~bgRepeat?,
        ~bgDarken?,
        ~overflow?,
        ~height?,
      ),
    children,
  );