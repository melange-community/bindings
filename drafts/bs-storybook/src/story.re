type section;

type webpackModule;

type chapter = unit => React.element;

type decorator = chapter => React.element;

type parameters = {component: React.element};

[@bs.val] [@bs.module "@storybook/react"]
external storiesOf: (string, webpackModule) => section = "storiesOf";

[@bs.send] external add: (section, string, chapter) => section = "add";

[@bs.send]
external addParameters: (section, parameters) => section = "addParameters";

[@bs.send]
external addDecorator: (section, decorator) => section = "addDecorator";