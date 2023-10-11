open Jest;
open ExpectJs;

describe("js", () => {
  let bsBeautify = JsBeautify.js;
  let jsBeautify = (code) => [%bs.raw "require('js-beautify').js(code)"];
  let jsBeautifyWithOptions = (code, options) => [%bs.raw "require('js-beautify').js(code, options)"];

  test("no options", () => {
    let code = "if(window.x){console.log('It is x');}else{console.log('It is not');}";
    let bsResult = bsBeautify(code);
    let jsResult = jsBeautify(code);

    expect(bsResult) |> toEqual(jsResult)
  });

  test("basic options", () => {
    let code = "if(window.x){console.log('It is x');}else{console.log('It is not');}";
    let bsResult = bsBeautify(~indent_size=4, ~indent_char="_", code);
    let jsResult = jsBeautifyWithOptions(code, [%bs.raw "{ indent_size: 4, indent_char: '_' }"]);

    expect(bsResult) |> toEqual(jsResult)
  });

  test("complex options", () => {
    let code = "if(window.x)\n{console.log('It is x');}\nelse\n{console.log('It is not');}";
    let bsResult = bsBeautify(~brace_style=`expand, ~operator_position=`preserveNewline, code);
    let jsResult = jsBeautifyWithOptions(code, [%bs.raw "{
      brace_style: 'expand',
      operator_position: 'preserve-newline'
    }"]);

    expect(bsResult) |> toEqual(jsResult)
  });
});
