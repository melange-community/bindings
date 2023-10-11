type rec t = {
  color?: string,
  fill?: string,
  @as("type") type_?: shadingType,
}
and shadingType = [
  | #clear
  | #diagCross
  | #diagStripe
  | #horzCross
  | #horzStripe
  | #nil
  | #pct5
  | #pct10
  | #pct12
  | #pct15
  | #pct20
  | #pct25
  | #pct30
  | #pct35
  | #pct37
  | #pct40
  | #pct45
  | #pct50
  | #pct55
  | #pct60
  | #pct62
  | #pct65
  | #pct70
  | #pct75
  | #pct80
  | #pct85
  | #pct87
  | #pct90
  | #pct95
  | #reverseDiagStripe
  | #solid
  | #thinDiagCross
  | #thinDiagStripe
  | #thinHorzCross
  | #thinReverseDiagStripe
  | #thinVertStripe
  | #vertStripe
]
