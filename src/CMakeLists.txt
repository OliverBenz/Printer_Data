add_executable(main main.cpp)

# Libraries
add_subdirectory(lib)

target_link_libraries(main PUBLIC datetime)
target_link_libraries(main PUBLIC print)
