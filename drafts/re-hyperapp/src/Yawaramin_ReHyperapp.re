/** Lightweight bindings to
    {{:https://github.com/jorgebucaran/hyperapp}Hyperapp}. Hyperapp has a
    very tiny API surface and already has a well-defined architecture, so
    we just follow that.

    JSX support is implemented in the [ReactDOMRe] and [ReasonReact]
    modules. See the former for more details. Note that both of these
    modules {i should not} be used directly; their purpose is to provide
    JSX support. */

/** Virtual DOM elements. I.e. the things that get rendered by views. */
type vdom;

/** [empty()] allows creating empty JavaScript objects. These are useful
    for components that don't have any props or state and need JS objects
    that represent that. You can thus use `unit` as the [state] and
    [actions] types of components which don't have state or actions. */
[@bs.obj] external empty: unit => Js.t(unit) = "";

/** Helpers for executing actions. */
module Action = {
  /** [exec(action, func)] carries out the given Hyperapp [action] by
      feeding it to the [func] callback, and discards the result. Meant
      to be used in event handlers. */
  let exec(action, func) = action |> func |> ignore;

  /** [nullary] should be used with [exec] when the intent is to execute
      an action which doesn't take any payload. */
  let nullary(action) = action(.);
};

/** Helpers for creating re-hyperapp components. */
module Component = {
  /** Type of a custom component (i.e. a capitalized JSX element). This
      module type makes it possible to create higher-order components
      using OCaml functors, by declaring the functors to accept and
      return this type as input and output. Using this module type also
      enables the compiler to infer better types for state and actions,
      and avoids type errors caused by the value restriction on object
      types. I strongly recommend enforcing this module type as it will
      guide you through the steps of creating the module--i.e. adding the
      required types and values. See also [StaticComponent] for an easy
      way to create stateless (and actionaless) components.

      Strictly speaking, this exact type is not needed to support custom
      elements in JSX; at a minimum, the JSX transform just needs the
      last parameter ([children]), but usually you'll want to pass in
      state and actions objects, because the first two parameters are how
      Hyperapp threads state and actions through custom components.

      Note that you'll need to define the [state] and [actions] {i types}
      as OCaml object types, but instantiate the [state] and [actions]
      {i values} as BuckleScript objects. See
      [Yawaramin_ReHyperapp_Demo_Component_Main.re] for more details.

      See also [ReasonReact] for more details on capitalized components,
      and [Yawaramin_ReHyperapp_Demo_Component_Main.rei] for an example
      of how to enforce this module type on a file component. */
  module type Type = {
    type state;

    /** Needs to be an OCaml object type with all fields of type:

        [(. a) => {. "b": c, ...}]

        or

        [(. a) => (. Js.t(state)) => {. "b": c, ...}]

        It's important that the functions are explicitly curried, all
        take a payload (or more) as the first parameter, possibly take
        the current state as the second curried parameter, and return a
        JavaScript object type that is some subset of the state type.
        Hyperapp will merge the new part of the state into the existing
        state--no need for explicit immutable update syntax. */
    type actions;

    /** This can be any type but when you want to pass multiple values in
        the props, it's useful to make it a JavaScript object type
        because that can be independently defined and used interoperably
        across modules with no risk of cyclic dependencies. */
    type props;

    /** The {i initial} state of the component. */
    let state: Js.t(state);

    /** Initial actions of the component. */
    let actions: Js.t(actions);

    /** The parameter order in this definition is important–state and
        actions need to come first--because that's the order that
        Hyperapp uses. */
    let make: (
      ~state: Js.t(state)=?,
      ~actions: Js.t(actions)=?,
      ~props: props,
      array(vdom),
    ) => vdom;
  };

  /** Helper module for creating static components. Include this module
      in your component module for a head start. Static components here
      mean components without state or actions. After including, you'll
      only need to define the type of [props] and the [make] function. */
  module Static = {
    type state = unit;
    type actions = unit;

    let state = empty();
    let actions = empty();
  };
};

type element = Dom.element;

/** A Hyperapp instance that can be mounted on the page. */
type t;

/** [array(vdoms)] allows injecting an array of VDOM nodes into a
    position where only a single one is expected. Hyperapp VDOM allows
    using an array of elements anywhere a child element is expected, so
    we don't really need fragments as such. */
external array: array(vdom) => vdom = "%identity";

external float: float => vdom = "%identity";
external int: int => vdom = "%identity";

/** [null] allows injecting 'nothing' into the VDOM. */
[@bs.val] external null: vdom = "";

/** [string(s)] allows injecting a string into the VDOM. */
external string: string => vdom = "%identity";

// The following two helpers are mostly not needed thanks to JSX support.

/** [h(tagName, attrs, children)] creates a [vdom] element with tag name
    [tagName], attributes [attrs], and child elements [children]. This is
    mostly useful for creating attributes that JSX doesn't support, e.g.
    [<div data-foo="bar">]. */
[@bs.module "hyperapp"]
external h: (string, Js.t({..}), array(vdom)) => vdom = "";

/** [h_(tagName, children)] creates a [vdom] element like above but with
    no attributes. */
[@bs.module "hyperapp"]
external h_: (string, [@bs.as {json|{}|json}] _, array(vdom)) => vdom =
  "h";

/** [make(~state, ~actions, ~view, element)] creates a Hyperapp instance.
    This is the main entry point to using this binding. Most of the type
    safety of the overall app comes from the way this function is typed:
    the view function must work with the state (model) and actions. */
[@bs.module "hyperapp"] external make: (
  ~state: Js.t({..}) as 'state,
  ~actions: Js.t({..}) as 'actions,
  ~view: [@bs.uncurry] ('state, 'actions) => vdom,
  Js.nullable(element),
) => t = "app";

/** Helper to get the DOM element that the [app] function needs to mount
    the app onto the page. */
[@bs.scope "document"] [@bs.val]
external getElementById: string => Js.nullable(element) = "";
