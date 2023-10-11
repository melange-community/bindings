open Jest;
open ExpectJs;

describe("css", () => {
  let bsBeautify = JsBeautify.css;
  let jsBeautify = (code) => [%bs.raw "require('js-beautify').css(code)"];
  let jsBeautifyWithOptions = (code, options) => [%bs.raw "require('js-beautify').css(code, options)"];

  test("no options", () => {
    let code = "div>.foo    [bar=baz]{color:#fff;display:block} span:after{content:attr(bar)}";
    let bsResult = bsBeautify(code);
    let jsResult = jsBeautify(code);

    expect(bsResult) |> toEqual(jsResult)
  });

  test("basic options", () => {
    let code = "div>.foo    [bar=baz]{color:#fff;display:block} span:after{content:attr(bar)}";
    let bsResult = bsBeautify(~indent_size=4, ~newline_between_rules=true, code);
    let jsResult = jsBeautifyWithOptions(code, [%bs.raw "{ indent_size: 4, newline_between_rules: true }"]);

    expect(bsResult) |> toEqual(jsResult)
  });
});
