[@bs.deriving abstract]
type domain('x, 'y) = {
  [@bs.optional]
  x: array('x),
  [@bs.optional]
  y: array('y),
};

[@bs.deriving abstract]
type domainPadding = {
  [@bs.optional]
  x: array(int),
  [@bs.optional]
  y: array(int),
};

[@bs.deriving abstract]
type singleQuadrantDomainPadding = {
  [@bs.optional]
  x: bool,
  [@bs.optional]
  y: bool,
};

[@bs.deriving abstract]
type padding = {
  [@bs.optional]
  top: int,
  [@bs.optional]
  bottom: int,
  [@bs.optional]
  left: int,
  [@bs.optional]
  right: int,
};

module Theme = {
  type t;

  [@bs.module "victory"] [@bs.scope "VictoryTheme"] external material: t = "";
};

module Container = {
  [@bs.module "victory"]
  external victoryContainer: ReasonReact.reactClass = "VictoryContainer";

  [@bs.deriving abstract]
  type jsProps('a) = {
    [@bs.optional]
    height: int,
    [@bs.optional]
    width: int,
    [@bs.optional]
    responsive: bool,
    [@bs.optional]
    style: 'a,
  };

  let make = (~height=?, ~width=?, ~responsive=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryContainer,
      ~props=jsProps(~height?, ~width?, ~responsive?, ~style?, ()),
      children,
    );
};

module Chart = {
  [@bs.module "victory"]
  external victoryChart: ReasonReact.reactClass = "VictoryChart";

  [@bs.deriving abstract]
  type jsProps('x, 'y) = {
    [@bs.optional]
    polar: bool,
    [@bs.optional]
    domainPadding,
    [@bs.optional]
    domain: domain('x, 'y),
    [@bs.optional]
    innerRadius: int,
    [@bs.optional]
    theme: Theme.t,
    [@bs.optional]
    startAngle: int,
    [@bs.optional]
    endAngle: int,
    [@bs.optional]
    standalone: bool,
    [@bs.optional]
    height: int,
    [@bs.optional]
    width: int,
    [@bs.optional]
    padding,
    [@bs.optional]
    disableContainerEvents: bool,
  };

  let make =
      (
        ~domainPadding=?,
        ~domain=?,
        ~polar=?,
        ~innerRadius=?,
        ~theme=?,
        ~startAngle=?,
        ~endAngle=?,
        ~standalone=?,
        ~height=?,
        ~width=?,
        ~padding=?,
        ~disableContainerEvents=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryChart,
      ~props=
        jsProps(
          ~polar?,
          ~domainPadding?,
          ~domain?,
          ~innerRadius?,
          ~theme?,
          ~startAngle?,
          ~endAngle?,
          ~standalone?,
          ~height?,
          ~width?,
          ~padding?,
          ~disableContainerEvents?,
          (),
        ),
      children,
    );
};

module Group = {
  [@bs.module "victory"]
  external victoryGroup: ReasonReact.reactClass = "VictoryGroup";

  [@bs.deriving abstract]
  type jsProps('style) = {
    [@bs.optional]
    colorScale: array(string),
    [@bs.optional]
    offset: int,
    [@bs.optional]
    horizontal: bool,
    [@bs.optional]
    range: array(int),
    [@bs.optional]
    style: 'style,
    [@bs.optional]
    singleQuadrantDomainPadding,
    [@bs.optional]
    standalone: bool,
  };

  let make =
      (
        ~offset=?,
        ~horizontal=?,
        ~colorScale=?,
        ~range=?,
        ~style=?,
        ~singleQuadrantDomainPadding=?,
        ~standalone=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryGroup,
      ~props=
        jsProps(
          ~offset?,
          ~horizontal?,
          ~colorScale?,
          ~range?,
          ~style?,
          ~singleQuadrantDomainPadding?,
          ~standalone?,
          (),
        ),
      children,
    );
};

module Pie = {
  [@bs.module "victory"]
  external victoryPie: ReasonReact.reactClass = "VictoryPie";

  [@bs.deriving abstract]
  type jsProps('a, 'b) = {
    data: array('a),
    [@bs.optional]
    padding,
    [@bs.optional]
    colorScale: array(string),
    [@bs.optional]
    labels: 'a => string,
    [@bs.optional]
    labelRadius: int,
    [@bs.optional]
    style: 'b,
    [@bs.optional]
    height: int,
    [@bs.optional]
    width: int,
    [@bs.optional]
    standalone: bool,
  };

  let make =
      (
        ~data,
        ~colorScale=?,
        ~labels=?,
        ~labelRadius=?,
        ~style=?,
        ~height=?,
        ~width=?,
        ~standalone=?,
        ~padding=?,
        _children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryPie,
      ~props=
        jsProps(
          ~data,
          ~padding?,
          ~colorScale?,
          ~labels?,
          ~labelRadius?,
          ~style?,
          ~height?,
          ~width?,
          ~standalone?,
          (),
        ),
      [||],
    );
};

module Bar = {
  [@bs.module "victory"]
  external victoryBar: ReasonReact.reactClass = "VictoryBar";

  [@bs.deriving abstract]
  type jsProps('a, 'style) = {
    data: array('a),
    [@bs.optional]
    padding,
    [@bs.optional]
    style: 'style,
  };

  let make = (~data, ~padding=?, ~style=?, _children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryBar,
      ~props=jsProps(~data, ~padding?, ~style?, ()),
      [||],
    );
};

module Axis = {
  [@bs.module "victory"]
  external victoryAxis: ReasonReact.reactClass = "VictoryAxis";

  [@bs.deriving abstract]
  type jsProps('a, 'b, 'style) = {
    [@bs.optional]
    dependentAxis: bool,
    [@bs.optional]
    tickValues: array('a),
    [@bs.optional]
    tickFormat: 'b,
    [@bs.optional]
    style: 'style,
    [@bs.optional]
    label: string,
    [@bs.optional]
    standalone: bool,
  };

  let make =
      (
        ~dependentAxis=?,
        ~tickValues=?,
        ~tickFormat=?,
        ~style=?,
        ~label=?,
        ~standalone=?,
        _children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryAxis,
      ~props=
        jsProps(
          ~dependentAxis?,
          ~tickValues?,
          ~tickFormat?,
          ~style?,
          ~label?,
          ~standalone?,
          (),
        ),
      [||],
    );
};

module Legend = {
  [@bs.module "victory"]
  external victoryLegend: ReasonReact.reactClass = "VictoryLegend";

  [@bs.deriving abstract]
  type jsProps('a, 'style) = {
    data: array('a),
    [@bs.optional]
    title: string,
    [@bs.optional]
    width: int,
    [@bs.optional]
    orientation: string,
    [@bs.optional]
    standalone: bool,
    [@bs.optional]
    itemsPerRow: int,
    [@bs.optional]
    centerTitle: bool,
    [@bs.optional]
    colorScale: array(string),
    [@bs.optional]
    borderPadding: padding,
    [@bs.optional]
    gutter: int,
    [@bs.optional]
    symbolSpacer: int,
    [@bs.optional]
    style: 'style,
  };

  let make =
      (
        ~data,
        ~title=?,
        ~width=?,
        ~orientation=?,
        ~standalone=?,
        ~itemsPerRow=?,
        ~centerTitle=?,
        ~colorScale=?,
        ~borderPadding=?,
        ~gutter=?,
        ~symbolSpacer=?,
        ~style=?,
        _children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=victoryLegend,
      ~props=
        jsProps(
          ~data,
          ~title?,
          ~width?,
          ~orientation?,
          ~standalone?,
          ~itemsPerRow?,
          ~centerTitle?,
          ~colorScale?,
          ~borderPadding?,
          ~gutter?,
          ~symbolSpacer?,
          ~style?,
          (),
        ),
      [||],
    );
};
