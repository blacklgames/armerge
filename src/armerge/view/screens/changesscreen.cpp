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
    checked = checked;
}

void ChangesScreen::updateView()
{
    const vFiles& fileList = mModel->getChangedFiles();
    QTreeWidget * tree = ui->treeChanges;
    tree->clear();

    for(auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        QTreeWidgetItem * topLevel = new QTreeWidgetItem();
        auto name = (*it)->getName();
        topLevel->setText(0, name);

        for(int i=0; i<5; i++)
        {
            QTreeWidgetItem * item = new QTreeWidgetItem();
            item->setText(0,"item " + QString::number(i+1));
            topLevel->addChild(item);
        }

        tree->addTopLevelItem(topLevel);

    }

}
