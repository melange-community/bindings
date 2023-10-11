let dynamoRequestToPromise = dynogelsRequest =>
  Belt.Result.(
    Js.Promise.make((~resolve, ~reject as _) =>
      dynogelsRequest((maybeExn, maybeItem) =>
        (
          switch (
            Js.Nullable.toOption(maybeExn),
            Js.Nullable.toOption(maybeItem),
          ) {
          | (None, Some(item)) => Ok(item)
          | (Some(exn), None) =>
            exn
            |> Js.Exn.message
            |> Js.Option.getWithDefault("An unknown error occurred")
            |> (msg => Error(msg))
          | (None, None) => Error("Got neither an error nor a result")
          | (Some(_), Some(_)) => Error("Got both an error and a result")
          }
        )
        |> (a => resolve(. a))
      )
    )
  );
