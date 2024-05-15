# bsdata

Random BS data generator

## Build Instructions

This project is written in C and uses `make` as its build system.

### Prerequisites

Before building the project, ensure you have `gcc`, `clang`, or any other C compiler installed on your system, along 
with any libc of your choice. You can set a specific compiler by exporting the `COMPILER` environment variable, 
otherwise `make` will use the default compiler (`cc`).

### Building the Project

1. **Clone the repository:**
   ```bash
   git clone https://github.com/penguNu/bsdata
   cd bsdata
   ```

2. **Compile the project:**
   To build the project, simply run:
   ```bash
   make
   ```

This will compile the sources into the `build/debug` directory with no optimizations and all warnings enabled.

### Running the Build

To have the project build and immediately run the built binary afterwards, you can run:
```bash
make run
```

This will run the binary produced in `build/debug` with no arguments. Alternatively, if you wish to run the build with
arguments, you can set the ARGS environment variable, like so:
```bash
make run ARGS="[your arguments here]"
```

### Building for Release

If you want to compile the project for release, which includes higher optimization levels, run:
```bash
make release
```
This will clean any previous builds and compile bsdata into the `build/release` directory using the `-O3` optimization 
level. Only the default compiler warnings will be displayed.


### Cleaning the Build Directory

To clean up the build directories, you can use:
```bash
make clean
```
This command will remove all the compiled files from both the `debug` and `release` build directories.

