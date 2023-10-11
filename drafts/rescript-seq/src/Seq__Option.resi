let map2: (option<'a>, option<'b>, ('a, 'b) => 'r) => option<'r>
let map3: (option<'a>, option<'b>, option<'c>, ('a, 'b, 'c) => 'r) => option<'r>
let map4: (option<'a>, option<'b>, option<'c>, option<'d>, ('a, 'b, 'c, 'd) => 'r) => option<'r>
let map5: (
  option<'a>,
  option<'b>,
  option<'c>,
  option<'d>,
  option<'e>,
  ('a, 'b, 'c, 'd, 'e) => 'r,
) => option<'r>
