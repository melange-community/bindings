open Belt
open Dom
open WebGl
open Vec3

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
      fColor = vColor;
      gl_Position = vPosition;
    }`)
    ->Option.getExn

  let fragmentShader =
    gl
    ->makeFragmentShader(`
    precision mediump float;
    
    varying vec4 fColor;
    
    void main() {
      gl_FragColor = fColor;
    }`)
    ->Option.getExn

  gl->makeProgram(vertexShader, fragmentShader)->Option.getExn
}

gl->useProgram(program)

let (points, colors) = {
  let triangle = ((points, colors), a, b, c, color) => (
    list{a, b, c, ...points},
    list{color, color, color, ...colors},
  )

  let tetra = (attrs, a, b, c, d) =>
    attrs
    ->triangle(a, c, b, (1.0, 0.0, 0.0))
    ->triangle(a, c, d, (0.0, 1.0, 0.0))
    ->triangle(a, b, d, (0.0, 0.0, 1.0))
    ->triangle(b, c, d, (0.0, 0.0, 0.0))

  let rec divideTetra = (attrs, a, b, c, d, count) =>
    if count == 0 {
      attrs->tetra(a, b, c, d)
    } else {
      let ab = a->mix(b, 0.5)
      let ac = a->mix(c, 0.5)
      let ad = a->mix(d, 0.5)
      let bc = b->mix(c, 0.5)
      let bd = b->mix(d, 0.5)
      let cd = c->mix(d, 0.5)

      attrs
      ->divideTetra(a, ab, ac, ad, count - 1)
      ->divideTetra(ab, b, bc, bd, count - 1)
      ->divideTetra(ac, bc, c, cd, count - 1)
      ->divideTetra(ad, bd, cd, d, count - 1)
    }

  let makeTetra = (a, b, c, d, count) => {
    let (points, colors) = divideTetra((list{}, list{}), a, b, c, d, count)
    (points->List.toArray, colors->List.toArray)
  }

  let (v0, v1, v2, v3) = (
    (0.0000, 0.0000, -1.0000),
    (0.0000, 0.9428, 0.3333),
    (-0.8165, -0.4714, 0.3333),
    (0.8165, -0.4714, 0.3333),
  )
  let subdivisions = 3

  makeTetra(v0, v1, v2, v3, subdivisions)
}

let vBuffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, vBuffer)
gl->bufferData(#ArrayBuffer, points->Vec3.flatten, #StaticDraw)

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

let cBuffer = gl->createBuffer->Option.getExn
gl->bindBuffer(#ArrayBuffer, cBuffer)
gl->bufferData(#ArrayBuffer, colors->Vec3.flatten, #StaticDraw)

let vColor = gl->getAttribLocation(program, "vColor")->Option.getExn
gl->vertexAttribPointer(vColor, ~size=3, ~dataType=#Float, ~normalized=false, ~stride=0, ~offset=0)
gl->enableVertexAttribArray(vColor)

gl->enable(#DepthTest)

gl->viewport(~x=0, ~y=0, ~width=canvas->getWidth, ~height=canvas->getHeight)
gl->clearColor(~r=1.0, ~g=1.0, ~b=1.0, ~a=1.0)
gl->clear(#ColorBuffer)
gl->drawArrays(#Triangles, ~offset=0, ~count=points->Array.length)
