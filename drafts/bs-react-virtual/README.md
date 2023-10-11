# bs-react-virtual

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [react-virtual](https://github.com/tannerlinsley/react-virtual)

![Build](https://github.com/tatchi/bs-react-virtual/workflows/Build/badge.svg)

## Installation

```sh
npm install --save @tatchi/bs-react-virtual
```

Then add `@tatchi/bs-react-virtual` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["@tatchi/bs-react-virtual"]
}
```

## Example

```reason
[@react.component]
let make = () => {
  let parentRef = React.useRef(Js.Nullable.null);

  let rowVirtualizer =
    ReactVirtual.useVirtual(
      ReactVirtual.options(
        ~size=10000,
        ~parentRef,
        ~estimateSize=React.useCallback0(_ => 35),
        ~scrollToFn=(offset, defaultScrollToFn) => defaultScrollToFn(offset),
        (),
      ),
    );

  <div>
    <button
      onClick={_ =>
        rowVirtualizer.scrollToIndex(.
          ~index=0,
          ~options=Some({align: ReactVirtual.Align.auto}),
        )
      }>
      {React.string("ScrollToIndex")}
    </button>
    <button
      onClick={_ =>
        rowVirtualizer.scrollToOffset(. ~offset=100, ~options=None)
      }>
      {React.string("ScrollToOffset")}
    </button>
    <div
      ref={ReactDOMRe.Ref.domRef(parentRef)}
      style={ReactDOMRe.Style.make(
        ~height="150px",
        ~width="300px",
        ~overflow="auto",
        (),
      )}>
      <div
        style={ReactDOMRe.Style.make(
          ~height={string_of_int(rowVirtualizer.totalSize) ++ "px"},
          ~width="100%",
          ~position="relative",
          (),
        )}>
        {rowVirtualizer.virtualItems
         ->Belt.Array.map(virtualRow =>
             <div
               ref={ReactDOMRe.Ref.domRef(virtualRow.measureRef)}
               key={string_of_int(virtualRow.index)}
               style={ReactDOMRe.Style.make(
                 ~position="absolute",
                 ~top="0px",
                 ~left="0px",
                 ~width="100%",
                 ~height={string_of_int(virtualRow.size) ++ "px"},
                 ~transform=
                   {"translateY(" ++ string_of_int(virtualRow.start) ++ "px)"},
                 (),
               )}>
               {React.string("Row " ++ string_of_int(virtualRow.index))}
             </div>
           )
         ->ReasonReact.array}
      </div>
    </div>
  </div>;
};
```
