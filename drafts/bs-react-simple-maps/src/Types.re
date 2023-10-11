[@bs.deriving abstract]
type style = {
  [@bs.optional]
  default: ReactDOMRe.Style.t,
  [@bs.optional]
  hover: ReactDOMRe.Style.t,
  [@bs.optional]
  pressed: ReactDOMRe.Style.t,
};

type coords = (float, float);
