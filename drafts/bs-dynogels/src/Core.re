type callback('a) = (Js.Nullable.t(Js.Exn.t), Js.Nullable.t('a)) => unit;

module Options = {
  type t;
  [@bs.set] external setPollingInterval : (t, int) => unit = "pollingInterval";
  [@bs.get] external getPollingInterval : t => int = "pollingInterval";
};

module StreamSpecification = {
  type t;
  [@bs.set] external setStreamEnabled : (t, bool) => unit = "streamEnabled";
  [@bs.get] external getStreamEnabled : t => bool = "streamEnabled";
  [@bs.set]
  external setStreamViewType : (t, string) => unit = "streamViewType";
  [@bs.get] external getStreamViewType : t => string = "streamViewType";
};

module TableOptions = {
  type t;
  [@bs.set] external setReadCapacity : (t, int) => unit = "readCapacity";
  [@bs.get] external getReadCapacity : t => int = "readCapacity";
  [@bs.set]
  external setStreamSpecificationy : (t, StreamSpecification.t) => unit =
    "streamSpecification";
  [@bs.get]
  external getStreamSpecificationy : t => StreamSpecification.t =
    "streamSpecification";
  [@bs.set] external setWriteCapacity : (t, int) => unit = "writeCapacity";
  [@bs.get] external getWriteCapacity : t => int = "writeCapacity";
};

module CreateTableOptions = {
  type t;
  [@bs.set] external setDynogelsOptions : (t, Options.t) => unit = "$dynogels";
  [@bs.get] external getDynogelsOptions : t => Options.t = "$dynogels";
  [@bs.set_index]
  external setTableOption : (t, string, TableOptions.t) => unit = "";
  [@bs.get_index] [@bs.return nullable]
  external getTableOption : (t, string) => option(TableOptions.t) = "";
};

type key = [ | `HashKey(string) | `RangeKey(string)];

type queryObject = Js.Dict.t(Js.Json.t);

module ValidatedResult = {
  type t;
  [@bs.get] [@bs.return nullable]
  external getError : t => option(Js.Exn.t) = "error";
  [@bs.get] [@bs.return nullable]
  external getValue : t => option(Js.Json.t) = "value";
};

module Schema = {
  type t;
  [@bs.send] external validate : (t, Js.Json.t) => ValidatedResult.t = "";
};

module TableSchema = {
  type t;
  [@bs.get] external getSchema : t => Schema.t = "schema";
};

module Item = {
  type t;
  [@bs.send] external destroy : (t, queryObject, callback(t)) => unit = "";
  [@bs.send] external get : (t, string) => Js.Nullable.t(Js.Json.t) = "";
  [@bs.send] external save : (t, callback(t)) => unit = "";
  [@bs.send] external set : (t, Js.Json.t) => t = "";
  [@bs.send] external toJSON : t => Js.Json.t = "";
  [@bs.send] external toPlainObject : t => Js.Json.t = "";
  [@bs.send] external update : (t, queryObject, callback(t)) => unit = "";
  [@bs.get] external getTable : t => TableSchema.t = "table";
};

module ConsumedCapacity = {
  type t;
  [@bs.get] external getCapacityUnits : t => int = "CapacityUnits";
  [@bs.get] external getTableName : t => string = "TableName";
};

module PaginatedRequest = {
  type t;
  [@bs.get]
  external getConsumedCapacity : t => ConsumedCapacity.t = "ConsumedCapacity";
  [@bs.get] external getCount : t => int = "Count";
  [@bs.get] external getItems : t => array(Item.t) = "Items";
  [@bs.get] [@bs.return nullable]
  external getLastEvaluatedKey : t => option(string) = "LastEvaluatedKey";
  [@bs.get] external getScannedCount : t => int = "ScannedCount";
};

module Condition = {
  type t;
  [@bs.set]
  external setAttributeNames : (t, Js.Dict.t(string)) => unit =
    "attributeNames";
  [@bs.get]
  external getAttributeNames : t => Js.Dict.t(string) = "attributeNames";
  [@bs.set]
  external setAttributeValues : (t, Js.Dict.t(string)) => unit =
    "attributeValues";
  [@bs.get]
  external getAttributeValues : t => Js.Dict.t(string) = "attributeValues";
  [@bs.set] external setStatement : (t, string) => unit = "statement";
  [@bs.get] external getStatement : t => string = "statement";
};

