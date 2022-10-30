#pragma once

#include <QObject>

class TestContentManager final : QObject {
    Q_OBJECT

public:
    TestContentManager();

public slots:
    void resetTestContent(QString input, QString answer);
    void updateInput(QString input);
    void updateAnswer(QString answer);

signals:
    void testContentChanged(QString input, QString answer);
    void inputChanged(QString input);
    void answerChanged(QString answer);

private:
    QString mInput;
    QString mAnswer;
};
