type projectionT;

[@bs.module "react-simple-maps"]
external geographyClass : ReasonReact.reactClass = "Geography";

[@bs.deriving abstract]
type geography = {id: string};

module Props = {
  [@bs.deriving abstract]
  type jsProps = {
    cacheId: Js.undefined(int),
    precision: float,
    round: bool,
    geography: Js.undefined(geography),
    tabable: Js.undefined(bool),
    projection: projectionT,
    style: Types.style,
  };
};

let fromOption = Js.Undefined.fromOption;

let make =
    (
      ~cacheId=?,
      ~precision=0.1,
      ~round=false,
      ~geography=?,
      ~projection,
      ~tabable=?,
      ~style: Types.style=Types.style(),
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyClass,
    ~props=
      Props.jsProps(
        ~cacheId=fromOption(cacheId),
        ~precision,
        ~round,
        ~geography=fromOption(geography),
        ~projection,
        ~tabable=fromOption(tabable),
        ~style,
      ),
    children,
  );
