#include "./utils.hpp"
#include <QApplication>
#include "appConfig.hpp"

Utils::Utils(QObject *parent)
    : QObject(parent)
{
}

void Utils::aboutQt()
{
    QApplication::aboutQt();
}

QString Utils::getProjectDomain() const
{
    return QString(PROJECT_DOMAIN);
}

QString Utils::getProjectIssuesDomain() const
{
    return QString(PROJECT_ISSUES_DOMAIN);
}
