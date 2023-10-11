(() => {
  // lib/es6/src/Audio__AudioBlob.bs.js
  function createFromBlob(blob) {
    return new Blob([blob], {
      type: "audio/ogg; codecs=opus"
    });
  }
  function createUrlFromBlob(blob) {
    return URL.createObjectURL(createFromBlob(blob));
  }

  // lib/es6/src/Audio__AudioNode.bs.js
  function setGainValue(gainNode, value, startTime) {
    gainNode.gain.setValueAtTime(value, startTime);
  }

  // node_modules/rescript/lib/es6/caml_exceptions.js
  var id = {
    contents: 0
  };
  function create(str) {
    id.contents = id.contents + 1 | 0;
    return str + ("/" + id.contents);
  }
  function caml_is_extension(e) {
    if (e == null) {
      return false;
    } else {
      return typeof e.RE_EXN_ID === "string";
    }
  }

  // node_modules/rescript/lib/es6/js_exn.js
  function raiseError(str) {
    throw new Error(str);
  }

  // node_modules/rescript/lib/es6/caml_array.js
  function sub(x, offset, len) {
    var result = new Array(len);
    var j = 0;
    var i = offset;
    while (j < len) {
      result[j] = x[i];
      j = j + 1 | 0;
      i = i + 1 | 0;
    }
    ;
    return result;
  }

  // node_modules/rescript/lib/es6/curry.js
  function app(_f, _args) {
    while (true) {
      var args = _args;
      var f = _f;
      var init_arity = f.length;
      var arity = init_arity === 0 ? 1 : init_arity;
      var len = args.length;
      var d = arity - len | 0;
      if (d === 0) {
        return f.apply(null, args);
      }
      if (d >= 0) {
        return function(f2, args2) {
          return function(x) {
            return app(f2, args2.concat([x]));
          };
        }(f, args);
      }
      _args = sub(args, arity, -d | 0);
      _f = f.apply(null, sub(args, 0, arity));
      continue;
    }
    ;
  }
  function _1(o, a0) {
    var arity = o.length;
    if (arity === 1) {
      return o(a0);
    } else {
      switch (arity) {
        case 1:
          return o(a0);
        case 2:
          return function(param) {
            return o(a0, param);
          };
        case 3:
          return function(param, param$1) {
            return o(a0, param, param$1);
          };
        case 4:
          return function(param, param$1, param$2) {
            return o(a0, param, param$1, param$2);
          };
        case 5:
          return function(param, param$1, param$2, param$3) {
            return o(a0, param, param$1, param$2, param$3);
          };
        case 6:
          return function(param, param$1, param$2, param$3, param$4) {
            return o(a0, param, param$1, param$2, param$3, param$4);
          };
        case 7:
          return function(param, param$1, param$2, param$3, param$4, param$5) {
            return o(a0, param, param$1, param$2, param$3, param$4, param$5);
          };
        default:
          return app(o, [a0]);
      }
    }
  }

  // node_modules/@ryyppy/rescript-promise/lib/es6/src/Promise.bs.js
  var JsError = /* @__PURE__ */ create("Promise.JsError");
  function $$catch(promise, callback) {
    return promise.catch(function(err) {
      return _1(callback, caml_is_extension(err) ? err : {
        RE_EXN_ID: JsError,
        _1: err
      });
    });
  }

  // lib/es6/src/Audio__MediaStream.bs.js
  function getStream(param) {
    var maybeMediaDevices = navigator.mediaDevices;
    if (maybeMediaDevices !== void 0) {
      return $$catch(maybeMediaDevices.getUserMedia({
        video: false,
        audio: true
      }).then(function(stream) {
        return Promise.resolve({
          TAG: 0,
          _0: stream
        });
      }), function(err) {
        return Promise.resolve({
          TAG: 1,
          _0: err
        });
      });
    } else {
      return Promise.resolve({
        TAG: 1,
        _0: raiseError("The method getUserMedia is not supported in this environment")
      });
    }
  }

  // lib/es6/src/Audio__MediaRecorder.bs.js
  function start(mediaRecorder, onDataAvailable2) {
    mediaRecorder.ondataavailable = onDataAvailable2;
    mediaRecorder.start();
  }

  // lib/es6/src/Demo.bs.js
  function setupEventListeners(onPause, onStart, onResume, onStop) {
    var selector = document.querySelector("audio");
    var audioContext = new AudioContext();
    var sourceNode = audioContext.createMediaElementSource(selector);
    var gain = audioContext.createGain();
    var mute = function(_e) {
      return setGainValue(gain, 0, audioContext.currentTime);
    };
    var boost = function(param) {
      return setGainValue(gain, 2, audioContext.currentTime);
    };
    console.log(sourceNode.connect(gain).connect(audioContext.destination));
    var addClickEvent = function(selector2, listener) {
      document.querySelector(selector2).addEventListener("click", listener);
    };
    addClickEvent("#start", onStart);
    addClickEvent("#pause", onPause);
    addClickEvent("#resume", onResume);
    addClickEvent("#stop", onStop);
    addClickEvent("#mute", mute);
    return addClickEvent("#boost", boost);
  }
  function updateAudioElementSrc(src) {
    document.querySelector("source").setAttribute("src", src);
  }
  var $$Document = {
    setupEventListeners,
    updateAudioElementSrc
  };
  var chunks = [];
  function onDataAvailable($$event) {
    return updateAudioElementSrc(createUrlFromBlob($$event.data));
  }
  var main = getStream(void 0).then(function(v) {
    if (v.TAG === 0) {
      var recorder = new MediaRecorder(v._0);
      var onStart = function(param) {
        start(recorder, onDataAvailable);
        console.log(recorder.state);
      };
      var onStop = function(param) {
        recorder.stop();
        console.log(recorder.state);
      };
      var onResume = function(param) {
        recorder.resume();
      };
      var onPause = function(param) {
        recorder.pause();
      };
      return setupEventListeners(onPause, onStart, onResume, onStop);
    }
    console.log(v._0);
  });
})();
