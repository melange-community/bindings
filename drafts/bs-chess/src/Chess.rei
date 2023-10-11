type t;

type successOrFail = [ | `success | `fail];

module type Jsonable = {
  type t;
  let toJson: t => Js.Json.t;
  let ofJson: Js.Json.t => t;
};

module Fen: {
  type t;
  include Jsonable with type t := t;
  type error = {
    error_number: int,
    error: string,
  };
  let ofString: string => Js.Result.t(t, error);
  let ofStringExn: string => t;
};

module Pgn: {
  type t = string;
  module Header: {
    type t = Js.Dict.t(string);
    type kv = {
      key: string,
      value: string,
    };
  };
};

let create: (~fen: Fen.t=?, unit) => t;

let loadFen: (t, Fen.t) => unit;

let fen: t => Fen.t;

let loadPgn: (~sloppy: bool=?, t, Pgn.t) => successOrFail;

let pgn: t => Pgn.t;

let header: t => Pgn.Header.t;

let addToHeader: (t, Pgn.Header.kv) => unit;

let ascii: t => string;

module Color: {
  type t =
    | Black
    | White;
  include Jsonable with type t := t;
  let toString: t => string;
};

module File: {
  type t = [ | `a | `b | `c | `d | `e | `f | `g | `h];
  include Jsonable with type t := t;
  let toChar: t => char;
  let ofChar: char => t;
  let ofString: string => t;
  let toString: t => string;
  let all: list(t);
};

module Rank: {
  type t = int;
  include Jsonable with type t := t;
  let all: list(t);
};

module Square: {
  type t = {
    file: File.t,
    rank: Rank.t,
  };
  include Jsonable with type t := t;
  let toString: t => string;
  let ofString: string => t;
};

module Piece: {
  module Type: {
    type t = [ | `king | `queen | `bishop | `knight | `rook | `pawn];
    include Jsonable with type t := t;
    let toString: t => string;
  };
  type t = {
    type_: Type.t,
    color: Color.t,
  };
  include Jsonable with type t := t;
  let toString: t => string;
};

module EndState: {
  type t =
    | Checkmate
    | Stalemate
    | ThreefoldRepetition
    | InsufficientMaterial
    | FiftyMoveRule;
  include Jsonable with type t := t;
  include Belt_Id.Hashable with type t := t;
  let toString: t => string;
};

let endState: t => option(EndState.t);

let inCheck: t => bool;

let gameOver: t => bool;

let inDraw: t => bool;

let get: (t, Square.t) => option(Piece.t);

module Move: {
  module San: {type t = string; include Jsonable with type t := t;};
  module FromTo: {
    type t = {
      from: string,
      to_: string,
    };
    include Jsonable with type t := t;
  };
  module Full: {
    type t = {
      color: Color.t,
      from: Square.t,
      to_: Square.t,
      flags: string,
      piece: Piece.Type.t,
      san: San.t,
    };
    include Jsonable with type t := t;
  };
  [@bs.deriving accessors]
  type t =
    | SAN(San.t)
    | FromTo(FromTo.t)
    | Full(Full.t);
  include Jsonable with type t := t;
  module Options: {type t = {square: option(Square.t)};};
};

let legalMoves: (~move_options: Move.Options.t=?, t) => array(Move.Full.t);

let move: (t, Move.t) => option(Move.Full.t);

let undo: t => option(Move.Full.t);

let remove: (t, Square.t) => option(Piece.t);

let put: (t, Piece.t, Square.t) => successOrFail;

let turn: t => Color.t;

let historySan: t => array(Move.San.t);

let historyFull: t => array(Move.Full.t);

let reset: t => unit;
