# Clearingnummer

[![](https://github.com/opendevtools/rescript-clearingnummer/workflows/Release/badge.svg)](https://github.com/opendevtools/rescript-clearingnummer/actions?workflow=Release)
[![npm (scoped)](https://img.shields.io/npm/v/@opendevtools/rescript-clearingnummer)](https://npm.im/@opendevtools/rescript-clearingnummer)

Sort codes, _clearingnummer_ in Swedish, are four or five digit identifiers for Swedish banks. This package helps you find the bank related to a specific number. All clearing numbers are taken from [Wikipedia](http://www.wikiwand.com/sv/Lista_%C3%B6ver_clearingnummer_till_svenska_banker) and [Swedish Bankers Association](http://www.swedishbankers.se/media/3535/1710_clearingnummer-institut.pdf).

This is a semi-port of my JavaScript library [Clearingnummer](https://github.com/opendevtools/clearingnummer) written completely in Reason.

## Installation

```bash
npm install @opendevtools/rescript-clearingnummer
```

Add `@opendevtools/rescript-clearingnummer` to `bs-dependencies` in `bsconfig.json`

## Modules

### BankName

#### fromInt

Takes a clearing number as `int`. This is the most common format.

```ocaml
(* int => string *)
let bankName = Clearingnummer.BankName.fromInt(5202)
(* bankName = "SEB" *)
```

#### fromString

Used by Swedbank and their old bank names (sparbanker)

```ocaml
(* string => string *)
let bankName = Clearingnummer.BankName.fromString("8060-6")
(* bankName = "Swedbank" *)
```

### Banks

#### all

```ocaml
(* array(string) *)
let banks = Clearingnummer.Banks.all
(* banks = ["Amfa Bank", "Avanza Bank", ...] *)
```

## Tests

Build JavaScript files first using `npm run build` or `npm run start`

```bash
$ npm test
```
