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

let createComponent =
    (~rule, ~baseElement=?, ~passThrough=?, ~extend=?, ~props, children) => {
  let reactClass =
    switch (passThrough) {
    | Some(pt) =>
      let be =
        switch (baseElement) {
        | Some(be) => be
        | None => `String("div")
        };
      createReactClassWithBaseElementAndPassThroughProps(rule, be, pt);
    | None =>
      switch (baseElement) {
      | Some(be) => createReactClassWithBaseElement(rule, be)
      | None => createReactClass(rule)
      }
    };
  switch (extend) {
  | None =>
    ReasonReact.wrapJsForReason(~reactClass, ~props, children);
  | Some(f) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=f(props), children);
  };
};

[@bs.module "react-fela"]
external createReactClassWithProxy :
  rule('props, 'style) => ReasonReact.reactClass =
  "createComponentWithProxy";

[@bs.module "react-fela"]
external createReactClassWithProxyAndBaseElement :
  (
    rule('props, 'style),
    [@bs.unwrap] [ | `String(string) | `ReactClass(ReasonReact.reactClass)]
  ) =>
  ReasonReact.reactClass =
  "createComponentWithProxy";

[@bs.module "react-fela"]
external createReactClassWithProxyBaseElementAndPassThroughProps :
  (
    rule('props, 'style),
    [@bs.unwrap] [ | `String(string) | `ReactClass(ReasonReact.reactClass)],
    array(string)
  ) =>
  ReasonReact.reactClass =
  "createComponentWithProxy";

let createComponentWithProxy =
    (~rule, ~baseElement=?, ~passThrough=?, ~extend=?, ~props, children) => {
  let reactClass =
    switch (passThrough) {
    | Some(pt) =>
      let be =
        switch (baseElement) {
        | Some(be) => be
        | None => `String("div")
        };
      createReactClassWithProxyBaseElementAndPassThroughProps(rule, be, pt);
    | None =>
      switch (baseElement) {
      | Some(be) => createReactClassWithProxyAndBaseElement(rule, be)
      | None => createReactClassWithProxy(rule)
      }
    };
  switch (extend) {
  | None =>
    ReasonReact.wrapJsForReason(~reactClass, ~props, children);
  | Some(f) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=f(props), children);
  };
};

[@bs.module "react-fela"]
external withTheme_ :
  (ReasonReact.reactClass, Js.nullable(string)) => ReasonReact.reactClass =
  "withTheme";

type makeWithTheme('theme, 'children) =
  (~theme: 'theme, 'children) => statelessComponent;

let withTheme = (~component, ~make, children) => {
  let reactClass =
    ReasonReact.wrapReasonForJs(~component, jsProps =>
      make(~theme=jsProps##theme, children)
    );
  let reactClass = withTheme_(reactClass, Js.Nullable.undefined);
  ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

type reactClassFactory = ReasonReact.reactClass => ReasonReact.reactClass;

[@bs.module "react-fela"]
external connect_ : 'rules => reactClassFactory = "connect";

type connectRules('props, 'rules) = [
  | `Object('rules)
  | `Function('props => 'rules)
];

let connect = (~rules, ~component, ~make, ~props, children) => {
  let reactClass =
    ReasonReact.wrapReasonForJs(~component, jsProps =>
      make(~styles=jsProps##styles, children)
    );
  let makeReactClass =
    switch (rules) {
    | `Object(o) => connect_(o)
    | `Function(f) => connect_(f)
    };
  let reactClass = makeReactClass(reactClass);
  ReasonReact.wrapJsForReason(~reactClass, ~props, children);
};

module Provider = {
  type renderer;
  [@bs.module "react-fela"]
  external provider : ReasonReact.reactClass = "Provider";
  [@bs.module "fela"] external createRenderer : unit => renderer = "";
  let defaultRenderer = createRenderer();
  let make = (~renderer=defaultRenderer, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=provider,
      ~props={"renderer": renderer},
      children
    );
};

module ThemeProvider = {
  [@bs.module "react-fela"]
  external reactClass : ReasonReact.reactClass = "ThemeProvider";
  let make = (~theme, ~overwrite=false, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "theme": theme,
        "overwrite": overwrite
      },
      children
    );
};
