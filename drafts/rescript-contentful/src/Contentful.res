type t

type assetKey = {
  secret: string,
  policy: string,
}

type tagLink = {"sys": {"type": [#Link], "linkType": [#Tag], "id": string}}

type metadata = {"tags": array<tagLink>}

type link<'linkType> = {"type": [#Link], "linkType": 'linkType, "id": string}

type contentTypeLink = link<[#ContentType]>
type spaceLink = link<[#Space]>
type environmentLink = link<[#Environment]>

type field = {
  "disabled": bool,
  "id": string,
  "linkType": option<string>,
  "localized": bool,
  "name": string,
  "omitted": bool,
  "required": bool,
  "type": [
    | #Symbol
    | #Text
    | #Integer
    | #Number
    | #Date
    | #Boolean
    | #Location
    | #Link
    | #Array
    | #Object
    | #RichText
  ],
  "validations": array<Js.Json.t>,
  "items": option<Js.Json.t>,
}

type sys = {
  "type": string,
  "id": string,
  "createdAt": string,
  "updatedAt": string,
  "locale": string,
  "revision": option<int>,
  "space": option<{
    "sys": spaceLink,
  }>,
  "environment": option<{
    "sys": environmentLink,
  }>,
  "contentType": {"sys": contentTypeLink},
}

type rec entry<'fields> = {
  "sys": sys,
  "fields": 'fields,
  "metadata": metadata,
  "toPlainObject": (. unit) => Js.Json.t,
  "update": (. unit) => promise<entry<'fields>>,
}

type asset = {
  "sys": sys,
  "fields": {
    "title": string,
    "description": string,
    "file": {
      "url": string,
      "details": {"size": int, "image": option<{"width": int, "height": int}>},
      "fileName": string,
      "contentType": string,
    },
  },
  "metadata": metadata,
  "toPlainObject": (. unit) => Js.Json.t,
}

type contentType = {
  "sys": sys,
  "name": string,
  "description": string,
  "displayField": string,
  "fields": array<field>,
  "toPlainObject": (. unit) => Js.Json.t,
}

type space = {
  "sys": sys,
  "name": string,
  "locales": array<string>,
  "toPlainObject": (. unit) => Js.Json.t,
}

type locale = {
  "code": string,
  "name": string,
  "default": bool,
  "fallbackCode": option<string>,
  "sys": {"id": string, "type": [#Locale], "version": int},
}

type tag = {
  "name": string,
  "sys": {"id": string, "type": [#Tag], "version": int, "visibility": [#public]},
}

type syncCollection = {
  "entries": array<entry<Js.Json.t>>,
  "assets": array<asset>,
  "deletedEntries": array<entry<Js.Json.t>>,
  "deletedAssets": array<asset>,
  "nextSyncToken": string,
  "toPlainObject": (. unit) => Js.Json.t,
  "stringifySafe": (option<Js.Json.t>, option<Js.Json.t>) => string,
}

type contentfulCollection<'a> = {
  "total": int,
  "skip": int,
  "limit": int,
  "items": array<'a>,
  "toPlainObject": (. unit) => Js.Json.t,
}

type entryCollection<'a> = {
  "total": int,
  "skip": int,
  "limit": int,
  "items": array<'a>,
  "errors": option<array<Js.Json.t>>,
  "includes": option<Js.Json.t>,
  "stringifySafe": (. option<Js.Json.t>, option<Js.Json.t>) => string,
  "toPlainObject": (. unit) => Js.Json.t,
}

type assetCollection = contentfulCollection<asset>
type contentTypeCollection = contentfulCollection<contentType>
type localeCollection = contentfulCollection<locale>
type tagCollection = contentfulCollection<tag>

type clientLogLevel = [#error | #warning | #info]

type proxyAuth = {username: string, password: string}

type axiosProxyConfig = {
  host: string,
  port: int,
  auth?: proxyAuth,
  protocol?: string,
}

type headers
external makeHeaders: 't => headers = "%identity"

type clientOpts = {
  accessToken: string,
  space: string,
  adapter?: Obj.t,
  application?: string,
  basePath?: string,
  environment?: string,
  headers?: Js.Dict.t<string>,
  host?: string,
  httpAgent?: Obj.t,
  httpsAgent?: Obj.t,
  insecure?: bool,
  integration?: string,
  logHandler?: (. clientLogLevel, Obj.t) => unit,
  proxy?: axiosProxyConfig,
  removeUnresolved?: bool,
  resolveLinks?: bool,
  retryLimit?: int,
  retryOnError?: bool,
  timeout?: int,
}

@module("contentful")
external createClient: clientOpts => t = "createClient"

@send external createAssetKey: (t, int) => promise<assetKey> = "createAssetKey"
@send external getAsset: (t, string, ~query: 'query=?, unit) => promise<asset> = "getAsset"
@send external getAssets: (t, ~query: 'query=?, unit) => promise<assetCollection> = "getAssets"
@send external getContentType: (t, string) => promise<contentType> = "getContentType"
@send
external getContentTypes: (t, ~query: 'query=?, unit) => promise<contentTypeCollection> =
  "getContentTypes"
@send external getEntry: (t, string) => promise<option<entry<'fields>>> = "getEntry"
@send
external getEntries: (t, ~query: 'query=?, unit) => promise<entryCollection<'fields>> =
  "getEntries"
@send external getSpace: t => promise<space> = "getSpace"
@send external getLocales: t => promise<localeCollection> = "getLocales"
@send external getTag: (t, string) => promise<tag> = "getTag"
@send external getTags: (t, ~query: 'query=?, unit) => promise<tagCollection> = "getTags"
@send external parseEntries: (t, 'raw) => promise<entryCollection<'fields>> = "parseEntries"
@send external sync: (t, 'query) => promise<syncCollection> = "sync"

@get external withoutLinkResolution: t => t = "withoutLinkResolution"
@get external withoutUnresolvableLinks: t => t = "withoutUnresolvableLinks"
@get external withAllLocales: t => t = "withAllLocales"
@get external version: t => string = "version"
