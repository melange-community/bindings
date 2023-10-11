// https://reactcommunity.org/react-transition-group/transition#Transition-props
type publicProps = {
  ...CommonProps.t,
  addEndListener?: ReactEvent.Synthetic.t => unit,
  enter?: bool,
  exit?: bool,
  mountOnEnter?: bool,
  onEnter?: ReactEvent.Synthetic.t => unit,
  onEntered?: ReactEvent.Synthetic.t => unit,
  onEntering?: ReactEvent.Synthetic.t => unit,
  onExit?: ReactEvent.Synthetic.t => unit,
  onExited?: ReactEvent.Synthetic.t => unit,
  onExiting?: ReactEvent.Synthetic.t => unit,
  unmountOnExit?: bool,
}

type props = {
  ...publicProps,
  appear?: bool,
}

type durationObject = {
  appear?: int,
  enter?: int,
  exit?: int,
}

@unboxed
type duration =
  | Time(int)
  | Object(durationObject)

@unboxed
type durationWithAuto =
  | @as("auto") Auto
  | Duration(int)
  | Object(durationObject)

type easingObject = {
  enter?: string,
  exit?: string,
}

@unboxed
type easing =
  | Easing(string)
  | Object(easingObject)

type delay // TODO

external propsFromObject: {..} => props = "%identity"
