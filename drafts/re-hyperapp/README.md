# Hyperapp Reason Bindings (WIP)

Very raw bindings for the
[Hyperapp](https://github.com/hyperapp/hyperapp) UI library.

## Setup

You'll need to do the following one-time setup:

_Either_ install globally (my preference):

    cd re-hyperapp
    npm i -g bs-platform
    npm link bs-platform

_Or_ install locally:

    cd re-hyperapp
    npm i bs-platform

_Then,_ install ParcelJS: `npm i -g parcel`

Finally, run the normal install: `npm i`

## Build

Full BuckleScript build: `bsb -make-world`

Incremental and watch for changes (but you probably don't need this if
you've set your editor to
[compile on save](https://twitter.com/yawaramin/status/962894993537970176)):
`bsb -w`

Bundle and watch for changes: `npm run serve`

Production bundle: `npm run build`

# Run

Go to http://localhost:1234
