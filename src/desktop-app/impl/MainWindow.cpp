#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <TaskProcessor/TaskLoader.hpp>
#include <TaskProcessor/ITask.hpp>

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::runTaskOpenDialog() {
    const QString taskDir = QFileDialog::getExistingDirectory(this, tr("Open Task"));
    if (taskDir.isEmpty())
        return ;
    unloadTask();
    loadTask(taskDir);
    ui->sptVisualization->setEnabled(!taskDir.isEmpty());
}

void MainWindow::unloadTask() {
    if (!mTask)
        return ;
    ui->sptVisualization->setEnabled(false);
    mTask.release();
}

void MainWindow::loadTask(QString taskDir) {
    mTask = TaskLoader::loadFromDirectory(taskDir.toStdString());
    ui->sptVisualization->setEnabled(true);
}
