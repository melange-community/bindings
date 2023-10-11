type t = Types.bn;

/* ------- Arithmetic ------- */
/** Returns the addition of two big numbers. */
let add: (t, t) => t;

/** Returns the addition of a float and a big number. */
let addn: (float, t) => t;

/** Adds a big number to another, storing the result in the second (side effect). */
let iadd: (t, t) => unit;

/** Adds a float to a big number, storing the result in the second (side effect). */
let iaddn: (float, t) => unit;

/** Returns the subtraction of two big numbers (the second minus the first). */
let sub: (t, t) => t;

/** Returns the subtraction of a float from a big number. */
let subn: (float, t) => t;

/** Subtracts a big number from another, storing the result in the second (side effect). */
let isub: (t, t) => unit;

/** Subtracts a float from a big number, storing the result in the second (side effect). */
let isubn: (float, t) => unit;

/** Returns the absolute value. */
let abs: t => t;

/** Calculates the absolute value and stores it in the big number passed as param (side effect). */
let iabs: t => unit;

/** Returns the multiplication of two big numbers. */
let mul: (t, t) => t;

/** Returns the multiplication of two big numbers, using FFT. */
let mulf: (t, t) => t;

/** Multiplies a big number with another, storing the result in the second (side effect). */
let imul: (t, t) => unit;

/** Multiplies a float with a big number, storing the result in the second (side effect). */
let imuln: (float, t) => unit;

/** Returns the multiplication of a float with a big number. */
let muln: (float, t) => t;

/** Returns the square root of a big number. */
let sqr: t => t;

/** Calculates the square root of a big number and stores it in the big number passed as param (side effect). */
let isqr: t => unit;

/** Returns the power considering the first param as exponent and the second as base. */
let pow: (t, t) => t;

/** Returns the quotient after dividing two big numbers. The first param is the divisor and the second is the divident: div(a, b) is equivalent to b / a. */
let div: (t, t) => t;

/** Returns the remainder after dividing two big numbers. The first param is the divisor and the second is the divident: mod_(a, b) is equivalent to b % a. */
let mod_: (t, t) => t;

/** Returns the unsigned remainder after dividing two big numbers. The first param is the divisor and the second is the divident: umod(a, b) is equivalent to b % a. */
let umod: (t, t) => t;

/** Returns the rounded quotient after dividing two big numbers. The first param is the divisor and the second is the divident: divRound(a, b) is equivalent to Math.round(b / a). */
let divRound: (t, t) => t;

/** Returns the remainder after dividing a big number by a float. The first param is the divisor and the second is the divident: modn(a, b) is equivalent to b % a. */
let modn: (float, t) => t;

/** Calculates the quotient after dividing a big number by a float, storing the result in the big number (side effect). The first param is the divisor and the second is the divident: idivn(a, b) is equivalent to b / a. */
let idivn: (float, t) => unit;

/** Returns the quotient after dividing a big number by a float. The first param is the divisor and the second is the divident: divn(a, b) is equivalent to b / a. */
let divn: (float, t) => t;

/** Compares two big numbers and returns the results of the comparison (equal, less than, greater). */
let cmp: (t, t) => Equality.t;

/** Compares a float with a big number and returns the results of the comparison (equal, less than, greater). */
let cmpn: (float, t) => Equality.t;

/** Compares two unsigned big numbers and returns the results of the comparison (equal, less than, greater). */
let ucmp: (t, t) => Equality.t;

/** Takes a float and a big number and returns true if the second is greater than the first. */
let gtn: (float, t) => bool;

/** Takes two big numbers and returns true if the second is greater than the first. */
let gt: (t, t) => bool;

/** Takes a float and a big number and returns true if the second is greater or equal than the first. */
let gten: (float, t) => bool;

/** Takes two big numbers and returns true if the second is greater or equal than the first. */
let gte: (t, t) => bool;

/** Takes a float and a big number and returns true if the second is less than the first. */
let ltn: (float, t) => bool;

/** Takes two big numbers and returns true if the second is less than the first. */
let lt: (t, t) => bool;

/** Takes a float and a big number and returns true if the second is less or equal than the first. */
let lten: (float, t) => bool;

