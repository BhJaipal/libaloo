include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

add_executable(aloo_exe "aloo.cpp")
target_link_libraries(aloo_exe
	"FTXUI/build/libftxui-dom.a"
	"FTXUI/build/libftxui-screen.a"
	"FTXUI/build/libftxui-component.a"
	${JSONCPP_LIBRARIES}
)
include_directories("FTXUI")
set_property(TARGET aloo_exe PROPERTY OUTPUT_NAME aloo)

add_executable(aloo-cli "aloo-cli.cpp")
target_link_libraries("aloo-cli"
	${JSONCPP_LIBRARIES}
)