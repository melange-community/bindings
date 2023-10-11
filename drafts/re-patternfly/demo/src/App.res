open Patternfly

module Build = {
  type t = {job: string, result: string, count: int}
  let samples = list{
    {job: "rpmbuild", result: "success", count: 42},
    {job: "rpmtest", result: "failure", count: 13},
    {job: "noop", result: "error", count: 100},
  }
}

module SortableTable = {
  @react.component
  let make = () => {
    let columns = [
      {title: "job", transforms: [sortable]},
      {title: "result", transforms: [sortable]},
      {title: "count", transforms: [sortable]},
    ]
    let isOrdered = (first: Build.t, second: Build.t, index) =>
      switch index {
      | 0 => first.job < second.job
      | 1 => first.result < second.result
      | 2 => first.count < second.count
      | _ => false
      }
    let (sortBy, setSortBy) = React.useState(_ => {index: 0, direction: #desc})

    let jobFormatter = (build: Build.t) => build.job->React.string
    let resultFormatter = (build: Build.t) => build.result->React.string
    let countFormatter = (build: Build.t) => build.count->string_of_int->React.string
    let formatters = list{jobFormatter, resultFormatter, countFormatter}

    let (rows, setRows) = React.useState(_ => Build.samples->mkRows(formatters))

    let doSort = (index, direction) => setRows(_ => rows->sortRows(isOrdered, index, direction))

    let onSort = (_, index, direction) => {
      setSortBy(_ => {index: index, direction: direction})
      doSort(index, direction)
    }
    React.useEffect0(() => {
      doSort(sortBy.index, sortBy.direction)
      None
    })
    <Table caption="Sortable Table" rows variant=#compact cells=columns sortBy onSort>
      <TableHeader /> <TableBody />
    </Table>
  }
}

@react.component
let make = () => <>
  <Breadcrumb>
    <BreadcrumbItem _to="#"> {"Home" |> React.string} </BreadcrumbItem>
    <BreadcrumbHeading _to="#"> {"Project" |> React.string} </BreadcrumbHeading>
  </Breadcrumb>
  <Patternfly.List>
    <Patternfly.ListItem> <Icons.Topology /> </Patternfly.ListItem>
    <Patternfly.ListItem> {"Hello patternfly!" |> React.string} </Patternfly.ListItem>
    <Patternfly.ListItem> <SortableTable /> </Patternfly.ListItem>
  </Patternfly.List>
</>
