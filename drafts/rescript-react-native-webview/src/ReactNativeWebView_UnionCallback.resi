module Make: (
  T: {
    type union
    type navigationEvent
    type errorEvent
  },
) =>
{
  type t

  let make: (
    ~navigationCallback: T.navigationEvent => unit,
    ~errorCallback: T.errorEvent => unit,
  ) => t

  let uncurriedMake: (
    ~navigationCallback: (. T.navigationEvent) => unit,
    ~errorCallback: (. T.errorEvent) => unit,
  ) => t
}
