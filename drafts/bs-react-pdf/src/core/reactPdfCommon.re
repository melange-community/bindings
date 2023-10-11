let make = (reactClass, props, ~key: option(string)=?, ~style=Js.Obj.empty(), children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Obj.assign(props, {"key": Js.Null_undefined.from_opt(key), "style": style}),
    children
  );
