/* Useful for stubbing out things while implementing */
/* let unimplemented = x => { */
/*   Js.log(x); */
/*   Js.Exn.raiseError("Unimplemented"); */
/* }; */
/* forward compose */
/* let (>>) = (f, g, x) => g(f(x)); */
module Raw = {
  /* Raw is a literal translation of the chess.js API */
  type chess;
  type fen = string;
  type pgn = string;
  type color = string;
  type piece = {
    .
    "_type": string,
    "color": string,
  };
  type square = string;
  type san = string;
  type from_to = {
    .
    "from": string,
    "to": string,
  };
  type full_move = {
    .
    "color": color,
    "from": square,
    "_to": square,
    "flags": string,
    "piece": string, /* Not the same as piece type */
    "san": san,
  };
  type header = Js.Dict.t(string);
  type validation = {
    .
    "valid": bool,
    "error_number": int,
    "error": string,
  };
  [@bs.new] [@bs.module]
  external createForBrowser : (~fen: fen=?, unit) => chess = "chess.js";
  [@bs.new] [@bs.module "chess.js"]
  external createForNode : (~fen: fen=?, unit) => chess = "Chess";
  [@bs.send] external ascii : chess => string = "";
  [@bs.send] external clear : chess => unit = "";
  [@bs.send] external fen : chess => fen = "";
  [@bs.send] external game_over : chess => bool = "";
  [@bs.send] external get : (chess, square) => Js.nullable(piece) = "";
  type verbose = {. "verbose": bool};
  [@bs.send] external history : chess => array(san) = "";
  [@bs.send]
  external history_verbose : (chess, verbose) => array(full_move) = "history";
  [@bs.send] external in_check : chess => bool = "";
  [@bs.send] external in_checkmate : chess => bool = "";
  [@bs.send] external in_draw : chess => bool = "";
  [@bs.send] external in_stalemate : chess => bool = "";
  [@bs.send] external in_threefold_repetition : chess => bool = "";
  [@bs.send] external addToHeader : (chess, string, string) => unit = "header";
  [@bs.send] external header : chess => header = "";
  [@bs.send] external insufficient_material : chess => bool = "";
  [@bs.send] external load : (chess, fen) => bool = "";
  type sloppy = {. "sloppy": bool};
  [@bs.send]
  external load_pgn : (chess, pgn, Js.nullable(sloppy), unit) => bool = "";
  [@bs.send]
  external move_san : (chess, san) => Js.nullable(full_move) = "move";
  [@bs.send]
  external move_from_to : (chess, from_to) => Js.nullable(full_move) = "move";
  /* The options you can pass to "moves" are too flexible to represent
     nicely so I'm just going to represent it as a few different
     functions. */
  [@bs.send] external moves : chess => array(san) = "moves";
  [@bs.send]
  external moves_verbose : (chess, verbose) => array(full_move) = "moves";
  type for_square = {. "square": square};
  type for_square_verbose = {
    .
    "square": square,
    "verbose": bool,
  };
  [@bs.send]
  external moves_for_square : (chess, for_square) => array(san) = "moves";
  [@bs.send]
  external moves_for_square_verbose :
    (chess, for_square_verbose) => array(full_move) =
    "moves";
  [@bs.send] external pgn : chess => pgn = "";
  [@bs.send] external put : (chess, piece, square) => bool = "";
  [@bs.send] external remove : (chess, square) => Js.nullable(piece) = "";
  [@bs.send] external reset : chess => unit = "";
  [@bs.send] external square_color : (chess, square) => color = "";
  [@bs.send] external turn : chess => color = "";
  [@bs.send] external undo : chess => Js.nullable(full_move) = "";
  [@bs.send] external validate_fen : (chess, fen) => validation = "";
};

module type Jsonable = {
  type t;
  let toJson: t => Js.Json.t;
  let ofJson: Js.Json.t => t;
};

module List = {
  include List;
  let init = (n, f) => Array.init(n, f) |> Array.to_list;
};

