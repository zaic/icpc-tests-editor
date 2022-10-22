#include "EntireFileTask.hpp"

#include "EntireFileTestSelector.hpp"
#include "TestVisualizerBase.hpp"

namespace fs = std::filesystem;

namespace {

fs::path getTestsDir(const fs::path& taskDir) {
    return taskDir / "tests";
}

}

EntireFileTask::EntireFileTask(std::filesystem::path taskDir)
    : mTaskDir(std::move(taskDir))
{
    if (!fs::is_directory(mTaskDir))
        throw std::runtime_error("Specified task directory is not a directory");
    if (!fs::is_directory(getTestsDir(mTaskDir)))
        throw std::runtime_error("Task directory should contain 'tests' directory");
}

EntireFileTask::~EntireFileTask() = default;

std::unique_ptr<ITestSelector> EntireFileTask::testSelector() {
    return std::make_unique<EntireFileTestSelector>(getTestsDir(mTaskDir));
}

std::unique_ptr<TestVisualizerBase> EntireFileTask::testVisualizer() {
    return nullptr;
}
