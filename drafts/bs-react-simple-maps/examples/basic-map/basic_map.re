ReactDOMRe.renderToElementWithId(
  <ComposableMap
    projectionConfig=(
      ComposableMap.projectionConfig(
        ~scale=205,
        ~rotation=((-11.), 0., 0.),
        (),
      )
    )
    width=980
    height=551>
    <ZoomableGroup center=(0., 20.) disablePanning=false>
      <Geographies geography="/examples/world-50m.json">
        (
          (geographies, projection) =>
            Array.map(
              geography =>
                Geography.id(geography) != "ATA" ?
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
    </ZoomableGroup>
  </ComposableMap>,
  "main",
);
