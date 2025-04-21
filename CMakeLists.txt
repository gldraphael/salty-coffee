cmake_minimum_required(VERSION 3.0)
project(salty-coffee VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# add_library(gbase-lib
#   Gbase/*.h
#   Gbase/*.cpp
#   Gbase/*.hpp
# )

file(GLOB GBASE_HEADERS Gbase/*.h Gbase/*.hpp)
file(GLOB GBASE_SOURCES Gbase/*.cpp)

add_library(gbase-lib
  ${GBASE_HEADERS}
  ${GBASE_SOURCES}
)

add_library(salty-coffee-lib

  CIA/IA.h
  CIA/IA.cpp
  CIA/Character.h
  CIA/Character.cpp

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


# Add executable
add_executable(salty-coffee
  CIA/main.cpp
)

target_link_libraries(salty-coffee
    gbase-lib
    salty-coffee-lib
)
