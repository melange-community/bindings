open Constants
(** The type of a bridge. If side is [`From] then [toApp] is non empty.
    If side is [`To], [token] is non empty. *)
type 'entry t =
  {
    toApp : 'entry HashString.t;
    side:System.Bridge.t;
    token:string
  } [@@deriving bs.abstract]

