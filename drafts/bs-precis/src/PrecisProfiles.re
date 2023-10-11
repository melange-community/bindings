/** Precis/PrecisProfiles.re
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 17 May 2019
 */

let bidi = (codePointList: list(PrecisUtils.codePoint)) => {
  let directionList =
    List.map(PrecisBidi.getDirectionProperty, codePointList);
  List.mem(PrecisBidi.R, directionList)
  || List.mem(PrecisBidi.AL, directionList)
  || List.mem(PrecisBidi.AN, directionList) ?
    PrecisBidi.validate(codePointList) : true;
};

let usernameCaseMapped = (codePointList: list(PrecisUtils.codePoint)) => {
  let str =
    codePointList
    |> PrecisMapping.mapWidth
    |> PrecisMapping.toLower
    |> PrecisUnorm.nfc;
  bidi(str) ?
    switch (PrecisClasses.identifierEnforce(str)) {
    | exception (PrecisUtils.PrecisError(PrecisUtils.Disallowed)) =>
      raise(PrecisUtils.PrecisError(PrecisUtils.Disallowed))
    | exception (PrecisUtils.PrecisError(PrecisUtils.Unassigned)) =>
      raise(PrecisUtils.PrecisError(PrecisUtils.Unassigned))
    | x => x |> PrecisUtils.nonEmptyExn
    } :
    raise(PrecisUtils.PrecisError(PrecisUtils.BidiError));
};

let usernameCasePreserved = (codePointList: list(PrecisUtils.codePoint)) => {
  let str = codePointList |> PrecisMapping.mapWidth |> PrecisUnorm.nfc;
  bidi(str) ?
    switch (PrecisClasses.identifierEnforce(str)) {
    | exception (PrecisUtils.PrecisError(PrecisUtils.Disallowed)) =>
      raise(PrecisUtils.PrecisError(PrecisUtils.Disallowed))
    | exception (PrecisUtils.PrecisError(PrecisUtils.Unassigned)) =>
      raise(PrecisUtils.PrecisError(PrecisUtils.Unassigned))
    | x => x |> PrecisUtils.nonEmptyExn
    } :
    raise(PrecisUtils.PrecisError(PrecisUtils.BidiError));
};

let opaqueString = (codePointList: list(PrecisUtils.codePoint)) => {
  let str = codePointList |> PrecisMapping.spaceMap |> PrecisUnorm.nfc;
  switch (PrecisClasses.freeformEnforce(str)) {
  | exception (PrecisUtils.PrecisError(PrecisUtils.Disallowed)) =>
    raise(PrecisUtils.PrecisError(PrecisUtils.Disallowed))
  | exception (PrecisUtils.PrecisError(PrecisUtils.Unassigned)) =>
    raise(PrecisUtils.PrecisError(PrecisUtils.Unassigned))
  | x => x |> PrecisUtils.nonEmptyExn
  };
};

let nickname = (codePointList: list(PrecisUtils.codePoint)) => {
  let str =
    codePointList
    |> PrecisMapping.spaceMap
    |> PrecisMapping.stripSpaces
    |> PrecisMapping.toLower
    |> PrecisUnorm.nfkc;
  switch (PrecisClasses.freeformEnforce(str)) {
  | exception (PrecisUtils.PrecisError(PrecisUtils.Disallowed)) =>
    raise(PrecisUtils.PrecisError(PrecisUtils.Disallowed))
  | exception (PrecisUtils.PrecisError(PrecisUtils.Unassigned)) =>
    raise(PrecisUtils.PrecisError(PrecisUtils.Unassigned))
  | x => x |> PrecisUtils.nonEmptyExn
  };
};

let usernameCaseMapped = (s: string) =>
  PrecisUtils.toCodePointList(s)
  |> usernameCaseMapped
  |> PrecisUtils.fromCodePointList;
let usernameCasePreserved = (s: string) =>
  PrecisUtils.toCodePointList(s)
  |> usernameCasePreserved
  |> PrecisUtils.fromCodePointList;
let opaqueString = (s: string) =>
  PrecisUtils.toCodePointList(s)
  |> opaqueString
  |> PrecisUtils.fromCodePointList;

let nickname = (s: string) =>
  PrecisUtils.toCodePointList(s)
  |> nickname
  |> nickname
  |> PrecisUtils.fromCodePointList;
