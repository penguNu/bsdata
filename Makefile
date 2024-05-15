.PHONY: build clean release test default

# environment variables
COMPILER ?= cc
OPTIMIZATION ?= -O0
BUILD_DIR ?= build

# local variables
headers = src/headers
sources = src/*.c

default: build

clean:
	rm -f $(BUILD_DIR)/debug/*
	rm -f $(BUILD_DIR)/release/*

build: 
	mkdir -p $(BUILD_DIR)/debug
	$(COMPILER) -I$(headers) $(OPTIMIZATION) -Wall -o $(BUILD_DIR)/debug/bsdata $(sources)


# release ignores the OPTIMIZATION env variable and compiles with -O3.
release: clean
	mkdir -p $(BUILD_DIR)/release
	$(COMPILER) -I$(headers) -O3 -o $(BUILD_DIR)/release/bsdata $(sources)

test: build
	# No tests currently exist. Contributions for tests would be appreciated.

run: build
	./$(BUILD_DIR)/debug/bsdata $(ARGS)
