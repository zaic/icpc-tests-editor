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

    connect(ui->txtInput, &QTextEdit::textChanged, [this](){
        mContentManager.updateInput(ui->txtInput->toPlainText());
    });
    connect(ui->txtOutput, &QTextEdit::textChanged, [this](){
        mContentManager.updateAnswer(ui->txtOutput->toPlainText());
    });
    connect(&mContentManager, &TestContentManager::testContentChanged, [this](QString input, QString answer){
        ui->txtInput->setText(input);
        ui->txtOutput->setText(answer);
    });
}
