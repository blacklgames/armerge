#include "settingssingletone.h"
#include "iostream"

SettingsSingletone* SettingsSingletone::_self = nullptr;

SettingsSingletone::SettingsSingletone()
{

}

SettingsSingletone::SettingsSingletone(const SettingsSingletone& )
{

}

void SettingsSingletone::add(QString path)
{
    mVector.push_back(path);
}

void SettingsSingletone::clearSettings()
{
    mVector.clear();
}

std::vector<QString> SettingsSingletone::getSettingList()
{
    return mVector;
}

QString SettingsSingletone::getFileName()
{
    QString str(FILE_NAME);
    return str;
}

void SettingsSingletone::addBuildName(QString buildName)
{
    cout << buildName.toStdString().c_str() << endl;
    vBuilds.push_back(buildName);
}

std::vector<QString> SettingsSingletone::getBuildsNameList()
{
    return vBuilds;
}

bool SettingsSingletone::isConfigure()
{
    return mVector.size() > 0;
}

string SettingsSingletone::getSettingsName(const eSettings settingsId)
{
    QString str = "";
    switch (settingsId) {
    case S_SOURCE_PATH:
        str = SOURCE_PATH_NAME;
        break;
    case S_BUILD_PATH:
        str = BUILD_PATH_NAME;
        break;
    case S_QT_PATH:
        str = QTT_PATH_NAME;
        break;
    case S_MERGE_PATH:
        str = MERGE_PATH_NAME;
        break;
    default:
        break;
    }
    return str.toStdString();
}


int SettingsSingletone::getBuildStream() const
{
    return mBuildStream;
}

void SettingsSingletone::setBuildStream(int buildStream)
{
    mBuildStream = buildStream;
}

QString SettingsSingletone::getBuidVersion() const
{
    return mBuidVersion;
}

void SettingsSingletone::setBuidVersion(const QString &buidVersion)
{
    mBuidVersion = buidVersion;
}

QString SettingsSingletone::getSoruceVersion() const
{
    return mSoruceVersion;
}

void SettingsSingletone::setSoruceVersion(const QString &soruceVersion)
{
    mSoruceVersion = soruceVersion;
}

