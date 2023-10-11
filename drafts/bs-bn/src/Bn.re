type t = Types.bn;

/* ---- Arithmetic ---- */
/* Add */
[@bs.send.pipe : t] external add : t => t = "";

[@bs.send.pipe : t] external addn : float => t = "";

[@bs.send.pipe : t] external iadd : t => unit = "";

[@bs.send.pipe : t] external iaddn : float => unit = "";

[@bs.send.pipe : t] external sub : t => t = "";

[@bs.send.pipe : t] external subn : float => t = "";

[@bs.send.pipe : t] external isub : t => unit = "";

[@bs.send.pipe : t] external isubn : float => unit = "";

[@bs.send] external abs : t => t = "";

[@bs.send] external iabs : t => unit = "";

[@bs.send.pipe : t] external mul : t => t = "";

[@bs.send.pipe : t] external mulf : t => t = "";

[@bs.send.pipe : t] external imul : t => unit = "";

[@bs.send.pipe : t] external imuln : float => unit = "";

[@bs.send.pipe : t] external muln : float => t = "";

[@bs.send] external sqr : t => t = "";

[@bs.send] external isqr : t => unit = "";

[@bs.send.pipe : t] external pow : t => t = "";

[@bs.send.pipe : t] external div : t => t = "";

[@bs.send.pipe : t] external mod_ : t => t = "mod";

[@bs.send.pipe : t] external umod : t => t = "";

[@bs.send.pipe : t] external divRound : t => t = "";

[@bs.send.pipe : t] external modn : float => t = "";

[@bs.send.pipe : t] external idivn : float => unit = "";

[@bs.send.pipe : t] external divn : float => t = "";

[@bs.send.pipe : t] external cmp : t => Equality.abs_t = "";

let cmp = (a, b) => Equality.tFromJs(cmp(a, b));

[@bs.send.pipe : t] external cmpn : float => Equality.abs_t = "";

let cmpn = (a, b) => Equality.tFromJs(cmpn(a, b));

[@bs.send.pipe : t] external ucmp : t => Equality.abs_t = "";

let ucmp = (a, b) => Equality.tFromJs(ucmp(a, b));

[@bs.send.pipe : t] external gtn : float => bool = "";

[@bs.send.pipe : t] external gt : t => bool = "";

[@bs.send.pipe : t] external gten : float => bool = "";

[@bs.send.pipe : t] external gte : t => bool = "";

[@bs.send.pipe : t] external ltn : float => bool = "";

[@bs.send.pipe : t] external lt : t => bool = "";

[@bs.send.pipe : t] external lten : float => bool = "";

[@bs.send.pipe : t] external lte : t => bool = "";

[@bs.send.pipe : t] external eqn : float => bool = "";

[@bs.send.pipe : t] external eq : t => bool = "";

[@bs.send] external neg : t => t = "";

[@bs.send] external ineg : t => unit = "";

[@bs.send] external isNeg : t => bool = "";

[@bs.send] external isOdd : t => bool = "";

[@bs.send] external isEven : t => bool = "";

[@bs.send] external isZero : t => bool = "";

[@bs.send] external bitLength : t => int = "";

[@bs.send] external byteLength : t => int = "";

[@bs.send.pipe : t] external toTwos : int => t = "";

[@bs.send.pipe : t] external fromTwos : int => t = "";

[@bs.send] external zeroBits : t => int = "";

[@bs.send.pipe : t] external invm : t => t = "";

[@bs.send.pipe : t] external gcd : t => t = "";

[@bs.send.pipe : t] external egcd : t => Types.abs_egcd = "";

let egcd = (a, b) => Types.egcdFromJs(egcd(a, b));

[@bs.module "bn.js"] external max : (t, t) => t = "";

[@bs.module "bn.js"] external min : (t, t) => t = "";

[@bs.send.pipe : t] external iushln : int => unit = "";

[@bs.send.pipe : t] external ishln : int => unit = "";

[@bs.send.pipe : t] external iushrn : int => unit = "";

[@bs.send.pipe : t] external ishrn : int => unit = "";

[@bs.send.pipe : t] external shln : int => t = "";

[@bs.send.pipe : t] external ushln : int => t = "";

[@bs.send.pipe : t] external shrn : int => t = "";

[@bs.send.pipe : t] external ushrn : int => t = "";

[@bs.send.pipe : t] external andln : int => int = "";

[@bs.send.pipe : t] external bincn : int => unit = "";

[@bs.send.pipe : t] external testn : int => bool = "";

[@bs.send.pipe : t] external imaskn : int => unit = "";

[@bs.send.pipe : t] external maskn : int => t = "";

[@bs.send.pipe : t] external iuor : t => unit = "";

[@bs.send.pipe : t] external ior : t => unit = "";

[@bs.send.pipe : t] external uor : t => t = "";

[@bs.send.pipe : t] external or_ : t => t = "or";

[@bs.send.pipe : t] external iuand : t => unit = "";

[@bs.send.pipe : t] external iand : t => unit = "";

[@bs.send.pipe : t] external uand : t => t = "";

[@bs.send.pipe : t] external and_ : t => t = "and";

[@bs.send.pipe : t] external iuxor : t => unit = "";

[@bs.send.pipe : t] external ixor : t => unit = "";

[@bs.send.pipe : t] external uxor : t => t = "";

[@bs.send.pipe : t] external xor : t => t = "";

