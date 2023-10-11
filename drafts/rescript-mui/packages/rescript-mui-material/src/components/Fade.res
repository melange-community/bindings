type publicProps = {
  ...Transition.publicProps,
  /**
    * Perform the enter transition when it first mounts if `in` is also `true`.
    * Set this to `false` to disable this behavior.
    * @default true
    */
  appear?: bool,
  /**
    * The transition timing function.
    * You may specify a single easing or a object containing enter and exit values.
    */
  easing?: Transition.easing,
  /**
    * If `true`, the component will transition in.
    */
  @as("in")
  in_?: bool,
  /**
    * The duration for the transition, in milliseconds.
    * You may specify a single timeout for all transitions, or individually with an object.
    * @default {
    *   enter: theme.transitions.duration.enteringScreen,
    *   exit: theme.transitions.duration.leavingScreen,
    * }
    */
  timeout?: Transition.duration,
}

type props = {
  ...publicProps,
  /**
   * A single child content element.
   */
  children: React.element,
}

@module("@mui/material/Fade")
external make: React.component<props> = "default"
