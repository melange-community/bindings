type t =
  | VoiceMail
  | Mobile(string)
  | Landline(string)
module Validate: {
  let isValid: string => bool
}
module Normalize: {
  let clean: string => string
}
module Link: {
  let make: string => string
}
let typeOfNumber: string => t
let parse: string => string
