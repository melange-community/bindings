# rescript-keycloak

[ReScript](https://rescript-lang.org) bindings for [`Keycloak`](https://github.com/keycloak/keycloak-documentation/blob/main/securing_apps/topics/oidc/javascript-adapter.adoc).

Exposed as `Keycloak` module.

## Installation

```console
npm install rescript-keycloak
# or
yarn add rescript-keycloak
```

`rescript-keycloak` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    // ...
+    "rescript-keycloak"
  ],
  //...
}
```
