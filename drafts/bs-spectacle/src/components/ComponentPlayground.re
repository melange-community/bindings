[@bs.module "spectacle"]
external reactClass: ReasonReact.reactClass = "ComponentPlayground";

type componentPlaygroundTheme =
  | Light
  | Dark;

let componentPlaygroundThemeToJs =
  (. theme) =>
    switch (theme) {
    | Light => "light"
    | Dark => "dark"
    };

[@bs.obj]
external makeProps:
  (
    ~code: string=?,
    ~previewBackgroundColor: string=?,
    ~theme: string=?,
    ~scope: Js.t('a)=?,
    unit
  ) =>
  _ =
  "";

let make = (~code=?, ~previewBackgroundColor=?, ~theme=?, ~scope=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~code?,
        ~previewBackgroundColor?,
        ~theme=?Js.Option.map(componentPlaygroundThemeToJs, theme),
        ~scope?,
        (),
      ),
    children,
  );