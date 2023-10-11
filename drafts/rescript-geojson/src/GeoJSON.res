type id = String(string) | Number(float)

module Position = {
  type t = LatLng(float, float) | LatLngAlt(float, float, float)
}

module Geometry = {
  type rec t =
    | Point({coordinates: Position.t})
    | MultiPoint({coordinates: array<Position.t>})
    | LineString({coordinates: array<Position.t>})
    | MultiLineString({coordinates: array<array<Position.t>>})
    | Polygon({coordinates: array<array<Position.t>>})
    | MultiPolygon({coordinates: array<array<array<Position.t>>>})
    | GeometryCollection({geometries: array<t>})
}

module Feature = {
  type t = {geometry: Geometry.t, id?: id, properties: option<Js.Dict.t<Js.Json.t>>}
}

type t =
  | Geometry(Geometry.t)
  | Feature(Feature.t)
  | FeatureCollection({features: array<Feature.t>})

module Decode = {
  open! Json.Decode

  let latLng = tuple2(float, float)
  let latLngAlt = tuple3(float, float, float)

  let position = oneOf([
    latLng->map((. (lat, lng)) => Position.LatLng(lat, lng)),
    latLngAlt->map((. (lat, lng, alt)) => Position.LatLngAlt(lat, lng, alt)),
  ])

  let point = object(field => Geometry.Point({
    coordinates: field.required(. "coordinates", position),
  }))

  let multiPoint = object(field => Geometry.MultiPoint({
    coordinates: field.required(. "coordinates", array(position)),
  }))

  let lineString = object(field => Geometry.LineString({
    coordinates: field.required(. "coordinates", array(position)),
  }))

  let multiLineString = object(field => Geometry.MultiLineString({
    coordinates: field.required(. "coordinates", array(array(position))),
  }))

  let polygon = object(field => Geometry.Polygon({
    coordinates: field.required(. "coordinates", array(array(position))),
  }))

  let multiPolygon = object(field => Geometry.MultiPolygon({
    coordinates: field.required(. "coordinates", array(array(array(position)))),
  }))

  let geometryCollection = geometry =>
    object(field => Geometry.GeometryCollection({
      geometries: field.required(. "geometries", array(geometry)),
    }))

  let geometry = {
    let rec geometry = json => {
      let result = json->decode(
        field("type", string)->flatMap((. typ) =>
          switch typ {
          | "Point" => point
          | "MultiPoint" => multiPoint
          | "LineString" => lineString
          | "MultiLineString" => multiLineString
          | "Polygon" => polygon
          | "MultiPolygon" => multiPolygon
          | "GeometryCollection" => geometryCollection(custom((. json) => geometry(json)))
          | other => raise(DecodeError(`unknown geometry type: '${other}'`))
          }
        ),
      )

      switch result {
      | Ok(v) => v
      | Error(err) => raise(DecodeError(err))
      }
    }

    custom((. json) => geometry(json))
  }

  let geometryCollection = geometryCollection(geometry) // TODO: awkward recursion hack

  let id = oneOf([string->map((. v) => String(v)), float->map((. v) => Number(v))])

  let feature = object((field): Feature.t => {
    geometry: field.required(. "geometry", geometry),
    id: ?field.optional(. "id", id),
    properties: field.required(. "properties", option(dict(Json.Decode.id))),
  })

  let object = field("type", string)->flatMap((. typ) =>
    switch typ {
    | "Feature" => feature->map((. v) => Feature(v))
    | "FeatureCollection" =>
      object(field => FeatureCollection({
        features: field.required(. "features", array(feature)),
      }))
    | _ => geometry->map((. v) => Geometry(v))
    }
  )
}
