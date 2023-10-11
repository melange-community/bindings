[@bs.module "react-admin"]
external datagrid : ReasonReact.reactClass = "Datagrid";

type currentSort =
  Js.t(
    {
      .
      "sort": string,
      "order": string,
    },
  );

[@bs.obj]
external makeProps :
  (
    ~basePath: string=?,
    ~classes: 'a=?,
    ~className: string=?,
    ~currentSort: currentSort=?,
    ~data: 'b=?,
    ~hasBulkActions: bool=?,
    ~hover: bool=?,
    ~ids: 'c=?,
    ~isLoading: bool=?,
    ~onSelect: 'd=?,
    ~onToggleItem: 'e=?,
    ~resource: string=?,
    ~rowStyle: 'f=?,
    ~selectedIds: 'g=?,
    ~setSort: 'h=?,
    ~total: int=?,
    ~version: int=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~basePath=?,
      ~classes=?,
      ~className=?,
      ~currentSort=?,
      ~data=?,
      ~hasBulkActions=?,
      ~hover=?,
      ~ids=?,
      ~isLoading=?,
      ~onSelect=?,
      ~onToggleItem=?,
      ~resource=?,
      ~rowStyle=?,
      ~selectedIds=?,
      ~setSort=?,
      ~total=?,
      ~version=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=datagrid,
    ~props=
      makeProps(
        ~basePath?,
        ~classes?,
        ~className?,
        ~currentSort?,
        ~data?,
        ~hasBulkActions?,
        ~hover?,
        ~ids?,
        ~isLoading?,
        ~onSelect?,
        ~onToggleItem?,
        ~resource?,
        ~rowStyle?,
        ~selectedIds?,
        ~setSort?,
        ~total?,
        ~version?,
        (),
      ),
    children,
  );
