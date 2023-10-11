open Belt
open Dom
open WebGl

let canvas = querySelector("canvas")->Option.getExn
let gl = canvas->getContext->Option.getExn

let vertexShader =
  gl
  ->makeVertexShader(`
    attribute vec4 vPosition;
    uniform float theta;

    void main() {
        float x = -sin(theta) * vPosition.x + cos(theta) * vPosition.y;
        float y = sin(theta) * vPosition.y + cos(theta) * vPosition.x;
        gl_Position = vec4(x, y, 0.0, 1.0);
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

let program = gl->makeProgram(vertexShader, fragmentShader)->Option.getExn

gl->useProgram(program)

let points = [(0.0, 1.0), (-1.0, 0.0), (1.0, 0.0), (0.0, -1.0)]

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

let thetaLoc = gl->getUniformLocation(program, "theta")->Option.getExn
let theta = ref(0.0)

let rec render = () => {
  gl->clear(#ColorBuffer)

  theta := theta.contents +. 0.1

  gl->uniform1f(thetaLoc, theta.contents)
  gl->drawArrays(#TriangleStrip, ~offset=0, ~count=Array.length(points))

  requestAnimationFrame(render)
}

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=1.0, ~g=1.0, ~b=1.0, ~a=1.0)
render()
