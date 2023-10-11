module Sync = {
  external clear: unit => unit = "chrome.storage.sync.clear"
  external clearWithCallback: (unit => unit) => unit = "chrome.storage.sync.clear"

  external set: 'a => promise<unit> = "chrome.storage.sync.set"
  external setWithCallback: ('a, unit => unit) => unit = "chrome.storage.sync.set"

  external remove: string => promise<unit> = "chrome.storage.sync.remove"
  external removeMany: array<string> => promise<unit> = "chrome.storage.sync.remove"
  external removeWithCallback: (string, unit => unit) => unit = "chrome.storage.sync.remove"
  external removeManyWithCallback: (array<string>, unit => unit) => unit =
    "chrome.storage.sync.remove"

  external getAll: ('a => unit) => unit = "chrome.storage.sync.get"
  external get: string => promise<'a> = "chrome.storage.sync.get"
  external getMany: array<string> => promise<'a> = "chrome.storage.sync.get"
  external getWithCallback: (string, 'a => unit) => unit = "chrome.storage.sync.get"
  external getManyWithCallback: (array<string>, 'a => unit) => unit = "chrome.storage.sync.get"
}
