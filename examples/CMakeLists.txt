set(LIST_EXAMPLE_SRC list_main.cpp)

add_executable(list_example "${LIST_EXAMPLE_SRC}")
target_link_libraries(list_example container)
