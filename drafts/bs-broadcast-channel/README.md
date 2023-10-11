# bs-broadcast-channel
> ReasonML bindings for Broadcast Channel

[![NPM](https://img.shields.io/npm/v/bs-broadcast-channel.svg)](https://www.npmjs.com/package/bs-broadcast-channel)

## Install

npm
```bash
npm i --save bs-broadcast-channel
```

yarn
```bash
yarn add bs-broadcast-channel
```

After installing, add it to the dependencies

bsconfig.json
```json
{
  "bs-dependencies": [
    "bs-broadcast-channel",
  ],
}
```

## Usage

```reason
open BsBroadcastChannel;

/**
 * Create a channel
 */

let channel = BroadcastChannel.make("My app");

/**
 * Listen to messages
 */
channel->BroadcastChannel.addEventListener("message", (data: MessageEvent.t) => {
  /**
   *  get our data
   */
  Js.log(data->MessageEvent.data);
});

/**
 * Post message
 */
channel->BroadcastChannel.postMessage("Hello World");

/**
 * Close our channel
 */
channel->BroadcastChannel.close();
```

## License

MIT © [lxsmnsyc](https://github.com/lxsmnsyc)