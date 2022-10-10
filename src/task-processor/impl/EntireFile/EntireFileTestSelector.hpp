#pragma once

#include "ITestSelector.hpp"

#include <filesystem>

class EntireFileTestSelector : public ITestSelector {
public:
    EntireFileTestSelector(std::filesystem::path testsDir);
    ~EntireFileTestSelector() override;

    std::vector<std::string> listTestIds() override;
    std::vector<TestNumber> listTestParts(const std::string& testId) override;
    std::unique_ptr<ITestContentEditor> createTestEditor(const TestNumber& testNumber) override;

private:
    const std::filesystem::path mTestsDir;
};
