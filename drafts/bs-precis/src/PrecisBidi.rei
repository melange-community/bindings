/** Precis/Bidi.rei
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 20 May 2019
 */

type direction =
  | BN
  | AN
  | ES
  | ON
  | R
  | AL
  | NSM
  | WS
  | CS
  | EN
  | L
  | ET
  | B
  | Illegal;

let validate: list(PrecisUtils.codePoint) => bool;
let getDirectionProperty: PrecisUtils.codePoint => direction;
