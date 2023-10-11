type t;

let createConsole: (
  ~level: string =?,
  ~silent: bool =?,
  ~eol: string =?,
  ~stderrLevels: list(string) =?,
  ~consoleWarnLevels: list(string) =?,
  unit
) => t;

let createFile: (
  ~level: string =?,
  ~silent: bool =?,
  ~eol: string =?,
  ~filename: string =?,
  ~maxsize: int =?,
  ~maxFiles: int =?,
  ~tailable: bool =?,
  ~maxRetries: int =?,
  ~zippedArchive: bool =?,
  ~options: Js.t('a) =?,
  unit
) => t;

let createHttp: (
  ~host: string =?,
  ~port: int =?,
  ~path: string =?,
  ~auth: Js.t('a) =?,
  ~ssl: bool =?,
  unit
) => t;

let createStream: (
  ~level: string =?,
  ~silent: bool =?,
  ~eol: string =?,
  ~stream: 'a =?,
  unit
) => t;
