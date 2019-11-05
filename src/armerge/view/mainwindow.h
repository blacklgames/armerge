#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qtreewidgetitemiterator.h>
#include "QStackedWidget.h"
#include "communication/viewproxy.h"


namespace Ui {
class MainWindow;
}

enum eScreens
{
    SCREEN_CHAGES,
    SCREEN_MERGE
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();
    void setProxy(ViewProxy* proxy);

private slots:
    void on_actionGoToChanges_triggered();
    void on_actionGoToMerges_triggered();

private:
    ViewProxy *mProxy;
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
};

#endif // MAINWINDOW_H
