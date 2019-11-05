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

void ChangesScreen::on_btnFix_clicked()
{
    notify(ViewSubject::FIX_CHANGES);
}

void ChangesScreen::on_btnRemoveSelected_clicked()
{
    notify(ViewSubject::REMOVE_SELECTED);
}

void ChangesScreen::on_btnClearAll_clicked()
{
    notify(ViewSubject::CLEAR_ALL);
}

void ChangesScreen::on_btnFix_clicked(bool checked)
{

}
