.PHONY: refreshPublicFunctionList build clean release test default 

# environment variables
COMPILER ?= cc
OPTIMIZATION ?= -O0
BUILD_DIR ?= build

# local variables
headers = src/headers
sources = src/*.c src/generate/*.c src/output/*.c

default: build

pubfuncsLength := $(shell wc -l < $(headers)/pubfuncs.h)
headerFunctions := $(shell grep --exclude=$(headers)/pubfuncs.h -iEh '[*]*[a-z]+[A-Za-z]* *\(.*\);' $(headers)/*)
startPoint := 8
endPoint := $(shell echo $$(( $(pubfuncsLength) - 2 )))

refreshPublicFunctionList: 
	@echo "Refreshing public function list..."
	@sed -i "$(startPoint),$(endPoint)d" $(headers)/pubfuncs.h
	@sed -i "$(startPoint)i\\$(headerFunctions)" $(headers)/pubfuncs.h
	@sed -i "$(startPoint)s/^/extern /g" $(headers)/pubfuncs.h
	@sed -i "$(startPoint)s/; /;\nextern /g" $(headers)/pubfuncs.h
	@sed -i "/^extern $$/d" $(headers)/pubfuncs.h

build: refreshPublicFunctionList
	mkdir -p $(BUILD_DIR)/debug
	$(COMPILER) -I$(headers) $(OPTIMIZATION) -Wall -o $(BUILD_DIR)/debug/bsdata $(sources)

clean:
	rm -f $(BUILD_DIR)/debug/*
	rm -f $(BUILD_DIR)/release/*

# release ignores the OPTIMIZATION env variable and compiles with -O3.
release: refreshPublicFunctionList
	mkdir -p $(BUILD_DIR)/release
	rm -f $(BUILD_DIR)/release/bsdata
	$(COMPILER) -I$(headers) -O3 -o $(BUILD_DIR)/release/bsdata $(sources)

test: build
	# No tests currently exist. Contributions for tests would be appreciated.

run: build
	@echo "=================="
	./$(BUILD_DIR)/debug/bsdata $(ARGS)

install: release
	mkdir -p /usr/local/bin
	cp $(BUILD_DIR)/release/bsdata /usr/local/bin/bsdata

dirtyformat:
	astyle --project=./config/astylerc $(sources) $(headers)/*.h

format: dirtyformat
	$(foreach source,$(sources),rm -f $(source).orig &&) true
	rm -f $(headers)/*.orig
	
