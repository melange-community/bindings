# bs-sonos

[![Build Status](https://travis-ci.com/believer/bs-sonos.svg?branch=master)](https://travis-ci.com/believer/bs-sonos)

BuckleScript bindings for [sonos](https://github.com/bencevans/node-sonos) used
to control one or more Sonos speakers.

## Example

```reason
open Methods;

/* Connect to a Sonos speaker using its IP */
let device = Device.make("192.168.0.1");

/* Queue a track and start playing it */
Js.Promise.(
  device->Queue.asLast("spotify:track:4fK6E2UywZTJIa5kWnCD6x")
  |> then_(_ => device->PlayerControl.play())
);
```

For all available methods, see [src/Methods.re](Methods) and for all response
parser see [src/Decode.re](Decode)

## Projects using bindings

Add yours if you are using the bindings

- [Wejay](https://github.com/Iteam1337/sonos-wejay/)
