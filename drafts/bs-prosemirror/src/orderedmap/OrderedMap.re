type t('a);

[@bs.module "orderedmap"] [@bs.scope "default"] external make: Js.Dict.t('a) => t('a) = "from";

[@bs.return nullable] [@bs.send] external get: (t('a), string) => option('a) = "get";

[@bs.send]
external update: (t('a), ~key: string, ~value: 'a, ~newKey: string=?, unit) => t('a) = "update";

[@bs.send] external remove: (t('a), ~key: string) => t('a) = "remove";

[@bs.send] external addToStart: (t('a), ~key: string, ~value: 'a) => t('a) = "addToStart";

[@bs.send] external addToEnd: (t('a), ~key: string, ~value: 'a) => t('a) = "addToEnd";

[@bs.send]
external addBefore: (t('a), ~place: string, ~key: string, ~value: 'a) => t('a) = "addBefore";

[@bs.send] external forEach: (t('a), (~key: string, ~value: 'a) => unit) => unit = "forEach";

[@bs.send] external prepend: (t('a), ~map: t('a)) => t('a) = "prepend";

[@bs.send] external append: (t('a), ~map: t('a)) => t('a) = "append";

[@bs.send] external subtract: (t('a), ~map: t('a)) => t('a) = "subtract";

[@bs.get] external size: t('a) => int = "size";
