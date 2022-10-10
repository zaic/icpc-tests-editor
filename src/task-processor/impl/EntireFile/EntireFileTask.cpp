#include "EntireFileTask.hpp"

#include "ITestSelector.hpp"
#include "ITestVisualizer.hpp"

EntireFileTask::EntireFileTask(std::filesystem::path taskDir)
    : mTaskDir(std::move(taskDir))
{
}

EntireFileTask::~EntireFileTask() = default;

std::unique_ptr<ITestSelector> EntireFileTask::testSelector() {
    return nullptr;
}

std::unique_ptr<ITestVisualizer> EntireFileTask::testVisualizer() {
    return nullptr;
}
