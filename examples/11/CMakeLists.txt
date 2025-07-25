file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS *.cpp)

find_package(Threads REQUIRED)

foreach(SOURCE_FILE ${CPP_FILES})
    get_filename_component(SOURCE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(cpp11_${SOURCE_NAME} ${SOURCE_FILE})
    target_link_libraries(cpp11_${SOURCE_NAME} PRIVATE Threads::Threads)
endforeach()
