module Core = {
  type t;

  [@bs.deriving abstract]
  type options = {
    [@bs.optional] hydrate: array(Dom.element),
    [@bs.optional] container: Dom.element,
    [@bs.optional] prefix: string
  };
};

module Client = {
  [@bs.module "styletron-engine-atomic"] [@bs.new]
  external createInstance :
    Js.nullable(Core.options) => Core.t =
    "Client";

  let make = (~options=?, ()) =>
    createInstance(Js.Nullable.fromOption(options));
};

module React = {
  type statelessComponent =
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );

  type rule('props, 'style) = 'props => 'style;

  type base = [ | `String(string) | `ReactClass(ReasonReact.reactClass)];

  [@bs.module "styletron-react"] [@bs.val]
  external styled :
    (
      [@bs.unwrap] [ | `String(string) | `ReactClass(ReasonReact.reactClass)],
      rule('props, 'style)
    ) =>
    ReasonReact.reactClass =
    "";

  let makeStyledClass = (~base, ~rule) => styled(base, rule);

  let makeStyled = (~base, ~rule, ~props, children) => {
    let reactClass = styled(base, rule);
    ReasonReact.wrapJsForReason(~reactClass, ~props, children);
  };

  let makeStyledComponent = (~rule, ~component, ~make, ~props, children) => {
    let reactClass =
      ReasonReact.wrapReasonForJs(~component, jsProps =>
        make(~props=jsProps, children)
      );
    let styledClass = styled(`ReactClass(reactClass), rule);
    ReasonReact.wrapJsForReason(
      ~reactClass=styledClass,
      ~props,
      children
    );
  };

  module Provider = {
    [@bs.module "styletron-react"]
    external reactClass : ReasonReact.reactClass = "Provider";

    [@bs.deriving abstract]
    type props = {
      value: Core.t
    };

    let make = (~value=Client.make(), children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=props(~value),
        children
      );
  };
};

