# Telefonnummer

[![](https://github.com/opendevtools/rescript-telefonnummer/workflows/Release/badge.svg)](https://github.com/opendevtools/rescript-telefonnummer/actions?workflow=Release)
[![npm (scoped)](https://img.shields.io/npm/v/@opendevtools/rescript-telefonnummer)](https://npm.im/@opendevtools/rescript-telefonnummer)

This is a port of my library [telefonnummer](https://github.com/believer/telefonnummer) to ReasonML. It parses Swedish phone numbers into a standard format. It doesn't contain the full API of the original library as I felt it would be a good opportunity to start fresh.

## Installation

```
npm install @opendevtools/rescript-telefonnummer
```

Add `@opendevtools/rescript-telefonnummer` in `bs-dependencies` of `bsconfig.json`

## API

### parse

Takes a phone number of any kind and parses it to a standard format

```reason
let parse: string => string
```

#### Example

```reason
let parsedPhoneNumber = Telefonnummer.parse("081234567") /* 08-123 45 67 */
let parsedMobileNumber = Telefonnummer.parse("0701234567") /* 070-123 45 67 */
```

### typeOfNumber

Takes a phone number and returns the type. Usable for pattern-matching.

```reason
type t =
  | VoiceMail
  | Mobile
  | Landline

let typeOfNumber: string => t
```

#### Example

```reason
let phoneNumberType = Telefonnummer.typeOfNumber("081234567") /* Landline */
```

### Normalize

The `Normalize` module is exposed publically if you need to clean up a phone number for use in for example `tel:` links.

```reason
module Normalize = {
  let clean: string => string
}
```

#### Example

```reason
let cleanPhoneNumber = Telefonnummer.Normalize.clean("08-12 3 45.67") /* 081234567 */
```

### Validate

The `Validate` module can help you check if a phone number is valid. It cleans the phone number from any non-number characters.

```reason
module Validate = {
  let isValid: string => bool
}
```

#### Example

```reason
let isValid = Telefonnummer.Validate.isValid("08-12 3 45.67") /* true */
```

### Link

The `Link` module creates phone number links.

```reason
module Link = {
  let make: string => string
}
```

#### Example

```reason
let link = Telefonnummer.Link.make("08-12 3 45.67") /* tel:081234567 */
```
