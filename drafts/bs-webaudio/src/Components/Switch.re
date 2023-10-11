let width = 40;
let height = 20;
let sizeInPixels = (x: int) => string_of_int(x) ++ "px";

[@react.component]
let make = (~isOn: bool, ~toggle: unit => unit, ~children) => {
  <div className="control-container">
    <h4 className="control-label"> children </h4>
    <div
      onClick={_ => toggle()}
      style={ReactDOMRe.Style.make(
        ~backgroundColor=ColorPalette.black,
        ~width=sizeInPixels(width),
        ~height=sizeInPixels(height),
        ~margin="10px 20px",
        (),
      )}>
      <div
        style={ReactDOMRe.Style.make(
          ~backgroundColor=ColorPalette.silver,
          ~border="1px solid " ++ ColorPalette.white,
          ~width=sizeInPixels(width / 2),
          ~height=sizeInPixels(height),
          ~transform=
            "translateX(" ++ (isOn ? sizeInPixels(width / 2) : "0") ++ ")",
          ~transition="transform 0.2s",
          (),
        )}
      />
    </div>
  </div>;
};
