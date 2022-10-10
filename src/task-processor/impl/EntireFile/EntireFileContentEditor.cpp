#include "EntireFileContentEditor.hpp"

EntireFileContentEditor::EntireFileContentEditor(std::filesystem::path testsDir, int testNumber)
    : mTestsDir(std::move(testsDir))
    , mTestNumber(testNumber)
{
}

EntireFileContentEditor::~EntireFileContentEditor() = default;

TestContent EntireFileContentEditor::load() {
    return TestContent();
}

void EntireFileContentEditor::save(const TestContent &testContent) {

}

bool EntireFileContentEditor::validateInput(const std::string &input) {
    return true;
}

bool EntireFileContentEditor::checkOutput(const std::string &output) {
    return true;
}
