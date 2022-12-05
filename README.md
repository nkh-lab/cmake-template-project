## Intro
Template `cmake` project.

The main purpose of creating it is to have a uniform style for projects and quickly set up a project based on this template.

Includes the following features:
* crossplatform tested (Windows, Linux (Ubuntu), see [CI Status](#ci-status))
* libraries (shared, header-only) and executable examples;
* Unit (based on `GTest` and `GMock`) and Component Tests;
* `cmake` configuration generation (`configure_file()`) usage example;
* tools:
    * `clang format` script;
    * `cppcheck` run script;
    * build portable package scripts.

## CI Status
[![CI](https://github.com/nkh-lab/cmake-template-project/actions/workflows/ci.yml/badge.svg)](https://github.com/nkh-lab/cmake-template-project/actions/workflows/ci.yml)

Ubuntu | Windows

## How to get project source code
Clone project:
```
git clone https://github.com/nkh-lab/cmake-template-project.git
```

## How to build
### Linux

```
mkdir build && cd build
cmake ..
make
```
### Windows
The following describes how to build the project from the command line for the compiler from Visual Studio.

Add `msbuild` to `PATH` environment variable if it's unset:
```
set PATH=%PATH%;<path to msbuild>
```
Build:
```
mkdir build && cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
```

### With Tests
For example both Unit and Component Tests:
```
cmake -Dprojectmy_BUILD_UTESTS=ON -Dprojectmy_BUILD_CTESTS=ON ..
make
```

### Portable
To be able to use the output binaries outside of the project, use the appropriate scripts from the [tools](tools) folder to build the portable package ([build/portable](build/portable) and its archive [build/projectmy-portable.tar.gz](build/projectmy-portable.tar.gz)), for example for Linux:
```
./tools/build-portable-linux.sh
```
