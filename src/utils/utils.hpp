#pragma once

#include <QObject>
#include <QString>

class Utils : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString projectDomain READ getProjectDomain)
    Q_PROPERTY(QString projectIssuesDomain READ getProjectIssuesDomain)

public:
    Utils(QObject *parent = nullptr);
    ~Utils() = default;

    QString getProjectDomain() const;
    QString getProjectIssuesDomain() const;

    Q_INVOKABLE static void aboutQt();
};
