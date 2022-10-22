#include "EntireFileContentEditor.hpp"

#include <fstream>

namespace fs = std::filesystem;

namespace {

std::string getInput(const std::string& testNumber) {
    return testNumber + ".in";
}

std::string getAnswer(const std::string& testNumber) {
    return testNumber + ".out";
}

std::string getDescription(const std::string& testNumber) {
    return testNumber + ".desc";
}

std::string readFileContent(const fs::path& filePath) {
    std::ifstream stream;
    stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    stream.open(filePath);

    std::string result, line;
    while (std::getline(stream, line)) {
        result += line;
        result += '\n';
    }
    return result;
}

std::optional<std::string> readFileContentIfPreset(const fs::path& filePath) {
    if (fs::is_regular_file(filePath))
        return readFileContent(filePath);
    return std::nullopt;
}

void writeFileContent(const fs::path& filePath, const std::string& content) {
    std::ofstream stream;
    stream.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    stream.open(filePath);

    stream << content;
}

}

EntireFileContentEditor::EntireFileContentEditor(fs::path testsDir, std::string testNumber)
    : mTestsDir(std::move(testsDir))
    , mTestNumber(std::move(testNumber))
{
}

EntireFileContentEditor::~EntireFileContentEditor() = default;

TestContent EntireFileContentEditor::load() {
    TestContent content;
    content.input = readFileContent(mTestsDir / getInput(mTestNumber));
    content.answer = readFileContentIfPreset(mTestsDir / getAnswer(mTestNumber));
    content.description = readFileContentIfPreset(mTestsDir / getDescription(mTestNumber));
    return content;
}

void EntireFileContentEditor::save(const TestContent& testContent) {
    writeFileContent(getInput(mTestNumber), testContent.input);

    if (testContent.answer.has_value())
        writeFileContent(getAnswer(mTestNumber), testContent.answer.value());
    else
        fs::remove(getAnswer(mTestNumber));

    if (testContent.description.has_value())
        writeFileContent(getDescription(mTestNumber), testContent.description.value());
    else
        fs::remove(getDescription(mTestNumber));
}

bool EntireFileContentEditor::validateInput(const std::string& input) {
    return true;
}

bool EntireFileContentEditor::checkOutput(const std::string& output) {
    return true;
}
