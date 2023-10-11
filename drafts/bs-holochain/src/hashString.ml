module type S =
sig
  type 'entry t = string
  (** Manually lift a string to a hash string type. Only should be used as
      a last resort. Instead, use the entry module level version or
      those in the constants module/
  *)
  val create : string -> 'entry t
  val equals : 'entry t -> 'entry t -> bool
  val hashEquals : 'entry t -> 'entry' t -> bool
end

include (struct
  type 'entry t = string
  let create s : 'entry t = s
  let hashEquals = (=)
  let equals = hashEquals
end : S)
