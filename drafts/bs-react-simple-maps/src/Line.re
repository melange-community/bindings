[@bs.module "react-simple-maps"]
external lineClass : ReasonReact.reactClass = "Line";

[@bs.deriving abstract]
type coordinatesT = {
  start: Types.coords,
  [@bs.as "end"]
  end_: Types.coords,
};

[@bs.deriving abstract]
type lineT = {coordinates: coordinatesT};

/* TODO: buildPath */
[@bs.deriving abstract]
type jsProps = {
  line: lineT,
  tabable: bool,
  style: Types.style,
  preserveMarkerAspect: bool,
};

let make =
    (
      ~start: Types.coords,
      ~stop: Types.coords,
      ~tabable=true,
      ~style=Types.style(),
      ~preserveMarkerAspect=true,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=lineClass,
    ~props=
      jsProps(
        ~line=lineT(~coordinates=coordinatesT(~start, ~end_=stop)),
        ~tabable,
        ~style,
        ~preserveMarkerAspect,
      ),
    children,
  );
