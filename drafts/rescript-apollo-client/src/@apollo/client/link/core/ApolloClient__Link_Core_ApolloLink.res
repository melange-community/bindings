module FetchResult = ApolloClient__Link_Core_Types.FetchResult
module GraphQLRequest = ApolloClient__Link_Core_Types.GraphQLRequest
module Observable = ApolloClient__ZenObservable.Observable
module Operation = ApolloClient__Link_Core_Types.Operation
module RequestHandler = ApolloClient__Link_Core_Types.RequestHandler

module Js_ = {
  // export declare class ApolloLink {
  //     static empty(): ApolloLink;
  //     static from(links: (ApolloLink | RequestHandler)[]): ApolloLink;
  //     static split(test: (op: Operation) => boolean, left: ApolloLink | RequestHandler, right?: ApolloLink | RequestHandler): ApolloLink;
  //     static execute(link: ApolloLink, operation: GraphQLRequest): Observable<FetchResult>;
  //     static concat(first: ApolloLink | RequestHandler, second: ApolloLink | RequestHandler): ApolloLink;
  //     constructor(request?: RequestHandler);
  //     split(test: (op: Operation) => boolean, left: ApolloLink | RequestHandler, right?: ApolloLink | RequestHandler): ApolloLink;
  //     concat(next: ApolloLink | RequestHandler): ApolloLink;
  //     request(operation: Operation, forward?: NextLink): Observable<FetchResult> | null;
  //     protected onError(reason: any): void;
  //     setOnError(fn: (reason: any) => any): this;
  // }
  type t

  module Static = {
    // static empty(): ApolloLink;
    @module("@apollo/client") @scope("ApolloLink")
    external empty: unit => t = "empty"
    // static from(links: (ApolloLink | RequestHandler)[]): ApolloLink;
    @module("@apollo/client") @scope("ApolloLink")
    external from: array<t> => t = "from"
    // static split(test: (op: Operation) => boolean, left: ApolloLink | RequestHandler, right?: ApolloLink | RequestHandler): ApolloLink;
    @module("@apollo/client") @scope("ApolloLink")
    external split: (~test: Operation.Js_.t => bool, ~whenTrue: t, ~whenFalse: t) => t = "split"
    // static execute(link: ApolloLink, operation: GraphQLRequest): Observable<FetchResult>;
    @module("@apollo/client") @scope("ApolloLink")
    external execute: (
      t,
      GraphQLRequest.t,
    ) => Observable.t<FetchResult.Js_.t<Js.Json.t>, Js.Exn.t> = "execute"
    // static concat(first: ApolloLink | RequestHandler, second: ApolloLink | RequestHandler): ApolloLink;
    @module("@apollo/client") @scope("ApolloLink")
    external concat: (t, t) => t = "concat"
  }

  @module("@apollo/client") @new
  external make: RequestHandler.Js_.t => t = "ApolloLink"

  @send external concat: (t, t) => t = "concat"

  @send external from: (t, array<t>) => t = "from"

  @send external setOnError: (t, Js.Json.t => unit) => unit = "onError"

  @send
  external split: (t, ~test: Operation.Js_.t => bool, ~whenTrue: t, ~whenFalse: t) => t = "split"
}

module Static = Js_.Static

type t = Js_.t

let make: RequestHandler.t => t = requestHandler => Js_.make(requestHandler->RequestHandler.toJs)

let concat = Js_.concat

let from = Js_.from

let setOnError = Js_.setOnError

let split: (t, ~test: Operation.t => bool, ~whenTrue: t, ~whenFalse: t) => t = (
  t,
  ~test,
  ~whenTrue,
  ~whenFalse,
) => t->Js_.split(~test=jsOperation => test(jsOperation->Operation.fromJs), ~whenTrue, ~whenFalse)
