#pragma once

#include "ITask.hpp"

#include <filesystem>

class EntireFileTask : public ITask {
public:
    EntireFileTask(std::filesystem::path taskDir);
    ~EntireFileTask() override;

    std::unique_ptr<ITestSelector> testSelector() override;
    std::unique_ptr<TestVisualizerBase> testVisualizer() override;

private:
    const std::filesystem::path mTaskDir;
};