[@bs.send.pipe : t] external inotn : int => unit = "";

[@bs.send.pipe : t] external notn : int => t = "";

[@bs.send.pipe : t] external setn : (int, bool) => unit = "";

/* ---- Fast reduction ---- */
[@bs.send.pipe : t] external toRed : Types.red_context => Types.red = "";

/* ---- Export ---- */
/* To string */
[@bs.send] external toNumber : t => float = "";

[@bs.send] external toJSON : t => string = "";

[@bs.send.pipe : t]
external toStringWithBaseAndPadding : (int, int) => string = "toString";

[@bs.send.pipe : t]
external toStringWithPadding : (int, int) => string = "toString";

[@bs.send.pipe : t] external toStringWithBase : int => string = "toString";

[@bs.send.pipe : t] external toStringDefault : unit => string = "toString";

let toString = (~base=?, ~padding=?) =>
  switch (base, padding) {
  | (Some(b), Some(p)) => toStringWithBaseAndPadding(b, p)
  | (Some(b), None) => toStringWithBase(b)
  | (None, Some(p)) => toStringWithPadding(10, p)
  | (None, None) => toStringDefault()
  };

/* To array */
[@bs.send.pipe : t]
external toArrayWithEndian : Endianness.abs_t => array(int) = "toArray";

[@bs.send.pipe : t] external toArrayWithLength : int => array(int) = "toArray";

[@bs.send.pipe : t]
external toArrayWithEndianAndLength : (Endianness.abs_t, int) => array(int) =
  "toArray";

[@bs.send.pipe : t] external toArrayDefault : unit => array(int) = "toArray";

let toArray = (~endian=?, ~length=?) =>
  switch (endian, length) {
  | (Some(e), Some(l)) => toArrayWithEndianAndLength(Endianness.tToJs(e), l)
  | (Some(e), None) => toArrayWithEndian(Endianness.tToJs(e))
  | (None, Some(l)) => toArrayWithLength(l)
  | (None, None) => toArrayDefault()
  };

/* To Buffer */
[@bs.send.pipe : t]
external toBufferWithEndian : Endianness.abs_t => Node.Buffer.t = "toBuffer";

[@bs.send.pipe : t]
external toBufferWithLength : int => Node.Buffer.t = "toBuffer";

[@bs.send.pipe : t]
external toBufferWithEndianAndLength : (Endianness.abs_t, int) => Node.Buffer.t =
  "toBuffer";

[@bs.send.pipe : t]
external toBufferDefault : unit => Node.Buffer.t = "toBuffer";

let toBuffer = (~endian=?, ~length=?) =>
  switch (endian, length) {
  | (Some(e), Some(l)) => toBufferWithEndianAndLength(Endianness.tToJs(e), l)
  | (Some(e), None) => toBufferWithEndian(Endianness.tToJs(e))
  | (None, Some(l)) => toBufferWithLength(l)
  | (None, None) => toBufferDefault()
  };

/* ---- Creation ---- */
/* From float */
[@bs.module "bn.js"] [@bs.new] external numberFromFloat : float => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithBase : (float, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithEndianness : (float, Endianness.abs_t) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromFloatWithBaseAndEndianness :
  (float, int, Endianness.abs_t) => t =
  "BN";

let fromFloat = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromFloatWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromFloatWithBase(v, b)
  | (None, Some(e)) => numberFromFloatWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromFloat(v)
  };

/* From string */
[@bs.module "bn.js"] [@bs.new] external numberFromString : string => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithBase : (string, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithEndianness : (string, Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromStringWithBaseAndEndianness :
  (string, int, Endianness.abs_t) => t =
  "BN";

let fromString = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromStringWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromStringWithBase(v, b)
  | (None, Some(e)) => numberFromStringWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromString(v)
  };

/* From array */
[@bs.module "bn.js"] [@bs.new]
external numberFromArray : array(int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithBase : (array(int), int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithEndianness : (array(int), Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromArrayWithBaseAndEndianness :
  (array(int), int, Endianness.abs_t) => t =
  "BN";

let fromArray = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromArrayWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromArrayWithBase(v, b)
  | (None, Some(e)) => numberFromArrayWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromArray(v)
  };

/* From buffer */
[@bs.module "bn.js"] [@bs.new]
external numberFromBuffer : Node.Buffer.t => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithBase : (Node.Buffer.t, int) => t = "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithEndianness :
  (Node.Buffer.t, Endianness.abs_t) => t =
  "BN";

[@bs.module "bn.js"] [@bs.new]
external numberFromBufferWithBaseAndEndianness :
  (Node.Buffer.t, int, Endianness.abs_t) => t =
  "BN";

let fromBuffer = (~base=?, ~endian=?, v) =>
  switch (base, endian) {
  | (Some(b), Some(e)) =>
    numberFromBufferWithBaseAndEndianness(v, b, Endianness.tToJs(e))
  | (Some(b), None) => numberFromBufferWithBase(v, b)
  | (None, Some(e)) => numberFromBufferWithEndianness(v, Endianness.tToJs(e))
  | (None, None) => numberFromBuffer(v)
  };

/* Clone */
[@bs.module "bn.js"] [@bs.new] external clone : t => t = "BN";

/* Utils */
[@bs.module "bn.js"] [@bs.new] external copy : (t, t) => unit = "BN";

[@bs.module "bn.js"] [@bs.new] external inspect : t => string = "BN";

include Red;