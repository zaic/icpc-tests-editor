#pragma once

#include "TestContentManager.hpp"

#include <QMainWindow>

#include <memory>

class ITask;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void runTaskOpenDialog();

private:
    void unloadTask();
    void loadTask(QString taskDir);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ITask> mTask;
    TestContentManager mContentManager;
};
