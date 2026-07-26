import { execSync } from "node:child_process";
import fs from "node:fs";
import path from "node:path";

const newVersion = process.argv[2];

if (!newVersion || !/^\d+\.\d+\.\d+/.test(newVersion)) {
  console.error("Usage: node scripts/bump-version.mjs <new-version>");
  console.error("Example: node scripts/bump-version.mjs 0.1.1");
  process.exit(1);
}

function updateJson(filePath, updater) {
  const fullPath = path.resolve(filePath);
  if (!fs.existsSync(fullPath)) return;

  const data = JSON.parse(fs.readFileSync(fullPath, "utf8"));
  updater(data);
  fs.writeFileSync(fullPath, JSON.stringify(data, null, 2) + "\n");
  console.log(`Updated: ${filePath}`);
}

const cargoPath = path.resolve("Cargo.toml");
if (fs.existsSync(cargoPath)) {
  let cargo = fs.readFileSync(cargoPath, "utf8");
  cargo = cargo.replace(/^version\s*=\s*".*?"/m, `version = "${newVersion}"`);
  fs.writeFileSync(cargoPath, cargo);
  console.log(`Updated: Cargo.toml`);
}

const packagesDir = path.resolve("npm", "packages");
if (fs.existsSync(packagesDir)) {
  const platforms = fs.readdirSync(packagesDir);
  for (const platform of platforms) {
    const pkgPath = path.join("npm", "packages", platform, "package.json");
    updateJson(pkgPath, (pkg) => {
      pkg.version = newVersion;
    });
  }
}

updateJson("npm/cli/package.json", (pkg) => {
  pkg.version = newVersion;

  if (pkg.optionalDependencies) {
    for (const dep of Object.keys(pkg.optionalDependencies)) {
      if (dep.includes("svd2c-")) {
        pkg.optionalDependencies[dep] = newVersion;
      }
    }
  }
});

console.log(`\nNew version ${newVersion}!`);

try {
  execSync("git add .");
  execSync(`git tag v${newVersion}`);

  console.log("\nTagged. Now run:");
  console.log("git push origin main");
  console.log(`git push origin v${newVersion}`);
} catch (error) {
  console.error(`\nGit error: ${error}`);
}
