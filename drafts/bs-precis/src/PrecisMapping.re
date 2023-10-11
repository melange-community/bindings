/** Precis/PrecisUtils.re
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 16 May 2019
 */

let spaces = [
  0x20,
  0x00A0,
  0x1680,
  0x2000,
  0x2001,
  0x2002,
  0x2003,
  0x2004,
  0x2005,
  0x2006,
  0x2007,
  0x2008,
  0x2009,
  0x200A,
  0x202F,
  0x205F,
  0x3000,
];

let space = 0x20;

let stripSpaces = (codePoints: list(PrecisUtils.codePoint)) => {
  let rec stripFrontSpaces = (codePoints) => {
    switch (codePoints) {
      | [head, ...tail] when (List.mem(head, spaces)) => stripFrontSpaces(tail)
      | _ => codePoints
      };
  };
  let rec stripDoubles = (newList, oldList) => {
    switch oldList {
      | [head, ...tail] when (List.mem(head, spaces)) => stripDoubles([space] @ newList, stripFrontSpaces(tail))
      | [head, ...tail] => stripDoubles( [head] @ newList, tail)
      | [] => newList
      };
  };
  codePoints |> stripFrontSpaces |> List.rev |> stripFrontSpaces |> stripDoubles([]);
};

let maybeMapWidth = (x: PrecisUtils.codePoint) =>
  switch (x) {
  | cp when cp <= 0xFF00 => cp // optimization
  | cp when cp >= 0xFF01 && cp <= 0xFF5E => cp - 0xFEE0
  | cp when cp == 0xFF65 => 0x30FB
  | cp when cp == 0xFF66 => 0x30F2
  | cp when cp == 0xFF67 => 0x30A1
  | cp when cp == 0xFF68 => 0x30A3
  | cp when cp == 0xFF69 => 0x30A5
  | cp when cp == 0xFF6A => 0x30A7
  | cp when cp == 0xFF6B => 0x30A9
  | cp when cp == 0xFF6D => 0x30E5
  | cp when cp == 0xFF6E => 0x30E7
  | cp when cp == 0xFF6F => 0x30C3
  | cp when cp == 0xFF70 => 0x30FC
  | cp when cp == 0xFF71 => 0x30A2
  | cp when cp == 0xFF72 => 0x30A4
  | cp when cp == 0xFF73 => 0x30A6
  | cp when cp == 0xFF74 => 0x30A8
  | cp when cp == 0xFF75 => 0x30AA
  | cp when cp == 0xFF76 => 0x30AB
  | cp when cp == 0xFF77 => 0x30AD
  | cp when cp == 0xFF78 => 0x30AF
  | cp when cp == 0xFF79 => 0x30B1
  | cp when cp == 0xFF7A => 0x30B3
  | cp when cp == 0xFF7B => 0x30B5
  | cp when cp == 0xFF7C => 0x30B7
  | cp when cp == 0xFF7D => 0x30B9
  | cp when cp == 0xFF7E => 0x30BB
  | cp when cp == 0xFF7F => 0x30BD
  | cp when cp == 0xFF80 => 0x30BF
  | cp when cp == 0xFF81 => 0x30C1
  | cp when cp == 0xFF82 => 0x30C4
  | cp when cp == 0xFF83 => 0x30C6
  | cp when cp == 0xFF84 => 0x30C8
  | cp when cp == 0xFF85 => 0x30CA
  | cp when cp == 0xFF86 => 0x30CB
  | cp when cp == 0xFF87 => 0x30CC
  | cp when cp == 0xFF89 => 0x30CE
  | cp when cp == 0xFF8A => 0x30CF
  | cp when cp == 0xFF8B => 0x30D2
  | cp when cp == 0xFF8C => 0x30D5
  | cp when cp == 0xFF8D => 0x30D8
  | cp when cp == 0xFF8E => 0x30DB
  | cp when cp == 0xFF8F => 0x30DE
  | cp when cp == 0xFF90 => 0x30DF
  | cp when cp == 0xFF91 => 0x30E0
  | cp when cp == 0xFF92 => 0x30E1
  | cp when cp == 0xFF93 => 0x30E2
  | cp when cp == 0xFF94 => 0x30E4
  | cp when cp == 0xFF95 => 0x30E6
  | cp when cp == 0xFF96 => 0x30E8
  | cp when cp == 0xFF97 => 0x30E9
  | cp when cp == 0xFF98 => 0x30EA
  | cp when cp == 0xFF99 => 0x30EB
  | cp when cp == 0xFF9A => 0x30EC
  | cp when cp == 0xFF9B => 0x30ED
  | cp when cp == 0xFF9C => 0x30EF
  | cp when cp == 0xFF9D => 0x30F3
  | cp when cp == 0xFF9E => 0x3099
  | cp when cp == 0xFF9F => 0x309A
  // Halfwidth Hangul variants - filler
  | cp when cp == 0xFFA0 => 0x3164
  // Halfwidth Hangul variants - KIYEOK => HIEUH
  | cp when cp >= 0xFFA1 && cp <= 0xFFBE => cp - 0xCE70
  // Halfwidth Hangul variants - A => E
  | cp when cp >= 0xFFC2 && cp <= 0xFFC7 => cp - 0xCE73
  // Halfwidth Hangul variants - YEO => OE
  | cp when cp >= 0xFFCA && cp <= 0xFFCF => cp - 0xCE75
  // Halfwidth Hangul variants - YO => YU
  | cp when cp >= 0xFFD2 && cp <= 0xFFD7 => cp - 0xCE77
  // Halfwidth Hangul variants - EU && YI && I
  | cp when cp >= 0xFFDA && cp <= 0xFFDC => cp - 0xCE79
  // Fullwidth Symbols
  | cp when cp == 0xFFE0 => 0x00A2
  | cp when cp == 0xFFE1 => 0x00A3
  | cp when cp == 0xFFE2 => 0x00AC
  | cp when cp == 0xFFE3 => 0x00AF
  | cp when cp == 0xFFE4 => 0x00A6
  | cp when cp == 0xFFE5 => 0x00A5
  | cp when cp == 0xFFE6 => 0x20A9
  // Halfwidth Symbols
  | cp when cp == 0xFFE8 => 0x2502
  | cp when cp == 0xFFE9 => 0x2190
  | cp when cp == 0xFFEA => 0x2191
  | cp when cp == 0xFFEB => 0x2192
  | cp when cp == 0xFFEC => 0x2193
  | cp when cp == 0xFFED => 0x25A0
  | cp when cp == 0xFFEE => 0x25CB
  | cp => cp
  };

let mapWidth = (codePointList: list(PrecisUtils.codePoint)) =>
  List.map(maybeMapWidth, codePointList);

let maybeMapSpace = (x: PrecisUtils.codePoint) =>
  List.mem(x, spaces) ? space : x;

let spaceMap = (codePointList: list(PrecisUtils.codePoint)) =>
  codePointList |> List.map(maybeMapSpace);

let additionalMapping = (codePointList: list(PrecisUtils.codePoint)) => {
  let rec aux = (codePointList, acc) => {
    switch (codePointList) {
    | [h1, h2, ...tail] when h1 == space && h1 == h2 => aux(tail, acc)
    | [h1, ...tail] => aux(tail, [h1] @ acc) // Optimization with reverse at end
    | [] => List.rev(acc)
    };
  };
  aux(codePointList, []);
};

let trim = (codePointList: list(PrecisUtils.codePoint)) => {
  let rec aux = (codePointList, acc) => {
    switch (codePointList) {
    | [h1, ...tail] when h1 == space => aux(tail, acc)
    | [h1, ...tail] => aux(tail, [h1] @ acc)
    | [] => List.rev(acc)
    };
  };
  aux(codePointList, []);
};

let lastLetterMap = (point: PrecisUtils.codePoint) => {
  switch point {
    | 931
    | 963 => 962
    | x => x
  };
};

