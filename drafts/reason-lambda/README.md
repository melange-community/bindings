# Reason-Lambda

`reason-lambda` is a set of bindings for AWS Lambda handlers. 
It makes use of Bucklescript 7 representation of records as JS objects. 
It includes bindings for both [v1 and v2 of lambda payloads](https://docs.aws.amazon.com/apigateway/latest/developerguide/http-api-develop-integrations-lambda.html).

## Install
```
yarn add @tsnobip/reason-lambda
```
And add `@tsnobip/reason-lambda` to the `bs-dependencies` of `bsconfig.json`.

## Usage

```reason
open ReasonLambda.V2;
type greetings = {greetings: string};
let handler: handler =
  (_event, _context) =>
    {greetings: "Hello world!"}->Response.fromBody->Js.Promise.resolve;
```

You can see a working example with the Serverless framework [here](https://github.com/tsnobip/reason-sls-example).