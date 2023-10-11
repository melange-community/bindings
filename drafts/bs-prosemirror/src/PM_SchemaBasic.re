[@bs.module "prosemirror-schema-basic"] external nodes: Js.Dict.t(PM_Model.NodeSpec.t) = "nodes";

[@bs.module "prosemirror-schema-basic"] external marks: Js.Dict.t(PM_Model.MarkSpec.t) = "marks";

[@bs.module "prosemirror-schema-basic"] external schema: PM_Model.Schema.t = "schema";
