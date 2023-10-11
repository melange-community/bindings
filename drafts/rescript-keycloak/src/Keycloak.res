module Keycloak = {
  type t
  @module("keycloak-js")

  type options = {
    url: string,
    realm: string,
    clientId: string,
  }

  @new
  external configKeycloak: (~options: options) => t = "Keycloak"
}

module ReactProvider = {
  @module("@react-keycloak/web") @react.component
  external make: (
    ~children: React.element,
    ~authClient: Keycloak.t,
  ) => React.element = "default"
}
