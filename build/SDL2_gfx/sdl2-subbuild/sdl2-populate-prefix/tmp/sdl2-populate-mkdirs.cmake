# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/SDL-2.24.2"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-build"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/tmp"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/src"
  "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Dev/C++/tp_projekt_3/build/SDL2_gfx/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
