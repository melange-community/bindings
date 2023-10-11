type t

@get external getDefaultValue: t => float = "defaultValue"

@get external getMaxValue: t => float = "maxValue"

@get external getMinValue: t => float = "minValue"

@get external getValue: t => float = "value"

@set external setValue: (t, float) => unit = "value"

@send external setValueAtTime: (t, ~value: float, ~startTime: float) => unit = "setValueAtTime"

@send
external linearRampToValueAtTime: (t, ~value: float, ~endTime: float) => t =
  "linearRampToValueAtTime"

@send
external exponentialRampToValueAtTime: (t, ~value: float, ~endTime: float) => t =
  "exponentialRampToValueAtTime"

@send
external setTargetAtTime: (t, ~target: float, ~startTime: float, ~timeConstant: float) => t =
  "setTargetAtTime"

@send
external setValueCurveAtTime: (t, ~values: array<float>, ~startTime: float, ~duration: float) => t =
  "SetValueCurveAtTime"

@send external cancelScheduledValues: (t, ~startTime: float) => t = "cancelScheduledValues"

@send external cancelAndHoldAtTime: (t, ~cancelTime: float) => t = "cancelAndHoldAtTime"
