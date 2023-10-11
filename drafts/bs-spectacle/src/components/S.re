[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "S";

[@bs.obj] external makeProps: (~_type: string=?, unit) => _ = "";

[@bs.deriving jsConverter]
type sType = [ | `strikethrough | `underline | `bold | `italic];

let mapSTypeToJs = (. sType) => sTypeToJs(sType);

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
      /* S specific props */
      ~type_: option(sType)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      BaseProps.extendProps(
        makeProps(~_type=?Js.Option.map(mapSTypeToJs, type_), ()),
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