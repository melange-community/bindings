open Types

@module("react-bootstrap") @react.component
external make: (
  ~_ref: ReactDOM.Ref.t=?,
  ~_as: string=?,
  ~validated: bool=?,
  ~children: React.element,
  ~className: string=?,
) => React.element = "Form"

module Floating = {
  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_as: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string,
  ) => React.element = "Floating"
}

module Group = {
  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_ref: ReactDOM.Ref.t=?,
    ~_as: string=?,
    ~controlId: string=?,
    ~className: string=?,
    ~children: React.element,
  ) => React.element = "Group"
}

module Label = {
  type column = Bool(bool) | Size([#sm | #lg])

  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_ref: ReactDOM.Ref.t=?,
    ~_as: string=?,
    ~column: column=?,
    ~visuallyHidden: bool=?,
    ~htmlFor: string=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Label"
}

module Text = {
  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_ref: ReactDOM.Ref.t=?,
    ~_as: string=?,
    ~muted: bool=?,
    ~className: string=?,
    ~children: React.element,
    ~bsPrefix: string=?,
  ) => React.element = "Text"
}

module Control = {
  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_ref: ReactDOM.Ref.t=?,
    ~_as: string=?,
    ~disabled: bool=?,
    ~htmlSize: int=?,
    ~id: string=?,
    ~isValid: bool=?,
    ~isInvalid: bool=?,
    ~plainText: bool=?,
    ~readOnly: bool=?,
    ~size: [#sm | #lg]=?,
    ~_type: string=?,
    ~value: string=?,
    ~className: string=?,
    ~onChange: ReactEvent.Form.t=?,
    ~bsPrefix: string=?,
  ) => React.element = "Control"

  module Feedback = {
    @module("react-bootstrap") @scope(("Form", "Control")) @react.component
    external make: (
      ~_as: string=?,
      ~tooltip: bool=?,
      ~_type: [#valid | #invalid]=?,
      ~className: string=?,
      ~children: React.element,
    ) => React.element = "Feedback"
  }
}

module Check = {
  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~_ref: ReactDOM.Ref.t=?,
    ~_as: string=?,
    ~children: React.element=?,
    ~disabled: bool=?,
    ~feedback: reactNode=?,
    ~feedbackTooltip: bool=?,
    ~id: string=?,
    ~inline: bool=?,
    ~isInvalid: bool=?,
    ~isValid: bool=?,
    ~label: string=?,
    ~title: string=?,
    ~className: string=?,
    ~_type: [#radio | #checkbox | #"switch"]=?,
    ~bsPrefix: string=?,
    ~bsSwitchPredfix: string=?,
  ) => React.element = "Check"

  module Input = {
    @module("react-bootstrap") @scope(("Form", "Check")) @react.component
    external make: (
      ~_as: string=?,
      ~id: string=?,
      ~isInvalid: bool=?,
      ~isValid: bool=?,
      ~className: string=?,
      ~_type: [#radio | #checkbox]=?,
      ~bsPrefix: string=?,
    ) => React.element = "Input"
  }

  module Label = {
    @module("react-bootstrap") @scope(("Form", "Check")) @react.component
    external make: (
      ~htmlFor: string,
      ~className: string=?,
      ~children: React.element,
      ~bsPrefix: string=?,
    ) => React.element = "Label"
  }

  module Range = {
    type value<'a> = Value('a) | Values(array<'a>)

    @module("react-bootstrap") @scope(("Form", "Check")) @react.component
    external make: (
      ~disabled: bool=?,
      ~id: string=?,
      ~onChange: ReactEvent.Form.t => unit=?,
      ~value: value<'a>=?,
      ~bsPrefix: string=?,
    ) => React.element = "Label"
  }
}

module Select = {
  type value<'a> = Value('a) | Values(array<'a>)

  @module("react-bootstrap") @scope("Form") @react.component
  external make: (
    ~disabled: bool=?,
    ~htmlSize: int=?,
    ~isInvalid: bool=?,
    ~isValid: bool=?,
    ~onChange: ReactEvent.Form.t=?,
    ~className: string=?,
    ~value: value<'a>=?,
    ~size: [#sm | #lg]=?,
    ~bsPrefix: string=?,
  ) => React.element = "Select"
}

module FloatingLabel = {
  @module("react-bootstrap") @react.component
  external make: (
    ~_as: string=?,
    ~controlId: string=?,
    ~label: string,
    ~className: string=?,
    ~children: React.element,
  ) => React.element = "FloatingLabel"
}
