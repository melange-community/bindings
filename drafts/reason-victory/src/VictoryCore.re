type dataPoint = {
  .
  x: int,
  y: int,
};

module VictoryTheme = {
  type t;

  [@bs.module "victory-core/es/victory-theme/material"] [@bs.val]
  external material: t = "default";

  [@bs.module "victory-core/es/victory-theme/grayscale"] [@bs.val]
  external grayscale: t = "default";
};
