#ifndef SETTINGSSINGLETONE_H
#define SETTINGSSINGLETONE_H

#include <string>
#include <QStringList>
#include <vector>

#define FILE_NAME "setup.ini"
#define SOURCE_PATH_NAME "SOURCE_PATH_NAME"
#define BUILD_PATH_NAME "BUILD_PATH_NAME"
#define QTT_PATH_NAME "QT_PATH_NAME"
#define MERGE_PATH_NAME "MERGE_PATH_NAME"
#define TARGET_BUILD_FOLDER_NAME "TARGET_BUILD_FOLDER_NAME "
#define TARGET_BUILD_VARIANT "TARGET_BUILD_VARIANT"

using namespace std;

class SettingsSingletone
{
public:
    enum eSettings
    {
        S_SOURCE_PATH,
        S_BUILD_PATH,
        S_QT_PATH,
        S_MERGE_PATH,
        S_MAX
    };

    enum eSourceStream
    {
        SNA,
        V_E01X,
        V_E02X,
        V_E03X
    };

    static SettingsSingletone* getInstance()
    {
        if(!_self)
        {
            _self = new SettingsSingletone();
        }
        return _self;
    }

    void add(QString path);
    void clearSettings();
    std::vector<QString> getSettingList();
    QString getFileName();
    string getSettingsName(const eSettings settingsId);
    bool isConfigure();
    QString getBuildInfoFileName();

    void addBuildName(QString buildName);
    std::vector<QString> getBuildsNameList();

    std::vector<QString> mVector;
    std::vector<QString> vBuilds;

    QString mSoruceVersion;
    QString mBuidVersion;
    int mBuildStream;

    QString getSoruceVersion() const;
    void setSoruceVersion(const QString &soruceVersion);

    QString getBuidVersion() const;
    void setBuidVersion(const QString &buidVersion);

    int getBuildStream() const;
    void setBuildStream(int buildStream);

protected:
    SettingsSingletone();
    SettingsSingletone(const SettingsSingletone& );

private:
    static SettingsSingletone* _self;
};

#endif // SETTINGSSINGLETONE_H
