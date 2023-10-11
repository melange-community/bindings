/*
   This binding matches with the React version of Font Awesome defined here:
   https://github.com/FortAwesome/react-fontawesome/blob/master/src/components/FontAwesomeIcon.js#L62-L118
 */

@module("@fortawesome/react-fontawesome") @react.component
external make: (
  ~icon: IconObject.t,
  ~className: string=?,
  ~title: string=?,
  ~transform: string=?,
  ~color: string=?,
  ~swapOpacity: bool=?,
  ~listItem: bool=?,
  ~fixedWidth: bool=?,
  ~flip: bool=?,
  ~spin: bool=?,
  ~pulse: bool=?,
  ~rotation: int=?,
  ~size: IconSize.t=?,
  ~style: ReactDOM.Style.t=?,
) => React.element = "FontAwesomeIcon"
