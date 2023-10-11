![Reason Cookie Logo](https://raw.githubusercontent.com/justgage/reason-cookie/master/logo.png)

#  🍪 ReasonCookie

A simple way to use cross-browser cookies that contain JSON.

Note this wraps [js-cookie](https://github.com/js-cookie/js-cookie)

# Is it ready for prime time?

These are just some simple bindings to the library it wraps. I've used it on some side projects but it should be _reasonably_ good. The underlying library is pretty battle tested and can even work in older browsers.

# Install

```
npm install --save @justgage/reason-cookie
```

Then in your `bsconfig.json`.

```
  "bs-dependencies": ["@justgage/reason-cookie"],
```

# API 😋

### Working with string values

```reason
open JustgageReasonCookie;

Cookie.getAsString("hello") /* None */
Cookie.setString("hello", "test");
Cookie.getAsString("hello") /* Some("test") */
```

### Working with JSON

```reason
open JustgageReasonCookie;

let obj = Js.Dict.empty();
Js.Dict.set(obj, "a", Js.Json.number(2.));
let obj = Js.Json.object_(obj);

Cookie.setJson("hello", obj);

let maybeCookie = Cookie.getAsJson("hello");
```

### Set path/expiry

* **expires**: number of days till it's gone.
* **path**: this scopes it to a page on your website (note: haven't used this personally)

(see [js-cookie](https://github.com/js-cookie/js-cookie) for more uses)

```reason
open JustgageReasonCookie;

Cookie.setJsonConfig(
  "hello",
  obj,
  Cookie.makeConfig(~path="", ~expires=2, ()),
);
```

# Contribute?

Best thing somone can do is just use it and find any problems it has.

Absolutely! Just make an issue. Please note that I usually ask people to make the changes themselves.
