.PHONY: refreshPublicFunctionList build clean release test default 

# environment variables
COMPILER ?= cc
OPTIMIZATION ?= -O0
BUILD_DIR ?= build

# local variables
headers = src/headers
sources = src/*.c

default: build

pubfuncsLength := $(shell wc -l < $(headers)/pubfuncs.h)
headerFunctions := $(shell grep --exclude=$(headers)/pubfuncs.h -iEh '[*]*[a-z]+[A-Za-z]*\(.*\);' $(headers)/*)
startPoint := 5
endPoint := $(shell echo $$(( $(pubfuncsLength) - 2 )))

refreshPublicFunctionList: 
	sed -i "$(startPoint),$(endPoint)d" $(headers)/pubfuncs.h
	sed -i "$(startPoint)i\\$(headerFunctions)" $(headers)/pubfuncs.h
	sed -i "$(startPoint)s/^/extern /g" $(headers)/pubfuncs.h
	sed -i "$(startPoint)s/; /;\nextern /g" $(headers)/pubfuncs.h
	sed -i "/^extern $$/d" $(headers)/pubfuncs.h

build: refreshPublicFunctionList
	mkdir -p $(BUILD_DIR)/debug
	$(COMPILER) -I$(headers) $(OPTIMIZATION) -Wall -o $(BUILD_DIR)/debug/bsdata $(sources)

clean:
	rm -f $(BUILD_DIR)/debug/*
	rm -f $(BUILD_DIR)/release/*

# release ignores the OPTIMIZATION env variable and compiles with -O3.
release: clean refreshFunctionList
	mkdir -p $(BUILD_DIR)/release
	$(COMPILER) -I$(headers) -O3 -o $(BUILD_DIR)/release/bsdata $(sources)

test: build
	# No tests currently exist. Contributions for tests would be appreciated.

run: build
	./$(BUILD_DIR)/debug/bsdata $(ARGS)
