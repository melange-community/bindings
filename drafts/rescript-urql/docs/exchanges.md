# Exchanges

Exchanges are the mechanism by which `rescript-urql` modifies requests before they are sent to your GraphQL API and alters responses as they are received. If you want to add some additional functionality to your GraphQL operations, this is a great place to do that.

The `Exchanges` `module` is a submodule of the `Client` module and can be referenced at `ReScriptUrql.Client.Exchanges`. The following exchanges are provided out of the box with `rescript-urql`.

## Core Exchanges

`urql` ships with a set of core exchanges that are baked right into `@urql/core` and can be referenced safely in `rescript-urql` without installing any additional packages. These are detailed below.

### `cacheExchange`

The `cacheExchange` provides basic caching support for your GraphQL operations. It is of type `Exchanges.t`.

### `dedupExchange`

The `dedupExchange` will deduplicate pending operations waiting for a response. For example, if a user attempts to execute the same query by clicking a button in rapid succession, the `dedupExchange` will filter these events to a single request. It is of type `Exchanges.t`.

### `fetchExchange`

The `fetchExchange` is responsible for actually sending your request to your GraphQL API and handling the response. It is of type `Exchanges.t`.

### `defaultExchanges`

The above three exchanges make up `urql`'s `defaultExchanges`. When you create a client in `rescript-urql` these exchanges are already applied by default. If you specify an `exchanges` array, be sure to include the specific exchanges you need. You almost always want the `defaultExchanges`, so make sure to include them using `Array.concat` or `Array.append`.

```rescript
open ReScriptUrql

let client = Client.make(
  ~url="https://mygraphql.com/api",
  ~exchanges=[
    myCustomExchange,
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.fetchExchange
  ],
  ()
)
```

### `debugExchange`

The `debugExchange` is useful for tracking how operations are passing through the exchanges pipeline. It simply logs all incoming and outgoing operations to the console. Be sure to remove this in production! It is of type `Exchanges.t`.

### `subscriptionExchange`

The `subscriptionExchange` should be used in the event that you intend to support GraphQL subscriptions in your application through use of `useSubscription` or the client's `executeSubscription` method.

In order to use the `subscriptionExchange`, you'll need to do a little bit of setup. Specifically, you'll need to configure a subscription client of some kind that will handle the websocket connection to your GraphQL API. In `examples/5-subscription` we have some simple bindings to `subscriptions-transport-ws` that allow us to use this protocol (which is supported by Apollo). Here's an example of how to set everything up:

```rescript
/* Create the subscriptionClient using APIs from your subscription client of choice.
In this case we use custom bindings to SubscriptionsTransportWS. */
let subscriptionClient =
  SubscriptionsTransportWS.make(
    ~url="ws://localhost:4001/graphql",
    ~subscriptionClientConfig=SubscriptionsTransportWS.makeClientOptions(),
    (),
  )

/* Implement the forwardSubscription function. This tells rescript-urql how to handle
incoming operations of operationType 'subscription'. */
let forwardSubscription = operation => subscriptionClient["request"](operation)

/* Include the subscriptionExchange in your client's exchanges array. */
let client = Client.(
  make(
    ~url="https://localhost:3000/graphql",
    ~exchanges=Array.append(
      Exchanges.defaultExchanges,
      [Client.Exchanges.subscriptionExchange(~forwardSubscription, ())]
    ),
    ()
  )
)
```

### `ssrExchange`

The `ssrExchange` accepts a single optional argument, `~ssrExchangeParams`, a record with two fields:

- `~initialState` - which populates the server-side rendered data with a rehydrated cache.
- `~isClient` – tell the exchange whether or not it is executing on the client or the server. By default, `rescript-urql` will look at the `suspense` parameter passed to the client to determine this if `isClient` is not provided.

If using the `ssrExchange`, it should be placed after any caching exchanges, like `cacheExchange`, but before any asynchronous exchanges, like `fetchExchange`.

```rescript
open ReScriptUrql

let ssrCache = Exchanges.ssrExchange()

let client = Client.Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    ssrCache,
    Client.Exchanges.fetchExchange
  ],
  ()
)
```

The resulting data structure returned from creating the `ssrExchange` can be accessed using two getters:

- `extractData` – this is typically used on the server-side to extract data returned from your GraphQL requests after they've been executed on the server.

```rescript
open ReScriptUrql

let ssrCache = Client.Exchanges.ssrExchange(~ssrExchangeParams, ())

/* Extract data from the ssrCache. (Server-side) */
let extractedData = Client.Exchanges.extractData(~exchange=ssrCache)
```

