module rec Push: {
  type recHook = {
    status: string,
    callback: unit => Obj.t,
  }
  type receieveRespType = {
    response: Obj.t,
    status: string,
  }
  type t = {
    channel: Channel.t,
    event: string,
    payload: unit => unit,
    recHooks: array<recHook>,
    receivedResp: receieveRespType,
    ref: string,
    refEvent: string,
    sent: bool,
    timeout: int,
    timeoutTimer: option<unit => unit>,
  }

  @new external make: (Channel.t, ~event: string, ~payload: 'a, ~timeout: int=?, unit) => t = "Push"
  @send external resend: (t, ~timeout: int) => unit = "resend"
  @send external send: t => unit = "send"
  @send external receive: (t, ~status: string, ~callback: 'a => unit) => t = "receive"
} = Push
and Channel: {
  type binding = {
    event: string,
    ref: int,
    callback: unit => unit,
  }
  type t = {
    bindingRef: int,
    bindings: array<binding>,
    joinedOnce: bool,
    joinPush: Push.t,
    socket: Socket.t,
    state: string,
    stateChageRefs: array<string>,
    timeout: int,
    topic: string,
  }
  type ref = int
  @send external make: (Socket.t, string, 'a) => Channel.t = "channel"
  @send external join: (Channel.t, ~timeout: int=?, unit) => Push.t = "join"
  @send
  external push: (Channel.t, ~event: string, ~payload: 'a, ~timeout: int=?, unit) => Push.t = "push"
  @send external leave: (Channel.t, ~timeout: int=?, unit) => Push.t = "leave"
  @send external on: (Channel.t, string, 'a => unit) => ref = "on"
  @send external off: (Channel.t, string, ~ref: ref=?, unit) => unit = "off"
  @send external onClose: (Channel.t, unit => unit) => unit = "onClose"
  @send external onError: (Channel.t, 'a => unit) => unit = "onError"
  @send external onMessage: (Channel.t, string, 'a, ref) => 'a = "onMessage"
} = Channel
