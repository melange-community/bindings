module Rest = {
  type request<'body> = {body: Js.Undefined.t<'body>, params: Js.Dict.t<string>}
  type response
  type realFetchResponse
  type context

  type responseTransformer
  type completeTransformer
  type responseResolver<'body> = (request<'body>, response, context) => completeTransformer

  let mock: (array<responseTransformer>, response) => completeTransformer = %raw(
    `
  function mock(transformers, response) {
      return response(...transformers);
  }
`
  )

  let mockOnce: (array<responseTransformer>, response) => completeTransformer = %raw(
    `
  function mockOnce(transformers, response) {
      return response.once(...transformers);
  }
`
  )

  @bs.send
  external rawStatus: (context, int) => responseTransformer = "status"
  let status = (code, ctx) => rawStatus(ctx, code)

  @bs.send
  external rawSet: (context, string, string) => responseTransformer = "set"
  let set = (key, value, ctx) => rawSet(ctx, key, value)

  @bs.send
  external rawDelay: (context, int) => responseTransformer = "delay"
  let delay = (ms, ctx) => rawDelay(ctx, ms)

  @bs.send
  external rawFetch: (context, request<'body>) => Js.Promise.t<realFetchResponse> = "fetch"
  let fetch = (req, ctx) => rawFetch(ctx, req)

  @bs.module("msw") @bs.val external instance: context = "rest"

  @bs.send
  external rawText: (context, string) => responseTransformer = "text"
  let text = (text, ctx) => rawText(ctx, text)

  @bs.send
  external rawJson: (context, Js.Json.t) => responseTransformer = "json"
  let json = (json, ctx) => rawJson(ctx, json)

  @bs.send external rawXml: (context, string) => responseTransformer = "xml"
  let xml = (xml, ctx) => rawXml(ctx, xml)
}

module GraphQL = {
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

  let mock: (array<responseTransformer>, response) => completeTransformer = %raw(
    `
  function (transformers, response) {
      return response(...transformers);
  }
`
  )

  let mockOnce: (array<responseTransformer>, response) => completeTransformer = %raw(
    `
  function (transformers, response) {
      return response(...transformers);
  }
`
  )

  @bs.send
  external rawStatus: (context, int) => responseTransformer = "status"
  let status = (code, ctx) => rawStatus(ctx, code)

  @bs.send
  external rawSet: (context, string, string) => responseTransformer = "set"
  let set = (key, value, ctx) => rawSet(ctx, key, value)

  @bs.send
  external rawDelay: (context, int) => responseTransformer = "delay"
  let delay = (ms, ctx) => rawDelay(ctx, ms)

  @bs.send
  external rawFetch: (context, request<'a>) => Js.Promise.t<realFetchResponse> = "fetch"
  let fetch = (req, ctx) => rawFetch(ctx, req)

  @bs.module("msw") @bs.val external instance: context = "graphql"

  @bs.send
  external rawData: (context, Js.Json.t) => responseTransformer = "data"
  let data = (json, ctx) => rawData(ctx, json)

  @bs.send
  external rawErrors: (context, array<Js.Json.t>) => responseTransformer = "errors"
  let errors = (errors, ctx) => rawErrors(ctx, errors)
}

type schemaAPI
type nodeServer
type requestHandler

let rest = Rest.instance
let graphql = GraphQL.instance

module ServiceWorker = {
  @bs.module("msw") @bs.variadic
  external setup: array<requestHandler> => schemaAPI = "setupWorker"

  @bs.send external start: (schemaAPI, unit) => unit = "start"

  @bs.send external stop: (schemaAPI, unit) => unit = "stop"

  @bs.send
  external resetHandlers: (schemaAPI, unit) => unit = "resetHandlers"

  @bs.send
  external restoreHandlers: (schemaAPI, unit) => unit = "restoreHandlers"

  @bs.send external use: (schemaAPI, requestHandler) => unit = "use"

  @bs.send
  external rawQuery: (GraphQL.context, string, GraphQL.responseResolver<'a>) => requestHandler =
    "query"

  let query = (url, resolver, ctx) => rawQuery(ctx, url, resolver)

  @bs.send
  external rawMutation: (GraphQL.context, string, GraphQL.responseResolver<'a>) => requestHandler =
    "mutation"

  let mutation = (url, resolver, ctx) => rawMutation(ctx, url, resolver)
}

module Node = {
  @bs.module("msw/node") @bs.variadic
  external setup: array<requestHandler> => nodeServer = "setupServer"

  @bs.send external listen: (nodeServer, unit) => unit = "listen"

  @bs.send external close: (nodeServer, unit) => unit = "close"

  @bs.send
  external resetHandlers: (nodeServer, unit) => unit = "resetHandlers"

  @bs.send
  external restoreHandlers: (nodeServer, unit) => unit = "restoreHandlers"

  @bs.send external use: (nodeServer, requestHandler) => unit = "use"

  @bs.send
  external rawGet: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler = "get"

  let get = (url, resolver, ctx) => rawGet(ctx, url, resolver)

  @bs.send
  external rawPost: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler = "post"

  let post = (url, resolver, ctx) => rawPost(ctx, url, resolver)

  @bs.send
  external rawPut: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler = "put"

  let put = (url, resolver, ctx) => rawPut(ctx, url, resolver)

  @bs.send
  external rawPatch: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler =
    "patch"

  let patch = (url, resolver, ctx) => rawPatch(ctx, url, resolver)

  @bs.send
  external rawDelete: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler =
    "delete"

  let delete = (url, resolver, ctx) => rawDelete(ctx, url, resolver)

  @bs.send
  external rawOptions: (Rest.context, string, Rest.responseResolver<'body>) => requestHandler =
    "options"

  let options = (url, resolver, ctx) => rawOptions(ctx, url, resolver)
}
