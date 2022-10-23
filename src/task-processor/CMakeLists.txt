find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    public/TaskProcessor/TaskLoader.cpp

    impl/EntireFile/EntireFileContentEditor.cpp
    impl/EntireFile/EntireFileTestSelector.cpp
    impl/EntireFile/EntireFileTask.cpp

    impl/Visualizer/StatVisualizer.cpp
)

add_library(TaskProcessor STATIC ${SOURCES})

target_link_libraries(TaskProcessor PUBLIC Qt6::Widgets)

target_include_directories(TaskProcessor PUBLIC public)
target_include_directories(TaskProcessor PRIVATE public/TaskProcessor)
target_include_directories(TaskProcessor PUBLIC impl)
