[![npm](https://img.shields.io/npm/v/bs-winston.svg)](https://www.npmjs.com/package/bs-winston)

# BsWinston

This is adapter of [winston](https://github.com/winstonjs/winston) for ReasonML. Because ReasonML is significantly different from js the API here is decidedly different from vanilla winston API. See the API section and examples below.


# Install 

```
npm install bs-winston
```
And to `bsconfig.json`: `"bs-dependencies": [..., "bs-winston", ...]`


# Examples
Initialize/Setup a logger e.g. in MyLogger.re you write:
```ocaml
module Format = BsWinston.Format;
module Transport = BsWinston.Transport;

let logger =
  BsWinston.Builder.(
    create()
    -> setLevel(Debug)
    -> addFormat(Format.createSimple())
    -> addTransport(Transport.createConsole(()))
    -> build);
```

Use the logger above in another module:
```ocaml
module L = BsWinston.Logger;
let logger = MyLogger.logger;

L.logInfoMsg(logger, "This is info message");
L.logWarnMsg(logger, "This messege is sent at warn level");

try (Js.Exn.raiseError("log this")) {
  | error => L.logErrorExn(logger, "Never fails to fail", error)
}

/* In a complicated case you may want to send extra json keys. It is possible: */
logger
-> L.info
-> L.withMessage("the usual")
-> L.withJson("keyX", Js.Json.string("valueX"))
-> L.withJson("keyY", Js.Json.number(float_of_int(42)))
-> L.log;
```


# API

## Logger <small>(module `BsWinston.Logger`)</small>
- Logger instance is of type `BsWinston.Logger.t`
- Set level:
  - `error:   t => t`
  - `warn:    t => t`
  - `info:    t => t`
  - `verbose: t => t`
  - `debug:   t => t`
  - `silly:   t => t`
  
  The functions do not mutate but rather create a new logger with the requested level.
- Combinators:
  - `withMessage: t => 'a => t`
    
    Converts the message (2nd arg) into string (with Js.String.make) and combines it with the possible message in the logger (1st arg) (with one space " " in between to avoid clumping)
  - `withExn: t => exn => t`
    
    Converts the exception to Js.Json.t if it is Js.Exn.t or just stringifies other ocaml exceptions and sets the result to a field ("error" by default) which can be defined on logger options. (This function does not combine with itself i.e. latter usage overwrites the previous)
  - `withJson: t => string => Js.Json.t => t`

    Sets the json to a field named with the string parameter.
- Output
  - `log: t => unit`

    Produces the side-effect of logging to the logger transport.
- Convenience functions to make some common use cases less verbose:
  - `logErrorMsg` = `(logger, msg) => logger -> error -> withMessage(msg) -> log`
  - `logErrorExn` = `(logger, msg, error) => logger -> error -> withMessage(msg) -> withExn(error) -> log`
  - `logWarnMsg`  = `(logger, msg) => logger -> warn -> withMessage(msg) -> log`
  - `logInfoMsg`  = `(logger, msg) => logger -> info -> withMessage(msg) -> log`
  - `logDebugMsg` = `(logger, msg) => logger -> debug -> withMessage(msg) -> log`


## Builder <small>(module `BsWinston.Builder`)</small>

Loggers can be build either with Builder functions or directly with `Logger.create` (which is sligthly more lower level).

- `create: unit => t` Create a builder. ! This is without trasport and you need at least one transport to create a valid logger.
- `setLevel: t => level => t` Logger wide max level to output.
- `setSilent: t => bool => t`
- `addFormat: t => Format.t => t`  (See Formats) (The list will be auto-combined for winston)
- `addTransport: t => Transport.t => t` (See Transports)
- `errorKey: t => string => t` Set field for error content
- `build: t => Logger.t` Create the logger instance.

## Format <small>(module `BsWinston.Format`)</small>

Create winston formats with functions:
- `createAlign`
- `createCli`
- `createColorize`
- `createJson`
- `createLabel`
- `createLogstash`
- `createMetadata`
- `createMs`
- `createPadLevels`
- `createPrettyPrint`
- `createPrintf`
- `createSimple`
- `createSplat`
- `createTimestamp`
- `createUncolorize`

See the [src/Format.rei](https://github.com/veikkaus/bs-winston/blob/master/src/Format.rei) file for function argument details and the [logform](https://github.com/winstonjs/logform) for further explanations.

Simple custom filters (without Symbol manipulation) can be created with:
- `fromMapFn: (Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t)) => t`

  The function given as argument takes the info object and returns manipulated info object which is then forwarded in the formatting chain.

## Transport <small>(module `BsWinston.Transport`)</small>

Create winston transports with functions:
- `createConsole`
- `createFile`
- `createHttp`
- `createStream`

See the [src/Transport.rei](https://github.com/veikkaus/bs-winston/blob/master/src/Transport.rei) file for function argument details and the [winston](https://github.com/winstonjs/winston/blob/master/docs/transports.md#winston-core) for further explanations.

Other transports:
- [AWS Cloudwatch](https://github.com/veikkaus/bs-winston-cloudwatch)
