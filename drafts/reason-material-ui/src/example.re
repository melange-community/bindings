module ExamplePage = {
  let se = ReasonReact.stringToElement;
  type exampleAppState = {isDialogOpen: bool};
  let component = ReasonReact.statefulComponent "Greeting";
  let make _children => {
    let toggleDialog _event {ReasonReact.state: state} =>
      ReasonReact.Update {isDialogOpen: not state.isDialogOpen};
    {
      ...component,
      initialState: fun () => {isDialogOpen: false},
      render: fun {state, update} => {
        let toggleDialog = update toggleDialog;
        let okButton = <MaterialUi.FlatButton label="OK" onClick=toggleDialog />;
        let cancelButton = <MaterialUi.FlatButton label="Cancel" onClick=toggleDialog />;
        let actions = [|cancelButton, okButton|];
        <div>
          <MaterialUi.MuiThemeProvider>
            <div>
              <MaterialUi.RaisedButton label="Open Dialog" onClick=toggleDialog />
              <MaterialUi.Dialog
                onRequestClose=toggleDialog isOpen=state.isDialogOpen title="Dialog Title" actions>
                (se "Dialog Content")
              </MaterialUi.Dialog>
            </div>
          </MaterialUi.MuiThemeProvider>
        </div>
      }
    }
  };
};

MaterialUi.injectTapEventPlugin ();

ReactDOMRe.renderToElementWithId <ExamplePage /> "index";