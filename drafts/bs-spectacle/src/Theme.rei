type theme;

type colorsDefinition = {
  primary: string,
  secondary: string,
  tertiary: string,
  quarternary: string,
};

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

let simpleFont: string => fontDefinition;

let createTheme: (colorsDefinition, fontsDefinition) => theme;