type query;

type queryFilter;

type queryWhere;

module Query = {
  type t = query;
  [@bs.send.pipe: t] external addFilterCondition : Condition.t => t = "";
  [@bs.send.pipe: t] external addKeyCondition : Condition.t => t = "";
  [@bs.send.pipe: t] external ascending : unit => t = "";
  [@bs.send.pipe: t] external attribute : string => t = "attributes";
  [@bs.send.pipe: t] external attributes : array(string) => t = "";
  [@bs.send.pipe: t] external buildKey : unit => string = "";
  [@bs.send.pipe: t] external buildRequest : unit => Js.Json.t = "";
  [@bs.send.pipe: t] external consistentRead : bool => t = "";
  [@bs.send.pipe: t] external descending : unit => t = "";
  [@bs.send.pipe: t]
  external exec : callback(PaginatedRequest.t) => unit = "";
  [@bs.send.pipe: t] external expressionAttributeNames : Js.Json.t => t = "";
  [@bs.send.pipe: t] external expressionAttributeValues : Js.Json.t => t = "";
  [@bs.send] external filter : string => queryFilter = "";
  [@bs.send.pipe: t] external filterExpression : string => t = "";
  [@bs.send.pipe: t] external limit : int => t = "";
  [@bs.send.pipe: t] external loadAll : unit => t = "";
  [@bs.send.pipe: t] external projectionExpression : string => t = "";
  [@bs.send.pipe: t] external returnConsumedCapacity : unit => t = "";
  [@bs.send.pipe: t]
  external returnConsumedCapacity__withValue : string => t =
    "returnConsumedCapacity";
  [@bs.send.pipe: t] external segments : (int, int) => t = "";
  [@bs.send.pipe: t] external select : string => t = "";
  [@bs.send.pipe: t] external startKey_ : string => t = "startKey";
  let startKey = (`HashKey(hashKey), query) => startKey_(hashKey, query);
  [@bs.send.pipe: t]
  external startKey_hashAndRangeKey_ : (string, string) => t = "startKey";
  let startKey_hashAndRangeKey =
      (`HashKey(hashKey), `RangeKey(rangeKey), query) =>
    startKey_hashAndRangeKey_(hashKey, rangeKey, query);
  [@bs.send.pipe: t] external usingIndex : string => t = "";
  [@bs.send.pipe: t] external where : string => queryWhere = "";
};

module QueryFilter = {
  type t = queryFilter;
  [@bs.send] external beginsWith : (t, Js.Json.t) => query = "";
  [@bs.send] external between : (t, Js.Json.t) => query = "";
  [@bs.send] external contains : (t, Js.Json.t) => query = "";
  [@bs.send] external eq : (t, Js.Json.t) => query = "";
  [@bs.send] external equals : (t, Js.Json.t) => query = "";
  [@bs.send] external exists : (t, Js.Json.t) => query = "";
  [@bs.send] external gt : (t, Js.Json.t) => query = "";
  [@bs.send] external gte : (t, Js.Json.t) => query = "";
  [@bs.send] external in_ : (t, Js.Json.t) => query = "in";
  [@bs.send] external lt : (t, Js.Json.t) => query = "";
  [@bs.send] external lte : (t, Js.Json.t) => query = "";
  [@bs.send] external ne : (t, Js.Json.t) => query = "";
  [@bs.send] external notContains : (t, Js.Json.t) => query = "";
  [@bs.send] external null : (t, Js.Json.t) => query = "";
};

module QueryWhere = {
  type t = queryWhere;
  [@bs.send.pipe: t] external beginsWith : Js.Json.t => query = "";
  [@bs.send.pipe: t] external between : Js.Json.t => query = "";
  [@bs.send.pipe: t] external eq : Js.Json.t => query = "";
  [@bs.send.pipe: t] external equals : Js.Json.t => query = "";
  [@bs.send.pipe: t] external gt : Js.Json.t => query = "";
  [@bs.send.pipe: t] external gte : Js.Json.t => query = "";
  [@bs.send.pipe: t] external lt : Js.Json.t => query = "";
  [@bs.send.pipe: t] external lte : Js.Json.t => query = "";
};

type scan;

type scanWhere;

module Scan = {
  type t = scan;
  [@bs.send.pipe: t] external addFilterCondition : Condition.t => t = "";
  [@bs.send.pipe: t] external attribute : string => t = "attributes";
  [@bs.send.pipe: t] external attributes : array(string) => t = "";
  [@bs.send.pipe: t] external buildRequest : unit => Js.Json.t = "";
  [@bs.send.pipe: t]
  external exec : callback(PaginatedRequest.t) => unit = "";
  [@bs.send.pipe: t] external expressionAttributeNames : Js.Json.t => t = "";
  [@bs.send.pipe: t] external expressionAttributeValues : Js.Json.t => t = "";
  [@bs.send.pipe: t] external filterExpression : string => t = "";
  [@bs.send.pipe: t] external limit : int => t = "";
  [@bs.send.pipe: t] external loadAll : unit => t = "";
  [@bs.send.pipe: t] external projectionExpression : string => t = "";
  [@bs.send.pipe: t] external returnConsumedCapacity : unit => t = "";
  [@bs.send.pipe: t]
  external returnConsumedCapacity__withValue : string => t =
    "returnConsumedCapacity";
  [@bs.send.pipe: t] external segments : (int, int) => t = "";
  [@bs.send.pipe: t] external select : string => t = "";
  [@bs.send.pipe: t] external startKey_ : string => t = "startKey";
  let startKey = (`HashKey(hashKey), scan) => startKey_(hashKey, scan);
  [@bs.send.pipe: t]
  external startKey__hashAndRangeKey_ : (string, string) => t = "startKey";
  let startKey__hashAndRangeKey =
      (`HashKey(hashKey), `RangeKey(rangeKey), scan) =>
    startKey__hashAndRangeKey_(hashKey, rangeKey, scan);
  [@bs.send.pipe: t] external where : string => scanWhere = "";
};

