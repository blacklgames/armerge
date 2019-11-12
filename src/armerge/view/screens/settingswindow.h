#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include "view/communication/viewsubject.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget, public ViewSubject
{
    Q_OBJECT

public:

    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

    void updateView();

private slots:
    void on_okBtn_clicked();

    void on_cbStrems_currentTextChanged(const QString &arg1);

private:
    Ui::SettingsWindow *ui;
    bool mInit;
};

#endif // SETTINGSWINDOW_H
