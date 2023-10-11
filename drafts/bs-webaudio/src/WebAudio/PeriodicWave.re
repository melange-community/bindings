type periodicWave;

type t = periodicWave;

let toTypedArray = (floatArray: array(Complex.t)) => {
  let realCoefficients =
    Array.map((x: Complex.t) => x.re, floatArray)
    ->Js_typed_array.Float32Array.make;
  let imaginaryCoefficients =
    Array.map((x: Complex.t) => x.im, floatArray)
    ->Js_typed_array.Float32Array.make;
  (realCoefficients, imaginaryCoefficients);
};

let calculateCoefficients = (samples: array(float)) => {
  samples
  |> Array.map(value => Complex.{re: value, im: 0.0})
  |> FFT.fft
  |> toTypedArray;
};
