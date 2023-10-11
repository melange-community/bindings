open Dom
open Js
open WebGl

let canvas = querySelector("canvas")->Option.getExn
let gl = canvas->getContext->Option.getExn

let colorPicker = querySelector("#color-picker")->Option.getExn
let endPolygonBtn = querySelector("#end-polygon")->Option.getExn

let program = {
  let vertexShader =
    gl
    ->makeVertexShader(`
        attribute vec4 vPosition;
        attribute vec4 vColor;
        varying vec4 fColor;

        void main() {
            gl_Position = vPosition;
            gl_PointSize = 5.0;
            fColor = vColor;
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

let maxPoints = 200

let positionBuffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, positionBuffer)
gl->bufferDataUninitialized(#ArrayBuffer, Vec2.size * maxPoints, #StaticDraw)

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

let colorBuffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, colorBuffer)
gl->bufferDataUninitialized(#ArrayBuffer, Vec3.size * maxPoints, #StaticDraw)

let vColor = gl->getAttribLocation(program, "vColor")->Option.getExn
gl->vertexAttribPointer(vColor, ~size=3, ~dataType=#Float, ~normalized=false, ~stride=0, ~offset=0)
gl->enableVertexAttribArray(vColor)

let numPoints = ref(0)
let currentPoints = ref(0)

let polygonPoints = []

endPolygonBtn->onClick(_ => {
  Array.push(currentPoints.contents, polygonPoints)->ignore
  currentPoints := 0
})

canvas->onClick(event =>
  if numPoints.contents < maxPoints {
    let (offsetX, offsetY) = (event->getOffsetX, event->getOffsetY)
    let (width, height) = (canvas->getHeight->float_of_int, canvas->getWidth->float_of_int)
    let t = (-1.0 +. 2.0 *. offsetX /. width, -1.0 +. 2.0 *. (height -. offsetY) /. height)

    gl->bindBuffer(#ArrayBuffer, positionBuffer)
    gl->bufferSubData(#ArrayBuffer, Vec2.size * numPoints.contents, [t]->Vec2.flatten)

    let color = {
      let hex = colorPicker->getValue
      let r = ("0x" ++ String.slice(~from=1, ~to_=3, hex))->float_of_string /. 255.0
      let g = ("0x" ++ String.slice(~from=3, ~to_=5, hex))->float_of_string /. 255.0
      let b = ("0x" ++ String.slice(~from=5, ~to_=7, hex))->float_of_string /. 255.0

      (r, g, b)
    }

    gl->bindBuffer(#ArrayBuffer, colorBuffer)
    gl->bufferSubData(#ArrayBuffer, Vec3.size * numPoints.contents, [color]->Vec3.flatten)

    numPoints := numPoints.contents + 1
    currentPoints := currentPoints.contents + 1
  }
)

let rec render = () => {
  gl->clear(#ColorBuffer)

  let offset = Array.reduce((offset, count) => {
    gl->drawArrays(#TriangleFan, ~offset, ~count)
    offset + count
  }, 0, polygonPoints)

  switch currentPoints.contents {
  | 0 => ()
  | 1 => gl->drawArrays(#Points, ~offset, ~count=1)
  | 2 => gl->drawArrays(#Lines, ~offset, ~count=2)
  | n => gl->drawArrays(#TriangleFan, ~offset, ~count=n)
  }

  requestAnimationFrame(render)
}

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=0.5, ~g=0.5, ~b=0.5, ~a=1.0)
render()
