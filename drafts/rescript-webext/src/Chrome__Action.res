type titleDetails = {title: string, tabId?: int}

external setTitle: titleDetails => promise<unit> = "chrome.action.setTitle"

external setTitleWithCallback: (titleDetails, unit => unit) => unit = "chrome.action.setTitle"

type tabIconDetails = {path?: string, tabId?: int, imageData?: Webapi.Dom.Image.t}

external setIcon: tabIconDetails => unit = "chrome.action.setIcon"

module OnClicked = {
  external addListener: (Chrome__Tabs.tab => unit) => unit = "chrome.action.onClicked.addListener"
}
