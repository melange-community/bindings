module Bullseye = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (~children: 'children=?, ~className: string=?) => React.element =
    "Bullseye";
};

module Flex = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~align: 'any1=?,
      ~alignContent: 'any2=?,
      ~alignItems: 'any3=?,
      ~alignSelf: 'any4=?,
      ~className: string=?,
      ~direction: 'any5=?,
      ~display: 'any6=?,
      ~flex: 'any7=?,
      ~flexWrap: 'any8=?,
      ~fullWidth: 'any9=?,
      ~grow: 'any10=?,
      ~justifyContent: 'any11=?,
      ~shrink: 'any12=?,
      ~spaceItems: 'any13=?,
      ~spacer: 'any14=?
    ) =>
    React.element =
    "Flex";
};

module FlexItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~align: 'any1=?,
      ~alignSelf: 'any2=?,
      ~className: string=?,
      ~flex: 'any3=?,
      ~fullWidth: 'any4=?,
      ~grow: 'any5=?,
      ~shrink: 'any6=?,
      ~spacer: 'any7=?
    ) =>
    React.element =
    "FlexItem";
};

module Gallery = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (~children: 'children=?, ~className: string=?, ~hasGutter: bool=?) =>
    React.element =
    "Gallery";
};

module GalleryItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make: (~children: 'children=?) => React.element = "GalleryItem";
};

module Grid = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~className: string=?,
      ~hasGutter: bool=?,
      ~lg: PFTypes.Column.t=?,
      ~md: PFTypes.Column.t=?,
      ~sm: PFTypes.Column.t=?,
      ~span: PFTypes.Column.t=?,
      ~xl: PFTypes.Column.t=?,
      ~xl2: PFTypes.Column.t=?
    ) =>
    React.element =
    "Grid";
};

module GridItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~className: string=?,
      ~lg: PFTypes.Column.t=?,
      ~lgOffset: PFTypes.Column.t=?,
      ~lgRowSpan: PFTypes.Column.t=?,
      ~md: PFTypes.Column.t=?,
      ~mdOffset: PFTypes.Column.t=?,
      ~mdRowSpan: PFTypes.Column.t=?,
      ~offset: PFTypes.Column.t=?,
      ~rowSpan: PFTypes.Column.t=?,
      ~sm: PFTypes.Column.t=?,
      ~smOffset: PFTypes.Column.t=?,
      ~smRowSpan: PFTypes.Column.t=?,
      ~span: PFTypes.Column.t=?,
      ~xl: PFTypes.Column.t=?,
      ~xl2: PFTypes.Column.t=?,
      ~xl2Offset: PFTypes.Column.t=?,
      ~xl2RowSpan: PFTypes.Column.t=?,
      ~xlOffset: PFTypes.Column.t=?,
      ~xlRowSpan: PFTypes.Column.t=?
    ) =>
    React.element =
    "GridItem";
};

module Level = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (~children: 'children=?, ~className: string=?, ~hasGutter: bool=?) =>
    React.element =
    "Level";
};

module LevelItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make: (~children: 'children=?) => React.element = "LevelItem";
};

module Split = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~className: string=?,
      ~component: 'children1=?,
      ~hasGutter: bool=?
    ) =>
    React.element =
    "Split";
};

module SplitItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (~children: 'children=?, ~className: string=?, ~isFilled: bool=?) =>
    React.element =
    "SplitItem";
};

module Stack = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (
      ~children: 'children=?,
      ~className: string=?,
      ~component: 'children1=?,
      ~hasGutter: bool=?
    ) =>
    React.element =
    "Stack";
};

module StackItem = {
  [@react.component] [@bs.module "@patternfly/react-core"]
  external make:
    (~children: 'children=?, ~className: string=?, ~isFilled: bool=?) =>
    React.element =
    "StackItem";
};
