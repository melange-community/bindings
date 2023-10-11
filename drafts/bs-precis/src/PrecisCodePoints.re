/** Precis/CodePoints.re
 ** Copyright 2019 NineFX Inc.
 ** Justin Baum
 ** Based on Samuel Nichol's Original Implementation in Smeagol
 ** 13 May 2019
 */

type precisTypes =
  | CONTEXTO
  | CONTEXTJ
  | PVALID
  | UNASSIGNED
  | FREEPVAL
  | DISALLOWED;

let fromCodePoint = (point: PrecisUtils.codePoint) =>
  if (point < 42999) {
    if (point < 3808) {
      if (point < 2693) {
        if (point < 1653) {
          if (point < 931) {
            if (point < 697) {
              if (point < 248) {
                if (point < 174) {
                  if (point < 127) {
                    if (point < 32) {
                      switch (point) {
                      | point when point >= 0 && point <= 31 => DISALLOWED
                      | _point => DISALLOWED
                      };
                    } else {
                      switch (point) {
                      | point when point >= 32 && point <= 32 => FREEPVAL
                      | point when point >= 33 && point <= 126 => PVALID
                      | _point => DISALLOWED
                      };
                    };
                  } else if (point < 160) {
                    switch (point) {
                    | point when point >= 127 && point <= 159 => DISALLOWED
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 160 && point <= 172 => FREEPVAL
                    | point when point >= 173 && point <= 173 => DISALLOWED
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 192) {
                  if (point < 183) {
                    switch (point) {
                    | point when point >= 174 && point <= 182 => FREEPVAL
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 183 && point <= 183 => CONTEXTO
                    | point when point >= 184 && point <= 191 => FREEPVAL
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 216) {
                  switch (point) {
                  | point when point >= 192 && point <= 214 => PVALID
                  | point when point >= 215 && point <= 215 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 216 && point <= 246 => PVALID
                  | point when point >= 247 && point <= 247 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 383) {
                if (point < 319) {
                  if (point < 306) {
                    switch (point) {
                    | point when point >= 248 && point <= 305 => PVALID
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 306 && point <= 307 => FREEPVAL
                    | point when point >= 308 && point <= 318 => PVALID
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 329) {
                  switch (point) {
                  | point when point >= 319 && point <= 320 => FREEPVAL
                  | point when point >= 321 && point <= 328 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 329 && point <= 329 => FREEPVAL
                  | point when point >= 330 && point <= 382 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 461) {
                if (point < 384) {
                  switch (point) {
                  | point when point >= 383 && point <= 383 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 384 && point <= 451 => PVALID
                  | point when point >= 452 && point <= 460 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 500) {
                switch (point) {
                | point when point >= 461 && point <= 496 => PVALID
                | point when point >= 497 && point <= 499 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 500 && point <= 687 => PVALID
                | point when point >= 688 && point <= 696 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 890) {
              if (point < 751) {
                if (point < 722) {
                  if (point < 706) {
                    switch (point) {
                    | point when point >= 697 && point <= 705 => PVALID
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 706 && point <= 709 => FREEPVAL
                    | point when point >= 710 && point <= 721 => PVALID
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 749) {
                  switch (point) {
                  | point when point >= 722 && point <= 747 => FREEPVAL
                  | point when point >= 748 && point <= 748 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 749 && point <= 749 => FREEPVAL
                  | point when point >= 750 && point <= 750 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 848) {
                if (point < 768) {
                  switch (point) {
                  | point when point >= 751 && point <= 767 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 768 && point <= 846 => PVALID
                  | point when point >= 847 && point <= 847 => DISALLOWED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 886) {
                switch (point) {
                | point when point >= 848 && point <= 884 => PVALID
                | point when point >= 885 && point <= 885 => CONTEXTO
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 886 && point <= 887 => PVALID
                | point when point >= 888 && point <= 889 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 903) {
              if (point < 895) {
                if (point < 891) {
                  switch (point) {
                  | point when point >= 890 && point <= 890 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 891 && point <= 893 => PVALID
                  | point when point >= 894 && point <= 894 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 900) {
                switch (point) {
                | point when point >= 895 && point <= 895 => PVALID
                | point when point >= 896 && point <= 899 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 900 && point <= 901 => FREEPVAL
                | point when point >= 902 && point <= 902 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 908) {
              if (point < 904) {
                switch (point) {
                | point when point >= 903 && point <= 903 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 904 && point <= 906 => PVALID
                | point when point >= 907 && point <= 907 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 910) {
              switch (point) {
              | point when point >= 908 && point <= 908 => PVALID
              | point when point >= 909 && point <= 909 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 910 && point <= 929 => PVALID
              | point when point >= 930 && point <= 930 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 1425) {
            if (point < 1160) {
              if (point < 1011) {
                if (point < 981) {
                  if (point < 976) {
                    switch (point) {
                    | point when point >= 931 && point <= 975 => PVALID
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 976 && point <= 978 => FREEPVAL
                    | point when point >= 979 && point <= 980 => PVALID
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 983) {
                  switch (point) {
                  | point when point >= 981 && point <= 982 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 983 && point <= 1007 => PVALID
                  | point when point >= 1008 && point <= 1010 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1017) {
                if (point < 1012) {
                  switch (point) {
                  | point when point >= 1011 && point <= 1011 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1012 && point <= 1014 => FREEPVAL
                  | point when point >= 1015 && point <= 1016 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1154) {
                switch (point) {
                | point when point >= 1017 && point <= 1017 => FREEPVAL
                | point when point >= 1018 && point <= 1153 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1154 && point <= 1154 => FREEPVAL
                | point when point >= 1155 && point <= 1159 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 1376) {
              if (point < 1329) {
                if (point < 1162) {
                  switch (point) {
                  | point when point >= 1160 && point <= 1161 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1162 && point <= 1327 => PVALID
                  | point when point >= 1328 && point <= 1328 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1369) {
                switch (point) {
                | point when point >= 1329 && point <= 1366 => PVALID
                | point when point >= 1367 && point <= 1368 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1369 && point <= 1369 => PVALID
                | point when point >= 1370 && point <= 1375 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 1417) {
              if (point < 1415) {
                switch (point) {
                | point when point >= 1376 && point <= 1414 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1415 && point <= 1415 => FREEPVAL
                | point when point >= 1416 && point <= 1416 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 1421) {
              switch (point) {
              | point when point >= 1417 && point <= 1418 => FREEPVAL
              | point when point >= 1419 && point <= 1420 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 1421 && point <= 1423 => FREEPVAL
              | point when point >= 1424 && point <= 1424 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 1525) {
            if (point < 1478) {
              if (point < 1472) {
                if (point < 1470) {
                  switch (point) {
                  | point when point >= 1425 && point <= 1469 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1470 && point <= 1470 => FREEPVAL
                  | point when point >= 1471 && point <= 1471 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1475) {
                switch (point) {
                | point when point >= 1472 && point <= 1472 => FREEPVAL
                | point when point >= 1473 && point <= 1474 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1475 && point <= 1475 => FREEPVAL
                | point when point >= 1476 && point <= 1477 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 1488) {
              if (point < 1479) {
                switch (point) {
                | point when point >= 1478 && point <= 1478 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1479 && point <= 1479 => PVALID
                | point when point >= 1480 && point <= 1487 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 1519) {
              switch (point) {
              | point when point >= 1488 && point <= 1514 => PVALID
              | point when point >= 1515 && point <= 1518 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 1519 && point <= 1522 => PVALID
              | point when point >= 1523 && point <= 1524 => CONTEXTO
              | _point => DISALLOWED
              };
            };
          } else if (point < 1566) {
            if (point < 1552) {
              if (point < 1536) {
                switch (point) {
                | point when point >= 1525 && point <= 1535 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1536 && point <= 1541 => DISALLOWED
                | point when point >= 1542 && point <= 1551 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 1564) {
              switch (point) {
              | point when point >= 1552 && point <= 1562 => PVALID
              | point when point >= 1563 && point <= 1563 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 1564 && point <= 1564 => DISALLOWED
              | point when point >= 1565 && point <= 1565 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 1601) {
            if (point < 1568) {
              switch (point) {
              | point when point >= 1566 && point <= 1567 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 1568 && point <= 1599 => PVALID
              | point when point >= 1600 && point <= 1600 => DISALLOWED
              | _point => DISALLOWED
              };
            };
          } else if (point < 1642) {
            switch (point) {
            | point when point >= 1601 && point <= 1631 => PVALID
            | point when point >= 1632 && point <= 1641 => CONTEXTO
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 1642 && point <= 1645 => FREEPVAL
            | point when point >= 1646 && point <= 1652 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 2483) {
          if (point < 2111) {
            if (point < 1807) {
              if (point < 1759) {
                if (point < 1749) {
                  if (point < 1657) {
                    switch (point) {
                    | point when point >= 1653 && point <= 1656 => FREEPVAL
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 1657 && point <= 1747 => PVALID
                    | point when point >= 1748 && point <= 1748 => FREEPVAL
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 1757) {
                  switch (point) {
                  | point when point >= 1749 && point <= 1756 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1757 && point <= 1757 => DISALLOWED
                  | point when point >= 1758 && point <= 1758 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1776) {
                if (point < 1769) {
                  switch (point) {
                  | point when point >= 1759 && point <= 1768 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1769 && point <= 1769 => FREEPVAL
                  | point when point >= 1770 && point <= 1775 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1792) {
                switch (point) {
                | point when point >= 1776 && point <= 1785 => CONTEXTO
                | point when point >= 1786 && point <= 1791 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1792 && point <= 1805 => FREEPVAL
                | point when point >= 1806 && point <= 1806 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2042) {
              if (point < 1869) {
                if (point < 1808) {
                  switch (point) {
                  | point when point >= 1807 && point <= 1807 => DISALLOWED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 1808 && point <= 1866 => PVALID
                  | point when point >= 1867 && point <= 1868 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 1984) {
                switch (point) {
                | point when point >= 1869 && point <= 1969 => PVALID
                | point when point >= 1970 && point <= 1983 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 1984 && point <= 2037 => PVALID
                | point when point >= 2038 && point <= 2041 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 2046) {
              if (point < 2043) {
                switch (point) {
                | point when point >= 2042 && point <= 2042 => DISALLOWED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2043 && point <= 2044 => UNASSIGNED
                | point when point >= 2045 && point <= 2045 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2094) {
              switch (point) {
              | point when point >= 2046 && point <= 2047 => FREEPVAL
              | point when point >= 2048 && point <= 2093 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2094 && point <= 2095 => UNASSIGNED
              | point when point >= 2096 && point <= 2110 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 2404) {
            if (point < 2208) {
              if (point < 2142) {
                if (point < 2112) {
                  switch (point) {
                  | point when point >= 2111 && point <= 2111 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2112 && point <= 2139 => PVALID
                  | point when point >= 2140 && point <= 2141 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2144) {
                switch (point) {
                | point when point >= 2142 && point <= 2142 => FREEPVAL
                | point when point >= 2143 && point <= 2143 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2144 && point <= 2154 => PVALID
                | point when point >= 2155 && point <= 2207 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2238) {
              if (point < 2229) {
                switch (point) {
                | point when point >= 2208 && point <= 2228 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2229 && point <= 2229 => UNASSIGNED
                | point when point >= 2230 && point <= 2237 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2274) {
              switch (point) {
              | point when point >= 2238 && point <= 2258 => UNASSIGNED
              | point when point >= 2259 && point <= 2273 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2274 && point <= 2274 => DISALLOWED
              | point when point >= 2275 && point <= 2403 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2447) {
            if (point < 2417) {
              if (point < 2406) {
                switch (point) {
                | point when point >= 2404 && point <= 2405 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2406 && point <= 2415 => PVALID
                | point when point >= 2416 && point <= 2416 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 2437) {
              switch (point) {
              | point when point >= 2417 && point <= 2435 => PVALID
              | point when point >= 2436 && point <= 2436 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2437 && point <= 2444 => PVALID
              | point when point >= 2445 && point <= 2446 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2473) {
            if (point < 2449) {
              switch (point) {
              | point when point >= 2447 && point <= 2448 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2449 && point <= 2450 => UNASSIGNED
              | point when point >= 2451 && point <= 2472 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2481) {
            switch (point) {
            | point when point >= 2473 && point <= 2473 => UNASSIGNED
            | point when point >= 2474 && point <= 2480 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2481 && point <= 2481 => UNASSIGNED
            | point when point >= 2482 && point <= 2482 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 2601) {
          if (point < 2532) {
            if (point < 2507) {
              if (point < 2492) {
                if (point < 2486) {
                  switch (point) {
                  | point when point >= 2483 && point <= 2485 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2486 && point <= 2489 => PVALID
                  | point when point >= 2490 && point <= 2491 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2503) {
                switch (point) {
                | point when point >= 2492 && point <= 2500 => PVALID
                | point when point >= 2501 && point <= 2502 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2503 && point <= 2504 => PVALID
                | point when point >= 2505 && point <= 2506 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2520) {
              if (point < 2511) {
                switch (point) {
                | point when point >= 2507 && point <= 2510 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2511 && point <= 2518 => UNASSIGNED
                | point when point >= 2519 && point <= 2519 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2526) {
              switch (point) {
              | point when point >= 2520 && point <= 2523 => UNASSIGNED
              | point when point >= 2524 && point <= 2525 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2526 && point <= 2526 => UNASSIGNED
              | point when point >= 2527 && point <= 2531 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2561) {
            if (point < 2556) {
              if (point < 2534) {
                switch (point) {
                | point when point >= 2532 && point <= 2533 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2534 && point <= 2545 => PVALID
                | point when point >= 2546 && point <= 2555 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 2558) {
              switch (point) {
              | point when point >= 2556 && point <= 2556 => PVALID
              | point when point >= 2557 && point <= 2557 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2558 && point <= 2558 => PVALID
              | point when point >= 2559 && point <= 2560 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2571) {
            if (point < 2564) {
              switch (point) {
              | point when point >= 2561 && point <= 2563 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2564 && point <= 2564 => UNASSIGNED
              | point when point >= 2565 && point <= 2570 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2577) {
            switch (point) {
            | point when point >= 2571 && point <= 2574 => UNASSIGNED
            | point when point >= 2575 && point <= 2576 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2577 && point <= 2578 => UNASSIGNED
            | point when point >= 2579 && point <= 2600 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 2633) {
          if (point < 2616) {
            if (point < 2610) {
              if (point < 2602) {
                switch (point) {
                | point when point >= 2601 && point <= 2601 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2602 && point <= 2608 => PVALID
                | point when point >= 2609 && point <= 2609 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2613) {
              switch (point) {
              | point when point >= 2610 && point <= 2611 => PVALID
              | point when point >= 2612 && point <= 2612 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2613 && point <= 2614 => PVALID
              | point when point >= 2615 && point <= 2615 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2621) {
            if (point < 2618) {
              switch (point) {
              | point when point >= 2616 && point <= 2617 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2618 && point <= 2619 => UNASSIGNED
              | point when point >= 2620 && point <= 2620 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2627) {
            switch (point) {
            | point when point >= 2621 && point <= 2621 => UNASSIGNED
            | point when point >= 2622 && point <= 2626 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2627 && point <= 2630 => UNASSIGNED
            | point when point >= 2631 && point <= 2632 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 2654) {
          if (point < 2641) {
            if (point < 2635) {
              switch (point) {
              | point when point >= 2633 && point <= 2634 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2635 && point <= 2637 => PVALID
              | point when point >= 2638 && point <= 2640 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2649) {
            switch (point) {
            | point when point >= 2641 && point <= 2641 => PVALID
            | point when point >= 2642 && point <= 2648 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2649 && point <= 2652 => PVALID
            | point when point >= 2653 && point <= 2653 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 2678) {
          if (point < 2655) {
            switch (point) {
            | point when point >= 2654 && point <= 2654 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2655 && point <= 2661 => UNASSIGNED
            | point when point >= 2662 && point <= 2677 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 2689) {
          switch (point) {
          | point when point >= 2678 && point <= 2678 => FREEPVAL
          | point when point >= 2679 && point <= 2688 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 2689 && point <= 2691 => PVALID
          | point when point >= 2692 && point <= 2692 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 3174) {
        if (point < 2929) {
          if (point < 2817) {
            if (point < 2758) {
              if (point < 2730) {
                if (point < 2706) {
                  if (point < 2702) {
                    switch (point) {
                    | point when point >= 2693 && point <= 2701 => PVALID
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 2702 && point <= 2702 => UNASSIGNED
                    | point when point >= 2703 && point <= 2705 => PVALID
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 2707) {
                  switch (point) {
                  | point when point >= 2706 && point <= 2706 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2707 && point <= 2728 => PVALID
                  | point when point >= 2729 && point <= 2729 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2740) {
                if (point < 2737) {
                  switch (point) {
                  | point when point >= 2730 && point <= 2736 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2737 && point <= 2737 => UNASSIGNED
                  | point when point >= 2738 && point <= 2739 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2746) {
                switch (point) {
                | point when point >= 2740 && point <= 2740 => UNASSIGNED
                | point when point >= 2741 && point <= 2745 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2746 && point <= 2747 => UNASSIGNED
                | point when point >= 2748 && point <= 2757 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2784) {
              if (point < 2763) {
                if (point < 2759) {
                  switch (point) {
                  | point when point >= 2758 && point <= 2758 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2759 && point <= 2761 => PVALID
                  | point when point >= 2762 && point <= 2762 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2768) {
                switch (point) {
                | point when point >= 2763 && point <= 2765 => PVALID
                | point when point >= 2766 && point <= 2767 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2768 && point <= 2768 => PVALID
                | point when point >= 2769 && point <= 2783 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2800) {
              if (point < 2788) {
                switch (point) {
                | point when point >= 2784 && point <= 2787 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2788 && point <= 2789 => UNASSIGNED
                | point when point >= 2790 && point <= 2799 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2809) {
              switch (point) {
              | point when point >= 2800 && point <= 2801 => FREEPVAL
              | point when point >= 2802 && point <= 2808 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2809 && point <= 2815 => PVALID
              | point when point >= 2816 && point <= 2816 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2876) {
            if (point < 2857) {
              if (point < 2829) {
                if (point < 2820) {
                  switch (point) {
                  | point when point >= 2817 && point <= 2819 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2820 && point <= 2820 => UNASSIGNED
                  | point when point >= 2821 && point <= 2828 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2833) {
                switch (point) {
                | point when point >= 2829 && point <= 2830 => UNASSIGNED
                | point when point >= 2831 && point <= 2832 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2833 && point <= 2834 => UNASSIGNED
                | point when point >= 2835 && point <= 2856 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2866) {
              if (point < 2858) {
                switch (point) {
                | point when point >= 2857 && point <= 2857 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2858 && point <= 2864 => PVALID
                | point when point >= 2865 && point <= 2865 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2869) {
              switch (point) {
              | point when point >= 2866 && point <= 2867 => PVALID
              | point when point >= 2868 && point <= 2868 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2869 && point <= 2873 => PVALID
              | point when point >= 2874 && point <= 2875 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2904) {
            if (point < 2889) {
              if (point < 2885) {
                switch (point) {
                | point when point >= 2876 && point <= 2884 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2885 && point <= 2886 => UNASSIGNED
                | point when point >= 2887 && point <= 2888 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2894) {
              switch (point) {
              | point when point >= 2889 && point <= 2890 => UNASSIGNED
              | point when point >= 2891 && point <= 2893 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2894 && point <= 2901 => UNASSIGNED
              | point when point >= 2902 && point <= 2903 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2911) {
            if (point < 2908) {
              switch (point) {
              | point when point >= 2904 && point <= 2907 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2908 && point <= 2909 => PVALID
              | point when point >= 2910 && point <= 2910 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 2918) {
            switch (point) {
            | point when point >= 2911 && point <= 2915 => PVALID
            | point when point >= 2916 && point <= 2917 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 2918 && point <= 2927 => PVALID
            | point when point >= 2928 && point <= 2928 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 3022) {
          if (point < 2973) {
            if (point < 2958) {
              if (point < 2946) {
                if (point < 2930) {
                  switch (point) {
                  | point when point >= 2929 && point <= 2929 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 2930 && point <= 2935 => FREEPVAL
                  | point when point >= 2936 && point <= 2945 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 2949) {
                switch (point) {
                | point when point >= 2946 && point <= 2947 => PVALID
                | point when point >= 2948 && point <= 2948 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2949 && point <= 2954 => PVALID
                | point when point >= 2955 && point <= 2957 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2966) {
              if (point < 2961) {
                switch (point) {
                | point when point >= 2958 && point <= 2960 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2961 && point <= 2961 => UNASSIGNED
                | point when point >= 2962 && point <= 2965 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 2971) {
              switch (point) {
              | point when point >= 2966 && point <= 2968 => UNASSIGNED
              | point when point >= 2969 && point <= 2970 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2971 && point <= 2971 => UNASSIGNED
              | point when point >= 2972 && point <= 2972 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 2990) {
            if (point < 2979) {
              if (point < 2974) {
                switch (point) {
                | point when point >= 2973 && point <= 2973 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 2974 && point <= 2975 => PVALID
                | point when point >= 2976 && point <= 2978 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 2984) {
              switch (point) {
              | point when point >= 2979 && point <= 2980 => PVALID
              | point when point >= 2981 && point <= 2983 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 2984 && point <= 2986 => PVALID
              | point when point >= 2987 && point <= 2989 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3011) {
            if (point < 3002) {
              switch (point) {
              | point when point >= 2990 && point <= 3001 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3002 && point <= 3005 => UNASSIGNED
              | point when point >= 3006 && point <= 3010 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 3017) {
            switch (point) {
            | point when point >= 3011 && point <= 3013 => UNASSIGNED
            | point when point >= 3014 && point <= 3016 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3017 && point <= 3017 => UNASSIGNED
            | point when point >= 3018 && point <= 3021 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3114) {
          if (point < 3067) {
            if (point < 3031) {
              if (point < 3024) {
                switch (point) {
                | point when point >= 3022 && point <= 3023 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3024 && point <= 3024 => PVALID
                | point when point >= 3025 && point <= 3030 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 3046) {
              switch (point) {
              | point when point >= 3031 && point <= 3031 => PVALID
              | point when point >= 3032 && point <= 3045 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3046 && point <= 3055 => PVALID
              | point when point >= 3056 && point <= 3066 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 3086) {
            if (point < 3072) {
              switch (point) {
              | point when point >= 3067 && point <= 3071 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3072 && point <= 3084 => PVALID
              | point when point >= 3085 && point <= 3085 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3090) {
            switch (point) {
            | point when point >= 3086 && point <= 3088 => PVALID
            | point when point >= 3089 && point <= 3089 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3090 && point <= 3112 => PVALID
            | point when point >= 3113 && point <= 3113 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3150) {
          if (point < 3141) {
            if (point < 3130) {
              switch (point) {
              | point when point >= 3114 && point <= 3129 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3130 && point <= 3132 => UNASSIGNED
              | point when point >= 3133 && point <= 3140 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 3145) {
            switch (point) {
            | point when point >= 3141 && point <= 3141 => UNASSIGNED
            | point when point >= 3142 && point <= 3144 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3145 && point <= 3145 => UNASSIGNED
            | point when point >= 3146 && point <= 3149 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3160) {
          if (point < 3157) {
            switch (point) {
            | point when point >= 3150 && point <= 3156 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3157 && point <= 3158 => PVALID
            | point when point >= 3159 && point <= 3159 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3168) {
          switch (point) {
          | point when point >= 3160 && point <= 3162 => PVALID
          | point when point >= 3163 && point <= 3167 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3168 && point <= 3171 => PVALID
          | point when point >= 3172 && point <= 3173 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 3479) {
        if (point < 3302) {
          if (point < 3253) {
            if (point < 3213) {
              if (point < 3200) {
                if (point < 3184) {
                  switch (point) {
                  | point when point >= 3174 && point <= 3183 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 3184 && point <= 3190 => UNASSIGNED
                  | point when point >= 3191 && point <= 3199 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 3204) {
                switch (point) {
                | point when point >= 3200 && point <= 3203 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3204 && point <= 3204 => FREEPVAL
                | point when point >= 3205 && point <= 3212 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 3218) {
              if (point < 3214) {
                switch (point) {
                | point when point >= 3213 && point <= 3213 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3214 && point <= 3216 => PVALID
                | point when point >= 3217 && point <= 3217 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 3242) {
              switch (point) {
              | point when point >= 3218 && point <= 3240 => PVALID
              | point when point >= 3241 && point <= 3241 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3242 && point <= 3251 => PVALID
              | point when point >= 3252 && point <= 3252 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3278) {
            if (point < 3269) {
              if (point < 3258) {
                switch (point) {
                | point when point >= 3253 && point <= 3257 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3258 && point <= 3259 => UNASSIGNED
                | point when point >= 3260 && point <= 3268 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 3273) {
              switch (point) {
              | point when point >= 3269 && point <= 3269 => UNASSIGNED
              | point when point >= 3270 && point <= 3272 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3273 && point <= 3273 => UNASSIGNED
              | point when point >= 3274 && point <= 3277 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 3294) {
            if (point < 3285) {
              switch (point) {
              | point when point >= 3278 && point <= 3284 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3285 && point <= 3286 => PVALID
              | point when point >= 3287 && point <= 3293 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3296) {
            switch (point) {
            | point when point >= 3294 && point <= 3294 => PVALID
            | point when point >= 3295 && point <= 3295 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3296 && point <= 3299 => PVALID
            | point when point >= 3300 && point <= 3301 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3402) {
          if (point < 3341) {
            if (point < 3315) {
              if (point < 3312) {
                switch (point) {
                | point when point >= 3302 && point <= 3311 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3312 && point <= 3312 => UNASSIGNED
                | point when point >= 3313 && point <= 3314 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 3332) {
              switch (point) {
              | point when point >= 3315 && point <= 3327 => UNASSIGNED
              | point when point >= 3328 && point <= 3331 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3332 && point <= 3332 => UNASSIGNED
              | point when point >= 3333 && point <= 3340 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 3346) {
            if (point < 3342) {
              switch (point) {
              | point when point >= 3341 && point <= 3341 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3342 && point <= 3344 => PVALID
              | point when point >= 3345 && point <= 3345 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3398) {
            switch (point) {
            | point when point >= 3346 && point <= 3396 => PVALID
            | point when point >= 3397 && point <= 3397 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3398 && point <= 3400 => PVALID
            | point when point >= 3401 && point <= 3401 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3430) {
          if (point < 3412) {
            if (point < 3407) {
              switch (point) {
              | point when point >= 3402 && point <= 3406 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3407 && point <= 3407 => FREEPVAL
              | point when point >= 3408 && point <= 3411 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3423) {
            switch (point) {
            | point when point >= 3412 && point <= 3415 => PVALID
            | point when point >= 3416 && point <= 3422 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3423 && point <= 3427 => PVALID
            | point when point >= 3428 && point <= 3429 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3456) {
          if (point < 3440) {
            switch (point) {
            | point when point >= 3430 && point <= 3439 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3440 && point <= 3449 => FREEPVAL
            | point when point >= 3450 && point <= 3455 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3460) {
          switch (point) {
          | point when point >= 3456 && point <= 3457 => UNASSIGNED
          | point when point >= 3458 && point <= 3459 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3460 && point <= 3460 => UNASSIGNED
          | point when point >= 3461 && point <= 3478 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 3663) {
        if (point < 3543) {
          if (point < 3520) {
            if (point < 3507) {
              if (point < 3482) {
                switch (point) {
                | point when point >= 3479 && point <= 3481 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3482 && point <= 3505 => PVALID
                | point when point >= 3506 && point <= 3506 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 3517) {
              switch (point) {
              | point when point >= 3507 && point <= 3515 => PVALID
              | point when point >= 3516 && point <= 3516 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3517 && point <= 3517 => PVALID
              | point when point >= 3518 && point <= 3519 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3531) {
            if (point < 3527) {
              switch (point) {
              | point when point >= 3520 && point <= 3526 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3527 && point <= 3529 => UNASSIGNED
              | point when point >= 3530 && point <= 3530 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 3541) {
            switch (point) {
            | point when point >= 3531 && point <= 3534 => UNASSIGNED
            | point when point >= 3535 && point <= 3540 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3541 && point <= 3541 => UNASSIGNED
            | point when point >= 3542 && point <= 3542 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3573) {
          if (point < 3558) {
            if (point < 3544) {
              switch (point) {
              | point when point >= 3543 && point <= 3543 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3544 && point <= 3551 => PVALID
              | point when point >= 3552 && point <= 3557 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 3570) {
            switch (point) {
            | point when point >= 3558 && point <= 3567 => PVALID
            | point when point >= 3568 && point <= 3569 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3570 && point <= 3571 => PVALID
            | point when point >= 3572 && point <= 3572 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 3636) {
          if (point < 3585) {
            switch (point) {
            | point when point >= 3573 && point <= 3584 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3585 && point <= 3634 => PVALID
            | point when point >= 3635 && point <= 3635 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 3647) {
          switch (point) {
          | point when point >= 3636 && point <= 3642 => PVALID
          | point when point >= 3643 && point <= 3646 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3647 && point <= 3647 => FREEPVAL
          | point when point >= 3648 && point <= 3662 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 3751) {
        if (point < 3717) {
          if (point < 3676) {
            if (point < 3664) {
              switch (point) {
              | point when point >= 3663 && point <= 3663 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3664 && point <= 3673 => PVALID
              | point when point >= 3674 && point <= 3675 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 3715) {
            switch (point) {
            | point when point >= 3676 && point <= 3712 => UNASSIGNED
            | point when point >= 3713 && point <= 3714 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3715 && point <= 3715 => UNASSIGNED
            | point when point >= 3716 && point <= 3716 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3724) {
          if (point < 3718) {
            switch (point) {
            | point when point >= 3717 && point <= 3717 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3718 && point <= 3722 => PVALID
            | point when point >= 3723 && point <= 3723 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 3749) {
          switch (point) {
          | point when point >= 3724 && point <= 3747 => PVALID
          | point when point >= 3748 && point <= 3748 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3749 && point <= 3749 => PVALID
          | point when point >= 3750 && point <= 3750 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 3783) {
        if (point < 3774) {
          if (point < 3763) {
            switch (point) {
            | point when point >= 3751 && point <= 3762 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 3763 && point <= 3763 => FREEPVAL
            | point when point >= 3764 && point <= 3773 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 3781) {
          switch (point) {
          | point when point >= 3774 && point <= 3775 => UNASSIGNED
          | point when point >= 3776 && point <= 3780 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3781 && point <= 3781 => UNASSIGNED
          | point when point >= 3782 && point <= 3782 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 3792) {
        if (point < 3784) {
          switch (point) {
          | point when point >= 3783 && point <= 3783 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 3784 && point <= 3789 => PVALID
          | point when point >= 3790 && point <= 3791 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 3804) {
        switch (point) {
        | point when point >= 3792 && point <= 3801 => PVALID
        | point when point >= 3802 && point <= 3803 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 3804 && point <= 3805 => FREEPVAL
        | point when point >= 3806 && point <= 3807 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 7674) {
      if (point < 5952) {
        if (point < 4696) {
          if (point < 3993) {
            if (point < 3897) {
              if (point < 3866) {
                if (point < 3851) {
                  if (point < 3840) {
                    switch (point) {
                    | point when point >= 3808 && point <= 3839 => UNASSIGNED
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 3840 && point <= 3840 => PVALID
                    | point when point >= 3841 && point <= 3850 => FREEPVAL
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 3852) {
                  switch (point) {
                  | point when point >= 3851 && point <= 3851 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 3852 && point <= 3863 => FREEPVAL
                  | point when point >= 3864 && point <= 3865 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 3893) {
                if (point < 3872) {
                  switch (point) {
                  | point when point >= 3866 && point <= 3871 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 3872 && point <= 3881 => PVALID
                  | point when point >= 3882 && point <= 3892 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 3895) {
                switch (point) {
                | point when point >= 3893 && point <= 3893 => PVALID
                | point when point >= 3894 && point <= 3894 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3895 && point <= 3895 => PVALID
                | point when point >= 3896 && point <= 3896 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 3959) {
              if (point < 3912) {
                if (point < 3898) {
                  switch (point) {
                  | point when point >= 3897 && point <= 3897 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 3898 && point <= 3901 => FREEPVAL
                  | point when point >= 3902 && point <= 3911 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 3949) {
                switch (point) {
                | point when point >= 3912 && point <= 3912 => UNASSIGNED
                | point when point >= 3913 && point <= 3948 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3949 && point <= 3952 => UNASSIGNED
                | point when point >= 3953 && point <= 3958 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 3962) {
              if (point < 3960) {
                switch (point) {
                | point when point >= 3959 && point <= 3959 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 3960 && point <= 3960 => PVALID
                | point when point >= 3961 && point <= 3961 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 3974) {
              switch (point) {
              | point when point >= 3962 && point <= 3972 => PVALID
              | point when point >= 3973 && point <= 3973 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 3974 && point <= 3991 => PVALID
              | point when point >= 3992 && point <= 3992 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 4295) {
            if (point < 4059) {
              if (point < 4038) {
                if (point < 4029) {
                  switch (point) {
                  | point when point >= 3993 && point <= 4028 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 4029 && point <= 4029 => UNASSIGNED
                  | point when point >= 4030 && point <= 4037 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 4045) {
                switch (point) {
                | point when point >= 4038 && point <= 4038 => PVALID
                | point when point >= 4039 && point <= 4044 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4045 && point <= 4045 => UNASSIGNED
                | point when point >= 4046 && point <= 4058 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 4176) {
              if (point < 4096) {
                switch (point) {
                | point when point >= 4059 && point <= 4095 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4096 && point <= 4169 => PVALID
                | point when point >= 4170 && point <= 4175 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 4256) {
              switch (point) {
              | point when point >= 4176 && point <= 4253 => PVALID
              | point when point >= 4254 && point <= 4255 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4256 && point <= 4293 => PVALID
              | point when point >= 4294 && point <= 4294 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 4352) {
            if (point < 4302) {
              if (point < 4296) {
                switch (point) {
                | point when point >= 4295 && point <= 4295 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4296 && point <= 4300 => UNASSIGNED
                | point when point >= 4301 && point <= 4301 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 4347) {
              switch (point) {
              | point when point >= 4302 && point <= 4303 => UNASSIGNED
              | point when point >= 4304 && point <= 4346 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4347 && point <= 4348 => FREEPVAL
              | point when point >= 4349 && point <= 4351 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 4682) {
            if (point < 4608) {
              switch (point) {
              | point when point >= 4352 && point <= 4607 => DISALLOWED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4608 && point <= 4680 => PVALID
              | point when point >= 4681 && point <= 4681 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 4688) {
            switch (point) {
            | point when point >= 4682 && point <= 4685 => PVALID
            | point when point >= 4686 && point <= 4687 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 4688 && point <= 4694 => PVALID
            | point when point >= 4695 && point <= 4695 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 4960) {
          if (point < 4799) {
            if (point < 4746) {
              if (point < 4702) {
                if (point < 4697) {
                  switch (point) {
                  | point when point >= 4696 && point <= 4696 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 4697 && point <= 4697 => UNASSIGNED
                  | point when point >= 4698 && point <= 4701 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 4704) {
                switch (point) {
                | point when point >= 4702 && point <= 4703 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4704 && point <= 4744 => PVALID
                | point when point >= 4745 && point <= 4745 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 4785) {
              if (point < 4750) {
                switch (point) {
                | point when point >= 4746 && point <= 4749 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4750 && point <= 4751 => UNASSIGNED
                | point when point >= 4752 && point <= 4784 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 4790) {
              switch (point) {
              | point when point >= 4785 && point <= 4785 => UNASSIGNED
              | point when point >= 4786 && point <= 4789 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4790 && point <= 4791 => UNASSIGNED
              | point when point >= 4792 && point <= 4798 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 4824) {
            if (point < 4802) {
              if (point < 4800) {
                switch (point) {
                | point when point >= 4799 && point <= 4799 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4800 && point <= 4800 => PVALID
                | point when point >= 4801 && point <= 4801 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 4808) {
              switch (point) {
              | point when point >= 4802 && point <= 4805 => PVALID
              | point when point >= 4806 && point <= 4807 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4808 && point <= 4822 => PVALID
              | point when point >= 4823 && point <= 4823 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 4886) {
            if (point < 4881) {
              switch (point) {
              | point when point >= 4824 && point <= 4880 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 4881 && point <= 4881 => UNASSIGNED
              | point when point >= 4882 && point <= 4885 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 4955) {
            switch (point) {
            | point when point >= 4886 && point <= 4887 => UNASSIGNED
            | point when point >= 4888 && point <= 4954 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 4955 && point <= 4956 => UNASSIGNED
            | point when point >= 4957 && point <= 4959 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 5761) {
          if (point < 5112) {
            if (point < 5008) {
              if (point < 4989) {
                switch (point) {
                | point when point >= 4960 && point <= 4988 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 4989 && point <= 4991 => UNASSIGNED
                | point when point >= 4992 && point <= 5007 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 5024) {
              switch (point) {
              | point when point >= 5008 && point <= 5017 => FREEPVAL
              | point when point >= 5018 && point <= 5023 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 5024 && point <= 5109 => PVALID
              | point when point >= 5110 && point <= 5111 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 5121) {
            if (point < 5118) {
              switch (point) {
              | point when point >= 5112 && point <= 5117 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 5118 && point <= 5119 => UNASSIGNED
              | point when point >= 5120 && point <= 5120 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 5743) {
            switch (point) {
            | point when point >= 5121 && point <= 5740 => PVALID
            | point when point >= 5741 && point <= 5742 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 5743 && point <= 5759 => PVALID
            | point when point >= 5760 && point <= 5760 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 5888) {
          if (point < 5792) {
            if (point < 5787) {
              switch (point) {
              | point when point >= 5761 && point <= 5786 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 5787 && point <= 5788 => FREEPVAL
              | point when point >= 5789 && point <= 5791 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 5873) {
            switch (point) {
            | point when point >= 5792 && point <= 5866 => PVALID
            | point when point >= 5867 && point <= 5872 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 5873 && point <= 5880 => PVALID
            | point when point >= 5881 && point <= 5887 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 5909) {
          if (point < 5901) {
            switch (point) {
            | point when point >= 5888 && point <= 5900 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 5901 && point <= 5901 => UNASSIGNED
            | point when point >= 5902 && point <= 5908 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 5941) {
          switch (point) {
          | point when point >= 5909 && point <= 5919 => UNASSIGNED
          | point when point >= 5920 && point <= 5940 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 5941 && point <= 5942 => FREEPVAL
          | point when point >= 5943 && point <= 5951 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 6688) {
        if (point < 6272) {
          if (point < 6104) {
            if (point < 6002) {
              if (point < 5997) {
                if (point < 5972) {
                  switch (point) {
                  | point when point >= 5952 && point <= 5971 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 5972 && point <= 5983 => UNASSIGNED
                  | point when point >= 5984 && point <= 5996 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 5998) {
                switch (point) {
                | point when point >= 5997 && point <= 5997 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 5998 && point <= 6000 => PVALID
                | point when point >= 6001 && point <= 6001 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 6068) {
              if (point < 6004) {
                switch (point) {
                | point when point >= 6002 && point <= 6003 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 6004 && point <= 6015 => UNASSIGNED
                | point when point >= 6016 && point <= 6067 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 6100) {
              switch (point) {
              | point when point >= 6068 && point <= 6069 => DISALLOWED
              | point when point >= 6070 && point <= 6099 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6100 && point <= 6102 => FREEPVAL
              | point when point >= 6103 && point <= 6103 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 6144) {
            if (point < 6112) {
              if (point < 6108) {
                switch (point) {
                | point when point >= 6104 && point <= 6107 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 6108 && point <= 6109 => PVALID
                | point when point >= 6110 && point <= 6111 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 6128) {
              switch (point) {
              | point when point >= 6112 && point <= 6121 => PVALID
              | point when point >= 6122 && point <= 6127 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6128 && point <= 6137 => FREEPVAL
              | point when point >= 6138 && point <= 6143 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 6160) {
            if (point < 6155) {
              switch (point) {
              | point when point >= 6144 && point <= 6154 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6155 && point <= 6158 => DISALLOWED
              | point when point >= 6159 && point <= 6159 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 6176) {
            switch (point) {
            | point when point >= 6160 && point <= 6169 => PVALID
            | point when point >= 6170 && point <= 6175 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 6176 && point <= 6264 => PVALID
            | point when point >= 6265 && point <= 6271 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 6510) {
          if (point < 6444) {
            if (point < 6390) {
              if (point < 6315) {
                switch (point) {
                | point when point >= 6272 && point <= 6314 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 6315 && point <= 6319 => UNASSIGNED
                | point when point >= 6320 && point <= 6389 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 6431) {
              switch (point) {
              | point when point >= 6390 && point <= 6399 => UNASSIGNED
              | point when point >= 6400 && point <= 6430 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6431 && point <= 6431 => UNASSIGNED
              | point when point >= 6432 && point <= 6443 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 6464) {
            if (point < 6448) {
              switch (point) {
              | point when point >= 6444 && point <= 6447 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6448 && point <= 6459 => PVALID
              | point when point >= 6460 && point <= 6463 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 6468) {
            switch (point) {
            | point when point >= 6464 && point <= 6464 => FREEPVAL
            | point when point >= 6465 && point <= 6467 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 6468 && point <= 6469 => FREEPVAL
            | point when point >= 6470 && point <= 6509 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 6608) {
          if (point < 6528) {
            if (point < 6512) {
              switch (point) {
              | point when point >= 6510 && point <= 6511 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6512 && point <= 6516 => PVALID
              | point when point >= 6517 && point <= 6527 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 6576) {
            switch (point) {
            | point when point >= 6528 && point <= 6571 => PVALID
            | point when point >= 6572 && point <= 6575 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 6576 && point <= 6601 => PVALID
            | point when point >= 6602 && point <= 6607 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 6622) {
          if (point < 6618) {
            switch (point) {
            | point when point >= 6608 && point <= 6617 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 6618 && point <= 6618 => FREEPVAL
            | point when point >= 6619 && point <= 6621 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 6684) {
          switch (point) {
          | point when point >= 6622 && point <= 6655 => FREEPVAL
          | point when point >= 6656 && point <= 6683 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 6684 && point <= 6685 => UNASSIGNED
          | point when point >= 6686 && point <= 6687 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 7232) {
        if (point < 6847) {
          if (point < 6810) {
            if (point < 6781) {
              if (point < 6751) {
                switch (point) {
                | point when point >= 6688 && point <= 6750 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 6751 && point <= 6751 => UNASSIGNED
                | point when point >= 6752 && point <= 6780 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 6794) {
              switch (point) {
              | point when point >= 6781 && point <= 6782 => UNASSIGNED
              | point when point >= 6783 && point <= 6793 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6794 && point <= 6799 => UNASSIGNED
              | point when point >= 6800 && point <= 6809 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 6824) {
            if (point < 6816) {
              switch (point) {
              | point when point >= 6810 && point <= 6815 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6816 && point <= 6822 => FREEPVAL
              | point when point >= 6823 && point <= 6823 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 6832) {
            switch (point) {
            | point when point >= 6824 && point <= 6829 => FREEPVAL
            | point when point >= 6830 && point <= 6831 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 6832 && point <= 6845 => PVALID
            | point when point >= 6846 && point <= 6846 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 7037) {
          if (point < 6992) {
            if (point < 6912) {
              switch (point) {
              | point when point >= 6847 && point <= 6911 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 6912 && point <= 6987 => PVALID
              | point when point >= 6988 && point <= 6991 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 7019) {
            switch (point) {
            | point when point >= 6992 && point <= 7001 => PVALID
            | point when point >= 7002 && point <= 7018 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 7019 && point <= 7027 => PVALID
            | point when point >= 7028 && point <= 7036 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 7164) {
          if (point < 7040) {
            switch (point) {
            | point when point >= 7037 && point <= 7039 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 7040 && point <= 7155 => PVALID
            | point when point >= 7156 && point <= 7163 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 7224) {
          switch (point) {
          | point when point >= 7164 && point <= 7167 => FREEPVAL
          | point when point >= 7168 && point <= 7223 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 7224 && point <= 7226 => UNASSIGNED
          | point when point >= 7227 && point <= 7231 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 7419) {
        if (point < 7355) {
          if (point < 7294) {
            if (point < 7242) {
              switch (point) {
              | point when point >= 7232 && point <= 7241 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 7242 && point <= 7244 => UNASSIGNED
              | point when point >= 7245 && point <= 7293 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 7305) {
            switch (point) {
            | point when point >= 7294 && point <= 7295 => FREEPVAL
            | point when point >= 7296 && point <= 7304 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 7305 && point <= 7311 => UNASSIGNED
            | point when point >= 7312 && point <= 7354 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 7368) {
          if (point < 7357) {
            switch (point) {
            | point when point >= 7355 && point <= 7356 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 7357 && point <= 7359 => PVALID
            | point when point >= 7360 && point <= 7367 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 7379) {
          switch (point) {
          | point when point >= 7368 && point <= 7375 => UNASSIGNED
          | point when point >= 7376 && point <= 7378 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 7379 && point <= 7379 => FREEPVAL
          | point when point >= 7380 && point <= 7418 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 7502) {
        if (point < 7471) {
          if (point < 7424) {
            switch (point) {
            | point when point >= 7419 && point <= 7423 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 7424 && point <= 7467 => PVALID
            | point when point >= 7468 && point <= 7470 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 7483) {
          switch (point) {
          | point when point >= 7471 && point <= 7471 => PVALID
          | point when point >= 7472 && point <= 7482 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 7483 && point <= 7483 => PVALID
          | point when point >= 7484 && point <= 7501 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 7544) {
        if (point < 7503) {
          switch (point) {
          | point when point >= 7502 && point <= 7502 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 7503 && point <= 7530 => FREEPVAL
          | point when point >= 7531 && point <= 7543 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 7579) {
        switch (point) {
        | point when point >= 7544 && point <= 7544 => FREEPVAL
        | point when point >= 7545 && point <= 7578 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 7579 && point <= 7615 => FREEPVAL
        | point when point >= 7616 && point <= 7673 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 11566) {
      if (point < 8232) {
        if (point < 8112) {
          if (point < 8025) {
            if (point < 7966) {
              if (point < 7835) {
                if (point < 7675) {
                  switch (point) {
                  | point when point >= 7674 && point <= 7674 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 7675 && point <= 7833 => PVALID
                  | point when point >= 7834 && point <= 7834 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 7958) {
                switch (point) {
                | point when point >= 7835 && point <= 7957 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 7958 && point <= 7959 => UNASSIGNED
                | point when point >= 7960 && point <= 7965 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 8008) {
              if (point < 7968) {
                switch (point) {
                | point when point >= 7966 && point <= 7967 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 7968 && point <= 8005 => PVALID
                | point when point >= 8006 && point <= 8007 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 8016) {
              switch (point) {
              | point when point >= 8008 && point <= 8013 => PVALID
              | point when point >= 8014 && point <= 8015 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8016 && point <= 8023 => PVALID
              | point when point >= 8024 && point <= 8024 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 8062) {
            if (point < 8028) {
              if (point < 8026) {
                switch (point) {
                | point when point >= 8025 && point <= 8025 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 8026 && point <= 8026 => UNASSIGNED
                | point when point >= 8027 && point <= 8027 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 8030) {
              switch (point) {
              | point when point >= 8028 && point <= 8028 => UNASSIGNED
              | point when point >= 8029 && point <= 8029 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8030 && point <= 8030 => UNASSIGNED
              | point when point >= 8031 && point <= 8061 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 8080) {
            if (point < 8064) {
              switch (point) {
              | point when point >= 8062 && point <= 8063 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8064 && point <= 8071 => PVALID
              | point when point >= 8072 && point <= 8079 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 8096) {
            switch (point) {
            | point when point >= 8080 && point <= 8087 => PVALID
            | point when point >= 8088 && point <= 8095 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8096 && point <= 8103 => PVALID
            | point when point >= 8104 && point <= 8111 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 8157) {
          if (point < 8133) {
            if (point < 8124) {
              if (point < 8117) {
                switch (point) {
                | point when point >= 8112 && point <= 8116 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 8117 && point <= 8117 => UNASSIGNED
                | point when point >= 8118 && point <= 8123 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 8127) {
              switch (point) {
              | point when point >= 8124 && point <= 8125 => FREEPVAL
              | point when point >= 8126 && point <= 8126 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8127 && point <= 8129 => FREEPVAL
              | point when point >= 8130 && point <= 8132 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 8144) {
            if (point < 8134) {
              switch (point) {
              | point when point >= 8133 && point <= 8133 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8134 && point <= 8139 => PVALID
              | point when point >= 8140 && point <= 8143 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 8150) {
            switch (point) {
            | point when point >= 8144 && point <= 8147 => PVALID
            | point when point >= 8148 && point <= 8149 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8150 && point <= 8155 => PVALID
            | point when point >= 8156 && point <= 8156 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 8188) {
          if (point < 8176) {
            if (point < 8160) {
              switch (point) {
              | point when point >= 8157 && point <= 8159 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8160 && point <= 8172 => PVALID
              | point when point >= 8173 && point <= 8175 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 8181) {
            switch (point) {
            | point when point >= 8176 && point <= 8177 => UNASSIGNED
            | point when point >= 8178 && point <= 8180 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8181 && point <= 8181 => UNASSIGNED
            | point when point >= 8182 && point <= 8187 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 8203) {
          if (point < 8191) {
            switch (point) {
            | point when point >= 8188 && point <= 8190 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8191 && point <= 8191 => UNASSIGNED
            | point when point >= 8192 && point <= 8202 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 8206) {
          switch (point) {
          | point when point >= 8203 && point <= 8203 => DISALLOWED
          | point when point >= 8204 && point <= 8205 => CONTEXTJ
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 8206 && point <= 8207 => DISALLOWED
          | point when point >= 8208 && point <= 8231 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 8579) {
        if (point < 8413) {
          if (point < 8308) {
            if (point < 8293) {
              if (point < 8239) {
                switch (point) {
                | point when point >= 8232 && point <= 8238 => DISALLOWED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 8239 && point <= 8287 => FREEPVAL
                | point when point >= 8288 && point <= 8292 => DISALLOWED
                | _point => DISALLOWED
                };
              };
            } else if (point < 8304) {
              switch (point) {
              | point when point >= 8293 && point <= 8293 => UNASSIGNED
              | point when point >= 8294 && point <= 8303 => DISALLOWED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8304 && point <= 8305 => FREEPVAL
              | point when point >= 8306 && point <= 8307 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 8349) {
            if (point < 8335) {
              switch (point) {
              | point when point >= 8308 && point <= 8334 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8335 && point <= 8335 => UNASSIGNED
              | point when point >= 8336 && point <= 8348 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 8384) {
            switch (point) {
            | point when point >= 8349 && point <= 8351 => UNASSIGNED
            | point when point >= 8352 && point <= 8383 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8384 && point <= 8399 => UNASSIGNED
            | point when point >= 8400 && point <= 8412 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 8487) {
          if (point < 8421) {
            if (point < 8417) {
              switch (point) {
              | point when point >= 8413 && point <= 8416 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8417 && point <= 8417 => PVALID
              | point when point >= 8418 && point <= 8420 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 8448) {
            switch (point) {
            | point when point >= 8421 && point <= 8432 => PVALID
            | point when point >= 8433 && point <= 8447 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8448 && point <= 8485 => FREEPVAL
            | point when point >= 8486 && point <= 8486 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 8498) {
          if (point < 8490) {
            switch (point) {
            | point when point >= 8487 && point <= 8489 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 8490 && point <= 8491 => PVALID
            | point when point >= 8492 && point <= 8497 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 8526) {
          switch (point) {
          | point when point >= 8498 && point <= 8498 => PVALID
          | point when point >= 8499 && point <= 8525 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 8526 && point <= 8526 => PVALID
          | point when point >= 8527 && point <= 8578 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 11312) {
        if (point < 9312) {
          if (point < 8592) {
            if (point < 8581) {
              switch (point) {
              | point when point >= 8579 && point <= 8580 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 8581 && point <= 8587 => FREEPVAL
              | point when point >= 8588 && point <= 8591 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 9280) {
            switch (point) {
            | point when point >= 8592 && point <= 9254 => FREEPVAL
            | point when point >= 9255 && point <= 9279 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 9280 && point <= 9290 => FREEPVAL
            | point when point >= 9291 && point <= 9311 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 11158) {
          if (point < 11124) {
            switch (point) {
            | point when point >= 9312 && point <= 11123 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 11124 && point <= 11125 => UNASSIGNED
            | point when point >= 11126 && point <= 11157 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 11264) {
          switch (point) {
          | point when point >= 11158 && point <= 11159 => UNASSIGNED
          | point when point >= 11160 && point <= 11263 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 11264 && point <= 11310 => PVALID
          | point when point >= 11311 && point <= 11311 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 11508) {
        if (point < 11388) {
          if (point < 11359) {
            switch (point) {
            | point when point >= 11312 && point <= 11358 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 11359 && point <= 11359 => UNASSIGNED
            | point when point >= 11360 && point <= 11387 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 11493) {
          switch (point) {
          | point when point >= 11388 && point <= 11389 => FREEPVAL
          | point when point >= 11390 && point <= 11492 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 11493 && point <= 11498 => FREEPVAL
          | point when point >= 11499 && point <= 11507 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 11558) {
        if (point < 11513) {
          switch (point) {
          | point when point >= 11508 && point <= 11512 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 11513 && point <= 11519 => FREEPVAL
          | point when point >= 11520 && point <= 11557 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 11560) {
        switch (point) {
        | point when point >= 11558 && point <= 11558 => UNASSIGNED
        | point when point >= 11559 && point <= 11559 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 11560 && point <= 11564 => UNASSIGNED
        | point when point >= 11565 && point <= 11565 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 12539) {
      if (point < 11856) {
        if (point < 11704) {
          if (point < 11671) {
            if (point < 11631) {
              if (point < 11568) {
                switch (point) {
                | point when point >= 11566 && point <= 11567 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 11568 && point <= 11623 => PVALID
                | point when point >= 11624 && point <= 11630 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 11633) {
              switch (point) {
              | point when point >= 11631 && point <= 11632 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 11633 && point <= 11646 => UNASSIGNED
              | point when point >= 11647 && point <= 11670 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 11688) {
            if (point < 11680) {
              switch (point) {
              | point when point >= 11671 && point <= 11679 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 11680 && point <= 11686 => PVALID
              | point when point >= 11687 && point <= 11687 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 11696) {
            switch (point) {
            | point when point >= 11688 && point <= 11694 => PVALID
            | point when point >= 11695 && point <= 11695 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 11696 && point <= 11702 => PVALID
            | point when point >= 11703 && point <= 11703 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 11735) {
          if (point < 11719) {
            if (point < 11711) {
              switch (point) {
              | point when point >= 11704 && point <= 11710 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 11711 && point <= 11711 => UNASSIGNED
              | point when point >= 11712 && point <= 11718 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 11727) {
            switch (point) {
            | point when point >= 11719 && point <= 11719 => UNASSIGNED
            | point when point >= 11720 && point <= 11726 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 11727 && point <= 11727 => UNASSIGNED
            | point when point >= 11728 && point <= 11734 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 11744) {
          if (point < 11736) {
            switch (point) {
            | point when point >= 11735 && point <= 11735 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 11736 && point <= 11742 => PVALID
            | point when point >= 11743 && point <= 11743 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 11823) {
          switch (point) {
          | point when point >= 11744 && point <= 11775 => PVALID
          | point when point >= 11776 && point <= 11822 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 11823 && point <= 11823 => PVALID
          | point when point >= 11824 && point <= 11855 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 12336) {
        if (point < 12272) {
          if (point < 11931) {
            if (point < 11904) {
              switch (point) {
              | point when point >= 11856 && point <= 11903 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 11904 && point <= 11929 => FREEPVAL
              | point when point >= 11930 && point <= 11930 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 12032) {
            switch (point) {
            | point when point >= 11931 && point <= 12019 => FREEPVAL
            | point when point >= 12020 && point <= 12031 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12032 && point <= 12245 => FREEPVAL
            | point when point >= 12246 && point <= 12271 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 12293) {
          if (point < 12284) {
            switch (point) {
            | point when point >= 12272 && point <= 12283 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12284 && point <= 12287 => UNASSIGNED
            | point when point >= 12288 && point <= 12292 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 12330) {
          switch (point) {
          | point when point >= 12293 && point <= 12295 => PVALID
          | point when point >= 12296 && point <= 12329 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 12330 && point <= 12333 => PVALID
          | point when point >= 12334 && point <= 12335 => DISALLOWED
          | _point => DISALLOWED
          };
        };
      } else if (point < 12353) {
        if (point < 12347) {
          if (point < 12337) {
            switch (point) {
            | point when point >= 12336 && point <= 12336 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12337 && point <= 12341 => DISALLOWED
            | point when point >= 12342 && point <= 12346 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 12349) {
          switch (point) {
          | point when point >= 12347 && point <= 12347 => DISALLOWED
          | point when point >= 12348 && point <= 12348 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 12349 && point <= 12351 => FREEPVAL
          | point when point >= 12352 && point <= 12352 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 12443) {
        if (point < 12439) {
          switch (point) {
          | point when point >= 12353 && point <= 12438 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 12439 && point <= 12440 => UNASSIGNED
          | point when point >= 12441 && point <= 12442 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 12447) {
        switch (point) {
        | point when point >= 12443 && point <= 12444 => FREEPVAL
        | point when point >= 12445 && point <= 12446 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 12447 && point <= 12448 => FREEPVAL
        | point when point >= 12449 && point <= 12538 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 42192) {
      if (point < 12772) {
        if (point < 12644) {
          if (point < 12544) {
            if (point < 12540) {
              switch (point) {
              | point when point >= 12539 && point <= 12539 => CONTEXTO
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 12540 && point <= 12542 => PVALID
              | point when point >= 12543 && point <= 12543 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 12592) {
            switch (point) {
            | point when point >= 12544 && point <= 12548 => UNASSIGNED
            | point when point >= 12549 && point <= 12591 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12592 && point <= 12592 => UNASSIGNED
            | point when point >= 12593 && point <= 12643 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 12688) {
          if (point < 12645) {
            switch (point) {
            | point when point >= 12644 && point <= 12644 => DISALLOWED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12645 && point <= 12686 => FREEPVAL
            | point when point >= 12687 && point <= 12687 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 12731) {
          switch (point) {
          | point when point >= 12688 && point <= 12703 => FREEPVAL
          | point when point >= 12704 && point <= 12730 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 12731 && point <= 12735 => UNASSIGNED
          | point when point >= 12736 && point <= 12771 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 19904) {
        if (point < 12831) {
          if (point < 12784) {
            switch (point) {
            | point when point >= 12772 && point <= 12783 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 12784 && point <= 12799 => PVALID
            | point when point >= 12800 && point <= 12830 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 13312) {
          switch (point) {
          | point when point >= 12831 && point <= 12831 => UNASSIGNED
          | point when point >= 12832 && point <= 13311 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 13312 && point <= 19893 => PVALID
          | point when point >= 19894 && point <= 19903 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 40960) {
        if (point < 19968) {
          switch (point) {
          | point when point >= 19904 && point <= 19967 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 19968 && point <= 40943 => PVALID
          | point when point >= 40944 && point <= 40959 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 42128) {
        switch (point) {
        | point when point >= 40960 && point <= 42124 => PVALID
        | point when point >= 42125 && point <= 42127 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 42128 && point <= 42182 => FREEPVAL
        | point when point >= 42183 && point <= 42191 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 42736) {
      if (point < 42608) {
        if (point < 42509) {
          if (point < 42238) {
            switch (point) {
            | point when point >= 42192 && point <= 42237 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 42238 && point <= 42239 => FREEPVAL
            | point when point >= 42240 && point <= 42508 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 42540) {
          switch (point) {
          | point when point >= 42509 && point <= 42511 => FREEPVAL
          | point when point >= 42512 && point <= 42539 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 42540 && point <= 42559 => UNASSIGNED
          | point when point >= 42560 && point <= 42607 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 42623) {
        if (point < 42612) {
          switch (point) {
          | point when point >= 42608 && point <= 42611 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 42612 && point <= 42621 => PVALID
          | point when point >= 42622 && point <= 42622 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 42654) {
        switch (point) {
        | point when point >= 42623 && point <= 42651 => PVALID
        | point when point >= 42652 && point <= 42653 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 42654 && point <= 42725 => PVALID
        | point when point >= 42726 && point <= 42735 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 42864) {
      if (point < 42752) {
        if (point < 42738) {
          switch (point) {
          | point when point >= 42736 && point <= 42737 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 42738 && point <= 42743 => FREEPVAL
          | point when point >= 42744 && point <= 42751 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 42784) {
        switch (point) {
        | point when point >= 42752 && point <= 42774 => FREEPVAL
        | point when point >= 42775 && point <= 42783 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 42784 && point <= 42785 => FREEPVAL
        | point when point >= 42786 && point <= 42863 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 42891) {
      if (point < 42865) {
        switch (point) {
        | point when point >= 42864 && point <= 42864 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 42865 && point <= 42888 => PVALID
        | point when point >= 42889 && point <= 42890 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 42946) {
      switch (point) {
      | point when point >= 42891 && point <= 42943 => PVALID
      | point when point >= 42944 && point <= 42945 => UNASSIGNED
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 42946 && point <= 42950 => PVALID
      | point when point >= 42951 && point <= 42998 => UNASSIGNED
      | _point => DISALLOWED
      };
    };
  } else if (point < 71360) {
    if (point < 67593) {
      if (point < 65040) {
        if (point < 43793) {
          if (point < 43457) {
            if (point < 43216) {
              if (point < 43066) {
                if (point < 43048) {
                  if (point < 43000) {
                    switch (point) {
                    | point when point >= 42999 && point <= 42999 => PVALID
                    | _point => DISALLOWED
                    };
                  } else {
                    switch (point) {
                    | point when point >= 43000 && point <= 43001 => FREEPVAL
                    | point when point >= 43002 && point <= 43047 => PVALID
                    | _point => DISALLOWED
                    };
                  };
                } else if (point < 43052) {
                  switch (point) {
                  | point when point >= 43048 && point <= 43051 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 43052 && point <= 43055 => UNASSIGNED
                  | point when point >= 43056 && point <= 43065 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 43128) {
                if (point < 43072) {
                  switch (point) {
                  | point when point >= 43066 && point <= 43071 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 43072 && point <= 43123 => PVALID
                  | point when point >= 43124 && point <= 43127 => FREEPVAL
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 43206) {
                switch (point) {
                | point when point >= 43128 && point <= 43135 => UNASSIGNED
                | point when point >= 43136 && point <= 43205 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43206 && point <= 43213 => UNASSIGNED
                | point when point >= 43214 && point <= 43215 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 43310) {
              if (point < 43256) {
                if (point < 43226) {
                  switch (point) {
                  | point when point >= 43216 && point <= 43225 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 43226 && point <= 43231 => UNASSIGNED
                  | point when point >= 43232 && point <= 43255 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 43260) {
                switch (point) {
                | point when point >= 43256 && point <= 43258 => FREEPVAL
                | point when point >= 43259 && point <= 43259 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43260 && point <= 43260 => FREEPVAL
                | point when point >= 43261 && point <= 43309 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 43359) {
              if (point < 43312) {
                switch (point) {
                | point when point >= 43310 && point <= 43311 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43312 && point <= 43347 => PVALID
                | point when point >= 43348 && point <= 43358 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 43389) {
              switch (point) {
              | point when point >= 43359 && point <= 43359 => FREEPVAL
              | point when point >= 43360 && point <= 43388 => DISALLOWED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 43389 && point <= 43391 => UNASSIGNED
              | point when point >= 43392 && point <= 43456 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 43616) {
            if (point < 43520) {
              if (point < 43482) {
                if (point < 43470) {
                  switch (point) {
                  | point when point >= 43457 && point <= 43469 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 43470 && point <= 43470 => UNASSIGNED
                  | point when point >= 43471 && point <= 43481 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 43488) {
                switch (point) {
                | point when point >= 43482 && point <= 43485 => UNASSIGNED
                | point when point >= 43486 && point <= 43487 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43488 && point <= 43518 => PVALID
                | point when point >= 43519 && point <= 43519 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 43598) {
              if (point < 43575) {
                switch (point) {
                | point when point >= 43520 && point <= 43574 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43575 && point <= 43583 => UNASSIGNED
                | point when point >= 43584 && point <= 43597 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 43610) {
              switch (point) {
              | point when point >= 43598 && point <= 43599 => UNASSIGNED
              | point when point >= 43600 && point <= 43609 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 43610 && point <= 43611 => UNASSIGNED
              | point when point >= 43612 && point <= 43615 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 43760) {
            if (point < 43715) {
              if (point < 43639) {
                switch (point) {
                | point when point >= 43616 && point <= 43638 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43639 && point <= 43641 => FREEPVAL
                | point when point >= 43642 && point <= 43714 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 43742) {
              switch (point) {
              | point when point >= 43715 && point <= 43738 => UNASSIGNED
              | point when point >= 43739 && point <= 43741 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 43742 && point <= 43743 => FREEPVAL
              | point when point >= 43744 && point <= 43759 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 43777) {
            if (point < 43762) {
              switch (point) {
              | point when point >= 43760 && point <= 43761 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 43762 && point <= 43766 => PVALID
              | point when point >= 43767 && point <= 43776 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 43785) {
            switch (point) {
            | point when point >= 43777 && point <= 43782 => PVALID
            | point when point >= 43783 && point <= 43784 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 43785 && point <= 43790 => PVALID
            | point when point >= 43791 && point <= 43792 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 64256) {
          if (point < 44014) {
            if (point < 43824) {
              if (point < 43815) {
                if (point < 43799) {
                  switch (point) {
                  | point when point >= 43793 && point <= 43798 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 43799 && point <= 43807 => UNASSIGNED
                  | point when point >= 43808 && point <= 43814 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 43816) {
                switch (point) {
                | point when point >= 43815 && point <= 43815 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43816 && point <= 43822 => PVALID
                | point when point >= 43823 && point <= 43823 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 43880) {
              if (point < 43867) {
                switch (point) {
                | point when point >= 43824 && point <= 43866 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 43867 && point <= 43871 => FREEPVAL
                | point when point >= 43872 && point <= 43879 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 44011) {
              switch (point) {
              | point when point >= 43880 && point <= 43887 => UNASSIGNED
              | point when point >= 43888 && point <= 44010 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 44011 && point <= 44011 => FREEPVAL
              | point when point >= 44012 && point <= 44013 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 55243) {
            if (point < 44032) {
              if (point < 44016) {
                switch (point) {
                | point when point >= 44014 && point <= 44015 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 44016 && point <= 44025 => PVALID
                | point when point >= 44026 && point <= 44031 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 55216) {
              switch (point) {
              | point when point >= 44032 && point <= 55203 => PVALID
              | point when point >= 55204 && point <= 55215 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 55216 && point <= 55238 => DISALLOWED
              | point when point >= 55239 && point <= 55242 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 63744) {
            if (point < 55292) {
              switch (point) {
              | point when point >= 55243 && point <= 55291 => DISALLOWED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 55292 && point <= 55295 => UNASSIGNED
              | point when point >= 55296 && point <= 63743 => DISALLOWED
              | _point => DISALLOWED
              };
            };
          } else if (point < 64112) {
            switch (point) {
            | point when point >= 63744 && point <= 64109 => PVALID
            | point when point >= 64110 && point <= 64111 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 64112 && point <= 64217 => PVALID
            | point when point >= 64218 && point <= 64255 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 64323) {
          if (point < 64311) {
            if (point < 64280) {
              if (point < 64263) {
                switch (point) {
                | point when point >= 64256 && point <= 64262 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 64263 && point <= 64274 => UNASSIGNED
                | point when point >= 64275 && point <= 64279 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 64288) {
              switch (point) {
              | point when point >= 64280 && point <= 64284 => UNASSIGNED
              | point when point >= 64285 && point <= 64287 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 64288 && point <= 64297 => FREEPVAL
              | point when point >= 64298 && point <= 64310 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 64318) {
            if (point < 64312) {
              switch (point) {
              | point when point >= 64311 && point <= 64311 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 64312 && point <= 64316 => PVALID
              | point when point >= 64317 && point <= 64317 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 64320) {
            switch (point) {
            | point when point >= 64318 && point <= 64318 => PVALID
            | point when point >= 64319 && point <= 64319 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 64320 && point <= 64321 => PVALID
            | point when point >= 64322 && point <= 64322 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 64848) {
          if (point < 64335) {
            if (point < 64325) {
              switch (point) {
              | point when point >= 64323 && point <= 64324 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 64325 && point <= 64325 => UNASSIGNED
              | point when point >= 64326 && point <= 64334 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 64467) {
            switch (point) {
            | point when point >= 64335 && point <= 64449 => FREEPVAL
            | point when point >= 64450 && point <= 64466 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 64467 && point <= 64831 => FREEPVAL
            | point when point >= 64832 && point <= 64847 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 64968) {
          if (point < 64912) {
            switch (point) {
            | point when point >= 64848 && point <= 64911 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 64912 && point <= 64913 => UNASSIGNED
            | point when point >= 64914 && point <= 64967 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 65022) {
          switch (point) {
          | point when point >= 64968 && point <= 65007 => UNASSIGNED
          | point when point >= 65008 && point <= 65021 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 65022 && point <= 65023 => UNASSIGNED
          | point when point >= 65024 && point <= 65039 => DISALLOWED
          | _point => DISALLOWED
          };
        };
      } else if (point < 65935) {
        if (point < 65498) {
          if (point < 65142) {
            if (point < 65127) {
              if (point < 65072) {
                if (point < 65050) {
                  switch (point) {
                  | point when point >= 65040 && point <= 65049 => FREEPVAL
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 65050 && point <= 65055 => UNASSIGNED
                  | point when point >= 65056 && point <= 65071 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 65107) {
                switch (point) {
                | point when point >= 65072 && point <= 65106 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 65107 && point <= 65107 => UNASSIGNED
                | point when point >= 65108 && point <= 65126 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 65136) {
              if (point < 65128) {
                switch (point) {
                | point when point >= 65127 && point <= 65127 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 65128 && point <= 65131 => FREEPVAL
                | point when point >= 65132 && point <= 65135 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 65140) {
              switch (point) {
              | point when point >= 65136 && point <= 65138 => FREEPVAL
              | point when point >= 65139 && point <= 65139 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65140 && point <= 65140 => FREEPVAL
              | point when point >= 65141 && point <= 65141 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 65471) {
            if (point < 65280) {
              if (point < 65277) {
                switch (point) {
                | point when point >= 65142 && point <= 65276 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 65277 && point <= 65278 => UNASSIGNED
                | point when point >= 65279 && point <= 65279 => DISALLOWED
                | _point => DISALLOWED
                };
              };
            } else if (point < 65440) {
              switch (point) {
              | point when point >= 65280 && point <= 65280 => UNASSIGNED
              | point when point >= 65281 && point <= 65439 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65440 && point <= 65440 => DISALLOWED
              | point when point >= 65441 && point <= 65470 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 65482) {
            if (point < 65474) {
              switch (point) {
              | point when point >= 65471 && point <= 65473 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65474 && point <= 65479 => FREEPVAL
              | point when point >= 65480 && point <= 65481 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 65490) {
            switch (point) {
            | point when point >= 65482 && point <= 65487 => FREEPVAL
            | point when point >= 65488 && point <= 65489 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 65490 && point <= 65495 => FREEPVAL
            | point when point >= 65496 && point <= 65497 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 65595) {
          if (point < 65532) {
            if (point < 65511) {
              if (point < 65501) {
                switch (point) {
                | point when point >= 65498 && point <= 65500 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 65501 && point <= 65503 => UNASSIGNED
                | point when point >= 65504 && point <= 65510 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 65519) {
              switch (point) {
              | point when point >= 65511 && point <= 65511 => UNASSIGNED
              | point when point >= 65512 && point <= 65518 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65519 && point <= 65528 => UNASSIGNED
              | point when point >= 65529 && point <= 65531 => DISALLOWED
              | _point => DISALLOWED
              };
            };
          } else if (point < 65548) {
            if (point < 65534) {
              switch (point) {
              | point when point >= 65532 && point <= 65533 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65534 && point <= 65535 => UNASSIGNED
              | point when point >= 65536 && point <= 65547 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 65575) {
            switch (point) {
            | point when point >= 65548 && point <= 65548 => UNASSIGNED
            | point when point >= 65549 && point <= 65574 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 65575 && point <= 65575 => UNASSIGNED
            | point when point >= 65576 && point <= 65594 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 65664) {
          if (point < 65599) {
            if (point < 65596) {
              switch (point) {
              | point when point >= 65595 && point <= 65595 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 65596 && point <= 65597 => PVALID
              | point when point >= 65598 && point <= 65598 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 65616) {
            switch (point) {
            | point when point >= 65599 && point <= 65613 => PVALID
            | point when point >= 65614 && point <= 65615 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 65616 && point <= 65629 => PVALID
            | point when point >= 65630 && point <= 65663 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 65795) {
          if (point < 65787) {
            switch (point) {
            | point when point >= 65664 && point <= 65786 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 65787 && point <= 65791 => UNASSIGNED
            | point when point >= 65792 && point <= 65794 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 65844) {
          switch (point) {
          | point when point >= 65795 && point <= 65798 => UNASSIGNED
          | point when point >= 65799 && point <= 65843 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 65844 && point <= 65846 => UNASSIGNED
          | point when point >= 65847 && point <= 65934 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 66464) {
        if (point < 66300) {
          if (point < 66046) {
            if (point < 65952) {
              if (point < 65936) {
                switch (point) {
                | point when point >= 65935 && point <= 65935 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 65936 && point <= 65947 => FREEPVAL
                | point when point >= 65948 && point <= 65951 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 66000) {
              switch (point) {
              | point when point >= 65952 && point <= 65952 => FREEPVAL
              | point when point >= 65953 && point <= 65999 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 66000 && point <= 66044 => FREEPVAL
              | point when point >= 66045 && point <= 66045 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 66208) {
            if (point < 66176) {
              switch (point) {
              | point when point >= 66046 && point <= 66175 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 66176 && point <= 66204 => PVALID
              | point when point >= 66205 && point <= 66207 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 66272) {
            switch (point) {
            | point when point >= 66208 && point <= 66256 => PVALID
            | point when point >= 66257 && point <= 66271 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66272 && point <= 66272 => PVALID
            | point when point >= 66273 && point <= 66299 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 66378) {
          if (point < 66340) {
            if (point < 66304) {
              switch (point) {
              | point when point >= 66300 && point <= 66303 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 66304 && point <= 66335 => PVALID
              | point when point >= 66336 && point <= 66339 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 66369) {
            switch (point) {
            | point when point >= 66340 && point <= 66348 => UNASSIGNED
            | point when point >= 66349 && point <= 66368 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66369 && point <= 66369 => FREEPVAL
            | point when point >= 66370 && point <= 66377 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 66427) {
          if (point < 66379) {
            switch (point) {
            | point when point >= 66378 && point <= 66378 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66379 && point <= 66383 => UNASSIGNED
            | point when point >= 66384 && point <= 66426 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 66462) {
          switch (point) {
          | point when point >= 66427 && point <= 66431 => UNASSIGNED
          | point when point >= 66432 && point <= 66461 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 66462 && point <= 66462 => UNASSIGNED
          | point when point >= 66463 && point <= 66463 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 66856) {
        if (point < 66720) {
          if (point < 66512) {
            if (point < 66500) {
              switch (point) {
              | point when point >= 66464 && point <= 66499 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 66500 && point <= 66503 => UNASSIGNED
              | point when point >= 66504 && point <= 66511 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 66560) {
            switch (point) {
            | point when point >= 66512 && point <= 66517 => FREEPVAL
            | point when point >= 66518 && point <= 66559 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66560 && point <= 66717 => PVALID
            | point when point >= 66718 && point <= 66719 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 66772) {
          if (point < 66730) {
            switch (point) {
            | point when point >= 66720 && point <= 66729 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66730 && point <= 66735 => UNASSIGNED
            | point when point >= 66736 && point <= 66771 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 66812) {
          switch (point) {
          | point when point >= 66772 && point <= 66775 => UNASSIGNED
          | point when point >= 66776 && point <= 66811 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 66812 && point <= 66815 => UNASSIGNED
          | point when point >= 66816 && point <= 66855 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 67392) {
        if (point < 66927) {
          if (point < 66864) {
            switch (point) {
            | point when point >= 66856 && point <= 66863 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 66864 && point <= 66915 => PVALID
            | point when point >= 66916 && point <= 66926 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 67072) {
          switch (point) {
          | point when point >= 66927 && point <= 66927 => FREEPVAL
          | point when point >= 66928 && point <= 67071 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 67072 && point <= 67382 => PVALID
          | point when point >= 67383 && point <= 67391 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 67432) {
        if (point < 67414) {
          switch (point) {
          | point when point >= 67392 && point <= 67413 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 67414 && point <= 67423 => UNASSIGNED
          | point when point >= 67424 && point <= 67431 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 67590) {
        switch (point) {
        | point when point >= 67432 && point <= 67583 => UNASSIGNED
        | point when point >= 67584 && point <= 67589 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 67590 && point <= 67591 => UNASSIGNED
        | point when point >= 67592 && point <= 67592 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 69826) {
      if (point < 68224) {
        if (point < 67903) {
          if (point < 67743) {
            if (point < 67645) {
              if (point < 67639) {
                if (point < 67594) {
                  switch (point) {
                  | point when point >= 67593 && point <= 67593 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 67594 && point <= 67637 => PVALID
                  | point when point >= 67638 && point <= 67638 => UNASSIGNED
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 67641) {
                switch (point) {
                | point when point >= 67639 && point <= 67640 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 67641 && point <= 67643 => UNASSIGNED
                | point when point >= 67644 && point <= 67644 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 67671) {
              if (point < 67647) {
                switch (point) {
                | point when point >= 67645 && point <= 67646 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 67647 && point <= 67669 => PVALID
                | point when point >= 67670 && point <= 67670 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 67703) {
              switch (point) {
              | point when point >= 67671 && point <= 67679 => FREEPVAL
              | point when point >= 67680 && point <= 67702 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 67703 && point <= 67711 => FREEPVAL
              | point when point >= 67712 && point <= 67742 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 67835) {
            if (point < 67808) {
              if (point < 67751) {
                switch (point) {
                | point when point >= 67743 && point <= 67750 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 67751 && point <= 67759 => FREEPVAL
                | point when point >= 67760 && point <= 67807 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 67828) {
              switch (point) {
              | point when point >= 67808 && point <= 67826 => PVALID
              | point when point >= 67827 && point <= 67827 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 67828 && point <= 67829 => PVALID
              | point when point >= 67830 && point <= 67834 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 67868) {
            if (point < 67840) {
              switch (point) {
              | point when point >= 67835 && point <= 67839 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 67840 && point <= 67861 => PVALID
              | point when point >= 67862 && point <= 67867 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 67872) {
            switch (point) {
            | point when point >= 67868 && point <= 67870 => UNASSIGNED
            | point when point >= 67871 && point <= 67871 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 67872 && point <= 67897 => PVALID
            | point when point >= 67898 && point <= 67902 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 68116) {
          if (point < 68048) {
            if (point < 68024) {
              if (point < 67904) {
                switch (point) {
                | point when point >= 67903 && point <= 67903 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 67904 && point <= 67967 => UNASSIGNED
                | point when point >= 67968 && point <= 68023 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 68030) {
              switch (point) {
              | point when point >= 68024 && point <= 68027 => UNASSIGNED
              | point when point >= 68028 && point <= 68029 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68030 && point <= 68031 => PVALID
              | point when point >= 68032 && point <= 68047 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 68100) {
            if (point < 68050) {
              switch (point) {
              | point when point >= 68048 && point <= 68049 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68050 && point <= 68095 => FREEPVAL
              | point when point >= 68096 && point <= 68099 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 68103) {
            switch (point) {
            | point when point >= 68100 && point <= 68100 => UNASSIGNED
            | point when point >= 68101 && point <= 68102 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68103 && point <= 68107 => UNASSIGNED
            | point when point >= 68108 && point <= 68115 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 68159) {
          if (point < 68121) {
            if (point < 68117) {
              switch (point) {
              | point when point >= 68116 && point <= 68116 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68117 && point <= 68119 => PVALID
              | point when point >= 68120 && point <= 68120 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 68152) {
            switch (point) {
            | point when point >= 68121 && point <= 68149 => PVALID
            | point when point >= 68150 && point <= 68151 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68152 && point <= 68154 => PVALID
            | point when point >= 68155 && point <= 68158 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 68176) {
          if (point < 68160) {
            switch (point) {
            | point when point >= 68159 && point <= 68159 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68160 && point <= 68168 => FREEPVAL
            | point when point >= 68169 && point <= 68175 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 68192) {
          switch (point) {
          | point when point >= 68176 && point <= 68184 => FREEPVAL
          | point when point >= 68185 && point <= 68191 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 68192 && point <= 68220 => PVALID
          | point when point >= 68221 && point <= 68223 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 68800) {
        if (point < 68440) {
          if (point < 68331) {
            if (point < 68288) {
              if (point < 68253) {
                switch (point) {
                | point when point >= 68224 && point <= 68252 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 68253 && point <= 68255 => FREEPVAL
                | point when point >= 68256 && point <= 68287 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 68297) {
              switch (point) {
              | point when point >= 68288 && point <= 68295 => PVALID
              | point when point >= 68296 && point <= 68296 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68297 && point <= 68326 => PVALID
              | point when point >= 68327 && point <= 68330 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 68406) {
            if (point < 68343) {
              switch (point) {
              | point when point >= 68331 && point <= 68342 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68343 && point <= 68351 => UNASSIGNED
              | point when point >= 68352 && point <= 68405 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 68416) {
            switch (point) {
            | point when point >= 68406 && point <= 68408 => UNASSIGNED
            | point when point >= 68409 && point <= 68415 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68416 && point <= 68437 => PVALID
            | point when point >= 68438 && point <= 68439 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 68509) {
          if (point < 68472) {
            if (point < 68448) {
              switch (point) {
              | point when point >= 68440 && point <= 68447 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68448 && point <= 68466 => PVALID
              | point when point >= 68467 && point <= 68471 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 68498) {
            switch (point) {
            | point when point >= 68472 && point <= 68479 => FREEPVAL
            | point when point >= 68480 && point <= 68497 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68498 && point <= 68504 => UNASSIGNED
            | point when point >= 68505 && point <= 68508 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 68608) {
          if (point < 68521) {
            switch (point) {
            | point when point >= 68509 && point <= 68520 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68521 && point <= 68527 => FREEPVAL
            | point when point >= 68528 && point <= 68607 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 68736) {
          switch (point) {
          | point when point >= 68608 && point <= 68680 => PVALID
          | point when point >= 68681 && point <= 68735 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 68736 && point <= 68786 => PVALID
          | point when point >= 68787 && point <= 68799 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 69457) {
        if (point < 69216) {
          if (point < 68864) {
            if (point < 68851) {
              switch (point) {
              | point when point >= 68800 && point <= 68850 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 68851 && point <= 68857 => UNASSIGNED
              | point when point >= 68858 && point <= 68863 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 68912) {
            switch (point) {
            | point when point >= 68864 && point <= 68903 => PVALID
            | point when point >= 68904 && point <= 68911 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 68912 && point <= 68921 => PVALID
            | point when point >= 68922 && point <= 69215 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 69405) {
          if (point < 69247) {
            switch (point) {
            | point when point >= 69216 && point <= 69246 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 69247 && point <= 69375 => UNASSIGNED
            | point when point >= 69376 && point <= 69404 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 69416) {
          switch (point) {
          | point when point >= 69405 && point <= 69414 => FREEPVAL
          | point when point >= 69415 && point <= 69415 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 69416 && point <= 69423 => UNASSIGNED
          | point when point >= 69424 && point <= 69456 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 69714) {
        if (point < 69623) {
          if (point < 69466) {
            switch (point) {
            | point when point >= 69457 && point <= 69465 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 69466 && point <= 69599 => UNASSIGNED
            | point when point >= 69600 && point <= 69622 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 69703) {
          switch (point) {
          | point when point >= 69623 && point <= 69631 => UNASSIGNED
          | point when point >= 69632 && point <= 69702 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 69703 && point <= 69709 => FREEPVAL
          | point when point >= 69710 && point <= 69713 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 69759) {
        if (point < 69734) {
          switch (point) {
          | point when point >= 69714 && point <= 69733 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 69734 && point <= 69743 => PVALID
          | point when point >= 69744 && point <= 69758 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 69821) {
        switch (point) {
        | point when point >= 69759 && point <= 69818 => PVALID
        | point when point >= 69819 && point <= 69820 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 69821 && point <= 69821 => DISALLOWED
        | point when point >= 69822 && point <= 69825 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 70417) {
      if (point < 70113) {
        if (point < 69968) {
          if (point < 69882) {
            if (point < 69840) {
              if (point < 69837) {
                switch (point) {
                | point when point >= 69826 && point <= 69836 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 69837 && point <= 69837 => DISALLOWED
                | point when point >= 69838 && point <= 69839 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 69865) {
              switch (point) {
              | point when point >= 69840 && point <= 69864 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 69865 && point <= 69871 => UNASSIGNED
              | point when point >= 69872 && point <= 69881 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 69942) {
            if (point < 69888) {
              switch (point) {
              | point when point >= 69882 && point <= 69887 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 69888 && point <= 69940 => PVALID
              | point when point >= 69941 && point <= 69941 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 69956) {
            switch (point) {
            | point when point >= 69942 && point <= 69951 => PVALID
            | point when point >= 69952 && point <= 69955 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 69956 && point <= 69958 => PVALID
            | point when point >= 69959 && point <= 69967 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 70093) {
          if (point < 70007) {
            if (point < 70004) {
              switch (point) {
              | point when point >= 69968 && point <= 70003 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 70004 && point <= 70005 => FREEPVAL
              | point when point >= 70006 && point <= 70006 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 70085) {
            switch (point) {
            | point when point >= 70007 && point <= 70015 => UNASSIGNED
            | point when point >= 70016 && point <= 70084 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70085 && point <= 70088 => FREEPVAL
            | point when point >= 70089 && point <= 70092 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 70107) {
          if (point < 70094) {
            switch (point) {
            | point when point >= 70093 && point <= 70093 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70094 && point <= 70095 => UNASSIGNED
            | point when point >= 70096 && point <= 70106 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 70109) {
          switch (point) {
          | point when point >= 70107 && point <= 70107 => FREEPVAL
          | point when point >= 70108 && point <= 70108 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70109 && point <= 70111 => FREEPVAL
          | point when point >= 70112 && point <= 70112 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 70287) {
        if (point < 70207) {
          if (point < 70162) {
            if (point < 70133) {
              switch (point) {
              | point when point >= 70113 && point <= 70132 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 70133 && point <= 70143 => UNASSIGNED
              | point when point >= 70144 && point <= 70161 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 70200) {
            switch (point) {
            | point when point >= 70162 && point <= 70162 => UNASSIGNED
            | point when point >= 70163 && point <= 70199 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70200 && point <= 70205 => FREEPVAL
            | point when point >= 70206 && point <= 70206 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 70280) {
          if (point < 70272) {
            switch (point) {
            | point when point >= 70207 && point <= 70271 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70272 && point <= 70278 => PVALID
            | point when point >= 70279 && point <= 70279 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 70282) {
          switch (point) {
          | point when point >= 70280 && point <= 70280 => PVALID
          | point when point >= 70281 && point <= 70281 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70282 && point <= 70285 => PVALID
          | point when point >= 70286 && point <= 70286 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 70384) {
        if (point < 70313) {
          if (point < 70302) {
            switch (point) {
            | point when point >= 70287 && point <= 70301 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70302 && point <= 70302 => UNASSIGNED
            | point when point >= 70303 && point <= 70312 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 70320) {
          switch (point) {
          | point when point >= 70313 && point <= 70313 => FREEPVAL
          | point when point >= 70314 && point <= 70319 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70320 && point <= 70378 => PVALID
          | point when point >= 70379 && point <= 70383 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 70404) {
        if (point < 70394) {
          switch (point) {
          | point when point >= 70384 && point <= 70393 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70394 && point <= 70399 => UNASSIGNED
          | point when point >= 70400 && point <= 70403 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 70413) {
        switch (point) {
        | point when point >= 70404 && point <= 70404 => UNASSIGNED
        | point when point >= 70405 && point <= 70412 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 70413 && point <= 70414 => UNASSIGNED
        | point when point >= 70415 && point <= 70416 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 70746) {
      if (point < 70478) {
        if (point < 70453) {
          if (point < 70442) {
            if (point < 70419) {
              switch (point) {
              | point when point >= 70417 && point <= 70418 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 70419 && point <= 70440 => PVALID
              | point when point >= 70441 && point <= 70441 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 70450) {
            switch (point) {
            | point when point >= 70442 && point <= 70448 => PVALID
            | point when point >= 70449 && point <= 70449 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70450 && point <= 70451 => PVALID
            | point when point >= 70452 && point <= 70452 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 70469) {
          if (point < 70458) {
            switch (point) {
            | point when point >= 70453 && point <= 70457 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70458 && point <= 70458 => UNASSIGNED
            | point when point >= 70459 && point <= 70468 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 70473) {
          switch (point) {
          | point when point >= 70469 && point <= 70470 => UNASSIGNED
          | point when point >= 70471 && point <= 70472 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70473 && point <= 70474 => UNASSIGNED
          | point when point >= 70475 && point <= 70477 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 70502) {
        if (point < 70487) {
          if (point < 70480) {
            switch (point) {
            | point when point >= 70478 && point <= 70479 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70480 && point <= 70480 => PVALID
            | point when point >= 70481 && point <= 70486 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 70493) {
          switch (point) {
          | point when point >= 70487 && point <= 70487 => PVALID
          | point when point >= 70488 && point <= 70492 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70493 && point <= 70499 => PVALID
          | point when point >= 70500 && point <= 70501 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 70517) {
        if (point < 70509) {
          switch (point) {
          | point when point >= 70502 && point <= 70508 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70509 && point <= 70511 => UNASSIGNED
          | point when point >= 70512 && point <= 70516 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 70731) {
        switch (point) {
        | point when point >= 70517 && point <= 70655 => UNASSIGNED
        | point when point >= 70656 && point <= 70730 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 70731 && point <= 70735 => FREEPVAL
        | point when point >= 70736 && point <= 70745 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 71096) {
      if (point < 70854) {
        if (point < 70749) {
          if (point < 70747) {
            switch (point) {
            | point when point >= 70746 && point <= 70746 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 70747 && point <= 70747 => FREEPVAL
            | point when point >= 70748 && point <= 70748 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 70752) {
          switch (point) {
          | point when point >= 70749 && point <= 70749 => FREEPVAL
          | point when point >= 70750 && point <= 70751 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70752 && point <= 70783 => UNASSIGNED
          | point when point >= 70784 && point <= 70853 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 70864) {
        if (point < 70855) {
          switch (point) {
          | point when point >= 70854 && point <= 70854 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 70855 && point <= 70855 => PVALID
          | point when point >= 70856 && point <= 70863 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 71040) {
        switch (point) {
        | point when point >= 70864 && point <= 70873 => PVALID
        | point when point >= 70874 && point <= 71039 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 71040 && point <= 71093 => PVALID
        | point when point >= 71094 && point <= 71095 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 71237) {
      if (point < 71134) {
        if (point < 71105) {
          switch (point) {
          | point when point >= 71096 && point <= 71104 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 71105 && point <= 71127 => FREEPVAL
          | point when point >= 71128 && point <= 71133 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 71233) {
        switch (point) {
        | point when point >= 71134 && point <= 71167 => UNASSIGNED
        | point when point >= 71168 && point <= 71232 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 71233 && point <= 71235 => FREEPVAL
        | point when point >= 71236 && point <= 71236 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 71264) {
      if (point < 71248) {
        switch (point) {
        | point when point >= 71237 && point <= 71247 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 71248 && point <= 71257 => PVALID
        | point when point >= 71258 && point <= 71263 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 71296) {
      switch (point) {
      | point when point >= 71264 && point <= 71276 => FREEPVAL
      | point when point >= 71277 && point <= 71295 => UNASSIGNED
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 71296 && point <= 71352 => PVALID
      | point when point >= 71353 && point <= 71359 => UNASSIGNED
      | _point => DISALLOWED
      };
    };
  } else if (point < 120135) {
    if (point < 92918) {
      if (point < 72968) {
        if (point < 72263) {
          if (point < 71914) {
            if (point < 71472) {
              if (point < 71451) {
                if (point < 71370) {
                  switch (point) {
                  | point when point >= 71360 && point <= 71369 => PVALID
                  | _point => DISALLOWED
                  };
                } else {
                  switch (point) {
                  | point when point >= 71370 && point <= 71423 => UNASSIGNED
                  | point when point >= 71424 && point <= 71450 => PVALID
                  | _point => DISALLOWED
                  };
                };
              } else if (point < 71453) {
                switch (point) {
                | point when point >= 71451 && point <= 71452 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 71453 && point <= 71467 => PVALID
                | point when point >= 71468 && point <= 71471 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 71680) {
              if (point < 71482) {
                switch (point) {
                | point when point >= 71472 && point <= 71481 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 71482 && point <= 71487 => FREEPVAL
                | point when point >= 71488 && point <= 71679 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 71740) {
              switch (point) {
              | point when point >= 71680 && point <= 71738 => PVALID
              | point when point >= 71739 && point <= 71739 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 71740 && point <= 71839 => UNASSIGNED
              | point when point >= 71840 && point <= 71913 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 72152) {
            if (point < 71936) {
              if (point < 71923) {
                switch (point) {
                | point when point >= 71914 && point <= 71922 => FREEPVAL
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 71923 && point <= 71934 => UNASSIGNED
                | point when point >= 71935 && point <= 71935 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 72104) {
              switch (point) {
              | point when point >= 71936 && point <= 72095 => UNASSIGNED
              | point when point >= 72096 && point <= 72103 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 72104 && point <= 72105 => UNASSIGNED
              | point when point >= 72106 && point <= 72151 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 72163) {
            if (point < 72154) {
              switch (point) {
              | point when point >= 72152 && point <= 72153 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 72154 && point <= 72161 => PVALID
              | point when point >= 72162 && point <= 72162 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 72192) {
            switch (point) {
            | point when point >= 72163 && point <= 72164 => PVALID
            | point when point >= 72165 && point <= 72191 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 72192 && point <= 72254 => PVALID
            | point when point >= 72255 && point <= 72262 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 72769) {
          if (point < 72384) {
            if (point < 72346) {
              if (point < 72264) {
                switch (point) {
                | point when point >= 72263 && point <= 72263 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 72264 && point <= 72271 => UNASSIGNED
                | point when point >= 72272 && point <= 72345 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 72350) {
              switch (point) {
              | point when point >= 72346 && point <= 72348 => FREEPVAL
              | point when point >= 72349 && point <= 72349 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 72350 && point <= 72354 => FREEPVAL
              | point when point >= 72355 && point <= 72383 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 72713) {
            if (point < 72441) {
              switch (point) {
              | point when point >= 72384 && point <= 72440 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 72441 && point <= 72703 => UNASSIGNED
              | point when point >= 72704 && point <= 72712 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 72759) {
            switch (point) {
            | point when point >= 72713 && point <= 72713 => UNASSIGNED
            | point when point >= 72714 && point <= 72758 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 72759 && point <= 72759 => UNASSIGNED
            | point when point >= 72760 && point <= 72768 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 72848) {
          if (point < 72794) {
            if (point < 72774) {
              switch (point) {
              | point when point >= 72769 && point <= 72773 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 72774 && point <= 72783 => UNASSIGNED
              | point when point >= 72784 && point <= 72793 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 72816) {
            switch (point) {
            | point when point >= 72794 && point <= 72812 => FREEPVAL
            | point when point >= 72813 && point <= 72815 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 72816 && point <= 72817 => FREEPVAL
            | point when point >= 72818 && point <= 72847 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 72873) {
          if (point < 72850) {
            switch (point) {
            | point when point >= 72848 && point <= 72849 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 72850 && point <= 72871 => PVALID
            | point when point >= 72872 && point <= 72872 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 72960) {
          switch (point) {
          | point when point >= 72873 && point <= 72886 => PVALID
          | point when point >= 72887 && point <= 72959 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 72960 && point <= 72966 => PVALID
          | point when point >= 72967 && point <= 72967 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 73714) {
        if (point < 73063) {
          if (point < 73022) {
            if (point < 73015) {
              if (point < 72970) {
                switch (point) {
                | point when point >= 72968 && point <= 72969 => PVALID
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 72970 && point <= 72970 => UNASSIGNED
                | point when point >= 72971 && point <= 73014 => PVALID
                | _point => DISALLOWED
                };
              };
            } else if (point < 73019) {
              switch (point) {
              | point when point >= 73015 && point <= 73017 => UNASSIGNED
              | point when point >= 73018 && point <= 73018 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 73019 && point <= 73019 => UNASSIGNED
              | point when point >= 73020 && point <= 73021 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 73040) {
            if (point < 73023) {
              switch (point) {
              | point when point >= 73022 && point <= 73022 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 73023 && point <= 73031 => PVALID
              | point when point >= 73032 && point <= 73039 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 73056) {
            switch (point) {
            | point when point >= 73040 && point <= 73049 => PVALID
            | point when point >= 73050 && point <= 73055 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 73056 && point <= 73061 => PVALID
            | point when point >= 73062 && point <= 73062 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 73113) {
          if (point < 73103) {
            if (point < 73065) {
              switch (point) {
              | point when point >= 73063 && point <= 73064 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 73065 && point <= 73065 => UNASSIGNED
              | point when point >= 73066 && point <= 73102 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 73106) {
            switch (point) {
            | point when point >= 73103 && point <= 73103 => UNASSIGNED
            | point when point >= 73104 && point <= 73105 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 73106 && point <= 73106 => UNASSIGNED
            | point when point >= 73107 && point <= 73112 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 73440) {
          if (point < 73120) {
            switch (point) {
            | point when point >= 73113 && point <= 73119 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 73120 && point <= 73129 => PVALID
            | point when point >= 73130 && point <= 73439 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 73465) {
          switch (point) {
          | point when point >= 73440 && point <= 73462 => PVALID
          | point when point >= 73463 && point <= 73464 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 73465 && point <= 73663 => UNASSIGNED
          | point when point >= 73664 && point <= 73713 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 82944) {
        if (point < 74869) {
          if (point < 74650) {
            if (point < 73727) {
              switch (point) {
              | point when point >= 73714 && point <= 73726 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 73727 && point <= 73727 => FREEPVAL
              | point when point >= 73728 && point <= 74649 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 74863) {
            switch (point) {
            | point when point >= 74650 && point <= 74751 => UNASSIGNED
            | point when point >= 74752 && point <= 74862 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 74863 && point <= 74863 => UNASSIGNED
            | point when point >= 74864 && point <= 74868 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 77824) {
          if (point < 74880) {
            switch (point) {
            | point when point >= 74869 && point <= 74879 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 74880 && point <= 75075 => PVALID
            | point when point >= 75076 && point <= 77823 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 78896) {
          switch (point) {
          | point when point >= 77824 && point <= 78894 => PVALID
          | point when point >= 78895 && point <= 78895 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 78896 && point <= 78904 => DISALLOWED
          | point when point >= 78905 && point <= 82943 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 92778) {
        if (point < 92729) {
          if (point < 83527) {
            switch (point) {
            | point when point >= 82944 && point <= 83526 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 83527 && point <= 92159 => UNASSIGNED
            | point when point >= 92160 && point <= 92728 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 92767) {
          switch (point) {
          | point when point >= 92729 && point <= 92735 => UNASSIGNED
          | point when point >= 92736 && point <= 92766 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 92767 && point <= 92767 => UNASSIGNED
          | point when point >= 92768 && point <= 92777 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 92880) {
        if (point < 92782) {
          switch (point) {
          | point when point >= 92778 && point <= 92781 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 92782 && point <= 92783 => FREEPVAL
          | point when point >= 92784 && point <= 92879 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 92912) {
        switch (point) {
        | point when point >= 92880 && point <= 92909 => PVALID
        | point when point >= 92910 && point <= 92911 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 92912 && point <= 92916 => PVALID
        | point when point >= 92917 && point <= 92917 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 119079) {
      if (point < 94208) {
        if (point < 93072) {
          if (point < 93008) {
            if (point < 92992) {
              if (point < 92928) {
                switch (point) {
                | point when point >= 92918 && point <= 92927 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 92928 && point <= 92982 => PVALID
                | point when point >= 92983 && point <= 92991 => FREEPVAL
                | _point => DISALLOWED
                };
              };
            } else if (point < 92996) {
              switch (point) {
              | point when point >= 92992 && point <= 92995 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 92996 && point <= 92997 => FREEPVAL
              | point when point >= 92998 && point <= 93007 => UNASSIGNED
              | _point => DISALLOWED
              };
            };
          } else if (point < 93026) {
            if (point < 93018) {
              switch (point) {
              | point when point >= 93008 && point <= 93017 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 93018 && point <= 93018 => UNASSIGNED
              | point when point >= 93019 && point <= 93025 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 93048) {
            switch (point) {
            | point when point >= 93026 && point <= 93026 => UNASSIGNED
            | point when point >= 93027 && point <= 93047 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 93048 && point <= 93052 => UNASSIGNED
            | point when point >= 93053 && point <= 93071 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 94088) {
          if (point < 93851) {
            if (point < 93760) {
              switch (point) {
              | point when point >= 93072 && point <= 93759 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 93760 && point <= 93823 => PVALID
              | point when point >= 93824 && point <= 93850 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 94027) {
            switch (point) {
            | point when point >= 93851 && point <= 93951 => UNASSIGNED
            | point when point >= 93952 && point <= 94026 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 94027 && point <= 94030 => UNASSIGNED
            | point when point >= 94031 && point <= 94087 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 94176) {
          if (point < 94095) {
            switch (point) {
            | point when point >= 94088 && point <= 94094 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 94095 && point <= 94111 => PVALID
            | point when point >= 94112 && point <= 94175 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 94179) {
          switch (point) {
          | point when point >= 94176 && point <= 94177 => PVALID
          | point when point >= 94178 && point <= 94178 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 94179 && point <= 94179 => PVALID
          | point when point >= 94180 && point <= 94207 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 113776) {
        if (point < 110931) {
          if (point < 101107) {
            if (point < 100344) {
              switch (point) {
              | point when point >= 94208 && point <= 100343 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 100344 && point <= 100351 => UNASSIGNED
              | point when point >= 100352 && point <= 101106 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 110879) {
            switch (point) {
            | point when point >= 101107 && point <= 110591 => UNASSIGNED
            | point when point >= 110592 && point <= 110878 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 110879 && point <= 110927 => UNASSIGNED
            | point when point >= 110928 && point <= 110930 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 110960) {
          if (point < 110948) {
            switch (point) {
            | point when point >= 110931 && point <= 110947 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 110948 && point <= 110951 => PVALID
            | point when point >= 110952 && point <= 110959 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 113664) {
          switch (point) {
          | point when point >= 110960 && point <= 111355 => PVALID
          | point when point >= 111356 && point <= 113663 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 113664 && point <= 113770 => PVALID
          | point when point >= 113771 && point <= 113775 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 113821) {
        if (point < 113801) {
          if (point < 113789) {
            switch (point) {
            | point when point >= 113776 && point <= 113788 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 113789 && point <= 113791 => UNASSIGNED
            | point when point >= 113792 && point <= 113800 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 113818) {
          switch (point) {
          | point when point >= 113801 && point <= 113807 => UNASSIGNED
          | point when point >= 113808 && point <= 113817 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 113818 && point <= 113819 => UNASSIGNED
          | point when point >= 113820 && point <= 113820 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 113828) {
        if (point < 113823) {
          switch (point) {
          | point when point >= 113821 && point <= 113822 => PVALID
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 113823 && point <= 113823 => FREEPVAL
          | point when point >= 113824 && point <= 113827 => DISALLOWED
          | _point => DISALLOWED
          };
        };
      } else if (point < 119030) {
        switch (point) {
        | point when point >= 113828 && point <= 118783 => UNASSIGNED
        | point when point >= 118784 && point <= 119029 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 119030 && point <= 119039 => UNASSIGNED
        | point when point >= 119040 && point <= 119078 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 119968) {
      if (point < 119362) {
        if (point < 119171) {
          if (point < 119146) {
            if (point < 119081) {
              switch (point) {
              | point when point >= 119079 && point <= 119080 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 119081 && point <= 119140 => FREEPVAL
              | point when point >= 119141 && point <= 119145 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 119155) {
            switch (point) {
            | point when point >= 119146 && point <= 119148 => FREEPVAL
            | point when point >= 119149 && point <= 119154 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 119155 && point <= 119162 => DISALLOWED
            | point when point >= 119163 && point <= 119170 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 119210) {
          if (point < 119173) {
            switch (point) {
            | point when point >= 119171 && point <= 119172 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 119173 && point <= 119179 => PVALID
            | point when point >= 119180 && point <= 119209 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 119273) {
          switch (point) {
          | point when point >= 119210 && point <= 119213 => PVALID
          | point when point >= 119214 && point <= 119272 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 119273 && point <= 119295 => UNASSIGNED
          | point when point >= 119296 && point <= 119361 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 119648) {
        if (point < 119520) {
          if (point < 119365) {
            switch (point) {
            | point when point >= 119362 && point <= 119364 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 119365 && point <= 119365 => FREEPVAL
            | point when point >= 119366 && point <= 119519 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 119552) {
          switch (point) {
          | point when point >= 119520 && point <= 119539 => FREEPVAL
          | point when point >= 119540 && point <= 119551 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 119552 && point <= 119638 => FREEPVAL
          | point when point >= 119639 && point <= 119647 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 119893) {
        if (point < 119673) {
          switch (point) {
          | point when point >= 119648 && point <= 119672 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 119673 && point <= 119807 => UNASSIGNED
          | point when point >= 119808 && point <= 119892 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 119965) {
        switch (point) {
        | point when point >= 119893 && point <= 119893 => UNASSIGNED
        | point when point >= 119894 && point <= 119964 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 119965 && point <= 119965 => UNASSIGNED
        | point when point >= 119966 && point <= 119967 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 120070) {
      if (point < 119982) {
        if (point < 119973) {
          if (point < 119970) {
            switch (point) {
            | point when point >= 119968 && point <= 119969 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 119970 && point <= 119970 => FREEPVAL
            | point when point >= 119971 && point <= 119972 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 119977) {
          switch (point) {
          | point when point >= 119973 && point <= 119974 => FREEPVAL
          | point when point >= 119975 && point <= 119976 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 119977 && point <= 119980 => FREEPVAL
          | point when point >= 119981 && point <= 119981 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 119996) {
        if (point < 119994) {
          switch (point) {
          | point when point >= 119982 && point <= 119993 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 119994 && point <= 119994 => UNASSIGNED
          | point when point >= 119995 && point <= 119995 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 120004) {
        switch (point) {
        | point when point >= 119996 && point <= 119996 => UNASSIGNED
        | point when point >= 119997 && point <= 120003 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 120004 && point <= 120004 => UNASSIGNED
        | point when point >= 120005 && point <= 120069 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 120094) {
      if (point < 120077) {
        if (point < 120071) {
          switch (point) {
          | point when point >= 120070 && point <= 120070 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 120071 && point <= 120074 => FREEPVAL
          | point when point >= 120075 && point <= 120076 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 120086) {
        switch (point) {
        | point when point >= 120077 && point <= 120084 => FREEPVAL
        | point when point >= 120085 && point <= 120085 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 120086 && point <= 120092 => FREEPVAL
        | point when point >= 120093 && point <= 120093 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 120127) {
      if (point < 120122) {
        switch (point) {
        | point when point >= 120094 && point <= 120121 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 120122 && point <= 120122 => UNASSIGNED
        | point when point >= 120123 && point <= 120126 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 120133) {
      switch (point) {
      | point when point >= 120127 && point <= 120127 => UNASSIGNED
      | point when point >= 120128 && point <= 120132 => FREEPVAL
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 120133 && point <= 120133 => UNASSIGNED
      | point when point >= 120134 && point <= 120134 => FREEPVAL
      | _point => DISALLOWED
      };
    };
  } else if (point < 126585) {
    if (point < 126065) {
      if (point < 122915) {
        if (point < 121462) {
          if (point < 120780) {
            if (point < 120146) {
              if (point < 120138) {
                switch (point) {
                | point when point >= 120135 && point <= 120137 => UNASSIGNED
                | _point => DISALLOWED
                };
              } else {
                switch (point) {
                | point when point >= 120138 && point <= 120144 => FREEPVAL
                | point when point >= 120145 && point <= 120145 => UNASSIGNED
                | _point => DISALLOWED
                };
              };
            } else if (point < 120486) {
              switch (point) {
              | point when point >= 120146 && point <= 120485 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 120486 && point <= 120487 => UNASSIGNED
              | point when point >= 120488 && point <= 120779 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 121399) {
            if (point < 120782) {
              switch (point) {
              | point when point >= 120780 && point <= 120781 => UNASSIGNED
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 120782 && point <= 121343 => FREEPVAL
              | point when point >= 121344 && point <= 121398 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 121453) {
            switch (point) {
            | point when point >= 121399 && point <= 121402 => FREEPVAL
            | point when point >= 121403 && point <= 121452 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 121453 && point <= 121460 => FREEPVAL
            | point when point >= 121461 && point <= 121461 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 121520) {
          if (point < 121484) {
            if (point < 121476) {
              switch (point) {
              | point when point >= 121462 && point <= 121475 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 121476 && point <= 121476 => PVALID
              | point when point >= 121477 && point <= 121483 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 121504) {
            switch (point) {
            | point when point >= 121484 && point <= 121498 => UNASSIGNED
            | point when point >= 121499 && point <= 121503 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 121504 && point <= 121504 => UNASSIGNED
            | point when point >= 121505 && point <= 121519 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 122888) {
          if (point < 122880) {
            switch (point) {
            | point when point >= 121520 && point <= 122879 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 122880 && point <= 122886 => PVALID
            | point when point >= 122887 && point <= 122887 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 122907) {
          switch (point) {
          | point when point >= 122888 && point <= 122904 => PVALID
          | point when point >= 122905 && point <= 122906 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 122907 && point <= 122913 => PVALID
          | point when point >= 122914 && point <= 122914 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 123642) {
        if (point < 123198) {
          if (point < 122923) {
            if (point < 122917) {
              switch (point) {
              | point when point >= 122915 && point <= 122916 => PVALID
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 122917 && point <= 122917 => UNASSIGNED
              | point when point >= 122918 && point <= 122922 => PVALID
              | _point => DISALLOWED
              };
            };
          } else if (point < 123181) {
            switch (point) {
            | point when point >= 122923 && point <= 123135 => UNASSIGNED
            | point when point >= 123136 && point <= 123180 => PVALID
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 123181 && point <= 123183 => UNASSIGNED
            | point when point >= 123184 && point <= 123197 => PVALID
            | _point => DISALLOWED
            };
          };
        } else if (point < 123214) {
          if (point < 123200) {
            switch (point) {
            | point when point >= 123198 && point <= 123199 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 123200 && point <= 123209 => PVALID
            | point when point >= 123210 && point <= 123213 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 123216) {
          switch (point) {
          | point when point >= 123214 && point <= 123214 => PVALID
          | point when point >= 123215 && point <= 123215 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 123216 && point <= 123583 => UNASSIGNED
          | point when point >= 123584 && point <= 123641 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 125143) {
        if (point < 124928) {
          if (point < 123647) {
            switch (point) {
            | point when point >= 123642 && point <= 123646 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 123647 && point <= 123647 => FREEPVAL
            | point when point >= 123648 && point <= 124927 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 125127) {
          switch (point) {
          | point when point >= 124928 && point <= 125124 => PVALID
          | point when point >= 125125 && point <= 125126 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 125127 && point <= 125135 => FREEPVAL
          | point when point >= 125136 && point <= 125142 => PVALID
          | _point => DISALLOWED
          };
        };
      } else if (point < 125264) {
        if (point < 125184) {
          switch (point) {
          | point when point >= 125143 && point <= 125183 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 125184 && point <= 125259 => PVALID
          | point when point >= 125260 && point <= 125263 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 125278) {
        switch (point) {
        | point when point >= 125264 && point <= 125273 => PVALID
        | point when point >= 125274 && point <= 125277 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 125278 && point <= 125279 => FREEPVAL
        | point when point >= 125280 && point <= 126064 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 126539) {
      if (point < 126505) {
        if (point < 126496) {
          if (point < 126270) {
            if (point < 126133) {
              switch (point) {
              | point when point >= 126065 && point <= 126132 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 126133 && point <= 126208 => UNASSIGNED
              | point when point >= 126209 && point <= 126269 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 126468) {
            switch (point) {
            | point when point >= 126270 && point <= 126463 => UNASSIGNED
            | point when point >= 126464 && point <= 126467 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126468 && point <= 126468 => UNASSIGNED
            | point when point >= 126469 && point <= 126495 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 126500) {
          if (point < 126497) {
            switch (point) {
            | point when point >= 126496 && point <= 126496 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126497 && point <= 126498 => FREEPVAL
            | point when point >= 126499 && point <= 126499 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 126503) {
          switch (point) {
          | point when point >= 126500 && point <= 126500 => FREEPVAL
          | point when point >= 126501 && point <= 126502 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126503 && point <= 126503 => FREEPVAL
          | point when point >= 126504 && point <= 126504 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 126524) {
        if (point < 126520) {
          if (point < 126515) {
            switch (point) {
            | point when point >= 126505 && point <= 126514 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126515 && point <= 126515 => UNASSIGNED
            | point when point >= 126516 && point <= 126519 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 126522) {
          switch (point) {
          | point when point >= 126520 && point <= 126520 => UNASSIGNED
          | point when point >= 126521 && point <= 126521 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126522 && point <= 126522 => UNASSIGNED
          | point when point >= 126523 && point <= 126523 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 126535) {
        if (point < 126530) {
          switch (point) {
          | point when point >= 126524 && point <= 126529 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126530 && point <= 126530 => FREEPVAL
          | point when point >= 126531 && point <= 126534 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 126537) {
        switch (point) {
        | point when point >= 126535 && point <= 126535 => FREEPVAL
        | point when point >= 126536 && point <= 126536 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 126537 && point <= 126537 => FREEPVAL
        | point when point >= 126538 && point <= 126538 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 126557) {
      if (point < 126549) {
        if (point < 126544) {
          if (point < 126540) {
            switch (point) {
            | point when point >= 126539 && point <= 126539 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126540 && point <= 126540 => UNASSIGNED
            | point when point >= 126541 && point <= 126543 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 126547) {
          switch (point) {
          | point when point >= 126544 && point <= 126544 => UNASSIGNED
          | point when point >= 126545 && point <= 126546 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126547 && point <= 126547 => UNASSIGNED
          | point when point >= 126548 && point <= 126548 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 126553) {
        if (point < 126551) {
          switch (point) {
          | point when point >= 126549 && point <= 126550 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126551 && point <= 126551 => FREEPVAL
          | point when point >= 126552 && point <= 126552 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 126555) {
        switch (point) {
        | point when point >= 126553 && point <= 126553 => FREEPVAL
        | point when point >= 126554 && point <= 126554 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 126555 && point <= 126555 => FREEPVAL
        | point when point >= 126556 && point <= 126556 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 126565) {
      if (point < 126560) {
        if (point < 126558) {
          switch (point) {
          | point when point >= 126557 && point <= 126557 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126558 && point <= 126558 => UNASSIGNED
          | point when point >= 126559 && point <= 126559 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 126563) {
        switch (point) {
        | point when point >= 126560 && point <= 126560 => UNASSIGNED
        | point when point >= 126561 && point <= 126562 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 126563 && point <= 126563 => UNASSIGNED
        | point when point >= 126564 && point <= 126564 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 126572) {
      if (point < 126567) {
        switch (point) {
        | point when point >= 126565 && point <= 126566 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 126567 && point <= 126570 => FREEPVAL
        | point when point >= 126571 && point <= 126571 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 126580) {
      switch (point) {
      | point when point >= 126572 && point <= 126578 => FREEPVAL
      | point when point >= 126579 && point <= 126579 => UNASSIGNED
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 126580 && point <= 126583 => FREEPVAL
      | point when point >= 126584 && point <= 126584 => UNASSIGNED
      | _point => DISALLOWED
      };
    };
  } else if (point < 129004) {
    if (point < 127222) {
      if (point < 126652) {
        if (point < 126603) {
          if (point < 126591) {
            if (point < 126589) {
              switch (point) {
              | point when point >= 126585 && point <= 126588 => FREEPVAL
              | _point => DISALLOWED
              };
            } else {
              switch (point) {
              | point when point >= 126589 && point <= 126589 => UNASSIGNED
              | point when point >= 126590 && point <= 126590 => FREEPVAL
              | _point => DISALLOWED
              };
            };
          } else if (point < 126592) {
            switch (point) {
            | point when point >= 126591 && point <= 126591 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126592 && point <= 126601 => FREEPVAL
            | point when point >= 126602 && point <= 126602 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 126628) {
          if (point < 126620) {
            switch (point) {
            | point when point >= 126603 && point <= 126619 => FREEPVAL
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126620 && point <= 126624 => UNASSIGNED
            | point when point >= 126625 && point <= 126627 => FREEPVAL
            | _point => DISALLOWED
            };
          };
        } else if (point < 126634) {
          switch (point) {
          | point when point >= 126628 && point <= 126628 => UNASSIGNED
          | point when point >= 126629 && point <= 126633 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 126634 && point <= 126634 => UNASSIGNED
          | point when point >= 126635 && point <= 126651 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 127136) {
        if (point < 126976) {
          if (point < 126704) {
            switch (point) {
            | point when point >= 126652 && point <= 126703 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 126704 && point <= 126705 => FREEPVAL
            | point when point >= 126706 && point <= 126975 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 127024) {
          switch (point) {
          | point when point >= 126976 && point <= 127019 => FREEPVAL
          | point when point >= 127020 && point <= 127023 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 127024 && point <= 127123 => FREEPVAL
          | point when point >= 127124 && point <= 127135 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 127168) {
        if (point < 127151) {
          switch (point) {
          | point when point >= 127136 && point <= 127150 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 127151 && point <= 127152 => UNASSIGNED
          | point when point >= 127153 && point <= 127167 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 127184) {
        switch (point) {
        | point when point >= 127168 && point <= 127168 => UNASSIGNED
        | point when point >= 127169 && point <= 127183 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 127184 && point <= 127184 => UNASSIGNED
        | point when point >= 127185 && point <= 127221 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 127570) {
      if (point < 127462) {
        if (point < 127248) {
          if (point < 127232) {
            switch (point) {
            | point when point >= 127222 && point <= 127231 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 127232 && point <= 127244 => FREEPVAL
            | point when point >= 127245 && point <= 127247 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 127344) {
          switch (point) {
          | point when point >= 127248 && point <= 127340 => FREEPVAL
          | point when point >= 127341 && point <= 127343 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 127344 && point <= 127404 => FREEPVAL
          | point when point >= 127405 && point <= 127461 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 127548) {
        if (point < 127491) {
          switch (point) {
          | point when point >= 127462 && point <= 127490 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 127491 && point <= 127503 => UNASSIGNED
          | point when point >= 127504 && point <= 127547 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 127561) {
        switch (point) {
        | point when point >= 127548 && point <= 127551 => UNASSIGNED
        | point when point >= 127552 && point <= 127560 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 127561 && point <= 127567 => UNASSIGNED
        | point when point >= 127568 && point <= 127569 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 128752) {
      if (point < 127744) {
        if (point < 127584) {
          switch (point) {
          | point when point >= 127570 && point <= 127583 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 127584 && point <= 127589 => FREEPVAL
          | point when point >= 127590 && point <= 127743 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 128736) {
        switch (point) {
        | point when point >= 127744 && point <= 128725 => FREEPVAL
        | point when point >= 128726 && point <= 128735 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 128736 && point <= 128748 => FREEPVAL
        | point when point >= 128749 && point <= 128751 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 128884) {
      if (point < 128763) {
        switch (point) {
        | point when point >= 128752 && point <= 128762 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 128763 && point <= 128767 => UNASSIGNED
        | point when point >= 128768 && point <= 128883 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 128985) {
      switch (point) {
      | point when point >= 128884 && point <= 128895 => UNASSIGNED
      | point when point >= 128896 && point <= 128984 => FREEPVAL
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 128985 && point <= 128991 => UNASSIGNED
      | point when point >= 128992 && point <= 129003 => FREEPVAL
      | _point => DISALLOWED
      };
    };
  } else if (point < 129652) {
    if (point < 129394) {
      if (point < 129120) {
        if (point < 129040) {
          if (point < 129024) {
            switch (point) {
            | point when point >= 129004 && point <= 129023 => UNASSIGNED
            | _point => DISALLOWED
            };
          } else {
            switch (point) {
            | point when point >= 129024 && point <= 129035 => FREEPVAL
            | point when point >= 129036 && point <= 129039 => UNASSIGNED
            | _point => DISALLOWED
            };
          };
        } else if (point < 129104) {
          switch (point) {
          | point when point >= 129040 && point <= 129095 => FREEPVAL
          | point when point >= 129096 && point <= 129103 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 129104 && point <= 129113 => FREEPVAL
          | point when point >= 129114 && point <= 129119 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 129198) {
        if (point < 129160) {
          switch (point) {
          | point when point >= 129120 && point <= 129159 => FREEPVAL
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 129160 && point <= 129167 => UNASSIGNED
          | point when point >= 129168 && point <= 129197 => FREEPVAL
          | _point => DISALLOWED
          };
        };
      } else if (point < 129292) {
        switch (point) {
        | point when point >= 129198 && point <= 129279 => UNASSIGNED
        | point when point >= 129280 && point <= 129291 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 129292 && point <= 129292 => UNASSIGNED
        | point when point >= 129293 && point <= 129393 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 129454) {
      if (point < 129402) {
        if (point < 129395) {
          switch (point) {
          | point when point >= 129394 && point <= 129394 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 129395 && point <= 129398 => FREEPVAL
          | point when point >= 129399 && point <= 129401 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 129445) {
        switch (point) {
        | point when point >= 129402 && point <= 129442 => FREEPVAL
        | point when point >= 129443 && point <= 129444 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 129445 && point <= 129450 => FREEPVAL
        | point when point >= 129451 && point <= 129453 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 129620) {
      if (point < 129483) {
        switch (point) {
        | point when point >= 129454 && point <= 129482 => FREEPVAL
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 129483 && point <= 129484 => UNASSIGNED
        | point when point >= 129485 && point <= 129619 => FREEPVAL
        | _point => DISALLOWED
        };
      };
    } else if (point < 129646) {
      switch (point) {
      | point when point >= 129620 && point <= 129631 => UNASSIGNED
      | point when point >= 129632 && point <= 129645 => FREEPVAL
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 129646 && point <= 129647 => UNASSIGNED
      | point when point >= 129648 && point <= 129651 => FREEPVAL
      | _point => DISALLOWED
      };
    };
  } else if (point < 183970) {
    if (point < 131072) {
      if (point < 129664) {
        if (point < 129656) {
          switch (point) {
          | point when point >= 129652 && point <= 129655 => UNASSIGNED
          | _point => DISALLOWED
          };
        } else {
          switch (point) {
          | point when point >= 129656 && point <= 129658 => FREEPVAL
          | point when point >= 129659 && point <= 129663 => UNASSIGNED
          | _point => DISALLOWED
          };
        };
      } else if (point < 129680) {
        switch (point) {
        | point when point >= 129664 && point <= 129666 => FREEPVAL
        | point when point >= 129667 && point <= 129679 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 129680 && point <= 129685 => FREEPVAL
        | point when point >= 129686 && point <= 131071 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 177973) {
      if (point < 173783) {
        switch (point) {
        | point when point >= 131072 && point <= 173782 => PVALID
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 173783 && point <= 173823 => UNASSIGNED
        | point when point >= 173824 && point <= 177972 => PVALID
        | _point => DISALLOWED
        };
      };
    } else if (point < 178206) {
      switch (point) {
      | point when point >= 177973 && point <= 177983 => UNASSIGNED
      | point when point >= 177984 && point <= 178205 => PVALID
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 178206 && point <= 178207 => UNASSIGNED
      | point when point >= 178208 && point <= 183969 => PVALID
      | _point => DISALLOWED
      };
    };
  } else if (point < 917536) {
    if (point < 194560) {
      if (point < 183984) {
        switch (point) {
        | point when point >= 183970 && point <= 183983 => UNASSIGNED
        | _point => DISALLOWED
        };
      } else {
        switch (point) {
        | point when point >= 183984 && point <= 191456 => PVALID
        | point when point >= 191457 && point <= 194559 => UNASSIGNED
        | _point => DISALLOWED
        };
      };
    } else if (point < 917505) {
      switch (point) {
      | point when point >= 194560 && point <= 195101 => PVALID
      | point when point >= 195102 && point <= 917504 => UNASSIGNED
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 917505 && point <= 917505 => DISALLOWED
      | point when point >= 917506 && point <= 917535 => UNASSIGNED
      | _point => DISALLOWED
      };
    };
  } else if (point < 918000) {
    if (point < 917632) {
      switch (point) {
      | point when point >= 917536 && point <= 917631 => DISALLOWED
      | _point => DISALLOWED
      };
    } else {
      switch (point) {
      | point when point >= 917632 && point <= 917759 => UNASSIGNED
      | point when point >= 917760 && point <= 917999 => DISALLOWED
      | _point => DISALLOWED
      };
    };
  } else if (point < 1048574) {
    switch (point) {
    | point when point >= 918000 && point <= 983039 => UNASSIGNED
    | point when point >= 983040 && point <= 1048573 => DISALLOWED
    | _point => DISALLOWED
    };
  } else {
    switch (point) {
    | point when point >= 1048574 && point <= 1048575 => UNASSIGNED
    | point when point >= 1048576 && point <= 1114109 => DISALLOWED
    | _point => DISALLOWED
    };
  };
