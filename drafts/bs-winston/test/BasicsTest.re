let describe = BsMocha.Mocha.describe;
open BsMocha.Async;
module Assert = BsMocha.Assert;
open Logger;


exception TestException(string);

let createTestLogger: unit => (Builder.t, (unit => Future.t(Belt.Result.t(string, exn)))) =
  () => {
    let (testTransport, createResultFuture) = TestTransport.create();
    let builder = Builder.create()
    -> Builder.setLevel(Builder.Debug)
    -> Builder.addTransport(testTransport);
    (builder, createResultFuture);
  };

let createTestLogger2 =
  () => {
    let (builder, createResultFuture) = createTestLogger();
    (builder
       -> Builder.addFormat(Format.createTimestamp(()))
       -> Builder.addFormat(Format.createSimple()),
     createResultFuture);
  };

let testResult: ((~error: Js.Exn.t=?, unit) => unit) => Future.t(Belt.Result.t(string, exn)) => string => unit =
  (done_, future, expected) =>
    future
    -> Future.mapOk(res => {
      Assert.equal(res, expected);
      done_();
    })
    -> Future.tapError(e => Assert.fail(e))
    -> ignore;

let createJsExn: string => exn =
  msg =>
    try (Js.Exn.raiseError(msg)) {
      | e => e
    };

let messageToUpper: Js.Dict.t(Js.Json.t) => Js.Dict.t(Js.Json.t) =
  infoObj => {
    infoObj
    -> Js.Dict.get("message")
    -> Belt.Option.flatMap(Js.Json.decodeString)
    -> Belt.Option.map(Js.String.toUpperCase)
    -> Belt.Option.map(Js.Json.string)
    -> Belt.Option.map(Js.Dict.set(infoObj, "message", _))
    -> ignore;
    infoObj;
  };

describe("Basic Logging", () => {

  describe("without Formats", () => {

    it("should log strings", done_ => {
      let (builder, createResultFuture) = createTestLogger();
      let logger = builder -> Builder.build;

      let resultFuture = createResultFuture();
      logger -> withMessage("jobs") -> withMessage(3451) -> logDebugMsg("testing this");
      testResult(done_, resultFuture, {js|{"message":"jobs 3451 testing this","level":"debug"}|js});
    });

    it("should log correct level", done_ => {
      let (builder, createResultFuture) = createTestLogger();
      let logger = builder -> Builder.setLevel(Builder.Warn) -> Builder.build;

      let resultFuture = createResultFuture();
      logger -> logDebugMsg("testing this");
      logger -> logErrorMsg("Some Error");
      logger -> logInfoMsg("kuckoo");
      testResult(done_, resultFuture, {js|{"message":"Some Error","level":"error"}|js});
    });

    it("should log ocaml errors", done_ => {
      let (builder, createResultFuture) = createTestLogger();
      let logger = builder -> Builder.build;

      let error = TestException("testing");

      let resultFuture = createResultFuture();
      logger -> logErrorExn("My context", error);
      testResult(done_, resultFuture, {js|{"error":"{\\"RE_EXN_ID\\":\\"BasicsTest-BsWinston.TestException/2\\",\\"_1\\":\\"testing\\"}","message":"My context","level":"error"}|js});
    });

    it("should log Js.Exn.t errors", done_ => {
      let (builder, createResultFuture) = createTestLogger();
      let logger = builder -> Builder.build;

      let error = createJsExn("another brother");
      let resultFuture = createResultFuture();
      logger -> logErrorExn("My context", error);

      resultFuture
      -> Future.mapOk(res => {
        Assert.equal(Js.String.startsWith({js|{"error":{"name":"Error","message":"another brother","stack":"Error: another brother|js}, res), true);
        Assert.equal(Js.String.endsWith({js|,"message":"My context","level":"error"}|js}, res), true);
        done_();
      })
      -> Future.tapError(e => Assert.fail(e))
      -> ignore;
    });

  });

  describe("format simple with timestamp", () => {
    it("should log strings", done_ => {
      let (builder, createResultFuture) = createTestLogger2();
      let logger = builder -> Builder.build;

      let resultFuture = createResultFuture();
      logger -> withMessage("jobs") -> withMessage(3451) -> logDebugMsg("testing this");

      resultFuture
      -> Future.mapOk(res => {
        Assert.equal(Js.String.startsWith({js|debug: jobs 3451 testing this {"timestamp":"|js}, res), true);
        done_();
      })
      -> Future.mapError(e => Assert.fail(e))
      -> ignore;
    });
  });

  describe("custom formatter with simple output formatter", () => {
    it("should do the trick", done_ => {
      let (builder, createResultFuture) = createTestLogger();
      let logger =
        builder
        -> Builder.addFormat(Format.fromMapFn(messageToUpper))
        -> Builder.addFormat(Format.createSimple())
        -> Builder.build;

      let resultFuture = createResultFuture();
      logger -> logDebugMsg("testing this");
      testResult(done_, resultFuture, {js|debug: TESTING THIS|js});
    });
  });

});
