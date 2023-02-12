#pragma once

#include <QObject>

class TestVisualizerBase : public QObject {
    Q_OBJECT

public:
    TestVisualizerBase();
    virtual ~TestVisualizerBase();

    virtual void drawVisualizationInto(QWidget& parent) = 0;

public slots:
    virtual void resetTestContent(QString input, QString answer) = 0;

signals:
    void inputChanged(QString input);
    void answerChanged(QString answer);
};
