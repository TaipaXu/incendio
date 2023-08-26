import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root

    title: qsTr("Incendio")
    visible: true
    width: 450
    height: 400
    minimumWidth: 250

    menuBar: MainWindowMenuBar {
        id: menuBar
    }

    Calculator {
        id: calculator
        anchors.fill: parent
    }
}
