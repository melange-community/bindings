# Lowercase/Casefold Generation Code

All the unicode case folding and lowercase maps are located in `unicodedata.txt`. Using those maps, this generates the ReasonML for casefold/lowercase.

```
./lowercase-gen.py >> ../src/PrecisMapping.re
```
