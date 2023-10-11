type messageSender = {
  id?: string,
  tab?: Chrome__Tabs.tab,
  nativeApplication?: string,
  frameId?: int,
  url?: string,
  tlsChannelId?: string,
  origin?: string,
}

external getURL: string => string = "chrome.runtime.getURL"

external reload: unit => unit = "chrome.runtime.reload"

external openOptionsPage: unit => unit = "chrome.runtime.openOptionsPage"

external sendMessage: ('message, 'response => unit) => unit = "chrome.runtime.sendMessage"

module OnMessage = {
  external addListener: (('message, messageSender, 'response => unit) => 'any) => unit =
    "chrome.runtime.onMessage.addListener"
}
