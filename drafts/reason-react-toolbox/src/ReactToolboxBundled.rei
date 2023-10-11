module AppBar: {
  /*** Component AppBar
       @param className Set a class for the root component.
       @param fixed Determine if the bar should have position fixed or relative.
       @param flat If true, the AppBar doesn't show a shadow.
       @param leftIcon If it exists it is used as the AppBar left icon
       @param onClick Callback called when the component is clicked.
       @param onLeftIconClick Called when the left icon is clicked
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onRightIconClick Called when the righticon is clicked
       @param rightIcon If it exists it is used as the AppBar right icon
       @param scrollHide Whether AppBar should be hidden during scroll.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param title If it exists it is used as the AppBar title */
  let make:
    (
      ~className: string=?,
      ~fixed: bool=?,
      ~flat: bool=?,
      ~leftIcon: ReasonReact.reactElement=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onLeftIconClick: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onRightIconClick: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~rightIcon: ReasonReact.reactElement=?,
      ~scrollHide: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~title: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Autocomplete: {
  module Direction: {
    type t =
      | Auto
      | Up
      | Down;
    let to_string: t => string;
  };
  module SelectedPosition: {
    type t =
      | Above
      | Below
      | None;
    let to_string: t => string;
  };
  module SuggestionMatch: {
    type t =
      | Disabled
      | Start
      | Anywhere
      | Word;
    let to_string: t => string;
  };
  /*** Component Autocomplete
       @param allowCreate Determines if user can create a new option with the current typed value.
       @param className Set a class for the root component.
       @param direction Determines the opening direction. It can be auto, up or down.
       @param disabled If true, component will be disabled.
       @param error Sets the error string for the internal input element.
       @param floating Indicates if the label is floating in the input field or not.
       @param hint The text string to use for hint text element.
       @param icon Name of an icon to use as a label for the input.
       @param keepFocusOnChange Whether component should keep focus after value change.
       @param label The text string to use for the floating label element.
       @param maxLength Specifies the maximum number of characters allowed in the component
       @param multiline If true, a textarea element will be rendered. The textarea also grows and shrinks according to the number of lines.
       @param multiple If true, component can hold multiple values.
       @param name Name for the input field.
       @param onBlur Callback function that is fired when component is blurred.
       @param onChange Callback function that is fired when the components's value changes.
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback function that is fired when component is focused.
       @param onKeyDown Callback function that is fired when a key is pressed down.
       @param onKeyPress Callback function that is fired when a key is pressed.
       @param onKeyUp Callback function that is fired when a key is lifted up.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onQueryChange Callback function that is fired when the components's query value changes.
       @param required If true, the html input has a required attribute.
       @param rows The number of rows the multiline input field has.
       @param selectedPosition Determines if the selected list is shown above or below input. It can be above or below.
       @param showSelectedWhenNotInSource Determines if the selected list is shown if the `value` keys don't exist in the source. Only works if passing the `value` prop as an Object.
       @param showSuggestionsWhenValueIsSet If true, the list of suggestions will not be filtered when a value is selected.
       @param source Object of key/values or array representing all items suggested.
       @param style Set inline style for the root component.
       @param suggestionMatch Determines how suggestions are supplied.
       @param theme Classnames object defining the component style.
       @param type Type of the input element. It can be a valid HTML5 input type.
       @param value Value or array of values currently selected component. */
  let make:
    (
      ~allowCreate: bool=?,
      ~className: string=?,
      ~direction: Direction.t=?,
      ~disabled: bool=?,
      ~error: ReasonReact.reactElement=?,
      ~floating: bool=?,
      ~hint: ReasonReact.reactElement=?,
      ~icon: ReasonReact.reactElement=?,
      ~keepFocusOnChange: bool=?,
      ~label: ReasonReact.reactElement=?,
      ~maxLength: float=?,
      ~multiline: bool=?,
      ~multiple: bool=?,
      ~name: string=?,
      ~onBlur: (ReactEvent.Focus.t, string) => unit=?,
      ~onChange: ('value, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onQueryChange: string => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~required: bool=?,
      ~rows: float=?,
      ~selectedPosition: SelectedPosition.t=?,
      ~showSelectedWhenNotInSource: bool=?,
      ~showSuggestionsWhenValueIsSet: bool=?,
      ~source: 'a=?,
      ~style: ReactDOMRe.style=?,
      ~suggestionMatch: SuggestionMatch.t=?,
      ~theme: 'b=?,
      ~_type: string=?,
      ~value: 'c=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Avatar: {
  /*** Component Avatar
       @param className Set a class for the root component.
       @param cover Set to true if your image is not squared so it will be used as a cover for the element.
       @param icon A key to identify an Icon from Material Design Icons or a custom Icon Element.
       @param image An image source or an image element.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param title A title for the image. If no image is provided, the first letter will be displayed as the avatar. */
  let make:
    (
      ~className: string=?,
      ~cover: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~image: ReasonReact.reactElement=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~title: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module BrowseButton: {
  /*** Component BrowseButton
       @param accent Indicates if the button should have accent color.
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param flat If true, the button will have a flat look.
       @param floating If true, the button will have a floating look.
       @param href Creates a link for the button.
       @param icon Value of the icon (See Font Icon Component).
       @param inverse If true, the neutral colors are inverted. Useful to put a button over a dark background.
       @param label The text string to use for the name of the button.
       @param mini To be used with floating button. If true, the button will be smaller.
       @param neutral Set it to false if you don't want the neutral styles to be included.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Fires after the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param primary Indicates if the button should have primary color.
       @param raised If true, the button will have a raised look.
       @param ripple If true, component will have a ripple effect on click.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Component root container type. */
  let make:
    (
      ~accent: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~flat: bool=?,
      ~floating: bool=?,
      ~href: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~inverse: bool=?,
      ~label: string=?,
      ~mini: bool=?,
      ~neutral: bool=?,
      ~onChange: ReactEvent.Form.t => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~primary: bool=?,
      ~raised: bool=?,
      ~ripple: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Button: {
  /*** Component Button
       @param accent Indicates if the button should have accent color.
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param flat If true, the button will have a flat look.
       @param floating If true, the button will have a floating look.
       @param href Creates a link for the button.
       @param icon Value of the icon (See Font Icon Component).
       @param inverse If true, the neutral colors are inverted. Useful to put a button over a dark background.
       @param label The text string to use for the name of the button.
       @param mini To be used with floating button. If true, the button will be smaller.
       @param neutral Set it to false if you don't want the neutral styles to be included.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Fires after the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onRippleEnded Function that will be called when the ripple animation ends.
       @param primary Indicates if the button should have primary color.
       @param raised If true, the button will have a raised look.
       @param ripple If true, component will have a ripple effect on click.
       @param spread Factor to indicate how much should the ripple spread under the component.
       @param style Set inline style for the root component.
       @param target Passed down to the root element
       @param theme Classnames object defining the component style.
       @param type Component root container type. */
  let make:
    (
      ~accent: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~flat: bool=?,
      ~floating: bool=?,
      ~href: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~inverse: bool=?,
      ~label: string=?,
      ~mini: bool=?,
      ~neutral: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onRippleEnded: ReactEvent.Transition.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~primary: bool=?,
      ~raised: bool=?,
      ~ripple: bool=?,
      ~spread: float=?,
      ~style: ReactDOMRe.style=?,
      ~target: string=?,
      ~theme: Js.t({..})=?,
      ~_type: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Card: {
  /*** Component Card
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param raised Increases the shadow depth to appear elevated.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~raised: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module CardActions: {
  /*** Component CardActions
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module CardMedia: {
  module AspectRatio: {
    type t =
      | Wide
      | Square;
    let to_string: t => string;
  };
  /*** Component CardMedia
       @param aspectRatio Forces a 16:9 or 1:1 aspect ratio respectively. Unset, the media area will have a flexible height.
       @param className Set a class for the root component.
       @param color Sets the background color.
       @param contentOverlay Creates a dark overlay underneath the child components.
       @param image Can be used instead of children. Accepts an element or a URL string.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~aspectRatio: AspectRatio.t=?,
      ~className: string=?,
      ~color: string=?,
      ~contentOverlay: bool=?,
      ~image: ReasonReact.reactElement=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module CardText: {
  /*** Component CardText
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module CardTitle: {
  /*** Component CardTitle
       @param avatar A string URL or Element to specify an avatar in the left side of the title.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param subtitle Text used for the sub header of the card.
       @param theme Classnames object defining the component style.
       @param title Text used for the title of the card. */
  let make:
    (
      ~avatar: ReasonReact.reactElement=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~subtitle: ReasonReact.reactElement=?,
      ~theme: Js.t({..})=?,
      ~title: ReasonReact.reactElement=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Checkbox: {
  /*** Component Checkbox
       @param checked Value for the checkbox, can be true or false.
       @param className Set a class for the root component.
       @param disabled If true, the checkbox shown as disabled and cannot be modified.
       @param label Text label to attach next to the checkbox element.
       @param name The name of the field to set in the input checkbox.
       @param onBlur Callback called when the checkbox is blurred.
       @param onChange Callback called when the checkbox value is changed.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~checked: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~label: ReasonReact.reactElement=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: (bool, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Chip: {
  /*** Component Chip
       @param className Set a class for the root component.
       @param deletable If true, the chip will be rendered with a delete icon.
       @param onClick Callback called when the component is clicked.
       @param onDeleteClick Callback to be invoked when the delete icon is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~deletable: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDeleteClick: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module DatePicker: {
  module Locale: {
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
    let to_string: t => string;
  };
  /*** Component DatePicker
       @param active Allows to control if the picker should be shown from outside. Beware you should update the prop when the Dialog is closed.
       @param autoOk Automatically selects a date upon clicking on a day
       @param cancelLabel Label used for cancel button on Dialog.
       @param className Set a class for the root component.
       @param disabledDates An array of date objects which will be disabled in the calendar. All other dates will be enabled.
       @param enabledDates An array of date objects which will be enabled in the calendar. All other dates will be disabled.
       @param error Give an error node to display under the field.
       @param icon A key to identify an Icon from Material Design Icons or a custom Icon Element.
       @param inputClassName This class will be applied to Input component of DatePicker.
       @param inputFormat Function to format the date displayed on the input.
       @param label The text string to use for the floating label element in the input component.
       @param locale Sets locale for the Dialog.
       @param maxDate Date object with the maximum selectable date.
       @param minDate Date object with the minimum selectable date.
       @param name Name for the input field.
       @param okLabel Label used for 'OK' button on Dialog.
       @param onChange Callback called when the picker value is changed.
       @param onClick Callback fired on Input click.
       @param onDismiss Callback fired after dismissing the Dialog.
       @param onEscKeyDown Callback called when the ESC key is pressed with the overlay active.
       @param onKeyPress Callback invoked on Input key press.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onOverlayClick Callback to be invoked when the dialog overlay is clicked.
       @param readonly The input element will be readonly and look like disabled.
       @param required Used in case the input is required.
       @param style Set inline style for the root component.
       @param sundayFirstDayOfWeek Set week's first day to Sunday. Default week's first day is Monday.
       @param theme Classnames object defining the component style.
       @param value Date object with the currently selected date. */
  let make:
    (
      ~active: bool=?,
      ~autoOk: bool=?,
      ~cancelLabel: string=?,
      ~className: string=?,
      ~disabledDates: array(Js.Date.t)=?,
      ~enabledDates: array(Js.Date.t)=?,
      ~error: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~inputClassName: string=?,
      ~inputFormat: Js.t({..})=?,
      ~label: string=?,
      ~locale: [ | `Enum(Locale.t) | `Object(Js.t({..}))]=?,
      ~maxDate: Js.Date.t=?,
      ~minDate: Js.Date.t=?,
      ~name: string=?,
      ~okLabel: string=?,
      ~onChange: (Js.Date.t, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDismiss: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onEscKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~readonly: bool=?,
      ~required: bool=?,
      ~style: ReactDOMRe.style=?,
      ~sundayFirstDayOfWeek: bool=?,
      ~theme: Js.t({..})=?,
      ~value: [ | `Date(Js.Date.t) | `String(string)]=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Dialog: {
  module Type: {
    type t =
      | Small
      | Normal
      | Large;
    let to_string: t => string;
  };
  /*** Component Dialog
       @param actions A array of objects representing the buttons for the dialog navigation area. The properties will be transferred to the buttons.
       @param active If true, the dialog will be active.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onEscKeyDown Callback called when the ESC key is pressed with the overlay active.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onOverlayClick Callback to be invoked when the dialog overlay is clicked.
       @param onOverlayMouseDown Callback called when the mouse button is pressed on the overlay.
       @param onOverlayMouseMove Callback called when the mouse is moving over the overlay.
       @param onOverlayMouseUp Callback called when the mouse button is released over the overlay.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param title The text string to use as standar title of the dialog.
       @param type Used to determine the size of the dialog. It can be small, normal or large. */
  let make:
    (
      ~actions: array(Js.t({..}))=?,
      ~active: bool=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onEscKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~onOverlayMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onOverlayMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onOverlayMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~title: string=?,
      ~_type: [ | `Enum(Type.t) | `String(string)]=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Drawer: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  /*** Component Drawer
       @param active If true, the drawer will be visible.
       @param className Set a class for the root component.
       @param insideTree If true the Drawer is rendered inside the normal tree.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onOverlayClick Callback function to be invoked when the overlay is clicked.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Type of drawer. It can be left or right to display the drawer on the left or right side of the screen.
       @param withOverlay If true display an Overlay that locks the scroll when the Drawer is active. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~insideTree: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      ~withOverlay: bool=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Dropdown: {
  /*** Component Dropdown
       @param allowBlank If true the dropdown will preselect the first item if the supplied value matches none of the options' values.
       @param auto If true, the dropdown will open up or down depending on the position in the screen.
       @param className Set a class for the root component.
       @param disabled Set the component as disabled.
       @param error Give an error string to display under the field.
       @param label The text string to use for the floating label element.
       @param labelKey Used for setting the label from source
       @param name Name for the input field.
       @param onBlur Callback function that is fired when the component is blurred.
       @param onChange Callback function that is fired when the component's value changes.
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback function that is fired when the component is focused.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param required If true, the dropdown has a required attribute.
       @param source Array of data objects with the data to represent in the dropdown.
       @param style Set inline style for the root component.
       @param template Callback function that returns a JSX template to represent the element.
       @param theme Classnames object defining the component style.
       @param value Default value using JSON data.
       @param valueKey Used for setting the value from source */
  let make:
    (
      ~allowBlank: bool=?,
      ~auto: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~error: string=?,
      ~label: string=?,
      ~labelKey: string=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: ('value, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~required: bool=?,
      ~source: array('a),
      ~style: ReactDOMRe.style=?,
      ~template: Js.t({..})=?,
      ~theme: Js.t({..})=?,
      ~value: [ | `String(string) | `Float(float)]=?,
      ~valueKey: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module FontIcon: {
  /*** Component FontIcon
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param value The key string for the icon you want be displayed. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~value: ReasonReact.reactElement=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module IconButton: {
  /*** Component IconButton
       @param accent Indicates if the button should have accent color.
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param href Creates a link for the button.
       @param icon Value of the icon (See Font Icon Component).
       @param inverse If true, the neutral colors are inverted. Useful to put a button over a dark background.
       @param neutral Set it to false if you don't want the neutral styles to be included.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Fires after the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param primary Indicates if the button should have primary color.
       @param ripple If true, component will have a ripple effect on click.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Component root container type. */
  let make:
    (
      ~accent: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~href: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~inverse: bool=?,
      ~neutral: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~primary: bool=?,
      ~ripple: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module IconMenu: {
  module Position: {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string: t => string;
  };
  /*** Component IconMenu
       @param active If true, the inner Menu component will be active.
       @param className Set a class for the root component.
       @param icon Icon font key string or Element to display the opener icon.
       @param iconRipple If true, the icon will show a ripple when is clicked.
       @param inverse If true, the neutral colors are inverted. Useful if the icon is over a dark background.
       @param menuRipple Transferred to the Menu component.
       @param onClick Callback called when the component is clicked.
       @param onHide Callback that will be called when the menu is being hidden.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onSelect Callback that will be invoked when a menu item is selected.
       @param onShow Callback that will be invoked when the menu is being shown.
       @param position Determines the position of the menu. This property is transferred to the inner Menu component.
       @param selectable If true, the menu will keep a value to highlight the active child item.
       @param selected Used for selectable menus. Indicates the current selected value so the child item with this value can be highlighted.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~iconRipple: bool=?,
      ~inverse: bool=?,
      ~menuRipple: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onHide: unit => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onSelect: ReactEvent.Selection.t => unit=?,
      ~onShow: unit => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~position: Position.t=?,
      ~selectable: bool=?,
      ~selected: 'a=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Input: {
  /*** Component Input
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param error Give an error node to display under the field.
       @param floating Indicates if the label is floating in the input field or not.
       @param hint The text string to use for hint text element.
       @param icon Name of an icon to use as a label for the input.
       @param label The text string to use for the floating label element.
       @param maxLength Specifies the maximum number of characters allowed in the component
       @param multiline If true, a textarea element will be rendered. The textarea also grows and shrinks according to the number of lines.
       @param name Name for the input field.
       @param onBlur Callback function that is fired when component is blurred.
       @param onChange Callback function that is fired when the component's value changes
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback function that is fired when component is focused.
       @param onKeyDown Callback function that is fired when a key is pressed down.
       @param onKeyPress Callback function that is fired when a key is pressed.
       @param onKeyUp Callback function that is fired when a key is released.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param required If true, the html input has a required attribute.
       @param rows The number of rows the multiline input field has.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Type of the input element. It can be a valid HTML5 input type.
       @param value Current value of the input element. */
  let make:
    (
      ~className: string=?,
      ~disabled: bool=?,
      ~error: ReasonReact.reactElement=?,
      ~floating: bool=?,
      ~hint: ReasonReact.reactElement=?,
      ~icon: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~maxLength: float=?,
      ~multiline: bool=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: (string, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~required: bool=?,
      ~rows: float=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: string=?,
      ~value: 'a=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Layout: {
  /*** Component Layout
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Link: {
  /*** Component Link
       @param active If true, adds active style to link.
       @param className Set a class for the root component.
       @param count Sets a count number.
       @param href Sets the anchor link.
       @param icon An icon key string to include a FontIcon component in front of the text.
       @param label The text string used for the text content of the link.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~count: float=?,
      ~href: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~label: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module List: {
  /*** Component List
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param ripple If true, each element in the list will have a ripple effect on click
       @param selectable If true, the elements in the list will display a hover effect and a pointer cursor.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~ripple: bool=?,
      ~selectable: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListCheckbox: {
  /*** Component ListCheckbox
       @param caption Main text of the item. Required.
       @param checked If true the checkbox appears checked by default.
       @param className Set a class for the root component.
       @param disabled If true, the item is displayed as disabled and it's not clickable.
       @param legend Secondary text to display under the caption.
       @param name Name for the checkbox input item.
       @param onBlur Callback called when the input element is blurred.
       @param onChange Callback called when the input element is changed.
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback called when the input element is focused.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~caption: string=?,
      ~checked: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~legend: string=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: ReactEvent.Form.t => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListDivider: {
  /*** Component ListDivider
       @param className Set a class for the root component.
       @param inset If true, will leave a space at the left side.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~inset: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListItemAction: {
  /*** Component ListItemAction
       @param action List item action.
       @param theme Object defining the component class name mappings. */
  let make:
    (~action: ReasonReact.reactElement=?, ~theme: Js.t({..})=?, 'children) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListItemActions: {
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  /*** Component ListItemActions
       @param theme Object defining the component class name mappings.
       @param type List item action type. */
  let make:
    (~theme: 'a=?, ~_type: Type.t=?, 'children) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListItemContent: {
  module Type: {
    type t =
      | Auto
      | Normal
      | Large;
    let to_string: t => string;
  };
  /*** Component ListItemContent
       @param caption Main text of the item.
       @param legend Secondary text to display under the caption.
       @param theme Object defining the component class name mappings.
       @param type List item content type. */
  let make:
    (
      ~caption: ReasonReact.reactElement=?,
      ~legend: string=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListItemLayout: {
  /*** Component ListItemLayout
       @param avatar A string URL to specify an avatar in the left side of the item.
       @param caption Main text of the item.
       @param className Set a class for the root component.
       @param disabled If true, the item is displayed as disabled and it's not clickable.
       @param itemContent Layout content.
       @param leftActions A list of elements that are placed on the left side of the item and after the avatar attribute.
       @param leftIcon A string key of a font icon or element to display an icon in the left side of the item.
       @param legend Secondary text to display under the caption.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param rightActions A list of elements that are placed on the right side of the item and after the rightIcon attribute.
       @param rightIcon The same as the leftIcon but in this case the icon is displayed in the right side.
       @param selectable If true, the elements in the list will display a hover effect and a pointer cursor. Inherited from the parent.
       @param style Set inline style for the root component.
       @param theme Object defining the component class name mappings.
       @param to In case you want to provide the item as a link, you can pass this property to specify the href. */
  let make:
    (
      ~avatar: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~caption: string=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~itemContent: Js.t({..})=?,
      ~leftActions: array(ReasonReact.reactElement)=?,
      ~leftIcon: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~legend: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~rightActions: array(ReasonReact.reactElement)=?,
      ~rightIcon: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~selectable: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: 'a=?,
      ~_to: string=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListItemText: {
  /*** Component ListItemText
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param primary Whether list item text should have 'primary' look.
       @param style Set inline style for the root component.
       @param theme Object defining the component class name mappings. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~primary: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ListSubHeader: {
  /*** Component ListSubHeader
       @param caption Text that will be displayed.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~caption: string=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Menu: {
  module Position: {
    type t =
      | Auto
      | Static
      | TopLeft
      | TopRight
      | BottomLeft
      | BottomRight;
    let to_string: t => string;
  };
  /*** Component Menu
       @param active If true, the menu will be displayed as opened by default.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onHide Callback that will be called when the menu is being hidden.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onSelect Callback that will be invoked when a menu item is selected.
       @param onShow Callback that will be invoked when the menu is being shown.
       @param outline If true the menu wrapper will show an outline with a soft shadow.
       @param position Determine the position of the menu. With static value the menu will be always shown, auto means that the it will decide the opening direction based on the current position. To force a position use topLeft, topRight, bottomLeft, bottomRight.
       @param ripple If true, the menu items will show a ripple effect on click.
       @param selectable If true, the menu will keep a value to highlight the active child item.
       @param selected Used for selectable menus. Indicates the current selected value so the child item with this value can be highlighted.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onHide: unit => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onSelect: 'value => unit=?,
      ~onShow: unit => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~outline: bool=?,
      ~position: Position.t=?,
      ~ripple: bool=?,
      ~selectable: bool=?,
      ~selected: 'a=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module MenuDivider: {
  /*** Component MenuDivider
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module MenuItem: {
  /*** Component MenuItem
       @param caption The text to include in the menu item. Required.
       @param className Set a class for the root component.
       @param disabled If true, the item will be displayed as disabled and is not selectable.
       @param icon Icon font key string or Element to display in the right side of the option.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param selected Transferred from the Menu component for selectable menus. Indicates if it's the current active option.
       @param shortcut Displays shortcut text on the right side of the caption attribute.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param value Passed down to the root element */
  let make:
    (
      ~caption: string,
      ~className: string=?,
      ~disabled: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~selected: bool=?,
      ~shortcut: string=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~value: 'a=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module NavDrawer: {
  module PermanentAt: {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string: t => string;
  };
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  /*** Component NavDrawer
       @param active If true, the drawer will be shown as an overlay.
       @param clipped If true, when the `AppBar` gets pinned, it will stand over the `Drawer`.
       @param insideTree If true the Drawer is rendered inside the normal tree.
       @param onOverlayClick Callback function to be invoked when the overlay is clicked. It only works if the `Drawer` is actually displaying and Overlay
       @param permanentAt The breakpoint at which the drawer is automatically pinned.
       @param pinned If true, the drawer will be pinned open. pinned takes precedence over active.
       @param theme Classnames object defining the component style.
       @param type Type of drawer. It can be left or right to display the drawer on the left or right side of the screen.
       @param withOverlay If true display an Overlay that locks the scroll when the Drawer is active. */
  let make:
    (
      ~active: bool=?,
      ~clipped: bool=?,
      ~insideTree: bool=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~permanentAt: PermanentAt.t=?,
      ~pinned: bool=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      ~withOverlay: bool=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Navigation: {
  module Type: {
    type t =
      | Vertical
      | Horizontal;
    let to_string: t => string;
  };
  /*** Component Navigation
       @param actions Array of objects that will be represented as <Button/> so the keys will be transferred as properties the Button Component.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param routes Array of objects similar to actions but that will be rendered as <Link/> component definition.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Type of the navigation, it can be vertical or horizontal. */
  let make:
    (
      ~actions: array('a)=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~routes: array('b)=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Overlay: {
  /*** Component Overlay
       @param active Whether overlay is active.
       @param className Additional class name(s) for root container.
       @param invisible Whether Overlay should have 'invisible' styles.
       @param onClick Callback invoked on Overlay click.
       @param onEscKeyDown Callback invoked on ESC key.
       @param theme Overlay theme. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~invisible: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onEscKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Panel: {
  /*** Component Panel
       @param bodyScroll You can set it to true in case you are using a pinned Sidebar so it takes an scrolled `div` instead of using the document scroll.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~bodyScroll: bool=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Portal: {
  /*** Component Portal
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component. */
  let make:
    (
      ~className: string=?,
      ~container: 'a=?,
      ~lockBody: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module ProgressBar: {
  module Mode: {
    type t =
      | Determinate
      | Indeterminate;
    let to_string: t => string;
  };
  module Type: {
    type t =
      | Linear
      | Circular;
    let to_string: t => string;
  };
  /*** Component ProgressBar
       @param buffer Value of a secondary progress bar useful for buffering.
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param max Maximum value permitted.
       @param min Minimum value permitted.
       @param mode Mode of the progress bar, it can be determinate or indeterminate.
       @param multicolor If true, the circular progress bar will be changing its color.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param type Type of the progress bar, it can be circular or linear.
       @param value Value of the current progress. */
  let make:
    (
      ~buffer: float=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~max: float=?,
      ~min: float=?,
      ~mode: Mode.t=?,
      ~multicolor: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      ~value: float=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module RadioButton: {
  /*** Component RadioButton
       @param checked If true, the input element will be selected by default. Transferred from the parent.
       @param className Set a class for the root component.
       @param disabled If true, the item will be displayed as disabled.
       @param label Label for the radio button.
       @param name Name for the input element.
       @param onBlur Callback function that will be invoked when the input is blurred.
       @param onChange Callback function that will be invoked when the value changes.
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback function that will be invoked when the input is focused.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param value Value for the radio button. */
  let make:
    (
      ~checked: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~label: ReasonReact.reactElement=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: ReactEvent.Form.t => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: 'a=?,
      ~value: 'b=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module RadioGroup: {
  /*** Component RadioGroup
       @param className Set a class for the root component.
       @param disabled If true, the group will be displayed as disabled.
       @param name Name for the input element group.
       @param onChange Callback function that will be invoked when the value changes.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param value Default value selected in the radio group. */
  let make:
    (
      ~className: string=?,
      ~disabled: bool=?,
      ~name: string=?,
      ~onChange: string => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~value: 'a=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Sidebar: {
  module PermanentAt: {
    type t =
      | Sm
      | SmTablet
      | Md
      | Lg
      | LgTablet
      | Xl
      | Xxl
      | Xxxl;
    let to_string: t => string;
  };
  module Type: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  /*** Component Sidebar
       @param active If true, the drawer will be visible.
       @param clipped If true, when the `AppBar` gets pinned, it will stand over the `Drawer`.
       @param insideTree If true the Drawer is rendered inside the normal tree.
       @param onOverlayClick Callback function to be invoked when the overlay is clicked.
       @param permanentAt The breakpoint at which the drawer is automatically pinned.
       @param pinned If true, the sidebar will be pinned open.
       @param theme Classnames object defining the component style.
       @param type Type of drawer. It can be left or right to display the drawer on the left or right side of the screen.
       @param width Width in standard increments (1-12) or percentage (25, 33, 50, 66, 75, 100)
       @param withOverlay If true display an Overlay that locks the scroll when the Drawer is active. */
  let make:
    (
      ~active: bool=?,
      ~clipped: bool=?,
      ~insideTree: bool=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~permanentAt: PermanentAt.t=?,
      ~pinned: bool=?,
      ~theme: Js.t({..})=?,
      ~_type: Type.t=?,
      ~width: float=?,
      ~withOverlay: bool=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Slider: {
  /*** Component Slider
       @param buffer Used to style the ProgressBar element
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param editable If true, an input is shown and the user can set the slider from keyboard value.
       @param max Maximum value permitted.
       @param min Minimum value permitted.
       @param onChange Callback function that will be invoked when the slider value changes.
       @param onClick Callback called when the component is clicked.
       @param onDragStart Callback function that will be invoked when the slider starts being dragged.
       @param onDragStop Callback function that will be invoked when the slider stops being dragged.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param pinned If true, a pin with numeric value label is shown when the slider thumb is pressed. Use for settings for which users need to know the exact value of the setting.
       @param snaps If true, the slider thumb snaps to tick marks evenly spaced based on the step property value.
       @param step Amount to vary the value when the knob is moved or increase/decrease is called.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param value Current value of the slider. */
  let make:
    (
      ~buffer: float=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~editable: bool=?,
      ~max: float=?,
      ~min: float=?,
      ~onChange: (float, ReactEvent.Focus.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDragStop: unit => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~pinned: bool=?,
      ~snaps: bool=?,
      ~step: float=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~value: float=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Snackbar: {
  module Type: {
    type t =
      | Accept
      | Cancel
      | Warning;
    let to_string: t => string;
  };
  /*** Component Snackbar
       @param action Label for the action component inside the Snackbar.
       @param active If true, the snackbar will be active.
       @param className Set a class for the root component.
       @param label Text to display in the content.
       @param onClick Callback function that will be called when the button action is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onTimeout Callback function when finish the set timeout.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style.
       @param timeout Amount of time in milliseconds after the Snackbar will be automatically hidden.
       @param type Indicates the action type. Can be accept, warning or cancel */
  let make:
    (
      ~action: string=?,
      ~active: bool=?,
      ~className: string=?,
      ~label: [ | `String(string) | `Object(Js.t({..}))]=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTimeout: unit => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      ~timeout: float=?,
      ~_type: Type.t=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Switch: {
  /*** Component Switch
       @param checked If true, the switch will be enabled.
       @param className Set a class for the root component.
       @param disabled If true, component will be disabled.
       @param label The text string to use for the floating label element.
       @param name The text string used as name of the input.
       @param onBlur Callback function that is fired when when the switch is blurred.
       @param onChange Callback function that is fired when the component's value changes.
       @param onClick Callback called when the component is clicked.
       @param onFocus Callback function that is fired when the switch is focused.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~checked: bool=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~label: string=?,
      ~name: string=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onChange: (bool, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Tab: {
  /*** Component Tab
       @param active If true, the current component is visible.
       @param activeClassName Additional class name to provide custom styling for the active tab.
       @param className Set a class for the root component.
       @param disabled If true, the current component is not clickable.
       @param hidden If true, the current component is not visible.
       @param icon Icon to be used in inner FontIcon.
       @param label Label text for navigation header.
       @param onActive Callback function that is fired when the tab is activated.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~active: bool=?,
      ~activeClassName: string=?,
      ~className: string=?,
      ~disabled: bool=?,
      ~hidden: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~label: string=?,
      ~onActive: unit => unit=?,
      ~onClick: (ReactEvent.Mouse.t, float) => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module TabContent: {
  /*** Component TabContent
       @param active Whether tab is active.
       @param className Set a class for the root component.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param tabIndex Current tab index.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~active: bool=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~tabIndex: float=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Table: {
  /*** Component Table
       @param className Set a class for the root component.
       @param multiSelectable If true, the header and each row will display a checkbox to allow the user to select multiple rows.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onRowSelect Will be called when the row selection changes. It passes an array of selected indexes as first parameter so you can figure out changes in your local state.
       @param selectable If true, each row will display a checkbox to allow the user to select that one row.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~multiSelectable: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onRowSelect: array(float => unit)=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~selectable: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module TableCell: {
  module Sorted: {
    type t =
      | Asc
      | Desc;
    let to_string: t => string;
  };
  module TagName: {
    type t =
      | Td
      | Th;
    let to_string: t => string;
  };
  /*** Component TableCell
       @param className Set a class for the root component.
       @param column The column number of this cell.
       @param numeric If true the cell is considered as numeric and the content will be displayed aligned to right.
       @param onClick Called when the cell is clicked with the click event, column number and row number.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param row The row number of the cell.
       @param sorted If you provide a value the cell will show an arrow pointing down or up depending on the value to indicate it is a sorted element. Useful only for columns.
       @param style Set inline style for the root component.
       @param tagName The element tag, either `td` or `th`.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~column: float=?,
      ~numeric: bool=?,
      ~onClick: (ReactEvent.Mouse.t, float, float) => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~row: float=?,
      ~sorted: Sorted.t=?,
      ~style: ReactDOMRe.style=?,
      ~tagName: TagName.t=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module TableHead: {
  /*** Component TableHead
       @param className Set a class for the root component.
       @param displaySelect If true, a checkbox will be displayed to select every row. In case the table is not multi-selectable, it will be disabled though.
       @param multiSelectable If true, the header and each row will display a checkbox to allow the user to select multiple rows.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onSelect Handle the select state change of the checkbox in the header row.
       @param selectable If true, each row will display a checkbox to allow the user to select that one row.
       @param selected If selectable, controls the selected state of the checkbox in the header row.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~displaySelect: bool=?,
      ~multiSelectable: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onSelect: (bool, ReactEvent.Mouse.t) => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~selectable: bool=?,
      ~selected: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module TableRow: {
  /*** Component TableRow
       @param className Set a class for the root component.
       @param idx The index of the row.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param onSelect Handle the select state change of the checkbox in the ow.
       @param selectable If true, each row will display a checkbox to allow the user to select that one row.
       @param selected If true, the row will be considered as selected so the row will display a selected style with the selection control activated. This property is used by `Table` to figure out the selection when you interact with the Table.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~idx: float=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onSelect: (float, bool) => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~selectable: bool=?,
      ~selected: bool=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module Tabs: {
  module HideMode: {
    type t =
      | Display
      | Unmounted;
    let to_string: t => string;
  };
  /*** Component Tabs
       @param className Set a class for the root component.
       @param disableAnimatedBottomBorder Disable the animation below the active tab.
       @param fixed If True, the tabs will be fixed, covering the whole width.
       @param hideMode `unmounted` mode will not mount the tab content of inactive tabs.
       `display` mode will mount but hide inactive tabs.
       Consider holding state outside of the Tabs component before using `display` mode
       @param index Current
       @param inverse If True, the tabs will have an inverse style.
       @param onChange Callback function that is fired when the tab changes.
       @param onClick Callback called when the component is clicked.
       @param onMouseDown Callback called when the mouse press the Component.
       @param onMouseEnter Callback called when the mouse enters the Component.
       @param onMouseLeave Callback called when the mouse leaves the Component.
       @param onMouseUp Fires after the mouse is released from the Component.
       @param style Set inline style for the root component.
       @param theme Classnames object defining the component style. */
  let make:
    (
      ~className: string=?,
      ~disableAnimatedBottomBorder: bool=?,
      ~fixed: bool=?,
      ~hideMode: HideMode.t=?,
      ~index: float=?,
      ~inverse: bool=?,
      ~onChange: float => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onContextMenu: ReactEvent.Mouse.t => unit=?,
      ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
      ~onDrag: ReactEvent.Mouse.t => unit=?,
      ~onDragEnd: ReactEvent.Mouse.t => unit=?,
      ~onDragEnter: ReactEvent.Mouse.t => unit=?,
      ~onDragExit: ReactEvent.Mouse.t => unit=?,
      ~onDragLeave: ReactEvent.Mouse.t => unit=?,
      ~onDragOver: ReactEvent.Mouse.t => unit=?,
      ~onDragStart: ReactEvent.Mouse.t => unit=?,
      ~onDrop: ReactEvent.Mouse.t => unit=?,
      ~onMouseDown: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onMouseMove: ReactEvent.Mouse.t => unit=?,
      ~onMouseOut: ReactEvent.Mouse.t => unit=?,
      ~onMouseOver: ReactEvent.Mouse.t => unit=?,
      ~onMouseUp: ReactEvent.Mouse.t => unit=?,
      ~onTouchCancel: ReactEvent.Touch.t => unit=?,
      ~onTouchEnd: ReactEvent.Touch.t => unit=?,
      ~onTouchMove: ReactEvent.Touch.t => unit=?,
      ~onTouchStart: ReactEvent.Touch.t => unit=?,
      ~style: ReactDOMRe.style=?,
      ~theme: Js.t({..})=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
module TimePicker: {
  module Format: {
    type t =
      | V_24hr
      | Ampm;
    let to_string: t => string;
  };
  /*** Component TimePicker
       @param active Whether time picker is active.
       @param cancelLabel Label used for cancel button.
       @param error Provide error text which will be displayed under the field.
       @param format Format to display the clock. It can be 24hr or ampm.
       @param icon A key to identify an Icon from Material Design Icons or a custom Icon Element.
       @param inputClassName This class will be applied to Input component of TimePicker.
       @param label The text string to use for the floating label element in the input component.
       @param okLabel Label used for 'OK' button on Dialog.
       @param onChange Callback called when the picker value is changed.
       @param onClick Callback fired on Input click.
       @param onDismiss Callback fired after dismissing the Dialog.
       @param onEscKeyDown Callback called when the ESC key is pressed with the overlay active.
       @param onKeyPress Callback invoked on Input key press.
       @param onOverlayClick Callback to be invoked when the dialog overlay is clicked.
       @param readonly The input element will be readonly and look like disabled.
       @param theme Classnames object defining the component style.
       @param value Datetime object with currrently selected time. */
  let make:
    (
      ~active: bool=?,
      ~cancelLabel: string=?,
      ~error: string=?,
      ~format: Format.t=?,
      ~icon: ReasonReact.reactElement=?,
      ~inputClassName: string=?,
      ~label: string=?,
      ~okLabel: string=?,
      ~onChange: (Js.Date.t, ReactEvent.Mouse.t) => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onDismiss: ReactEvent.Mouse.t => unit=?,
      ~onEscKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onOverlayClick: ReactEvent.Mouse.t => unit=?,
      ~readonly: bool=?,
      ~theme: Js.t({..})=?,
      ~value: Js.Date.t=?,
      'children
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
