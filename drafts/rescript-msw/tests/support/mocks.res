open MSW

module Rest = {
  open Node

  let get = rest |> get("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let postWithBody = rest |> post("https://api.github.com/repos", (req, res, ctx) => {
    let body = req.body |> Js.Undefined.toOption

    let body = Printf.sprintf(
      "%s/%s",
      body |> Option.flatMap(_, body => Js.Dict.get(body, "owner")) |> Option.getWithDefault(_, ""),
      body |> Option.flatMap(_, body => Js.Dict.get(body, "repo")) |> Option.getWithDefault(_, ""),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let post = rest |> post("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let put = rest |> put("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let patch = rest |> patch("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let delete = rest |> delete("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })

  let options = rest |> options("https://api.github.com/repos/:owner/:repo", (req, res, ctx) => {
    let body = Printf.sprintf(
      "%s/%s",
      req.params |> Js.Dict.get(_, "owner") |> Option.getWithDefault(_, "N/A"),
      req.params |> Js.Dict.get(_, "repo") |> Option.getWithDefault(_, "N/A"),
    )

    res |> Rest.mock([ctx |> Rest.status(200), ctx |> Rest.text(body)])
  })
}

module GraphQL = {
  open ServiceWorker

  let queryOk =
    graphql |> query("GetUserDetail", (req, res, ctx) =>
      res |> GraphQL.mock([
        ctx |> GraphQL.status(200),
        ctx |> GraphQL.data(
          Js.Dict.fromList(list{("name", req.variables["name"])}) |> Js.Json.object_,
        ),
      ])
    )

  let queryError = graphql |> query("GetUserDetailError", (req, res, ctx) => {
    let message = ("message", Js.Json.string("This is a mocked error: " ++ req.variables["name"]))
    let location = Js.Dict.fromList(list{
      ("line", Js.Json.number(1.0)),
      ("column", Js.Json.number(2.0)),
    })
    let locations = ("locations", Js.Json.objectArray([location]))

    res |> GraphQL.mock([
      ctx |> GraphQL.status(200),
      ctx |> GraphQL.errors([Js.Dict.fromList(list{message, locations}) |> Js.Json.object_]),
    ])
  })

  let mutationOk =
    graphql |> mutation("Logout", (req, res, ctx) =>
      res |> GraphQL.mock([
        ctx |> GraphQL.status(200),
        ctx |> GraphQL.data(
          Js.Dict.fromList(list{("referrer", req.variables["referrer"])}) |> Js.Json.object_,
        ),
      ])
    )

  let mutationError = graphql |> mutation("LogoutError", (req, res, ctx) => {
    let message = (
      "message",
      Js.Json.string("This is a mocked error: " ++ req.variables["referrer"]),
    )
    let location = Js.Dict.fromList(list{
      ("line", Js.Json.number(1.0)),
      ("column", Js.Json.number(2.0)),
    })
    let locations = ("locations", Js.Json.objectArray([location]))

    res |> GraphQL.mock([
      ctx |> GraphQL.status(200),
      ctx |> GraphQL.errors([Js.Dict.fromList(list{message, locations}) |> Js.Json.object_]),
    ])
  })
}