- `restoreData` is typically used to rehydrate the client with data from the server. The `restore` argument is what allows you to reference the data returned from the server to the client.

```rescript
open ReScriptUrql

let ssrCache = Client.Exchanges.ssrExchange(~ssrExchangeParams, ())

/* Extract data from the ssrCache. */
let extractedData = Client.Exchanges.restoreData(~exchange=ssrCache, ~restore=urqlData)
```

This part of the API is still quite experimental, as server-side rendering in ReScript with Next.js is still in its infancy. Use with caution. For more information, read `urql`'s server-side rendering guide [here](https://github.com/FormidableLabs/urql/blob/master/docs/basics.md#server-side-rendering). To see an example of server-side rendering with `rescript-urql`, check out our [SSR example](https://github.com/parkerziegler/reason-urql-ssr).

### `composeExchanges`

`composeExchanges` is a helper function that will compose a single exchange function from an array of exchanges. Operations will be run through the provided exchanges in the order that they were provided to `composeExchanges`.

## Ecosystem Exchanges

In addition to the core exchanges exposed by `@urql/core`, `urql` also supports more abstracted exchanges that meet particular needs that may or may not be critical to your use case. In contrast to the core exchanges, these ecosystem exchanges should be used when you have a specific use case that warrants them. Many of these exchanges require additional packages to be installed. `rescript-urql` is in the process of adding bindings for these exchanges; if the ecosystem exchange you're interested in isn't outlined below, the bindings may not have yet been implemented. Community contributions are very welcome in this space!

### `multipartFetchExchange`

The `multipartFetchExchange` builds on the `fetchExchange` but adds additional functionality for multipart file uploads. It should replace the use of the `fetchExchange` if you need to support traditional fetches and multipart file uploads.

To use the `multipartFetchExchange`, add the package to your dependencies:

```sh
yarn add @urql/exchange-multipart-fetch
```

Then, substitute the `fetchExchange` with the `multipartFetchExchange`:

```rescript
open ReScriptUrql

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.multipartFetchExchange,
  ],
  ()
)
```

