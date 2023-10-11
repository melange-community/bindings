[![NPM](https://nodei.co/npm/bs-mysql2.png)](https://nodei.co/npm/bs-mysql2/)
[![Build Status](https://travis-ci.org/scull7/bs-mysql2.svg?branch=master)](https://travis-ci.org/scull7/bs-mysql2)
[![Coverage Status](https://coveralls.io/repos/github/scull7/bs-mysql2/badge.svg)](https://coveralls.io/github/scull7/bs-mysql2)

# bs-mysql2

ReasonML bindings to the [mysql2] library.

This is a very rough implementation that will enable very simple use cases.

Initially this was just a copy of [bs-mysql].

## Why?

The main difference between these bindings and the [bs-mysql] bindings is the
use of the [mysql2] library / driver over the [mysql] (version 1) driver. You
can see the reasoning behind the new [mysql2] driver here:
[History and Why MySQL2][mysql2-features]

### Version 2

Version 2 of this driver removed most of the API surface area. This is now
intended as a module which better interfaces are built on top of, yet it still
quite usable.

However, if you are looking for a higher level interface then you should look
at the [bs-sql-common] library. This library can be used along side
[bs-sql-common] as a data provider.

## Status

Not all of the [mysql2] library [features][mysql2-features] are implemented but
there is a usable implementation of the [Promise based wrapper](#promise-interface)
and [Named Placeholders](#named-placeholders).

- [x] Faster / Better Performance (_kind of get this for free_)
- [x] [Prepared Statements][mysql2-prepared-statements] - [examples](#prepared-statements)
- [ ] MySQL Binary Log Protocol
- [ ] [MySQL Server][mysql2-server]
- [ ] Extended support for Encoding and Collation
- [ ] [Promise Wrapper][mysql2-promise] - [examples](#promise-interface)
- [ ] Compression
- [ ] SSL and [Authentication Switch][mysql2-auth-switch]
- [ ] [Custom Streams][mysql2-custom-streams]
- [ ] Pooling

**_NOTE:_** If you're trying to run the tests on macOS then you will need to:
` brew install watchman`

## Usage

### Standard Callback Interface

#### Standard Query Method

```reason
let conn
  = MySql2.Connection.connect(~host=127.0.0.1, ~port=3306, ~user="root", ());

MySql2.execute(conn, "SHOW DATABASES", None, res => {
    switch res {
    | `Error(e) => Js.log2("ERROR: ", e)
    | `Select(select) => Js.log2("SELECT: ", select)
    | `Mutation(mutation) => Js.log2("MUTATION: ", mutation)
    }
  MySql2.close(conn);
});

```

#### Prepared Statements

##### Named Placeholders

```reason
let conn
  = MySql2.Connect.connect(~host=127.0.0.1, ~port=3306, ~user="root", ());

let named = MySql2.Params.named(
  Json.Encode.object_([
    ("x", Json.Encode.int(1)),
    ("y", Json.Encode.int(2)),
  ])
);

MySql2.execute(conn, "SELECT :x + :y AS result", Some(named), res => {
    switch res {
    | `Error(e) => Js.log2("ERROR: ", e)
    | `Select(select) => Js.log2("SELECT: ", select)
    | `Mutation(mutation) => Js.log2("MUTATION: ", mutation)
    }
  }
  MySql2.close(conn);
});
```

##### Unnamed Placeholders

```reason
let conn
  = MySql2.Connection.connect(~host=127.0.0.1, ~port=3306, ~user="root", ());

let positional = MySql2.Params.positional(
  Belt_Array.map([|5, 6|], Json.Encode.int) |> Json.Encode.jsonArray
);

MySql2.execute(conn, "SELECT 1 + ? + ? AS result", Some(positional), res => {
    switch res {
    | `Error(e) => Js.log2("ERROR: ", e)
    | `Select(rows, meta) => Js.log2("SELECT: ", rows, meta)
    | `Mutation(count, id) => Js.log2("MUTATION: ", count, id)
    }
  }
  MySql2.close(conn);
});
```

## How do I install it?

Inside of a BuckleScript project:

```shell
yarn install --save bs-mysql2 @glennsl/bs-json
```

Then add `bs-mysql2` and `@glennsl/bs-json` to your `bs-dependencies` in `bsconfig.json`:

```json
{
  "bs-dependencies": ["bs-mysql2", "@glennsl/bs-json"]
}
```

## How do I use it?

`bs-mysql2` examples assume that there is:

- a datatabase named test inside mysql: create it by running `create database test`
- you are using `mysql_native_password` as authentication for the root user
  - see https://stackoverflow.com/questions/50093144/mysql-8-0-client-does-not-support-authentication-protocol-requested-by-server

### Use it in your project

See the [Usage](#usage) section above...

### Run the examples

```shell
yarn run examples:simple
```

```shell
yarn run examples:prepared-statements
```

## What's missing?

Mostly everything...

[bs-mysql]: https://github.com/davidgomes/bs-mysql
[bs-sql-common]: https://github.com/scull7/bs-sql-common
[mysql]: https://www.npmjs.com/package/mysql
[mysql2]: https://www.npmjs.com/package/mysql2
[mysql2-features]: https://github.com/sidorares/node-mysql2#history-and-why-mysql2
[mysql2-prepared-statements]: https://github.com/sidorares/node-mysql2/tree/master/documentation/Prepared-Statements.md
[mysql2-server]: https://github.com/sidorares/node-mysql2/tree/master/documentation/MySQL-Server.md
[mysql2-promise]: https://github.com/sidorares/node-mysql2/tree/master/documentation/Promise-Wrapper.md
[mysql2-auth-switch]: https://github.com/sidorares/node-mysql2/tree/master/documentation/Authentication-Switch.md
[mysql2-custom-streams]: https://github.com/sidorares/node-mysql2/tree/master/documentation/Extras.md
