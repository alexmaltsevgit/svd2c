.PHONY: all check test clean build-all build-macos build-linux-x64 build-linux-arm64 build-windows-x64 build-darwin-x64 build-darwin-arm64

all: check test

build-all: build-linux-x64 build-windows-x64

build-macos: build-darwin-x64 build-darwin-arm64

build-linux-x64:
	node scripts/build.mjs linux-x64

build-windows-x64:
	node scripts/build.mjs win32-x64

build-darwin-x64:
	node scripts/build.mjs darwin-x64

build-darwin-arm64:
	node scripts/build.mjs darwin-arm64

bump:
	@test -n "$(VERSION)" || (echo "Specify VERSION: make bump VERSION=0.1.1"; exit 1)
	node scripts/bump-version.mjs $(VERSION)
	cargo check

test:
	cargo test

check:
	cargo fmt --check
	cargo clippy -- -D warnings

clean:
	cargo clean
	rm -rf npm/packages/*/bin dist
