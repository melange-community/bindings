[@bs.deriving abstract]
type pagination = {
  page: int,
  perPage: int,
};

[@bs.deriving abstract]
type sort = {
  field: string,
  order: [ | `asc | `desc],
};

[@bs.deriving abstract]
type params = {
  [@bs.optional]
  pagination,
  [@bs.optional]
  sort,
  [@bs.optional]
  filter: string,
  [@bs.optional]
  id: string,
  [@bs.optional]
  ids: list(string),
  [@bs.optional]
  target: string,
};

[@bs.module "ra-data-json-server"] 
external raDataJsonServer :
  ( 
    ~apiUrl: string,
    ~httpClient: (string, _) => Js.Promise.t(Fetch.Response.t)=?,
    unit
  ) =>
  BsReactAdmin__Admin.dataProvider =
  "default";
