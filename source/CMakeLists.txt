project(libxviewer)

find_package(Backward CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

set(${PROJECT_NAME}_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
                         ${CMAKE_CURRENT_SOURCE_DIR}/basis
                         ${CMAKE_CURRENT_SOURCE_DIR}/component
                         ${CMAKE_CURRENT_SOURCE_DIR}/ui)

foreach(dir ${${PROJECT_NAME}_DIRS})
    file(GLOB_RECURSE header_files "${dir}/*.h" "${dir}/*.hpp" "${dir}/*.hxx")
    list(APPEND ${PROJECT_NAME}_HEADERS ${header_files})
    file(GLOB_RECURSE src_files "${dir}/*.cpp" "${dir}/*.c")
    list(APPEND ${PROJECT_NAME}_SRCS ${src_files})
endforeach()




add_library(${PROJECT_NAME} ${${PROJECT_NAME}_HEADERS} ${${PROJECT_NAME}_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE Backward::Backward)
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE implot::implot)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp::yaml-cpp)
target_include_directories(${PROJECT_NAME}  PRIVATE ${Stb_INCLUDE_DIR})
