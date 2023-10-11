# rescript-uuid

Rescript bindings for [uuid](https://www.npmjs.com/package/uuid)


# Install
```
yarn add uuid
yarn add -D rescript-uuid
```
Add it to your bsconfig.json
```
"bs-dependencies": [
    ...
    "rescript-uuid"
],
```

# Example

```re
let myNamespace = "1b671a64-40d5-491e-99b0-da01ff1f3341"

/**
 * Common functions
 */

let isValid = Uuid.validate(Uuid.V1.make())
let uuidParsed = Uuid.parse(Uuid.V1.make())
let uuidStringified = Uuid.stringify(uuidParsed)
let uuidVersion = Uuid.version(uuidStringified)

/**
 * UUID V1
 */
let uuidv1_1 = Uuid.V1.make()

let uuidv1_2 = Uuid.V1.makeWithOptions(~options=Uuid.V1.options(~clockseq=1, ()))

let uuidv1_3 = Uuid.V1.makeWithBuffer(
  ~options=Uuid.V1.options(~clockseq=1, ()),
  ~buffer=[1, 2, 3, 4],
  ~offset=0,
  (),
)

/**
 * UUID V3
 */
let uuidv3_DNS = Uuid.V3._DNS
let uuidv3_URL = Uuid.V3._URL

let uuidv3_1 = Uuid.V3.make(~name="google.com", ~namespace=#Uuid(myNamespace))
let uuidv3_2 = Uuid.V3.makeWithBuffer(
  ~name="google.com",
  ~namespace=#Uuid(myNamespace),
  ~buffer=[],
  ~offset=0,
  (),
)

/**
 * UUID V4
 */
let uuidv4_1 = Uuid.V4.make()
let uuidv4_2 = Uuid.V4.makeWithOptions(~options=Uuid.V4.options())
let uuidv4_3 = Uuid.V4.makeWithBuffer(~options=Uuid.V4.options(), ~buffer=[], ~offset=0, ())

/**
 * UUID V5
 */

let uuidv5_DNS = Uuid.V5._DNS
let uuidv5_URL = Uuid.V5._URL

let uuidv5_1 = Uuid.V5.make(~name="google.com", ~namespace=#Uuid(myNamespace))
let uuidv5_2 = Uuid.V5.makeWithBuffer(
  ~name="google.com",
  ~namespace=#Uuid(myNamespace),
  ~buffer=[],
  ~offset=0,
  (),
)
```