# rescript-contentful

[![npm](https://img.shields.io/npm/v/rescript-contentful?color=%23CC3534&logo=npm)](https://www.npmjs.com/package/rescript-contentful)
![npm](https://img.shields.io/npm/dm/rescript-contentful)

ReScript bindings (FFI) for [contentful.js](https://github.com/contentful/contentful.js), the JavaScript library for interacting with Contentful's Delivery API.

## Installation
Run `npm install rescript-contentful contentful`, and then update the `bs-dependencies` key in your `bsconfig.json` file to include "rescript-contentful".

## Usage
```rescript
open Contentful

// Create a Contentful client instance
let client = createClient({
  accessToken: "<ACCESS_TOKEN>",
  space: "<SPACE_ID>",
})

// Fetch an entry
// client is piped to the first
// argument of the function
client
->getEntry(id)
->Promise.then(entry => { /* do something */ })

// Fetch an asset
client
->getAsset(id, ())
->Promise.then(asset => { /* do something */ })
```

See [DOCUMENTATION.md](https://github.com/arafatamim/rescript-contentful/blob/main/DOCUMENTATION.md) for a more detailed outline of the API.

## License
MIT Licensed. Full text available in the [LICENSE](https://github.com/arafatamim/rescript-contentful/blob/main/LICENSE) file.
