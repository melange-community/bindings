type chapter = unit => React.element;

type section;

[@bs.val] [@bs.module "@storybook/react"]
external storiesOf: (string, 'a) => section = "storiesOf";

[@bs.send] external extAdd: (section, string, chapter) => unit = "add";

type decorator = chapter => React.element;

[@bs.send]
external addDecorator: (section, decorator) => unit = "addDecorator";

type webpackModule;

type chapterAdd = (string, chapter) => unit;

type story = {add: chapterAdd};

let createStory =
    (
      ~title: string,
      ~decorators: list(decorator),
      ~_module: webpackModule,
      (),
    )
    : story => {
  let story = storiesOf(title, _module);
  List.iter(dec => addDecorator(story, dec), decorators);
  {add: (name: string, c: chapter) => extAdd(story, name, c)};
};