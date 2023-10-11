open Js.Promise
open Jest
open Expect
open MSW

describe("Node Server", () => {
  open Node

  let server = setup([
    Mocks.Rest.get,
    Mocks.Rest.post,
    Mocks.Rest.postWithBody,
    Mocks.Rest.put,
    Mocks.Rest.patch,
    Mocks.Rest.delete,
    Mocks.Rest.options,
    Mocks.GraphQL.queryOk,
    Mocks.GraphQL.queryError,
    Mocks.GraphQL.mutationOk,
    Mocks.GraphQL.mutationError,
  ])

  beforeAll(() => server->listen())

  beforeEach(() => server->resetHandlers())

  afterAll(() => server->close())

  describe("Rest", () => {
    testPromise("get works", () =>
      Fetch.fetch("https://api.github.com/repos/jihchi/res-msw")
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )

    testPromise("post with request body works", () => {
      let payload = Js.Dict.fromArray([
        ("owner", Js.Json.string("jihchi")),
        ("repo", Js.Json.string("res-msw")),
      ])

      Fetch.fetchWithInit(
        "https://api.github.com/repos",
        Fetch.RequestInit.make(
          ~method_=Post,
          ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
          ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
          (),
        ),
      )
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    })

    testPromise("post works", () =>
      Fetch.fetchWithInit(
        "https://api.github.com/repos/jihchi/res-msw",
        Fetch.RequestInit.make(~method_=Post, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )

    testPromise("put works", () =>
      Fetch.fetchWithInit(
        "https://api.github.com/repos/jihchi/res-msw",
        Fetch.RequestInit.make(~method_=Put, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )

    testPromise("patch works", () =>
      Fetch.fetchWithInit(
        "https://api.github.com/repos/jihchi/res-msw",
        Fetch.RequestInit.make(~method_=Patch, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )

    testPromise("delete works", () =>
      Fetch.fetchWithInit(
        "https://api.github.com/repos/jihchi/res-msw",
        Fetch.RequestInit.make(~method_=Delete, ()),
      )
      |> then_(Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )

    testPromise("options works", () =>
      Fetch.fetchWithInit(
        "https://api.github.com/repos/jihchi/res-msw",
        Fetch.RequestInit.make(~method_=Options, ()),
      )
      |> then_(res => res->Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
    )
  })

  describe("GraphQL", () => {
    let contentTypeJson = Fetch.HeadersInit.makeWithArray([("Content-Type", "application/json")])

    testPromise("query works", () => {
      let body = {
        "query": `
            query GetUserDetail {
              user {
                name
              }
            }
          `,
        "variables": {
          "name": "jihchi/res-msw",
        },
      }
      ->Js.Json.stringifyAny
      ->Option.getWithDefault("")
      ->Fetch.BodyInit.make

      Fetch.fetchWithInit(
        "http://this.does.not/matter",
        Fetch.RequestInit.make(~method_=Post, ~headers=contentTypeJson, ~body, ()),
      )
      |> then_(res => res->Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual(`{"data":{"name":"jihchi/res-msw"}}`) |> resolve)
    })

    testPromise("query error works", () => {
      let body = {
        "query": `
            query GetUserDetailError {
              user {
                name
              }
            }
          `,
        "variables": {
          "name": "jihchi/res-msw",
        },
      }
      ->Js.Json.stringifyAny
      ->Option.getWithDefault("")
      ->Fetch.BodyInit.make

      Fetch.fetchWithInit(
        "http://this.does.not/matter",
        Fetch.RequestInit.make(~method_=Post, ~headers=contentTypeJson, ~body, ()),
      )
      |> then_(res => res->Fetch.Response.text)
      |> then_(text =>
        expect(text)
        |> toEqual(
          `{"errors":[{"message":"This is a mocked error: jihchi/res-msw","locations":[{"line":1,"column":2}]}]}`,
        )
        |> resolve
      )
    })

    testPromise("mutation works", () => {
      let body = {
        "query": `
            mutation Logout {
              logout {
                session
              }
            }
          `,
        "variables": {
          "referrer": "jihchi/res-msw",
        },
      }
      ->Js.Json.stringifyAny
      ->Option.getWithDefault("")
      ->Fetch.BodyInit.make

      Fetch.fetchWithInit(
        "http://this.does.not/matter",
        Fetch.RequestInit.make(~method_=Post, ~headers=contentTypeJson, ~body, ()),
      )
      |> then_(res => res->Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual(`{"data":{"referrer":"jihchi/res-msw"}}`) |> resolve)
    })

    testPromise("mutation error works", () => {
      let body = {
        "query": `
            mutation Logout {
              logout {
                session
              }
            }
          `,
        "variables": {
          "referrer": "jihchi/res-msw",
        },
      }
      ->Js.Json.stringifyAny
      ->Option.getWithDefault("")
      ->Fetch.BodyInit.make

      Fetch.fetchWithInit(
        "http://this.does.not/matter",
        Fetch.RequestInit.make(~method_=Post, ~headers=contentTypeJson, ~body, ()),
      )
      |> then_(res => res->Fetch.Response.text)
      |> then_(text => expect(text) |> toEqual(`{"data":{"referrer":"jihchi/res-msw"}}`) |> resolve)
    })
  })

  testPromise("runtime request handler", () => {
    server->use(rest |> get("https://api.github.com/starred/:owner/:repo", (req, res, ctx) => {
        let body = Printf.sprintf(
          "starred: %s/%s",
          req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
          req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
        )

        res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
      }))

    Fetch.fetch("https://api.github.com/starred/jihchi/res-msw")
    |> then_(Fetch.Response.text)
    |> then_(text => expect(text) |> toEqual("starred: jihchi/res-msw") |> resolve)
  })

  testPromise("permanent override", () => {
    server->use(rest |> get("https://api.github.com/starred/:owner/:repo", (req, res, ctx) => {
        let body = Printf.sprintf(
          "starred: %s/%s",
          req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
          req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
        )

        res |> Rest.mockOnce([ctx |> Rest.status(200), ctx |> Rest.text(body)])
      }))

    Fetch.fetch("https://api.github.com/starred/jihchi/res-msw")
    |> then_(Fetch.Response.text)
    |> then_(text => expect(text) |> toEqual("starred: jihchi/res-msw") |> resolve)
  })

  testPromise("restore handlers", () => {
    server->use(
      rest |> get("https://api.github.com/repos/:owner/:repo", (_req, res, ctx) =>
        res |> Rest.mockOnce([ctx |> Rest.status(500), ctx |> Rest.text("Internal server error")])
      ),
    )

    server->restoreHandlers()

    Fetch.fetch("https://api.github.com/repos/jihchi/res-msw")
    |> then_(_res => Fetch.fetch("https://api.github.com/repos/jihchi/res-msw"))
    |> then_(Fetch.Response.text)
    |> then_(text => expect(text) |> toEqual("jihchi/res-msw") |> resolve)
  })
})
