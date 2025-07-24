file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS *.cpp)

foreach(SOURCE_FILE ${CPP_FILES})
    get_filename_component(SOURCE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(cpp17_${SOURCE_NAME} ${SOURCE_FILE})
endforeach()
