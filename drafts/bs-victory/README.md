# @reasonableconsulting/bs-victory

BuckleScript bindings for Victory Charts.

## Usage

```reason
<Victory.Container height=250 width=250 responsive=false>
  <Victory.Legend
    standalone=false
    data=legendData
    orientation="horizontal"
    itemsPerRow=2
    width=250
    symbolSpacer=10
    style=legendStyles
  />
  <Victory.Pie
    standalone=false
    data=pieData
    padding={Victory.padding(~left=0, ~right=0, ~top=0, ~bottom=0, ())}
    height=250
    width=250
    labelRadius=60
    labels={data => data##y}
    style=pieStyles
  />
</Victory.Container>
```
