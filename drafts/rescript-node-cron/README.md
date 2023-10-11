# rescript-cron

[![NPM version](http://img.shields.io/npm/v/rescript-cron.svg)](https://www.npmjs.org/package/rescript-cron)
[![Build Status](https://travis-ci.org/mikaello/rescript-node-cron.svg?branch=master)](https://travis-ci.org/mikaello/rescript-node-cron)

Bindings for [node-cron](https://github.com/kelektiv/node-cron), a tool that
allows you to execute _something_ on a schedule. This is typically done using
the cron syntax:

```
*    *    *    *    *    *
┬    ┬    ┬    ┬    ┬    ┬
│    │    │    │    │    │
│    │    │    │    │    └ day of week (0 - 6, or sun - sat), 0 is Sunday
│    │    │    │    └───── month (0 - 11, or jan - dec)
│    │    │    └────────── day of month (1 - 31)
│    │    └─────────────── hour (0 - 23)
│    └──────────────────── minute (0 - 59)
└───────────────────────── second (0 - 59, OPTIONAL)
```

Learn more about the syntax at [crontab.guru](https://crontab.guru/) (NB it does
not have the seconds parameter and months start at 1 (this lib has 0-indexed
months)).

## Getting started

```
yarn add rescript-cron
```

Then add `rescript-cron` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "rescript-cron"
]
```

## Example

```reason
open RescriptCron

// Make a job that will fire every second when started
let job =
  CronJob.make(
    `CronString("* * * * * *"),
    _ => Js.log("Just doing my job"),
    (),
  );

// Firing every second, printing 'Just doing my job'
start(job);

let time =
  CronTime.make(`JsDate(Js.Date.fromString("2021-04-11T10:20:30Z")), ());

// setTime will stop the current job, and change when it will fire next
setTime(job, time);

// It will now fire once in april 2021
start(job);
```

[The tests](https://github.com/mikaello/rescript-node-cron/tree/master/__tests__)
have more examples of how to use these bindings.

## Contribute

- If you find bugs or want to improve this library, feel free to open an issue
  or PR.
- If you are upgrading any dependencies, please use yarn so `yarn.lock` is
  updated.
- Try to adhere to
  [Angular commit guidelines](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guideline).

## Alternatives

[_node-schedule_](https://github.com/node-schedule/node-schedule) is a JS
library similar to [_node-cron_](https://github.com/kelektiv/node-cron) (which
this library is bindings for).
