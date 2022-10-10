#include "EntireFileTestSelector.hpp"

#include "ITestContentEditor.hpp"

EntireFileTestSelector::EntireFileTestSelector(std::filesystem::path testsDir)
    : mTestsDir(std::move(testsDir)) {
}

EntireFileTestSelector::~EntireFileTestSelector() = default;

std::vector<std::string> EntireFileTestSelector::listTestIds() {
    return {};
}

std::vector<TestNumber> EntireFileTestSelector::listTestParts(const std::string &testId) {
    return {};
}

std::unique_ptr<ITestContentEditor> EntireFileTestSelector::createTestEditor(const TestNumber &testNumber) {
    return nullptr;
}
