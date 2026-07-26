.PHONY: all check test clean build-all build-macos build-linux-x64 build-linux-arm64 build-windows-x64 build-darwin-x64 build-darwin-arm64

all: check test

build-all: build-linux-x64 build-linux-arm64 build-windows-x64

build-macos: build-darwin-x64 build-darwin-arm64

build-linux-x64:
	node scripts/build.mjs linux-x64

build-linux-arm64:
	CC_aarch64_unknown_linux_gnu=aarch64-linux-gnu-gcc \
	CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc \
	cargo build --release --target aarch64-unknown-linux-gnu

build-windows-x64:
	node scripts/build.mjs win32-x64

build-darwin-x64:
	node scripts/build.mjs darwin-x64

build-darwin-arm64:
	node scripts/build.mjs darwin-arm64

bump:
	@if [ -z "$(VERSION)" ]; then \
		echo "Error: specify version (make bump VERSION=0.1.2"); \
		exit 1; \
	fi
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
