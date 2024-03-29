#pragma once

#include "TestVisualizerBase.hpp"
#include <QLabel>

class StatVisualizer : public TestVisualizerBase {
    Q_OBJECT

public:
    StatVisualizer();
    ~StatVisualizer() override;

    void drawVisualizationInto(QWidget& parent) override;

public slots:
    void resetTestContent(QString input, QString answer) override;

private:
    QLabel* mStatLabel = nullptr;
};
