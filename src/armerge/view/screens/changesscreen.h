#ifndef BASESCREEN_H
#define BASESCREEN_H

#include <QWidget>
#include "view/communication/viewsubject.h"


namespace Ui {
class ChangesScreen;
}

class ChangesScreen : public QWidget, public ViewSubject
{
    Q_OBJECT

public:
    explicit ChangesScreen(QWidget *parent = nullptr);
    ~ChangesScreen();

private:
    Ui::ChangesScreen *ui;
};

#endif // BASESCREEN_H
