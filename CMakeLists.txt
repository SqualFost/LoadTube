cmake_minimum_required(VERSION 3.15)
project(yt_dl C)

set(CMAKE_C_STANDARD 11)

# Chemin Homebrew SDL3
set(SDL3_PATH "/opt/homebrew/Cellar/sdl3/3.2.28")
set(SDL3_TTF_PATH "/opt/homebrew/Cellar/sdl3_ttf/3.2.2")

include_directories(${SDL3_PATH}/include)
include_directories(${SDL3_TTF_PATH}/include)

# Ajouter l'exécutable
add_executable(yt_dl main.c)

# Lier SDL3 en donnant le chemin complet du dylib
target_link_libraries(yt_dl "${SDL3_PATH}/lib/libSDL3.dylib" "${SDL3_TTF_PATH}/lib/libSDL3_ttf.dylib")