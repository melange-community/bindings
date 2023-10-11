# [Chess.js](https://github.com/jhlywa/chess.js) bindings for Bucklescript in Reason

Disclaimer: Work in progress

# Documentation
My hope is that the interface file
[Chess.rei](https://github.com/russelldmatt/bs-chess.js/blob/master/src/Chess.rei)
is sufficiently clear to serve as documentation.  Let me know if
that's not the case.

# Examples/Tests (needs more)
For right now, you can look at
[Test.re](https://github.com/russelldmatt/bs-chess.js/blob/master/src/Test.re)
for some examples/tests.  I'll try to make this better in the future.

# Quickstart

## To use this repo in your project:
```
# create your reason project.  Here is one way (but not the only way):
bsb -init my-chess-app -theme basic-reason && cd my-chess-app

# install this package
npm install --save russelldmatt/bs-chess.js

# Add this library to the bsconfig.json `bs-dependencies` section.
# It should look something like this: "bs-dependencies": [ "bs-chess.js"],
# (you have to do this manually)

# all the normal npm stuff
npm install && npm build && npm start

# edit src/Demo.re
# All the useful stuff exported from this library will be in the
# module BsChessjs.Chess.
```

## To get this repo working:
### Clone
```
git clone https://github.com/russelldmatt/bs-chess.js.git bs-chess.js
```

### Build
```
yarn install
yarn build
```

### Run with Node:
```
node src/Chess.bs.js
```

### Run in Browser (Works now thanks to @chenglou!):
```
yarn run webpack
open index.html
```
