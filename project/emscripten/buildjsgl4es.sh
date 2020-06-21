#/bin/sh
set -e
emcc -std=c++17 -Wall -Wno-unused-private-field -Wno-unused-variable -Wno-parentheses-equality -Wno-unused-function -I../../include ../../source/sdl/*.cpp ../../source/sdl/emscripten/*.cpp ../../platform/linux/*.cpp ../../source/emulation/cpu/*.cpp ../../source/emulation/cpu/common/*.cpp ../../source/emulation/cpu/normal/*.cpp ../../source/emulation/softmmu/*.cpp ../../source/io/*.cpp ../../source/kernel/*.cpp ../../source/kernel/devs/*.cpp ../../source/kernel/proc/*.cpp ../../source/kernel/sys/*.cpp ../../source/kernel/loader/*.cpp ../../source/util/*.cpp ../../source/opengl/sdl/*.cpp ../../source/opengl/*.cpp ../../lib/gl4es/build/libGL.a -o boxedwine.html -O3 -DUSE_MMU -s FULL_ES2=1 -I../../lib/gl4es/include -L../../lib/gl4es/build -s ERROR_ON_UNDEFINED_SYMBOLS=0 -lGL "-DGLH=<GL/gl.h>" -DBOXEDWINE_OPENGL_SDL -DDISABLE_GL_EXTENSIONS -s USE_SDL=2 -DSDL2 -DBOXEDWINE_DISABLE_UI -s TOTAL_MEMORY=536870912 --shell-file shellfs.html -s EXTRA_EXPORTED_RUNTIME_METHODS='["addRunDependency", "removeRunDependency"]'

