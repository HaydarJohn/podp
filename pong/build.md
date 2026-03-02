# Building Pong 0.8

This document contains build instructions for Pong on Windows, macOS, and Linux.

## Prerequisites

You only need two things:

- **CMake** 3.10 or higher
- **A C++ compiler** (any recent one)

### Platform-specific setup

**Windows:**
- Install [Visual Studio](https://visualstudio.microsoft.com/) with the "Desktop development with C++" workload
- Or install [MinGW-w64](https://www.mingw-w64.org/)

**macOS:**
```bash
xcode-select --install
```

**Linux:**
- Ubuntu/Debian: `sudo apt install cmake build-essential libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl-dev`
- Fedora: `sudo dnf install cmake gcc-c++ libX11-devel libXrandr-devel libXinerama-devel libXcursor-devel libXi-devel mesa-libGL-devel`
- Arch: `sudo pacman -S cmake base-devel libx11 libxrandr libxinerama libxcursor libxi mesa`

---

## Quick Start (Recommended)

```bash
cd pong

# Set up both Debug and Release build directories
cmake -P CMakeSetup.cmake

# Build Debug (shaders loaded at runtime - edit and rebuild)
cmake --build ./build/debug

# Build Release (shaders embedded in binary - portable)
cmake --build ./build/release --config Release

# Run
./build/debug/pong       # Debug version
./build/release/pong    # Release version
```

On Windows, executables are named `pong.exe`.

---

## Debug vs Release

| Build Type | Behavior |
|------------|----------|
| **Debug** | Loads shaders from `src/test.vert` and `src/test.frag` at runtime. Edit shader files and rebuild to see changes. |
| **Release** | Shaders are embedded into the binary. The executable is fully portable with no external files needed. |

---

## Troubleshooting

**CMake not found:** Ensure CMake is installed and in your PATH. Verify with `cmake --version`.

**Build fails on Linux:** Make sure you installed all X11 development libraries listed above.

**Shader not found in Debug mode:** Run the executable from the debug directory in build and ensure `src/test.vert` and `src/test.frag` exist relative to where you run the binary. Or dont use debug config.