/** Takes two big numbers and returns true if the second is less or equal than the first. */
let lte: (t, t) => bool;

/** Takes a float and a big number and returns true if they are equal. */
let eqn: (float, t) => bool;

/** Takes two big numbers and returns true if they are equal. */
let eq: (t, t) => bool;

/** Returns the negative version of a big number. */
let neg: t => t;

/** Calculates the negative version of a big number, storing the result in that same reference (side effect). */
let ineg: t => unit;

/** Returns true if the big number is negative. */
let isNeg: t => bool;

/** Returns true if the number is odd. */
let isOdd: t => bool;

/** Returns true if the number is even. */
let isEven: t => bool;

/** Returns true if the number is zero. */
let isZero: t => bool;

/** Returns the number of used bits in a big number. */
let bitLength: t => int;

/** Returns the number of used bytes in a big number. */
let byteLength: t => int;

/** Returns the two's complement of a given big number, with some width passed as first param. */
let toTwos: (int, t) => t;

/** Returns a big number from a given two's complement, with some width passed as first param. */
let fromTwos: (int, t) => t;

/** Returns the number of trailing zero bits in a big number. */
let zeroBits: t => int;

/** Returns the inverted value of the second param, modulo the first param. */
let invm: (t, t) => t;

/** Returns the greater common divisor of two big numbers. */
let gcd: (t, t) => t;

/** Returns the results of the extended greater common divisor ax + by = gcd(a, b). The result is a record with shape: { a: ..., b: ..., gcd: ... } */
let egcd: (t, t) => Types.egcd;

/** Returns the max of two big numbers. */
let max: (t, t) => t;

/** Returns the min of two big numbers. */
let min: (t, t) => t;

/* ------- Binary ------- */
/** Unsigned shift left n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let iushln: (int, t) => unit;

/** Shift left n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let ishln: (int, t) => unit;

/** Unsigned shift right n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let iushrn: (int, t) => unit;

/** Shift right n bits (first param) a big number (second param), storing the result in the same reference (side effect). */
let ishrn: (int, t) => unit;

/** Returns the result of shifting left n bits (first param) a big number (second param). */
let shln: (int, t) => t;

/** Returns the result of unsigned shifting left n bits (first param) a big number (second param). */
let ushln: (int, t) => t;

/** Returns the result of shifting right n bits (first param) a big number (second param). */
let shrn: (int, t) => t;

/** Returns the result of unsigned shifting right n bits (first param) a big number (second param). */
let ushrn: (int, t) => t;

/** Adds an int and the first word of a big number. */
let andln: (int, t) => int;

/** Increments at the bit position (first param), storing the result in the same reference (side effect). */
let bincn: (int, t) => unit;

/** Tests if bit as position n (first param) is set */
let testn: (int, t) => bool;

/** Return only lowers bits of a big number, storing the result in the same reference (side effect). */
let imaskn: (int, t) => unit;

/** Return only lowers bits of a big number. */
let maskn: (int, t) => t;

/** Applies the binary unsigned `or` operation between two big numbers, storing the result in the second (side effect). */
let iuor: (t, t) => unit;

/** Applies the binary `or` operation between two big numbers, storing the result in the second (side effect). */
let ior: (t, t) => unit;

/** Returns the binary unsigned `or` operation between two big numbers. */
let uor: (t, t) => t;

/** Returns the binary `or` operation between two big numbers. */
let or_: (t, t) => t;

/** Applies the binary unsigned `and` operation between two big numbers, storing the result in the second (side effect). */
let iuand: (t, t) => unit;

/** Applies the binary `and` operation between two big numbers, storing the result in the second (side effect). */
let iand: (t, t) => unit;

/** Returns the binary unsigned `and` operation between two big numbers. */
let uand: (t, t) => t;

/** Returns the binary `and` operation between two big numbers. */
let and_: (t, t) => t;

/** Applies the binary unsigned `xor` operation between two big numbers, storing the result in the second (side effect). */
let iuxor: (t, t) => unit;

/** Applies the binary `xor` operation between two big numbers, storing the result in the second (side effect). */
let ixor: (t, t) => unit;

/** Returns the binary unsigned `xor` operation between two big numbers. */
let uxor: (t, t) => t;

/** Returns the binary `xor` operation between two big numbers. */
let xor: (t, t) => t;

