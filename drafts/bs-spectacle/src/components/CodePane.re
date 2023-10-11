[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "CodePane";

[@bs.obj] external makeProps: (~lang: string, ~source: string, unit) => _ = "";

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
      /* CodePane specific props */
      ~lang,
      ~source,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      BaseProps.extendProps(
        makeProps(~lang, ~source, ()),
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