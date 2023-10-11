# Changelog of `rescript-react-helmet`

## 4.0.0 - 2022-04-13

- Migrated to ReScript
- Renamed `rescript-react-helmet`

## 3.0.0 - 2020-06-11

- Bump react-helmet peer dependency to v6
- Bump reason-react to v0.8

No binding changes.

## 2.1.0 - 2019-04-15

- Improved htmlAttributes and meta types [#1](https://github.com/MoOx/rescript-react-helmet/pull/1) by @johnridesabike

## 2.0.0 - 2019-04-15

- Updated for reason-react 0.7 & bs-platform 5.0
- Add Helmet.renderStatic

## 1.1.3 - 2018-12-19

- Small internal refactoring to avoid `undefined` keys.
  Instead of an ugly raw JavaScript trick, we now rely on `[@bs.optional]`.

## 1.1.2 - 2018-12-18

- Fix missing `defer` type
- Avoid undefined props to be forwarded as JavaScript `undefined`.
  `react-helmet` actually checks keys and not values to override some values
  (eg: if 2 call are done too quickly with `title` set on the first one but
  not the other, this could omit the title by sending a undefined (ignored)
  value).

## 1.1.1 - 2018-12-17

- Fix missing `test` directory by flagging it as `dev`

## 1.1.0 - 2018-12-17

- Add support for `titleAttributes` prop
- Add support for `titleTemplate` prop
- Add support for `script` prop

## 1.0.0 - 2018-10-27

Initial release from [rescript-react-helmet](https://github.com/bguzryanto/rescript-react-helmet).
