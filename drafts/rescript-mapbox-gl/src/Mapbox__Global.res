type t;
type worker; 
@module("mapbox-gl")
external mapbox: t = "default"
external asWorker : 'a => worker = "%identity"
/**
if you have some custom workerClass e.g: import workerClass from 'xyz', so
```rescript
@module("xyz")
external customWorkerClass: unit => Mapbox.worker = "default"
```
**/
@module("worker-loader!mapbox-gl/dist/mapbox-gl-csp-worker.js")
external mapboxGLWorker:  worker = "default"
@get external getAccessToken: t => string = "accessToken"
@set external setAccessToken: (t, string) => unit = "accessToken"
@get external getBaseApiUrl: t => string = "baseApiUrl"
@set external setBaseApiUrl: (t, string) => unit = "baseApiUrl"
@get external getWorkerClass: t => worker = "workerClass"
@set external setWorkerClass: (t, worker) => unit = "workerClass"
@get external getWorkerCount: t => int = "workerCount"
@set external setWorkerCount: (t, int) => unit = "workerCount"
@get external getMaxParallelImageRequests: t => int = "maxParallelImageRequests"
@set external setMaxParallelImageRequests: (t, int) => unit = "maxParallelImageRequests"
@send external supported: (t,unit) => bool = "supported"
@get external version: t => string = "version"
@send external setRTLTextPlugin: (t, string) => unit = "setRTLTextPlugin"
@send external getRTLTextPluginStatus: (t, unit) => @string [ | #unavailable | #deferred | #loading | #loaded | #error] = "getRTLTextPluginStatus"
@send external clearStorage: (t, unit) => unit = "clearStorage"
@send external prewarm: (t, unit) => unit = "prewarm"
@send external clearPrewarmedResources: (t, unit) => unit = "clearPrewarmedResources"
// TODO
// CameraOptions
// FreeCameraOptions
// PaddingOptions
// RequestParameter
// StyleImageInterface
// CustomLayerInterface
