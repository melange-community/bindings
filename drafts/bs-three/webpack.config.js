const webpack = require("webpack");
const path = require("path");

module.exports = [{
  name: "bundle",
  entry: './src/main.bs.js',
  output: {
    path: __dirname + '/build',
    filename: 'bs-three.js',
  },
  mode: "development",
  devtool: "source-map",
  devServer: {
    contentBase: path.join(__dirname, 'test'),
    compress: true,
  }
}, {
  name: "demo",
  entry: './src/main.bs.js',
  output: {
    path: __dirname + '/docs',
    filename: 'bs-three.js',
  },
  mode: "production"
},
];