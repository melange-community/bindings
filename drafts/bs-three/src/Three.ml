
type vec3 = < x:int ; y:int ; z:int > Js.t

module rec Math:
sig
    module Euler:
    sig
        class type _euler = object
            method x: float [@@bs.set]
            method y: float [@@bs.set]
            method z: float [@@bs.set]
        end [@bs] 
        type t = _euler Js.t
        external make: int -> int -> int -> t = "Euler" [@@bs.new] [@@bs.module "THREE"] 
    end
end = Math

module rec Vector3:
sig
    class type _vector3 = object
        method x: float [@@bs.set]
        method y: float [@@bs.set]
        method z: float [@@bs.set]
    end [@bs] 
    type t = _vector3 Js.t
    external make: int -> int -> int -> Vector3.t = "Vector3" [@@bs.new] [@@bs.module "THREE"] 
end = Vector3

module rec Camera:
sig
    class type _camera = object
        method position: Vector3.t
    end [@bs] 
    type t = _camera Js.t
    module Perspective:
        sig
        external make : ?fov:float -> ?aspect:float -> ?near:float -> far:float -> t = "PerspectiveCamera" [@@bs.new] [@@bs.module "THREE"]
        end
end = Camera

module rec Geometry:
sig
    type t
    module Box:
        sig
            external make: int -> int -> int -> t = "BoxGeometry" [@@bs.new] [@@bs.module "THREE"] 
        end
end = Geometry


module rec Material:
sig
    type t
    module MeshBasic:
        sig
            external make: < color: int > Js.t -> t = "MeshBasicMaterial" [@@bs.new] [@@bs.module "THREE"] 
        end
end = Material

module rec Mesh:
sig
    class type _mesh = object
        method rotation: Math.Euler.t
    end [@bs]
    type t = _mesh Js.t
    external rotate: Mesh.t -> Vector3.t -> float -> unit = "setRotationFromAxisAngle" [@@bs.send]
    external make: Geometry.t -> Material.t -> Mesh.t = "Mesh" [@@bs.new] [@@bs.module "THREE"] 
end = Mesh

module rec Scene:
sig
    class type _scene = object
        method add: Mesh.t -> unit
    end [@bs] 
    type t = _scene Js.t
    external make: unit -> Scene.t = "Scene" [@@bs.new] [@@bs.module "THREE"] 
    external add: t -> Mesh.t -> unit = "" [@@bs.send]
end = Scene 

module rec WebGLRenderer:
sig
    class type _webGLRenderer = object
        method setSize: int -> int -> unit
        method domElement: Dom.element
        method render: Scene.t -> Camera.t -> unit
    end [@bs]
    type t = _webGLRenderer Js.t
    external make: unit -> t = "WebGLRenderer" [@@bs.new] [@@bs.module "THREE"] 
end = WebGLRenderer