# rescript-ava

Runtime free [ReScript](https://github.com/rescript-lang) bindings for [Ava](https://github.com/avajs/ava)

## Usage

### Installation

```sh
npm install -D @dzakh/rescript-ava ava@5.2.x
```

Then add `@dzakh/rescript-ava` to `bs-dev-dependencies` in your `bsconfig.json`:

```diff
{
  ...
+ "bs-dev-dependencies": ["@dzakh/rescript-ava"]
}
```

Then add `__tests__` to `sources` in your `bsconfig.json`:

```diff
"sources": [
  {
    "dir": "src"
  },
+ {
+   "dir": "__tests__",
+   "type": "dev"
+ }
]
```

Then add `test` script and minimalistic configuration in your `package.json`:

```diff
{
  "name": "awesome-package",
  "scripts": {
+   "test": "ava"
  },
  "devDependencies": {
    "@dzakh/rescript-ava": "1.0.0"
  },
+ "ava": {
+   "files": [
+     "__tests__/**/*_test.mjs",
+     "__tests__/**/*_test.bs.js"
+   ]
+ }
}
```

### Create your test file

Create a test file in the **tests** directory and use the suffix `*_test.res`. When compiled they will be put in a **tests** directory with a `*_test.bs.js` suffix, ready to be picked up when you run ava. If you're not already familiar with [Ava](https://github.com/avajs/ava), see [the Ava documentation](https://github.com/avajs/ava#documentation).

```res
// __tests__/Main_test.res
open Ava

test("foo", t => {
  t->Assert.pass()
})

asyncTest("bar", t => {
  Promise.resolve("bar")->Promise.thenResolve(bar => {
    t->Assert.is(bar, "bar", ())
  })
})

```

### Running your tests

```sh
npm test
```

Or with npx:

```sh
npx ava
```

Run with the --watch flag to enable AVA's [watch mode](https://github.com/avajs/ava/blob/main/docs/recipes/watch-mode.md):

```sh
npx ava --watch
```

## Documentation

For the moment, please refer to [Ava.res](./src/Ava.res).

## Examples

Open source projects using **rescript-ava**:

- [rescript-struct](https://github.com/DZakh/rescript-struct) - A simple and composable way to describe relationship between JavaScript and ReScript structures
- [rescript-envsafe](https://github.com/DZakh/rescript-envsafe) - Makes sure you don't accidentally deploy apps with missing or invalid environment variables
- [rescript-json-schema](https://github.com/DZakh/rescript-json-schema) - Typesafe JSON schema for ReScript
