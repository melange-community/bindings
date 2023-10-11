module Core: {
  type t;

  [@bs.deriving abstract]
  type options = {
    [@bs.optional] hydrate: array(Dom.element),
    [@bs.optional] container: Dom.element,
    [@bs.optional] prefix: string
  };
};

module Client: {
  let make:
    (~options: Core.options=?, unit) =>
    Core.t;
};

module React: {
  type statelessComponent =
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );

  type rule('props, 'style) = 'props => 'style;

  type base = [ | `String(string) | `ReactClass(ReasonReact.reactClass)];

  let makeStyledClass:
    (~base: base, ~rule: rule('props, 'style)) => ReasonReact.reactClass;

  let makeStyled:
    (
      ~base: base,
      ~rule: rule('props, 'style),
      ~props: 'props,
      'children
    ) =>
    statelessComponent;

  let makeStyledComponent:
    (
      ~rule: rule('props, 'style),
      ~component: statelessComponent,
      ~make: (~props: 'props, 'children) => statelessComponent,
      ~props: 'props,
      'children
    ) =>
    statelessComponent;

  module Provider: {
    let make: (~value: Core.t=?, 'children) => statelessComponent;
  };
};

