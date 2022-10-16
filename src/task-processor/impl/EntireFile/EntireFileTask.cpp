#include "EntireFileTask.hpp"

#include "ITestSelector.hpp"
#include "TestVisualizerBase.hpp"

EntireFileTask::EntireFileTask(std::filesystem::path taskDir)
    : mTaskDir(std::move(taskDir))
{
}

EntireFileTask::~EntireFileTask() = default;

std::unique_ptr<ITestSelector> EntireFileTask::testSelector() {
    return nullptr;
}

std::unique_ptr<TestVisualizerBase> EntireFileTask::testVisualizer() {
    return nullptr;
}
