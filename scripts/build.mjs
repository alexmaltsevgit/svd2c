import { execFileSync } from "node:child_process";
import fs from "node:fs";
import path from "node:path";

const targets = {
  "linux-x64": {
    cargoTarget: null,
    source: "target/release/svd2c",
    output: "npm/packages/linux-x64/bin/svd2c",
  },
  // "linux-arm64": {
  //   cargoTarget: "aarch64-unknown-linux-gnu",
  //   source: "target/release/svd2c",
  //   output: "npm/packages/linux-x64/bin/svd2c",
  // },
  "win32-x64": {
    cargoTarget: "x86_64-pc-windows-gnu",
    source: "target/x86_64-pc-windows-gnu/release/svd2c.exe",
    output: "npm/packages/win32-x64/bin/svd2c.exe",
  },
};

const platform = process.argv[2];

if (!targets[platform]) {
  throw new Error(`Unknown platform: ${platform}`);
}

const config = targets[platform];
const args = ["build", "--release"];

if (config.cargoTarget) {
  args.push("--target", config.cargoTarget);
}

execFileSync("cargo", args, { stdio: "inherit" });

fs.mkdirSync(path.dirname(config.output), { recursive: true });
fs.copyFileSync(config.source, config.output);

if (!config.output.endsWith(".exe")) {
  fs.chmodSync(config.output, 0o755);
}