Read more on the `multipartFetchExchange` [here](https://github.com/FormidableLabs/urql/tree/main/exchanges/multipart-fetch).

### `persistedFetchExchange`

The `persistedFetchExchange` adds support for [persisted queries](https://www.onegraph.com/docs/persisted_queries.html), building off of the standard `fetchExchange`.

To use the `persistedFetchExchange`, add the package to your dependencies:

```sh
yarn add @urql/exchange-persisted-fetch
```

Then, add the exchange to your array of `exchanges`, sepcifying the options you want to configure:

```rescript
open ReScriptUrql

let persistedFetchExchangeOptions = Client.Exchanges.makePersistedFetchExchangeOptions(
  ~preferGetForPersistedQueries=true,
  (),
)

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.persistedFetchExchange(persistedFetchExchangeOptions),
    // Keep the fetchExchange to handle mutations.
    // The persistedFetchExchange only handles queries.
    Client.Exchanges.fetchExchange,
  ],
  ()
)
```

Read more about the `persistedFetchExchange` [here](https://github.com/FormidableLabs/urql/tree/main/exchanges/persisted-fetch).

### `refocusExchange`

The `refocusExchange` allows `rescript-urql` to redispatch active operations when the window regains focus.

To use the `refocusExchange`, add the package to your dependencies:

```sh
yarn add @urql/exchange-refocus
```

Then, add the exchange to your array of `exchanges`. The `refocusExchange` should be added _after_ the `dedupeExchange`, to prevent doing additional work on requests that are later deduplicated, and _before_ the `fetchExchange`:

```rescript
open ReScriptUrql

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.refocusExchange(),
    Client.Exchanges.cacheExchange,
    Client.Exchanges.fetchExchange,
  ],
  ()
)
```

### `requestPolicyExchange`

The `requestPolicyExchange` allows `rescript-urql` to automatically upgrade an operation's `requestPolicy` on a time-to-live basis. When the specified TTL has elapsed, `rescript-urql` will either:

- Upgrade the `requestPolicy` of the operation to `cache-and-network` if no `shouldUpgrade` callback is specified, or:
- Run the `shouldUpgrade` function to determine whether or not to upgrade the specific operation.

To use the `requestPolicyExchange`, add the package to your dependencies:

```sh
yarn add @urql/exchange-request-policy
```

Then, add the exchange to your array of `exchanges`, specifying the options you want to configure:

```rescript
open ReScriptUrql

let shouldUpgrade = (operation: Types.operation) =>
  operation.context.requestPolicy !== #CacheOnly

let requestPolicyExchangeOptions = Client.Exchanges.makeRequestPolicyExchangeOptions(
  ~shouldUpgrade,
  ~ttl=2000,
  (),
)

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.requestPolicyExchange(requestPolicyExchangeOptions),
    Client.Exchanges.fetchExchange,
  ],
  ()
)
```

Read more about the `requestPolicyExchange` [here](https://github.com/FormidableLabs/urql/tree/main/exchanges/request-policy).

### `retryExchange`

The `retryExchange` is useful for retrying particular operations. By default, adding this exchange with the base options will retry any operations that failed due to network errors. However, we can customize the exchange to catch more specific error cases as well.

To use the `retryExchange`, add the package to your dependencies:

```sh
yarn add @urql/exchange-retry
```

Then, add the exchange to your array of `exchanges`, specifying the options you want to configure:

```rescript
open ReScriptUrql

let retryExchangeOptions =
  Client.Exchanges.makeRetryExchangeOptions(~initialDelayMs=2000, ~randomDelay=false, ())

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.retryExchange(retryExchangeOptions),
    Client.Exchanges.fetchExchange,
  ],
  ()
)
```

By default, `urql` will apply the following configuration for you:

```typescript
{
  initialDelayMs: 1000,
  maxDelayMs: 15000,
  randomDelay: true,
  maxNumberAttempts: 2,
  retryIf: err => err && err.networkError,
}
```

If you want to use the defaults from `urql`, call `makeRetryExchangeOptions` with just a `unit` parameter.

```rescript
open ReScriptUrql

let retryExchangeOptions =
  Client.Exchanges.makeRetryExchangeOptions()

let client = Client.make(
  ~url="http://localhost:3000",
  ~exchanges=[
    Client.Exchanges.dedupExchange,
    Client.Exchanges.cacheExchange,
    Client.Exchanges.retryExchange(retryExchangeOptions),
    Client.Exchanges.fetchExchange,
  ],
  ()
)
```

Read more on the `retryExchange` [here](https://formidable.com/open-source/urql/docs/advanced/retry-operations/).

## Custom Exchanges

`rescript-urql` also allows you to write your own exchanges to modify outgoing GraphQL requests and incoming responses. To read up on the basics of exchanges, check out the excellent [`urql` documentation](https://formidable.com/open-source/urql/docs/concepts/exchanges/).

The signature of an exchange in `rescript-urql` is:

```rescript
type t = (
  exchangeInput,
  . Wonka.Types.sourceT<Types.operation>,
) => Wonka.Types.sourceT<Types.operationResultJs<Js.Json.t>>
```

`exchangeInput` here is a record containing two fields:

- `forward` – a function for forwarding the current operation onto the next exchange.
- `client` – your `rescript-urql` client instance.

Let's look at an example to see how to implement our own exchanges.

#### Rewriting the `debugExchange` in ReScript

To see how we can write our own custom exchange, we'll reimplement the `urql`'s native `debugExchange` in ReScript:

```rescript
open ReScriptUrql

// This is the native debugExchange that ships with `urql`, re-implemented in ReScript.
// Typically, you'd just add Exchanges.debugExchange to the Client's exchange array.
let debugExchange = ({Client.Exchanges.forward: forward}, . ops) =>
  ops
  // Execute the supplied callback as an operation is sent out.
  |> Wonka.tap((. op) => Js.log2("[debugExchange]: Incoming operation: ", op))
  // Forward the operation on to the next exchange.
  |> forward
  // Execute the supplied callback as an operation comes back in (i.e. an API request resolves).
  |> Wonka.tap((. res) => Js.log2("[debugExchange]: Completed operation: ", res))
```

That's it! We've successfully re-implemented `urql`'s `debugExchange` in ReScript. Because the `Wonka` library used for much of `urql`'s exchange architecture is written in Reason, writing our own exchanges is often more ergonomic than the JS experience. When you've written your exchange, just supply it to your client like so:

```rescript
open ReScriptUrql

let debugExchange = ({Client.Exchanges.forward: forward}, . ops) =>
  ops
  |> Wonka.tap((. op) => Js.log2("[debugExchange]: Incoming operation: ", op))
  |> forward
  |> Wonka.tap((. res) => Js.log2("[debugExchange]: Completed operation: ", res))

let client = Client.make(
  ~url="https://my-graphql-endpoint.com/graphql",
  ~exchanges=[
    debugExchange,
    Exchanges.dedupExchange,
    Exchanges.cacheExchange,
    Exchanges.fetchExchange
  ],
(),
)
```
