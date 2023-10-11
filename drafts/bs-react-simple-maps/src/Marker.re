open Types;

[@bs.module "react-simple-maps"]
external markerClass : ReasonReact.reactClass = "Marker";

[@bs.deriving abstract]
type markerT = {coordinates: Types.coords};

[@bs.deriving abstract]
type jsProps = {
  marker: markerT,
  tabable: bool,
  style: Types.style,
  preserveMarkerAspect: bool,
};

let make =
    (
      ~coordinates: Types.coords,
      ~tabable=true,
      ~style: Types.style=Types.style(),
      ~preserveMarkerAspect=true,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerClass,
    ~props=
      jsProps(
        ~marker=markerT(~coordinates),
        ~tabable,
        ~style,
        ~preserveMarkerAspect,
      ),
    children,
  );
