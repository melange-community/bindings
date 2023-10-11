const { readFileSync, writeFileSync } = require("fs");
const { execSync } = require("child_process");

module.exports = (fileName) => {
  const contents = readFileSync(fileName).toString();
  const formattedCode = execSync(`node_modules/.bin/bsc -format ${fileName}`);
  if (formattedCode !== contents) {
    writeFileSync(fileName, formattedCode);
    return true;
  }
  return false;
};
