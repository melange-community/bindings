type margin = {
  top: int,
  right: int,
  bottom: int,
  left: int,
};

module RLC = RenderLifeCycle.Make(RenderLifeCycle.SynchronousEffectImmediacy);
//module RLC = RenderLifeCycle.Make(RenderLifeCycle.AsyncEffectImmediacy);

module AxisBottom = {
  [@react.component]
  let make = (~height: int, ~xScale: D3.ScaleBand.t) => {
    let gRef = React.useRef(Js.Nullable.null);
    RLC.render(
      ~firstRender=
        () => {
          Js.log("AxisBottom first render");
          switch (gRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            //D3.call(s, axis) == foreach thing in s: axis(thing)
            D3.(S.select(element)->S.call(ScaleBand.axisBottom(xScale)))
          | None => ()
          };
        },
      ~updateRender=
        () => {
          Js.log("AxisBottom update render");
          switch (gRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            D3.(
              S.select(element)
              ->S.transition()
              ->S.call(ScaleBand.axisBottom(xScale))
            )
          | None => ()
          };
        },
      ~lastRender=() => Js.log("finished AxiBottom"),
    );
    <g
      transform={j|translate(0, $height)|j}
      ref={ReactDOMRe.Ref.domRef(gRef)}
    />;
  };
};

module AxisLeft = {
  [@react.component]
  let make = (~yScale: D3.ScaleLinear.t) => {
    let gRef = React.useRef(Js.Nullable.null);
    RLC.render(
      ~firstRender=
        () => {
          Js.log("AxisLeft first render");
          switch (gRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            D3.(S.select(element)->S.call(ScaleLinear.axisLeft(yScale)))
          | None => ()
          };
        },
      ~updateRender=
        () => {
          Js.log("AxisLeft update render");
          switch (gRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            D3.(
              S.select(element)
              ->S.transition()
              ->S.call(ScaleLinear.axisLeft(yScale))
            )
          | None => ()
          };
        },
      ~lastRender=() => Js.log("Finished AxisLeft"),
    );
    <g ref={ReactDOMRe.Ref.domRef(gRef)} />;
  };
};

module Bar = {
  [@react.component]
  let make =
      (
        ~datum: Data.datum,
        ~width: int,
        ~height: int,
        ~xScale: D3.ScaleBand.t,
        ~yScale: D3.ScaleLinear.t,
      ) => {
    let rectRef = React.useRef(Js.Nullable.null);

    RLC.render(
      ~firstRender=
        () => {
          Js.log("Bar first render");
          switch (rectRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            ignore(
              D3.S.(
                select(element)
                ->attr("fill", "green")
                ->attr("x", xScale->D3.ScaleBand.get(datum.date))
                ->attr("y", yScale->D3.ScaleLinear.get(datum.value))
                ->attr("height", 0)
                ->attr("width", xScale->D3.ScaleBand.bandwidth())
                ->transition()
                ->attr(
                    "height",
                    height - yScale->D3.ScaleLinear.get(datum.value),
                  )
              ),
            )
          | None => ()
          };
        },
      ~updateRender=
        () => {
          Js.log("AxisLeft update render");
          switch (rectRef->React.Ref.current->Js.Nullable.toOption) {
          | Some(element) =>
            ignore(
              D3.S.(
                select(element)
                ->attr("fill", "blue")
                ->transition()
                ->attr("x", xScale->D3.ScaleBand.get(datum.date))
                ->attr("y", yScale->D3.ScaleLinear.get(datum.value))
                ->attr("width", xScale->D3.ScaleBand.bandwidth())
                ->attr(
                    "height",
                    height - yScale->D3.ScaleLinear.get(datum.value),
                  )
              ),
            )
          | None => ()
          };
        },
      ~lastRender=() => Js.log("finished bar"),
    );

    <rect ref={ReactDOMRe.Ref.domRef(rectRef)} />;
  };
};

module Bars = {
  [@react.component]
  let make =
      (
        ~data: Data.data,
        ~width: int,
        ~height: int,
        ~xScale: D3.ScaleBand.t,
        ~yScale: D3.ScaleLinear.t,
      ) => {
    let bars =
      data
      ->Array.map(datum => {
          <Bar
            key={datum.id->string_of_int}
            datum
            height
            width
            xScale
            yScale
          />
        })
      ->React.array;

    <g className="bars"> {height > 0 && width > 0 ? bars : React.null} </g>;
  };
};

module Svg = {
  [@react.component]
  let make = (~svgHeight: int, ~svgWidth: int, ~data: Data.data) => {
    let margin = {top: 20, right: 20, bottom: 30, left: 40};
    let width = svgWidth - margin.left - margin.right;
    let height = svgHeight - margin.top - margin.bottom;
    let xScale = D3.ScaleBand.(create()->range([|0, width|])->padding(0.1));
    let yScale = D3.ScaleLinear.(create()->range([|height, 0|]));
    //    [%debugger];
    Js.log(xScale);
    Js.log(yScale);
    xScale->D3.ScaleBand.domain(data->Array.map(d => d.date));
    yScale->D3.ScaleLinear.domain([|
      0,
      data->Array.reduce(0, (acc, d) =>
        if (d.value > acc) {
          d.value;
        } else {
          acc;
        }
      ),
    |]);
    Js.log(xScale);
    Js.log(yScale);
    <svg height={svgHeight->string_of_int} width={svgWidth->string_of_int}>
      <g>
        <AxisBottom height xScale />
        <AxisLeft yScale />
        <Bars data height width xScale yScale />
      </g>
    </svg>;
  };
};

[@react.component]
let make = () => {
  let (data, setData) = React.useState(() => Data.getData());
  <div>
    <button onClick={_ => setData(_ => Data.getData())}>
      "DATA"->React.string
    </button>
    <Svg svgHeight=500 svgWidth=960 data />
  </div>;
};
