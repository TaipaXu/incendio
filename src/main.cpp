#include <QApplication>
#include "core.hpp"
#include "appConfig.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationDomain(ORGANIZATION_DOMAIN);
    app.setApplicationVersion(PROJECT_VERSION);
    app.setApplicationName(PROJECT_NAME);
    app.setApplicationDisplayName(DISPLAY_NAME);

    Core core;

    const int result = app.exec();

    return result;
}
