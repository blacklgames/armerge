#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screens/changesscreen.h"
#include "screens/mergescreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stackedWidget(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Luxoft ARMerge tool");
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    ChangesScreen* changes = new ChangesScreen();
    MergeScreen* merges = new MergeScreen();
    stackedWidget->addWidget(changes);
    stackedWidget->addWidget(merges);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGoToChanges_triggered()
{
    stackedWidget->setCurrentIndex(SCREEN_CHAGES);
}

void MainWindow::on_actionGoToMerges_triggered()
{
    stackedWidget->setCurrentIndex(SCREEN_MERGE);
}
