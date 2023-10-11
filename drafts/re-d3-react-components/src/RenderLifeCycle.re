module type EffectImmediacy = {
  let effect: (unit => option(unit => unit)) => unit;
  let effect0: (unit => option(unit => unit)) => unit;
  let effect1: (unit => option(unit => unit), array('a)) => unit;
  let effect2: (unit => option(unit => unit), ('a, 'b)) => unit;
};

module SynchronousEffectImmediacy: EffectImmediacy = {
  let effect = React.useLayoutEffect;
  let effect0 = React.useLayoutEffect0;
  let effect1 = React.useLayoutEffect1;
  let effect2 = React.useLayoutEffect2;
};

module AsyncEffectImmediacy: EffectImmediacy = {
  let effect = React.useEffect;
  let effect0 = React.useEffect0;
  let effect1 = React.useEffect1;
  let effect2 = React.useEffect2;
};

module Make = (EI: EffectImmediacy) => {
  /* type t = { */
  /*   firstRender: unit => unit, */
  /*   updateRender: unit => unit, */
  /*   lastRender: unit => unit, */
  /* }; */

  let noop = () => {
    ();
  };

  let render = (~firstRender, ~updateRender, ~lastRender) => {
    let runsOnce = [||];
    let isFirstRender = React.useRef(true);
    EI.effect(() => {
      if (!isFirstRender->React.Ref.current) {
        Js.log("Do update render");
        updateRender();
      } else {
        Js.log("noop update render");
        noop();
      };
      None;
    });

    runsOnce
    |> EI.effect1(() => {
         if (isFirstRender->React.Ref.current) {
           Js.log("set flag to false");
           isFirstRender->React.Ref.setCurrent(false);
           Js.log("Do first render");
           firstRender();
         } else {
           Js.log("noop first render");
           noop();
         };
         Some(
           () => {
             Js.log("do last render");
             lastRender();
           },
         );
       });
    ();
  };
};
