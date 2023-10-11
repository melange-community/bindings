module Rest: {
  type request<'body> = {body: Js.Undefined.t<'body>, params: Js.Dict.t<string>}
  type responseTransformer
  type response
  type realFetchResponse
  type context

  type completeTransformer
  type responseResolver<'body> = (request<'body>, response, context) => completeTransformer

  let mock: (array<responseTransformer>, response) => completeTransformer
  let mockOnce: (array<responseTransformer>, response) => completeTransformer

  let status: (int, context) => responseTransformer
  let set: (string, string, context) => responseTransformer
  let delay: (int, context) => responseTransformer
  let fetch: (request<'body>, context) => Js.Promise.t<realFetchResponse>

  let text: (string, context) => responseTransformer
  let json: (Js.Json.t, context) => responseTransformer
  let xml: (string, context) => responseTransformer
}

module GraphQL: {
  type request<'a> = {
    variables: 'a,
    params: Js.Dict.t<string>,
  }
  type responseTransformer
  type response
  type realFetchResponse
  type context

  type completeTransformer
  type responseResolver<'a> = (request<'a>, response, context) => completeTransformer

  let mock: (array<responseTransformer>, response) => completeTransformer
  let mockOnce: (array<responseTransformer>, response) => completeTransformer

  let status: (int, context) => responseTransformer
  let set: (string, string, context) => responseTransformer
  let delay: (int, context) => responseTransformer
  let fetch: (request<'a>, context) => Js.Promise.t<realFetchResponse>

  let data: (Js.Json.t, context) => responseTransformer
  let errors: (array<Js.Json.t>, context) => responseTransformer
}

type schemaAPI
type nodeServer
type requestHandler

let rest: Rest.context
let graphql: GraphQL.context

module ServiceWorker: {
  let setup: array<requestHandler> => schemaAPI
  let start: (schemaAPI, unit) => unit
  let stop: (schemaAPI, unit) => unit
  let resetHandlers: (schemaAPI, unit) => unit
  let restoreHandlers: (schemaAPI, unit) => unit
  let use: (schemaAPI, requestHandler) => unit
  let query: (string, GraphQL.responseResolver<'a>, GraphQL.context) => requestHandler
  let mutation: (string, GraphQL.responseResolver<'a>, GraphQL.context) => requestHandler
}

module Node: {
  let setup: array<requestHandler> => nodeServer
  let listen: (nodeServer, unit) => unit
  let close: (nodeServer, unit) => unit
  let resetHandlers: (nodeServer, unit) => unit
  let restoreHandlers: (nodeServer, unit) => unit
  let use: (nodeServer, requestHandler) => unit
  let get: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
  let post: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
  let put: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
  let patch: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
  let delete: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
  let options: (string, Rest.responseResolver<'body>, Rest.context) => requestHandler
}
