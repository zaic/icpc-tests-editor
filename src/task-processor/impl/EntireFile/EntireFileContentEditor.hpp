#pragma once

#include "ITestContentEditor.hpp"

#include <filesystem>

class EntireFileContentEditor : public ITestContentEditor {
public:
    EntireFileContentEditor(std::filesystem::path testsDir, std::string testNumber);
    ~EntireFileContentEditor() override;

    TestContent load() override;
    void save(const TestContent& testContent) override;

    bool validateInput(const std::string& input) override;
    bool checkOutput(const std::string& output) override;

private:
    const std::filesystem::path mTestsDir;
    const std::string mTestNumber;
};
