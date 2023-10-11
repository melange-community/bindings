let included = [
  "ARG",
  "BOL",
  "BRA",
  "CHL",
  "COL",
  "ECU",
  "GUY",
  "PRY",
  "PER",
  "SUR",
  "URY",
  "VEN",
];

type markerDef = {
  markerOffset: int,
  name: string,
  coordinates: (float, float),
};

let markers = [|
  {
    markerOffset: (-25),
    name: "Buenos Aires",
    coordinates: ((-58.3816), (-34.6037)),
  },
  {
    markerOffset: (-25),
    name: "La Paz",
    coordinates: ((-68.1193), (-16.4897)),
  },
  {
    markerOffset: 35,
    name: "Brasilia",
    coordinates: ((-47.8825), (-15.7942)),
  },
  {
    markerOffset: 35,
    name: "Santiago",
    coordinates: ((-70.6693), (-33.4489)),
  },
  {markerOffset: 35, name: "Bogota", coordinates: ((-74.0721), 4.7110)},
  {markerOffset: 35, name: "Quito", coordinates: ((-78.4678), (-0.1807))},
  {
    markerOffset: (-25),
    name: "Georgetown",
    coordinates: ((-58.1551), 6.8013),
  },
  {
    markerOffset: (-25),
    name: "Asuncion",
    coordinates: ((-57.5759), (-25.2637)),
  },
  {markerOffset: 35, name: "Paramaribo", coordinates: ((-55.2038), 5.8520)},
  {
    markerOffset: 35,
    name: "Montevideo",
    coordinates: ((-56.1645), (-34.9011)),
  },
  {markerOffset: (-25), name: "Caracas", coordinates: ((-66.9036), 10.4806)},
|];

ReactDOMRe.renderToElementWithId(
  <ComposableMap
    projectionConfig=(ComposableMap.projectionConfig(~scale=800, ()))
    width=1000
    height=1000>
    <ZoomableGroup center=((-60.), (-25.)) disablePanning=false>
      <Geographies geography="/examples/world-50m.json">
        (
          (geographies, projection) =>
            Array.map(
              geography =>
                List.exists(id => id == Geography.id(geography), included) ?
                  <Geography
                    key=(Geography.id(geography))
                    geography
                    projection
                    style=(
                      Types.style(
                        ~default=
                          ReactDOMRe.Style.make(
                            ~fill="#ECEFF1",
                            ~stroke="#607D8B",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                        ~hover=
                          ReactDOMRe.Style.make(
                            ~fill="#607D8B",
                            ~stroke="#607D8B",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                        ~pressed=
                          ReactDOMRe.Style.make(
                            ~fill="#FF5722",
                            ~stroke="#607D8B",
                            ~strokeWidth="0.75px",
                            ~outline="none",
                            (),
                          ),
                        (),
                      )
                    )
                  /> :
                  ReasonReact.null,
              geographies,
            )
        )
      </Geographies>
      <Markers>
        (
          Array.mapi(
            (i, marker) =>
              <Marker
                key=(string_of_int(i))
                coordinates=marker.coordinates
                style=(
                  Types.style(
                    ~default=ReactDOMRe.Style.make(~fill="#FF5722", ()),
                    ~hover=ReactDOMRe.Style.make(~fill="#FFFFFF", ()),
                    ~pressed=ReactDOMRe.Style.make(~fill="#FF5722", ()),
                    (),
                  )
                )>
                <circle
                  cx="0"
                  cy="0"
                  r="10"
                  style=(
                    ReactDOMRe.Style.make(
                      ~stroke="#FF5722",
                      ~strokeWidth="3",
                      ~opacity="0.9",
                      (),
                    )
                  )
                />
                <text
                  textAnchor="middle"
                  y=(string_of_int(marker.markerOffset))
                  style=(
                    ReactDOMRe.Style.make(
                      ~fontFamily="Roboto, sans-serif",
                      ~fill="#607D8B",
                      (),
                    )
                  )>
                  (ReasonReact.string(marker.name))
                </text>
              </Marker>,
            markers,
          )
        )
      </Markers>
    </ZoomableGroup>
  </ComposableMap>,
  "main",
);
