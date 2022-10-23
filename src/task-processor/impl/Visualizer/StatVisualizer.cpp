#include "StatVisualizer.h"

#include <QVBoxLayout>

StatVisualizer::StatVisualizer() = default;

StatVisualizer::~StatVisualizer() = default;

void StatVisualizer::drawVisualizationInto(QWidget &parent) {
    auto layout = new QVBoxLayout(&parent);
    mStatLabel = new QLabel();
    layout->addWidget(mStatLabel);
}

void StatVisualizer::resetTestContent(QString input, QString answer) {
    int lines = 0;
    int words = 0;
    int chars = 0;
    bool inWord = false;
    for (const QChar c : input) {
        if (c.isSpace()) {
            inWord = false;
        } else {
            if (!inWord)
                ++words;
            inWord = true;
        }

        if (c == '\n')
            ++lines;

        ++chars;
    }
    mStatLabel->setText(QString("Lines: %1\nWords: %2\nCharacters: %3").arg(lines).arg(words).arg(chars));
}
