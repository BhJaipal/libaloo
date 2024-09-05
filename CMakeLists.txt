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

include_directories(
	"../gtest/test-build/_deps/googletest-src/googletest/include/gtest"
	${GTEST_INCLUDE_DIRS}
	"/usr/include/gtk-4.0"
	"/usr/include/glib-2.0"
	"/usr/include/gdk-pixbuf-2.0"
	"/usr/lib/x86_64-linux-gnu/glib-2.0/include"
	"/usr/include/gtk-4.0/gdk"
	"/usr/include/gtk-4.0"
	"/usr/include/cairo"
	"/usr/lib/x86_64-linux-gnu/graphene-1.0/include"
	"/usr/include/pango-1.0"
	"/usr/include/graphene-1.0"
	"/usr/include/harfbuzz"
	"/usr/include/tirpc"
)
find_package(GTest REQUIRED)

target_link_libraries(aloo
	${GTK4_LIBRARIES}
	${GTEST_LIBRARIES}
	"${CMAKE_SOURCE_DIR}/gtest/build/lib/libgmock.a"
	"${CMAKE_SOURCE_DIR}/gtest/build/lib/libgmock_main.a"
	"${CMAKE_SOURCE_DIR}/gtest/build/lib/libgtest.a"
	"${CMAKE_SOURCE_DIR}/gtest/build/lib/libgtest_main.a"
	"/lib/x86_64-linux-gnu/libgtk-4.so.1"
	"/lib/x86_64-linux-gnu/libgobject-2.0.so"
	"/lib/x86_64-linux-gnu/libglib-2.0.so"
	"/lib/x86_64-linux-gnu/libglib-2.0.so.0"
	"/lib/x86_64-linux-gnu/libsqlite3.so"
	"/lib/x86_64-linux-gnu/libsqlite3.so.0"
)
add_executable(test.exe "test/main.c")
target_link_libraries(test.exe aloo)

set(CMAKE_BUILD_TYPE Release)
add_test(AlooTest "bin/test.exe")
enable_testing(AlooTest)