[@bs.module "react-admin"] external admin : ReasonReact.reactClass = "Admin";

type dataProvider;
type authProvider =
  (string, Js.Json.t) => Js.Promise.t(Js.Nullable.t(string));

[@bs.obj]
external makeProps :
  (
    ~appLayout: 'a=?,
    ~authProvider: authProvider=?,
    ~catchAll: 'c=?,
    ~customSagas: 'd=?,
    ~customReducers: 'e=?,
    ~customRoutes: 'f=?,
    ~dashboard: 'g=?,
    ~dataProvider: dataProvider,
    ~history: 'h=?,
    ~i18nProvider: 'i=?,
    ~initialState: 'j=?,
    ~loading: 'k=?,
    ~locale: string=?,
    ~loginPage: 'l=?,
    ~logoutButton: 'm=?,
    ~menu: 'n=?,
    ~theme: 'o=?,
    ~title: 'p=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~appLayout=?,
      ~authProvider=?,
      ~catchAll=?,
      ~customSagas=?,
      ~customReducers=?,
      ~customRoutes=?,
      ~dashboard=?,
      ~dataProvider,
      ~history=?,
      ~i18nProvider=?,
      ~initialState=?,
      ~loading=?,
      ~locale=?,
      ~loginPage=?,
      ~logoutButton=?,
      ~menu=?,
      ~theme=?,
      ~title=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=admin,
    ~props=
      makeProps(
        ~appLayout?,
        ~authProvider?,
        ~catchAll?,
        ~customSagas?,
        ~customReducers?,
        ~customRoutes?,
        ~dashboard?,
        ~dataProvider,
        ~history?,
        ~i18nProvider?,
        ~initialState?,
        ~loading?,
        ~locale?,
        ~loginPage?,
        ~logoutButton?,
        ~menu?,
        ~theme?,
        ~title?,
        (),
      ),
    children,
  );
