set(SOURCES
    public/TaskProcessor/TaskLoader.cpp
)

add_library(TaskProcessor STATIC ${SOURCES})

target_include_directories(TaskProcessor PUBLIC public)
