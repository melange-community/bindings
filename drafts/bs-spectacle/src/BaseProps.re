[@bs.obj]
external makeBaseProps:
  (
    ~italic: bool=?,
    ~bold: bool=?,
    ~caps: bool=?,
    ~margin: string=?,
    ~padding: string=?,
    ~textColor: string=?,
    ~textSize: string=?,
    ~textAlign: string=?,
    ~textFont: string=?,
    ~bgColor: string=?,
    ~bgImage: string=?,
    ~bgSize: string=?,
    ~bgPosition: string=?,
    ~bgRepeat: string=?,
    ~bgDarken: float=?,
    ~overflow: string=?,
    ~height: string=?,
    unit
  ) =>
  _ =
  "";

let extendProps =
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
      moreProps,
    ) =>
  Object.assign(
    Js.Obj.empty(),
    makeBaseProps(
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
      (),
    ),
    moreProps,
  );

module type BaseComponent = {let reactClass: ReasonReact.reactClass;};

module MakeBaseComponent = (BaseComponent: BaseComponent) => {
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
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=BaseComponent.reactClass,
      ~props=
        makeBaseProps(
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
          (),
        ),
      children,
    );
};