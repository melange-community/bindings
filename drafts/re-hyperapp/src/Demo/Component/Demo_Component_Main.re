module Detail = Demo_Component_Detail;
module Domain = Demo_Domain;
module Hy = Yawaramin_ReHyperapp;

type props = unit;
type tab = [Domain.Status.t | `All];
type state = {.
  tab,
  books: Js.Dict.t(Domain.Book.t),
  currBookId: option(Domain.Book.id),
  detail: Js.t(Detail.state),
};
type setTab = (. tab) => {. "tab": tab};
type actions = {.
  setTab,
  setCurrBookId: (. option(Domain.Book.id)) =>
    {. "currBookId": option(Domain.Book.id)},
  addNew: (. unit) => {. "currBookId": option(Domain.Book.id)},
  detail: Js.t(Detail.actions),
};
type tabProps = {. "currTab": tab, "newTab": tab, "setTab": setTab};

module Tab: Hy.Component.Type with type props = tabProps = {
  include Hy.Component.Static;

  type props = tabProps;

  let isActive(currTab, newTab) = if (currTab == newTab) "is-active" else "";

  let make(~state as _=?, ~actions as _=?, ~props, _) = {
    let newTab = props##newTab;

    <a
      _class=isActive(props##currTab, newTab)
      onclick={(. _event) =>
        Hy.Action.exec(props##setTab, action => action(. newTab))}>
      {Hy.string(Domain.Status.(toEmoji(newTab) ++ " " ++ toString(newTab)))}
    </a>;
  };
};

// Dummy data
let books = Js.Dict.fromArray([|
  ("1", {
    "author": "J.R.R. Tolkien",
    "description": "The story of the fellowship of the races that overthrew the Dark Lord, and the great journey undertaken by two hobbits that made it possible.",
    "id": "1",
    "title": "The Lord of the Rings",
    "status": `Read,
  }),
  ("2", {
    "author": "Mikhail Bulgakov",
    "description": "The Devil comes to Stalin-era Moscow and wreaks havoc with his retinue of demons, while the Master struggles to finish his life's work (the story of Yeshua Ha-Nozri), and Margarita seeks a way to break free from the shackles of society and be reunited with her love.",
    "id": "2",
    "title": "The Master and Margarita",
    "status": `Read,
  }),
|]);

let state = {
  "tab": `All,
  "books": books,
  "currBookId": None,
  "detail": Detail.state,
};

let actions = {
  "setTab": (. tab) => {"tab": tab},
  "setCurrBookId": (. bookId) => {"currBookId": bookId},
  "addNew": (.) => {"currBookId": None},
  "detail": Detail.actions,
};

let showFor(currTab, book) = switch (currTab, book##status) {
  | (`All, _)
  | (`ToRead, `ToRead)
  | (`Reading, `Reading)
  | (`Read, `Read) => true
  | _ => false
};

let tabProps(~currTab, ~newTab, ~setTab, ()) = {
  "currTab": currTab,
  "newTab": newTab,
  "setTab": setTab,
};

let make(~state=state, ~actions=actions, ~props as _, _) = {
  module Book = Demo_Component_Book;

  let currTab = state##tab;
  let currBookId = state##currBookId;
  let books = state##books
    |> Js.Dict.values
    |> Js.Array.filter(showFor(currTab))
    |> Js.Array.map(book =>
      <Book props={
        "currBookId": currBookId,
        "book": book,
        "onSelect": (. bookId) =>
          Hy.Action.(exec(actions##setCurrBookId, action =>
            action(. Some(bookId)))),
      } />)
    |> Hy.array;
  let currBook = currBookId |> Js.Option.andThen((. currBookId) =>
    Js.Dict.get(state##books, currBookId));
  let setTab = actions##setTab;
  let addNewClass = "panel-block" ++ switch (currBookId) {
    | Some(_) => ""
    | None => " is-active"
  };

  <section>
    <nav _class="level">
      <div _class="level-item has-text-centered">
        <h1 style="margin-top: .75rem" _class="title">
          {Hy.string({j|🏫 My Library|j})}
        </h1>
      </div>
    </nav>
    <div _class="container is-fluid">
      <div _class="tile is-ancestor">
        <div _class="tile is-4 is-parent">
          <div _class="tile is-child">
            <nav _class="panel">
              <div _class="panel-block">
                <p _class="control has-icons-left">
                  <input _class="input is-small" _type="search" placeholder="Filter" />
                  <span _class="icon is-small is-left">{Hy.string({j|🔍|j})}</span>
                </p>
              </div>
              <p _class="panel-tabs">
                <Tab props=tabProps(~currTab, ~newTab=`All, ~setTab, ()) />
                <Tab props=tabProps(~currTab, ~newTab=`ToRead, ~setTab, ()) />
                <Tab props=tabProps(~currTab, ~newTab=`Reading, ~setTab, ()) />
                <Tab props=tabProps(~currTab, ~newTab=`Read, ~setTab, ()) />
              </p>
              <a
                _class=addNewClass
                onclick={(. _event) =>
                  Hy.Action.exec(actions##setCurrBookId, action =>
                    action(. None))}>
                <span _class="panel-icon">{Hy.string({j|🆕|j})}</span>
                {Hy.string("Add New")}
              </a>
              {books}
            </nav>
          </div>
        </div>
        <Detail state=state##detail actions=actions##detail props=currBook />
      </div>
    </div>
  </section>;
};
