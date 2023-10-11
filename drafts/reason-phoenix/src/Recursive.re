module rec Push: {
  type t;

  [@bs.module "phoenix"] [@bs.new]
  external make:
    (Channel.t, ~event: string, ~payload: 'a, ~timeout: int=?, unit) => t =
    "Push";

  [@bs.send] external resend: (t, ~timeout: int) => unit = "resend";
  [@bs.send] external send: t => unit = "send";
  [@bs.send]
  external receive: (t, ~status: string, ~callback: 'a => unit) => t =
    "receive";
} = Push

and Channel: {
  type t;

  type ref;

  [@bs.send] external make: (Socket.t, string, 'a) => t = "channel";

  [@bs.send] external join: (t, ~timeout: int=?, unit) => Push.t = "join";
  [@bs.send]
  external push:
    (t, ~event: string, ~payload: 'a, ~timeout: int=?, unit) => Push.t =
    "push";
  [@bs.send] external leave: (t, ~timeout: int=?, unit) => Push.t = "leave";
  [@bs.send] external on: (t, string, 'a => unit) => ref = "on";
  [@bs.send] external off: (t, string, ref) => bool = "off";
  [@bs.send] external onClose: (t, unit => unit) => unit = "onClose";
  [@bs.send] external onError: (t, 'a => unit) => unit = "onError";
  [@bs.send] external onMessage: (t, string, 'a, ref) => 'a = "onMessage";
} = Channel;
