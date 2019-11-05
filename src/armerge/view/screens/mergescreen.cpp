#include "mergescreen.h"
#include "ui_mergescreen.h"

MergeScreen::MergeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MergeScreen)
{
    ui->setupUi(this);
}

MergeScreen::~MergeScreen()
{
    delete ui;
}

void MergeScreen::on_btnMoveYorSelected_clicked()
{
    notify(MOVE_YOR_SELECTED);
}

void MergeScreen::on_btnMoveYourAll_clicked()
{
    notify(MOVE_YOUR_ALL);
}

void MergeScreen::on_btnRemoveCurrentSelected_clicked()
{
    notify(REMOVE_CURRENT_SELECTED);
}

void MergeScreen::on_btnRemoveCurrentAll_clicked()
{
    notify(REMOVE_CURRENT_ALL);
}
