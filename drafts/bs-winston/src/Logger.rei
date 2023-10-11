type t;

let create: (
  ~level: string =?,
  ~format: Format.t =?,
  ~transports: list(Transport.t),
  ~silent: bool =?,
  ~errorKey: string =?,
  unit
) => t;

let error:   t => t;
let warn:    t => t;
let info:    t => t;
let verbose: t => t;
let debug:   t => t;
let silly:   t => t;

let withMessage: t => 'a => t;
let withExn:     t => exn => t;
let withJson:    t => string => Js.Json.t => t;

let log: t => unit;


/* Common combinations abbreviated for usage convenience */
let logErrorMsg: t => 'a => unit;
let logErrorExn: t => 'a => exn => unit;
let logWarnMsg:  t => 'a => unit;
let logInfoMsg:  t => 'a => unit;
let logDebugMsg: t => 'a => unit;
