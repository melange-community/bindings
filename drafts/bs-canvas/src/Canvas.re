type t;
type htmlCanvasElement;

[@bs.deriving jsConverter]
type canvasFormat = [ | [@bs.as "svg"] `SVG | [@bs.as "pdf"] `PDF];

[@bs.new] [@bs.module]
external createCanvas':
  (~width: float=?, ~height: float=?, ~type_: string=?, unit) => t =
  "canvas";
let createCanvas = (~width=?, ~height=?, ~type_=?, ()) =>
  switch (type_) {
  | Some(type_) =>
    createCanvas'(~width?, ~height?, ~type_=type_ |> canvasFormatToJs, ())
  | None => createCanvas'(~width?, ~height?, ())
  };

type pngStream;
type jpegStream;
type pdfStream;

[@bs.deriving abstract]
type jpegStreamOptions = {
  [@bs.optional]
  bufsize: int,
  [@bs.optional]
  quality: int,
  [@bs.optional]
  progressive: bool,
};

[@bs.send] external pngStream: t => pngStream = "";
[@bs.send]
external jpegStream: (t, ~options: jpegStreamOptions=?, unit) => jpegStream =
  "";
[@bs.send] external pdfStream: t => pdfStream = "";

/* TODO: Add bindings for all possible forms of toBuffer function */
[@bs.send] external toBuffer: t => Node.Buffer.t = "";

[@bs.deriving jsConverter]
type imageFormat = [
  | [@bs.as "image/png"] `PNG
  | [@bs.as "image/jpeg"] `JPEG
];

[@bs.get] external widthGet: t => float = "width";
[@bs.get] external heightGet: t => float = "height";

/* TODO: Add binding for async toDataURL */
[@bs.send]
external toDataURL':
  (t, ~type_: string=?, ~encoderOptions: float=?, unit) => string =
  "toDataURL";
let toDataURL = (canvas, ~type_=?, ~encoderOptions=?, ()) =>
  switch (type_) {
  | Some(type_) =>
    canvas->toDataURL'(~type_=type_ |> imageFormatToJs, ~encoderOptions?, ())
  | None => canvas->toDataURL'(~encoderOptions?, ())
  };

