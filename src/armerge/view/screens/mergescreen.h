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

private:
    Ui::MergeScreen *ui;
};

#endif // MERGESCREEN_H
