cmake_minimum_required(VERSION 3.5)

project(JEU_DE_LA_VIE)

# set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB PROJECT_SOURCES
     "${PROJECT_SOURCE_DIR}/*.cpp"
     "${PROJECT_SOURCE_DIR}/fichier/*.cpp"
     "${PROJECT_SOURCE_DIR}/fichier/*.hpp"
      )
# Find any version 2.X of SFML, first trying 2.5 or above (for which CMake configuration changed)
find_package(SFML 2.5 QUIET COMPONENTS graphics window system)
    if(SFML_FOUND)
        message(STATUS "Found SFML ${SFML_VERSION_MAJOR}.${SFML_VERSION_MINOR}.${SFML_VERSION_PATCH}")
     add_executable (jeu  ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCES})
     target_link_libraries(jeu sfml-graphics sfml-window sfml-system)
    else()
        set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
        find_package(SFML 2 COMPONENTS graphics window system)
        if(SFML_FOUND)

            message(STATUS "SFML_INCLUDE_DIR : ${SFML_INCLUDE_DIR}")
            message(STATUS "SFML_LIBRARIES   : ${SFML_LIBRARIES}")
            message(STATUS "SFML_DEPENDENCIES: ${SFML_DEPENDENCIES}")

            include_directories(${SFML_INCLUDE_DIR})
            add_executable (jeu  ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCES})
            target_link_libraries(jeu ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
        else()
            message(STATUS "SFML NOT FOUND ! ")
        endif() ## SFML 2
endif() ## SFML 2.5
