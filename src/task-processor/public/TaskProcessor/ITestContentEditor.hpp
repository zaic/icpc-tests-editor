#pragma once

#include <string>
#include <optional>

struct TestContent {
    std::string input;
    std::optional<std::string> answer;
    std::optional<std::string> description;
};

class ITestContentEditor {
public:
    virtual ~ITestContentEditor() = default;

    virtual TestContent load() = 0;
    virtual void save(const TestContent& testContent) = 0;

    virtual bool validateInput(const std::string& input) = 0;
    virtual bool checkOutput(const std::string& output) = 0;
};
