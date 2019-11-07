#include "settingswindow.h"
#include "ui_settingscreen.h"

#include "iostream"
#include "settingssingletone.h"

#include <Qt>
#include <QDir>
#include <QtCore>

using namespace std;

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow),
    mInit(false)
{
    ui->setupUi(this);
    ui->txtInfo->setText("");

    if (QFile::exists(QString(FILE_NAME)))
    {
        QFile file(QString(FILE_NAME));
        if (file.open(QIODevice::ReadOnly))
        {
            QString str;
            QStringList list;

            while(!file.atEnd())
            {
                str = file.readLine();
                list.append(str.right(str.size() - str.indexOf("=") - 1).simplified());
            }

            if(list.size() < SettingsSingletone::S_MAX - 1)
            {
                cerr << "correct setup.ini" << endl;
            }

            ui->sourcePath->setText(list[SettingsSingletone::S_SOURCE_PATH]);
            ui->buildPath->setText(list[SettingsSingletone::S_BUILD_PATH]);
            ui->qtPath->setText(list[SettingsSingletone::S_QT_PATH]);
            ui->mergePath->setText(list[SettingsSingletone::S_MERGE_PATH]);

            SettingsSingletone::getInstance()->clearSettings();
            SettingsSingletone::getInstance()->add(list[SettingsSingletone::S_SOURCE_PATH]);
            SettingsSingletone::getInstance()->add(list[SettingsSingletone::S_BUILD_PATH]);
            SettingsSingletone::getInstance()->add(list[SettingsSingletone::S_QT_PATH]);
            SettingsSingletone::getInstance()->add(list[SettingsSingletone::S_MERGE_PATH]);

            /*QDir d(list[SettingsSingletone::S_SOURCE_PATH].split("\\").join("\\\\").append("\\\\.."));
            if(d.exists())
            {
                QString currName("");
                QFileInfoList il = d.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs);
                for (int i = 0; i < il.size(); ++i)
                {
                    QFileInfo info = il.at(i);
                    if(info.isDir())
                    {
                        QString name = info.fileName();
                        QDir dd(info.absoluteFilePath());
                        if(dd.exists())
                        {
                            QFileInfoList ill = dd.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
                            for (int j = 0; j < ill.size(); ++j)
                            {
                                QFileInfo in = ill.at(j);
                                if(in.fileName() == "WorkspaceSettings.set")
                                {
                                    ui->cbStrems->addItem(name);
                                    SettingsSingletone::getInstance()->addBuildName(name);
                                    if(list[SettingsSingletone::S_SOURCE_PATH].contains(name))
                                    {
                                        currName = name;
                                    }

                                }
                            }
                        }
                    }
                }

                ui->cbStrems->setCurrentText(currName);
                SettingsSingletone::getInstance()->setSoruceVersion(currName);
            }*/
        }
    }
    else
    {
        cout << "file doesn't exist create new file" << endl;
        QFile mFile(FILE_NAME);
        mFile.open(QIODevice::WriteOnly);
        mFile.close();
    }

    mInit = true;
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_okBtn_clicked()
{
    QString path1 = ui->sourcePath->text();
    QString path2 = ui->buildPath->text();
    QString path3 = ui->qtPath->text();
    QString path4 = ui->mergePath->text();

    if (QFile::exists(QString(FILE_NAME)))
    {
        QFile file(QString(FILE_NAME));
        if (file.open(QIODevice::WriteOnly | QFile::Truncate))
        {
            QTextStream stream(&file);
            string s1(SOURCE_PATH_NAME);
            string s2(BUILD_PATH_NAME);
            string s3(QTT_PATH_NAME);
            string s4(MERGE_PATH_NAME);

            stream << s1.c_str() << "=" << path1 << endl;
            stream << s2.c_str() << "=" << path2 << endl;
            stream << s3.c_str() << "=" << path3 << endl;
            stream << s4.c_str() << "=" << path4 << endl;

            file.close();
        }
    }

    /*if(path1.size() == 0 || !QDir::isAbsolutePath(path1))
    {
        ui->txtInfo->setText("Set path for working project directory");
        return;
    }
    else if(path2.size() == 0 || !QDir::isAbsolutePath(path2))
    {
        ui->txtInfo->setText("Set path for buildin project directory");
        return;
    }*/
    ui->txtInfo->setText("Ok");
    SettingsSingletone::getInstance()->clearSettings();
    SettingsSingletone::getInstance()->add(path1);
    SettingsSingletone::getInstance()->add(path2);
    SettingsSingletone::getInstance()->add(path3);
    SettingsSingletone::getInstance()->add(path4);
}

void SettingsWindow::on_cbStrems_currentTextChanged(const QString &arg1)
{
    QDir d(ui->sourcePath->text().split("\\").join("\\\\").append("\\\\.."));
    if(d.exists() && mInit)
    {
        ui->sourcePath->setText(d.absolutePath().append("\\" + arg1));
        SettingsSingletone::getInstance()->setSoruceVersion(arg1);
        on_okBtn_clicked();
    }
}
