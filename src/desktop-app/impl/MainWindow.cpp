#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <TaskProcessor/TaskLoader.hpp>
#include <TaskProcessor/ITask.hpp>
#include <TaskProcessor/TestVisualizerBase.hpp>

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
}

void MainWindow::unloadTask() {
    if (!mTask)
        return ;
    // todo disconnect?
    ui->sptVisualization->setEnabled(false);
    mTask.release();
}

void MainWindow::loadTask(QString taskDir) {
    mTask = TaskLoader::loadFromDirectory(taskDir.toStdString());
    ui->sptVisualization->setEnabled(true);

    // todo:
    //  get visualuzation widget
    //  add it into windows
    //  remove when unloadint the task
    auto visualizer = mTask->testVisualizer();
    visualizer->drawVisualizationInto(*ui->wdgVisualization);

    connect(ui->txtInput, &QTextEdit::textChanged, [this](){
        mContentManager.updateInput(ui->txtInput->toPlainText());
    });
    connect(ui->txtOutput, &QTextEdit::textChanged, [this](){
        mContentManager.updateAnswer(ui->txtOutput->toPlainText());
    });
    connect(&mContentManager, &TestContentManager::testContentChanged, [this](QString input, QString answer){
        ui->txtInput->setText(input);
        ui->txtOutput->setText(answer);
        //visualizer->resetTestContent(input, answer);
    });

    mContentManager.resetTestContent("input text", "output text");
}
