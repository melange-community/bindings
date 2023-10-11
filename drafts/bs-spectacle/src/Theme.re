type theme;

[@bs.deriving {jsConverter: newType}]
type colorsDefinition = {
  primary: string,
  secondary: string,
  tertiary: string,
  quarternary: string,
};

[@bs.deriving {jsConverter: newType}]
type fontDefinition = {
  name: string,
  googleFont: bool,
  styles: array(string),
};

type fontsDefinition = {
  primary: fontDefinition,
  secondary: fontDefinition,
  tertiary: fontDefinition,
};

let fontsDefinitionToJs = fonts => {
  "primary": fontDefinitionToJs(fonts.primary),
  "secondary": fontDefinitionToJs(fonts.secondary),
  "tertiary": fontDefinitionToJs(fonts.tertiary),
};

[@bs.module "spectacle/lib/themes/default"]
external _createTheme:
  (
    abs_colorsDefinition,
    {
      .
      "primary": abs_fontDefinition,
      "secondary": abs_fontDefinition,
      "tertiary": abs_fontDefinition,
    }
  ) =>
  theme =
  "default";

let simpleFont = (name: string) => {name, googleFont: false, styles: [||]};

let createTheme = (colors, fonts) =>
  _createTheme(colorsDefinitionToJs(colors), fontsDefinitionToJs(fonts));