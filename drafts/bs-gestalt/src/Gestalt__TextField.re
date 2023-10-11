[@bs.module "gestalt"] [@react.component]
external make:
  (
    ~autoComplete: [@bs.string] [
                     | [@bs.as "current-password"] `currentPassword
                     | [@bs.as "new-password"] `newPassword
                     | `on
                     | `off
                     | `username
                   ]
                     =?,
    ~disabled: bool=?,
    ~errorMessage: string=?,
    ~id: string,
    ~name: string=?,
    ~onBlur: Gestalt__Event.t(ReactEvent.Focus.t) => unit=?,
    ~onChange: Gestalt__Event.t(ReactEvent.Form.t) => unit,
    ~onFocus: Gestalt__Event.t(ReactEvent.Focus.t) => unit=?,
    ~onKeyDown: Gestalt__Event.t(ReactEvent.Keyboard.t) => unit=?,
    ~placeholder: string=?,
    ~_type: [@bs.string] [
              | `date
              | `email
              | `number
              | `password
              | `text
              | `url
            ]
              =?,
    ~value: string=?,
    unit
  ) =>
  React.element =
  "TextField";
