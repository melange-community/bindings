module Utils = {
  // get is needed because I don't know how to bind to a
  // javascript object like LinearScale that can also be
  // called like a function i.e.
  // js:  var xScale = LinearScale(); xScale(datapoint);
  //
  // so I use the bs.raw escape hatch annotated with types
  // and then immediately call it with some values of those types
  // for some reason merlin thinks the called values aren't used?
  let get = (this: 'this, value: 'value): 'value =>
    [%raw
      {|
         function(callable, value) { return callable(value); }
    |}
    ](
      this,
      value,
    );
};

module Select = {
  type t;
  [@bs.module "d3"] external select: Dom.element => t = "select";
  [@bs.send] external call: (t, 'a) => unit = "call";
  [@bs.send] external transition: (t, unit) => t = "transition";
  [@bs.send] external attr: (t, string, 'thing) => t = "attr";
};

module S = {
  include Select;
}; // easier typing

module ScaleBand = {
  type t;
  [@bs.module "d3"] external create: unit => t = "scaleBand";
  [@bs.send] external range: (t, array(int)) => t = "range";
  [@bs.send] external padding: (t, float) => t = "padding";
  let get = (this: t, value: 'value): 'value => {
    Utils.get(this, value);
  };
  [@bs.module "d3"] external axisBottom: t => 'a = "axisBottom";
  [@bs.send] external bandwidth: (t, unit) => 'a = "bandwidth";
  [@bs.send] external domain: (t, array('a)) => unit = "domain";
};

module ScaleLinear = {
  type t;
  [@bs.module "d3"] external create: unit => t = "scaleLinear";
  [@bs.send] external range: (t, array(int)) => t = "range";
  let get = (this: t, value: 'value): 'value => {
    Utils.get(this, value);
  };
  [@bs.module "d3"] external axisLeft: t => 'a = "axisLeft";
  [@bs.send] external domain: (t, array('a)) => unit = "domain";
};
