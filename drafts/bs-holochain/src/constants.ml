(** Holochain global constants *)

(** {2} Holochain system constants *)
module System = struct
  let version :
    string = [%raw {|HC.Version|}]
  let version = version

  let hashNotFound : string = [%raw {|HC.HashNotFound|}]

  type hashNotFound = [`Hash_not_found] HashString.t

  let hashNotFound : hashNotFound =
    HashString.create hashNotFound

  module Status :
  sig
    type t
    val live : t
    val deleted : t
    val modified : t
    val rejected : t
    val any : t
  end =
  struct
    type t = int
    let live : t = [%raw {|HC.Status.Live|}]
    let deleted : t = [%raw {|HC.Status.Deleted|}]
    let modified : t = [%raw {|HC.Status.Modified|}]
    let rejected : t = [%raw {|HC.Status.Rejected|}]
    let any : t = [%raw {|HC.Status.Any|}]
  end

  module GetMask :
  sig
    type t
    val default : t
    val entry : t
    val entryType : t
    val sources : t
    val all : t
  end =
  struct
    type t = int

    let default : t = [%raw {|HC.GetMask.Default|}]
    let entry : t = [%raw {|HC.GetMask.Entry|}]
    let entryType : t = [%raw {|HC.GetMask.EntryType|}]
    let sources : t = [%raw {|HC.GetMask.Sources|}]
    let all : t = [%raw {|HC.GetMask.All|}]
  end

  module LinkAction :
  sig
    type t
    val add : t
    val del : t
  end
  = struct
      type t = int
      let add : t = [%raw {|HC.LinkAction.Add|}]
      let del : t = [%raw {|HC.LinkAction.Del|}]
  end

  module PkgReq :
  sig
    type t
    val chain : t
    val chainOpt : t
    val entryTypes : t
  end = struct
    type t = int
    let chain : t = [%raw {|HC.PkgReq.Chain|}]
    let chainOpt : t = [%raw {|HC.PkgReq.ChainOpt|}]
    let entryTypes : t = [%raw {|HC.PkgReq.Entries|}]
  end

  module ChainOpt :
  sig
    type t
    val none : t
    val headers : t
    val entries : t
    val full : t
  end = struct
    type t = int
    let none :
      t = [%raw {|HC.PkgReq.ChainOpt.None|}]
    let headers :
      t = [%raw {|HC.PkgReq.ChainOpt.Headers|}]
    let entries :
      t = [%raw {|HC.PkgReq.ChainOpt.Entries|}]
     let full :
      t = [%raw {|HC.PkgReq.ChainOpt.Full|}]
  end


  module Bridge :
  sig
    type t
    val from : t
    val to_ : t
  end = struct
    type t = int
    let from : t = [%raw {|HC.Bridge.From|}]
    let to_ : t = [%raw {|HC.Bridge.To|}]
  end

  module SysEntryType :
  sig
    type t
    val dna : t
    val agent : t
    val key : t
    val headers : t
    val del : t
  end =
  struct
    type t = int
    let dna : t = [%raw {|HC.SysEntryType.DNA|}]
    let agent : t = [%raw {|HC.SysEntryType.Agent|}]
    let key : t = [%raw {|HC.SysEntryType.Key|}]
    let headers : t = [%raw {|HC.SysEntryType.Headers|}]
    let del : t = [%raw {|HC.SysEntryType.Del|}]
  end

end

(** Holochain local application constants *)
module App0 = struct

  (** Holds the Name of this Holochain from the DNA. *)
  let name : string = [%raw {|App.Name|}]
  let name = name

  (** Holochain's DNA related constants *)
  module DNA = struct
    (** Holds the unique identifier of this Holochain's DNA.
       Nodes must run the same DNA to be on the same Holochain.
     * *)
    let hash : string = [%raw {|App.DNA.Hash|}]

    type hash = [`DNA] HashString.t
    let hash : hash = (HashString.create hash :> hash)
  end

  (** Holochain's Agent related constants *)
  module Agent = struct

    let hash : string = [%raw {|App.Agent.Hash|}]

    type hash = [`Agent] HashString.t

    (** Holds your peer's identity info on the DHT. This is the hash for the
     * second entry (identity info) on your chain. **)
    let hash : hash = (HashString.create hash :> hash)

    let topHash : string = [%raw {|App.Agent.TopHash|}]

    (** Holds the most recent agent indentity entry that has been committed to
     * the chain. To start with its value is equivalent to App.Agent.Hash after
     * a call to updateAgent it will have the value of the newly committed
     * agent entry. *)
    let topHash : [`Top] HashString.t = HashString.create topHash

    let string : string = [%raw {|App.Agent.String|}]

    (** Holds the identity string used to initialize the holochain software
     * with hcadmin init If you used JSON to embed multiple properties (such as
     * FirstName, LastName, Email, etc), they can be retrieved here as
     * App.Agent.FirstName, etc. *)
     let string = string

  end

  (** Holochain's Key related constants *)
  module Key = struct
    let hash : string = [%raw {|App.Key.Hash|}]

   (* Holds the hash of your public key. This is your node address on the DHT.
    * It can be used for node-to-node messaging with send and receive
    * functions. *)
    type hash = [`Key] HashString.t
    let hash : hash = (HashString.create hash :> hash)
 end

end


