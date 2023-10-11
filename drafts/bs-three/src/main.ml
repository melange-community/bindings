let _ = Js.log "Three.js BuckleScript binding r1"

open Three
open PromiseMonad

type document
type element = Dom.element
external document:document = "" [@@bs.val]
external width:int = "window.innerWidth" [@@bs.val]
external height:int = "window.innerHeight" [@@bs.val]
external getElementById: string -> element = "" [@@bs.val][@@bs.scope "document"]
external appendChild: element -> element -> unit = "" [@@bs.send]
external textContent: element -> string -> unit= "" [@@bs.set]
external createElement: document -> string -> unit -> element = "" [@@bs.send]
external requestAnimationFrame: (float -> unit) -> unit = "" [@@bs.val][@@bs.scope "window"] 


let createDiv = createElement document "div"
let mainDiv = getElementById "main"


let newDiv = createDiv ()

let ratio = (float_of_int width) /. (float_of_int height)

let scene = Scene.make ()
let camera = Camera.Perspective.make ~fov:45.0 ~aspect:ratio ~near:1.0 ~far:1000.0

let renderer = WebGLRenderer.make ()
let _ = renderer##setSize width height
let _ = appendChild mainDiv renderer##domElement

let geometry = Geometry.Box.make 1 1 1
let material = Material.MeshBasic.make [%bs.obj { color = int_of_string "0x00ff00" }]
let cube = Mesh.make geometry material

let v = [%bs.obj { x=0;y=32;z=0}]
let vv = Vector3.make 0 1 0


let _ =
    Scene.add scene cube;
    cube##rotation##x #= 10.0;
    camera##position##z #= 5.0
    
let render renderer t =
    Mesh.rotate cube vv t;
    renderer##render scene camera

let angle = ref 0.0
let rec animate timestamp =
    (* Js.log(!angle); *)
    render renderer !angle;
    (* vv##x = !angle /. 3.141 *)
    (* vv##y = (3.141 - !angle) /. 3.141 *)
    angle := mod_float (!angle +. 0.05) 3.141;
    requestAnimationFrame(animate)

let _ = animate(0.0)