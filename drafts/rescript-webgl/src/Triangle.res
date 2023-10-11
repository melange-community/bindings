open Belt
open Dom
open Js.Typed_array
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

let vertices = Float32Array.make([-1.0, -1.0, 0.0, 1.0, 1.0, -1.0])

let buffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, buffer)
gl->bufferData(#ArrayBuffer, vertices->Float32Array.buffer, #StaticDraw)

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
gl->drawArrays(#Triangles, ~offset=0, ~count=3)
