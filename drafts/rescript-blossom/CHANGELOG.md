# ReScript-Blossom Changelog

## 3.0

- Replaced bs-platform package with rescript package.
- Removed rescript-logger.
- Changed license to the Mozilla Public License.

## 2.0

- Changed name to rescript-blossom
- Converted Reason to ReScript syntax.

## 1.1.1
- Improved documentation.

## 1.1
- Replaced `Belt.Id.comparable` with a custom `comparable` type.
- Added `Match.MakeComparable` and `Match.MakeComparableU` functors.
- Added `Match.comparable` and `Match.comparableU` functions.
- Added `Match.unsafeComparableFromBelt` and `Match.unsafeComparableFromBeltU`
  functions.
- `Match.make` no longer requires the `cmp` function separate from the `id`.
- Improved performance.
- Removed dependency on `Belt.List`.
- Added types `Match.String.t` and `Match.Int.t`.
- Updated documentation.

## 1.0.8

- Fixed a bug in the function that scans for potential blossoms.
- Cleaned up documentation.
- Updated dependencies.

## 1.0.7

- Updated the function that scans for potential blossoms. It is now more robust 
  and can handle more complex paths.
- Fixed a crash on some graphs.

## 1.0.6

- Fixed a crash on graphs with large blossoms.

## 1.0.5

- Fixed a crash on some graphs.

## 1.0.4

- Fixed a bug that allowed some duplicate edges.

## 1.0.3

- Fixed a crash on certain graphs.

## 1.0.2

- Added package description.

## 1.0.1

- Initial release.

