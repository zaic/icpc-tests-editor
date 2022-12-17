#include "TestContentManager.hpp"

TestContentManager::TestContentManager() = default;


void TestContentManager::resetTestContent(QString input, QString answer) {
    if (input == mInput && answer == mAnswer)
        return ;

    mInput = input;
    mAnswer = answer;
    emit testContentChanged(mInput, mAnswer);
}

void TestContentManager::updateInput(QString input) {
    if (input == mInput)
        return ;

    mInput = input;
    emit testContentChanged(mInput, mAnswer);
}

void TestContentManager::updateAnswer(QString answer) {
    if (answer == mAnswer)
        return ;

    mAnswer = answer;
    emit testContentChanged(mInput, mAnswer);
}