module ScanWhere = {
  type t = scanWhere;
  [@bs.send.pipe: t] external beginsWith : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external between : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external contains : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external eq : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external equals : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external gt : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external gte : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external in_ : Js.Json.t => scan = "in";
  [@bs.send.pipe: t] external lt : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external lte : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external ne : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external notContains : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external notNull : Js.Json.t => scan = "";
  [@bs.send.pipe: t] external null : Js.Json.t => scan = "";
};

module Model = {
  type t;
  [@bs.send] external create : (t, Js.Json.t, callback(Item.t)) => unit = "";
  [@bs.send]
  external createWithOptions :
    (t, Js.Json.t, queryObject, callback(Item.t)) => unit =
    "create";
  [@bs.send]
  external createItems : (t, array(Js.Json.t), callback(Item.t)) => unit =
    "create";
  [@bs.send]
  external createItemsWithOptions :
    (t, array(Js.Json.t), queryObject, callback(Item.t)) => unit =
    "create";
  [@bs.send] external destroy_ : (t, string, callback(Item.t)) => unit = "";
  let destroy = (model, `HashKey(hashKey), callback) =>
    destroy_(model, hashKey, callback);
  [@bs.send]
  external destroyWithOptions_ :
    (t, string, queryObject, callback(Item.t)) => unit =
    "destroy";
  let destroyWithOptions = (model, `HashKey(hashKey), queryObject, callback) =>
    destroyWithOptions_(model, hashKey, queryObject, callback);
  [@bs.send]
  external destroyHashAndRangeKey_ :
    (t, string, string, callback(Item.t)) => unit =
    "destroy";
  let destroyHashAndRangeKey =
      (model, `HashKey(hashKey), `RangeKey(rangeKey), callback) =>
    destroyWithOptions_(model, hashKey, rangeKey, callback);
  [@bs.send]
  external destroyHashAndRangeKeyWithOptions_ :
    (t, string, string, queryObject, callback(Item.t)) => unit =
    "destroy";
  let destroyHashAndRangeKeyWithOptions =
      (model, `HashKey(hashKey), `RangeKey(rangeKey), queryObject, callback) =>
    destroyHashAndRangeKeyWithOptions_(
      model,
      hashKey,
      rangeKey,
      queryObject,
      callback,
    );
  [@bs.send] external get_ : (t, string, callback(Item.t)) => unit = "";
  let get = (model, `HashKey(hashKey), callback) =>
    get_(model, hashKey, callback);
  [@bs.send]
  external getWithOptions_ :
    (t, string, queryObject, callback(Item.t)) => unit =
    "get";
  let getWithOptions = (model, `HashKey(hashKey), queryObject, callback) =>
    getWithOptions_(model, hashKey, queryObject, callback);
  [@bs.send]
  external getHashAndRangeKey_ : (t, string, string, callback(Item.t)) => unit =
    "get";
  let getHashAndRangeKey =
      (model, `HashKey(hashKey), `RangeKey(rangeKey), callback) =>
    getHashAndRangeKey_(model, hashKey, rangeKey, callback);
  [@bs.send]
  external getHashAndRangeKeyWithOptions_ :
    (t, string, string, queryObject, callback(Item.t)) => unit =
    "get";
  let getHashAndRangeKeyWithOptions =
      (model, `HashKey(hashKey), `RangeKey(rangeKey), queryObject, callback) =>
    getHashAndRangeKeyWithOptions_(
      model,
      hashKey,
      rangeKey,
      queryObject,
      callback,
    );
  [@bs.send]
  external getItems_ : (t, array(string), callback(Item.t)) => unit =
    "getItems";
  let getItems = (model, hashKeys, callback) =>
    hashKeys
    |> Js.Array.map((`HashKey(hashKey)) => hashKey)
    |> getItems_(model, _, callback);
  [@bs.send]
  external getItemsWithOptions_ :
    (t, array(string), queryObject, callback(Item.t)) => unit =
    "getItems";
  let getItemsWithOptions = (model, hashKeys, queryObject, callback) =>
    hashKeys
    |> Js.Array.map((`HashKey(hashKey)) => hashKey)
    |> getItemsWithOptions_(model, _, queryObject, callback);
  [@bs.send]
  external getItemsHashAndRangeKeys_ :
    (t, array(Js.Dict.t(string)), callback(Item.t)) => unit =
    "getItems";
  [@bs.send]
  external getItemsHashAndRangeKeysWithOptions_ :
    (t, array(Js.Dict.t(string)), queryObject, callback(Item.t)) => unit =
    "getItems";
  [@bs.send] external parallelScan : (t, int) => scan = "parallelScan";
  [@bs.send] external query : (t, string) => query = "query";
  [@bs.send] external scan : t => scan = "scan";
  [@bs.send] external tableName : t => string = "tableName";
  [@bs.send] external update : (t, Js.Json.t, callback(Item.t)) => unit = "";
  [@bs.send]
  external update__withOptions :
    (t, Js.Json.t, queryObject, callback(Item.t)) => unit =
    "update";
};

