type t = Js.Promise.t(unit);

type visitor = React.element => Js.Nullable.t(Js.Promise.t(Js.Json.t));

type elementType;

[@bs.deriving abstract]
type elementJS('a) = {
  [@bs.as "type"]
  type_: elementType,
  props: Js.t({..} as 'a),
  key: string,
};

[@bs.send] external toElementJS: React.element => elementJS('a) = "%identity";

[@bs.module]
external ssrPrepass:
  (
  [@bs.unwrap]
  [
    | `PrepassNode(React.element)
    | `PrepassNodeVisitor(React.element, visitor)
  ]
  ) =>
  t =
  "react-ssr-prepass";