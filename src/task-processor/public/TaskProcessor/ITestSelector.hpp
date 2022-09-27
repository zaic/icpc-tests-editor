#pragma once

#include <string>
#include <vector>
#include <memory>

class ITestContentEditor;

struct TestNumber {
    std::string id;
    std::vector<std::string> parts;
};

class ITestSelector {
public:
    virtual ~ITestSelector() = default;

    virtual std::vector<std::string> listTestIds() = 0;
    virtual std::vector<TestNumber> listTestParts(const std::string& testId) = 0;
    virtual std::unique_ptr<ITestContentEditor> createTestEditor(const TestNumber& testNumber) = 0;
};
