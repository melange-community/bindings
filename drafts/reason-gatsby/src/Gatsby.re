type graphql;

// not used currently
[@bs.module "gatsby"] external graphql: 'any = "graphql";

[@bs.module "gatsby"]
external useStaticQuery: string => Js.Json.t = "useStaticQuery";

module Link = {
  [@bs.module "gatsby"] [@react.component]
  external make:
    (
      ~children: React.element,
      ~_to: string,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~replace: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~state: Js.Json.t=?,
      ~activeClassName: string=?,
      ~activeStyle: ReactDOMRe.Style.t=?,
      ~partiallyActive: bool=?,
      ~rel: string=?
    ) =>
    React.element =
    "Link";
};

type location = {
  key: string,
  pathname: string,
  search: string,
  hash: string,
  state: option(Js.Json.t),
};

type navigationOptions = {
  state: option(Js.Json.t),
  replace: bool
};

[@bs.module "@reach/router"] external navigate: string => unit = "navigate";
[@bs.module "@reach/router"] external navigateWithOpts: (string, navigationOptions) => unit = "navigate";

// ___loader is a Gatsby global, that can enqueue routes to fetch
let hover: string => unit = [%bs.raw
  {|
function(str) {
  if (___loader) {
    ___loader.hovering(str)
  }
}
|}
];

let enqueue: string => unit = [%bs.raw
  {| function (str) {
  if (___loader) {
    ___loader.enqueue(str)
  }
}|}
];
