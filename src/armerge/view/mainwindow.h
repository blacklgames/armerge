#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qtreeview.h>
#include <QtWidgets/qtreewidgetitemiterator.h>
#include "QStackedWidget.h"
#include "communication/viewproxy.h"
#include "communication/viewsubject.h"
#include "model/model.h"

namespace Ui {
class MainWindow;
}

enum eScreens
{
    SCREEN_CHAGES,
    SCREEN_MERGE,
    SCREEN_SETTINGS
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();
    void setProxy(ViewProxy* proxy);
    void setModel(Model* model);

private slots:
    void on_actionGoToChanges_triggered();
    void on_actionGoToMerges_triggered();
    void on_actionGoToSettings_triggered();

public slots:
    void updateView();

private:
    ViewProxy *mProxy;
    Model *mModel;
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    std::vector<ViewSubject*> mViewList;
};

#endif // MAINWINDOW_H
