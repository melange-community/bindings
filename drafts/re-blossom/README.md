# Re-Blossom 🌺

![GitHub package.json version](https://img.shields.io/github/package-json/v/johnridesabike/re-blossom)
![Node.js CI](https://github.com/johnridesabike/re-blossom/workflows/Node.js%20CI/badge.svg)
![GitHub](https://img.shields.io/github/license/johnridesabike/re-blossom)

Re-Blossom is a [Reason](https://reasonml.github.io/) implementation of the
famous [blossom algorithm](https://en.wikipedia.org/wiki/Blossom_algorithm). It
finds a maximum matching of vertices on general, undirected, weighted graphs.

**[📖 Read the documentation](https://johnridesa.bike/re-blossom/)**

## Notice

If you're using [ReScript](https://rescript-lang.org), check out
[ReScript-Blossom](https://github.com/johnridesabike/rescript-blossom). It's
the same algorithm, but optimized for a JavaScript environment.

This package originally had similar optimizations, but I've reworked it to be
more compatible with native-Reason. This package currently still relies on
`bs-platform` to compile to JavaScript, but that's only for testing. All of
the core modules should be native-compatible.

I'm not currently using this package in a native environment, so I haven't
fully converted it yet. If you think you will find this useful, I encourage
you to fork it and make the modifications you need.

## Installation

Re-Blossom requires [BuckleScript](https://bucklescript.github.io/) as a peer
dependency, so you will have to install it separately. Add it by running:
```sh
npm install bs-platform -D
```

You can add Re-Blossom to your project by running:
```sh
npm install re-blossom
```

You will need to edit your project's `bsconfig.json` file and list Re-Blossom in
the `bs-dependencies`.
```json
{
  "bs-dependencies": [
    "re-blossom"
  ]
}
```

## Development

Download the code:
```sh
git clone https://github.com/johnridesabike/re-blossom.git
```
If you want to make your own changes, then it's recommended to fork the
repository on GitHub and clone your forked version.

Install the dependencies:
```sh
npm install
```

Compile a production build:
```sh
npm run build
```

Run the Reason watcher (not necessary if your IDE automatically compiles
Reason):
```sh
npm run start
```

Run the tests:
```sh
npm run test
```

Run benchmarks that compare it to the similar JavaScript algorithm:
```sh
npm run bench
```

Run benchmarks in a browser:
```sh
npm run browser
```
Then open the URL provided and navigate to the `__benchmarks__` directory.

To turn on debug logging, enable [bs-log](https://github.com/MinimaHQ/bs-log)
with the `BS_LOG` environmental variable:
```sh
BS_LOG=re-blossom=* npm run build

# or with your editor

BS_LOG=re-blossom=* vim
```

When reading the code, you may need familiarity with BuckleScript's
[uncurrying](https://bucklescript.github.io/docs/en/function#solution-guaranteed-uncurrying),
as well as its map and set structures.

This code uses many terms and ideas from
["Efficient algorithms for finding maximum matching in graphs" by Zvi Galil, *ACM Computing Surveys*, 1986](https://doi.org/10.1145/6462.6502).
Reading the paper will make this code much more understandable.

