#ifndef CHANGEDFILES_H
#define CHANGEDFILES_H

#include <QObject>

class ChangedFiles : public QObject
{
    Q_OBJECT
public:
    explicit ChangedFiles(QObject *parent = nullptr);
    void setName(QString name);
    QString getName() const ;


signals:

public slots:

private:
    QString mName;
};

#endif // CHANGEDFILES_H
