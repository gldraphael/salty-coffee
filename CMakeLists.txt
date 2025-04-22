cmake_minimum_required(VERSION 3.0)
project(salty-coffee VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Make sure SDL1.2 is available
find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)

# Setup Gbase
file(GLOB GBASE_HEADERS Gbase/*.h Gbase/*.hpp)
file(GLOB GBASE_SOURCES Gbase/*.cpp)

add_library(gbase-lib
  ${GBASE_HEADERS}
  ${GBASE_SOURCES}
)
target_include_directories(gbase-lib
  PUBLIC ./Gbase
)
target_compile_options(gbase-lib PUBLIC -fpermissive)
target_link_libraries(gbase-lib PUBLIC
  ${SDL_LIBRARY}
  ${SDLIMAGE_LIBRARY}
  ${SDLMIXER_LIBRARY}
  ${SDLTTF_LIBRARY}
)

# Setup salty-coffee
add_library(salty-coffee-lib

  CIA/IA.h
  CIA/IA.cpp
  CIA/Character.h
  CIA/Character.cpp
  CIA/Scene.h
  CIA/Scene.cpp
  CIA/StatusBar.h
  CIA/StatusBar.cpp
  CIA/Transition.h
  CIA/Transition.cpp

  CIA/Intro.h
  CIA/Intro.cpp
  CIA/Ask.h
  CIA/Ask.cpp
  CIA/Cafe.h
  CIA/Cafe.cpp
  CIA/FlashBack.h
  CIA/FlashBack.cpp
  CIA/Naration.h   # retaining the typo from the original filename
  CIA/Naration.cpp
  CIA/Letter1.h
  CIA/Letter1.cpp
  CIA/Letter2.h
  CIA/Letter2.cpp
  CIA/Taste.h
  CIA/Taste.cpp
  CIA/TheEnd.h
  CIA/TheEnd.cpp
)
target_link_libraries(salty-coffee-lib PUBLIC gbase-lib)

# Add executable
add_executable(salty-coffee
  CIA/main.cpp
)

target_link_libraries(salty-coffee
    salty-coffee-lib
)

# Copy assets over
file(COPY ./CIA/images DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ./CIA/fonts  DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ./CIA/music  DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