/** Returns the binary `not` operation from a big numbers, taking a given bitwidth as first param, and storing the result in the second (side effect). */
let inotn: (int, t) => unit;

/** Returns the binary `not` operation from a big numbers, taking a given bitwidth as first param. */
let notn: (int, t) => t;

/** Sets the value passed as second param in the position passed as first param, storing the result in the big number passed as third param (side effect). */
let setn: (int, bool, t) => unit;

/* ------- Export ------- */
/** Returns a big number represented as a number. */
let toNumber: t => float;

/** Returns a big number represented as a JSON compatible hex string (alias of toString(~base=16)) */
let toJSON: t => string;

/** Returns a big number represented as a string. */
let toString: (~base: int=?, ~padding: int=?, t) => string;

/** Returns a big number represented as an array. */
let toArray: (~endian: Endianness.t=?, ~length: int=?, t) => array(int);

/** Returns a big number represented as a NodeJS Buffer. */
let toBuffer: (~endian: Endianness.t=?, ~length: int=?, t) => Node.Buffer.t;

/* ------- Import ------- */
/** Creates a big number from a float. */
let fromFloat: (~base: int=?, ~endian: Endianness.t=?, float) => t;

/** Creates a big number from a string. */
let fromString: (~base: int=?, ~endian: Endianness.t=?, string) => t;

/** Creates a big number from an array. */
let fromArray: (~base: int=?, ~endian: Endianness.t=?, array(int)) => t;

/** Creates a big number from a Buffer. */
let fromBuffer: (~base: int=?, ~endian: Endianness.t=?, Node.Buffer.t) => t;

/** Returns a new copy of a big number. */
let clone: t => t;

/* ------- Utils ------- */
/** Copies the big number passed as first param into the big number passed as second param (side effect). */
let copy: (t, t) => unit;

/** For debugging purposes: prints a big number as a string (including structural information). */
let inspect: t => string;

/* ------- Fast reduction ------- */
/** Returns a reduction context using the Plain method. */
let red: t => Types.red_context;

/** Returns a reduction context using the Montgomery method. */
let mont: t => Types.red_context;

/** Given a prime number, returns a reduction context using the Plain method. */
let redWithPrime: Types.prime => Types.red_context;

/** Given a prime number, returns a reduction context using the Montgomery method. */
let montWithPrime: Types.prime => Types.red_context;

/** Converts a big number to a reducted one, taking a reduction context as param. */
let toRed: (Types.red_context, t) => Types.red;

/** Converts a reducted big number to a regular big number. */
let fromRed: Types.red => t;

/** Returns the addition of two reducted big numbers. */
let redAdd: (Types.red, Types.red) => Types.red;

/** Adds two reducted big numbers, storing the result in the instance passed as second param (side effect).  */
let redIAdd: (Types.red, Types.red) => unit;

/** Returns the subtraction of two reducted big numbers (the second minus the first). */
let redSub: (Types.red, Types.red) => Types.red;

/** Subtracts two reducted big numbers (the second minus the first), storing the result in the instance passed as second param (side effect).  */
let redISub: (Types.red, Types.red) => unit;

/** Returns the result of shifting left n bits (first param) a reducted big number (second param). */
let redShl: (int, Types.red) => Types.red;

/** Returns the subtraction of two reducted big numbers.  */
let redMul: (Types.red, Types.red) => Types.red;

/** Returns the subtraction of two reducted big numbers, storing the result in the instance passed as second param (side effect). */
let redIMul: (Types.red, Types.red) => unit;

/** Returns the square root of a reducted big number. */
let redSqr: Types.red => Types.red;

/** Applies the square root of a reducted big number, storing the result in the same instance passed as param (side effect). */
let redISqr: Types.red => unit;

/** Returns the square root modulo reduction context's prime of a reducted big number. */
let redSqrt: Types.red => Types.red;

/** Returns the modular inverse of a reducted big number. */
let redInvm: Types.red => Types.red;

/** Returns the negative version of a reducted big number. */
let redNeg: Types.red => Types.red;

/** Returns the power, considering the first param as exponent (regular big number) and the second as base (reducted big number). */
let redPow: (t, Types.red) => Types.red;


