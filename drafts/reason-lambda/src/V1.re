/**
   Type definitions for AWS Lambda v1 Payload
   http://docs.aws.amazon.com/lambda
   https://docs.aws.amazon.com/apigateway/latest/developerguide/http-api-develop-integrations-lambda.html
 */
module Response = {
  type t;

  [@bs.obj]
  external make:
    (
      ~isBase64Encoded: bool=?,
      ~statusCode: int,
      ~headers: Js.Dict.t(string)=?,
      ~multiValueHeaders: Js.Dict.t(array(string))=?,
      ~body: string=?,
      unit
    ) =>
    t;
};

module Context = Common.Context;

type httpMethod = string;

module Identity = {
  type t = {
    accessKey: Js.nullable(string),
    accountId: Js.nullable(string),
    caller: Js.nullable(string),
    cognitoAuthenticationProvider: Js.nullable(string),
    cognitoAuthenticationType: Js.nullable(string),
    cognitoIdentityId: Js.nullable(string),
    cognitoIdentityPoolId: Js.nullable(string),
    principalOrgId: Js.nullable(string),
    sourceIp: string,
    user: Js.nullable(string),
    userAgent: string,
    userArn: Js.nullable(string),
  };
};

module RequestContext = {
  type t = {
    accountId: string,
    apiId: string,
    domainName: string,
    domainPrefix: string,
    extendedRequestId: string,
    httpMethod,
    identity: Identity.t,
    path: string,
    protocol: string,
    requestId: string,
    requestTime: string,
    requestTimeEpoch: float,
    resourceId: string,
    resourcePath: string,
    stage: string,
  };
};

module Event = {
  type t = {
    version: string,
    resource: string,
    path: string,
    httpMethod,
    headers: Js.Dict.t(string),
    multiValueHeaders: Js.Dict.t(array(string)),
    queryStringParameters: Js.nullable(Js.Dict.t(string)),
    multiValueQueryStringParameters: Js.nullable(Js.Dict.t(array(string))),
    requestContex: RequestContext.t,
    pathParameters: Js.nullable(Js.Dict.t(string)),
    stageVariables: Js.nullable(Js.Dict.t(string)),
    body: Js.Json.t,
    isBase64Encoded: bool,
  };
};

type handler = (Event.t, Context.t) => Js.Promise.t(Response.t);