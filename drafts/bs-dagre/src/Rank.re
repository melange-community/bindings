module Dir = {
  exception UnexpectedDir(string);

  /** The direction for rank nodes. */
  type t =
    | TopBottom
    | BottomTop
    | LeftRight
    | RightLeft;

  let toString = (dir: t): string =>
    switch (dir) {
    | TopBottom => "TB"
    | BottomTop => "BT"
    | LeftRight => "LR"
    | RightLeft => "RL"
    };

  let fromStringExn = (str: string): t =>
    switch (str) {
    | "TB" => TopBottom
    | "BT" => BottomTop
    | "LR" => LeftRight
    | "RL" => RightLeft
    | _ => raise(UnexpectedDir(str))
    };
};

module Align = {
  exception UnexpectedAlign(string);
  /** The alignment for the rank nodes. */
  type t =
    | UpLeft
    | UpRight
    | DownLeft
    | DownRight;

  let toString = (align: t): string =>
    switch (align) {
    | UpLeft => "UL"
    | UpRight => "UR"
    | DownLeft => "DL"
    | DownRight => "DR"
    };

  let fromStringExn = (str: string): t =>
    switch (str) {
    | "UL" => UpLeft
    | "UR" => UpRight
    | "DL" => DownLeft
    | "DR" => DownRight
    | _ => raise(UnexpectedAlign(str))
    };
};

module Strategy = {
  exception UnexpectedStrategy(string);

  type t =
    | NetworkSimplex
    | TightTree
    | LongestPath;

  let toString = (strategy: t): string =>
    switch (strategy) {
    | NetworkSimplex => "network-simplex"
    | TightTree => "tight-tree"
    | LongestPath => "longest-path"
    };

  let fromStringExn = (str: string): t =>
    switch (str) {
    | "network-simplex" => NetworkSimplex
    | "tight-tree" => TightTree
    | "longest-path" => LongestPath
    | _ => raise(UnexpectedStrategy(str))
    };
};
