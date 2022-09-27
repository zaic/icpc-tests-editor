#pragma once

#include <memory>
#include <filesystem>

class ITask;

class TaskLoader {
public:
    static std::unique_ptr<ITask> loadFromDirectory(const std::filesystem::path& taskPath);

private:
    TaskLoader() = delete;
};
