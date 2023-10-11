[@react.component]
let make = () => {
  let appContext = React.useContext(AppContextProvider.appContext);
  let (oscillatorIndex, setOscillatorIndex) = React.useState(() => 1);
  let (oscillators, setOscillators) = React.useState(() => [1]);

  let addOscillator = () => {
    setOscillators(oList => {[oscillatorIndex + 1, ...oList]});
    setOscillatorIndex(idx => idx + 1);
  };

  let removeOscillator =
    React.useCallback0((osc: int, ()) => {
      setOscillators(oList => oList |> List.filter(o => o != osc))
    });

  <div>
    <button onClick={_ => addOscillator()} className="unit-container">
      {React.string("Add Oscillator")}
    </button>
    <div>
      {switch (appContext.lfoOutputGain) {
       | Some(outputGain) =>
         oscillators
         |> List.map(osc =>
              <OscillatorUnit
                key={string_of_int(osc)}
                name={"OSCILLATOR " ++ string_of_int(osc)}
                targetOutput={Some(outputGain)}
                alone={oscillators |> List.length == 1}
                remove={removeOscillator(osc)}
              />
            )
         |> Array.of_list
         |> ReasonReact.array
       | None => ReasonReact.null
       }}
    </div>
  </div>;
};
