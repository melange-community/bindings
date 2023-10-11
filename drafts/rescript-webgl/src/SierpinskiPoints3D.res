open Belt
open Dom
open Vec3
open WebGl

let canvas = querySelector("canvas")->Option.getExn
let gl = canvas->getContext->Option.getExn

let program = {
  let vertexShader =
    gl
    ->makeVertexShader(`
      attribute vec4 vPosition;
      varying vec4 fColor;

      void main() {
        fColor = vec4((1.0 + vPosition.xyz) / 2.0, 1.0);
        gl_PointSize = 1.0;
        gl_Position = vPosition;
      }
      `)
    ->Option.getExn

  let fragmentShader =
    gl
    ->makeFragmentShader(`
      precision mediump float;

      varying vec4 fColor;

      void main() {
        gl_FragColor = fColor;
      }
      `)
    ->Option.getExn

  gl->makeProgram(vertexShader, fragmentShader)->Option.getExn
}

gl->useProgram(program)

let vertices = {
  let (v0, v1, v2, v3) = (
    (0.0000, 0.0000, -1.0000),
    (0.0000, 0.9428, 0.3333),
    (-0.8165, -0.4714, 0.3333),
    (0.8165, -0.4714, 0.3333),
  )
  let numPoints = 500_000

  let p = (0.0, 0.0, 0.0)->ref

  Array.makeBy(numPoints, _ => {
    let vertex = switch Js.Math.random_int(0, 4) {
    | 0 => v0
    | 1 => v1
    | 2 => v2
    | _ => v3
    }

    p := p.contents->mix(vertex, 0.5)
    p.contents
  })
}

let buffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, buffer)
gl->bufferData(#ArrayBuffer, vertices->flatten, #StaticDraw)

let vPosition = gl->getAttribLocation(program, "vPosition")->Option.getExn
gl->vertexAttribPointer(
  vPosition,
  ~size=3,
  ~dataType=#Float,
  ~normalized=false,
  ~stride=0,
  ~offset=0,
)
gl->enableVertexAttribArray(vPosition)

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=1.0, ~g=1.0, ~b=1.0, ~a=1.0)
gl->clear(#ColorBuffer)
gl->drawArrays(#Points, ~offset=0, ~count=vertices->Array.length)
