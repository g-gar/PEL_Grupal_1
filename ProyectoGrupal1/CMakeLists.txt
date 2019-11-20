cmake_minimum_required(VERSION 3.0.0)
project(ProyectoGrupal1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ProyectoGrupal1 main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(${PROJECT_NAME} PROPERTIES
   CXX_STANDARD 20
   CXX_STANDARD_REQUIRED ON
   CXX_EXTENSIONS OFF
   RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug
   RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release
)

find_package(fmt CONFIG REQUIRED)
find_package(range-v3 CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
   fmt::fmt
   range-v3
   nlohmann_json::nlohmann_json
)