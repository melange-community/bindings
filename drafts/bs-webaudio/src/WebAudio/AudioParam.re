type audioParam;

type t = audioParam;

[@bs.get] external defaultValue: t => float = "defaultValue";
[@bs.get] external maxValue: t => float = "maxValue";
[@bs.get] external minValue: t => float = "minValue";
[@bs.get] external getValue: t => float = "value";
[@bs.set] external setValue: (t, float) => unit = "value";

[@bs.send.pipe: t]
external setValueAtTime: (~value: float, ~startTime: float) => unit =
  "setValueAtTime";

[@bs.send.pipe: t]
external linearRampToValueAtTime: (~value: float, ~endTime: float) => unit =
  "linearRampToValueAtTime";

[@bs.send.pipe: t]
external exponentialRampToValueAtTime: (~value: float, ~endTime: float) => unit =
  "exponentialRampToValueAtTime";

[@bs.send.pipe: t]
external setTargetAtTime:
  (~target: float, ~startTime: float, ~timeConstant: float) => unit =
  "setTargetAtTime";

[@bs.send.pipe: t]
external setValueCurveAtTime:
  (~curve: array(float), ~startTime: float, ~duration: float) => unit =
  "setValueCurveAtTime";

[@bs.send.pipe: t]
external cancelScheduledValues: (~startTime: float) => unit =
  "cancelScheduledValues";

[@bs.send.pipe: t]
external cancelAndHoldAtTime: (~cancelTime: float) => unit =
  "cancelAndHoldAtTime";
