[@bs.val] external setTimeout: (unit => unit, int) => float = "setTimeout";
[@bs.val] external infinity: float = "Infinity";

let example1 =
  Typing.make(
    "#typing-example1",
    Typing.options(
      ~strings=[|
        {j|Typing animation in ReasonML with the help of Typed.js|j},
      |],
      ~typeSpeed=60,
      ~typeDelay=30,
      ~loop=true,
      ~loopCount=infinity,
      ~onDestroy=
        self => {
          let _ = setTimeout(() => self##reset(true), 4000);
          ();
        },
      (),
    ),
  );

let _ = setTimeout(() => example1##destroy(), 2000);

let example2 =
  Typing.make(
    "#typing-example2",
    Typing.options(
      ~stringsElement="#typed-strings",
      ~typeSpeed=50,
      ~typeDelay=30,
      ~loop=true,
      ~loopCount=5.0,
      (),
    ),
  );
