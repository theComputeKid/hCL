#* MAKEFILE for Linux and MacOS

PREMAKE_OUT	:= build/premake5

.PHONY: all debug release vendor clean xcode compileCommands

ifeq ($(shell uname -s),Darwin)
OS := macosx
ARCH := Universal
else
OS := linux
ARCH := x64
endif

#* Build everything rules
all:
	@$(MAKE) debug
	@$(MAKE) release
	@echo Completed Build: $@

#* Build debug mode
debug: vendor
	@cd build/projects && $(MAKE) config=$@
	$(MAKE) compileCommands
	@echo Completed Build: $@

#* Build release mode
release: vendor
	@cd build/projects && $(MAKE) config=$@
	@echo Completed Build: $@

#* Build vendor dependencies
vendor: $(PREMAKE_OUT)
	$(PREMAKE_OUT) gmake2
	@echo Completed Build: $@

#* Clean project files
clean:
	@rm -rf build
	@echo Completed: $@

#* Rebuild project files
rebuild: clean
	$(MAKE) all
	@echo Completed: $@

#* Run tests
run:
	$(MAKE) all
	@build/bin/debug/test
	@build/bin/release/test
	@echo Completed: $@

#* Help
help:
	@echo ------------------
	@echo Available options:
	@echo make all - builds debug and release [default]
	@echo make debug - builds debug
	@echo make release - builds release
	@echo make vendor - builds vendor dependencies
	@echo make clean - cleans project files
	@echo make rebuild - rebuilds project files
	@echo make run - runs all tests
	@echo make xcode - creates xcode project and builds via xcodebuild [macOS only]
	@echo make compileCommands - creates compile_commands.json

$(PREMAKE_OUT):
	@$(MAKE) uuid
	@cd vendor/premake-core && $(MAKE) -f Bootstrap.mak $(OS) PLATFORM=$(ARCH)
	@mkdir -p build
	@cp vendor/premake-core/bin/release/premake5 $@

#* Checking if dependencies needed to build vendor present.
clang++:
	@echo Checking: $@
	@hash $@ || (echo "Error: $@ not detected. Please install $@." && exit 1)
	@echo "int main(){ return 0; }" | clang++ -x c++ - -fsyntax-only -std=c++20 || \
	(echo "Error: $@ not detected with C++20 enabled. \
	Please install a version of $@ that supports the C++20 flag." && exit 1)

uuid: clang++
	@echo Checking: $@
	@echo "int main(){}" | clang++ -include uuid/uuid.h -x c - -fsyntax-only || \
	(echo "Error: $@ (uuid/uuid.h) not detected. Please install $@." && exit 1)

#* Exotic build methods
ifeq ($(shell uname -s),Darwin)
xcode: $(PREMAKE_OUT)
	$(PREMAKE_OUT) xcode4
	@cd build/projects && xcodebuild -alltargets -parallelizeTargets -verbose -showBuildTimingSummary \
	-scheme test build -configuration debug
	@cd build/projects && xcodebuild -alltargets -parallelizeTargets -verbose -showBuildTimingSummary \
	-scheme test build -configuration release
endif

compileCommands: $(PREMAKE_OUT)
	$(PREMAKE_OUT) export-compile-commands
