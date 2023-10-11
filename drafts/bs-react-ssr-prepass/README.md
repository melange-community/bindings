# bs-react-ssr-prepass

BuckleScript bindings for [`react-ssr-prepass`](https://github.com/FormidableLabs/react-ssr-prepass). This allows you to use React `Suspense` for data fetching on the server-side in ReasonML.

## API

These bindings expose a single function, `ssrPrepass`, that allows you to walk your React tree and look for thrown `Promise`s to trigger `Suspense`. The argument passed to this function is a polymorphic variant with two possible constructors.

```reason
[
  | `PrepassNode(React.element)
  | `PrepassNodeVisitor(React.element, visitor)
]
```

If you just want to have `react-ssr-prepass` walk your React tree (or a part of it) and suspend on any thrown `Promise`s, just use the first constructor.

```reason
let prepass = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));

prepass
|> Js.Promise.then_(() => {
     Js.log("Prepass has finished. Server render the app!");
     Js.Promise.resolve(() => ());
   });
```

You can also pass a custom `visitor` function to `react-ssr-prepass` that will visit each React element in your application and allow you to execute custom data fetching logic based on the `element`.

```reason
let prepass = ReactSSRPrepass.ssrPrepass(`PrepassNodeVisitor(<App />, element => {
  /* Inspect the element as you like to call custom data fetching logic. */
}));

prepass
|> Js.Promise.then_(() => {
     Js.log("Prepass has finished. Server render the app!");
     Js.Promise.resolve(() => ());
   });
```

Because ReasonReact doesn't expose any utilities for you to introspect React elements themselves (i.e. examine their `type`, `key`, or `props` directly), the `ReactSSRPrepass` `module` exposes a few useful functions to deal with this. The first is `toElementJS`. This function takes in a `React.element` and returns a `[@bs.deriving abstract]` object representing the raw React element. You can then use the accessors provided by the `[@bs.deriving abstract]` to access those fields. An example will help make this clear:

```reason
let _ =
  ReactSSRPrepass.ssrPrepass(
    `PrepassNodeVisitor((
      <App />,
      element => {
        /* Get the type property off the element. */
        let elementType =
          ReactSSRPrepass.toElementJS(element) |> ReactSSRPrepass.type_Get;

        /* Get the type property off an arbitrary Component. */
        let componentType =
          Component.make(Js.Obj.empty())
          |> ReactSSRPrepass.toElementJS
          |> ReactSSRPrepass.type_Get;

        /* Check if the types match. */
        if (elementType === componentType) {
          /* Execute specific data fetching logic for this element. */
          Js.log("Execute data fetching logic!");
        };

        /* Return undefined. You can also return a promise from this function. */
        Js.Nullable.undefined;
      },
    )),
  );
```

Note that `toElementJS` takes advantage of [BuckleScript's `%identity` trick](https://bucklescript.github.io/docs/en/interop-cheatsheet#identity-external). It's a bandaid solution as long as we can't get fully type-safe access to the internals of `ReasonReact.element`.


## Maintenance Status

**Archived:** This project is no longer maintained by Formidable. We are no longer responding to issues or pull requests unless they relate to security concerns. We encourage interested developers to fork this project and make it their own!
