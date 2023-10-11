let _ = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));
let _ =
  ReactSSRPrepass.ssrPrepass(
    `PrepassNodeVisitor((
      <App />,
      element => {
        Js.log2("Element found: ", element);
        let elementType =
          ReactSSRPrepass.toElementJS(element) |> ReactSSRPrepass.type_Get;
        let componentType =
          Component.make(Js.Obj.empty())
          |> ReactSSRPrepass.toElementJS
          |> ReactSSRPrepass.type_Get;

        if (elementType === componentType) {
          Js.log("Execute data fetching logic!");
        };

        Js.Nullable.undefined;
      },
    )),
  );

let prepass = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));
prepass
|> Js.Promise.then_(() => {
     Js.log("Prepass has finished.");
     Js.Promise.resolve(() => ());
   });