open Jest;
open ExpectJs;

describe("html", () => {
  let bsBeautify = JsBeautify.html;
  let jsBeautify = (code) => [%bs.raw "require('js-beautify').html(code)"];
  let jsBeautifyWithOptions = (code, options) => [%bs.raw "require('js-beautify').html(code, options)"];

  test("no options", () => {
    let code = "<div>foo <strong>bar</strong></div><ul><li><em>an item</em></li></ul>";
    let bsResult = bsBeautify(code);
    let jsResult = jsBeautify(code);

    expect(bsResult) |> toEqual(jsResult)
  });

  test("basic options", () => {
    let code = "<div>foo <strong>bar</strong></div><ul><li><em>an item</em></li></ul>";
    let bsResult = bsBeautify(~indent_size=4, ~indent_char="_", code);
    let jsResult = jsBeautifyWithOptions(code, [%bs.raw "{ indent_size: 4, indent_char: '_' }"]);

    expect(bsResult) |> toEqual(jsResult)
  });

  test("complex options", () => {
    let code = "<img src=http://example.com/image.jpg alt=Example image />";
    let bsResult = bsBeautify(~brace_style=`expand, ~wrap_attributes=`forceExpandMultiline, code);
    let jsResult = jsBeautifyWithOptions(code, [%bs.raw "{
      brace_style: 'expand',
      wrap_attributes: 'force-expand-multiline'
    }"]);

    expect(bsResult) |> toEqual(jsResult)
  });
});
