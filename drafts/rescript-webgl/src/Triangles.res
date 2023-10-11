open Belt
open Dom
open WebGl

let canvas = querySelector("canvas")->Option.getExn
let gl = canvas->getContext->Option.getExn

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

canvas->onClick(event =>
  if numPoints.contents < maxPoints {
    let (offsetX, offsetY) = (event->getOffsetX, event->getOffsetY)
    let (width, height) = (canvas->getHeight->float_of_int, canvas->getWidth->float_of_int)
    let t = (-1.0 +. 2.0 *. offsetX /. width, -1.0 +. 2.0 *. (height -. offsetY) /. height)

    gl->bindBuffer(#ArrayBuffer, positionBuffer)
    gl->bufferSubData(#ArrayBuffer, Vec2.size * numPoints.contents, [t]->Vec2.flatten)

    let color = {
      let colors = [
        (0.0, 0.0, 0.0), // black
        (1.0, 0.0, 0.0), // red
        (1.0, 1.0, 0.0), // yellow
        (0.0, 1.0, 0.0), // green
        (0.0, 0.0, 1.0), // blue
        (1.0, 0.0, 1.0), // magenta
        (0.0, 1.0, 1.0), // cyan
      ]

      colors[mod(numPoints.contents, 7)]->Option.getExn
    }
    gl->bindBuffer(#ArrayBuffer, colorBuffer)
    gl->bufferSubData(#ArrayBuffer, Vec3.size * numPoints.contents, [color]->Vec3.flatten)
    numPoints := numPoints.contents + 1
  }
)

let rec render = () => {
  gl->clear(#ColorBuffer)

  switch numPoints.contents {
  | 0 => ()
  | 1 => gl->drawArrays(#Points, ~offset=0, ~count=1)
  | 2 => gl->drawArrays(#Lines, ~offset=0, ~count=2)
  | n => gl->drawArrays(#TriangleStrip, ~offset=0, ~count=n)
  }

  requestAnimationFrame(render)
}

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=0.5, ~g=0.5, ~b=0.5, ~a=1.0)
render()
