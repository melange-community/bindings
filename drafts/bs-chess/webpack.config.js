const path = require('path');
const outputDir = path.join(__dirname, "build/");

module.exports = {
  entry: './src/Test.bs.js',
  mode: 'development',
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: 'Index.js',
  },
};
