module Types = {
  type paragraph
  type table

  module ParagraphOrTable = {
    type t

    external fromParagraph: paragraph => t = "%identity"
    external fromTable: table => t = "%identity"
  }

  module Percentage = {
    type t

    let make = (~negative=false, ~val: float) =>
      `${negative ? "-" : ""}${val->Belt.Float.toString}%`
  }

  module Number = {
    type t

    external fromFloat: float => t = "%identity"
  }

  module Bool = {
    type t

    external fromBool: bool => t = "%identity"
  }

  // TODO: should be more precise and model the fact that the value could be a 'positive' universal measure
  module NumberOrUniversalMeasure = {
    include Number

    external fromUniversalMeasure: string => t = "%identity"
  }

  module NumberOrPositiveUniversalMeasure = {
    include Number

    external fromPositiveUniversalMeasure: string => t = "%identity"
  }

  module BoolOrNumberOrUniversalMeasure = {
    include NumberOrUniversalMeasure

    external fromBool: bool => t = "%identity"
  }

  module NumberOrPercentageOrUniversalMeasure = {
    include NumberOrUniversalMeasure

    external fromPercentage: Percentage.t => t = "%identity"
  }

  module BoolOrString = {
    type t

    external fromBool: bool => t = "%identity"
    external fromString: string => t = "%identity"
  }

  type numbering = {
    custom?: bool,
    instance?: float,
    level: int,
    reference: string,
  }
}
