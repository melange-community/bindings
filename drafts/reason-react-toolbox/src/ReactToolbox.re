type jsUnsafe;
external toJsUnsafe: 'a => jsUnsafe = "%identity";
let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(b)
  | `Float(f) => toJsUnsafe(f)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `Object(o) => toJsUnsafe(o)
  | `Enum(_) => assert(false);
let optionMap = (fn, option) =>
  switch (option) {
  | Some(value) => Some(fn(value))
  | None => None
  };

module ThemeProvider = {
  type theme;
  [@bs.module "react-css-themr/lib/index"]
  external themeProvider: ReasonReact.reactClass = "ThemeProvider";
  let make = (~theme: theme, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=themeProvider,
      ~props={"theme": theme},
      children,
    );
};
module AppBar = {
  [@bs.module "react-toolbox/lib/app_bar/AppBar"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~fixed: option(bool)=?,
        ~flat: option(bool)=?,
        ~leftIcon: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onLeftIconClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onRightIconClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~rightIcon: option(ReasonReact.reactElement)=?,
        ~scrollHide: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "fixed": Js.Nullable.fromOption(fixed),
        "flat": Js.Nullable.fromOption(flat),
        "leftIcon": Js.Nullable.fromOption(leftIcon),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onLeftIconClick": Js.Nullable.fromOption(onLeftIconClick),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onRightIconClick": Js.Nullable.fromOption(onRightIconClick),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "rightIcon": Js.Nullable.fromOption(rightIcon),
        "scrollHide": Js.Nullable.fromOption(scrollHide),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "title": Js.Nullable.fromOption(title),
      },
      children,
    );
};
module Autocomplete = {
  module Direction = {
    type t =
      | Auto
      | Up
      | Down;
    let to_string =
      fun
      | Auto => "auto"
      | Up => "up"
      | Down => "down";
  };
  module SelectedPosition = {
    type t =
      | Above
      | Below
      | None;
    let to_string =
      fun
      | Above => "above"
      | Below => "below"
      | None => "none";
  };
  module SuggestionMatch = {
    type t =
      | Disabled
      | Start
      | Anywhere
      | Word;
    let to_string =
      fun
      | Disabled => "disabled"
      | Start => "start"
      | Anywhere => "anywhere"
      | Word => "word";
  };
  [@bs.module "react-toolbox/lib/autocomplete/Autocomplete"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~allowCreate: option(bool)=?,
        ~className: option(string)=?,
        ~direction: option(Direction.t)=?,
        ~disabled: option(bool)=?,
        ~error: option(ReasonReact.reactElement)=?,
        ~floating: option(bool)=?,
        ~hint: option(ReasonReact.reactElement)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~keepFocusOnChange: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~maxLength: option(float)=?,
        ~multiline: option(bool)=?,
        ~multiple: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option((ReactEvent.Focus.t, string) => unit)=?,
        ~onChange: option(('value, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyPress: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onQueryChange: option(string => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~required: option(bool)=?,
        ~rows: option(float)=?,
        ~selectedPosition: option(SelectedPosition.t)=?,
        ~showSelectedWhenNotInSource: option(bool)=?,
        ~showSuggestionsWhenValueIsSet: option(bool)=?,
        ~source: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~suggestionMatch: option(SuggestionMatch.t)=?,
        ~theme: option('b)=?,
        ~_type: option(string)=?,
        ~value: option('c)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "allowCreate": Js.Nullable.fromOption(allowCreate),
        "className": Js.Nullable.fromOption(className),
        "direction":
          Js.Nullable.fromOption(optionMap(Direction.to_string, direction)),
        "disabled": Js.Nullable.fromOption(disabled),
        "error": Js.Nullable.fromOption(error),
        "floating": Js.Nullable.fromOption(floating),
        "hint": Js.Nullable.fromOption(hint),
        "icon": Js.Nullable.fromOption(icon),
        "keepFocusOnChange": Js.Nullable.fromOption(keepFocusOnChange),
        "label": Js.Nullable.fromOption(label),
        "maxLength": Js.Nullable.fromOption(maxLength),
        "multiline": Js.Nullable.fromOption(multiline),
        "multiple": Js.Nullable.fromOption(multiple),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onKeyDown": Js.Nullable.fromOption(onKeyDown),
        "onKeyPress": Js.Nullable.fromOption(onKeyPress),
        "onKeyUp": Js.Nullable.fromOption(onKeyUp),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onQueryChange": Js.Nullable.fromOption(onQueryChange),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "required": Js.Nullable.fromOption(required),
        "rows": Js.Nullable.fromOption(rows),
        "selectedPosition":
          Js.Nullable.fromOption(
            optionMap(SelectedPosition.to_string, selectedPosition),
          ),
        "showSelectedWhenNotInSource":
          Js.Nullable.fromOption(showSelectedWhenNotInSource),
        "showSuggestionsWhenValueIsSet":
          Js.Nullable.fromOption(showSuggestionsWhenValueIsSet),
        "source": Js.Nullable.fromOption(source),
        "style": Js.Nullable.fromOption(style),
        "suggestionMatch":
          Js.Nullable.fromOption(
            optionMap(SuggestionMatch.to_string, suggestionMatch),
          ),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(_type),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module Avatar = {
  [@bs.module "react-toolbox/lib/avatar/Avatar"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~cover: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~image: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "cover": Js.Nullable.fromOption(cover),
        "icon": Js.Nullable.fromOption(icon),
        "image": Js.Nullable.fromOption(image),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "title": Js.Nullable.fromOption(title),
      },
      children,
    );
};
module BrowseButton = {
  [@bs.module "react-toolbox/lib/button/BrowseButton"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~flat: option(bool)=?,
        ~floating: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~label: option(string)=?,
        ~mini: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onChange: option(ReactEvent.Form.t => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~primary: option(bool)=?,
        ~raised: option(bool)=?,
        ~ripple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.fromOption(accent),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "flat": Js.Nullable.fromOption(flat),
        "floating": Js.Nullable.fromOption(floating),
        "href": Js.Nullable.fromOption(href),
        "icon": Js.Nullable.fromOption(icon),
        "inverse": Js.Nullable.fromOption(inverse),
        "label": Js.Nullable.fromOption(label),
        "mini": Js.Nullable.fromOption(mini),
        "neutral": Js.Nullable.fromOption(neutral),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "primary": Js.Nullable.fromOption(primary),
        "raised": Js.Nullable.fromOption(raised),
        "ripple": Js.Nullable.fromOption(ripple),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(_type),
      },
      children,
    );
};
module Button = {
  [@bs.module "react-toolbox/lib/button/Button"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~flat: option(bool)=?,
        ~floating: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~label: option(string)=?,
        ~mini: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onRippleEnded: option(ReactEvent.Transition.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~primary: option(bool)=?,
        ~raised: option(bool)=?,
        ~ripple: option(bool)=?,
        ~spread: option(float)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~target: option(string)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.fromOption(accent),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "flat": Js.Nullable.fromOption(flat),
        "floating": Js.Nullable.fromOption(floating),
        "href": Js.Nullable.fromOption(href),
        "icon": Js.Nullable.fromOption(icon),
        "inverse": Js.Nullable.fromOption(inverse),
        "label": Js.Nullable.fromOption(label),
        "mini": Js.Nullable.fromOption(mini),
        "neutral": Js.Nullable.fromOption(neutral),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onRippleEnded": Js.Nullable.fromOption(onRippleEnded),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "primary": Js.Nullable.fromOption(primary),
        "raised": Js.Nullable.fromOption(raised),
        "ripple": Js.Nullable.fromOption(ripple),
        "spread": Js.Nullable.fromOption(spread),
        "style": Js.Nullable.fromOption(style),
        "target": Js.Nullable.fromOption(target),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(_type),
      },
      children,
    );
};
module Card = {
  [@bs.module "react-toolbox/lib/card/Card"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~raised: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "raised": Js.Nullable.fromOption(raised),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module CardActions = {
  [@bs.module "react-toolbox/lib/card/CardActions"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module CardMedia = {
  module AspectRatio = {
    type t =
      | Wide
      | Square;
    let to_string =
      fun
      | Wide => "wide"
      | Square => "square";
  };
  [@bs.module "react-toolbox/lib/card/CardMedia"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~aspectRatio: option(AspectRatio.t)=?,
        ~className: option(string)=?,
        ~color: option(string)=?,
        ~contentOverlay: option(bool)=?,
        ~image: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "aspectRatio":
          Js.Nullable.fromOption(
            optionMap(AspectRatio.to_string, aspectRatio),
          ),
        "className": Js.Nullable.fromOption(className),
        "color": Js.Nullable.fromOption(color),
        "contentOverlay": Js.Nullable.fromOption(contentOverlay),
        "image": Js.Nullable.fromOption(image),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module CardText = {
  [@bs.module "react-toolbox/lib/card/CardText"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module CardTitle = {
  [@bs.module "react-toolbox/lib/card/CardTitle"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~subtitle: option(ReasonReact.reactElement)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(ReasonReact.reactElement)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "avatar": Js.Nullable.fromOption(avatar),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "subtitle": Js.Nullable.fromOption(subtitle),
        "theme": Js.Nullable.fromOption(theme),
        "title": Js.Nullable.fromOption(title),
      },
      children,
    );
};
module Checkbox = {
  [@bs.module "react-toolbox/lib/checkbox/Checkbox"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option((bool, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.fromOption(checked),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "label": Js.Nullable.fromOption(label),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Chip = {
  [@bs.module "react-toolbox/lib/chip/Chip"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~deletable: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDeleteClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "deletable": Js.Nullable.fromOption(deletable),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDeleteClick": Js.Nullable.fromOption(onDeleteClick),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module DatePicker = {
  module Locale = {
    type t =
      | De
      | No
      | En
      | Es
      | Af
      | Ar
      | Be
      | Bg
      | Bn
      | Bo
      | Br
      | Bs
      | Ca
      | Gl
      | Eu
      | Pt
      | It
      | Fr
      | Ru
      | Ua
      | Zh_cn
      | Zh_hk
      | Zh_tw;
    let to_string =
      fun
      | De => "de"
      | No => "no"
      | En => "en"
      | Es => "es"
      | Af => "af"
      | Ar => "ar"
      | Be => "be"
      | Bg => "bg"
      | Bn => "bn"
      | Bo => "bo"
      | Br => "br"
      | Bs => "bs"
      | Ca => "ca"
      | Gl => "gl"
      | Eu => "eu"
      | Pt => "pt"
      | It => "it"
      | Fr => "fr"
      | Ru => "ru"
      | Ua => "ua"
      | Zh_cn => "zh-cn"
      | Zh_hk => "zh-hk"
      | Zh_tw => "zh-tw";
  };
  [@bs.module "react-toolbox/lib/date_picker/DatePicker"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~autoOk: option(bool)=?,
        ~cancelLabel: option(string)=?,
        ~className: option(string)=?,
        ~disabledDates: option(array(Js.Date.t))=?,
        ~enabledDates: option(array(Js.Date.t))=?,
        ~error: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputClassName: option(string)=?,
        ~inputFormat: option(Js.t({..}))=?,
        ~label: option(string)=?,
        ~locale: option([ | `Enum(Locale.t) | `Object(Js.t({..}))])=?,
        ~maxDate: option(Js.Date.t)=?,
        ~minDate: option(Js.Date.t)=?,
        ~name: option(string)=?,
        ~okLabel: option(string)=?,
        ~onChange: option((Js.Date.t, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDismiss: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onEscKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyPress: option(ReactEvent.Keyboard.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~readonly: option(bool)=?,
        ~required: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~sundayFirstDayOfWeek: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option([ | `Date(Js.Date.t) | `String(string)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "autoOk": Js.Nullable.fromOption(autoOk),
        "cancelLabel": Js.Nullable.fromOption(cancelLabel),
        "className": Js.Nullable.fromOption(className),
        "disabledDates": Js.Nullable.fromOption(disabledDates),
        "enabledDates": Js.Nullable.fromOption(enabledDates),
        "error": Js.Nullable.fromOption(error),
        "icon": Js.Nullable.fromOption(icon),
        "inputClassName": Js.Nullable.fromOption(inputClassName),
        "inputFormat": Js.Nullable.fromOption(inputFormat),
        "label": Js.Nullable.fromOption(label),
        "locale":
          Js.Nullable.fromOption(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Locale.to_string(e)))
              | x => unwrapValue(x),
              locale,
            ),
          ),
        "maxDate": Js.Nullable.fromOption(maxDate),
        "minDate": Js.Nullable.fromOption(minDate),
        "name": Js.Nullable.fromOption(name),
        "okLabel": Js.Nullable.fromOption(okLabel),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDismiss": Js.Nullable.fromOption(onDismiss),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onEscKeyDown": Js.Nullable.fromOption(onEscKeyDown),
        "onKeyPress": Js.Nullable.fromOption(onKeyPress),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "readonly": Js.Nullable.fromOption(readonly),
        "required": Js.Nullable.fromOption(required),
        "style": Js.Nullable.fromOption(style),
        "sundayFirstDayOfWeek": Js.Nullable.fromOption(sundayFirstDayOfWeek),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(optionMap(unwrapValue, value)),
      },
      children,
    );
};
module Dialog = {
  module Type = {
    type t =
      | Small
      | Normal
      | Large;
    let to_string =
      fun
      | Small => "small"
      | Normal => "normal"
      | Large => "large";
  };
  [@bs.module "react-toolbox/lib/dialog/Dialog"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~actions: option(array(Js.t({..})))=?,
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onEscKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~title: option(string)=?,
        ~_type: option([ | `Enum(Type.t) | `String(string)])=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "actions": Js.Nullable.fromOption(actions),
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onEscKeyDown": Js.Nullable.fromOption(onEscKeyDown),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "onOverlayMouseDown": Js.Nullable.fromOption(onOverlayMouseDown),
        "onOverlayMouseMove": Js.Nullable.fromOption(onOverlayMouseMove),
        "onOverlayMouseUp": Js.Nullable.fromOption(onOverlayMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "title": Js.Nullable.fromOption(title),
        "type":
          Js.Nullable.fromOption(
            optionMap(
              fun
              | `Enum(e) => unwrapValue(`String(Type.to_string(e)))
              | x => unwrapValue(x),
              _type,
            ),
          ),
      },
      children,
    );
};
module Drawer = {
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/drawer/Drawer"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~insideTree: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~withOverlay: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "insideTree": Js.Nullable.fromOption(insideTree),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
        "withOverlay": Js.Nullable.fromOption(withOverlay),
      },
      children,
    );
};
module Dropdown = {
  [@bs.module "react-toolbox/lib/dropdown/Dropdown"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~allowBlank: option(bool)=?,
        ~auto: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(string)=?,
        ~label: option(string)=?,
        ~labelKey: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option(('value, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~required: option(bool)=?,
        ~source: array('a),
        ~style: option(ReactDOMRe.style)=?,
        ~template: option(Js.t({..}))=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option([ | `String(string) | `Float(float)])=?,
        ~valueKey: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "allowBlank": Js.Nullable.fromOption(allowBlank),
        "auto": Js.Nullable.fromOption(auto),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "error": Js.Nullable.fromOption(error),
        "label": Js.Nullable.fromOption(label),
        "labelKey": Js.Nullable.fromOption(labelKey),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "required": Js.Nullable.fromOption(required),
        "source": source,
        "style": Js.Nullable.fromOption(style),
        "template": Js.Nullable.fromOption(template),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(optionMap(unwrapValue, value)),
        "valueKey": Js.Nullable.fromOption(valueKey),
      },
      children,
    );
};
module FontIcon = {
  [@bs.module "react-toolbox/lib/font_icon/FontIcon"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option(ReasonReact.reactElement)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module IconButton = {
  [@bs.module "react-toolbox/lib/button/IconButton"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~accent: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inverse: option(bool)=?,
        ~neutral: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~primary: option(bool)=?,
        ~ripple: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "accent": Js.Nullable.fromOption(accent),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "href": Js.Nullable.fromOption(href),
        "icon": Js.Nullable.fromOption(icon),
        "inverse": Js.Nullable.fromOption(inverse),
        "neutral": Js.Nullable.fromOption(neutral),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "primary": Js.Nullable.fromOption(primary),
        "ripple": Js.Nullable.fromOption(ripple),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(_type),
      },
      children,
    );
};
module IconMenu = {
  module Position = {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string =
      fun
      | Auto => "auto"
      | Static => "static"
      | TopLeft => "topLeft"
      | TopRight => "topRight"
      | BottomLeft => "bottomLeft"
      | BottomRight => "bottomRight";
  };
  [@bs.module "react-toolbox/lib/menu/IconMenu"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~iconRipple: option(bool)=?,
        ~inverse: option(bool)=?,
        ~menuRipple: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onHide: option(unit => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onSelect: option(ReactEvent.Selection.t => unit)=?,
        ~onShow: option(unit => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~position: option(Position.t)=?,
        ~selectable: option(bool)=?,
        ~selected: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "icon": Js.Nullable.fromOption(icon),
        "iconRipple": Js.Nullable.fromOption(iconRipple),
        "inverse": Js.Nullable.fromOption(inverse),
        "menuRipple": Js.Nullable.fromOption(menuRipple),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onHide": Js.Nullable.fromOption(onHide),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onSelect": Js.Nullable.fromOption(onSelect),
        "onShow": Js.Nullable.fromOption(onShow),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "position":
          Js.Nullable.fromOption(optionMap(Position.to_string, position)),
        "selectable": Js.Nullable.fromOption(selectable),
        "selected": Js.Nullable.fromOption(selected),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Input = {
  [@bs.module "react-toolbox/lib/input/Input"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(ReasonReact.reactElement)=?,
        ~floating: option(bool)=?,
        ~hint: option(ReasonReact.reactElement)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~maxLength: option(float)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option((string, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyPress: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~required: option(bool)=?,
        ~rows: option(float)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~value: option('a)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "error": Js.Nullable.fromOption(error),
        "floating": Js.Nullable.fromOption(floating),
        "hint": Js.Nullable.fromOption(hint),
        "icon": Js.Nullable.fromOption(icon),
        "label": Js.Nullable.fromOption(label),
        "maxLength": Js.Nullable.fromOption(maxLength),
        "multiline": Js.Nullable.fromOption(multiline),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onKeyDown": Js.Nullable.fromOption(onKeyDown),
        "onKeyPress": Js.Nullable.fromOption(onKeyPress),
        "onKeyUp": Js.Nullable.fromOption(onKeyUp),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "required": Js.Nullable.fromOption(required),
        "rows": Js.Nullable.fromOption(rows),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(_type),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module Layout = {
  [@bs.module "react-toolbox/lib/layout/Layout"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Link = {
  [@bs.module "react-toolbox/lib/link/Link"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~count: option(float)=?,
        ~href: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "count": Js.Nullable.fromOption(count),
        "href": Js.Nullable.fromOption(href),
        "icon": Js.Nullable.fromOption(icon),
        "label": Js.Nullable.fromOption(label),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module List = {
  [@bs.module "react-toolbox/lib/list/List"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~ripple: option(bool)=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "ripple": Js.Nullable.fromOption(ripple),
        "selectable": Js.Nullable.fromOption(selectable),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module ListCheckbox = {
  [@bs.module "react-toolbox/lib/list/ListCheckbox"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~caption: option(string)=?,
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~legend: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option(ReactEvent.Form.t => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.fromOption(caption),
        "checked": Js.Nullable.fromOption(checked),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "legend": Js.Nullable.fromOption(legend),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module ListDivider = {
  [@bs.module "react-toolbox/lib/list/ListDivider"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~inset: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "inset": Js.Nullable.fromOption(inset),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module ListItemAction = {
  [@bs.module "react-toolbox/lib/list/ListItemAction"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "action": Js.Nullable.fromOption(action),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module ListItemActions = {
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/list/ListItemActions"]
  external reactClass: ReasonReact.reactClass = "default";
  let make = (~theme: option('a)=?, ~_type: option(Type.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
      },
      children,
    );
};
module ListItemContent = {
  module Type = {
    type t =
      | Auto
      | Normal
      | Large;
    let to_string =
      fun
      | Auto => "auto"
      | Normal => "normal"
      | Large => "large";
  };
  [@bs.module "react-toolbox/lib/list/ListItemContent"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~caption: option(ReasonReact.reactElement)=?,
        ~legend: option(string)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.fromOption(caption),
        "legend": Js.Nullable.fromOption(legend),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
      },
      children,
    );
};
module ListItemLayout = {
  [@bs.module "react-toolbox/lib/list/ListItemLayout"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~avatar:
           option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~caption: option(string)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~itemContent: option(Js.t({..}))=?,
        ~leftActions: option(array(ReasonReact.reactElement))=?,
        ~leftIcon:
           option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~legend: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~rightActions: option(array(ReasonReact.reactElement))=?,
        ~rightIcon:
           option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option('a)=?,
        ~_to: option(string)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "avatar": Js.Nullable.fromOption(optionMap(unwrapValue, avatar)),
        "caption": Js.Nullable.fromOption(caption),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "itemContent": Js.Nullable.fromOption(itemContent),
        "leftActions": Js.Nullable.fromOption(leftActions),
        "leftIcon": Js.Nullable.fromOption(optionMap(unwrapValue, leftIcon)),
        "legend": Js.Nullable.fromOption(legend),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "rightActions": Js.Nullable.fromOption(rightActions),
        "rightIcon":
          Js.Nullable.fromOption(optionMap(unwrapValue, rightIcon)),
        "selectable": Js.Nullable.fromOption(selectable),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "to": Js.Nullable.fromOption(_to),
      },
      children,
    );
};
module ListItemText = {
  [@bs.module "react-toolbox/lib/list/ListItemText"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~primary: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "primary": Js.Nullable.fromOption(primary),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module ListSubHeader = {
  [@bs.module "react-toolbox/lib/list/ListSubHeader"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~caption: option(string)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": Js.Nullable.fromOption(caption),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Menu = {
  module Position = {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string =
      fun
      | Auto => "auto"
      | Static => "static"
      | TopLeft => "topLeft"
      | TopRight => "topRight"
      | BottomLeft => "bottomLeft"
      | BottomRight => "bottomRight";
  };
  [@bs.module "react-toolbox/lib/menu/Menu"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onHide: option(unit => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onSelect: option('value => unit)=?,
        ~onShow: option(unit => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~outline: option(bool)=?,
        ~position: option(Position.t)=?,
        ~ripple: option(bool)=?,
        ~selectable: option(bool)=?,
        ~selected: option('a)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onHide": Js.Nullable.fromOption(onHide),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onSelect": Js.Nullable.fromOption(onSelect),
        "onShow": Js.Nullable.fromOption(onShow),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "outline": Js.Nullable.fromOption(outline),
        "position":
          Js.Nullable.fromOption(optionMap(Position.to_string, position)),
        "ripple": Js.Nullable.fromOption(ripple),
        "selectable": Js.Nullable.fromOption(selectable),
        "selected": Js.Nullable.fromOption(selected),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module MenuDivider = {
  [@bs.module "react-toolbox/lib/menu/MenuDivider"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module MenuItem = {
  [@bs.module "react-toolbox/lib/menu/MenuItem"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~caption: string,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~selected: option(bool)=?,
        ~shortcut: option(string)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option('a)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "caption": caption,
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "icon": Js.Nullable.fromOption(icon),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "selected": Js.Nullable.fromOption(selected),
        "shortcut": Js.Nullable.fromOption(shortcut),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module NavDrawer = {
  module PermanentAt = {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string =
      fun
      | Sm => "sm"
      | SmTablet => "smTablet"
      | Md => "md"
      | Lg => "lg"
      | LgTablet => "lgTablet"
      | Xl => "xl"
      | Xxl => "xxl"
      | Xxxl => "xxxl";
  };
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/layout/NavDrawer"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~clipped: option(bool)=?,
        ~insideTree: option(bool)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~permanentAt: option(PermanentAt.t)=?,
        ~pinned: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~withOverlay: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "clipped": Js.Nullable.fromOption(clipped),
        "insideTree": Js.Nullable.fromOption(insideTree),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "permanentAt":
          Js.Nullable.fromOption(
            optionMap(PermanentAt.to_string, permanentAt),
          ),
        "pinned": Js.Nullable.fromOption(pinned),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
        "withOverlay": Js.Nullable.fromOption(withOverlay),
      },
      children,
    );
};
module Navigation = {
  module Type = {
    type t =
      | Vertical
      | Horizontal;
    let to_string =
      fun
      | Vertical => "vertical"
      | Horizontal => "horizontal";
  };
  [@bs.module "react-toolbox/lib/navigation/Navigation"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~actions: option(array('a))=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~routes: option(array('b))=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "actions": Js.Nullable.fromOption(actions),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "routes": Js.Nullable.fromOption(routes),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
      },
      children,
    );
};
module Overlay = {
  [@bs.module "react-toolbox/lib/overlay/Overlay"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~invisible: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onEscKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "invisible": Js.Nullable.fromOption(invisible),
        "onClick": Js.Nullable.fromOption(onClick),
        "onEscKeyDown": Js.Nullable.fromOption(onEscKeyDown),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Panel = {
  [@bs.module "react-toolbox/lib/layout/Panel"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~bodyScroll: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "bodyScroll": Js.Nullable.fromOption(bodyScroll),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Portal = {
  [@bs.module "react-toolbox/lib/hoc/Portal"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~container: option('a)=?,
        ~lockBody: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "container": Js.Nullable.fromOption(container),
        "lockBody": Js.Nullable.fromOption(lockBody),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
      },
      children,
    );
};
module ProgressBar = {
  module Mode = {
    type t =
      | Determinate
      | Indeterminate;
    let to_string =
      fun
      | Determinate => "determinate"
      | Indeterminate => "indeterminate";
  };
  module Type = {
    type t =
      | Linear
      | Circular;
    let to_string =
      fun
      | Linear => "linear"
      | Circular => "circular";
  };
  [@bs.module "react-toolbox/lib/progress_bar/ProgressBar"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~buffer: option(float)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~max: option(float)=?,
        ~min: option(float)=?,
        ~mode: option(Mode.t)=?,
        ~multicolor: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~value: option(float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "buffer": Js.Nullable.fromOption(buffer),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "max": Js.Nullable.fromOption(max),
        "min": Js.Nullable.fromOption(min),
        "mode": Js.Nullable.fromOption(optionMap(Mode.to_string, mode)),
        "multicolor": Js.Nullable.fromOption(multicolor),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module RadioButton = {
  [@bs.module "react-toolbox/lib/radio/RadioButton"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option(ReactEvent.Form.t => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option('a)=?,
        ~value: option('b)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.fromOption(checked),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "label": Js.Nullable.fromOption(label),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module RadioGroup = {
  [@bs.module "react-toolbox/lib/radio/RadioGroup"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~name: option(string)=?,
        ~onChange: option(string => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~value: option('a)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "name": Js.Nullable.fromOption(name),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module Sidebar = {
  module PermanentAt = {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string =
      fun
      | Sm => "sm"
      | SmTablet => "smTablet"
      | Md => "md"
      | Lg => "lg"
      | LgTablet => "lgTablet"
      | Xl => "xl"
      | Xxl => "xxl"
      | Xxxl => "xxxl";
  };
  module Type = {
    type t =
      | Left
      | Right;
    let to_string =
      fun
      | Left => "left"
      | Right => "right";
  };
  [@bs.module "react-toolbox/lib/layout/Sidebar"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~clipped: option(bool)=?,
        ~insideTree: option(bool)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~permanentAt: option(PermanentAt.t)=?,
        ~pinned: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~_type: option(Type.t)=?,
        ~width: option(float)=?,
        ~withOverlay: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "clipped": Js.Nullable.fromOption(clipped),
        "insideTree": Js.Nullable.fromOption(insideTree),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "permanentAt":
          Js.Nullable.fromOption(
            optionMap(PermanentAt.to_string, permanentAt),
          ),
        "pinned": Js.Nullable.fromOption(pinned),
        "theme": Js.Nullable.fromOption(theme),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
        "width": Js.Nullable.fromOption(width),
        "withOverlay": Js.Nullable.fromOption(withOverlay),
      },
      children,
    );
};
module Slider = {
  [@bs.module "react-toolbox/lib/slider/Slider"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~buffer: option(float)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~editable: option(bool)=?,
        ~max: option(float)=?,
        ~min: option(float)=?,
        ~onChange: option((float, ReactEvent.Focus.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStop: option(unit => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~pinned: option(bool)=?,
        ~snaps: option(bool)=?,
        ~step: option(float)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option(float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "buffer": Js.Nullable.fromOption(buffer),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "editable": Js.Nullable.fromOption(editable),
        "max": Js.Nullable.fromOption(max),
        "min": Js.Nullable.fromOption(min),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDragStop": Js.Nullable.fromOption(onDragStop),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "pinned": Js.Nullable.fromOption(pinned),
        "snaps": Js.Nullable.fromOption(snaps),
        "step": Js.Nullable.fromOption(step),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
module Snackbar = {
  module Type = {
    type t =
      | Accept
      | Cancel
      | Warning;
    let to_string =
      fun
      | Accept => "accept"
      | Cancel => "cancel"
      | Warning => "warning";
  };
  [@bs.module "react-toolbox/lib/snackbar/Snackbar"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~action: option(string)=?,
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~label: option([ | `String(string) | `Object(Js.t({..}))])=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTimeout: option(unit => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        ~timeout: option(float)=?,
        ~_type: option(Type.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "action": Js.Nullable.fromOption(action),
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "label": Js.Nullable.fromOption(optionMap(unwrapValue, label)),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTimeout": Js.Nullable.fromOption(onTimeout),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
        "timeout": Js.Nullable.fromOption(timeout),
        "type": Js.Nullable.fromOption(optionMap(Type.to_string, _type)),
      },
      children,
    );
};
module Switch = {
  [@bs.module "react-toolbox/lib/switch/Switch"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~checked: option(bool)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~label: option(string)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReactEvent.Focus.t => unit)=?,
        ~onChange: option((bool, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onFocus: option(ReactEvent.Focus.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.fromOption(checked),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "label": Js.Nullable.fromOption(label),
        "name": Js.Nullable.fromOption(name),
        "onBlur": Js.Nullable.fromOption(onBlur),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onFocus": Js.Nullable.fromOption(onFocus),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Tab = {
  [@bs.module "react-toolbox/lib/tabs/Tab"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~activeClassName: option(string)=?,
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~hidden: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(string)=?,
        ~onActive: option(unit => unit)=?,
        ~onClick: option((ReactEvent.Mouse.t, float) => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "activeClassName": Js.Nullable.fromOption(activeClassName),
        "className": Js.Nullable.fromOption(className),
        "disabled": Js.Nullable.fromOption(disabled),
        "hidden": Js.Nullable.fromOption(hidden),
        "icon": Js.Nullable.fromOption(icon),
        "label": Js.Nullable.fromOption(label),
        "onActive": Js.Nullable.fromOption(onActive),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module TabContent = {
  [@bs.module "react-toolbox/lib/tabs/TabContent"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~tabIndex: option(float)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "className": Js.Nullable.fromOption(className),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "tabIndex": Js.Nullable.fromOption(tabIndex),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Table = {
  [@bs.module "react-toolbox/lib/table/Table"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~multiSelectable: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onRowSelect: option(array(float => unit))=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~selectable: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "multiSelectable": Js.Nullable.fromOption(multiSelectable),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onRowSelect": Js.Nullable.fromOption(onRowSelect),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "selectable": Js.Nullable.fromOption(selectable),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module TableCell = {
  module Sorted = {
    type t =
      | Asc
      | Desc;
    let to_string =
      fun
      | Asc => "asc"
      | Desc => "desc";
  };
  module TagName = {
    type t =
      | Td
      | Th;
    let to_string =
      fun
      | Td => "td"
      | Th => "th";
  };
  [@bs.module "react-toolbox/lib/table/TableCell"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~column: option(float)=?,
        ~numeric: option(bool)=?,
        ~onClick: option((ReactEvent.Mouse.t, float, float) => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~row: option(float)=?,
        ~sorted: option(Sorted.t)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~tagName: option(TagName.t)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "column": Js.Nullable.fromOption(column),
        "numeric": Js.Nullable.fromOption(numeric),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "row": Js.Nullable.fromOption(row),
        "sorted":
          Js.Nullable.fromOption(optionMap(Sorted.to_string, sorted)),
        "style": Js.Nullable.fromOption(style),
        "tagName":
          Js.Nullable.fromOption(optionMap(TagName.to_string, tagName)),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module TableHead = {
  [@bs.module "react-toolbox/lib/table/TableHead"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~displaySelect: option(bool)=?,
        ~multiSelectable: option(bool)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onSelect: option((bool, ReactEvent.Mouse.t) => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~selectable: option(bool)=?,
        ~selected: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "displaySelect": Js.Nullable.fromOption(displaySelect),
        "multiSelectable": Js.Nullable.fromOption(multiSelectable),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onSelect": Js.Nullable.fromOption(onSelect),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "selectable": Js.Nullable.fromOption(selectable),
        "selected": Js.Nullable.fromOption(selected),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module TableRow = {
  [@bs.module "react-toolbox/lib/table/TableRow"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~idx: option(float)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onSelect: option((float, bool) => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~selectable: option(bool)=?,
        ~selected: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "idx": Js.Nullable.fromOption(idx),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onSelect": Js.Nullable.fromOption(onSelect),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "selectable": Js.Nullable.fromOption(selectable),
        "selected": Js.Nullable.fromOption(selected),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module Tabs = {
  module HideMode = {
    type t =
      | Display
      | Unmounted;
    let to_string =
      fun
      | Display => "display"
      | Unmounted => "unmounted";
  };
  [@bs.module "react-toolbox/lib/tabs/Tabs"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableAnimatedBottomBorder: option(bool)=?,
        ~fixed: option(bool)=?,
        ~hideMode: option(HideMode.t)=?,
        ~index: option(float)=?,
        ~inverse: option(bool)=?,
        ~onChange: option(float => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onContextMenu: option(ReactEvent.Mouse.t => unit)=?,
        ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrag: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragExit: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onDragStart: option(ReactEvent.Mouse.t => unit)=?,
        ~onDrop: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOut: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseOver: option(ReactEvent.Mouse.t => unit)=?,
        ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
        ~onTouchCancel: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
        ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
        ~style: option(ReactDOMRe.style)=?,
        ~theme: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.fromOption(className),
        "disableAnimatedBottomBorder":
          Js.Nullable.fromOption(disableAnimatedBottomBorder),
        "fixed": Js.Nullable.fromOption(fixed),
        "hideMode":
          Js.Nullable.fromOption(optionMap(HideMode.to_string, hideMode)),
        "index": Js.Nullable.fromOption(index),
        "inverse": Js.Nullable.fromOption(inverse),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onContextMenu": Js.Nullable.fromOption(onContextMenu),
        "onDoubleClick": Js.Nullable.fromOption(onDoubleClick),
        "onDrag": Js.Nullable.fromOption(onDrag),
        "onDragEnd": Js.Nullable.fromOption(onDragEnd),
        "onDragEnter": Js.Nullable.fromOption(onDragEnter),
        "onDragExit": Js.Nullable.fromOption(onDragExit),
        "onDragLeave": Js.Nullable.fromOption(onDragLeave),
        "onDragOver": Js.Nullable.fromOption(onDragOver),
        "onDragStart": Js.Nullable.fromOption(onDragStart),
        "onDrop": Js.Nullable.fromOption(onDrop),
        "onMouseDown": Js.Nullable.fromOption(onMouseDown),
        "onMouseEnter": Js.Nullable.fromOption(onMouseEnter),
        "onMouseLeave": Js.Nullable.fromOption(onMouseLeave),
        "onMouseMove": Js.Nullable.fromOption(onMouseMove),
        "onMouseOut": Js.Nullable.fromOption(onMouseOut),
        "onMouseOver": Js.Nullable.fromOption(onMouseOver),
        "onMouseUp": Js.Nullable.fromOption(onMouseUp),
        "onTouchCancel": Js.Nullable.fromOption(onTouchCancel),
        "onTouchEnd": Js.Nullable.fromOption(onTouchEnd),
        "onTouchMove": Js.Nullable.fromOption(onTouchMove),
        "onTouchStart": Js.Nullable.fromOption(onTouchStart),
        "style": Js.Nullable.fromOption(style),
        "theme": Js.Nullable.fromOption(theme),
      },
      children,
    );
};
module TimePicker = {
  module Format = {
    type t =
      | V_24hr
      | Ampm;
    let to_string =
      fun
      | V_24hr => "24hr"
      | Ampm => "ampm";
  };
  [@bs.module "react-toolbox/lib/time_picker/TimePicker"]
  external reactClass: ReasonReact.reactClass = "default";
  let make =
      (
        ~active: option(bool)=?,
        ~cancelLabel: option(string)=?,
        ~error: option(string)=?,
        ~format: option(Format.t)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputClassName: option(string)=?,
        ~label: option(string)=?,
        ~okLabel: option(string)=?,
        ~onChange: option((Js.Date.t, ReactEvent.Mouse.t) => unit)=?,
        ~onClick: option(ReactEvent.Mouse.t => unit)=?,
        ~onDismiss: option(ReactEvent.Mouse.t => unit)=?,
        ~onEscKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
        ~onKeyPress: option(ReactEvent.Keyboard.t => unit)=?,
        ~onOverlayClick: option(ReactEvent.Mouse.t => unit)=?,
        ~readonly: option(bool)=?,
        ~theme: option(Js.t({..}))=?,
        ~value: option(Js.Date.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.fromOption(active),
        "cancelLabel": Js.Nullable.fromOption(cancelLabel),
        "error": Js.Nullable.fromOption(error),
        "format":
          Js.Nullable.fromOption(optionMap(Format.to_string, format)),
        "icon": Js.Nullable.fromOption(icon),
        "inputClassName": Js.Nullable.fromOption(inputClassName),
        "label": Js.Nullable.fromOption(label),
        "okLabel": Js.Nullable.fromOption(okLabel),
        "onChange": Js.Nullable.fromOption(onChange),
        "onClick": Js.Nullable.fromOption(onClick),
        "onDismiss": Js.Nullable.fromOption(onDismiss),
        "onEscKeyDown": Js.Nullable.fromOption(onEscKeyDown),
        "onKeyPress": Js.Nullable.fromOption(onKeyPress),
        "onOverlayClick": Js.Nullable.fromOption(onOverlayClick),
        "readonly": Js.Nullable.fromOption(readonly),
        "theme": Js.Nullable.fromOption(theme),
        "value": Js.Nullable.fromOption(value),
      },
      children,
    );
};