module SchemaGlobalIndex = {
  type t;
  let make: (string, string) => t = [%bs.raw
    {| function (hashKey, name) {
    return { hashKey: hashKey, name: name, type: 'global' };
  } |}
  ];
  [@bs.set] external setHashKey : (t, string) => unit = "hashKey";
  [@bs.get] external getHashKey : t => string = "hashKey";
  [@bs.set] external setName : (t, string) => unit = "name";
  [@bs.get] external getName : t => string = "name";
  [@bs.set]
  external setProjection : (t, Js.Nullable.t(Js.Json.t)) => unit =
    "projection";
  [@bs.get]
  external getProjection : t => Js.Nullable.t(Js.Json.t) = "projection";
  [@bs.set]
  external setRangeKey : (t, Js.Nullable.t(string)) => unit = "rangeKey";
  [@bs.get] external getRangeKey : t => Js.Nullable.t(string) = "rangeKey";
  [@bs.set]
  external setReadCapacity : (t, Js.Nullable.t(int)) => unit = "readCapacity";
  [@bs.get]
  external getReadCapacity : t => Js.Nullable.t(int) = "readCapacity";
  [@bs.set]
  external setWriteCapacity : (t, Js.Nullable.t(int)) => unit =
    "writeCapacity";
  [@bs.get]
  external getWriteCapacity : t => Js.Nullable.t(int) = "writeCapacity";
};

