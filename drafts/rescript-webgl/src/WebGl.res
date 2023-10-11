open Belt

type glT

type clearMaskT = [#DepthBuffer | #ColorBuffer | #DepthAndColorBuffer]

type capabilityT = [#DepthTest]

type drawModeT = [#Points | #Lines | #Triangles | #TriangleStrip | #TriangleFan]

type shaderT
type vertexShaderT = shaderT
type fragmentShaderT = shaderT

type programT

type bufferT

type targetT = [#ArrayBuffer]
type usageT = [#StaticDraw]

type attribLocationT = int
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

@send @return(nullable)
external createShader: (
  glT,
  @int [@as(0x8B31) #VertexShader | @as(0x8B30) #FragmentShader],
) => option<shaderT> = "createShader"

@send external shaderSource: (glT, shaderT, string) => unit = "shaderSource"
@send external compileShader: (glT, shaderT) => unit = "compileShader"
@send
external getShaderParamBool: (glT, shaderT, @int [@as(0x8B81) #CompileStatus]) => bool =
  "getShaderParameter"

@send external createProgram: glT => option<programT> = "createProgram"
@send external attachShader: (glT, programT, shaderT) => unit = "attachShader"
@send external linkProgram: (glT, programT) => unit = "linkProgram"
@send
external getProgramParamBool: (glT, programT, @int [@as(0x8B82) #LinkStatus]) => bool =
  "getProgramParameter"
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

@send external _getAttribLocation: (glT, programT, string) => int = "getAttribLocation"
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

let makeShader = (ctx: glT, typ: [#VertexShader | #FragmentShader], src: string): option<shaderT> =>
  ctx
  ->createShader(typ)
  ->Option.flatMap(shader => {
    ctx->shaderSource(shader, src)
    ctx->compileShader(shader)
    ctx->getShaderParamBool(shader, #CompileStatus) ? Some(shader) : None
  })

let makeVertexShader = (ctx: glT, src: string): option<vertexShaderT> =>
  ctx->makeShader(#VertexShader, src)

let makeFragmentShader = (ctx: glT, src: string): option<fragmentShaderT> =>
  ctx->makeShader(#FragmentShader, src)

let makeProgram = (ctx: glT, vert: vertexShaderT, frag: fragmentShaderT): option<programT> =>
  ctx
  ->createProgram
  ->Option.flatMap(program => {
    ctx->attachShader(program, vert)
    ctx->attachShader(program, frag)
    ctx->linkProgram(program)
    ctx->getProgramParamBool(program, #LinkStatus) ? Some(program) : None
  })

let getAttribLocation = (ctx: glT, program: programT, src: string): option<attribLocationT> =>
  switch _getAttribLocation(ctx, program, src) {
  | -1 => None
  | loc => Some(loc)
  }
