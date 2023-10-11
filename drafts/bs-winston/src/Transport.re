type t;

module Console {
  [@bs.deriving abstract]
  type config = {
    [@bs.optional] level: string,
    [@bs.optional] silent: bool,
    [@bs.optional] eol: string,
    [@bs.optional] stderrLevels: array(string),
    [@bs.optional] consoleWarnLevels: array(string)
  };
  [@bs.new] [@bs.module "winston"] [@bs.scope "transports"] external newConsoleTransport: config => t = "Console";

  let create =
    (~level=?, ~silent=?, ~eol=?, ~stderrLevels=?, ~consoleWarnLevels=?, ()) =>
      newConsoleTransport(config(
        ~level =? level,
        ~silent =? silent,
        ~eol =? eol,
        ~stderrLevels =? stderrLevels -> Belt.Option.map(Belt.List.toArray),
        ~consoleWarnLevels =? consoleWarnLevels -> Belt.Option.map(Belt.List.toArray),
        ()
      ));
};
let createConsole = Console.create;

module File {
  [@bs.deriving abstract]
  type config('a) = {
    [@bs.optional] level: string,
    [@bs.optional] silent: bool,
    [@bs.optional] eol: string,
    [@bs.optional] filename: string,
    [@bs.optional] maxsize: int,
    [@bs.optional] maxFiles: int,
    [@bs.optional] tailable: bool,
    [@bs.optional] maxRetries: int,
    [@bs.optional] zippedArchive: bool,
    [@bs.optional] options: Js.t('a)
  };
  [@bs.new] [@bs.module "winston"] [@bs.scope "transports"] external newFileTransport: config('a) => t = "File";

  let create =
    (~level=?, ~silent=?, ~eol=?, ~filename=?, ~maxsize=?, ~maxFiles=?, ~tailable=?, ~maxRetries=?, ~zippedArchive=?, ~options=?, ()) =>
      newFileTransport(config(
        ~level =? level,
        ~silent =? silent,
        ~eol =? eol,
        ~filename =? filename,
        ~maxsize =? maxsize,
        ~maxFiles =? maxFiles,
        ~tailable =? tailable,
        ~maxRetries =? maxRetries,
        ~zippedArchive =? zippedArchive,
        ~options =? options,
        ()
      ));
};
let createFile = File.create;

module Http {
  [@bs.deriving abstract]
  type config('a) = {
    [@bs.optional] host: string,
    [@bs.optional] port: int,
    [@bs.optional] path: string,
    [@bs.optional] auth: Js.t('a),
    [@bs.optional] ssl: bool
  };
  [@bs.new] [@bs.module "winston"] [@bs.scope "transports"] external newHttpTransport: config('a) => t = "Http";

  let create =
    (~host=?, ~port=?, ~path=?, ~auth=?, ~ssl=?, ()) =>
      newHttpTransport(config(
        ~host =? host,
        ~port =? port,
        ~path =? path,
        ~auth =? auth,
        ~ssl =? ssl,
        ()
      ));
};
let createHttp = Http.create;

module Stream {
  [@bs.deriving abstract]
  type config('a) = {
    [@bs.optional] level: string,
    [@bs.optional] silent: bool,
    [@bs.optional] eol: string,
    [@bs.optional] stream: 'a
  };
  [@bs.new] [@bs.module "winston"] [@bs.scope "transports"] external newStreamTransport: config('a) => t = "Stream";

  let create =
    (~level=?, ~silent=?, ~eol=?, ~stream=?, ()) =>
      newStreamTransport(config(
        ~level =? level,
        ~silent =? silent,
        ~eol =? eol,
        ~stream =? stream,
        ()
      ));
};
let createStream = Stream.create;
