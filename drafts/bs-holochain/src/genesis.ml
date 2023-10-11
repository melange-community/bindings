module type S =
sig
  val genesis : unit -> bool
end

module Success : S = struct let genesis () = true end
module Failure : S = struct let genesis () = false end
