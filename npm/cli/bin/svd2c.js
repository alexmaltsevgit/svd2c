#!/usr/bin/env node

const { spawnSync } = require("node:child_process");
const path = require("node:path");

const targets = {
  "linux-x64": "svd2c-linux-x64",
  "win32-x64": "svd2c-win32-x64",
  "darwin-arm64": "svd2c-darwin-arm64",
  "darwin-x64": "svd2c-darwin-x64"
};

const target = `${process.platform}-${process.arch}`;
const packageName = targets[target];

if (!packageName) {
  console.error(`Unsupported platform: ${target}`);
  process.exit(1);
}

let binary;
try {
  const binaryFile = process.platform === "win32" ? "svd2c.exe" : "svd2c";
  binary = require.resolve(`${packageName}/bin/${binaryFile}`);
} catch {
  console.error(
    `Native binary package ${packageName} was not installed.\n` +
    `Try reinstalling dependencies without --no-optional.`
  );
  process.exit(1);
}

const result = spawnSync(binary, process.argv.slice(2), {
  stdio: "inherit"
});

process.exit(result.status ?? 1);
