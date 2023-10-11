/**
   Type definitions for AWS Lambda v2 Payload
   http://docs.aws.amazon.com/lambda
   https://docs.aws.amazon.com/apigateway/latest/developerguide/http-api-develop-integrations-lambda.html
 */
module Response: {
  type t;

  /**
   * create a response from an optional stringified body
   * and the different available options
   */
  [@bs.obj]
  external make:
    (
      ~cookies: array(string)=?,
      ~isBase64Encoded: bool=?,
      ~statusCode: int,
      ~headers: Js.Dict.t(string)=?,
      ~body: string=?,
      unit
    ) =>
    t;

  /**
   * create a response from a JSON compliant body
   */
  let fromBody: 'a => t;
} = {
  [@unboxed]
  type t =
    | Response('a): t;

  [@bs.obj]
  external make:
    (
      ~cookies: array(string)=?,
      ~isBase64Encoded: bool=?,
      ~statusCode: int,
      ~headers: Js.Dict.t(string)=?,
      ~body: string=?,
      unit
    ) =>
    t;

  let fromBody = body => Response(body);
};

module Context = Common.Context;

module Authorizer = {
  type jwt = {
    claims: option(Js.Dict.t(string)),
    scopes: option(array(string)),
  };

  type t = {jwt};
};

module Http = {
  type t = {
    method: string,
    path: string,
    protocol: string,
    sourceIp: string,
    userAgent: string,
  };
};

module RequestContext = {
  type t = {
    accountId: string,
    apiId: string,
    authorizer: option(Authorizer.t),
    domainName: string,
    domainPrefix: string,
    http: Http.t,
    requestId: string,
    routeKey: string,
    stage: string,
    time: string,
    timeEpoch: float,
  };
};

module Event = {
  type t = {
    version: string,
    routeKey: string,
    rawPath: string,
    rawQueryString: string,
    cookies: array(string),
    headers: Js.Dict.t(string),
    queryStringParameters: option(Js.Dict.t(string)),
    requestContext: RequestContext.t,
    body: Js.Json.t,
    pathParameters: option(Js.Dict.t(string)),
    isBase64Encoded: bool,
    stageVariables: option(Js.Dict.t(string)),
  };
};

type handler = (Event.t, Context.t) => Js.Promise.t(Response.t);