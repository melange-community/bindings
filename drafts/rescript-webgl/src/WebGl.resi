type glT

type clearMaskT = [#DepthBuffer | #ColorBuffer | #DepthAndColorBuffer]

type capabilityT = [#DepthTest]

type drawModeT = [#Points | #Lines | #Triangles | #TriangleStrip | #TriangleFan]

type vertexShaderT
type fragmentShaderT
type programT

type bufferT

type targetT = [#ArrayBuffer]
type usageT = [#StaticDraw]

type attribLocationT
type uniformLocationT

type dataTypeT = [#Float]

@send @return(nullable)
external getContext: (Dom.elementT, @as("webgl") _) => option<glT> = "getContext"
@send external viewport: (glT, ~x: int, ~y: int, ~width: int, ~height: int) => unit = "viewport"
@send
external clearColor: (glT, ~r: float, ~g: float, ~b: float, ~a: float) => unit = "clearColor"

@send
external clear: (
  glT,
  @int
  [
    | @as(0x00000100)
    #DepthBuffer
    | @as(0x00004000)
    #ColorBuffer
    | @as(0x00004100)
    #DepthAndColorBuffer
  ],
) => unit = "clear"
@send external enable: (glT, @int [@as(0x0B71) #DepthTest]) => unit = "enable"

@send
external drawArrays: (
  glT,
  @int
  [
    | @as(0x0000)
    #Points
    | @as(0x0001)
    #Lines
    | @as(0x0004)
    #Triangles
    | @as(0x0005)
    #TriangleStrip
    | @as(0x0006)
    #TriangleFan
  ],
  ~offset: int,
  ~count: int,
) => unit = "drawArrays"

let makeVertexShader: (glT, string) => option<vertexShaderT>
let makeFragmentShader: (glT, string) => option<fragmentShaderT>

let makeProgram: (glT, vertexShaderT, fragmentShaderT) => option<programT>
@send external useProgram: (glT, programT) => unit = "useProgram"

@send @return(nullable) external createBuffer: glT => option<bufferT> = "createBuffer"
@send
external bindBuffer: (glT, @int [@as(0x8892) #ArrayBuffer], bufferT) => unit = "bindBuffer"
@send
external bufferData: (
  glT,
  @int [@as(0x8892) #ArrayBuffer],
  Js.Typed_array.ArrayBuffer.t,
  @int [@as(0x88E4) #StaticDraw],
) => unit = "bufferData"
@send
external bufferDataUninitialized: (
  glT,
  @int [@as(0x8892) #ArrayBuffer],
  int,
  @int [@as(0x88E4) #StaticDraw],
) => unit = "bufferData"
@send
external bufferSubData: (
  glT,
  @int [@as(0x8892) #ArrayBuffer],
  int,
  Js.Typed_array.ArrayBuffer.t,
) => unit = "bufferSubData"

let getAttribLocation: (glT, programT, string) => option<attribLocationT>
@send
external vertexAttribPointer: (
  glT,
  attribLocationT,
  ~size: int,
  ~dataType: @int [@as(0x1406) #Float],
  ~normalized: bool,
  ~stride: int,
  ~offset: int,
) => unit = "vertexAttribPointer"
@send
external enableVertexAttribArray: (glT, attribLocationT) => unit = "enableVertexAttribArray"

@send @return(nullable)
external getUniformLocation: (glT, programT, string) => option<uniformLocationT> =
  "getUniformLocation"

@send external uniform1f: (glT, uniformLocationT, float) => unit = "uniform1f"