module String = {
  include String;
  let ofChar = c => String.make(1, c);
};

/* chess.js, ocamlified. */
module Api = {
  type t = Raw.chess;
  module SuccessOrFail = {
    type t = [ | `success | `fail];
    let ofBool = b : t => b ? `success : `fail;
  };
  type successOrFail = SuccessOrFail.t;
  let pgn = Raw.pgn;
  module Pgn = {
    type t = Raw.pgn;
    module Header = {
      type t = Js.Dict.t(string);
      type kv = {
        key: string,
        value: string,
      };
    };
  };
  let header = Raw.header;
  let addToHeader = (t, key_value: Pgn.Header.kv) =>
    Raw.addToHeader(t, key_value.key, key_value.value);
  module Color = {
    type t =
      | Black
      | White;
    let ofRaw: Raw.color => t =
      raw =>
        switch (raw) {
        | "b" => Black
        | "w" => White
        | raw =>
          Js.Exn.raiseError(
            "Cannot convert color from raw (raw: " ++ raw ++ ")",
          )
        };
    let toRaw = t =>
      switch (t) {
      | White => "w"
      | Black => "b"
      };
    let toString = t =>
      switch (t) {
      | Black => "black"
      | White => "white"
      };
    let ofString = str =>
      switch (str) {
      | "black" => Black
      | "white" => White
      | str => Js.Exn.raiseError("Cannot convert Color.t from str: " ++ str)
      };
    let toJson = t : Js.Json.t => Json.Encode.(t |> toString |> string);
    let ofJson = json : t => Json.Decode.(json |> string |> ofString);
  };
  module File = {
    type t = [ | `a | `b | `c | `d | `e | `f | `g | `h];
    let toChar = t =>
      switch (t) {
      | `a => 'a'
      | `b => 'b'
      | `c => 'c'
      | `d => 'd'
      | `e => 'e'
      | `f => 'f'
      | `g => 'g'
      | `h => 'h'
      };
    let ofChar = c =>
      switch (c) {
      | 'a' => `a
      | 'b' => `b
      | 'c' => `c
      | 'd' => `d
      | 'e' => `e
      | 'f' => `f
      | 'g' => `g
      | 'h' => `h
      | c =>
        Js.Exn.raiseError(
          "Cannot convert File.t from char (char: " ++ String.ofChar(c) ++ ")",
        )
      };
    let ofString = s => ofChar(s.[0]);
    let toString = t => t |> toChar |> String.ofChar;
    let all: list(t) = [`a, `b, `c, `d, `e, `f, `g, `h];
    let toJson = t : Js.Json.t => Json.Encode.(t |> toString |> string);
    let ofJson = json : t => Json.Decode.(json |> string |> ofString);
  };
  module Rank = {
    type t = int;
    let all = List.init(8, x => x + 1);
    let toJson = t : Js.Json.t => Json.Encode.(t |> int);
    let ofJson = json : t => Json.Decode.(json |> int);
  };
  module Square = {
    type t = {
      file: File.t,
      rank: Rank.t,
    };
    let toString = t => {
      let {file, rank} = t;
      File.toString(file) ++ string_of_int(rank);
    };
    let ofString = s => {
      file: s.[0] |> File.ofChar,
      rank: s.[1] |> String.ofChar |> int_of_string,
    };
    let toJson = t : Js.Json.t => Json.Encode.(t |> toString |> string);
    let ofJson = json : t => Json.Decode.(json |> string |> ofString);
  };
  module Piece = {
    module Type = {
      type t = [ | `king | `queen | `bishop | `knight | `rook | `pawn];
      let ofRaw = raw =>
        switch (String.lowercase(raw)) {
        | "k" => `king
        | "q" => `queen
        | "b" => `bishop
        | "n" => `knight
        | "r" => `rook
        | "p" => `pawn
        | raw =>
          Js.Exn.raiseError(
            "Cannot convert piece from raw (raw: " ++ raw ++ ")",
          )
        };
      let toRaw = t =>
        switch (t) {
        | `king => "k"
        | `queen => "q"
        | `bishop => "b"
        | `knight => "n"
        | `rook => "r"
        | `pawn => "p"
        };
      let toString = t =>
        switch (t) {
        | `king => "king"
        | `queen => "queen"
        | `bishop => "bishop"
        | `knight => "knight"
        | `rook => "rook"
        | `pawn => "pawn"
        };
      let ofString = str =>
        switch (str) {
        | "king" => `king
        | "queen" => `queen
        | "bishop" => `bishop
        | "knight" => `knight
        | "rook" => `rook
        | "pawn" => `pawn
        | str =>
          Js.Exn.raiseError("Cannot convert Piece.Type.t from str: " ++ str)
        };
      let toJson = t : Js.Json.t => Json.Encode.(t |> toString |> string);
      let ofJson = json : t => Json.Decode.(json |> string |> ofString);
    };
    type t = {
      type_: Type.t,
      color: Color.t,
    };
    let ofRaw: Raw.piece => t =
      raw => {
        type_: raw##_type |> Type.ofRaw,
        color: Color.ofRaw(raw##color),
      };
    let toRaw = t : Raw.piece => {
      "_type": t.type_ |> Type.toRaw,
      "color": t.color |> Color.toRaw,
    };
    let toString = t =>
      Color.toString(t.color) ++ " " ++ Type.toString(t.type_);
    let toJson = t : Js.Json.t => {
      open Json.Encode;
      let {type_, color} = t;
      [("type_", Type.toJson(type_)), ("color", Color.toJson(color))]
      |> object_;
    };
    let ofJson = json : t =>
      Json.Decode.{
        type_: json |> field("type_", Type.ofJson),
        color: json |> field("color", Color.ofJson),
      };
  };
  let create = (~fen=?, ()) =>
    switch ([%external window]) {
    | None => Raw.createForNode(~fen?, ())
    | Some(_) => Raw.createForBrowser(~fen?, ())
    };
  module Fen = {
    type t = string;
    type error = {
      error_number: int,
      error: string,
    };
    let error_of_validation = validation => {
      error_number: validation##error_number,
      error: validation##error,
    };
    let ofString = s : Js.Result.t(t, error) => {
      let t = create();
      let validation = Raw.validate_fen(t, s);
      Js.log(validation);
      let valid: bool = validation##valid;
      valid ?
        Js.Result.Ok(s) : Js.Result.Error(validation |> error_of_validation);
    };
    let ofStringExn = s =>
      switch (ofString(s)) {
      | Ok(t) =>
        Js.log("ok fen: " ++ s);
        t;
      | Error(error) =>
        Printf.sprintf(
          "{ error_number: %d, error: %s }",
          error.error_number,
          error.error,
        )
        |> Js.Exn.raiseError
      };
    let toJson = t : Js.Json.t => Json.Encode.(t |> string);
    let ofJson = json : t => Json.Decode.(json |> string |> ofStringExn);
  };
  let ascii = Raw.ascii;
  let fen = Raw.fen;
  let get: (t, Square.t) => option(Piece.t) =
    (t, square) => {
      let rawSquare = square |> Square.toString;
      let raw = Raw.get(t, rawSquare) |> Js.Nullable.toOption;
      Belt.Option.map(raw, Piece.ofRaw);
    };
  module Move = {
    module San = {
      type t = string;
      let toJson = t : Js.Json.t => Json.Encode.(t |> string);
      let ofJson = json : t => Json.Decode.(json |> string);
    };
    module FromTo = {
      type t = {
        from: string,
        to_: string,
      };
      let toRaw: t => Raw.from_to = t => {"from": t.from, "to": t.to_};
      let toJson = t : Js.Json.t => {
        open Json.Encode;
        let {from, to_} = t;
        [("from", string(from)), ("to_", string(to_))] |> object_;
      };
      let ofJson = json : t =>
        Json.Decode.{
          from: json |> field("from", string),
          to_: json |> field("to_", string),
        };
    };
    module Full = {
      /* CR mrussell: Want to expose the tToJs function without exposing another full type. */
      [@bs.deriving jsConverter]
      type t = {
        color: Color.t,
        from: Square.t,
        to_: Square.t,
        flags: string,
        piece: Piece.Type.t,
        san: San.t,
      };
      let toJson = t : Js.Json.t => {
        open Json.Encode;
        let {color, from, to_, flags, piece, san} = t;
        [
          ("color", Color.toJson(color)),
          ("from", Square.toJson(from)),
          ("to_", Square.toJson(to_)),
          ("flags", Js.Json.string(flags)),
          ("piece", Piece.Type.toJson(piece)),
          ("san", Js.Json.string(san)),
        ]
        |> object_;
      };
      let ofJson = json : t =>
        Json.Decode.{
          color: json |> field("color", Color.ofJson),
          from: json |> field("from", Square.ofJson),
          to_: json |> field("to_", Square.ofJson),
          flags: json |> field("flags", string),
          piece: json |> field("piece", Piece.Type.ofJson),
          san: json |> field("san", string),
        };
      let ofRaw: Raw.full_move => t =
        raw => {
          color: Color.ofRaw(raw##color),
          from: Square.ofString(raw##from),
          to_: Square.ofString(raw##_to),
          flags: raw##flags,
          piece: Piece.Type.ofRaw(raw##piece),
          san: raw##san,
        };
      /* let toRaw: t => Raw.full_move = */
      /*   t => { */
      /*     "color": Color.toRaw(t.color), */
      /*     "from": Square.toString(t.from), */
      /*     "_to": Square.toString(t.to_), */
      /*     "flags": t.flags, */
      /*     "piece": Piece.Type.toRaw(t.piece), */
      /*     "san": t.san, */
      /*   }; */
    };
    [@bs.deriving accessors]
    type t =
      | SAN(San.t)
      | FromTo(FromTo.t)
      | Full(Full.t);
    let toJson = t : Js.Json.t =>
      Json.Encode.(
        (
          switch (t) {
          | SAN(san) => [
              ("type", string("SAN")),
              ("value", San.toJson(san)),
            ]
          | FromTo(fromTo) => [
              ("type", string("FromTo")),
              ("value", FromTo.toJson(fromTo)),
            ]
          | Full(full) => [
              ("type", string("Full")),
              ("value", Full.toJson(full)),
            ]
          }
        )
        |> object_
      );
    let ofJson = json : t => {
      open Json.Decode;
      let decodeValue = (constructor, ofJson, json) =>
        constructor(json |> field("value", ofJson));
      let decoder =
        field("type", string)
        |> andThen(type_ =>
             switch (type_) {
             | "SAN" => decodeValue(sAN, San.ofJson)
             | "FromTo" => decodeValue(fromTo, FromTo.ofJson)
             | "Full" => decodeValue(full, Full.ofJson)
             | _ => Js.Exn.raiseError("unknown move type")
             }
           );
      json |> decoder;
    };
    module Options = {
      type t = {square: option(Square.t)};
    };
  };
  let legalMoves = (~move_options=?, t) => {
    let square = Belt.Option.flatMap(move_options, x => x.Move.Options.square);
    let raw_full_moves =
      switch (square) {
      | None => Raw.moves_verbose(t, {"verbose": true})
      | Some(square) =>
        Raw.moves_for_square_verbose(
          t,
          {"square": Square.toString(square), "verbose": true},
        )
      };
    Array.map(Move.Full.ofRaw, raw_full_moves);
  };
  let move: (t, Move.t) => option(Move.Full.t) =
    (t, req) => {
      let parseResponse = r =>
        r |> Js.Nullable.toOption |. Belt.Option.map(Move.Full.ofRaw);
      switch (req) {
      | Move.SAN(san) => Raw.move_san(t, san) |> parseResponse
      | FromTo(from_to) =>
        Move.FromTo.toRaw(from_to) |> Raw.move_from_to(t) |> parseResponse
      | Full(full) => Raw.move_san(t, full.san) |> parseResponse
      };
    };
  let loadPgn = (~sloppy=?, t, pgn) => {
    let sloppy =
      Belt.Option.map(sloppy, s => {"sloppy": s}) |> Js.Nullable.fromOption;
    Raw.load_pgn(t, pgn, sloppy, ()) |> SuccessOrFail.ofBool;
  };
  module EndState = {
    module T = {
      type t =
        | Checkmate
        | Stalemate
        | ThreefoldRepetition
        | InsufficientMaterial
        | FiftyMoveRule;
      let hash = t : int => Hashtbl.hash(t);
      let eq = (t1, t2) => t1 == t2;
    };
    include T;
    include (Belt_Id.MakeHashable(T): Belt_Id.Hashable with type t := t);
    let toString = t : string =>
      switch (t) {
      | Checkmate => "Checkmate"
      | Stalemate => "Stalemate"
      | ThreefoldRepetition => "ThreefoldRepetition"
      | InsufficientMaterial => "InsufficientMaterial"
      | FiftyMoveRule => "FiftyMoveRule"
      };
    let ofString = str : t =>
      switch (str) {
      | "Checkmate" => Checkmate
      | "Stalemate" => Stalemate
      | "ThreefoldRepetition" => ThreefoldRepetition
      | "InsufficientMaterial" => InsufficientMaterial
      | "FiftyMoveRule" => FiftyMoveRule
      | str =>
        Js.Exn.raiseError("Cannot convert EndState.t from str: " ++ str)
      };
    let toJson = t : Js.Json.t => Json.Encode.(t |> toString |> string);
    let ofJson = json : t => Json.Decode.(json |> string |> ofString);
  };
  let inCheck = Raw.in_check;
  let gameOver = Raw.game_over;
  let inDraw = Raw.in_draw;
  let endState: t => option(EndState.t) =
    t =>
      if (Raw.game_over(t)) {
        Some(
          Raw.in_checkmate(t) ?
            Checkmate :
            Raw.in_stalemate(t) ?
              Stalemate :
              Raw.in_threefold_repetition(t) ?
                ThreefoldRepetition :
                Raw.insufficient_material(t) ?
                  InsufficientMaterial :
                  inDraw(t) ?
                    FiftyMoveRule :
                    Js.Exn.raiseError(
                      "LIBRARY BUG: game is over but can't detect the end state",
                    ),
        );
      } else {
        None;
      };
  let undo = t =>
    t |> Raw.undo |> Js.Nullable.toOption |. Belt.Option.map(Move.Full.ofRaw);
  let turn = t => t |> Raw.turn |> Color.ofRaw;
  let remove = (t, square) =>
    Raw.remove(t, Square.toString(square))
    |> Js.Nullable.toOption
    |. Belt.Option.map(Piece.ofRaw);
  let put = (t, piece, square) =>
    Raw.put(t, Piece.toRaw(piece), Square.toString(square))
    |> SuccessOrFail.ofBool;
  let loadFen = (t, fen) : unit =>
    Raw.load(t, fen) ?
      () : Js.Exn.raiseError("BUG: load didn't work on a valid fen");
  let historySan = t => Raw.history(t);
  let historyFull = t =>
    Raw.history_verbose(t, {"verbose": true})
    |> Array.map(raw_full_move => Move.Full.ofRaw(raw_full_move));
  let reset = Raw.reset;
  /* Explicitly ignore a few raw things that don't seem that useful  */
  let _ = Raw.square_color; /* When would you need that? */
  let _ = Raw.moves_for_square; /* Just always use verbose */
  let _ = Raw.moves; /* Just always use verbose */
  let _ = Raw.clear; /* Just create a new one? */
};

include Api;
