open Belt;
module PM = BsProsemirror;
module PMPlugins = BsProsemirrorPlugins;
module SchemaBasic = PM.SchemaBasic;
module EditorState = PM.State.EditorState;
module Model = PM.Model;

let schema = SchemaBasic.schema;

let config =
  PM.State.EditorState.Config.make(
    ~schema=SchemaBasic.schema,
    ~plugins=[|
      PMPlugins.History.history(),
      PMPlugins.DropCursor.dropCursor([("color", "red")]->Js.Dict.fromList),
      PMPlugins.Keymap.keymap(
        [
          ("Mod-z", PMPlugins.History.undo),
          ("Mod-y", PMPlugins.History.redo),
          (
            "Mod-b",
            PM.Commands.toggleMark(
              ~markType=schema->Model.Schema.marks->Js.Dict.get("strong")->Option.getExn,
              ~attrs=Model.Attrs.empty(),
            ),
          ),
          (
            "Mod-i",
            PM.Commands.toggleMark(
              ~markType=schema->Model.Schema.marks->Js.Dict.get("em")->Option.getExn,
              ~attrs=Model.Attrs.empty(),
            ),
          ),
        ]
        |> Js.Dict.fromList,
      ),
      PMPlugins.Keymap.keymap(PM.Commands.baseKeymap),
    |],
    (),
  );

let state = EditorState.create(config);

let viewConfig =
  PM.View.DirectEditorProps.make(
    ~state,
    ~dispatchTransaction=
      (view, tr) => {
        Js.log2("tr", tr);
        let oldState = view->PM.View.state;
        let newState = oldState->PM.State.EditorState.apply(tr);
        PM.View.updateState(view, newState);
      },
    (),
  );

let editorNode = {
  Webapi.(Dom.Document.getElementById("editor", Dom.document)->Belt.Option.getExn);
};

let view = PM.View.make(`Node(editorNode), viewConfig);

view->PM.View.focus;
