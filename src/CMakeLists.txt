set(FORWARD_LIST_SRC forward_list.cpp forward_list.hpp)
set(LIST_SRC)

add_library(
        container
        "${FORWARD_LIST_SRC}"
        "${LIST_SRC}"
)
target_include_directories(container PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")