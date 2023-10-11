let complexZero = Complex.{re: 0.0, im: 0.0};
let to_complex = (x: float) => Complex.{re: x, im: 0.0};

let rec fft = (vector: array(Complex.t)) => {
  let n = Array.length(vector);
  let x = Array.make(n, complexZero);

  if (n == 1) {
    [|vector[0]|];
  } else {
    let x_evens = Array.make(n / 2, complexZero);
    let x_odds = Array.make(n / 2, complexZero);
    Array.iteri(
      (idx, value) =>
        idx mod 2 == 0
          ? x_evens[idx / 2] = value : x_odds[(idx - 1) / 2] = value,
      vector,
    );

    let x_evens_fft = fft(x_evens);
    let x_odds_fft = fft(x_odds);

    for (k in 0 to n / 2 - 1) {
      let t = x_evens_fft[k];
      let exponent =
        to_complex(
          (-2.0) *. Js.Math._PI *. (float_of_int(k) /. float_of_int(n)),
        )
        ->Complex.mul(Complex.i)
        ->Complex.exp;
      let e = Complex.mul(exponent, x_odds_fft[k]);
      x[k] = Complex.add(t, e);
      x[k + n / 2] = Complex.sub(t, e);
    };

    x;
  };
};
