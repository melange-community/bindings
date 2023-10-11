open Jest;

describe("Cookie", () => {
  open Expect;
  test(".setString can set a cookie", () => {
    Cookie.setString("hello", "test");
    Cookie.getAsString("hello")
    |> Belt.Option.getWithDefault(_, "")
    |> expect
    |> toBe("test");
  });
  test(".getAsString can get stuff stored by setStringConfig", () => {
    Cookie.setStringConfig(
      "foo",
      "bar",
      Cookie.makeConfig(~path="", ~expires=2, ()),
    );
    /* Note that it doesn't actualy test the expires, not sure how */
    Cookie.getAsString("foo") |> expect |> toEqual(Some("bar"));
  });
  test(".remove can remove a cookie", () => {
    Cookie.setString("hello", "test");
    Cookie.remove("hello");
    Cookie.getAsString("hello") |> expect |> toBe(None);
  });
  test(".getAsJson can get some Json", () => {
    Cookie.setString("hello", {js|{"a": 2}|js});
    let obj = Js.Dict.empty();
    Js.Dict.set(obj, "a", Js.Json.number(2.));
    Cookie.getAsJson("hello")
    |> expect
    |> toEqual(Some(Js.Json.object_(obj)));
  });
  test(".getAsJson can get stuff stored by setJson", () => {
    let obj = Js.Dict.empty();
    Js.Dict.set(obj, "a", Js.Json.number(2.));
    let obj = Js.Json.object_(obj);
    Cookie.setJson("hello", obj);
    Cookie.getAsJson("hello") |> expect |> toEqual(Some(obj));
  });
  test(".getAsJson can get stuff stored by setJsonConfig", () => {
    let obj = Js.Dict.empty();
    Js.Dict.set(obj, "a", Js.Json.number(2.));
    let obj = Js.Json.object_(obj);
    Cookie.setJsonConfig(
      "hello",
      obj,
      Cookie.makeConfig(~path="", ~expires=2, ()),
    );
    /* Note that it doesn't actualy test the expires, not sure how */
    Cookie.getAsJson("hello") |> expect |> toEqual(Some(obj));
  });
  test(".getAsJson will return None", () => {
    Cookie.remove("hello");
    Cookie.getAsJson("hello") |> expect |> toEqual(None);
  });
});