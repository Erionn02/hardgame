include(CMakePrintHelpers)


add_lib("${CMAKE_PROJECT_NAME}_lib"
        SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/GameEngine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MovementRequest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/RectangleCollisionObject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Movable.cpp
        )
