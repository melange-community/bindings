/** Bindings for react-fela: https://github.com/rofrischmann/fela/tree/master/packages/react-fela */

type rule('props, 'style) = 'props => 'style;

type statelessComponent =
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless
  );

type baseElement = [ | `String(string) | `ReactClass(ReasonReact.reactClass)];

[@bs.module "react-fela"]
external createReactClass : rule('props, 'style) => ReasonReact.reactClass =
  "createComponent";

[@bs.module "react-fela"]
external createReactClassWithBaseElement :
  (
    rule('props, 'style),
    [@bs.unwrap] [ | `String(string) | `ReactClass(ReasonReact.reactClass)]
  ) =>
  ReasonReact.reactClass =
  "createComponent";

[@bs.module "react-fela"]
external createReactClassWithBaseElementAndPassThroughProps :
  (
    rule('props, 'style),
    [@bs.unwrap] [ | `String(string) | `ReactClass(ReasonReact.reactClass)],
    array(string)
  ) =>
  ReasonReact.reactClass =
  "createComponent";

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/createComponent.md */
let createComponent:
  (
    ~rule: rule('props, 'style),
    ~baseElement: baseElement=?,
    ~passThrough: array(string)=?,
    ~extend: 'props => 'newProps=?,
    ~props: 'props,
    'children
  ) =>
  statelessComponent;

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/createComponentWithProxy.md */
let createComponentWithProxy:
  (
    ~rule: rule('props, 'style),
    ~baseElement: baseElement=?,
    ~passThrough: array(string)=?,
    ~extend: 'props => 'newProps=?,
    ~props: 'props,
    'children
  ) =>
  statelessComponent;

type makeWithTheme('theme, 'children) =
  (~theme: 'theme, 'children) => statelessComponent;

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/withTheme.md */
let withTheme:
  (
    ~component: statelessComponent,
    ~make: makeWithTheme('theme, 'children),
    'children
  ) =>
  statelessComponent;

type connectRules('props, 'rules) = [
  | `Object('rules)
  | `Function('props => 'rules)
];

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/connect.md */
let connect:
  (
    ~rules: connectRules('props, 'rules),
    ~component: statelessComponent,
    ~make: (~styles: 'styles, 'children) => statelessComponent,
    ~props: 'props,
    'children
  ) =>
  statelessComponent;

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/Provider.md */
module Provider: {
  type renderer;
  let defaultRenderer: renderer;
  let make: (~renderer: renderer=?, 'children) => statelessComponent;
};

/** https://github.com/rofrischmann/fela/blob/master/packages/react-fela/docs/ThemeProvider.md */
module ThemeProvider: {
  let make:
    (
      ~theme: 'theme,
      ~overwrite: bool=?,
      ReasonReact.reactElement
    ) =>
    statelessComponent;
};
