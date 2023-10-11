@deriving(jsConverter)
type iconSet = [
  | #Solid
  | #Regular
  | #Light
  | #Duotone
  | #Thin
  | #SharpSolid
  | #Brands
]

let iconSets = [#Solid, #Regular, #Light, #Duotone, #Thin, #SharpSolid, #Brands]

let getAll = iconSet =>
  switch iconSet {
  | #Solid => Solid_All.all
  | #Regular => Regular_All.all
  | #Light => Light_All.all
  | #Duotone => Duotone_All.all
  | #Thin => Thin_All.all
  | #SharpSolid => SharpSolid_All.all
  | #Brands => Brands_All.all
  }

@react.component
let make = () => {
  let (iconSet, setIconSet) = React.useState(_ => #Solid)
  let (size: IconSize.t, setSize) = React.useState(_ => #"2x")
  let icons = iconSet->getAll
  <div className="flex flex-col">
    <div className="flex flex-row">
      <span>
        {React.string("Icon set:")}
        <select
          className="ml-1"
          onChange={event => {
            let value = ReactEvent.Form.target(event)["value"]
            setIconSet(_ => value)
          }}>
          {iconSets
          ->Js.Array2.map(s =>
            <option key={s->iconSetToJs} selected={s == iconSet} value={s->iconSetToJs}>
              {React.string(s->iconSetToJs)}
            </option>
          )
          ->React.array}
        </select>
      </span>
      <span className="ml-2">
        {React.string("Icon size:")}
        <select
          className="ml-1"
          onChange={event => {
            let value = ReactEvent.Form.target(event)["value"]
            value->IconSize.tFromJs->Belt.Option.forEach(size => setSize(_ => size))
          }}>
          {IconSize.all
          ->Js.Array2.map(s =>
            <option key={IconSize.tToJs(s)} selected={s == size} value={IconSize.tToJs(s)}>
              {React.string(s->IconSize.tToJs)}
            </option>
          )
          ->React.array}
        </select>
      </span>
    </div>
    {React.string(`${icons->Js.Array.length->Js.Int.toString} ${iconSet->iconSetToJs} icons`)}
    <div className="md:grid md:grid-cols-5 md:gap-6">
      {icons
      ->Js.Array2.map(icon => {
        let name = icon->IconObject.iconName
        <div key=name className="flex items-center justify-between flex-wrap border-2 rounded p-2">
          <span> {React.string(name)} </span> <Icon icon size />
        </div>
      })
      ->React.array}
    </div>
  </div>
}
