cmake_minimum_required(VERSION 3.16)
project(burning_forest)

set(CMAKE_CXX_STANDARD 17)

# my stuff

set(APP_USABLES usables/)
include_directories(${APP_USABLES})

set(SOURCE_FILES
        usables/containers/stack.h
        usables/containers/deque.h
        usables/my_tree.cpp
        usables/my_tree.h
        usables/containers/array.h
        usables/graph.h
        usables/graph.cpp
        usables/containers/cyclic_array.h
        usables/containers/list.h headers/Automaton.h headers/Rules.h headers/Cell.h src/Rules.cpp src/Automaton.cpp)


add_executable(burning_forest
        main.cpp
        src/Table.cpp
        headers/Table.h
        src/App.cpp
        headers/App.h

        ${SOURCE_FILES}
        )

# sfml include magic

include_directories(headers /usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(burning_forest ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()