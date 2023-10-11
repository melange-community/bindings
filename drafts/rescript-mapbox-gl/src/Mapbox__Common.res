module Impl = (
  T: {
    type t
  },
) => {
  @send external toArray: T.t => array<float> = "toArray"
  @send external toString: T.t => string = "toString"
}
