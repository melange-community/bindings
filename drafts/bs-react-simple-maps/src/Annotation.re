[@bs.module "react-simple-maps"]
external annotationClass : ReasonReact.reactClass = "Annotation";

[@bs.deriving abstract]
type jsProps = {
  subject: (float, float),
  dx: int,
  dy: int,
  zoom: int,
  stroke: string,
  strokeWidth: float,
  style: ReactDOMRe.Style.t,
  markerEnd: string,
  curve: int,
};

let make =
    (
      ~subject=(0.0, 0.0),
      ~dx=30,
      ~dy=30,
      ~zoom=1,
      ~stroke="#000000",
      ~strokeWidth=1.0,
      ~style=ReactDOMRe.Style.make(),
      ~markerEnd="none",
      ~curve=0,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=annotationClass,
    ~props=
      jsProps(
        ~subject,
        ~dx,
        ~dy,
        ~zoom,
        ~stroke,
        ~strokeWidth,
        ~style,
        ~markerEnd,
        ~curve,
      ),
    children,
  );
