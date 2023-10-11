const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === "production";

/**
 * @type import("webpack").Configuration
 */
module.exports = {
  entry: "./src/WebpackEntry.bs.js",
  mode: isProd ? "production" : "development",
  output: {
    path: outputDir,
    filename: "clientBundle.js",
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "src/index.html",
      inject: false,
    }),
  ],
  devServer: {
    compress: true,
    static: {
      directory: outputDir,
    },
    port: process.env.PORT || 8000,
    historyApiFallback: true,
  },
};
