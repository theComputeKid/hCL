#* MAKEFILE for Linux and MacOS

PREMAKE_OUT	:= build/premake5

.PHONY: all debug release vendor clean

ifeq ($(shell uname -s),Darwin)
OS := macosx
ARCH := Universal
PREMAKE_TARGET := xcode4
else
OS := linux
ARCH := x64
PREMAKE_TARGET := gmake2
endif

#* Build everything rules
all:
	@$(MAKE) debug
	@$(MAKE) release
	@echo Completed Build: $@

#* Build debug mode
debug: vendor
	@echo Completed Build: $@

#* Build release mode
release: vendor
	@echo Completed Build: $@

#* Build vendor dependencies
vendor: $(PREMAKE_OUT)
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
	@build/bin/debug/hCL
	@build/bin/release/hCL
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
