open Jest;

open ExpectJs;

describe(
  "latLng",
  LeafletRe.(
    () =>
      test("creation", () =>
        expect(create_lat_lng(~latitude=0., ~longitude=0., ~altitude=None))
        |> toEqual(create_lat_lng(~latitude=0., ~longitude=0., ~altitude=None))
      )
  )
);

describe(
  "point",
  LeafletRe.(
    () => {
      test("creation", () =>
        expect(point_int(0, 0)) |> toEqual(point_int(0, 0))
      );
      test("creation float", () =>
        expect(point_float(0., 0., false))
        |> toEqual(point_float(0., 0., false))
      );
      test("creation float with rounding", () =>
        expect(point_float(0.1, 0.1, true))
        |> toEqual(point_float(0.2, 0.2, true))
      );
    }
  )
);
