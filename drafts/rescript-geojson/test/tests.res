let featureCollection = %raw(`{
    type: 'FeatureCollection',
    features: [
        {
            id: 1234,
            type: 'Feature',
            geometry: {
                type: 'Point',
                coordinates: [102.0, 0.5],
            },
            properties: {
                prop0: 'value0',
            },
        },
        {
            id: 'stringid',
            type: 'Feature',
            geometry: {
                type: 'LineString',
                coordinates: [
                    [102.0, 0.0],
                    [103.0, 1.0],
                    [104.0, 0.0],
                    [105.0, 1.0],
                ],
            },
            properties: {
                prop0: 'value0',
                prop1: 0.0,
            },
        },
        {
            type: 'Feature',
            geometry: {
                type: 'Polygon',
                coordinates: [
                    [
                        [100.0, 0.0],
                        [101.0, 0.0],
                        [101.0, 1.0],
                        [100.0, 1.0],
                        [100.0, 0.0],
                    ],
                ],
            },
            properties: {
                prop0: 'value0',
                prop1: {
                    that: 'this',
                },
            },
        },
    ],
}`)

let featureWithPolygon = %raw(`{
    type: 'Feature',
    bbox: [-180.0, -90.0, 180.0, 90.0],
    geometry: {
        type: 'Polygon',
        coordinates: [
            [
                [-180.0, 10.0],
                [20.0, 90.0],
                [180.0, -5.0],
                [-30.0, -90.0],
            ],
        ],
    },
    properties: null,
}`)

let point = %raw(`{
    type: 'Point',
    coordinates: [100.0, 0.0],
}`)

let lineString = %raw(`{
    type: 'LineString',
    coordinates: [
        [100.0, 0.0],
        [101.0, 1.0],
    ],
}`)

let polygon = %raw(`{
    type: 'Polygon',
    coordinates: [
        [
            [100.0, 0.0],
            [101.0, 0.0],
            [101.0, 1.0],
            [100.0, 1.0],
            [100.0, 0.0],
        ],
    ],
}`)

let polygonWithHole = %raw(`{
    type: 'Polygon',
    coordinates: [
        [
            [100.0, 0.0],
            [101.0, 0.0],
            [101.0, 1.0],
            [100.0, 1.0],
            [100.0, 0.0],
        ],
        [
            [100.2, 0.2],
            [100.8, 0.2],
            [100.8, 0.8],
            [100.2, 0.8],
            [100.2, 0.2],
        ],
    ],
}`)

let multiPoint = %raw(`{
    type: 'MultiPoint',
    coordinates: [
        [100.0, 0.0],
        [101.0, 1.0],
    ],
}`)

let multiLineString = %raw(`{
    type: 'MultiLineString',
    coordinates: [
        [
            [100.0, 0.0],
            [101.0, 1.0],
        ],
        [
            [102.0, 2.0],
            [103.0, 3.0],
        ],
    ],
}`)

let multiPolygon = %raw(`{
    type: 'MultiPolygon',
    coordinates: [
        [
            [
                [102.0, 2.0],
                [103.0, 2.0],
                [103.0, 3.0],
                [102.0, 3.0],
                [102.0, 2.0],
            ],
        ],
        [
            [
                [100.0, 0.0],
                [101.0, 0.0],
                [101.0, 1.0],
                [100.0, 1.0],
                [100.0, 0.0],
            ],
            [
                [100.2, 0.2],
                [100.8, 0.2],
                [100.8, 0.8],
                [100.2, 0.8],
                [100.2, 0.2],
            ],
        ],
    ],
}`)

let test = json => json->Json.decode(GeoJSON.Decode.object)->Belt.Result.getExn->Js.log

test(featureCollection)
test(featureWithPolygon)
test(point)
test(lineString)
test(polygon)
test(polygonWithHole)
test(multiPoint)
test(multiLineString)
test(multiPolygon)

module Example = {
  let json = %raw(`{
        type: 'Feature',
        geometry: {
            type: 'Polygon',
            coordinates: [
                [
                    [-180.0, 10.0],
                    [20.0, 90.0],
                    [180.0, -5.0],
                    [-30.0, -90.0],
                ],
            ],
        },
        properties: null,
    }`)

  switch json->Json.decode(GeoJSON.Decode.object) {
  | Ok(Feature({geometry: Polygon({coordinates})})) => Js.log2("Polygon coordinates: ", coordinates)
  | Ok(_) => Js.log("not a feature with polygon?!")
  | Error(err) => Js.log(err)
  }
}