[@bs.deriving jsConverter]
type renderingContext = [ | [@bs.as "2d"] `CanvasRenderingContext2D];

/* TODO: Add image data modes */
module Image = {
  type t;

  [@bs.get] external srcGet: t => string = "src";
  [@bs.set] external srcSet: (t, string) => unit = "src";

  [@bs.new] [@bs.module "canvas"]
  external createImage: (~width: float=?, ~height: float=?, unit) => t =
    "Image";
};

/* TODO: Set correct data types instead of using ints */
module ImageData = {
  type t;
  [@bs.get] external dataGet': t => array(int) = "data";
  let dataGet = t => t->dataGet' |> Array.to_list;
  [@bs.get] external height: t => int64 = "";
  [@bs.get] external width: t => int64 = "";

  [@bs.new] [@bs.module "canvas"]
  external createImageData: (int64, int64) => t = "ImageData";

  [@bs.new] [@bs.module "canvas"]
  external createImageDataFromData': (array(int), int64, int64) => t =
    "ImageData";
  let createImageDataFromData = (data, width, height) =>
    createImageDataFromData'(data |> Array.of_list, width, height);
};

module CanvasRenderingContext2D = {
  type t;
  /* TODO: Add methods for gradient type */
  type gradient;
  /* TODO: Add methods for pattern type */
  type pattern;

  module TextMetrics = {
    [@bs.deriving abstract]
    type t =
      pri {
        width: float,
        actualBoundingBoxLeft: float,
        actualBoundingRight: float,
        fontBoundingBoxAscent: float,
        fontBoundingBoxDescent: float,
        actualBoundingBoxAscent: float,
        actualBoundingBoxDescent: float,
        emHeightAscent: float,
        emHeightDescent: float,
        alphabeticBaseline: float,
        ideographicBaseline: float,
      };
  };

  [@bs.get] external fontGet: t => string = "font";
  [@bs.set] external fontSet: (t, string) => unit = "font";

  [@bs.get] external shadowBlurGet: t => float = "shadowBlur";
  [@bs.set] external shadowBlurSet: (t, float) => unit = "shadowBlur";

  [@bs.get] external shadowOffsetXGet: t => float = "shadowOffsetX";
  [@bs.set] external shadowOffsetXSet: (t, float) => unit = "shadowOffsetX";

  [@bs.get] external shadowOffsetYGet: t => float = "shadowOffsetY";
  [@bs.set] external shadowOffsetYSet: (t, float) => unit = "shadowOffsetY";

  [@bs.get] external shadowColorGet: t => string = "shadowColor";
  [@bs.set] external shadowColorSet: (t, string) => unit = "shadowColor";

  [@bs.get] external lineWidthGet: t => float = "lineWidth";
  [@bs.set] external lineWidthSet: (t, float) => unit = "lineWidth";

  [@bs.get] external lineDashOffsetGet: t => float = "lineDashOffset";
  [@bs.set] external lineDashOffsetSet: (t, float) => unit = "lineDashOffset";

  [@bs.get] external globalAlphaGet: t => float = "globalAlpha";
  [@bs.set] external globalAlphaSet: (t, float) => unit = "globalAlpha";

  [@bs.get]
  external imageSmoothingEnabledGet: t => bool = "imageSmoothingEnabled";
  [@bs.set]
  external imageSmoothingEnabledSet: (t, bool) => unit =
    "imageSmoothingEnabled";

  [@bs.deriving jsConverter]
  type globalCompositeOperation = [
    | [@bs.as "source-over"] `sourceOver
    | [@bs.as "source-in"] `sourceIn
    | [@bs.as "source-out"] `sourceOut
    | [@bs.as "source-atop"] `sourceAtop
    | [@bs.as "destination-over"] `destinationOver
    | [@bs.as "destination-in"] `destinationIn
    | [@bs.as "destination-out"] `destinationOut
    | [@bs.as "destination-atop"] `destinationAtop
    | `lighter
    | `copy
    | `xor
    | `multiply
    | `screen
    | `overlay
    | `darken
    | `lighten
    | [@bs.as "color-dodge"] `colorDodge
    | [@bs.as "color-burn"] `colorBurn
    | [@bs.as "hard-light"] `hardLight
    | [@bs.as "soft-light"] `softLight
    | `difference
    | `exclusion
    | `hue
    | `saturation
    | `color
    | `luminosity
    | [@bs.as "hsl-hue"] `hslHue
    | [@bs.as "hsl-saturation"] `hslSaturation
    | [@bs.as "hsl-color"] `hslColor
    | [@bs.as "hsl-luminosity"] `hslLuminosity
    | `unknown
  ];

  [@bs.get]
  external globalCompositeOperationGet': t => string =
    "globalCompositeOperation";
  let globalCompositeOperationGet = t =>
    switch (t->globalCompositeOperationGet' |> globalCompositeOperationFromJs) {
    | Some(globalCompositeOperation) => globalCompositeOperation
    | None => `unknown
    };
  [@bs.set]
  external globalCompositeOperationSet': (t, string) => unit =
    "globalCompositeOperation";
  let globalCompositeOperationSet = (t, globalCompositeOperation) =>
    t
    ->globalCompositeOperationSet'(
        globalCompositeOperation |> globalCompositeOperationToJs,
      );

  [@bs.send] external getLineDash': t => array(float) = "";
  let getLineDash = t => t->getLineDash' |> Array.to_list;
  [@bs.send] external setLineDash': (t, array(float)) => unit = "";
  let setLineDash = (t, segments) =>
    t->setLineDash'(segments |> Array.of_list);

  [@bs.deriving jsConverter]
  type lineCap = [ | `butt | `round | `square | `unknown];
  [@bs.get] external lineCapGet': t => string = "lineCap";
  let lineCapGet = t =>
    switch (t->lineCapGet' |> lineCapFromJs) {
    | Some(lineCap) => lineCap
    | None => `unknown
    };
  [@bs.set] external lineCapSet': (t, string) => unit = "lineCap";
  let lineCapSet = (t, lineCap) => t->lineCapSet'(lineCap |> lineCapToJs);

  [@bs.deriving jsConverter]
  type lineJoin = [ | `bevel | `round | `miter | `unknown];
  [@bs.get] external lineJoinGet': t => string = "lineJoin";
  let lineJoinGet = t =>
    switch (t->lineJoinGet' |> lineJoinFromJs) {
    | Some(lineJoin) => lineJoin
    | None => `unknown
    };
  [@bs.set] external lineJoinSet': (t, string) => unit = "lineJoin";
  let lineJoinSet = (t, lineJoin) =>
    t->lineJoinSet'(lineJoin |> lineJoinToJs);

  [@bs.deriving jsConverter]
  type textAlign = [
    | `left
    | `right
    | `center
    | `start
    | [@bs.as "end"] `end_
    | `unknown
  ];
  [@bs.get] external textAlignGet': t => string = "textAlign";
  let textAlignGet = t =>
    switch (t->textAlignGet' |> textAlignFromJs) {
    | Some(textAlign) => textAlign
    | None => `unknown
    };
  [@bs.set] external textAlignSet': (t, string) => unit = "textAlign";
  let textAlignSet = (t, textAlign) =>
    t->textAlignSet'(textAlign |> textAlignToJs);

  [@bs.deriving jsConverter]
  type textBaseLine = [ | `top | `middle | `alphabetic | `bottom | `unknown];
  [@bs.get] external textBaseLineGet': t => string = "textBaseLine";
  let textBaseLineGet = t =>
    switch (t->textBaseLineGet' |> textBaseLineFromJs) {
    | Some(textBaseLine) => textBaseLine
    | None => `unknown
    };
  [@bs.set] external textBaseLineSet': (t, string) => unit = "textBaseLine";
  let textBaseLineSet = (t, textBaseLine) =>
    t->textBaseLineSet'(textBaseLine |> textBaseLineToJs);

  [@bs.get] external fillStyleColorGet: t => string = "fillStyle";
  [@bs.set] external fillStyleColorSet: (t, string) => unit = "fillStyle";
  [@bs.get] external fillStyleGradientGet: t => gradient = "fillStyle";
  [@bs.set] external fillStyleGradientSet: (t, gradient) => unit = "fillStyle";
  [@bs.get] external fillStylePatternGet: t => pattern = "fillStyle";
  [@bs.set] external fillStylePatternSet: (t, pattern) => unit = "fillStyle";

  [@bs.get] external strokeStyleColorGet: t => string = "strokeStyle";
  [@bs.set] external strokeStyleColorSet: (t, string) => unit = "strokeStyle";
  [@bs.get] external strokeStyleGradientGet: t => gradient = "strokeStyle";
  [@bs.set]
  external strokeStyleGradientSet: (t, gradient) => unit = "strokeStyle";
  [@bs.get] external strokeStylePatternGet: t => pattern = "strokeStyle";
  [@bs.set]
  external strokeStylePatternSet: (t, pattern) => unit = "strokeStyle";

  [@bs.send]
  external createLinearGradient: (t, float, float, float, float) => gradient =
    "";
  [@bs.send]
  external createRadialGradient:
    (t, float, float, float, float, float, float) => gradient =
    "";

  [@bs.deriving jsConverter]
  type repetition = [
    | `repeat
    | [@bs.as "repeat-x"] `repeatX
    | [@bs.as "repeat-y"] `repeatY
    | [@bs.as "no-repeat"] `noRepeat
  ];
  [@bs.send]
  external createPatternFromImage': (t, Image.t, string) => pattern =
    "createPattern";
  let createPatternFromImage = (t, image, repetion) =>
    t->createPatternFromImage'(image, repetion |> repetitionToJs);

  [@bs.deriving jsConverter]
  type patternQuality = [ | `fast | `good | `best | `unknown];
  [@bs.get] external patternQualityGet': t => string = "patternQuality";
  let patternQualityGet = t =>
    switch (t->patternQualityGet' |> patternQualityFromJs) {
    | Some(patternQuality) => patternQuality
    | None => `unknown
    };
  [@bs.set]
  external patternQualitySet': (t, string) => unit = "patternQuality";
  let patternQualitySet = (t, patternQuality) =>
    t->patternQualitySet'(patternQuality |> patternQualityToJs);

  [@bs.deriving jsConverter]
  type textDrawingMode = [ | `path | `glyph | `unknown];
  [@bs.get] external textDrawingModeGet': t => string = "textDrawingMode";
  let textDrawingModeGet = t =>
    switch (t->textDrawingModeGet' |> textDrawingModeFromJs) {
    | Some(textDrawingMode) => textDrawingMode
    | None => `unknown
    };
  [@bs.set]
  external textDrawingModeSet': (t, string) => unit = "textDrawingMode";
  let textDrawingModeSet = (t, textDrawingMode) =>
    t->textDrawingModeSet'(textDrawingMode |> textDrawingModeToJs);

  [@bs.deriving jsConverter]
  type antialias = [ | `default | `none | `gray | `subpixel | `unknown];
  [@bs.get] external antialiasGet': t => string = "antialias";
  let antialiasGet = t =>
    switch (t->antialiasGet' |> antialiasFromJs) {
    | Some(antialias) => antialias
    | None => `unknown
    };
  [@bs.set] external antialiasSet': (t, string) => unit = "antialias";
  let antialiasSet = (t, antialias) =>
    t->antialiasSet'(antialias |> antialiasToJs);

  [@bs.send] external clearRect: (t, float, float, float, float) => unit = "";
  [@bs.send] external fillRect: (t, float, float, float, float) => unit = "";
  [@bs.send] external strokeRect: (t, float, float, float, float) => unit = "";
  [@bs.send]
  external fillText:
    (t, string, float, float, ~maxWidth: float=?, unit) => unit =
    "";
  [@bs.send]
  external strokeText:
    (t, string, float, float, ~maxWidth: float=?, unit) => unit =
    "";
  [@bs.send] external measureText: (t, string) => TextMetrics.t = "";
  [@bs.send] external beginPath: t => unit = "";
  [@bs.send] external closePath: t => unit = "";
  [@bs.send] external moveTo: (t, float, float) => unit = "";
  [@bs.send] external lineTo: (t, float, float) => unit = "";
  [@bs.send]
  external quadraticCurveTo: (t, float, float, float, float) => unit = "";
  [@bs.send]
  external bezierCurveTo: (t, float, float, float, float, float, float) => unit =
    "";
  [@bs.send]
  external arc:
    (t, float, float, float, float, float, ~anticlockwise: bool=?, unit) =>
    unit =
    "";
  [@bs.send]
  external arcTo: (t, float, float, float, float, float) => unit = "";
  [@bs.send] external rect: (t, float, float, float, float) => unit = "";
  [@bs.send] external fill: t => unit = "";
  [@bs.send] external stroke: t => unit = "";
  [@bs.send] external clip: t => unit = "";
  [@bs.send] external isPointInPath: (t, float, float) => bool = "";
  [@bs.send] external rotate: (t, float) => unit = "";
  [@bs.send] external scale: (t, float, float) => unit = "";
  [@bs.send] external translate: (t, float, float) => unit = "";
  [@bs.send]
  external transform: (t, float, float, float, float, float, float) => unit =
    "";
  [@bs.send]
  external setTransform: (t, float, float, float, float, float, float) => unit =
    "";
  [@bs.send] external resetTransform: t => unit = "";

  [@bs.send] external drawImage: (t, Image.t, float, float) => unit = "";
  [@bs.send]
  external drawImageDst: (t, Image.t, float, float, float, float) => unit =
    "drawImage";
  [@bs.send]
  external drawImageSrcDst:
    (t, Image.t, float, float, float, float, float, float, float, float) =>
    unit =
    "drawImage";

  [@bs.send] external createImageData: (t, float, float) => ImageData.t = "";
  [@bs.send]
  external createFromImageData: (t, ImageData.t) => ImageData.t =
    "createImageData";
  [@bs.send]
  external getImageData: (t, float, float, float, float) => ImageData.t = "";
  [@bs.send]
  external putImageData: (t, ImageData.t, float, float) => unit = "";
  [@bs.send]
  external putImageDataDirty:
    (t, ImageData.t, float, float, float, float, float, float) => unit =
    "";

  [@bs.send] external save: t => unit = "";
  [@bs.send] external restore: t => unit = "";

  [@bs.get]
  external canvasGet': t => Js.Nullable.t(htmlCanvasElement) = "canvas";
  let canvasGet = t => t->canvasGet' |> Js.Nullable.toOption;
};

[@bs.send]
external createPatternFromCanvas':
  (CanvasRenderingContext2D.t, t, string) => CanvasRenderingContext2D.pattern =
  "createPattern";
let createPatternFromCanvas = (t, canvas, repetion) =>
  t
  ->createPatternFromCanvas'(
      canvas,
      repetion |> CanvasRenderingContext2D.repetitionToJs,
    );

[@bs.send]
external drawCanvas: (CanvasRenderingContext2D.t, t, float, float) => unit =
  "drawImage";
[@bs.send]
external drawCanvasDst:
  (CanvasRenderingContext2D.t, t, float, float, float, float) => unit =
  "drawImage";
[@bs.send]
external drawCanvasSrcDst:
  (
    CanvasRenderingContext2D.t,
    t,
    float,
    float,
    float,
    float,
    float,
    float,
    float,
    float
  ) =>
  unit =
  "drawImage";

[@bs.send] external getContext': (t, string) => 'a = "getContext";
let getContext = (canvas, contextType) =>
  canvas->getContext'(contextType |> renderingContextToJs);
let getCanvasRenderingContext2D = canvas: CanvasRenderingContext2D.t =>
  canvas->getContext(`CanvasRenderingContext2D);