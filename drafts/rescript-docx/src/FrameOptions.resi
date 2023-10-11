module DropCapType: {
  type t
  let drop: t
  let margin: t
  let none: t
}

module HeightRule: {
  type t
  /** At least the value specified */
  let atLeast: t
  /** Height is determined based on the content, so value is ignored. */
  let auto: t
  /** Exactly the value specified */
  let exact: t
}

module FrameWrap: {
  type t
  let around: t
  let auto: t
  let none: t
  let not_beside: t
  let through: t
  let tight: t
}

module FrameAnchorType: {
  type t
  let margin: t
  let page: t
  let text: t
}

module HorizontalPositionAlign: {
  type t
  let center: t
  let inside: t
  let left: t
  let outside: t
  let right: t
}

module VerticalPositionAlign: {
  type t
  let bottom: t
  let center: t
  let inside: t
  let outside: t
  let top: t
}
type anchor = {horizontal: FrameAnchorType.t, vertical: FrameAnchorType.t}

type rec xyFrameOptions = {
  anchor: anchor,
  anchorLock?: bool,
  dropCap?: DropCapType.t,
  height: float,
  lines?: float,
  position: position,
  rule?: HeightRule.t,
  width: float,
  wrap?: FrameWrap.t,
}
and position = {
  x: float,
  y: float,
}

type rec alignmentFrameOptions = {
  alignment: alignment,
  anchor: anchor,
  anchorLock?: bool,
  dropCap?: DropCapType.t,
  height: float,
  lines?: float,
  rule?: HeightRule.t,
  space?: space,
  width: float,
  wrap?: FrameWrap.t,
}
and alignment = {
  x: HorizontalPositionAlign.t,
  y: VerticalPositionAlign.t,
}
and space = {
  horizontal: float,
  vertical: float,
}

/** @see https://docx.js.org/api/types/IFrameOptions.html */
@unwrap
type t = XYFrameOptions(xyFrameOptions) | AlignmentFrameOptions(alignmentFrameOptions)
