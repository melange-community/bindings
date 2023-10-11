open ReactInstantSearch;

let make = _children => {
  ...ReasonReact.statelessComponent("Search"),
  render: _self =>
    <InstantSearch
      appId="OFCNCOG2CU"
      apiKey="f54e21fa3a2a0160595bb058179bfb1e"
      indexName="npm-search">
      <Configure attributesToRetrieve=[|"name", "owner", "description"|] />
      <RefinementList attribute="owner.name" searchable=true />
      <SearchBox />
      <Hits />
      <Pagination />
    </InstantSearch>,
};
