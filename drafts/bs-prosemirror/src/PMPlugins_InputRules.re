module InputRule = {
  type t;

  [@bs.module "prosemirror-inputrules"] [@bs.new]
  external make:
    (
      ~match: Js.Re.t,
      ~handler: [@bs.unwrap] [
                  | `String(string)
                  | `Fn(
                      (
                        ~state: PM_State.EditorState.t,
                        ~match: array(string),
                        ~start: int,
                        ~end_: int
                      ) =>
                      Js.Nullable.t(PM_State.Transaction.t),
                    )
                ]
    ) =>
    t =
    "InputRule";
};

[@bs.module "prosemirror-inputrules"]
external inputRulesExt: {. "rules": array(InputRule.t)} => PM_State.Plugin.t('a) = "inputRules";

let inputRules: array(InputRule.t) => PM_State.Plugin.t('a) =
  xs => inputRulesExt({"rules": xs});

[@bs.module "prosemirror-inputrules"] external undoInputRule: PM_Command.t = "undoInputRule";

[@bs.module "prosemirror-inputrules"] external emDash: InputRule.t = "emDash";

[@bs.module "prosemirror-inputrules"] external ellipsis: InputRule.t = "ellipsis";

[@bs.module "prosemirror-inputrules"] external openDoubleQuote: InputRule.t = "openDoubleQuote";

[@bs.module "prosemirror-inputrules"] external closeDoubleQuote: InputRule.t = "closeDoubleQuote";

[@bs.module "prosemirror-inputrules"] external openSingleQuote: InputRule.t = "openSingleQuote";

[@bs.module "prosemirror-inputrules"] external closeSingleQuote: InputRule.t = "closeSingleQuote";

[@bs.module "prosemirror-inputrules"] external smartQuotes: InputRule.t = "smartQuotes";

[@bs.module "prosemirror-inputrules"]
external wrappingInputRule:
  (
    ~regexp: Js.Re.t,
    ~nodeType: PM_Model.NodeType.t,
    ~getAttrs: [@bs.unwrap] [
                 | `Attrs(PM_Model.Attrs.t)
                 | `Fn(array(string) => PM_Model.Attrs.t)
               ]
                 =?,
    ~joinPredicate: (array(string), PM_Model.Node.t) => bool=?,
    unit
  ) =>
  InputRule.t =
  "wrappingInputRule";

[@bs.module "prosemirror-inputrules"]
external textblockTypeInputRule:
  (
    ~regexp: Js.Re.t,
    ~nodeType: PM_Model.NodeType.t,
    ~getAttrs: [@bs.unwrap] [
                 | `Attrs(PM_Model.Attrs.t)
                 | `Fn(array(string) => PM_Model.Attrs.t)
               ]
                 =?,
    unit
  ) =>
  InputRule.t =
  "textblockTypeInputRule";
