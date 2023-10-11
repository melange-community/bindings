[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "Heading";

[@bs.obj]
external makeProps:
  (~size: int=?, ~fit: bool=?, ~lineHeight: float=?, unit) => _ =
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
      /* Heading specific props */
      ~size=?,
      ~fit=?,
      ~lineHeight=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      BaseProps.extendProps(
        makeProps(~size?, ~fit?, ~lineHeight?, ()),
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