open Jest;
open Decode;
open Expect;

describe("CurrentPlayState", () => {
  test("stopped", () =>
    expect(CurrentPlayState.make("stopped"))
    |> toEqual(CurrentPlayState.Stopped)
  );

  test("playing", () =>
    expect(CurrentPlayState.make("playing"))
    |> toEqual(CurrentPlayState.Playing)
  );

  test("paused", () =>
    expect(CurrentPlayState.make("paused"))
    |> toEqual(CurrentPlayState.Paused)
  );

  test("undefined", () =>
    expect(CurrentPlayState.make("undefined"))
    |> toEqual(CurrentPlayState.UnknownState)
  );
});

describe("CurrentTrack", () => {
  test("parse current track without track data", () => {
    let mockPayload =
      {|{
              "position": 0,
              "duration": 0,
              "queuePosition": 0,
              "uri": null
            }|}
      |> Js.Json.parseExn;

    let expected: CurrentTrack.t = {
      album: None,
      albumArtURI: "",
      albumArtURL: "",
      artist: "",
      duration: 0.,
      position: 0.,
      queuePosition: 0.,
      title: "",
      uri: None,
    };

    expect(CurrentTrack.make(mockPayload)) |> toEqual(expected);
  });

  test("parse current track with data", () => {
    let mockPayload =
      {|{
              "album": "Sempiternal",
              "albumArtURI": "some-art-uri",
              "albumArtURL": "some-art-url",
              "artist": "Bring Me The Horizon",
              "duration": 320,
              "position": 1,
              "queuePosition": 3,
              "title": "Hospital for Souls",
              "uri": "some-uri"
            }|}
      |> Js.Json.parseExn;

    let expected: CurrentTrack.t = {
      album: Some("Sempiternal"),
      albumArtURI: "some-art-uri",
      albumArtURL: "some-art-url",
      artist: "Bring Me The Horizon",
      duration: 320.,
      position: 1.,
      queuePosition: 3.,
      title: "Hospital for Souls",
      uri: Some("some-uri"),
    };

    expect(CurrentTrack.make(mockPayload)) |> toEqual(expected);
  });
});

describe("CurrentQueue", () =>
  test("parse current queue with track data", () => {
    let mockPayload =
      {|{
        "returned": "1",
        "total": "1",
        "items": [{
              "album": "Sempiternal",
              "albumArtURI": "some-art-uri",
              "artist": "Bring Me The Horizon",
              "title": "Hospital for Souls",
              "uri": "some-uri"
            }]
        }|}
      |> Js.Json.parseExn;

    let expected: CurrentQueue.t = {
      returned: "1",
      total: "1",
      items: [|
        {
          album: Some("Sempiternal"),
          albumArtURI: "some-art-uri",
          artist: "Bring Me The Horizon",
          title: "Hospital for Souls",
          uri: "some-uri",
        },
      |],
    };

    expect(CurrentQueue.make(mockPayload)) |> toEqual(expected);
  })
);

describe("QueueTrack", () =>
  test("parse queue response", () => {
    let mockPayload =
      {|{
        "FirstTrackNumberEnqueued": "1",
        "NewQueueLength": "1",
        "NumTracksAdded": "1"
        }|}
      |> Js.Json.parseExn;

    let expected: QueueTrack.t = {
      firstTrackNumberEnqueued: "1",
      newQueueLength: "1",
      numTracksAdded: "1",
    };

    expect(QueueTrack.make(mockPayload)) |> toEqual(expected);
  })
);
