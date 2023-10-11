module DropCapType = {
  type t

  @module("docx") @scope("DropCapType")
  external drop: t = "DROP"

  @module("docx") @scope("DropCapType")
  external margin: t = "MARGIN"

  @module("docx") @scope("DropCapType")
  external none: t = "NONE"
}

module HeightRule = {
  type t

  @module("docx") @scope("HeightRule")
  external atLeast: t = "ATLEAST"

  @module("docx") @scope("HeightRule")
  external auto: t = "AUTO"

  @module("docx") @scope("HeightRule")
  external exact: t = "EXACT"
}

module FrameWrap = {
  type t

  @module("docx") @scope("FrameWrap")
  external around: t = "AROUND"

  @module("docx") @scope("FrameWrap")
  external auto: t = "AUTO"

  @module("docx") @scope("FrameWrap")
  external none: t = "NONE"

  @module("docx") @scope("FrameWrap")
  external not_beside: t = "NOT_BESIDE"

  @module("docx") @scope("FrameWrap")
  external through: t = "THROUGH"

  @module("docx") @scope("FrameWrap")
  external tight: t = "TIGHT"
}

module FrameAnchorType = {
  type t

  @module("docx") @scope("FrameAnchorType")
  external margin: t = "MARGIN"

  @module("docx") @scope("FrameAnchorType")
  external page: t = "PAGE"

  @module("docx") @scope("FrameAnchorType")
  external text: t = "TEXT"
}

module HorizontalPositionAlign = {
  type t

  @module("docx") @scope("HorizontalPositionAlign")
  external center: t = "CENTER"

  @module("docx") @scope("HorizontalPositionAlign")
  external inside: t = "INSIDE"

  @module("docx") @scope("HorizontalPositionAlign")
  external left: t = "LEFT"

  @module("docx") @scope("HorizontalPositionAlign")
  external outside: t = "OUTSIDE"

  @module("docx") @scope("HorizontalPositionAlign")
  external right: t = "RIGHT"
}

module VerticalPositionAlign = {
  type t

  @module("docx") @scope("VerticalPositionAlign")
  external bottom: t = "BOTTOM"

  @module("docx") @scope("VerticalPositionAlign")
  external center: t = "CENTER"

  @module("docx") @scope("VerticalPositionAlign")
  external inside: t = "INSIDE"

  @module("docx") @scope("VerticalPositionAlign")
  external outside: t = "OUTSIDE"

  @module("docx") @scope("VerticalPositionAlign")
  external top: t = "TOP"
}

type anchor = {
  horizontal: FrameAnchorType.t,
  vertical: FrameAnchorType.t,
}

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

@unwrap
type t = XYFrameOptions(xyFrameOptions) | AlignmentFrameOptions(alignmentFrameOptions)
