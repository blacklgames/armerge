#include "changesscreen.h"
#include "ui_changesscreen.h"

ChangesScreen::ChangesScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangesScreen)
{
    ui->setupUi(this);
}

ChangesScreen::~ChangesScreen()
{
    delete ui;
}
