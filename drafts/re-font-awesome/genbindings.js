/* eslint-disable no-console */
const formatRescriptFile = require("./formatRescriptFile");

const iconObjectTypeName = "IconObject.t";
[
  ["regular", "pro"],
  ["solid", "pro"],
  ["light", "pro"],
  ["duotone", "pro"],
  ["thin", "pro"],
  ["sharp-solid", "pro"],
  ["regular", "free"],
  ["solid", "free"],
  ["brands", "free"],
].forEach(([style, tier]) => {
  const libName =
    style === "sharp-solid"
      ? `@fortawesome/sharp-solid-svg-icons`
      : `@fortawesome/${tier}-${style}-svg-icons`;
  const lib = require(libName);
  const iconNames = Object.keys(lib)
    .filter((s) => s.match(/fa[A-Z][A-Za-z]+/))
    .sort();
  const bindings = iconNames.map(
    (n) =>
      `@module("${libName}")\nexternal ${n}: ${iconObjectTypeName} = "${n}";`
  );
  const capitalizedStyle = style
    .split("-")
    .map((s) => s[0].toUpperCase() + s.slice(1))
    .join("");
  const bindingModuleName = `${
    tier === "free" && style !== "brands" ? "Free" : ""
  }${capitalizedStyle}`;
  const bindingModuleContents = bindings.join("\n\n");
  const bindingPath = `src/${bindingModuleName}.res`;
  require("fs").writeFileSync(bindingPath, bindingModuleContents);
  formatRescriptFile(bindingPath);
  console.log(`Generated ${bindingPath}`);

  const allArrayModuleContents = `let all: array<${iconObjectTypeName}> = [${iconNames
    .map((n) => `${bindingModuleName}.${n}`)
    .join(", ")}]`;
  const allArrayPath = `src/${bindingModuleName}_All.res`;
  require("fs").writeFileSync(allArrayPath, allArrayModuleContents);
  formatRescriptFile(allArrayPath);

  console.log(`Generated ${allArrayPath}`);
});
