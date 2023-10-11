[@bs.module "react-simple-maps"]
external graticuleClass : ReasonReact.reactClass = "Graticule";

[@bs.deriving abstract]
type jsProps = {
  step: (float, float),
  round: bool,
  precision: float,
  outline: bool,
  stroke: string,
  fill: string,
  style: ReactDOMRe.Style.t,
  disableOptimization: bool,
  globe: bool,
};

let make =
    (
      ~step=(10.0, 10.0),
      ~round=true,
      ~precision=0.1,
      ~outline=true,
      ~stroke="#dddddd",
      ~fill="transparent",
      ~style=ReactDOMRe.Style.make(~pointerEvents="none", ()),
      ~disableOptimization=true,
      ~globe=false,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=graticuleClass,
    ~props=
      jsProps(
        ~step,
        ~round,
        ~precision,
        ~outline,
        ~stroke,
        ~fill,
        ~style,
        ~disableOptimization,
        ~globe,
      ),
    children,
  );
