open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("jsx3", () => {
  test("empty", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs>
      {""}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { },
        '')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("language", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs language={`JavaScript}>
      {"const foo = () => {};"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { language: 'javascript' },
        'const foo = () => {};')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("style", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs style={ReactSyntaxHighlighter.Hljs.Style.darcula}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { style: require('react-syntax-highlighter/dist/esm/styles/hljs').darcula },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("renderer", () => {
    let renderer: ReactSyntaxHighlighter.Hljs.Renderer.t = (input) => {
      let theFirstRow = input##rows[0];
      let theFirstElement = theFirstRow##children[0];
      let textNode = theFirstElement##children[0];
      let text = textNode##value;

      text |> React.string;
    };
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs renderer>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    ) |> Enzyme.shallow;
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { renderer: (props) => props.rows[0].children[0].children[0].value },
        'foobar')
    "] |> Enzyme.shallow;

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("pre tag as intrinsic", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs _PreTag={`intrinsic("span")}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { PreTag: 'span' },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("pre tag as component", () => {
    let fn = (props) => {
      <Foo style={props##style}>props##children</Foo>
    };
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs _PreTag={`component(fn)}>
      ...{"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { PreTag: fn },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  test("className", () => {
    let reasonComponent = (
      <ReactSyntaxHighlighter.Hljs className={"foo"}>
      {"foobar"}
      </ReactSyntaxHighlighter.Hljs>
    );
    let jsComponent = [%bs.raw "
      require('react').createElement(
        require('react-syntax-highlighter').default,
        { className: 'foo' },
        'foobar')
    "];

    expect(reasonComponent) |> toEqual(jsComponent);
  });

  describe("line props", () => {
    test("plain object", () => {
      let props = `Plain(ReactDOMRe.props(~className="foobar", ()));
      let reasonComponent = (
        <ReactSyntaxHighlighter.Hljs lineProps={props} wrapLines={true}>
        {"foobar"}
        </ReactSyntaxHighlighter.Hljs>
      ) |> Enzyme.shallow;
      let jsComponent = [%bs.raw "
        require('react').createElement(
          require('react-syntax-highlighter').default,
          { lineProps: { className: 'foobar' }, wrapLines: true },
          'foobar')
      "] |> Enzyme.shallow;

      expect(reasonComponent) |> toEqual(jsComponent);
    });

    test("function object", () => {
      let props = `Factory((ln) => ReactDOMRe.props(~className="foobar_" ++ string_of_int(ln), ()));
      let reasonComponent = (
        <ReactSyntaxHighlighter.Hljs lineProps={props} wrapLines={true}>
        {"foobar"}
        </ReactSyntaxHighlighter.Hljs>
      ) |> Enzyme.shallow;
      let jsComponent = [%bs.raw "
        require('react').createElement(
          require('react-syntax-highlighter').default,
          { lineProps: (ln) => ({ className: 'foobar_' + ln }), wrapLines: true },
          'foobar')
      "] |> Enzyme.shallow;

      expect(reasonComponent) |> toEqual(jsComponent);
    });
  });
});
