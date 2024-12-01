project(xviewer_demo)

add_executable(xviewer_demo main.cpp xviewer_demo.cpp)
target_link_libraries(xviewer_demo PRIVATE libxviewer)