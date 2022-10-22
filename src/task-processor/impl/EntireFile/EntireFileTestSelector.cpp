#include "EntireFileTestSelector.hpp"

#include "EntireFileContentEditor.hpp"

namespace fs = std::filesystem;

namespace {

std::optional<int> extractTestNumber(const std::string test) {
    try {
        return std::stoi(test);
    }
    catch (std::invalid_argument& ) {
        return std::nullopt;
    }
}

bool compareTestNumber(const std::string& left, const std::string& right) {
    const std::optional<int> leftNumber = extractTestNumber(left);
    const std::optional<int> rightNumber = extractTestNumber(right);

    if (leftNumber.has_value() && rightNumber.has_value())
        return leftNumber.value() < rightNumber.value();

    if (!leftNumber.has_value() && !rightNumber.has_value())
        return left < right;

    return leftNumber.has_value();
};

}

EntireFileTestSelector::EntireFileTestSelector(fs::path testsDir)
    : mTestsDir(std::move(testsDir)) {
}

EntireFileTestSelector::~EntireFileTestSelector() = default;

std::vector<std::string> EntireFileTestSelector::listTestIds() {
    std::vector<std::string> testIds;
    for (const auto& dirEntry : fs::directory_iterator{mTestsDir}) {
        const std::string inputExtension = ".in";
        if (dirEntry.is_regular_file() && dirEntry.path().extension() == inputExtension) {
            const std::string fileName = dirEntry.path().filename().string();
            const std::string testNumber = fileName.substr(0, fileName.size() - inputExtension.size());
            testIds.push_back(testNumber);
        }
    }

    std::sort(testIds.begin(), testIds.end(), compareTestNumber);

    return testIds;
}

std::vector<TestNumber> EntireFileTestSelector::listTestParts(const std::string& testId) {
    return {TestNumber{testId, {}}};
}

std::unique_ptr<ITestContentEditor> EntireFileTestSelector::createTestEditor(const TestNumber& testNumber) {
    return std::make_unique<EntireFileContentEditor>(mTestsDir, testNumber.id);
}
