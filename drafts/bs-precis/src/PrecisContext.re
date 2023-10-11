/** Precis/Context.re
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 14 August 2019
 */

let zeroWidthNonJoiner = 0x200c;
/*
Code point:
      U+200C

   Overview:
      This may occur in a formally cursive script (such as Arabic) in a
      context where it breaks a cursive connection as required for
      orthographic rules, as in the Persian language, for example.  It
      also may occur in Indic scripts in a consonant-conjunct context
      (immediately following a virama), to control required display of
      such conjuncts.

   Lookup:
      True

   Rule Set:

      False;

      If Canonical_Combining_Class(Before(cp)) .eq.  Virama Then True;

      If RegExpMatch((Joining_Type:{L,D})(Joining_Type:T)*\u200C

         (Joining_Type:T)*(Joining_Type:{R,D})) Then True;

*/
let zeroWidthJoiner = 0x200d;
/*
Appendix A.2.  ZERO WIDTH JOINER

   Code point:
      U+200D

   Overview:
      This may occur in Indic scripts in a consonant-conjunct context
      (immediately following a virama), to control required display of
      such conjuncts.

   Lookup:
      True

   Rule Set:

      False;

      If Canonical_Combining_Class(Before(cp)) .eq.  Virama Then True;
*/
let middleDot = 0x00b7;
/* 
   Code point:
      U+00B7

   Overview:
      Between 'l' (U+006C) characters only, used to permit the Catalan
      character ela geminada to be expressed.

   Lookup:
      False

   Rule Set:

      False;

      If Before(cp) .eq.  U+006C And

         After(cp) .eq.  U+006C Then True;
*/
let greekLowerNumericalSign = 0x0375;
let hebrewPunctuationGeresh = 0x05f3;
let hebrewPunctuationGereshayim = 0x05f4;
let katakanaMiddleDot = 0x30fb;
let arabicIndicDigitsStart = 0x0660; 
let arabicIndicDigitsEnd = 0x0669;

let viramas = [
  0x094d,
  0x09cd,
  0x0a4d,
  0x0acd,
  0x0b4d,
  0x0bcd,
  0x0c4d,
  0x0ccd,
  0x0d3b,
  0x0d3c,
  0x0d4d,
  0x0f84,
  0x1039,
  0x1714,
  0x1bab,
  0xa8c4,
  0xa8f3,
  0xa8f4,
  0xa953,
  0xaaf6,
  0x10a3f,
  0x11046,
  0x110b9,
  0x11133,
  0x111c0,
  0x11235,
  0x112ea,
  0x1134d,
  0x11442,
  0x114c2,
  0x115bf,
];

let virama = cp => List.mem(cp, viramas);
let zwnjRegexp = false;
let greek = cp => (cp >= 0x342 && cp <= 0x3ff) || (cp >= 0x1d26 && cp <= 0x1ffe);
let hebrew = cp => (cp >= 0x0591 && cp <= 0x5f4);
let hiragana = cp => (cp >= 0x3041 && cp <= 0x30a0);
let hiragana = cps => List.fold_left((a, cp) => a && hiragana(cp), true, cps);
let katakana = cp => (cp >= 0x3099 && cp <= 0x31ff);
let katakana = cps => List.fold_left((a, cp) => a && katakana(cp), true, cps);
let han = _ => false;
// Check for arabic Indic Digits
let arabicIndicDigits = List.fold_left((v, cp) =>
  v && !(cp >= 0x06f0 && cp <= 0x06f9), true);

let rec optimizedContext = (codePointList, precisCodePoints, acc, precisAcc) => {
  open PrecisCodePoints;
  switch precisCodePoints {
    | [] => true
    // PreJoiners
    | [cc, CONTEXTO as contextCode | CONTEXTJ as contextCode, cc2, ...precisTail] =>
      switch codePointList {
        //Pre
        | [cp1, cp2, cp3, ...cpTail] when cp2 == middleDot => (cp1 == middleDot) && (cp1 == cp3) && optimizedContext(cpTail, precisTail, [cp3, cp2, cp1] @ acc, [cc2, contextCode, cc] @ precisAcc)
        | [cp1, cp2, ...cpTail] when cp2 == zeroWidthNonJoiner => (virama(cp1) || zwnjRegexp) && optimizedContext(cpTail, [cc2] @  precisTail, [cp2, cp1] @ acc, [contextCode, cc] @ precisAcc)
        // Zero Width Joiner
        | [cp1, cp2, ...cpTail] when cp2 == zeroWidthJoiner => virama(cp1) && optimizedContext(cpTail, [cc2] @ precisTail, [cp2, cp1] @ acc, [contextCode, cc] @ precisAcc)
        | [cp1, cp2, ...cpTail] when cp2 == hebrewPunctuationGeresh || cp2 == hebrewPunctuationGereshayim => hebrew(cp1) && optimizedContext(cpTail, [cc2] @ precisTail, [cp2, cp1] @ acc, [contextCode, cc] @ precisAcc)
        // Post
        | [cp1, cp2, cp3, ...cpTail] when cp2 == greekLowerNumericalSign => greek(cp3) && optimizedContext(cpTail, precisTail, [cp3, cp2, cp1] @ acc, [cc2, contextCode, cc] @ precisAcc)
        // Total
        | [cp1, cp2, ...cpTail] when cp2 == katakanaMiddleDot => (hiragana(acc @ codePointList) || katakana(acc @ codePointList) || han(acc @ codePointList)) && optimizedContext(cpTail, [cc2] @ precisTail, [cp2, cp1] @ acc, [contextCode, cc] @ precisAcc)
        | [cp1, cp2, ...cpTail] when cp2 >= arabicIndicDigitsStart && cp2 <= arabicIndicDigitsEnd => arabicIndicDigits(acc @ codePointList) && optimizedContext(cpTail, [cc2] @ precisTail, [cp2, cp1] @ acc, [contextCode, cc] @ precisAcc)
        | _ => false
      }
    | [cp, ...precisTail] => optimizedContext(List.tl(codePointList), precisTail, [List.hd(codePointList)] @ acc, [cp] @ precisAcc)
  }
};

let context = (codePointList) => optimizedContext(codePointList, codePointList |> List.map(PrecisCodePoints.fromCodePoint), [], []);
