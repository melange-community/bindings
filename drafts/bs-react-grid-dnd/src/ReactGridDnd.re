type gridOnChange =
  (
    ~sourceId: string,
    ~sourceIndex: int,
    ~targetIndex: int,
    ~targetId: option(string)
  ) =>
  unit;

module GridContextProvider = {
  [@bs.module "react-grid-dnd"] [@react.component]
  external make: (~onChange: gridOnChange, ~children: 'a) => React.element =
    "GridContextProvider";
};

module GridDropZone = {
  [@bs.module "react-grid-dnd"] [@react.component]
  external make:
    (
      ~className: string=?,
      ~boxesPerRow: int,
      ~rowHeight: int,
      ~id: string,
      ~disableDrag: bool=?,
      ~disableDrop: bool=?,
      ~children: 'a
    ) =>
    React.element =
    "GridDropZone";
};

module GridItem = {
  [@bs.module "react-grid-dnd"] [@react.component]
  external make: (~className: string=?, ~children: 'a) => React.element =
    "GridItem";
};

module GridUtil = {
  [@bs.module "react-grid-dnd"]
  external swap:
    (~itemArray: array('b), ~moveIndex: int, ~toIndex: int) => array('b) =
    "swap";

  external move:
    (
      ~source: array('b),
      ~destination: array('b),
      ~droppableSource: int,
      ~droppableDestination: int
    ) =>
    array('b) =
    "move";
};