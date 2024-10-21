cmake_minimum_required(VERSION 3.30)

project("$appName")

add_executable(app.exe "app/main.c")
set(CMAKE_BINARY_DIR build/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(SQLITE REQUIRED sqlite3)

include_directories(
	"$include_dir"
	${GTK4_INCLUDE_DIRS}
	${SQLITE_INCLUDE_DIRS}
	"/usr/include/tirpc"
)

add_executable(test.exe "test/main.c")

target_link_libraries(app.exe
	"$libaloo"
	${GTK4_LIBRARIES}
	${SQLITE_LIBRARIES}
)
target_link_libraries(test.exe
	"$libaloo"
	${GTK4_LIBRARIES}
	${SQLITE_LIBRARIES}
)

set(CMAKE_BUILD_TYPE "$ENV{Release}")
add_test(AlooTest "../bin/test.exe")
enable_testing(AlooTest)