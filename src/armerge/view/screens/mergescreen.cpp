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
