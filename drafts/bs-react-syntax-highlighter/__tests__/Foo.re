[@react.component]
let make = (~style=ReactDOMRe.Style.make(()), ~children) => {
    <span style>{children}</span>
};

module Jsx2 = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make =
    (
      ~style=?,
      children,
    ) => ReasonReactCompat.wrapReactForReasonReact(
      make,
      makeProps(
        ~style?,
        ~children,
        (),
      ),
      children,
    );
};