type mode = [ | `time | `date | `month | `year | `decade];
[@bs.deriving jsConverter]
type picker = [ | [@bs.as "date"] `date | `week | `month | `quarter | `year];
type size = [ | `large | `middle | `small];

[@bs.module "antd"] [@react.component]
external make:
  (
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~bordered: bool=?,
    ~className: string=?,
    ~dateRender: 'a=?,
    ~disabled: bool=?,
    ~disabledDate: unit => bool=?,
    ~dropdownClassName: string=?,
    ~getPopupContainer: unit => unit=?,
    ~inputReadOnly: bool=?,
    ~locale: 'b=?,
    ~mode: mode=?,
    ~_open: bool=?,
    ~panelRender: unit => React.element=?,
    ~picker: picker=?,
    ~placeHolder: 'c=?,
    ~popupStyle: 'd=?,
    ~size: size=?,
    ~style: ReactDOMRe.Style.t=?,
    ~suffixIcon: React.element=?,
    ~onOpenChange: unit => unit=?,
    ~onPanelChange: unit => unit=?,
    ~defaultValue: 'e=?,
    ~defaultPickerValue: 'f=?,
    ~format: string=?,
    ~value: 'g=?,
    ~showToday: bool=?,
    ~onChange: ReactEvent.Form.t=?,
    ~showTime: 'h=?
  ) =>
  React.element =
  "DatePicker";
