type interface;

[@bs.deriving abstract]
type interfaceOptions = {
  input: in_channel,
  [@bs.optional]
  output: out_channel,
  [@bs.optional]
  terminal: bool,
  [@bs.optional]
  historySize: int,
  [@bs.optional]
  prompt: string,
  [@bs.optional]
  crlfDelay: int,
  [@bs.optional]
  removeHistoryDuplicates: int,
};

[@bs.module "readline"]
external createInterface: interfaceOptions => interface = "createInterface";

[@bs.send]
external on:
  (
    interface,
    [@bs.string] [
      | `close(unit => unit)
      | `line(string => unit)
      | `pause(unit => unit)
      | `resume(unit => unit)
      | `SIGCONT(unit => unit)
      | `SIGINT(unit => unit)
      | `SIGTSTP(unit => unit)
    ]
  ) =>
  interface =
  "on";

[@bs.send] external close: interface => unit = "close";

[@bs.send] external pause: interface => unit = "pause";

[@bs.send]
external prompt: (interface, ~preserveCursor: bool=?, unit) => unit = "prompt";

[@bs.send]
external question: (interface, string, string => unit) => unit = "question";

[@bs.send] external resume: interface => unit = "resume";

[@bs.send] external setPrompt: (interface, string) => unit = "setPrompt";

[@bs.deriving abstract]
type keyOption = {
  [@bs.optional]
  ctrl: bool,
  [@bs.optional]
  meta: bool,
  [@bs.optional]
  shift: bool,
  name: string,
};

[@bs.send]
external write: (interface, ~key: keyOption=?, unit) => unit = "write";