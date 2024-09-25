include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_Declare(
	ftxui
	GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
	GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

add_executable(aloo_exe "aloo.cpp")
include (GNUInstallDirs)
include_directories("${ftxui_SOURCE_DIR}/include")

target_link_libraries(
	aloo_exe
	PRIVATE ${JSONCPP_LIBRARIES}
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
	PRIVATE ftxui::screen
)
set_property(TARGET aloo_exe PROPERTY OUTPUT_NAME aloo)

add_executable(aloo-cli "aloo-cli.cpp")
target_link_libraries("aloo-cli"
	${JSONCPP_LIBRARIES}
)