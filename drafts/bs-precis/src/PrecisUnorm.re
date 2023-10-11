/** Precis/Unorm.re
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 15 May 2019
 */ /** These are the bindings to Bjarke Walling's Unorm library
 ** Licensed under the MIT & GPL license.
 */
[@bs.val] [@bs.module "unorm"]
external nfc: string /* str */ => string = "nfc";
let nfcString = nfc;
let nfc = (codePointList: list(PrecisUtils.codePoint)) =>
  codePointList
  |> PrecisUtils.fromCodePointList
  |> nfc
  |> PrecisUtils.toCodePointList;

[@bs.val] [@bs.module "unorm"]
external nfkc: string /* str */ => string = "nfkc";
let nfkcString = nfkc;
let nfkc = (codePointList: list(PrecisUtils.codePoint)) =>
  codePointList
  |> PrecisUtils.fromCodePointList
  |> nfkc
  |> PrecisUtils.toCodePointList;
