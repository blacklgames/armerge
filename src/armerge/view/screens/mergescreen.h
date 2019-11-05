#ifndef MERGESCREEN_H
#define MERGESCREEN_H

#include <QWidget>
#include "view/communication/viewsubject.h"

namespace Ui {
class MergeScreen;
}

class MergeScreen : public QWidget, public ViewSubject
{
    Q_OBJECT

public:
    explicit MergeScreen(QWidget *parent = nullptr);
    ~MergeScreen();

private slots:
    void on_btnMoveYorSelected_clicked();

    void on_btnMoveYourAll_clicked();

    void on_btnRemoveCurrentSelected_clicked();

    void on_btnRemoveCurrentAll_clicked();

private:
    Ui::MergeScreen *ui;
};

#endif // MERGESCREEN_H
