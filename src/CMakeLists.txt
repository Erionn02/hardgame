include(CMakePrintHelpers)


add_lib("${CMAKE_PROJECT_NAME}_lib"
        SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/MovementController.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MovementRequest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
        )


add_lib(template_lib_one
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/TestClass.cpp
        )

add_lib(template_lib_two
        SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/TestClass2.cpp
        )