module SchemaLocalIndex = {
  type t;
  let make: string => t = [%bs.raw
    {| function (name) {
    return { name: name, type: 'local' };
  } |}
  ];
  [@bs.set] external setName : (t, string) => unit = "name";
  [@bs.get] external getName : t => string = "name";
  [@bs.set]
  external setProjection : (t, Js.Nullable.t(Js.Json.t)) => unit =
    "projection";
  [@bs.get]
  external getProjection : t => Js.Nullable.t(Js.Json.t) = "projection";
  [@bs.set]
  external setRangeKey : (t, Js.Nullable.t(string)) => unit = "rangeKey";
  [@bs.get] external getRangeKey : t => Js.Nullable.t(string) = "rangeKey";
};

module SchemaIndexes = {
  type t;
  let make: unit => t = [%bs.raw {| function () {
    return [];
  } |}];
  [@bs.send]
  external addGlobalIndex : (t, SchemaGlobalIndex.t) => unit = "push";
  [@bs.send] external addLocalIndex : (t, SchemaLocalIndex.t) => unit = "push";
};

module SchemaConfig = {
  /*
   TODO: this also has a schema field on it but it _must_ be a Joi schema which
   kind of sucks. We should PR Dynogels to allow for just a validation function
   to be passed in instead of relying on Joi
   */
  type t;
  let make: unit => t = [%bs.raw
    {| function () {
    return { createdAt: true, updatedAt: true };
  } |}
  ];
  [@bs.set] external setCreatedAt : (t, string) => unit = "createdAt";
  [@bs.set] external setCreatedAtBoolVal : (t, bool) => unit = "createdAt";
  [@bs.set]
  external setHashKey : (t, Js.Nullable.t(string)) => unit = "hashKey";
  [@bs.get] external getHashKey : t => Js.Nullable.t(string) = "hashKey";
  [@bs.set]
  external setIndexes : (t, Js.Nullable.t(SchemaIndexes.t)) => unit =
    "indexes";
  [@bs.get]
  external getIndexes : t => Js.Nullable.t(SchemaIndexes.t) = "indexes";
  [@bs.set]
  external setRangeKey : (t, Js.Nullable.t(string)) => unit = "rangeKey";
  [@bs.get] external getRangeKey : t => Js.Nullable.t(string) = "rangeKey";
  [@bs.set]
  external setTableName : (t, Js.Nullable.t(string)) => unit = "tableName";
  [@bs.get] external getTableName : t => Js.Nullable.t(string) = "tableName";
  [@bs.set] external setUpdatedAt : (t, string) => unit = "updatedAt";
  [@bs.set] external setUpdatedAtBoolVal : (t, bool) => unit = "updatedAt";
  /*
   NOTE: If timestamps is set to true then Joi validation will kick in and you'll
   probably see things starting to break since there is no way to add Joi
   validation to the schema through this package right now.
   */
  [@bs.set]
  external setTimestamps : (t, Js.Nullable.t(bool)) => unit = "timestamps";
  [@bs.get] external getTimestamps : t => Js.Nullable.t(bool) = "timestamps";
};

type documentClient;

[@bs.module "aws-sdk"] [@bs.scope "DynamoDB"] [@bs.new]
external getDefaultDocumentClient : unit => documentClient = "DocumentClient";

[@bs.module "aws-sdk"] [@bs.scope "DynamoDB"] [@bs.new]
external getDocumentClient :
  {
    .
    "accessKeyId": string,
    "endpoint": string,
    "region": string,
    "secretAccessKey": string,
  } =>
  documentClient =
  "DocumentClient";

[@bs.module "dynogels"]
external createTables : (CreateTableOptions.t, callback(unit)) => unit = "";

[@bs.module "dynogels"] [@bs.return nullable]
external define : (string, SchemaConfig.t) => option(Model.t) = "";

[@bs.module "dynogels"]
external documentClient : documentClient => documentClient = "";

[@bs.module "dynogels"] external reset : unit => unit = "";
