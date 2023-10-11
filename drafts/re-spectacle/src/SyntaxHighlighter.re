[@bs.deriving abstract]
type textStyle = {
    [@bs.optional] fontSize: string,
    [@bs.optional] lineHeight: string
};

[@bs.deriving abstract]
type codeStyle = {
    style: textStyle
};


[@bs.module "react-syntax-highlighter"][@react.component]
external make: (~language: string, ~codeTagProps: codeStyle, ~customStyle: textStyle, ~children: React.element) => React.element = "Prism";