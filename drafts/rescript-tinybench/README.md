# rescript-tinybench

ReScript bindings to [tinybench](https://github.com/tinylibs/tinybench)

## Usage

```res
open RescriptCore
open RescriptTinybench

let bench =
  Bench.make(~time=100.0, ())
  ->Bench.add("switch 1", () => {
    let a = ref(1)
    let b = ref(2)
    let c = a.contents
    a := b.contents
    b := c
  })
  ->Bench.add("switch 2", () => {
    let a = ref(1)
    let b = ref(10)
    a := b.contents + a.contents
    b := a.contents - b.contents
    a := b.contents - a.contents
  })

await bench.run(.)
bench.table(.)->Console.table
```

## LICENSE

MIT
