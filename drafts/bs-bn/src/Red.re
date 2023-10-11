[@bs.module "bn.js"] external red : Types.bn => Types.red_context = "";

[@bs.module "bn.js"]
external redWithPrime : Types.abs_prime => Types.red_context = "red";

let redWithPrime = a => redWithPrime(Types.primeToJs(a));

[@bs.module "bn.js"] external mont : Types.bn => Types.red_context = "";

[@bs.module "bn.js"]
external montWithPrime : Types.abs_prime => Types.red_context = "mont";

let montWithPrime = a => montWithPrime(Types.primeToJs(a));

[@bs.send] external fromRed : Types.red => Types.bn = "";

[@bs.send.pipe : Types.red] external redAdd : Types.red => Types.red = "";

[@bs.send.pipe : Types.red] external redIAdd : Types.red => unit = "";

[@bs.send.pipe : Types.red] external redSub : Types.red => Types.red = "";

[@bs.send.pipe : Types.red] external redISub : Types.red => unit = "";

[@bs.send.pipe : Types.red] external redShl: (int) => Types.red = "";

[@bs.send.pipe : Types.red] external redMul : Types.red => Types.red = "";

[@bs.send.pipe : Types.red] external redIMul : Types.red => unit = "";

[@bs.send] external redSqr : Types.red => Types.red = "";

[@bs.send] external redISqr : Types.red => unit = "";

[@bs.send] external redSqrt : Types.red => Types.red = "";

[@bs.send] external redInvm : Types.red => Types.red = "";

[@bs.send] external redNeg : Types.red => Types.red = "";

[@bs.send.pipe : Types.red] external redPow : Types.bn => Types.red = "";
