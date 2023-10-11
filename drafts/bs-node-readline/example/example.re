let options =
  Readline.interfaceOptions(
    ~input=[%raw "process.stdin"],
    ~output=[%raw "process.stdout"],
    (),
  );

let readline = Readline.createInterface(options);
let yes = [%re "/yes|y/gi"];
let no = [%re "/no|n/gi"];

readline->(
            Readline.question("Is ReasonML and BuckleScript awesome? ", answer => {
              switch (answer) {
              | a when Js.Re.test_(yes, a) => print_endline("You know it!")
              | a when Js.Re.test_(no, a) =>
                print_endline("You need to revaluate your answer")
              | a =>
                print_endline(
                  {j| I don't have a variant for your answer 😦: $a |j},
                )
              };
              Readline.close(readline);
            })
          );