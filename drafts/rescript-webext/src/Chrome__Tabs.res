type tab = {
  status?: string,
  index: int,
  openerTabId?: int,
  title?: string,
  url?: string,
  pendingUrl?: string,
  pinned: bool,
  highlighted: bool,
  windowId: int,
  active: bool,
  favIconUrl?: string,
  id?: int,
  incognito: bool,
  selected: bool,
  audible?: bool,
  discarded: bool,
  autoDiscardable: bool,
  // TODO: mutedInfo?: MutedInfo,
  width?: float,
  height?: float,
  sessionId?: string,
  groupId: int,
}

type createProperties = {
  index?: int,
  openerTabId?: int,
  url?: string,
  pinned?: bool,
  windowId?: int,
  active?: bool,
  selected?: bool,
}

external create: createProperties => promise<tab> = "chrome.tabs.create"
external createWithCallback: (createProperties, tab => unit) => unit = "chrome.tabs.create"