let lowerCaseMap = (point: PrecisUtils.codePoint) =>
  if (point < 7788) {
    if (point < 1152) {
      if (point < 486) {
        if (point < 317) {
          if (point < 209) {
            if (point < 86) {
              if (point < 75) {
                if (point < 70) {
                  if (point < 67) {
                    switch (point) {
                    | 65 => 97
                    | 66 => 98
                    | point => point
                    };
                  } else if (point < 68) {
                    switch (point) {
                    | 67 => 99
                    | point => point
                    };
                  } else {
                    switch (point) {
                    | 68 => 100
                    | 69 => 101
                    | point => point
                    };
                  };
                } else if (point < 72) {
                  switch (point) {
                  | 70 => 102
                  | 71 => 103
                  | point => point
                  };
                } else if (point < 73) {
                  switch (point) {
                  | 72 => 104
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 73 => 105
                  | 74 => 106
                  | point => point
                  };
                };
              } else if (point < 80) {
                if (point < 77) {
                  switch (point) {
                  | 75 => 107
                  | 76 => 108
                  | point => point
                  };
                } else if (point < 78) {
                  switch (point) {
                  | 77 => 109
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 78 => 110
                  | 79 => 111
                  | point => point
                  };
                };
              } else if (point < 83) {
                if (point < 81) {
                  switch (point) {
                  | 80 => 112
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 81 => 113
                  | 82 => 114
                  | point => point
                  };
                };
              } else if (point < 84) {
                switch (point) {
                | 83 => 115
                | point => point
                };
              } else {
                switch (point) {
                | 84 => 116
                | 85 => 117
                | point => point
                };
              };
            } else if (point < 198) {
              if (point < 192) {
                if (point < 88) {
                  switch (point) {
                  | 86 => 118
                  | 87 => 119
                  | point => point
                  };
                } else if (point < 89) {
                  switch (point) {
                  | 88 => 120
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 89 => 121
                  | 90 => 122
                  | point => point
                  };
                };
              } else if (point < 195) {
                if (point < 193) {
                  switch (point) {
                  | 192 => 224
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 193 => 225
                  | 194 => 226
                  | point => point
                  };
                };
              } else if (point < 196) {
                switch (point) {
                | 195 => 227
                | point => point
                };
              } else {
                switch (point) {
                | 196 => 228
                | 197 => 229
                | point => point
                };
              };
            } else if (point < 203) {
              if (point < 200) {
                switch (point) {
                | 198 => 230
                | 199 => 231
                | point => point
                };
              } else if (point < 201) {
                switch (point) {
                | 200 => 232
                | point => point
                };
              } else {
                switch (point) {
                | 201 => 233
                | 202 => 234
                | point => point
                };
              };
            } else if (point < 206) {
              if (point < 204) {
                switch (point) {
                | 203 => 235
                | point => point
                };
              } else {
                switch (point) {
                | 204 => 236
                | 205 => 237
                | point => point
                };
              };
            } else if (point < 207) {
              switch (point) {
              | 206 => 238
              | point => point
              };
            } else {
              switch (point) {
              | 207 => 239
              | 208 => 240
              | point => point
              };
            };
          } else if (point < 272) {
            if (point < 220) {
              if (point < 214) {
                if (point < 211) {
                  switch (point) {
                  | 209 => 241
                  | 210 => 242
                  | point => point
                  };
                } else if (point < 212) {
                  switch (point) {
                  | 211 => 243
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 212 => 244
                  | 213 => 245
                  | point => point
                  };
                };
              } else if (point < 217) {
                switch (point) {
                | 214 => 246
                | 216 => 248
                | point => point
                };
              } else if (point < 218) {
                switch (point) {
                | 217 => 249
                | point => point
                };
              } else {
                switch (point) {
                | 218 => 250
                | 219 => 251
                | point => point
                };
              };
            } else if (point < 260) {
              if (point < 222) {
                switch (point) {
                | 220 => 252
                | 221 => 253
                | point => point
                };
              } else if (point < 256) {
                switch (point) {
                | 222 => 254
                | point => point
                };
              } else {
                switch (point) {
                | 256 => 257
                | 258 => 259
                | point => point
                };
              };
            } else if (point < 266) {
              if (point < 262) {
                switch (point) {
                | 260 => 261
                | point => point
                };
              } else {
                switch (point) {
                | 262 => 263
                | 264 => 265
                | point => point
                };
              };
            } else if (point < 268) {
              switch (point) {
              | 266 => 267
              | point => point
              };
            } else {
              switch (point) {
              | 268 => 269
              | 270 => 271
              | point => point
              };
            };
          } else if (point < 294) {
            if (point < 282) {
              if (point < 276) {
                switch (point) {
                | 272 => 273
                | 274 => 275
                | point => point
                };
              } else if (point < 278) {
                switch (point) {
                | 276 => 277
                | point => point
                };
              } else {
                switch (point) {
                | 278 => 279
                | 280 => 281
                | point => point
                };
              };
            } else if (point < 288) {
              if (point < 284) {
                switch (point) {
                | 282 => 283
                | point => point
                };
              } else {
                switch (point) {
                | 284 => 285
                | 286 => 287
                | point => point
                };
              };
            } else if (point < 290) {
              switch (point) {
              | 288 => 289
              | point => point
              };
            } else {
              switch (point) {
              | 290 => 291
              | 292 => 293
              | point => point
              };
            };
          } else if (point < 304) {
            if (point < 298) {
              switch (point) {
              | 294 => 295
              | 296 => 297
              | point => point
              };
            } else if (point < 300) {
              switch (point) {
              | 298 => 299
              | point => point
              };
            } else {
              switch (point) {
              | 300 => 301
              | 302 => 303
              | point => point
              };
            };
          } else if (point < 310) {
            if (point < 306) {
              switch (point) {
              | 304 => 105
              | point => point
              };
            } else {
              switch (point) {
              | 306 => 307
              | 308 => 309
              | point => point
              };
            };
          } else if (point < 313) {
            switch (point) {
            | 310 => 311
            | point => point
            };
          } else {
            switch (point) {
            | 313 => 314
            | 315 => 316
            | point => point
            };
          };
        } else if (point < 400) {
          if (point < 360) {
            if (point < 338) {
              if (point < 327) {
                if (point < 321) {
                  switch (point) {
                  | 317 => 318
                  | 319 => 320
                  | point => point
                  };
                } else if (point < 323) {
                  switch (point) {
                  | 321 => 322
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 323 => 324
                  | 325 => 326
                  | point => point
                  };
                };
              } else if (point < 332) {
                switch (point) {
                | 327 => 328
                | 330 => 331
                | point => point
                };
              } else if (point < 334) {
                switch (point) {
                | 332 => 333
                | point => point
                };
              } else {
                switch (point) {
                | 334 => 335
                | 336 => 337
                | point => point
                };
              };
            } else if (point < 348) {
              if (point < 342) {
                switch (point) {
                | 338 => 339
                | 340 => 341
                | point => point
                };
              } else if (point < 344) {
                switch (point) {
                | 342 => 343
                | point => point
                };
              } else {
                switch (point) {
                | 344 => 345
                | 346 => 347
                | point => point
                };
              };
            } else if (point < 354) {
              if (point < 350) {
                switch (point) {
                | 348 => 349
                | point => point
                };
              } else {
                switch (point) {
                | 350 => 351
                | 352 => 353
                | point => point
                };
              };
            } else if (point < 356) {
              switch (point) {
              | 354 => 355
              | point => point
              };
            } else {
              switch (point) {
              | 356 => 357
              | 358 => 359
              | point => point
              };
            };
          } else if (point < 381) {
            if (point < 370) {
              if (point < 364) {
                switch (point) {
                | 360 => 361
                | 362 => 363
                | point => point
                };
              } else if (point < 366) {
                switch (point) {
                | 364 => 365
                | point => point
                };
              } else {
                switch (point) {
                | 366 => 367
                | 368 => 369
                | point => point
                };
              };
            } else if (point < 376) {
              if (point < 372) {
                switch (point) {
                | 370 => 371
                | point => point
                };
              } else {
                switch (point) {
                | 372 => 373
                | 374 => 375
                | point => point
                };
              };
            } else if (point < 377) {
              switch (point) {
              | 376 => 255
              | point => point
              };
            } else {
              switch (point) {
              | 377 => 378
              | 379 => 380
              | point => point
              };
            };
          } else if (point < 391) {
            if (point < 386) {
              switch (point) {
              | 381 => 382
              | 385 => 595
              | point => point
              };
            } else if (point < 388) {
              switch (point) {
              | 386 => 387
              | point => point
              };
            } else {
              switch (point) {
              | 388 => 389
              | 390 => 596
              | point => point
              };
            };
          } else if (point < 395) {
            if (point < 393) {
              switch (point) {
              | 391 => 392
              | point => point
              };
            } else {
              switch (point) {
              | 393 => 598
              | 394 => 599
              | point => point
              };
            };
          } else if (point < 398) {
            switch (point) {
            | 395 => 396
            | point => point
            };
          } else {
            switch (point) {
            | 398 => 477
            | 399 => 601
            | point => point
            };
          };
        } else if (point < 437) {
          if (point < 418) {
            if (point < 407) {
              if (point < 403) {
                switch (point) {
                | 400 => 603
                | 401 => 402
                | point => point
                };
              } else if (point < 404) {
                switch (point) {
                | 403 => 608
                | point => point
                };
              } else {
                switch (point) {
                | 404 => 611
                | 406 => 617
                | point => point
                };
              };
            } else if (point < 413) {
              if (point < 408) {
                switch (point) {
                | 407 => 616
                | point => point
                };
              } else {
                switch (point) {
                | 408 => 409
                | 412 => 623
                | point => point
                };
              };
            } else if (point < 415) {
              switch (point) {
              | 413 => 626
              | point => point
              };
            } else {
              switch (point) {
              | 415 => 629
              | 416 => 417
              | point => point
              };
            };
          } else if (point < 428) {
            if (point < 422) {
              switch (point) {
              | 418 => 419
              | 420 => 421
              | point => point
              };
            } else if (point < 423) {
              switch (point) {
              | 422 => 640
              | point => point
              };
            } else {
              switch (point) {
              | 423 => 424
              | 425 => 643
              | point => point
              };
            };
          } else if (point < 433) {
            if (point < 430) {
              switch (point) {
              | 428 => 429
              | point => point
              };
            } else {
              switch (point) {
              | 430 => 648
              | 431 => 432
              | point => point
              };
            };
          } else if (point < 434) {
            switch (point) {
            | 433 => 650
            | point => point
            };
          } else {
            switch (point) {
            | 434 => 651
            | 435 => 436
            | point => point
            };
          };
        } else if (point < 463) {
          if (point < 453) {
            if (point < 440) {
              switch (point) {
              | 437 => 438
              | 439 => 658
              | point => point
              };
            } else if (point < 444) {
              switch (point) {
              | 440 => 441
              | point => point
              };
            } else {
              switch (point) {
              | 444 => 445
              | 452 => 454
              | point => point
              };
            };
          } else if (point < 458) {
            if (point < 455) {
              switch (point) {
              | 453 => 454
              | point => point
              };
            } else {
              switch (point) {
              | 455 => 457
              | 456 => 457
              | point => point
              };
            };
          } else if (point < 459) {
            switch (point) {
            | 458 => 460
            | point => point
            };
          } else {
            switch (point) {
            | 459 => 460
            | 461 => 462
            | point => point
            };
          };
        } else if (point < 473) {
          if (point < 467) {
            switch (point) {
            | 463 => 464
            | 465 => 466
            | point => point
            };
          } else if (point < 469) {
            switch (point) {
            | 467 => 468
            | point => point
            };
          } else {
            switch (point) {
            | 469 => 470
            | 471 => 472
            | point => point
            };
          };
        } else if (point < 480) {
          if (point < 475) {
            switch (point) {
            | 473 => 474
            | point => point
            };
          } else {
            switch (point) {
            | 475 => 476
            | 478 => 479
            | point => point
            };
          };
        } else if (point < 482) {
          switch (point) {
          | 480 => 481
          | point => point
          };
        } else {
          switch (point) {
          | 482 => 483
          | 484 => 485
          | point => point
          };
        };
      } else if (point < 937) {
        if (point < 574) {
          if (point < 526) {
            if (point < 504) {
              if (point < 497) {
                if (point < 490) {
                  switch (point) {
                  | 486 => 487
                  | 488 => 489
                  | point => point
                  };
                } else if (point < 492) {
                  switch (point) {
                  | 490 => 491
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 492 => 493
                  | 494 => 495
                  | point => point
                  };
                };
              } else if (point < 500) {
                switch (point) {
                | 497 => 499
                | 498 => 499
                | point => point
                };
              } else if (point < 502) {
                switch (point) {
                | 500 => 501
                | point => point
                };
              } else {
                switch (point) {
                | 502 => 405
                | 503 => 447
                | point => point
                };
              };
            } else if (point < 514) {
              if (point < 508) {
                switch (point) {
                | 504 => 505
                | 506 => 507
                | point => point
                };
              } else if (point < 510) {
                switch (point) {
                | 508 => 509
                | point => point
                };
              } else {
                switch (point) {
                | 510 => 511
                | 512 => 513
                | point => point
                };
              };
            } else if (point < 520) {
              if (point < 516) {
                switch (point) {
                | 514 => 515
                | point => point
                };
              } else {
                switch (point) {
                | 516 => 517
                | 518 => 519
                | point => point
                };
              };
            } else if (point < 522) {
              switch (point) {
              | 520 => 521
              | point => point
              };
            } else {
              switch (point) {
              | 522 => 523
              | 524 => 525
              | point => point
              };
            };
          } else if (point < 548) {
            if (point < 536) {
              if (point < 530) {
                switch (point) {
                | 526 => 527
                | 528 => 529
                | point => point
                };
              } else if (point < 532) {
                switch (point) {
                | 530 => 531
                | point => point
                };
              } else {
                switch (point) {
                | 532 => 533
                | 534 => 535
                | point => point
                };
              };
            } else if (point < 542) {
              if (point < 538) {
                switch (point) {
                | 536 => 537
                | point => point
                };
              } else {
                switch (point) {
                | 538 => 539
                | 540 => 541
                | point => point
                };
              };
            } else if (point < 544) {
              switch (point) {
              | 542 => 543
              | point => point
              };
            } else {
              switch (point) {
              | 544 => 414
              | 546 => 547
              | point => point
              };
            };
          } else if (point < 558) {
            if (point < 552) {
              switch (point) {
              | 548 => 549
              | 550 => 551
              | point => point
              };
            } else if (point < 554) {
              switch (point) {
              | 552 => 553
              | point => point
              };
            } else {
              switch (point) {
              | 554 => 555
              | 556 => 557
              | point => point
              };
            };
          } else if (point < 570) {
            if (point < 560) {
              switch (point) {
              | 558 => 559
              | point => point
              };
            } else {
              switch (point) {
              | 560 => 561
              | 562 => 563
              | point => point
              };
            };
          } else if (point < 571) {
            switch (point) {
            | 570 => 11365
            | point => point
            };
          } else {
            switch (point) {
            | 571 => 572
            | 573 => 410
            | point => point
            };
          };
        } else if (point < 914) {
          if (point < 882) {
            if (point < 582) {
              if (point < 579) {
                switch (point) {
                | 574 => 11366
                | 577 => 578
                | point => point
                };
              } else if (point < 580) {
                switch (point) {
                | 579 => 384
                | point => point
                };
              } else {
                switch (point) {
                | 580 => 649
                | 581 => 652
                | point => point
                };
              };
            } else if (point < 588) {
              if (point < 584) {
                switch (point) {
                | 582 => 583
                | point => point
                };
              } else {
                switch (point) {
                | 584 => 585
                | 586 => 587
                | point => point
                };
              };
            } else if (point < 590) {
              switch (point) {
              | 588 => 589
              | point => point
              };
            } else {
              switch (point) {
              | 590 => 591
              | 880 => 881
              | point => point
              };
            };
          } else if (point < 905) {
            if (point < 895) {
              switch (point) {
              | 882 => 883
              | 886 => 887
              | point => point
              };
            } else if (point < 902) {
              switch (point) {
              | 895 => 1011
              | point => point
              };
            } else {
              switch (point) {
              | 902 => 940
              | 904 => 941
              | point => point
              };
            };
          } else if (point < 910) {
            if (point < 906) {
              switch (point) {
              | 905 => 942
              | point => point
              };
            } else {
              switch (point) {
              | 906 => 943
              | 908 => 972
              | point => point
              };
            };
          } else if (point < 911) {
            switch (point) {
            | 910 => 973
            | point => point
            };
          } else {
            switch (point) {
            | 911 => 974
            | 913 => 945
            | point => point
            };
          };
        } else if (point < 925) {
          if (point < 919) {
            if (point < 916) {
              switch (point) {
              | 914 => 946
              | 915 => 947
              | point => point
              };
            } else if (point < 917) {
              switch (point) {
              | 916 => 948
              | point => point
              };
            } else {
              switch (point) {
              | 917 => 949
              | 918 => 950
              | point => point
              };
            };
          } else if (point < 922) {
            if (point < 920) {
              switch (point) {
              | 919 => 951
              | point => point
              };
            } else {
              switch (point) {
              | 920 => 952
              | 921 => 953
              | point => point
              };
            };
          } else if (point < 923) {
            switch (point) {
            | 922 => 954
            | point => point
            };
          } else {
            switch (point) {
            | 923 => 955
            | 924 => 956
            | point => point
            };
          };
        } else if (point < 931) {
          if (point < 927) {
            switch (point) {
            | 925 => 957
            | 926 => 958
            | point => point
            };
          } else if (point < 928) {
            switch (point) {
            | 927 => 959
            | point => point
            };
          } else {
            switch (point) {
            | 928 => 960
            | 929 => 961
            | point => point
            };
          };
        } else if (point < 934) {
          if (point < 932) {
            switch (point) {
            | 931 => 963
            | point => point
            };
          } else {
            switch (point) {
            | 932 => 964
            | 933 => 965
            | point => point
            };
          };
        } else if (point < 935) {
          switch (point) {
          | 934 => 966
          | point => point
          };
        } else {
          switch (point) {
          | 935 => 967
          | 936 => 968
          | point => point
          };
        };
      } else if (point < 1044) {
        if (point < 1022) {
          if (point < 996) {
            if (point < 986) {
              if (point < 939) {
                switch (point) {
                | 937 => 969
                | 938 => 970
                | point => point
                };
              } else if (point < 975) {
                switch (point) {
                | 939 => 971
                | point => point
                };
              } else {
                switch (point) {
                | 975 => 983
                | 979 => 973
                | 984 => 985
                | point => point
                };
              };
            } else if (point < 990) {
              switch (point) {
              | 986 => 987
              | 988 => 989
              | point => point
              };
            } else if (point < 992) {
              switch (point) {
              | 990 => 991
              | point => point
              };
            } else {
              switch (point) {
              | 992 => 993
              | 994 => 995
              | point => point
              };
            };
          } else if (point < 1006) {
            if (point < 1000) {
              switch (point) {
              | 996 => 997
              | 998 => 999
              | point => point
              };
            } else if (point < 1002) {
              switch (point) {
              | 1000 => 1001
              | point => point
              };
            } else {
              switch (point) {
              | 1002 => 1003
              | 1004 => 1005
              | point => point
              };
            };
          } else if (point < 1017) {
            if (point < 1012) {
              switch (point) {
              | 1006 => 1007
              | point => point
              };
            } else {
              switch (point) {
              | 1012 => 952
              | 1015 => 1016
              | point => point
              };
            };
          } else if (point < 1018) {
            switch (point) {
            | 1017 => 1010
            | point => point
            };
          } else {
            switch (point) {
            | 1018 => 1019
            | 1021 => 891
            | point => point
            };
          };
        } else if (point < 1033) {
          if (point < 1027) {
            if (point < 1024) {
              switch (point) {
              | 1022 => 892
              | 1023 => 893
              | point => point
              };
            } else if (point < 1025) {
              switch (point) {
              | 1024 => 1104
              | point => point
              };
            } else {
              switch (point) {
              | 1025 => 1105
              | 1026 => 1106
              | point => point
              };
            };
          } else if (point < 1030) {
            if (point < 1028) {
              switch (point) {
              | 1027 => 1107
              | point => point
              };
            } else {
              switch (point) {
              | 1028 => 1108
              | 1029 => 1109
              | point => point
              };
            };
          } else if (point < 1031) {
            switch (point) {
            | 1030 => 1110
            | point => point
            };
          } else {
            switch (point) {
            | 1031 => 1111
            | 1032 => 1112
            | point => point
            };
          };
        } else if (point < 1038) {
          if (point < 1035) {
            switch (point) {
            | 1033 => 1113
            | 1034 => 1114
            | point => point
            };
          } else if (point < 1036) {
            switch (point) {
            | 1035 => 1115
            | point => point
            };
          } else {
            switch (point) {
            | 1036 => 1116
            | 1037 => 1117
            | point => point
            };
          };
        } else if (point < 1041) {
          if (point < 1039) {
            switch (point) {
            | 1038 => 1118
            | point => point
            };
          } else {
            switch (point) {
            | 1039 => 1119
            | 1040 => 1072
            | point => point
            };
          };
        } else if (point < 1042) {
          switch (point) {
          | 1041 => 1073
          | point => point
          };
        } else {
          switch (point) {
          | 1042 => 1074
          | 1043 => 1075
          | point => point
          };
        };
      } else if (point < 1066) {
        if (point < 1055) {
          if (point < 1049) {
            if (point < 1046) {
              switch (point) {
              | 1044 => 1076
              | 1045 => 1077
              | point => point
              };
            } else if (point < 1047) {
              switch (point) {
              | 1046 => 1078
              | point => point
              };
            } else {
              switch (point) {
              | 1047 => 1079
              | 1048 => 1080
              | point => point
              };
            };
          } else if (point < 1052) {
            if (point < 1050) {
              switch (point) {
              | 1049 => 1081
              | point => point
              };
            } else {
              switch (point) {
              | 1050 => 1082
              | 1051 => 1083
              | point => point
              };
            };
          } else if (point < 1053) {
            switch (point) {
            | 1052 => 1084
            | point => point
            };
          } else {
            switch (point) {
            | 1053 => 1085
            | 1054 => 1086
            | point => point
            };
          };
        } else if (point < 1060) {
          if (point < 1057) {
            switch (point) {
            | 1055 => 1087
            | 1056 => 1088
            | point => point
            };
          } else if (point < 1058) {
            switch (point) {
            | 1057 => 1089
            | point => point
            };
          } else {
            switch (point) {
            | 1058 => 1090
            | 1059 => 1091
            | point => point
            };
          };
        } else if (point < 1063) {
          if (point < 1061) {
            switch (point) {
            | 1060 => 1092
            | point => point
            };
          } else {
            switch (point) {
            | 1061 => 1093
            | 1062 => 1094
            | point => point
            };
          };
        } else if (point < 1064) {
          switch (point) {
          | 1063 => 1095
          | point => point
          };
        } else {
          switch (point) {
          | 1064 => 1096
          | 1065 => 1097
          | point => point
          };
        };
      } else if (point < 1130) {
        if (point < 1071) {
          if (point < 1068) {
            switch (point) {
            | 1066 => 1098
            | 1067 => 1099
            | point => point
            };
          } else if (point < 1069) {
            switch (point) {
            | 1068 => 1100
            | point => point
            };
          } else {
            switch (point) {
            | 1069 => 1101
            | 1070 => 1102
            | point => point
            };
          };
        } else if (point < 1124) {
          if (point < 1120) {
            switch (point) {
            | 1071 => 1103
            | point => point
            };
          } else {
            switch (point) {
            | 1120 => 1121
            | 1122 => 1123
            | point => point
            };
          };
        } else if (point < 1126) {
          switch (point) {
          | 1124 => 1125
          | point => point
          };
        } else {
          switch (point) {
          | 1126 => 1127
          | 1128 => 1129
          | point => point
          };
        };
      } else if (point < 1140) {
        if (point < 1134) {
          switch (point) {
          | 1130 => 1131
          | 1132 => 1133
          | point => point
          };
        } else if (point < 1136) {
          switch (point) {
          | 1134 => 1135
          | point => point
          };
        } else {
          switch (point) {
          | 1136 => 1137
          | 1138 => 1139
          | point => point
          };
        };
      } else if (point < 1146) {
        if (point < 1142) {
          switch (point) {
          | 1140 => 1141
          | point => point
          };
        } else {
          switch (point) {
          | 1142 => 1143
          | 1144 => 1145
          | point => point
          };
        };
      } else if (point < 1148) {
        switch (point) {
        | 1146 => 1147
        | point => point
        };
      } else {
        switch (point) {
        | 1148 => 1149
        | 1150 => 1151
        | point => point
        };
      };
    } else if (point < 5036) {
      if (point < 1332) {
        if (point < 1246) {
          if (point < 1202) {
            if (point < 1180) {
              if (point < 1170) {
                if (point < 1164) {
                  switch (point) {
                  | 1152 => 1153
                  | 1162 => 1163
                  | point => point
                  };
                } else if (point < 1166) {
                  switch (point) {
                  | 1164 => 1165
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 1166 => 1167
                  | 1168 => 1169
                  | point => point
                  };
                };
              } else if (point < 1174) {
                switch (point) {
                | 1170 => 1171
                | 1172 => 1173
                | point => point
                };
              } else if (point < 1176) {
                switch (point) {
                | 1174 => 1175
                | point => point
                };
              } else {
                switch (point) {
                | 1176 => 1177
                | 1178 => 1179
                | point => point
                };
              };
            } else if (point < 1190) {
              if (point < 1184) {
                switch (point) {
                | 1180 => 1181
                | 1182 => 1183
                | point => point
                };
              } else if (point < 1186) {
                switch (point) {
                | 1184 => 1185
                | point => point
                };
              } else {
                switch (point) {
                | 1186 => 1187
                | 1188 => 1189
                | point => point
                };
              };
            } else if (point < 1196) {
              if (point < 1192) {
                switch (point) {
                | 1190 => 1191
                | point => point
                };
              } else {
                switch (point) {
                | 1192 => 1193
                | 1194 => 1195
                | point => point
                };
              };
            } else if (point < 1198) {
              switch (point) {
              | 1196 => 1197
              | point => point
              };
            } else {
              switch (point) {
              | 1198 => 1199
              | 1200 => 1201
              | point => point
              };
            };
          } else if (point < 1223) {
            if (point < 1212) {
              if (point < 1206) {
                switch (point) {
                | 1202 => 1203
                | 1204 => 1205
                | point => point
                };
              } else if (point < 1208) {
                switch (point) {
                | 1206 => 1207
                | point => point
                };
              } else {
                switch (point) {
                | 1208 => 1209
                | 1210 => 1211
                | point => point
                };
              };
            } else if (point < 1217) {
              if (point < 1214) {
                switch (point) {
                | 1212 => 1213
                | point => point
                };
              } else {
                switch (point) {
                | 1214 => 1215
                | 1216 => 1231
                | point => point
                };
              };
            } else if (point < 1219) {
              switch (point) {
              | 1217 => 1218
              | point => point
              };
            } else {
              switch (point) {
              | 1219 => 1220
              | 1221 => 1222
              | point => point
              };
            };
          } else if (point < 1234) {
            if (point < 1227) {
              switch (point) {
              | 1223 => 1224
              | 1225 => 1226
              | point => point
              };
            } else if (point < 1229) {
              switch (point) {
              | 1227 => 1228
              | point => point
              };
            } else {
              switch (point) {
              | 1229 => 1230
              | 1232 => 1233
              | point => point
              };
            };
          } else if (point < 1240) {
            if (point < 1236) {
              switch (point) {
              | 1234 => 1235
              | point => point
              };
            } else {
              switch (point) {
              | 1236 => 1237
              | 1238 => 1239
              | point => point
              };
            };
          } else if (point < 1242) {
            switch (point) {
            | 1240 => 1241
            | point => point
            };
          } else {
            switch (point) {
            | 1242 => 1243
            | 1244 => 1245
            | point => point
            };
          };
        } else if (point < 1290) {
          if (point < 1268) {
            if (point < 1256) {
              if (point < 1250) {
                switch (point) {
                | 1246 => 1247
                | 1248 => 1249
                | point => point
                };
              } else if (point < 1252) {
                switch (point) {
                | 1250 => 1251
                | point => point
                };
              } else {
                switch (point) {
                | 1252 => 1253
                | 1254 => 1255
                | point => point
                };
              };
            } else if (point < 1262) {
              if (point < 1258) {
                switch (point) {
                | 1256 => 1257
                | point => point
                };
              } else {
                switch (point) {
                | 1258 => 1259
                | 1260 => 1261
                | point => point
                };
              };
            } else if (point < 1264) {
              switch (point) {
              | 1262 => 1263
              | point => point
              };
            } else {
              switch (point) {
              | 1264 => 1265
              | 1266 => 1267
              | point => point
              };
            };
          } else if (point < 1278) {
            if (point < 1272) {
              switch (point) {
              | 1268 => 1269
              | 1270 => 1271
              | point => point
              };
            } else if (point < 1274) {
              switch (point) {
              | 1272 => 1273
              | point => point
              };
            } else {
              switch (point) {
              | 1274 => 1275
              | 1276 => 1277
              | point => point
              };
            };
          } else if (point < 1284) {
            if (point < 1280) {
              switch (point) {
              | 1278 => 1279
              | point => point
              };
            } else {
              switch (point) {
              | 1280 => 1281
              | 1282 => 1283
              | point => point
              };
            };
          } else if (point < 1286) {
            switch (point) {
            | 1284 => 1285
            | point => point
            };
          } else {
            switch (point) {
            | 1286 => 1287
            | 1288 => 1289
            | point => point
            };
          };
        } else if (point < 1312) {
          if (point < 1300) {
            if (point < 1294) {
              switch (point) {
              | 1290 => 1291
              | 1292 => 1293
              | point => point
              };
            } else if (point < 1296) {
              switch (point) {
              | 1294 => 1295
              | point => point
              };
            } else {
              switch (point) {
              | 1296 => 1297
              | 1298 => 1299
              | point => point
              };
            };
          } else if (point < 1306) {
            if (point < 1302) {
              switch (point) {
              | 1300 => 1301
              | point => point
              };
            } else {
              switch (point) {
              | 1302 => 1303
              | 1304 => 1305
              | point => point
              };
            };
          } else if (point < 1308) {
            switch (point) {
            | 1306 => 1307
            | point => point
            };
          } else {
            switch (point) {
            | 1308 => 1309
            | 1310 => 1311
            | point => point
            };
          };
        } else if (point < 1322) {
          if (point < 1316) {
            switch (point) {
            | 1312 => 1313
            | 1314 => 1315
            | point => point
            };
          } else if (point < 1318) {
            switch (point) {
            | 1316 => 1317
            | point => point
            };
          } else {
            switch (point) {
            | 1318 => 1319
            | 1320 => 1321
            | point => point
            };
          };
        } else if (point < 1329) {
          if (point < 1324) {
            switch (point) {
            | 1322 => 1323
            | point => point
            };
          } else {
            switch (point) {
            | 1324 => 1325
            | 1326 => 1327
            | point => point
            };
          };
        } else if (point < 1330) {
          switch (point) {
          | 1329 => 1377
          | point => point
          };
        } else {
          switch (point) {
          | 1330 => 1378
          | 1331 => 1379
          | point => point
          };
        };
      } else if (point < 4264) {
        if (point < 1353) {
          if (point < 1342) {
            if (point < 1337) {
              if (point < 1334) {
                switch (point) {
                | 1332 => 1380
                | 1333 => 1381
                | point => point
                };
              } else if (point < 1335) {
                switch (point) {
                | 1334 => 1382
                | point => point
                };
              } else {
                switch (point) {
                | 1335 => 1383
                | 1336 => 1384
                | point => point
                };
              };
            } else if (point < 1339) {
              switch (point) {
              | 1337 => 1385
              | 1338 => 1386
              | point => point
              };
            } else if (point < 1340) {
              switch (point) {
              | 1339 => 1387
              | point => point
              };
            } else {
              switch (point) {
              | 1340 => 1388
              | 1341 => 1389
              | point => point
              };
            };
          } else if (point < 1347) {
            if (point < 1344) {
              switch (point) {
              | 1342 => 1390
              | 1343 => 1391
              | point => point
              };
            } else if (point < 1345) {
              switch (point) {
              | 1344 => 1392
              | point => point
              };
            } else {
              switch (point) {
              | 1345 => 1393
              | 1346 => 1394
              | point => point
              };
            };
          } else if (point < 1350) {
            if (point < 1348) {
              switch (point) {
              | 1347 => 1395
              | point => point
              };
            } else {
              switch (point) {
              | 1348 => 1396
              | 1349 => 1397
              | point => point
              };
            };
          } else if (point < 1351) {
            switch (point) {
            | 1350 => 1398
            | point => point
            };
          } else {
            switch (point) {
            | 1351 => 1399
            | 1352 => 1400
            | point => point
            };
          };
        } else if (point < 1364) {
          if (point < 1358) {
            if (point < 1355) {
              switch (point) {
              | 1353 => 1401
              | 1354 => 1402
              | point => point
              };
            } else if (point < 1356) {
              switch (point) {
              | 1355 => 1403
              | point => point
              };
            } else {
              switch (point) {
              | 1356 => 1404
              | 1357 => 1405
              | point => point
              };
            };
          } else if (point < 1361) {
            if (point < 1359) {
              switch (point) {
              | 1358 => 1406
              | point => point
              };
            } else {
              switch (point) {
              | 1359 => 1407
              | 1360 => 1408
              | point => point
              };
            };
          } else if (point < 1362) {
            switch (point) {
            | 1361 => 1409
            | point => point
            };
          } else {
            switch (point) {
            | 1362 => 1410
            | 1363 => 1411
            | point => point
            };
          };
        } else if (point < 4258) {
          if (point < 1366) {
            switch (point) {
            | 1364 => 1412
            | 1365 => 1413
            | point => point
            };
          } else if (point < 4256) {
            switch (point) {
            | 1366 => 1414
            | point => point
            };
          } else {
            switch (point) {
            | 4256 => 11520
            | 4257 => 11521
            | point => point
            };
          };
        } else if (point < 4261) {
          if (point < 4259) {
            switch (point) {
            | 4258 => 11522
            | point => point
            };
          } else {
            switch (point) {
            | 4259 => 11523
            | 4260 => 11524
            | point => point
            };
          };
        } else if (point < 4262) {
          switch (point) {
          | 4261 => 11525
          | point => point
          };
        } else {
          switch (point) {
          | 4262 => 11526
          | 4263 => 11527
          | point => point
          };
        };
      } else if (point < 4286) {
        if (point < 4275) {
          if (point < 4269) {
            if (point < 4266) {
              switch (point) {
              | 4264 => 11528
              | 4265 => 11529
              | point => point
              };
            } else if (point < 4267) {
              switch (point) {
              | 4266 => 11530
              | point => point
              };
            } else {
              switch (point) {
              | 4267 => 11531
              | 4268 => 11532
              | point => point
              };
            };
          } else if (point < 4272) {
            if (point < 4270) {
              switch (point) {
              | 4269 => 11533
              | point => point
              };
            } else {
              switch (point) {
              | 4270 => 11534
              | 4271 => 11535
              | point => point
              };
            };
          } else if (point < 4273) {
            switch (point) {
            | 4272 => 11536
            | point => point
            };
          } else {
            switch (point) {
            | 4273 => 11537
            | 4274 => 11538
            | point => point
            };
          };
        } else if (point < 4280) {
          if (point < 4277) {
            switch (point) {
            | 4275 => 11539
            | 4276 => 11540
            | point => point
            };
          } else if (point < 4278) {
            switch (point) {
            | 4277 => 11541
            | point => point
            };
          } else {
            switch (point) {
            | 4278 => 11542
            | 4279 => 11543
            | point => point
            };
          };
        } else if (point < 4283) {
          if (point < 4281) {
            switch (point) {
            | 4280 => 11544
            | point => point
            };
          } else {
            switch (point) {
            | 4281 => 11545
            | 4282 => 11546
            | point => point
            };
          };
        } else if (point < 4284) {
          switch (point) {
          | 4283 => 11547
          | point => point
          };
        } else {
          switch (point) {
          | 4284 => 11548
          | 4285 => 11549
          | point => point
          };
        };
      } else if (point < 5025) {
        if (point < 4291) {
          if (point < 4288) {
            switch (point) {
            | 4286 => 11550
            | 4287 => 11551
            | point => point
            };
          } else if (point < 4289) {
            switch (point) {
            | 4288 => 11552
            | point => point
            };
          } else {
            switch (point) {
            | 4289 => 11553
            | 4290 => 11554
            | point => point
            };
          };
        } else if (point < 4295) {
          if (point < 4292) {
            switch (point) {
            | 4291 => 11555
            | point => point
            };
          } else {
            switch (point) {
            | 4292 => 11556
            | 4293 => 11557
            | point => point
            };
          };
        } else if (point < 4301) {
          switch (point) {
          | 4295 => 11559
          | point => point
          };
        } else {
          switch (point) {
          | 4301 => 11565
          | 5024 => 43888
          | point => point
          };
        };
      } else if (point < 5030) {
        if (point < 5027) {
          switch (point) {
          | 5025 => 43889
          | 5026 => 43890
          | point => point
          };
        } else if (point < 5028) {
          switch (point) {
          | 5027 => 43891
          | point => point
          };
        } else {
          switch (point) {
          | 5028 => 43892
          | 5029 => 43893
          | point => point
          };
        };
      } else if (point < 5033) {
        if (point < 5031) {
          switch (point) {
          | 5030 => 43894
          | point => point
          };
        } else {
          switch (point) {
          | 5031 => 43895
          | 5032 => 43896
          | point => point
          };
        };
      } else if (point < 5034) {
        switch (point) {
        | 5033 => 43897
        | point => point
        };
      } else {
        switch (point) {
        | 5034 => 43898
        | 5035 => 43899
        | point => point
        };
      };
    } else if (point < 7325) {
      if (point < 5079) {
        if (point < 5057) {
          if (point < 5046) {
            if (point < 5041) {
              if (point < 5038) {
                switch (point) {
                | 5036 => 43900
                | 5037 => 43901
                | point => point
                };
              } else if (point < 5039) {
                switch (point) {
                | 5038 => 43902
                | point => point
                };
              } else {
                switch (point) {
                | 5039 => 43903
                | 5040 => 43904
                | point => point
                };
              };
            } else if (point < 5043) {
              switch (point) {
              | 5041 => 43905
              | 5042 => 43906
              | point => point
              };
            } else if (point < 5044) {
              switch (point) {
              | 5043 => 43907
              | point => point
              };
            } else {
              switch (point) {
              | 5044 => 43908
              | 5045 => 43909
              | point => point
              };
            };
          } else if (point < 5051) {
            if (point < 5048) {
              switch (point) {
              | 5046 => 43910
              | 5047 => 43911
              | point => point
              };
            } else if (point < 5049) {
              switch (point) {
              | 5048 => 43912
              | point => point
              };
            } else {
              switch (point) {
              | 5049 => 43913
              | 5050 => 43914
              | point => point
              };
            };
          } else if (point < 5054) {
            if (point < 5052) {
              switch (point) {
              | 5051 => 43915
              | point => point
              };
            } else {
              switch (point) {
              | 5052 => 43916
              | 5053 => 43917
              | point => point
              };
            };
          } else if (point < 5055) {
            switch (point) {
            | 5054 => 43918
            | point => point
            };
          } else {
            switch (point) {
            | 5055 => 43919
            | 5056 => 43920
            | point => point
            };
          };
        } else if (point < 5068) {
          if (point < 5062) {
            if (point < 5059) {
              switch (point) {
              | 5057 => 43921
              | 5058 => 43922
              | point => point
              };
            } else if (point < 5060) {
              switch (point) {
              | 5059 => 43923
              | point => point
              };
            } else {
              switch (point) {
              | 5060 => 43924
              | 5061 => 43925
              | point => point
              };
            };
          } else if (point < 5065) {
            if (point < 5063) {
              switch (point) {
              | 5062 => 43926
              | point => point
              };
            } else {
              switch (point) {
              | 5063 => 43927
              | 5064 => 43928
              | point => point
              };
            };
          } else if (point < 5066) {
            switch (point) {
            | 5065 => 43929
            | point => point
            };
          } else {
            switch (point) {
            | 5066 => 43930
            | 5067 => 43931
            | point => point
            };
          };
        } else if (point < 5073) {
          if (point < 5070) {
            switch (point) {
            | 5068 => 43932
            | 5069 => 43933
            | point => point
            };
          } else if (point < 5071) {
            switch (point) {
            | 5070 => 43934
            | point => point
            };
          } else {
            switch (point) {
            | 5071 => 43935
            | 5072 => 43936
            | point => point
            };
          };
        } else if (point < 5076) {
          if (point < 5074) {
            switch (point) {
            | 5073 => 43937
            | point => point
            };
          } else {
            switch (point) {
            | 5074 => 43938
            | 5075 => 43939
            | point => point
            };
          };
        } else if (point < 5077) {
          switch (point) {
          | 5076 => 43940
          | point => point
          };
        } else {
          switch (point) {
          | 5077 => 43941
          | 5078 => 43942
          | point => point
          };
        };
      } else if (point < 5101) {
        if (point < 5090) {
          if (point < 5084) {
            if (point < 5081) {
              switch (point) {
              | 5079 => 43943
              | 5080 => 43944
              | point => point
              };
            } else if (point < 5082) {
              switch (point) {
              | 5081 => 43945
              | point => point
              };
            } else {
              switch (point) {
              | 5082 => 43946
              | 5083 => 43947
              | point => point
              };
            };
          } else if (point < 5087) {
            if (point < 5085) {
              switch (point) {
              | 5084 => 43948
              | point => point
              };
            } else {
              switch (point) {
              | 5085 => 43949
              | 5086 => 43950
              | point => point
              };
            };
          } else if (point < 5088) {
            switch (point) {
            | 5087 => 43951
            | point => point
            };
          } else {
            switch (point) {
            | 5088 => 43952
            | 5089 => 43953
            | point => point
            };
          };
        } else if (point < 5095) {
          if (point < 5092) {
            switch (point) {
            | 5090 => 43954
            | 5091 => 43955
            | point => point
            };
          } else if (point < 5093) {
            switch (point) {
            | 5092 => 43956
            | point => point
            };
          } else {
            switch (point) {
            | 5093 => 43957
            | 5094 => 43958
            | point => point
            };
          };
        } else if (point < 5098) {
          if (point < 5096) {
            switch (point) {
            | 5095 => 43959
            | point => point
            };
          } else {
            switch (point) {
            | 5096 => 43960
            | 5097 => 43961
            | point => point
            };
          };
        } else if (point < 5099) {
          switch (point) {
          | 5098 => 43962
          | point => point
          };
        } else {
          switch (point) {
          | 5099 => 43963
          | 5100 => 43964
          | point => point
          };
        };
      } else if (point < 7314) {
        if (point < 5106) {
          if (point < 5103) {
            switch (point) {
            | 5101 => 43965
            | 5102 => 43966
            | point => point
            };
          } else if (point < 5104) {
            switch (point) {
            | 5103 => 43967
            | point => point
            };
          } else {
            switch (point) {
            | 5104 => 5112
            | 5105 => 5113
            | point => point
            };
          };
        } else if (point < 5109) {
          if (point < 5107) {
            switch (point) {
            | 5106 => 5114
            | point => point
            };
          } else {
            switch (point) {
            | 5107 => 5115
            | 5108 => 5116
            | point => point
            };
          };
        } else if (point < 7312) {
          switch (point) {
          | 5109 => 5117
          | point => point
          };
        } else {
          switch (point) {
          | 7312 => 4304
          | 7313 => 4305
          | point => point
          };
        };
      } else if (point < 7319) {
        if (point < 7316) {
          switch (point) {
          | 7314 => 4306
          | 7315 => 4307
          | point => point
          };
        } else if (point < 7317) {
          switch (point) {
          | 7316 => 4308
          | point => point
          };
        } else {
          switch (point) {
          | 7317 => 4309
          | 7318 => 4310
          | point => point
          };
        };
      } else if (point < 7322) {
        if (point < 7320) {
          switch (point) {
          | 7319 => 4311
          | point => point
          };
        } else {
          switch (point) {
          | 7320 => 4312
          | 7321 => 4313
          | point => point
          };
        };
      } else if (point < 7323) {
        switch (point) {
        | 7322 => 4314
        | point => point
        };
      } else {
        switch (point) {
        | 7323 => 4315
        | 7324 => 4316
        | point => point
        };
      };
    } else if (point < 7700) {
      if (point < 7346) {
        if (point < 7335) {
          if (point < 7330) {
            if (point < 7327) {
              switch (point) {
              | 7325 => 4317
              | 7326 => 4318
              | point => point
              };
            } else if (point < 7328) {
              switch (point) {
              | 7327 => 4319
              | point => point
              };
            } else {
              switch (point) {
              | 7328 => 4320
              | 7329 => 4321
              | point => point
              };
            };
          } else if (point < 7332) {
            switch (point) {
            | 7330 => 4322
            | 7331 => 4323
            | point => point
            };
          } else if (point < 7333) {
            switch (point) {
            | 7332 => 4324
            | point => point
            };
          } else {
            switch (point) {
            | 7333 => 4325
            | 7334 => 4326
            | point => point
            };
          };
        } else if (point < 7340) {
          if (point < 7337) {
            switch (point) {
            | 7335 => 4327
            | 7336 => 4328
            | point => point
            };
          } else if (point < 7338) {
            switch (point) {
            | 7337 => 4329
            | point => point
            };
          } else {
            switch (point) {
            | 7338 => 4330
            | 7339 => 4331
            | point => point
            };
          };
        } else if (point < 7343) {
          if (point < 7341) {
            switch (point) {
            | 7340 => 4332
            | point => point
            };
          } else {
            switch (point) {
            | 7341 => 4333
            | 7342 => 4334
            | point => point
            };
          };
        } else if (point < 7344) {
          switch (point) {
          | 7343 => 4335
          | point => point
          };
        } else {
          switch (point) {
          | 7344 => 4336
          | 7345 => 4337
          | point => point
          };
        };
      } else if (point < 7359) {
        if (point < 7351) {
          if (point < 7348) {
            switch (point) {
            | 7346 => 4338
            | 7347 => 4339
            | point => point
            };
          } else if (point < 7349) {
            switch (point) {
            | 7348 => 4340
            | point => point
            };
          } else {
            switch (point) {
            | 7349 => 4341
            | 7350 => 4342
            | point => point
            };
          };
        } else if (point < 7354) {
          if (point < 7352) {
            switch (point) {
            | 7351 => 4343
            | point => point
            };
          } else {
            switch (point) {
            | 7352 => 4344
            | 7353 => 4345
            | point => point
            };
          };
        } else if (point < 7357) {
          switch (point) {
          | 7354 => 4346
          | point => point
          };
        } else {
          switch (point) {
          | 7357 => 4349
          | 7358 => 4350
          | point => point
          };
        };
      } else if (point < 7688) {
        if (point < 7682) {
          switch (point) {
          | 7359 => 4351
          | 7680 => 7681
          | point => point
          };
        } else if (point < 7684) {
          switch (point) {
          | 7682 => 7683
          | point => point
          };
        } else {
          switch (point) {
          | 7684 => 7685
          | 7686 => 7687
          | point => point
          };
        };
      } else if (point < 7694) {
        if (point < 7690) {
          switch (point) {
          | 7688 => 7689
          | point => point
          };
        } else {
          switch (point) {
          | 7690 => 7691
          | 7692 => 7693
          | point => point
          };
        };
      } else if (point < 7696) {
        switch (point) {
        | 7694 => 7695
        | point => point
        };
      } else {
        switch (point) {
        | 7696 => 7697
        | 7698 => 7699
        | point => point
        };
      };
    } else if (point < 7744) {
      if (point < 7722) {
        if (point < 7710) {
          if (point < 7704) {
            switch (point) {
            | 7700 => 7701
            | 7702 => 7703
            | point => point
            };
          } else if (point < 7706) {
            switch (point) {
            | 7704 => 7705
            | point => point
            };
          } else {
            switch (point) {
            | 7706 => 7707
            | 7708 => 7709
            | point => point
            };
          };
        } else if (point < 7716) {
          if (point < 7712) {
            switch (point) {
            | 7710 => 7711
            | point => point
            };
          } else {
            switch (point) {
            | 7712 => 7713
            | 7714 => 7715
            | point => point
            };
          };
        } else if (point < 7718) {
          switch (point) {
          | 7716 => 7717
          | point => point
          };
        } else {
          switch (point) {
          | 7718 => 7719
          | 7720 => 7721
          | point => point
          };
        };
      } else if (point < 7732) {
        if (point < 7726) {
          switch (point) {
          | 7722 => 7723
          | 7724 => 7725
          | point => point
          };
        } else if (point < 7728) {
          switch (point) {
          | 7726 => 7727
          | point => point
          };
        } else {
          switch (point) {
          | 7728 => 7729
          | 7730 => 7731
          | point => point
          };
        };
      } else if (point < 7738) {
        if (point < 7734) {
          switch (point) {
          | 7732 => 7733
          | point => point
          };
        } else {
          switch (point) {
          | 7734 => 7735
          | 7736 => 7737
          | point => point
          };
        };
      } else if (point < 7740) {
        switch (point) {
        | 7738 => 7739
        | point => point
        };
      } else {
        switch (point) {
        | 7740 => 7741
        | 7742 => 7743
        | point => point
        };
      };
    } else if (point < 7766) {
      if (point < 7754) {
        if (point < 7748) {
          switch (point) {
          | 7744 => 7745
          | 7746 => 7747
          | point => point
          };
        } else if (point < 7750) {
          switch (point) {
          | 7748 => 7749
          | point => point
          };
        } else {
          switch (point) {
          | 7750 => 7751
          | 7752 => 7753
          | point => point
          };
        };
      } else if (point < 7760) {
        if (point < 7756) {
          switch (point) {
          | 7754 => 7755
          | point => point
          };
        } else {
          switch (point) {
          | 7756 => 7757
          | 7758 => 7759
          | point => point
          };
        };
      } else if (point < 7762) {
        switch (point) {
        | 7760 => 7761
        | point => point
        };
      } else {
        switch (point) {
        | 7762 => 7763
        | 7764 => 7765
        | point => point
        };
      };
    } else if (point < 7776) {
      if (point < 7770) {
        switch (point) {
        | 7766 => 7767
        | 7768 => 7769
        | point => point
        };
      } else if (point < 7772) {
        switch (point) {
        | 7770 => 7771
        | point => point
        };
      } else {
        switch (point) {
        | 7772 => 7773
        | 7774 => 7775
        | point => point
        };
      };
    } else if (point < 7782) {
      if (point < 7778) {
        switch (point) {
        | 7776 => 7777
        | point => point
        };
      } else {
        switch (point) {
        | 7778 => 7779
        | 7780 => 7781
        | point => point
        };
      };
    } else if (point < 7784) {
      switch (point) {
      | 7782 => 7783
      | point => point
      };
    } else {
      switch (point) {
      | 7784 => 7785
      | 7786 => 7787
      | point => point
      };
    };
  } else if (point < 42598) {
    if (point < 8547) {
      if (point < 7978) {
        if (point < 7882) {
          if (point < 7838) {
            if (point < 7808) {
              if (point < 7798) {
                if (point < 7792) {
                  switch (point) {
                  | 7788 => 7789
                  | 7790 => 7791
                  | point => point
                  };
                } else if (point < 7794) {
                  switch (point) {
                  | 7792 => 7793
                  | point => point
                  };
                } else {
                  switch (point) {
                  | 7794 => 7795
                  | 7796 => 7797
                  | point => point
                  };
                };
              } else if (point < 7802) {
                switch (point) {
                | 7798 => 7799
                | 7800 => 7801
                | point => point
                };
              } else if (point < 7804) {
                switch (point) {
                | 7802 => 7803
                | point => point
                };
              } else {
                switch (point) {
                | 7804 => 7805
                | 7806 => 7807
                | point => point
                };
              };
            } else if (point < 7818) {
              if (point < 7812) {
                switch (point) {
                | 7808 => 7809
                | 7810 => 7811
                | point => point
                };
              } else if (point < 7814) {
                switch (point) {
                | 7812 => 7813
                | point => point
                };
              } else {
                switch (point) {
                | 7814 => 7815
                | 7816 => 7817
                | point => point
                };
              };
            } else if (point < 7824) {
              if (point < 7820) {
                switch (point) {
                | 7818 => 7819
                | point => point
                };
              } else {
                switch (point) {
                | 7820 => 7821
                | 7822 => 7823
                | point => point
                };
              };
            } else if (point < 7826) {
              switch (point) {
              | 7824 => 7825
              | point => point
              };
            } else {
              switch (point) {
              | 7826 => 7827
              | 7828 => 7829
              | point => point
              };
            };
          } else if (point < 7860) {
            if (point < 7848) {
              if (point < 7842) {
                switch (point) {
                | 7838 => 223
                | 7840 => 7841
                | point => point
                };
              } else if (point < 7844) {
                switch (point) {
                | 7842 => 7843
                | point => point
                };
              } else {
                switch (point) {
                | 7844 => 7845
                | 7846 => 7847
                | point => point
                };
              };
            } else if (point < 7854) {
              if (point < 7850) {
                switch (point) {
                | 7848 => 7849
                | point => point
                };
              } else {
                switch (point) {
                | 7850 => 7851
                | 7852 => 7853
                | point => point
                };
              };
            } else if (point < 7856) {
              switch (point) {
              | 7854 => 7855
              | point => point
              };
            } else {
              switch (point) {
              | 7856 => 7857
              | 7858 => 7859
              | point => point
              };
            };
          } else if (point < 7870) {
            if (point < 7864) {
              switch (point) {
              | 7860 => 7861
              | 7862 => 7863
              | point => point
              };
            } else if (point < 7866) {
              switch (point) {
              | 7864 => 7865
              | point => point
              };
            } else {
              switch (point) {
              | 7866 => 7867
              | 7868 => 7869
              | point => point
              };
            };
          } else if (point < 7876) {
            if (point < 7872) {
              switch (point) {
              | 7870 => 7871
              | point => point
              };
            } else {
              switch (point) {
              | 7872 => 7873
              | 7874 => 7875
              | point => point
              };
            };
          } else if (point < 7878) {
            switch (point) {
            | 7876 => 7877
            | point => point
            };
          } else {
            switch (point) {
            | 7878 => 7879
            | 7880 => 7881
            | point => point
            };
          };
        } else if (point < 7924) {
          if (point < 7902) {
            if (point < 7892) {
              if (point < 7886) {
                switch (point) {
                | 7882 => 7883
                | 7884 => 7885
                | point => point
                };
              } else if (point < 7888) {
                switch (point) {
                | 7886 => 7887
                | point => point
                };
              } else {
                switch (point) {
                | 7888 => 7889
                | 7890 => 7891
                | point => point
                };
              };
            } else if (point < 7896) {
              switch (point) {
              | 7892 => 7893
              | 7894 => 7895
              | point => point
              };
            } else if (point < 7898) {
              switch (point) {
              | 7896 => 7897
              | point => point
              };
            } else {
              switch (point) {
              | 7898 => 7899
              | 7900 => 7901
              | point => point
              };
            };
          } else if (point < 7912) {
            if (point < 7906) {
              switch (point) {
              | 7902 => 7903
              | 7904 => 7905
              | point => point
              };
            } else if (point < 7908) {
              switch (point) {
              | 7906 => 7907
              | point => point
              };
            } else {
              switch (point) {
              | 7908 => 7909
              | 7910 => 7911
              | point => point
              };
            };
          } else if (point < 7918) {
            if (point < 7914) {
              switch (point) {
              | 7912 => 7913
              | point => point
              };
            } else {
              switch (point) {
              | 7914 => 7915
              | 7916 => 7917
              | point => point
              };
            };
          } else if (point < 7920) {
            switch (point) {
            | 7918 => 7919
            | point => point
            };
          } else {
            switch (point) {
            | 7920 => 7921
            | 7922 => 7923
            | point => point
            };
          };
        } else if (point < 7949) {
          if (point < 7934) {
            if (point < 7928) {
              switch (point) {
              | 7924 => 7925
              | 7926 => 7927
              | point => point
              };
            } else if (point < 7930) {
              switch (point) {
              | 7928 => 7929
              | point => point
              };
            } else {
              switch (point) {
              | 7930 => 7931
              | 7932 => 7933
              | point => point
              };
            };
          } else if (point < 7946) {
            if (point < 7944) {
              switch (point) {
              | 7934 => 7935
              | point => point
              };
            } else {
              switch (point) {
              | 7944 => 7936
              | 7945 => 7937
              | point => point
              };
            };
          } else if (point < 7947) {
            switch (point) {
            | 7946 => 7938
            | point => point
            };
          } else {
            switch (point) {
            | 7947 => 7939
            | 7948 => 7940
            | point => point
            };
          };
        } else if (point < 7962) {
          if (point < 7951) {
            switch (point) {
            | 7949 => 7941
            | 7950 => 7942
            | point => point
            };
          } else if (point < 7960) {
            switch (point) {
            | 7951 => 7943
            | point => point
            };
          } else {
            switch (point) {
            | 7960 => 7952
            | 7961 => 7953
            | point => point
            };
          };
        } else if (point < 7965) {
          if (point < 7963) {
            switch (point) {
            | 7962 => 7954
            | point => point
            };
          } else {
            switch (point) {
            | 7963 => 7955
            | 7964 => 7956
            | point => point
            };
          };
        } else if (point < 7976) {
          switch (point) {
          | 7965 => 7957
          | point => point
          };
        } else {
          switch (point) {
          | 7976 => 7968
          | 7977 => 7969
          | point => point
          };
        };
      } else if (point < 8091) {
        if (point < 8027) {
          if (point < 7996) {
            if (point < 7983) {
              if (point < 7980) {
                switch (point) {
                | 7978 => 7970
                | 7979 => 7971
                | point => point
                };
              } else if (point < 7981) {
                switch (point) {
                | 7980 => 7972
                | point => point
                };
              } else {
                switch (point) {
                | 7981 => 7973
                | 7982 => 7974
                | point => point
                };
              };
            } else if (point < 7993) {
              switch (point) {
              | 7983 => 7975
              | 7992 => 7984
              | point => point
              };
            } else if (point < 7994) {
              switch (point) {
              | 7993 => 7985
              | point => point
              };
            } else {
              switch (point) {
              | 7994 => 7986
              | 7995 => 7987
              | point => point
              };
            };
          } else if (point < 8009) {
            if (point < 7998) {
              switch (point) {
              | 7996 => 7988
              | 7997 => 7989
              | point => point
              };
            } else if (point < 7999) {
              switch (point) {
              | 7998 => 7990
              | point => point
              };
            } else {
              switch (point) {
              | 7999 => 7991
              | 8008 => 8000
              | point => point
              };
            };
          } else if (point < 8012) {
            if (point < 8010) {
              switch (point) {
              | 8009 => 8001
              | point => point
              };
            } else {
              switch (point) {
              | 8010 => 8002
              | 8011 => 8003
              | point => point
              };
            };
          } else if (point < 8013) {
            switch (point) {
            | 8012 => 8004
            | point => point
            };
          } else {
            switch (point) {
            | 8013 => 8005
            | 8025 => 8017
            | point => point
            };
          };
        } else if (point < 8072) {
          if (point < 8042) {
            if (point < 8031) {
              switch (point) {
              | 8027 => 8019
              | 8029 => 8021
              | point => point
              };
            } else if (point < 8040) {
              switch (point) {
              | 8031 => 8023
              | point => point
              };
            } else {
              switch (point) {
              | 8040 => 8032
              | 8041 => 8033
              | point => point
              };
            };
          } else if (point < 8045) {
            if (point < 8043) {
              switch (point) {
              | 8042 => 8034
              | point => point
              };
            } else {
              switch (point) {
              | 8043 => 8035
              | 8044 => 8036
              | point => point
              };
            };
          } else if (point < 8046) {
            switch (point) {
            | 8045 => 8037
            | point => point
            };
          } else {
            switch (point) {
            | 8046 => 8038
            | 8047 => 8039
            | point => point
            };
          };
        } else if (point < 8077) {
          if (point < 8074) {
            switch (point) {
            | 8072 => 8064
            | 8073 => 8065
            | point => point
            };
          } else if (point < 8075) {
            switch (point) {
            | 8074 => 8066
            | point => point
            };
          } else {
            switch (point) {
            | 8075 => 8067
            | 8076 => 8068
            | point => point
            };
          };
        } else if (point < 8088) {
          if (point < 8078) {
            switch (point) {
            | 8077 => 8069
            | point => point
            };
          } else {
            switch (point) {
            | 8078 => 8070
            | 8079 => 8071
            | point => point
            };
          };
        } else if (point < 8089) {
          switch (point) {
          | 8088 => 8080
          | point => point
          };
        } else {
          switch (point) {
          | 8089 => 8081
          | 8090 => 8082
          | point => point
          };
        };
      } else if (point < 8140) {
        if (point < 8110) {
          if (point < 8104) {
            if (point < 8093) {
              switch (point) {
              | 8091 => 8083
              | 8092 => 8084
              | point => point
              };
            } else if (point < 8094) {
              switch (point) {
              | 8093 => 8085
              | point => point
              };
            } else {
              switch (point) {
              | 8094 => 8086
              | 8095 => 8087
              | point => point
              };
            };
          } else if (point < 8107) {
            if (point < 8105) {
              switch (point) {
              | 8104 => 8096
              | point => point
              };
            } else {
              switch (point) {
              | 8105 => 8097
              | 8106 => 8098
              | point => point
              };
            };
          } else if (point < 8108) {
            switch (point) {
            | 8107 => 8099
            | point => point
            };
          } else {
            switch (point) {
            | 8108 => 8100
            | 8109 => 8101
            | point => point
            };
          };
        } else if (point < 8123) {
          if (point < 8120) {
            switch (point) {
            | 8110 => 8102
            | 8111 => 8103
            | point => point
            };
          } else if (point < 8121) {
            switch (point) {
            | 8120 => 8112
            | point => point
            };
          } else {
            switch (point) {
            | 8121 => 8113
            | 8122 => 8048
            | point => point
            };
          };
        } else if (point < 8137) {
          if (point < 8124) {
            switch (point) {
            | 8123 => 8049
            | point => point
            };
          } else {
            switch (point) {
            | 8124 => 8115
            | 8136 => 8050
            | point => point
            };
          };
        } else if (point < 8138) {
          switch (point) {
          | 8137 => 8051
          | point => point
          };
        } else {
          switch (point) {
          | 8138 => 8052
          | 8139 => 8053
          | point => point
          };
        };
      } else if (point < 8185) {
        if (point < 8168) {
          if (point < 8153) {
            switch (point) {
            | 8140 => 8131
            | 8152 => 8144
            | point => point
            };
          } else if (point < 8154) {
            switch (point) {
            | 8153 => 8145
            | point => point
            };
          } else {
            switch (point) {
            | 8154 => 8054
            | 8155 => 8055
            | point => point
            };
          };
        } else if (point < 8171) {
          if (point < 8169) {
            switch (point) {
            | 8168 => 8160
            | point => point
            };
          } else {
            switch (point) {
            | 8169 => 8161
            | 8170 => 8058
            | point => point
            };
          };
        } else if (point < 8172) {
          switch (point) {
          | 8171 => 8059
          | point => point
          };
        } else {
          switch (point) {
          | 8172 => 8165
          | 8184 => 8056
          | point => point
          };
        };
      } else if (point < 8490) {
        if (point < 8187) {
          switch (point) {
          | 8185 => 8057
          | 8186 => 8060
          | point => point
          };
        } else if (point < 8188) {
          switch (point) {
          | 8187 => 8061
          | point => point
          };
        } else {
          switch (point) {
          | 8188 => 8179
          | 8486 => 969
          | point => point
          };
        };
      } else if (point < 8544) {
        if (point < 8491) {
          switch (point) {
          | 8490 => 107
          | point => point
          };
        } else {
          switch (point) {
          | 8491 => 229
          | 8498 => 8526
          | point => point
          };
        };
      } else if (point < 8545) {
        switch (point) {
        | 8544 => 8560
        | point => point
        };
      } else {
        switch (point) {
        | 8545 => 8561
        | 8546 => 8562
        | point => point
        };
      };
    } else if (point < 11360) {
      if (point < 11267) {
        if (point < 9405) {
          if (point < 8557) {
            if (point < 8552) {
              if (point < 8549) {
                switch (point) {
                | 8547 => 8563
                | 8548 => 8564
                | point => point
                };
              } else if (point < 8550) {
                switch (point) {
                | 8549 => 8565
                | point => point
                };
              } else {
                switch (point) {
                | 8550 => 8566
                | 8551 => 8567
                | point => point
                };
              };
            } else if (point < 8554) {
              switch (point) {
              | 8552 => 8568
              | 8553 => 8569
              | point => point
              };
            } else if (point < 8555) {
              switch (point) {
              | 8554 => 8570
              | point => point
              };
            } else {
              switch (point) {
              | 8555 => 8571
              | 8556 => 8572
              | point => point
              };
            };
          } else if (point < 9399) {
            if (point < 8559) {
              switch (point) {
              | 8557 => 8573
              | 8558 => 8574
              | point => point
              };
            } else if (point < 8579) {
              switch (point) {
              | 8559 => 8575
              | point => point
              };
            } else {
              switch (point) {
              | 8579 => 8580
              | 9398 => 9424
              | point => point
              };
            };
          } else if (point < 9402) {
            if (point < 9400) {
              switch (point) {
              | 9399 => 9425
              | point => point
              };
            } else {
              switch (point) {
              | 9400 => 9426
              | 9401 => 9427
              | point => point
              };
            };
          } else if (point < 9403) {
            switch (point) {
            | 9402 => 9428
            | point => point
            };
          } else {
            switch (point) {
            | 9403 => 9429
            | 9404 => 9430
            | point => point
            };
          };
        } else if (point < 9416) {
          if (point < 9410) {
            if (point < 9407) {
              switch (point) {
              | 9405 => 9431
              | 9406 => 9432
              | point => point
              };
            } else if (point < 9408) {
              switch (point) {
              | 9407 => 9433
              | point => point
              };
            } else {
              switch (point) {
              | 9408 => 9434
              | 9409 => 9435
              | point => point
              };
            };
          } else if (point < 9413) {
            if (point < 9411) {
              switch (point) {
              | 9410 => 9436
              | point => point
              };
            } else {
              switch (point) {
              | 9411 => 9437
              | 9412 => 9438
              | point => point
              };
            };
          } else if (point < 9414) {
            switch (point) {
            | 9413 => 9439
            | point => point
            };
          } else {
            switch (point) {
            | 9414 => 9440
            | 9415 => 9441
            | point => point
            };
          };
        } else if (point < 9421) {
          if (point < 9418) {
            switch (point) {
            | 9416 => 9442
            | 9417 => 9443
            | point => point
            };
          } else if (point < 9419) {
            switch (point) {
            | 9418 => 9444
            | point => point
            };
          } else {
            switch (point) {
            | 9419 => 9445
            | 9420 => 9446
            | point => point
            };
          };
        } else if (point < 11264) {
          if (point < 9422) {
            switch (point) {
            | 9421 => 9447
            | point => point
            };
          } else {
            switch (point) {
            | 9422 => 9448
            | 9423 => 9449
            | point => point
            };
          };
        } else if (point < 11265) {
          switch (point) {
          | 11264 => 11312
          | point => point
          };
        } else {
          switch (point) {
          | 11265 => 11313
          | 11266 => 11314
          | point => point
          };
        };
      } else if (point < 11289) {
        if (point < 11278) {
          if (point < 11272) {
            if (point < 11269) {
              switch (point) {
              | 11267 => 11315
              | 11268 => 11316
              | point => point
              };
            } else if (point < 11270) {
              switch (point) {
              | 11269 => 11317
              | point => point
              };
            } else {
              switch (point) {
              | 11270 => 11318
              | 11271 => 11319
              | point => point
              };
            };
          } else if (point < 11275) {
            if (point < 11273) {
              switch (point) {
              | 11272 => 11320
              | point => point
              };
            } else {
              switch (point) {
              | 11273 => 11321
              | 11274 => 11322
              | point => point
              };
            };
          } else if (point < 11276) {
            switch (point) {
            | 11275 => 11323
            | point => point
            };
          } else {
            switch (point) {
            | 11276 => 11324
            | 11277 => 11325
            | point => point
            };
          };
        } else if (point < 11283) {
          if (point < 11280) {
            switch (point) {
            | 11278 => 11326
            | 11279 => 11327
            | point => point
            };
          } else if (point < 11281) {
            switch (point) {
            | 11280 => 11328
            | point => point
            };
          } else {
            switch (point) {
            | 11281 => 11329
            | 11282 => 11330
            | point => point
            };
          };
        } else if (point < 11286) {
          if (point < 11284) {
            switch (point) {
            | 11283 => 11331
            | point => point
            };
          } else {
            switch (point) {
            | 11284 => 11332
            | 11285 => 11333
            | point => point
            };
          };
        } else if (point < 11287) {
          switch (point) {
          | 11286 => 11334
          | point => point
          };
        } else {
          switch (point) {
          | 11287 => 11335
          | 11288 => 11336
          | point => point
          };
        };
      } else if (point < 11300) {
        if (point < 11294) {
          if (point < 11291) {
            switch (point) {
            | 11289 => 11337
            | 11290 => 11338
            | point => point
            };
          } else if (point < 11292) {
            switch (point) {
            | 11291 => 11339
            | point => point
            };
          } else {
            switch (point) {
            | 11292 => 11340
            | 11293 => 11341
            | point => point
            };
          };
        } else if (point < 11297) {
          if (point < 11295) {
            switch (point) {
            | 11294 => 11342
            | point => point
            };
          } else {
            switch (point) {
            | 11295 => 11343
            | 11296 => 11344
            | point => point
            };
          };
        } else if (point < 11298) {
          switch (point) {
          | 11297 => 11345
          | point => point
          };
        } else {
          switch (point) {
          | 11298 => 11346
          | 11299 => 11347
          | point => point
          };
        };
      } else if (point < 11305) {
        if (point < 11302) {
          switch (point) {
          | 11300 => 11348
          | 11301 => 11349
          | point => point
          };
        } else if (point < 11303) {
          switch (point) {
          | 11302 => 11350
          | point => point
          };
        } else {
          switch (point) {
          | 11303 => 11351
          | 11304 => 11352
          | point => point
          };
        };
      } else if (point < 11308) {
        if (point < 11306) {
          switch (point) {
          | 11305 => 11353
          | point => point
          };
        } else {
          switch (point) {
          | 11306 => 11354
          | 11307 => 11355
          | point => point
          };
        };
      } else if (point < 11309) {
        switch (point) {
        | 11308 => 11356
        | point => point
        };
      } else {
        switch (point) {
        | 11309 => 11357
        | 11310 => 11358
        | point => point
        };
      };
    } else if (point < 11448) {
      if (point < 11404) {
        if (point < 11376) {
          if (point < 11369) {
            if (point < 11363) {
              switch (point) {
              | 11360 => 11361
              | 11362 => 619
              | point => point
              };
            } else if (point < 11364) {
              switch (point) {
              | 11363 => 7549
              | point => point
              };
            } else {
              switch (point) {
              | 11364 => 637
              | 11367 => 11368
              | point => point
              };
            };
          } else if (point < 11373) {
            switch (point) {
            | 11369 => 11370
            | 11371 => 11372
            | point => point
            };
          } else if (point < 11374) {
            switch (point) {
            | 11373 => 593
            | point => point
            };
          } else {
            switch (point) {
            | 11374 => 625
            | 11375 => 592
            | point => point
            };
          };
        } else if (point < 11392) {
          if (point < 11381) {
            switch (point) {
            | 11376 => 594
            | 11378 => 11379
            | point => point
            };
          } else if (point < 11390) {
            switch (point) {
            | 11381 => 11382
            | point => point
            };
          } else {
            switch (point) {
            | 11390 => 575
            | 11391 => 576
            | point => point
            };
          };
        } else if (point < 11398) {
          if (point < 11394) {
            switch (point) {
            | 11392 => 11393
            | point => point
            };
          } else {
            switch (point) {
            | 11394 => 11395
            | 11396 => 11397
            | point => point
            };
          };
        } else if (point < 11400) {
          switch (point) {
          | 11398 => 11399
          | point => point
          };
        } else {
          switch (point) {
          | 11400 => 11401
          | 11402 => 11403
          | point => point
          };
        };
      } else if (point < 11426) {
        if (point < 11414) {
          if (point < 11408) {
            switch (point) {
            | 11404 => 11405
            | 11406 => 11407
            | point => point
            };
          } else if (point < 11410) {
            switch (point) {
            | 11408 => 11409
            | point => point
            };
          } else {
            switch (point) {
            | 11410 => 11411
            | 11412 => 11413
            | point => point
            };
          };
        } else if (point < 11420) {
          if (point < 11416) {
            switch (point) {
            | 11414 => 11415
            | point => point
            };
          } else {
            switch (point) {
            | 11416 => 11417
            | 11418 => 11419
            | point => point
            };
          };
        } else if (point < 11422) {
          switch (point) {
          | 11420 => 11421
          | point => point
          };
        } else {
          switch (point) {
          | 11422 => 11423
          | 11424 => 11425
          | point => point
          };
        };
      } else if (point < 11436) {
        if (point < 11430) {
          switch (point) {
          | 11426 => 11427
          | 11428 => 11429
          | point => point
          };
        } else if (point < 11432) {
          switch (point) {
          | 11430 => 11431
          | point => point
          };
        } else {
          switch (point) {
          | 11432 => 11433
          | 11434 => 11435
          | point => point
          };
        };
      } else if (point < 11442) {
        if (point < 11438) {
          switch (point) {
          | 11436 => 11437
          | point => point
          };
        } else {
          switch (point) {
          | 11438 => 11439
          | 11440 => 11441
          | point => point
          };
        };
      } else if (point < 11444) {
        switch (point) {
        | 11442 => 11443
        | point => point
        };
      } else {
        switch (point) {
        | 11444 => 11445
        | 11446 => 11447
        | point => point
        };
      };
    } else if (point < 11499) {
      if (point < 11470) {
        if (point < 11458) {
          if (point < 11452) {
            switch (point) {
            | 11448 => 11449
            | 11450 => 11451
            | point => point
            };
          } else if (point < 11454) {
            switch (point) {
            | 11452 => 11453
            | point => point
            };
          } else {
            switch (point) {
            | 11454 => 11455
            | 11456 => 11457
            | point => point
            };
          };
        } else if (point < 11464) {
          if (point < 11460) {
            switch (point) {
            | 11458 => 11459
            | point => point
            };
          } else {
            switch (point) {
            | 11460 => 11461
            | 11462 => 11463
            | point => point
            };
          };
        } else if (point < 11466) {
          switch (point) {
          | 11464 => 11465
          | point => point
          };
        } else {
          switch (point) {
          | 11466 => 11467
          | 11468 => 11469
          | point => point
          };
        };
      } else if (point < 11480) {
        if (point < 11474) {
          switch (point) {
          | 11470 => 11471
          | 11472 => 11473
          | point => point
          };
        } else if (point < 11476) {
          switch (point) {
          | 11474 => 11475
          | point => point
          };
        } else {
          switch (point) {
          | 11476 => 11477
          | 11478 => 11479
          | point => point
          };
        };
      } else if (point < 11486) {
        if (point < 11482) {
          switch (point) {
          | 11480 => 11481
          | point => point
          };
        } else {
          switch (point) {
          | 11482 => 11483
          | 11484 => 11485
          | point => point
          };
        };
      } else if (point < 11488) {
        switch (point) {
        | 11486 => 11487
        | point => point
        };
      } else {
        switch (point) {
        | 11488 => 11489
        | 11490 => 11491
        | point => point
        };
      };
    } else if (point < 42576) {
      if (point < 42564) {
        if (point < 11506) {
          switch (point) {
          | 11499 => 11500
          | 11501 => 11502
          | point => point
          };
        } else if (point < 42560) {
          switch (point) {
          | 11506 => 11507
          | point => point
          };
        } else {
          switch (point) {
          | 42560 => 42561
          | 42562 => 42563
          | point => point
          };
        };
      } else if (point < 42570) {
        if (point < 42566) {
          switch (point) {
          | 42564 => 42565
          | point => point
          };
        } else {
          switch (point) {
          | 42566 => 42567
          | 42568 => 42569
          | point => point
          };
        };
      } else if (point < 42572) {
        switch (point) {
        | 42570 => 42571
        | point => point
        };
      } else {
        switch (point) {
        | 42572 => 42573
        | 42574 => 42575
        | point => point
        };
      };
    } else if (point < 42586) {
      if (point < 42580) {
        switch (point) {
        | 42576 => 42577
        | 42578 => 42579
        | point => point
        };
      } else if (point < 42582) {
        switch (point) {
        | 42580 => 42581
        | point => point
        };
      } else {
        switch (point) {
        | 42582 => 42583
        | 42584 => 42585
        | point => point
        };
      };
    } else if (point < 42592) {
      if (point < 42588) {
        switch (point) {
        | 42586 => 42587
        | point => point
        };
      } else {
        switch (point) {
        | 42588 => 42589
        | 42590 => 42591
        | point => point
        };
      };
    } else if (point < 42594) {
      switch (point) {
      | 42592 => 42593
      | point => point
      };
    } else {
      switch (point) {
      | 42594 => 42595
      | 42596 => 42597
      | point => point
      };
    };
  } else if (point < 66747) {
    if (point < 42932) {
      if (point < 42838) {
        if (point < 42792) {
          if (point < 42636) {
            if (point < 42626) {
              if (point < 42602) {
                switch (point) {
                | 42598 => 42599
                | 42600 => 42601
                | point => point
                };
              } else if (point < 42604) {
                switch (point) {
                | 42602 => 42603
                | point => point
                };
              } else {
                switch (point) {
                | 42604 => 42605
                | 42624 => 42625
                | point => point
                };
              };
            } else if (point < 42630) {
              switch (point) {
              | 42626 => 42627
              | 42628 => 42629
              | point => point
              };
            } else if (point < 42632) {
              switch (point) {
              | 42630 => 42631
              | point => point
              };
            } else {
              switch (point) {
              | 42632 => 42633
              | 42634 => 42635
              | point => point
              };
            };
          } else if (point < 42646) {
            if (point < 42640) {
              switch (point) {
              | 42636 => 42637
              | 42638 => 42639
              | point => point
              };
            } else if (point < 42642) {
              switch (point) {
              | 42640 => 42641
              | point => point
              };
            } else {
              switch (point) {
              | 42642 => 42643
              | 42644 => 42645
              | point => point
              };
            };
          } else if (point < 42786) {
            if (point < 42648) {
              switch (point) {
              | 42646 => 42647
              | point => point
              };
            } else {
              switch (point) {
              | 42648 => 42649
              | 42650 => 42651
              | point => point
              };
            };
          } else if (point < 42788) {
            switch (point) {
            | 42786 => 42787
            | point => point
            };
          } else {
            switch (point) {
            | 42788 => 42789
            | 42790 => 42791
            | point => point
            };
          };
        } else if (point < 42816) {
          if (point < 42804) {
            if (point < 42796) {
              switch (point) {
              | 42792 => 42793
              | 42794 => 42795
              | point => point
              };
            } else if (point < 42798) {
              switch (point) {
              | 42796 => 42797
              | point => point
              };
            } else {
              switch (point) {
              | 42798 => 42799
              | 42802 => 42803
              | point => point
              };
            };
          } else if (point < 42810) {
            if (point < 42806) {
              switch (point) {
              | 42804 => 42805
              | point => point
              };
            } else {
              switch (point) {
              | 42806 => 42807
              | 42808 => 42809
              | point => point
              };
            };
          } else if (point < 42812) {
            switch (point) {
            | 42810 => 42811
            | point => point
            };
          } else {
            switch (point) {
            | 42812 => 42813
            | 42814 => 42815
            | point => point
            };
          };
        } else if (point < 42826) {
          if (point < 42820) {
            switch (point) {
            | 42816 => 42817
            | 42818 => 42819
            | point => point
            };
          } else if (point < 42822) {
            switch (point) {
            | 42820 => 42821
            | point => point
            };
          } else {
            switch (point) {
            | 42822 => 42823
            | 42824 => 42825
            | point => point
            };
          };
        } else if (point < 42832) {
          if (point < 42828) {
            switch (point) {
            | 42826 => 42827
            | point => point
            };
          } else {
            switch (point) {
            | 42828 => 42829
            | 42830 => 42831
            | point => point
            };
          };
        } else if (point < 42834) {
          switch (point) {
          | 42832 => 42833
          | point => point
          };
        } else {
          switch (point) {
          | 42834 => 42835
          | 42836 => 42837
          | point => point
          };
        };
      } else if (point < 42893) {
        if (point < 42860) {
          if (point < 42848) {
            if (point < 42842) {
              switch (point) {
              | 42838 => 42839
              | 42840 => 42841
              | point => point
              };
            } else if (point < 42844) {
              switch (point) {
              | 42842 => 42843
              | point => point
              };
            } else {
              switch (point) {
              | 42844 => 42845
              | 42846 => 42847
              | point => point
              };
            };
          } else if (point < 42854) {
            if (point < 42850) {
              switch (point) {
              | 42848 => 42849
              | point => point
              };
            } else {
              switch (point) {
              | 42850 => 42851
              | 42852 => 42853
              | point => point
              };
            };
          } else if (point < 42856) {
            switch (point) {
            | 42854 => 42855
            | point => point
            };
          } else {
            switch (point) {
            | 42856 => 42857
            | 42858 => 42859
            | point => point
            };
          };
        } else if (point < 42878) {
          if (point < 42873) {
            switch (point) {
            | 42860 => 42861
            | 42862 => 42863
            | point => point
            };
          } else if (point < 42875) {
            switch (point) {
            | 42873 => 42874
            | point => point
            };
          } else {
            switch (point) {
            | 42875 => 42876
            | 42877 => 7545
            | point => point
            };
          };
        } else if (point < 42884) {
          if (point < 42880) {
            switch (point) {
            | 42878 => 42879
            | point => point
            };
          } else {
            switch (point) {
            | 42880 => 42881
            | 42882 => 42883
            | point => point
            };
          };
        } else if (point < 42886) {
          switch (point) {
          | 42884 => 42885
          | point => point
          };
        } else {
          switch (point) {
          | 42886 => 42887
          | 42891 => 42892
          | point => point
          };
        };
      } else if (point < 42918) {
        if (point < 42906) {
          if (point < 42898) {
            switch (point) {
            | 42893 => 613
            | 42896 => 42897
            | point => point
            };
          } else if (point < 42902) {
            switch (point) {
            | 42898 => 42899
            | point => point
            };
          } else {
            switch (point) {
            | 42902 => 42903
            | 42904 => 42905
            | point => point
            };
          };
        } else if (point < 42912) {
          if (point < 42908) {
            switch (point) {
            | 42906 => 42907
            | point => point
            };
          } else {
            switch (point) {
            | 42908 => 42909
            | 42910 => 42911
            | point => point
            };
          };
        } else if (point < 42914) {
          switch (point) {
          | 42912 => 42913
          | point => point
          };
        } else {
          switch (point) {
          | 42914 => 42915
          | 42916 => 42917
          | point => point
          };
        };
      } else if (point < 42925) {
        if (point < 42922) {
          switch (point) {
          | 42918 => 42919
          | 42920 => 42921
          | point => point
          };
        } else if (point < 42923) {
          switch (point) {
          | 42922 => 614
          | point => point
          };
        } else {
          switch (point) {
          | 42923 => 604
          | 42924 => 609
          | point => point
          };
        };
      } else if (point < 42929) {
        if (point < 42926) {
          switch (point) {
          | 42925 => 620
          | point => point
          };
        } else {
          switch (point) {
          | 42926 => 618
          | 42928 => 670
          | point => point
          };
        };
      } else if (point < 42930) {
        switch (point) {
        | 42929 => 647
        | point => point
        };
      } else {
        switch (point) {
        | 42930 => 669
        | 42931 => 43859
        | point => point
        };
      };
    } else if (point < 66567) {
      if (point < 65324) {
        if (point < 65313) {
          if (point < 42942) {
            if (point < 42936) {
              switch (point) {
              | 42932 => 42933
              | 42934 => 42935
              | point => point
              };
            } else if (point < 42938) {
              switch (point) {
              | 42936 => 42937
              | point => point
              };
            } else {
              switch (point) {
              | 42938 => 42939
              | 42940 => 42941
              | point => point
              };
            };
          } else if (point < 42948) {
            switch (point) {
            | 42942 => 42943
            | 42946 => 42947
            | point => point
            };
          } else if (point < 42949) {
            switch (point) {
            | 42948 => 42900
            | point => point
            };
          } else {
            switch (point) {
            | 42949 => 642
            | 42950 => 7566
            | point => point
            };
          };
        } else if (point < 65318) {
          if (point < 65315) {
            switch (point) {
            | 65313 => 65345
            | 65314 => 65346
            | point => point
            };
          } else if (point < 65316) {
            switch (point) {
            | 65315 => 65347
            | point => point
            };
          } else {
            switch (point) {
            | 65316 => 65348
            | 65317 => 65349
            | point => point
            };
          };
        } else if (point < 65321) {
          if (point < 65319) {
            switch (point) {
            | 65318 => 65350
            | point => point
            };
          } else {
            switch (point) {
            | 65319 => 65351
            | 65320 => 65352
            | point => point
            };
          };
        } else if (point < 65322) {
          switch (point) {
          | 65321 => 65353
          | point => point
          };
        } else {
          switch (point) {
          | 65322 => 65354
          | 65323 => 65355
          | point => point
          };
        };
      } else if (point < 65335) {
        if (point < 65329) {
          if (point < 65326) {
            switch (point) {
            | 65324 => 65356
            | 65325 => 65357
            | point => point
            };
          } else if (point < 65327) {
            switch (point) {
            | 65326 => 65358
            | point => point
            };
          } else {
            switch (point) {
            | 65327 => 65359
            | 65328 => 65360
            | point => point
            };
          };
        } else if (point < 65332) {
          if (point < 65330) {
            switch (point) {
            | 65329 => 65361
            | point => point
            };
          } else {
            switch (point) {
            | 65330 => 65362
            | 65331 => 65363
            | point => point
            };
          };
        } else if (point < 65333) {
          switch (point) {
          | 65332 => 65364
          | point => point
          };
        } else {
          switch (point) {
          | 65333 => 65365
          | 65334 => 65366
          | point => point
          };
        };
      } else if (point < 66561) {
        if (point < 65337) {
          switch (point) {
          | 65335 => 65367
          | 65336 => 65368
          | point => point
          };
        } else if (point < 65338) {
          switch (point) {
          | 65337 => 65369
          | point => point
          };
        } else {
          switch (point) {
          | 65338 => 65370
          | 66560 => 66600
          | point => point
          };
        };
      } else if (point < 66564) {
        if (point < 66562) {
          switch (point) {
          | 66561 => 66601
          | point => point
          };
        } else {
          switch (point) {
          | 66562 => 66602
          | 66563 => 66603
          | point => point
          };
        };
      } else if (point < 66565) {
        switch (point) {
        | 66564 => 66604
        | point => point
        };
      } else {
        switch (point) {
        | 66565 => 66605
        | 66566 => 66606
        | point => point
        };
      };
    } else if (point < 66589) {
      if (point < 66578) {
        if (point < 66572) {
          if (point < 66569) {
            switch (point) {
            | 66567 => 66607
            | 66568 => 66608
            | point => point
            };
          } else if (point < 66570) {
            switch (point) {
            | 66569 => 66609
            | point => point
            };
          } else {
            switch (point) {
            | 66570 => 66610
            | 66571 => 66611
            | point => point
            };
          };
        } else if (point < 66575) {
          if (point < 66573) {
            switch (point) {
            | 66572 => 66612
            | point => point
            };
          } else {
            switch (point) {
            | 66573 => 66613
            | 66574 => 66614
            | point => point
            };
          };
        } else if (point < 66576) {
          switch (point) {
          | 66575 => 66615
          | point => point
          };
        } else {
          switch (point) {
          | 66576 => 66616
          | 66577 => 66617
          | point => point
          };
        };
      } else if (point < 66583) {
        if (point < 66580) {
          switch (point) {
          | 66578 => 66618
          | 66579 => 66619
          | point => point
          };
        } else if (point < 66581) {
          switch (point) {
          | 66580 => 66620
          | point => point
          };
        } else {
          switch (point) {
          | 66581 => 66621
          | 66582 => 66622
          | point => point
          };
        };
      } else if (point < 66586) {
        if (point < 66584) {
          switch (point) {
          | 66583 => 66623
          | point => point
          };
        } else {
          switch (point) {
          | 66584 => 66624
          | 66585 => 66625
          | point => point
          };
        };
      } else if (point < 66587) {
        switch (point) {
        | 66586 => 66626
        | point => point
        };
      } else {
        switch (point) {
        | 66587 => 66627
        | 66588 => 66628
        | point => point
        };
      };
    } else if (point < 66736) {
      if (point < 66594) {
        if (point < 66591) {
          switch (point) {
          | 66589 => 66629
          | 66590 => 66630
          | point => point
          };
        } else if (point < 66592) {
          switch (point) {
          | 66591 => 66631
          | point => point
          };
        } else {
          switch (point) {
          | 66592 => 66632
          | 66593 => 66633
          | point => point
          };
        };
      } else if (point < 66597) {
        if (point < 66595) {
          switch (point) {
          | 66594 => 66634
          | point => point
          };
        } else {
          switch (point) {
          | 66595 => 66635
          | 66596 => 66636
          | point => point
          };
        };
      } else if (point < 66598) {
        switch (point) {
        | 66597 => 66637
        | point => point
        };
      } else {
        switch (point) {
        | 66598 => 66638
        | 66599 => 66639
        | point => point
        };
      };
    } else if (point < 66741) {
      if (point < 66738) {
        switch (point) {
        | 66736 => 66776
        | 66737 => 66777
        | point => point
        };
      } else if (point < 66739) {
        switch (point) {
        | 66738 => 66778
        | point => point
        };
      } else {
        switch (point) {
        | 66739 => 66779
        | 66740 => 66780
        | point => point
        };
      };
    } else if (point < 66744) {
      if (point < 66742) {
        switch (point) {
        | 66741 => 66781
        | point => point
        };
      } else {
        switch (point) {
        | 66742 => 66782
        | 66743 => 66783
        | point => point
        };
      };
    } else if (point < 66745) {
      switch (point) {
      | 66744 => 66784
      | point => point
      };
    } else {
      switch (point) {
      | 66745 => 66785
      | 66746 => 66786
      | point => point
      };
    };
  } else if (point < 71851) {
    if (point < 68754) {
      if (point < 66768) {
        if (point < 66757) {
          if (point < 66752) {
            if (point < 66749) {
              switch (point) {
              | 66747 => 66787
              | 66748 => 66788
              | point => point
              };
            } else if (point < 66750) {
              switch (point) {
              | 66749 => 66789
              | point => point
              };
            } else {
              switch (point) {
              | 66750 => 66790
              | 66751 => 66791
              | point => point
              };
            };
          } else if (point < 66754) {
            switch (point) {
            | 66752 => 66792
            | 66753 => 66793
            | point => point
            };
          } else if (point < 66755) {
            switch (point) {
            | 66754 => 66794
            | point => point
            };
          } else {
            switch (point) {
            | 66755 => 66795
            | 66756 => 66796
            | point => point
            };
          };
        } else if (point < 66762) {
          if (point < 66759) {
            switch (point) {
            | 66757 => 66797
            | 66758 => 66798
            | point => point
            };
          } else if (point < 66760) {
            switch (point) {
            | 66759 => 66799
            | point => point
            };
          } else {
            switch (point) {
            | 66760 => 66800
            | 66761 => 66801
            | point => point
            };
          };
        } else if (point < 66765) {
          if (point < 66763) {
            switch (point) {
            | 66762 => 66802
            | point => point
            };
          } else {
            switch (point) {
            | 66763 => 66803
            | 66764 => 66804
            | point => point
            };
          };
        } else if (point < 66766) {
          switch (point) {
          | 66765 => 66805
          | point => point
          };
        } else {
          switch (point) {
          | 66766 => 66806
          | 66767 => 66807
          | point => point
          };
        };
      } else if (point < 68743) {
        if (point < 68737) {
          if (point < 66770) {
            switch (point) {
            | 66768 => 66808
            | 66769 => 66809
            | point => point
            };
          } else if (point < 66771) {
            switch (point) {
            | 66770 => 66810
            | point => point
            };
          } else {
            switch (point) {
            | 66771 => 66811
            | 68736 => 68800
            | point => point
            };
          };
        } else if (point < 68740) {
          if (point < 68738) {
            switch (point) {
            | 68737 => 68801
            | point => point
            };
          } else {
            switch (point) {
            | 68738 => 68802
            | 68739 => 68803
            | point => point
            };
          };
        } else if (point < 68741) {
          switch (point) {
          | 68740 => 68804
          | point => point
          };
        } else {
          switch (point) {
          | 68741 => 68805
          | 68742 => 68806
          | point => point
          };
        };
      } else if (point < 68748) {
        if (point < 68745) {
          switch (point) {
          | 68743 => 68807
          | 68744 => 68808
          | point => point
          };
        } else if (point < 68746) {
          switch (point) {
          | 68745 => 68809
          | point => point
          };
        } else {
          switch (point) {
          | 68746 => 68810
          | 68747 => 68811
          | point => point
          };
        };
      } else if (point < 68751) {
        if (point < 68749) {
          switch (point) {
          | 68748 => 68812
          | point => point
          };
        } else {
          switch (point) {
          | 68749 => 68813
          | 68750 => 68814
          | point => point
          };
        };
      } else if (point < 68752) {
        switch (point) {
        | 68751 => 68815
        | point => point
        };
      } else {
        switch (point) {
        | 68752 => 68816
        | 68753 => 68817
        | point => point
        };
      };
    } else if (point < 68776) {
      if (point < 68765) {
        if (point < 68759) {
          if (point < 68756) {
            switch (point) {
            | 68754 => 68818
            | 68755 => 68819
            | point => point
            };
          } else if (point < 68757) {
            switch (point) {
            | 68756 => 68820
            | point => point
            };
          } else {
            switch (point) {
            | 68757 => 68821
            | 68758 => 68822
            | point => point
            };
          };
        } else if (point < 68762) {
          if (point < 68760) {
            switch (point) {
            | 68759 => 68823
            | point => point
            };
          } else {
            switch (point) {
            | 68760 => 68824
            | 68761 => 68825
            | point => point
            };
          };
        } else if (point < 68763) {
          switch (point) {
          | 68762 => 68826
          | point => point
          };
        } else {
          switch (point) {
          | 68763 => 68827
          | 68764 => 68828
          | point => point
          };
        };
      } else if (point < 68770) {
        if (point < 68767) {
          switch (point) {
          | 68765 => 68829
          | 68766 => 68830
          | point => point
          };
        } else if (point < 68768) {
          switch (point) {
          | 68767 => 68831
          | point => point
          };
        } else {
          switch (point) {
          | 68768 => 68832
          | 68769 => 68833
          | point => point
          };
        };
      } else if (point < 68773) {
        if (point < 68771) {
          switch (point) {
          | 68770 => 68834
          | point => point
          };
        } else {
          switch (point) {
          | 68771 => 68835
          | 68772 => 68836
          | point => point
          };
        };
      } else if (point < 68774) {
        switch (point) {
        | 68773 => 68837
        | point => point
        };
      } else {
        switch (point) {
        | 68774 => 68838
        | 68775 => 68839
        | point => point
        };
      };
    } else if (point < 71840) {
      if (point < 68781) {
        if (point < 68778) {
          switch (point) {
          | 68776 => 68840
          | 68777 => 68841
          | point => point
          };
        } else if (point < 68779) {
          switch (point) {
          | 68778 => 68842
          | point => point
          };
        } else {
          switch (point) {
          | 68779 => 68843
          | 68780 => 68844
          | point => point
          };
        };
      } else if (point < 68784) {
        if (point < 68782) {
          switch (point) {
          | 68781 => 68845
          | point => point
          };
        } else {
          switch (point) {
          | 68782 => 68846
          | 68783 => 68847
          | point => point
          };
        };
      } else if (point < 68785) {
        switch (point) {
        | 68784 => 68848
        | point => point
        };
      } else {
        switch (point) {
        | 68785 => 68849
        | 68786 => 68850
        | point => point
        };
      };
    } else if (point < 71845) {
      if (point < 71842) {
        switch (point) {
        | 71840 => 71872
        | 71841 => 71873
        | point => point
        };
      } else if (point < 71843) {
        switch (point) {
        | 71842 => 71874
        | point => point
        };
      } else {
        switch (point) {
        | 71843 => 71875
        | 71844 => 71876
        | point => point
        };
      };
    } else if (point < 71848) {
      if (point < 71846) {
        switch (point) {
        | 71845 => 71877
        | point => point
        };
      } else {
        switch (point) {
        | 71846 => 71878
        | 71847 => 71879
        | point => point
        };
      };
    } else if (point < 71849) {
      switch (point) {
      | 71848 => 71880
      | point => point
      };
    } else {
      switch (point) {
      | 71849 => 71881
      | 71850 => 71882
      | point => point
      };
    };
  } else if (point < 93782) {
    if (point < 93760) {
      if (point < 71861) {
        if (point < 71856) {
          if (point < 71853) {
            switch (point) {
            | 71851 => 71883
            | 71852 => 71884
            | point => point
            };
          } else if (point < 71854) {
            switch (point) {
            | 71853 => 71885
            | point => point
            };
          } else {
            switch (point) {
            | 71854 => 71886
            | 71855 => 71887
            | point => point
            };
          };
        } else if (point < 71858) {
          switch (point) {
          | 71856 => 71888
          | 71857 => 71889
          | point => point
          };
        } else if (point < 71859) {
          switch (point) {
          | 71858 => 71890
          | point => point
          };
        } else {
          switch (point) {
          | 71859 => 71891
          | 71860 => 71892
          | point => point
          };
        };
      } else if (point < 71866) {
        if (point < 71863) {
          switch (point) {
          | 71861 => 71893
          | 71862 => 71894
          | point => point
          };
        } else if (point < 71864) {
          switch (point) {
          | 71863 => 71895
          | point => point
          };
        } else {
          switch (point) {
          | 71864 => 71896
          | 71865 => 71897
          | point => point
          };
        };
      } else if (point < 71869) {
        if (point < 71867) {
          switch (point) {
          | 71866 => 71898
          | point => point
          };
        } else {
          switch (point) {
          | 71867 => 71899
          | 71868 => 71900
          | point => point
          };
        };
      } else if (point < 71870) {
        switch (point) {
        | 71869 => 71901
        | point => point
        };
      } else {
        switch (point) {
        | 71870 => 71902
        | 71871 => 71903
        | point => point
        };
      };
    } else if (point < 93771) {
      if (point < 93765) {
        if (point < 93762) {
          switch (point) {
          | 93760 => 93792
          | 93761 => 93793
          | point => point
          };
        } else if (point < 93763) {
          switch (point) {
          | 93762 => 93794
          | point => point
          };
        } else {
          switch (point) {
          | 93763 => 93795
          | 93764 => 93796
          | point => point
          };
        };
      } else if (point < 93768) {
        if (point < 93766) {
          switch (point) {
          | 93765 => 93797
          | point => point
          };
        } else {
          switch (point) {
          | 93766 => 93798
          | 93767 => 93799
          | point => point
          };
        };
      } else if (point < 93769) {
        switch (point) {
        | 93768 => 93800
        | point => point
        };
      } else {
        switch (point) {
        | 93769 => 93801
        | 93770 => 93802
        | point => point
        };
      };
    } else if (point < 93776) {
      if (point < 93773) {
        switch (point) {
        | 93771 => 93803
        | 93772 => 93804
        | point => point
        };
      } else if (point < 93774) {
        switch (point) {
        | 93773 => 93805
        | point => point
        };
      } else {
        switch (point) {
        | 93774 => 93806
        | 93775 => 93807
        | point => point
        };
      };
    } else if (point < 93779) {
      if (point < 93777) {
        switch (point) {
        | 93776 => 93808
        | point => point
        };
      } else {
        switch (point) {
        | 93777 => 93809
        | 93778 => 93810
        | point => point
        };
      };
    } else if (point < 93780) {
      switch (point) {
      | 93779 => 93811
      | point => point
      };
    } else {
      switch (point) {
      | 93780 => 93812
      | 93781 => 93813
      | point => point
      };
    };
  } else if (point < 125196) {
    if (point < 125185) {
      if (point < 93787) {
        if (point < 93784) {
          switch (point) {
          | 93782 => 93814
          | 93783 => 93815
          | point => point
          };
        } else if (point < 93785) {
          switch (point) {
          | 93784 => 93816
          | point => point
          };
        } else {
          switch (point) {
          | 93785 => 93817
          | 93786 => 93818
          | point => point
          };
        };
      } else if (point < 93790) {
        if (point < 93788) {
          switch (point) {
          | 93787 => 93819
          | point => point
          };
        } else {
          switch (point) {
          | 93788 => 93820
          | 93789 => 93821
          | point => point
          };
        };
      } else if (point < 93791) {
        switch (point) {
        | 93790 => 93822
        | point => point
        };
      } else {
        switch (point) {
        | 93791 => 93823
        | 125184 => 125218
        | point => point
        };
      };
    } else if (point < 125190) {
      if (point < 125187) {
        switch (point) {
        | 125185 => 125219
        | 125186 => 125220
        | point => point
        };
      } else if (point < 125188) {
        switch (point) {
        | 125187 => 125221
        | point => point
        };
      } else {
        switch (point) {
        | 125188 => 125222
        | 125189 => 125223
        | point => point
        };
      };
    } else if (point < 125193) {
      if (point < 125191) {
        switch (point) {
        | 125190 => 125224
        | point => point
        };
      } else {
        switch (point) {
        | 125191 => 125225
        | 125192 => 125226
        | point => point
        };
      };
    } else if (point < 125194) {
      switch (point) {
      | 125193 => 125227
      | point => point
      };
    } else {
      switch (point) {
      | 125194 => 125228
      | 125195 => 125229
      | point => point
      };
    };
  } else if (point < 125207) {
    if (point < 125201) {
      if (point < 125198) {
        switch (point) {
        | 125196 => 125230
        | 125197 => 125231
        | point => point
        };
      } else if (point < 125199) {
        switch (point) {
        | 125198 => 125232
        | point => point
        };
      } else {
        switch (point) {
        | 125199 => 125233
        | 125200 => 125234
        | point => point
        };
      };
    } else if (point < 125204) {
      if (point < 125202) {
        switch (point) {
        | 125201 => 125235
        | point => point
        };
      } else {
        switch (point) {
        | 125202 => 125236
        | 125203 => 125237
        | point => point
        };
      };
    } else if (point < 125205) {
      switch (point) {
      | 125204 => 125238
      | point => point
      };
    } else {
      switch (point) {
      | 125205 => 125239
      | 125206 => 125240
      | point => point
      };
    };
  } else if (point < 125212) {
    if (point < 125209) {
      switch (point) {
      | 125207 => 125241
      | 125208 => 125242
      | point => point
      };
    } else if (point < 125210) {
      switch (point) {
      | 125209 => 125243
      | point => point
      };
    } else {
      switch (point) {
      | 125210 => 125244
      | 125211 => 125245
      | point => point
      };
    };
  } else if (point < 125215) {
    if (point < 125213) {
      switch (point) {
      | 125212 => 125246
      | point => point
      };
    } else {
      switch (point) {
      | 125213 => 125247
      | 125214 => 125248
      | point => point
      };
    };
  } else if (point < 125216) {
    switch (point) {
    | 125215 => 125249
    | point => point
    };
  } else {
    switch (point) {
    | 125216 => 125250
    | 125217 => 125251
    | point => point
    };
  };

let replaceTrailers = (codePointList) => {
  let rec aux = (newList, codePointList) => {
    switch codePointList {
      | [x] => aux([x |> lastLetterMap] @ newList, [])
      | [x, space_, ...tail] when space_ == space => aux([space, x |> lastLetterMap] @ newList, tail)
      | [x, ...tail] => aux([x] @ newList, tail)
      | [] => List.rev(newList)
    }
  }
  and aux2 = (newList, codePointList) => {
    switch codePointList {
      | [x, ...tail] => aux([x] @ newList, tail)
      | [] => List.rev(newList)
      }
  };
  aux2([], codePointList);
};

let toLower = (codePointList: list(PrecisUtils.codePoint)) => {
  codePointList |> List.map(lowerCaseMap) |> replaceTrailers;
};
