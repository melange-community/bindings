# Bidi Generator
## precis-gen/bidi-gen.py

This script will generate the switch statement, and in `bidi-gen2.py` will create the binary search for a function that takes a codepoint, and turns it into a bidi type.

The Bidi types are from the Unicode spec, [Bidi Algorithm UAX-9](https://unicode.org/reports/tr9/). Precis requires some profiles to conform to certain standards in respect to Bidi.

```
./bidi-gen.py >> ../src/PrecisBidi.re
```
