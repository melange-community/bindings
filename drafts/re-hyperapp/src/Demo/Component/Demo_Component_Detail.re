module Hy = Yawaramin_ReHyperapp;
module Domain = Demo_Domain;
include Hy.Component.Static;

type optionProps = {.
  "status": Domain.Status.t,
  "currStatus": Domain.Status.t,
};

module Option: Hy.Component.Type with type props = optionProps = {
  include Hy.Component.Static;

  type props = optionProps;

  let make(~state as _=?, ~actions as _=?, ~props, _children) = {
    open Domain.Status;

    let status = props##status;
    let value = toString(status);

    <option value selected={status == props##currStatus}>
      {Hy.string(toEmoji(status) ++ " " ++ value)}
    </option>;
  };
};

type props = option(Domain.Book.t);

let (or) = Belt.Option.getWithDefault;

let make(~state as _=?, ~actions as _=?, ~props, _children) = {
  let id = Js.Option.map((. book) => book##id, props) or "(New)";
  let title = Js.Option.map((. book) => book##title, props) or "";
  let author = Js.Option.map((. book) => book##author, props) or "";
  let description = Js.Option.map((. book) => book##description, props) or "";
  let status = Js.Option.map((. book) => book##status, props) or `ToRead;
  let onsubmit(. event) = {
    event##preventDefault();
    Js.log(event##target);
  };

  <div _class="tile is-parent">
    <div _class="tile is-child box">
      <form onsubmit>
        <div _class="field">
          <label _class="label" _for="detail-id">
            {Hy.string("ID")}
          </label>
          <div _class="control">
            <input
              _class="input"
              readonly=true
              id="detail-id"
              name="id"
              value=id />
          </div>
        </div>

        <div _class="field">
          <label _class="label" _for="detail-title">
            {Hy.string({j|❡ Title|j})}
          </label>
          <div _class="control">
            <input
              _class="input"
              id="detail-title"
              name="title"
              value=title required=true />
          </div>
        </div>

        <div _class="field">
          <label _class="label" _for="detail-author">
            {Hy.string({j|🗣 Author(s)|j})}
          </label>
          <div _class="control">
            <input
              _class="input"
              id="detail-author"
              name="author"
              value=author
              placeholder="Joe Q. Author"
              required=true />
          </div>
        </div>

        <div _class="field">
          <label _class="label" _for="detail-description">
            {Hy.string({j|📝 Description|j})}
          </label>
          <div _class="control">
            <textarea
              _class="textarea"
              id="detail-description"
              name="description"
              placeholder="A nice description of the document"
              value=description />
          </div>
        </div>

        <div _class="field">
          <label _class="label" _for="detail-status">
            {Hy.string({j|📚 Status|j})}
          </label>
          <div _class="select">
            <select id="detail-status" name="status">
              <Option props={"status": `ToRead, "currStatus": status} />
              <Option props={"status": `Reading, "currStatus": status} />
              <Option props={"status": `Read, "currStatus": status} />
            </select>
          </div>
        </div>

        <div _class="field is-grouped">
          <div _class="control">
            <button _type="submit" _class="button is-link">
              {Hy.string("Save")}
            </button>
          </div>
          <div _class="control">
            <p>
              {Hy.string("Clicking any of the options in the left panel will reset this entry form.")}
            </p>
          </div>
        </div>
      </form>
    </div>
  </div>;
};
