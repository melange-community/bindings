[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "GoToAction";

type goToSlideAction = string => unit;

[@bs.obj]
external makeProps:
  (
    ~slide: int=?,
    ~render: goToSlideAction => ReasonReact.reactElement=?,
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
      /* GoToAction specific props */
      ~slide=?,
      ~render=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      BaseProps.extendProps(
        makeProps(~slide?, ~render?, ()),
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