open Belt
open Dom
open Vec2
open WebGl

let canvas = querySelector("canvas")->Option.getExn
let gl = canvas->getContext->Option.getExn

let program = {
  let vertexShader =
    gl
    ->makeVertexShader(`
      attribute vec4 vPosition;

      void main() {
        gl_Position = vPosition;
      }
      `)
    ->Option.getExn

  let fragmentShader =
    gl
    ->makeFragmentShader(`
      precision mediump float;

      void main() {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
      }
      `)
    ->Option.getExn

  gl->makeProgram(vertexShader, fragmentShader)->Option.getExn
}

gl->useProgram(program)

let points = {
  let rec divideTriangles = (points, a, b, c, count) => {
    if count == 0 {
      list{a, b, c, ...points}
    } else {
      let ab = a->mix(b, 0.5)
      let ac = a->mix(c, 0.5)
      let bc = b->mix(c, 0.5)

      points
      ->divideTriangles(a, ab, ac, count - 1)
      ->divideTriangles(b, bc, ab, count - 1)
      ->divideTriangles(c, ac, bc, count - 1)
    }
  }

  let makeTriangles = (a, b, c, count) => divideTriangles(list{}, a, b, c, count)->List.toArray

  let (v0, v1, v2) = ((-1.0, -1.0), (0.0, 1.0), (1.0, -1.0))
  let subdivisions = 5

  makeTriangles(v0, v1, v2, subdivisions)
}

let buffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, buffer)
gl->bufferData(#ArrayBuffer, points->Vec2.flatten, #StaticDraw)

let vPosition = gl->getAttribLocation(program, "vPosition")->Option.getExn
gl->vertexAttribPointer(
  vPosition,
  ~size=2,
  ~dataType=#Float,
  ~normalized=false,
  ~stride=0,
  ~offset=0,
)
gl->enableVertexAttribArray(vPosition)

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=1.0, ~g=1.0, ~b=1.0, ~a=1.0)
gl->clear(#ColorBuffer)
gl->drawArrays(#Triangles, ~offset=0, ~count=points->Array.length)
