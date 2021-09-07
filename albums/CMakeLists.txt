cmake_minimum_required(VERSION 3.15)
project(albums C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror")

add_executable(albums main.c Album.c csv.c AlbumList.c)
add_executable(test_csv test_csv.c csv.c)
add_executable(test_Album test_Album.c Album.c)
add_executable(test_AlbumList test_AlbumList.c AlbumList.c)