const path = require("path");

module.exports = {
  entry: path.join(__dirname, "/lib/es6_global/example/Example.js"),
  output: {
    path: path.join(__dirname, "/example"),
    filename: "bundle.js"
  }
};
