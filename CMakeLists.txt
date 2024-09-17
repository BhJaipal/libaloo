cmake_minimum_required(VERSION 3.30)
project(Aloo)

include_directories(include)

add_library(aloo
	"src/common/app.c"
	"src/common/box.c"
	"src/common/builder.c"
	"src/common/button.c"
	"src/common/grid.c"
	"src/common/input.c"
	"src/common/label.c"
	"src/common/style.c"
	"src/common/widget.c"
	"src/common/window.c"
	"src/utils/error.c"
	"src/utils/logger.c"
	"src/test/aloo.c"
	"src/db/sqlite.c"
)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(SQLITE REQUIRED sqlite3)

include_directories(
	${GTK4_INCLUDE_DIRS}
	${SQLITE_INCLUDE_DIRS}
	"/usr/include/tirpc"
)

target_link_libraries(aloo
	${GTK4_LIBRARIES}
	${SQLITE_LIBRARIES}
)

add_executable(test-1.exe "test/int.spec.c")

target_link_libraries(test-1.exe aloo)
set_target_properties(test-1.exe PROPERTIES CFLAGS "${GTK4_CFLAGS}")

set(CMAKE_BUILD_TYPE "$ENV{Release}")

add_test(IntegerTest "../bin/test-1.exe")

enable_testing(IntegerTest)