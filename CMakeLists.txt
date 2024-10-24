cmake_minimum_required(VERSION 3.2)   

project("kiwi")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# link time optimization
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE CACHE INTERNAL "")	# only enable on release

if (CMAKE_BUILD_TYPE STREQUAL Debug)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
endif()

if(MSVC)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
	add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
	)
endif()


file(GLOB source "src/*.cpp" "src/*.h" "src/gui/*.cpp" "src/gui/*.h")
add_executable("${PROJECT_NAME}" WIN32 ${source} "res/kiwi.rc")

if (UNIX)
	add_compile_options(-lX11 -lXi -lXcursor)
endif()

# wxWidgets
set(wxBUILD_SHARED OFF CACHE INTERNAL "")
add_subdirectory("thirdparty/wxWidgets-3.2.6" EXCLUDE_FROM_ALL)

target_link_libraries("${PROJECT_NAME}"
	PUBLIC 
	wx::base
	wx::core
	wx::aui
	wx::richtext
)

if (MSVC)
	# windows app
	set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DPI_AWARE "PerMonitor")
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${PROJECT_NAME}")
endif()

# strip binary for release builds
if (CMAKE_BUILD_TYPE STREQUAL Release)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_STRIP} ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})
endif()
