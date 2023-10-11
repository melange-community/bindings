type bn;
type red;
type red_context;

[@bs.deriving {jsConverter: newType}]
type egcd = {
  a: bn,
  b: bn,
  gcd: bn
};

[@bs.deriving {jsConverter: newType}]
type prime = [ | `k256 | `p224 | `p192 | `p25519];
