cmake_minimum_required(VERSION 3.20)

project("Aloo Edit")

add_executable(app.exe app/main.c)
set(CMAKE_BINARY_DIR build/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

include_directories(../include)
target_link_libraries(app.exe "/home/jaipal001/Desktop/files/c-use/libaloo/lib/libaloo.a")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(SQLITE REQUIRED sqlite3)

include_directories(
	"/home/jaipal001/Desktop/files/c-use/libaloo/include"
	${GTK4_INCLUDE_DIRS}
	${SQLITE_INCLUDE_DIRS}
	"/usr/include/tirpc"
)

target_link_libraries(app.exe
	${GTK4_LIBRARIES}
	${SQLITE_LIBRARIES}
)

add_executable(test.exe "test/main.c")
target_link_libraries(test.exe
	"/home/jaipal001/Desktop/files/c-use/libaloo/lib/libaloo.a"
	${GTK4_LIBRARIES}
	${SQLITE_LIBRARIES}
)

set(CMAKE_BUILD_TYPE "$ENV{Release}")
add_test(AlooTest "../bin/test.exe")
enable_testing(AlooTest)