set(SOURCES
    public/TaskProcessor/TaskLoader.cpp

    impl/EntireFile/EntireFileContentEditor.cpp
    impl/EntireFile/EntireFileTestSelector.cpp
    impl/EntireFile/EntireFileTask.cpp
)

add_library(TaskProcessor STATIC ${SOURCES})

target_include_directories(TaskProcessor PUBLIC public)
target_include_directories(TaskProcessor PRIVATE public/TaskProcessor)
target_include_directories(TaskProcessor PUBLIC impl)
