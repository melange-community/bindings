module Domain = Demo_Domain;
module Hy = Yawaramin_ReHyperapp;
include Hy.Component.Static;

type props = {.
  "currBookId": option(Domain.Book.id),
  "book": Domain.Book.t,
  "onSelect": (. Domain.Book.id) => unit,
};

let make(~state as _=?, ~actions as _=?, ~props, _children) = {
  let book = props##book;
  let bookId = book##id;

  let _class = "panel-block" ++ switch (props##currBookId) {
    | Some(id) when id == bookId => " is-active"
    | _ => ""
  };

  let id = "item-" ++ bookId;
  let desc = {
    let author = book##author;
    if (author == "") "" else {j| · $author|j};
  };

  <a _class
    id
    key=id
    onclick={(. _event) =>
      Hy.Action.exec(props##onSelect, action => action(. bookId))}>
    <span _class="panel-icon">
      {book##status |> Domain.Status.toEmoji |> Hy.string}
    </span>
    {Hy.string(book##title ++ desc)}
  </a>;
};
