find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    public/TaskProcessor/TaskLoader.cpp
    public/TaskProcessor/TestVisualizerBase.hpp
    public/TaskProcessor/TestVisualizerBase.cpp

    impl/EntireFile/EntireFileContentEditor.cpp
    impl/EntireFile/EntireFileTestSelector.cpp
    impl/EntireFile/EntireFileTask.cpp

    impl/Visualizer/StatVisualizer.h
    impl/Visualizer/StatVisualizer.cpp
)

set(CMAKE_AUTOMOC ON)

add_library(TaskProcessor STATIC ${SOURCES})

target_link_libraries(TaskProcessor PUBLIC Qt6::Widgets)

target_include_directories(TaskProcessor PUBLIC public)
target_include_directories(TaskProcessor PRIVATE public/TaskProcessor)
target_include_directories(TaskProcessor PUBLIC impl) # todo PUBLIC is temporary
