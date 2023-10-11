# :art: bs-canvas

BuckleScript bindings for [node-canvas](https://github.com/Automattic/node-canvas).

Currently, only bindings for the latest 1.x version are available.

:warning: _Not all bindings have been tested. If you find a problem please file an issue. PRs are also welcome!_ :warning:

# :memo: To Do
- Add bindings for node-canvas 2.0.0.
- Add interface file to hide internal functions.
- Add bindings for all possible forms of `toBuffer` function.
- Add binding for async `toDataURL`.
- Add data modes to the `Image` module.
- Set correct data types in the `ImageData` module instead of using `int` and `int64`.
- Add methods for gradient type.
- Add methods for pattern type.
- Prepare for publishing to redex.
- Add usage examples.
- Add tests.

# :hammer: Build
```
npm run build
```

# :eyeglasses: Build + Watch

```
npm run start
```


# :pencil2: Editor
If you use `vscode`, Press `Windows + Shift + B` it will build automatically
