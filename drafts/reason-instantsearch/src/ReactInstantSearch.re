module InstantSearch = {
  [@bs.module "react-instantsearch/es/dom"]
  external instantSearch : ReasonReact.reactClass = "InstantSearch";

  [@bs.deriving abstract]
  type jsProps = {
    appId: string,
    apiKey: string,
    indexName: string,
  };

  let make = (~appId, ~apiKey, ~indexName, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=instantSearch,
      ~props=jsProps(~appId, ~apiKey, ~indexName),
      children,
    );
};

module SearchBox = {
  [@bs.module "react-instantsearch/es/dom"]
  external searchBox : ReasonReact.reactClass = "SearchBox";

  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=searchBox, ~props=(), children);
};

module Hits = {
  [@bs.module "react-instantsearch/es/dom"]
  external hits : ReasonReact.reactClass = "Hits";

  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=hits,
      /* hmm, how do I give `hitComponent` */
      ~props=(),
      children,
    );
};

module Pagination = {
  [@bs.module "react-instantsearch/es/dom"]
  external pagination : ReasonReact.reactClass = "Pagination";

  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=pagination, ~props=(), children);
};

module Configure = {
  [@bs.module "react-instantsearch/es/dom"]
  external configure : ReasonReact.reactClass = "Configure";
  [@bs.deriving abstract]
  type jsProps = {
    [@bs.optional]
    attributesToRetrieve: array(string) /* please make me actually optional */
  };

  let make = (~attributesToRetrieve, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=configure,
      ~props=jsProps(~attributesToRetrieve),
      children,
    );
};

module RefinementList = {
  [@bs.module "react-instantsearch/es/dom"]
  external refinementList : ReasonReact.reactClass = "RefinementList";
  [@bs.deriving abstract]
  type jsProps = {
    attribute: string,
    searchable: bool,
  };

  let make = (~attribute, ~searchable, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=refinementList,
      ~props=jsProps(~attribute, ~searchable),
      children,
    );
};

/*

 type hoc = ReasonReact.reactClass => ReasonReact.reactClass;

 module type CreateWithStateParams = {
   /* This is the secret sauce ingredient, with it the users can pass whatever state they want */
   type state;
   let defaultValue: state;
 };

 module CreateWithState = (Params: CreateWithStateParams) => {
   [@bs.module "react-instantsearch"]
   external withState : (string, string, Params.state) => hoc = "withState";

   type setState = Params.state => unit;

   type children =
     (~setState: setState, ~state: Params.state) => ReasonReact.reactElement;
   let component = ReasonReact.statelessComponent("WithState");

   let make' = (~setState: setState, ~state: Params.state, children: children) => {
     ...component,
     render: _self => children(~setState, ~state),
   };

   let jsComponent =
     ReasonReact.wrapReasonForJs(
       ~component,
       (
         props: {
           .
           "setState": setState,
           "state": Params.state,
           "children": children,
         },
       ) =>
       make'(~setState=props##setState, ~state=props##state, props##children)
     );

   let enhanced =
     withState("state", "setState", Params.defaultValue, jsComponent);

   let make = (children: children) =>
     ReasonReact.wrapJsForReason(
       ~reactClass=enhanced,
       ~props=Js.Obj.empty(),








  hildren,
     );
 }; */
