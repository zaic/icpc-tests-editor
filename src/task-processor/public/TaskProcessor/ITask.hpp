#pragma once

#include <memory>

class ITestSelector;
class TestVisualizerBase;

class ITask {
public:
    virtual ~ITask() = default;

    virtual std::unique_ptr<ITestSelector> testSelector() = 0;
    virtual std::unique_ptr<TestVisualizerBase> testVisualizer() = 0;
};
