[@bs.module "util"]
external getSystemErrorName: int => string = "getSystemErrorName";

type inspectOptions;
[@bs.obj]
external inspectOptions:
  (
    ~showHidden: bool=?,
    ~depth: int=?,
    ~colors: bool=?,
    ~customInspect: bool=?,
    ~showProxy: bool=?,
    ~maxArrayLength: int=?,
    ~breakLength: int=?,
    ~compact: bool=?,
    ~sorted: bool=?,
    ~getters: bool=?,
    unit
  ) =>
  inspectOptions;

module Types = {
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isAnyArrayBuffer: 'a => bool = "isAnyArrayBuffer";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isArgumentsObject: 'a => bool = "isArgumentsObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isAsyncFunction: 'a => bool = "isAsyncFunction";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isBigInt64Array: 'a => bool = "isBigInt64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isBigUint64Array: 'a => bool = "isBigUint64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isBooleanObject: 'a => bool = "isBooleanObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isBoxedPrimitive: 'a => bool = "isBoxedPrimitive";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isDataView: 'a => bool = "isDataView";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isDate: 'a => bool = "isDate";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isExternal: 'a => bool = "isExternal";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isFloat32Array: 'a => bool = "isFloat32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isFloat64Array: 'a => bool = "isFloat64Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isGeneratorObject: 'a => bool = "isGeneratorObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isInt8Array: 'a => bool = "isInt8Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isInt16Array: 'a => bool = "isInt16Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isInt32Array: 'a => bool = "isInt32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isMap: 'a => bool = "isMap";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isMapIterator: 'a => bool = "isMapIterator";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isModuleNamespaceObject: 'a => bool = "isModuleNamespaceObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isNumberObject: 'a => bool = "isNumberObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isPromise: 'a => bool = "isPromise";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isProxy: 'a => bool = "isProxy";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isRegExp: 'a => bool = "isRegExp";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isSet: 'a => bool = "isSet";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isSetIterator: 'a => bool = "isSetIterator";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isSharedArrayBuffer: 'a => bool = "isSharedArrayBuffer";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isStringObject: 'a => bool = "isStringObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isSymbolObject: 'a => bool = "isSymbolObject";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isUint8Array: 'a => bool = "isUint8Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isUint8ClampedArray: 'a => bool = "isUint8ClampedArray";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isUint16Array: 'a => bool = "isUint16Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isUint32Array: 'a => bool = "isUint32Array";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isWeakMap: 'a => bool = "isWeakMap";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isWeakSet: 'a => bool = "isWeakSet";
  [@bs.val] [@bs.module "util"] [@bs.scope "types"]
  external isWebAssemblyCompiledModule: 'a => bool =
    "isWebAssemblyCompiledModule";
};
