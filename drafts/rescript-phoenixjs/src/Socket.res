type t;

type ref;

type messageArgs<'a> = {
  event: string,
  join_ref: option<string>,
  payload: 'a,
  ref: option<string>,
  topic: string,
};

type protocol = [ | #wss | #ws]

type binaryType = [ | #blob | #arraybuffer]

type connectionState = [ | #closed | #errored | #joined | #joining | #leaving ]

type transport = [ | #longpoll | #websocket]

type logger<'a> = (~kind: string, ~msg: string, ~data: 'a) => unit;

@deriving(abstract)
type options<'a, 'b> = {
  @optional transport,
  @optional timeout: int,
  @optional heartbeatIntervalMs: int,
  @optional reconnectAfterMs: int,
  @optional rejoinAfterMs: int,
  @optional longpollerTimeout: int,
  @optional binaryType,
  @optional logger: 'b,
  params: 'a,
};

@module("phoenix")
@new external make: (string, option<options<_, _>>) => t = "Socket";

@send external endPointURL: t => string = "endPointURL";
@send external protocol: t => protocol = "protocol";
@send external connect: t => unit = "connect";
@send external disconnect:
  (t, ~callback: 'a => unit, ~code: int=?, ~reason: string=?, unit) => unit =
  "disconnect";
@send external log: (t, ~kind: string, ~msg: string, ~param: 'a) => unit = "log";
@send external hasLogger: t => bool = "hasLogger";
@send external onOpen: (t, unit => unit) => ref = "onOpen";
@send external onClose: (t, 'a => unit) => ref = "onClose";
@send external onError: (t, 'a => unit) => ref = "onError";
@send external onMessage: (t, messageArgs<'a> => unit) => ref = "onMessage";
@send external connectionState: t => connectionState = "connectionState";
@send external isConnected: t => bool = "isConnected";
@send external makeRef: t => ref = "makeRef";
@send external push: (t, messageArgs<'a>) => unit = "push";