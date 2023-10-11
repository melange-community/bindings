type arrayOfItems = array(string);

module BasicAutocomplete = {
  let component = ReasonReact.statelessComponent("BasicAutocomplete");
  let make = (~items: arrayOfItems, ~onChange, _children) => {
    ...component,
    render: _self =>
      <Downshift
        onChange
        render=(
          t =>
            <div>
              (
                /*
                 NOTE: spreading props is discouraged in ReasonReact!
                 https://reasonml.github.io/reason-react/docs/en/props-spread.html
                 */
                ReasonReact.cloneElement(
                  <input />,
                  /* The method `getInputProps` returns a type `any`, we simply
                     cast it to a `{..}` type. */
                  ~props=
                    Downshift.toJsObj(
                      Downshift.ControllerStateAndHelpers.getInputProps(
                        t,
                        ~options=
                          ReactDOMRe.props(
                            ~placeholder="Favorite color ?",
                            (),
                          ),
                        (),
                      ),
                    ),
                  [||],
                )
              )
              (
                if (Downshift.ControllerStateAndHelpers.isOpen(t)) {
                  <div
                    style=(
                      ReactDOMRe.Style.make(~border="1px solid #ccc", ())
                    )>
                    (
                      ReasonReact.array(
                        {
                          let index = ref(0);
                          /* NOTE: I'm using `Array.fold_left` because
                             `Array.filter` is not supported yet.
                             However we need to track the `index` ourselves. */
                          Array.fold_left(
                            (filteredArray, item) => {
                              index := index^ + 1;
                              let inputValue =
                                Js.Nullable.toOption(
                                  Downshift.ControllerStateAndHelpers.inputValue(
                                    t,
                                  ),
                                );
                              let shouldFilterItem =
                                switch (inputValue) {
                                | None => true
                                | Some(v) =>
                                  Js.String.includes(
                                    String.lowercase(v),
                                    String.lowercase(item),
                                  )
                                };
                              shouldFilterItem ?
                                filteredArray :
                                {
                                  let backgroundColor =
                                    if (Downshift.ControllerStateAndHelpers.highlightedIndex(
                                          t,
                                        )
                                        == Js.Nullable.return(index^)) {
                                      "gray";
                                    } else {
                                      "white";
                                    };
                                  let fontWeight =
                                    if (Downshift.ControllerStateAndHelpers.selectedItem(
                                          t,
                                        )
                                        == Downshift.toAny(item)) {
                                      "bold";
                                    } else {
                                      "normal";
                                    };
                                  let elem =
                                    ReasonReact.cloneElement(
                                      <div
                                        key=item
                                        style=(
                                          ReactDOMRe.Style.make(
                                            ~backgroundColor,
                                            ~fontWeight,
                                            (),
                                          )
                                        )
                                      />,
                                      ~props=
                                        Downshift.toJsObj(
                                          Downshift.ControllerStateAndHelpers.getItemProps(
                                            t,
                                            ~item=Downshift.toAny(item),
                                            (),
                                          ),
                                        ),
                                      [|ReasonReact.string(item)|],
                                    );
                                  Array.append(filteredArray, [|elem|]);
                                };
                            },
                            [||],
                            items,
                          );
                        },
                      )
                    )
                  </div>;
                } else {
                  ReasonReact.null;
                }
              )
            </div>
        )
      />,
  };
};

module App = {
  let component = ReasonReact.statelessComponent("App");
  let make = _children => {
    ...component,
    render: _self =>
      <BasicAutocomplete
        items=[|"apple", "orange", "carrot"|]
        onChange=((selectedItem, _stateAndHelpers) => Js.log(selectedItem))
      />,
  };
};