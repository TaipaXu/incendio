find_package(QT NAMES Qt6 COMPONENTS Widgets Quick QuickControls2 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Quick QuickControls2 REQUIRED)

configure_file(./appConfig.hpp.in ./appConfig.hpp)

set(TARGET incendio)
set(SOURCES
        main.cpp
        core.hpp
        core.cpp

        quicks/calculator.hpp
        quicks/calculator.cpp

        utils/utils.hpp
        utils/utils.cpp
)

add_executable(
    ${TARGET}
    ${SOURCES}
)

target_link_libraries(${TARGET} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickControls2
    ${CMAKE_THREAD_LIBS_INIT})

qt_add_qml_module(${TARGET}
    URI qml
    NO_RESOURCE_TARGET_PATH
    QML_FILES
        "widgets/MainWindow.qml"
        "widgets/MainWindowMenuBar.qml"
        "widgets/Calculator.qml"
)
