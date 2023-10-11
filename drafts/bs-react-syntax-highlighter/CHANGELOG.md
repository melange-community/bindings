# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [0.3.0](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.2.2...v0.3.0) (2020-09-22)


### ⚠ BREAKING CHANGES

* **bindings:** rows and children are now Arrays, not lists.
* **api:** JSX 2 version removed,
as bs-platform@8 doesn't support it anymore

* **api:** get rid of JSX 2 version ([251247f](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/251247fdd80c4c18d05d62f1393cdcc2f0f739ab))
* **bindings:** replace list with array ([b8357fe](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/b8357fe65e5f675d7e9be9f8e0b8a400a2b493fd))

### [0.2.2](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.2.1...v0.2.2) (2020-05-26)

### [0.2.1](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.2.0...v0.2.1) (2020-01-25)


### Bug Fixes

* **api:** type *Tag properties properly ([4ac3f1f](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/4ac3f1f2e84b5c018b93c5070111924df39395d3))

## [0.2.0](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.1.1...v0.2.0) (2020-01-04)


### ⚠ BREAKING CHANGES

* **api:** `lineProps` accepts polymorphic variant instead of `ReactDOMRe.props` type

Change the existing code as follows:

```diff
-let props = ReactDOMRe.props(~className="foobar", ());
+let props = `Plain( ReactDOMRe.props(~className="foobar", ()) );

<ReactSyntaxHighlighter.Prism lineProps={props}>
  {"foobar"}
</ReactSyntaxHighlighter.Prism>
```

### Features

* **api:** add support for defining `lineProps` as a function ([6b38614](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/6b3861467fe2e14dc910220a142b57135c5a522c))

### [0.1.1](https://github.com/erykpiast/bs-react-syntax-highlighter/compare/v0.1.0...v0.1.1) (2020-01-01)


### Bug Fixes

* **lint:** change letter case for excluded word ([b5f6695](https://github.com/erykpiast/bs-react-syntax-highlighter/commit/b5f6695b2a4bc347d2711dcab2a77e52ce4d9c60))

## 0.1.0 (2020-01-01)

Initial release.

# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.
