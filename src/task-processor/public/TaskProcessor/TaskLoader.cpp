#include "TaskLoader.hpp"

#include "ITask.hpp"
#include "EntireFile/EntireFileTask.hpp"

std::unique_ptr<ITask> TaskLoader::loadFromDirectory(const std::filesystem::path& taskPath) {
    return std::make_unique<EntireFileTask>(taskPath);
}
