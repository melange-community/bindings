module Dialog = {
  type closeDetail = {action: option<string>}

  type onClose = {detail: closeDetail}
}

module TextField = {
  // type changeEvent = {currentTarget: Dom.htmlInputElement}
  type changeEvent = ReactEvent.synthetic<ReactEvent.Form.tag>
}

module Button = {
  type rippleProp = {
    accent: option<bool>,
    surface: option<bool>,
    unbounded: option<bool>,
  }
}
