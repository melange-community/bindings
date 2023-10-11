# bs-swr
BuckleScript bindings to [SWR](https://github.com/zeit/swr).

## Installation
Add
```
"@roddynpm/bs-swr": "^0.2.5",
"swr": "^0.2.0",
```
as dependencies to `package.json` and `@roddynpm/bs-swr` to `bsconfig.json`.

## Example
```reason
[@react.component]
let make = () => {
  let config = Swr.Options.make(~dedupingInterval=6000, ());
  let Swr.{data} = Swr.useSWR(~config, "key", _ => load_data());

  switch (data) {
  | Some(data) => render(data)
  | None => render_loading()
  };
};
```
