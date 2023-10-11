# bs-jsonwebtoken
A small library for interacting with the jsonwebtoken npm package.

## Status
The package is in an extremely early state however there's really only 3 functions you want, `sign`, `decode`, and `verify`, and the bindings for those functions are present and should work as they would in a javascript project. I want to provide better types for the actual options for `decode` and `verify` later but the options record for `sign` should allow you to do everything you would in javascript land.


## Example

```reason
open JsonWebToken;
open Json_encode;


// emptyOptions is provided to allow you to set only the options you care about
let signingOptions = Some({ ...emptyOptions, algorithm: HS256, notBefore: "2 days"});

// allows for you to provide a string, buffer, jsonewebtoken secret object 
let secret = `string("secret");

type testPayload = {
  foo: string
};

let encodeTestPayload = (payload: testPayload) => {
  object_([("foo", string(payload.foo))]);
};

// it's expected that you will json encode your payload before passing it in to sign
// I recommend using @glennsl/bs-json to do your json encoding as I have here
let testPayload = { foo: "bar"};
let payload = `json(encodeTestPayload(testPayload));

let jwtToken = sign(~secret, ~options, payload);

// Verify the token with your secret and recieve the json typed token
// if your token uses a public/private key pair this will also take the public key
// results from both verify and decode require you to json decode,
// again @glennsl/bs-json can handle this.
let payloadFromVerify = verify(jwtToken, secret)

// Decod the token if already verified.
let payloadFromDecode = decode(jwtToekn)

```

## Installation

```sh
npm i @beem812/bs-jsonwebtoken
```

Then add `@beem812/bs-jsonwebtokent` to `bs-dependencies` in your `bsconfig.json`:
```js
{
  ...
  "bs-dependencies": ["@beem812/bs-jsonwebtoken"]
}
```
