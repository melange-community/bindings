open Chess;

module List = {
  include List;
  let bind = (f, l) => l |> List.map(f) |> List.concat;
  let filter_map = Belt.List.keepMap;
};

let chess = create();

Js.log(ascii(chess));

Js.log(fen(chess));

let chess = {
  let fen =
    Fen.ofStringExn(
      "6nr/3p2pp/5Q2/3b2B1/1nk1PPBP/p4Np1/p5R1/1R1K1N2 b - - 2 40",
    );
  create(~fen, ());
};

let full_move = {
  Move.Full.color: Color.Black,
  from: {
    Square.file: `a,
    rank: 2,
  },
  to_: {
    Square.file: `a,
    rank: 1,
  },
  flags: "np",
  piece: `pawn,
  san: "a1=B",
};

/* Move.Full.ofRaw( */
/*   [%raw {|{ color: 'b', from: 'f2', to: 'f1', flags: 'np', piece: 'p' }|}], */
/* ); */
Js.log(ascii(chess));

Js.log(Move.Full.toJson(full_move));

Js.log(
  move(chess, Move.Full(full_move)) |. Belt.Option.map(Move.Full.toJson),
);

Js.log(ascii(chess));

Js.log(ascii(chess));

Js.log("hey");

Js.log(ascii(chess));

Js.log(gameOver(chess));

Js.log(get(chess, {Square.file: `e, rank: 8}));

Js.log(get(chess, {Square.file: `e, rank: 1}));

Js.log(
  get(chess, {Square.file: `g, rank: 2}) |. Belt.Option.map(Piece.toString),
);

let allSquares: list(Square.t) =
  File.all
  |> List.bind(file => Rank.all |> List.map(rank => {Square.file, rank}));

Js.log("gettin all squares");

let allPieces: list((Square.t, Piece.t)) =
  allSquares
  |. List.filter_map(square =>
       Belt.Option.map(get(chess, square), piece => (square, piece))
     );

Js.log(ascii(chess));

allPieces
|> List.iter(((square, piece)) =>
     Js.log3(Square.toString(square), ":", Piece.toString(piece))
   );

let play_random_game = (~print=false, t: t) => {
  Js.log("about to play random game");
  Random.self_init();
  /* random game */
  let rec loop = t => {
    print ? Js.log(fen(t)) : ();
    print ? Js.log(ascii(t)) : ();
    if (gameOver(t)) {
      Js.log("Game over");
    } else {
      let moves = legalMoves(t);
      /* Js.log("legal moves:"); */
      /* Array.iter(Js.log, Array.map(Move.Full.toJson, moves)); */
      let selected_move = moves[Random.int(Array.length(moves))];
      print ? Js.log("selecting move:") : ();
      print ? Js.log(Move.Full.toJson(selected_move)) : ();
      switch (move(t, Move.Full(selected_move))) {
      | Some(_) => loop(t)
      | None => Js.log("error")
      };
    };
  };
  loop(t);
};

play_random_game(create(), ~print=true);

let endStates = Belt.HashMap.make(~hintSize=5, ~id=(module EndState));

let total = endStates =>
  Belt.HashMap.reduce(endStates, 0, (count, _, v) => count + v);

let rec check_for_game_over_but_no_end_state = n =>
  if (n <= 0) {
    ();
  } else {
    Js.log2(n, " rounds left");
    let chess = create();
    play_random_game(chess, ~print=false);
    switch (endState(chess)) {
    | None =>
      Js.log(ascii(chess));
      Js.Exn.raiseError("game over but not sure why");
    | Some(x) =>
      Js.log(EndState.toString(x));
      let count =
        Belt.Option.getWithDefault(Belt.HashMap.get(endStates, x), 0);
      Belt.HashMap.set(endStates, x, count + 1);
      let total = total(endStates);
      Belt.HashMap.forEach(endStates, (endState, count) =>
        Js.log3(
          "--",
          EndState.toString(endState),
          float(count) /. float(total),
        )
      );
      check_for_game_over_but_no_end_state(n - 1);
    };
  };

check_for_game_over_but_no_end_state(2);
