## 3.1.0

Changes:

- Allow React 17 (00ed643)

## 3.0.0

Breaking Changes:

- Add `isReset` parameter to effect onSet callback ([https://github.com/barodeur](@barodeur)) (e35223f)
- Fix type signature for atom with effects ([https://github.com/barodeur](@barodeur)) (a74ac31)

Features:

- Add `DefaultValue` handler (f949f04)

## 2.1.1

Fixes:

- Add missing `atomWithDangerouslyAllowMutability` signature (this [https://github.com/searleser97](@searleser97)) (0ef742a)

## 2.1.0

Features:

- Add support `dangerouslyAllowMutability` (thanks [https://github.com/happylinks](@happylinks)!) (054cd23)

## 2.0.0

Changes:

- Update to ReScript (7ac9c88)

## 1.0.1

Changes:

- Allow higher versions of recoil (3b76965)

## 1.0.0

Changes:

- **Breaking**: Move from react-react to @rescript/react (1ae6f67)

## 0.11.2

Fixes:

- Better package description (9d9b1a1)

## 0.11.1

Fixes:

- Fixed `onSet` signature (Thanks [@happylinks](https://github.com/happylinks)) (42943b0)

## 0.11.0

**Breaking release**: The minimum version for `bs-platform` is now 8.2.0!

Features:

- Add effects support (f8d77c6)

Changes:

- Move to ReScript (f3d8d67)
- Rename project (6676938)

## 0.10.0

Features:

- Add uncurried callbacks (Thanks [@anmonteiro](https://github.com/anmonteiro)) (659360f)

Changes:

- Breaking change: use functional setters everywhere (Thanks [@anmonteiro](https://github.com/anmonteiro)) (bae86d4)
- Upgrade devDependency for ReasonReact (Thanks [@weslenng](https://github.com/weslenng)) (0abe847)


## 0.9.4

Features:

- Add `asyncSelectorFamilyWithWrite` (Thanks [@anmonteiro](https://github.com/anmonteiro)) (547f437)

## 0.9.3

Fixes:

- Add missing parameter to `selectorFamilyWithWrite` (673141f)

## 0.9.2

Features:

- Add `reset` to selectors with write `set` function (dcea387)

## 0.9.1

Features:

- Add support for waitForAll/waitForAny/waitForNone/noWait (caff6a7)

## 0.9.0

> Requires an upgrade to Recoil 0.0.10

Features:

- `atomFamily` and `selectorFamily` (bdf659d)
- Add `asyncAtom`, `atomFromRecoilValue`, `selectorFromRecoilValue` (bdf659d)

Changes:

- Update `useRecoilCallback` to reflect the new API (bdf659d)

## 0.8.0

Fixes:

- Fix `ReactRoot`'s `initializeState` (9f8e116)

## 0.7.0

Features:

- Add support for `useRecoilValueLoadable` (thanks @tatchi) (379a785)

## 0.6.0

Changes:

- Turn off namespacing for a simpler usage (057d9af)

## 0.5.2

Changes:

- Add uncurry declarations to callbacks (b358177)

## 0.5.1

Features:

- Add useRecoilCallback without dependencies too (eb20c61)

## 0.5.0

Features:

- Add useRecoilCallback (a11e13c)

Changes:

- Move recoil/react and all to peerDeps (e18a46c)

## 0.4.3

Changes:

- Simplify `RecoilRoot` signature (thanks @yawaramin) (41ecf96)

## 0.4.2

Changes:

- Use meaningful type parameters names (04dbd86)

Fixes:

- Fixed RecoilRoot signature (04dbd86)

## 0.4.1

Changes:

- Use a single variant for readOnly/readWrite (0ef7342)

## 0.4.0

Changes:

- Changed the `t` value type (thanks @anmonteiro) (394d247)

## 0.3.0

Features:

- Much better API that doesn't require `unboxed` (Thanks @tatchi!) (c8156f1)

## 0.2.2

Features:

- Add support for async selector (6e0a31b)

## 0.2.1

Fixes:

- Fixed a type-definition (0209746)

## 0.2.0

Features:

- Differentiale read-only from read-write values (22c4ddc)

## 0.1.1

Fixes:

- Fixed a definition in selectors bindings (f27e798)

## 0.1.0

Changes:

- Init project (d29d29f)
