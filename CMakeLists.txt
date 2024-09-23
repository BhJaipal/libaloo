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

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_Declare(
	ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
	GIT_TAG v5.0.0
)

FetchContent_MakeAvailable(ftxui)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(SQLITE REQUIRED sqlite3)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

add_executable(aloo_exe "cli/aloo.cpp")
target_link_libraries(aloo_exe
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
	${JSONCPP_LIBRARIES}
)
set_property(TARGET aloo_exe PROPERTY OUTPUT_NAME aloo)

add_executable("aloo-cli" "cli/aloo-cli.cpp")
target_link_libraries("aloo-cli"
	${JSONCPP_LIBRARIES}
)

include_directories(
	"build/_deps/ftxui-src/include"
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