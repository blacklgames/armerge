#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "screens/changesscreen.h"
#include "screens/mergescreen.h"
#include "screens/settingswindow.h"
#include "settingssingletone.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stackedWidget(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Luxoft ARMerge tool");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    SettingsWindow* settings = new SettingsWindow();
    ChangesScreen* changes = new ChangesScreen();
    MergeScreen* merges = new MergeScreen();

    stackedWidget->addWidget(changes);
    stackedWidget->addWidget(merges);
    stackedWidget->addWidget(settings);
    changes->attach(mProxy);
    merges->attach(mProxy);
    settings->attach(mProxy);

    if(!SettingsSingletone::getInstance()->isConfigure())
    {
        stackedWidget->setCurrentIndex(SCREEN_SETTINGS);
    }
    else
    {
        changes->notify(ViewSubject::INIT);
    }

}

void MainWindow::setProxy(ViewProxy* proxy)
{
    mProxy = proxy;
}

void MainWindow::on_actionGoToChanges_triggered()
{
    stackedWidget->setCurrentIndex(SCREEN_CHAGES);
}

void MainWindow::on_actionGoToMerges_triggered()
{
    stackedWidget->setCurrentIndex(SCREEN_MERGE);
}

void MainWindow::on_actionGoToSettings_triggered()
{
    stackedWidget->setCurrentIndex(SCREEN_SETTINGS);
}
