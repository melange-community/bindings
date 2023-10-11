# Precis Generation Code

All of these will take in the `unicode.txt` that is zip archived in the repository as `unicodedata.zip`. All scripts need to be run from inside the `precis-gen` folder. And all output to `stdout`.

An example of a script being run would look as,

```bash
pushd ./precis-gen/
  ./bidi-gen.py > ../src/PrecisBidi.re
popd
```

Most of these do need to be modified by hand after.

## Files
* [bidi-gen.py](./bidi-gen.md)
* [generate-json-tests.py](./generate-json-tests.md)
* [lowercase-gen.py](./lowercase-gen.md)
* [precis-ranges.py](./precis-ranges.md)
