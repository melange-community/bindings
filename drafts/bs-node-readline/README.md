# bs-node-readline

Low level bindings for Node's readline

## Example

```reason
let options =
  Readline.interfaceOptions(
    ~input=[%raw "process.stdin"],
    ~output=[%raw "process.stdout"],
    (),
  );

let readline = Readline.createInterface(options);
let yes = [%re "/yes|y/gi"];
let no = [%re "/no|n/gi"];

readline
|. Readline.question("Is ReasonML and BuckleScript awesome? ", answer => {
     switch (answer) {
     | a when Js.Re.test(a, yes) => print_endline("You know it!")
     | a when Js.Re.test(a, no) =>
       print_endline("You need to revaluate your answer")
     | a =>
       print_endline({j| I don't have a variant for your answer 😦: $a |j})
     };
     Readline.close(readline);
   });
```

then you can run the compiled JS file with Node:
<img src="./Screen Shot 2018-07-05 at 8.46.24 AM.png" alt="Example of binding" />

## Installation

```sh
npm i --save bs-node-readline
```

then add
Then add `bs-node-readline` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["bs-node-readline"]
}
```

## Usage

See example in `example/example.re`. Follows the NodeJS API found here: https://nodejs.org/api/readline.html
