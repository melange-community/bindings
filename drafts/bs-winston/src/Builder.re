type level =
  | Error
  | Warn
  | Info
  | Verbose
  | Debug
  | Silly;

type t = {
  level: option(level),
  formats: list(Format.t),
  transports: list(Transport.t),
  silent: option(bool),
  errorKey: option(string)
};

let levelStr: level => string =
  lvl => switch (lvl) {
    | Error => "error"
    | Warn => "warn"
    | Info => "info"
    | Verbose => "verbose"
    | Debug => "debug"
    | Silly => "silly"
  };

let create = () => ({level: None, formats: [], transports: [], silent: None, errorKey: None});

let setLevel = (builder, lvl) => ({...builder, level: Some(lvl)});

let setSilent = (builder, silent) => ({...builder, silent: Some(silent)});

let addFormat = (builder, format) => ({...builder, formats: [format, ...builder.formats]});

let addTransport = (builder, transport) => ({...builder, transports: [transport, ...builder.transports]});

let setErrorKey = (builder, key) => ({...builder, errorKey: Some(key)});

let aggregateFormats: list(Format.t) => option(Format.t) =
  formats => switch (Belt.List.length(formats)) {
    | 0 => None
    | 1 => formats -> Belt.List.head
    | _ => formats -> Belt.List.reverse -> Format.combine -> Some
  };

let build =
  builder => 
    Logger.create(
      ~level =? builder.level -> Belt.Option.map(levelStr),
      ~format =? builder.formats -> aggregateFormats,
      ~transports = builder.transports -> Belt.List.reverse,
      ~silent =? builder.silent,
      ~errorKey =? builder.errorKey,
      ()
    );
