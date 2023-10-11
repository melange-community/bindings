# ReScript-Blossom 🌺

![GitHub package.json version](https://img.shields.io/github/package-json/v/johnridesabike/rescript-blossom)
![Node.js CI](https://github.com/johnridesabike/rescript-blossom/workflows/Node.js%20CI/badge.svg)
![GitHub](https://img.shields.io/github/license/johnridesabike/rescript-blossom)

ReScript-Blossom is a [ReScript](https://rescript-lang.org/) implementation of the
famous [blossom algorithm](https://en.wikipedia.org/wiki/Blossom_algorithm). It
finds a maximum matching of vertices on general, undirected, weighted graphs.

**[📖 Read the documentation](https://johnridesa.bike/rescript-blossom/)**

## Installation

You can add ReScript-Blossom to your project by running:
```sh
npm install rescript-blossom
```

You will need to edit your project's `bsconfig.json` file and list
ReScript-Blossom in the `bs-dependencies`.
```json
{
  "bs-dependencies": [
    "rescript-blossom"
  ]
}
```

## Development

Download the code:
```sh
git clone https://github.com/johnridesabike/rescript-blossom.git
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

Run the ReScript watcher.
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

This code uses many terms and ideas from
["Efficient algorithms for finding maximum matching in graphs" by Zvi Galil, *ACM Computing Surveys*, 1986](https://doi.org/10.1145/6462.6502).
Reading the paper will make this code much more understandable.

