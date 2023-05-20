#include "./core.hpp"
#include <QQmlApplicationEngine>
#include "quicks/calculator.hpp"
#include "utils/utils.hpp"

Core::Core()
{
    qmlRegisterType<Quick::Calculator>("calculator", 1, 0, "Calculator");
    qmlRegisterType<Utils>("utils", 1, 0, "Utils");

    engine = new QQmlApplicationEngine();
    engine->load(":/mainWindow");
}

Core::~Core()
{
    delete engine;
}
