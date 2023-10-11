## Precis Generation

Using the file from [precis-table](https://github.com/NineFX/smeagol/blob/master/spec/code_gen/precis_cp.txt), the script `precis-ranges.py` can generate ReasonML code for pattern matching our Precis spec.

To run,

`.../precis-ranges.py`

To insert into file, first make sure `precis_cp.txt` is in the same directory. Then run the snippet below.

```
echo """
type precisTypes =
  | CONTEXTO
  | CONTEXTJ
  | PVALID
  | UNASSIGNED
  | FREEPVAL
  | DISALLOWED;
let fromCodePoint = x =>
""" > somefile.re;
./precis-ranges.py >> somefile.re;
echo ";" >> somefile.re;
```
