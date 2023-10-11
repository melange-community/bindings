[@bs.module "spectacle"] external reactClass: ReasonReact.reactClass = "Deck";

[@bs.obj]
external makeProps:
  (
    ~controls: bool=?,
    ~contentHeight: int=?,
    ~contentWidth: int=?,
    /* TODO implement history, right now it's abstract*/
    ~history: 'a=?,
    ~progress: string=?,
    ~theme: Theme.theme=?,
    ~transition: array(Types.transition)=?,
    ~transitionDuration: int=?,
    ~autoplay: bool=?,
    ~autoplayDuration: int=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~controls=?,
      ~contentHeight=?,
      ~contentWidth=?,
      /* TODO implement history, right now it's abstract*/
      ~history=?,
      ~progress=?,
      ~theme=?,
      ~transition=?,
      ~transitionDuration=?,
      ~autoplay=?,
      ~autoplayDuration=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~controls?,
        ~contentHeight?,
        ~contentWidth?,
        ~history?,
        ~progress=?Js.Option.map(Types.mapProgressToJs, progress),
        ~theme?,
        ~transition=?Types.mapTransitionsToJs(transition),
        ~transitionDuration?,
        ~autoplay?,
        ~autoplayDuration?,
        (),
      ),
    children,
  );