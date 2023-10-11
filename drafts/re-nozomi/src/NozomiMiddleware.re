module Basic = {
  type t =
    (
      NozomiRequest.Basic.t,
      NozomiResponse.Basic.t,
      unit => [@bs.uncurry] unit
    ) =>
    [@bs.uncurry] unit;
};

type t =
  (
    ~request: NozomiRequest.t,
    ~response: NozomiResponse.t,
    ~next: unit => unit
  ) =>
  [@bs.uncurry] unit;

let bindBasic = (f, req, res, next) =>
  f(
    ~request=NozomiRequest.from(req),
    ~response=NozomiResponse.from(res),
    ~next
  );

let basic = (f: t) : Basic.t => bindBasic(f);