import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import calculator as Quick

Quick.Calculator {
    id: root

    property list<var> cpuCores: []

    ColumnLayout {
        property int padding: 10

        width: parent.width - padding * 2
        height: parent.height - padding * 2
        x: padding
        y: padding

        RowLayout {
            id: layout

            Layout.alignment: Qt.AlignTop

            ComboBox {
                id: cpuCoresSelector

                displayText: qsTr("CPU Cores ") + currentText
                textRole: "text"
                valueRole: "value"
            }

            Item {
                Layout.fillWidth: true
            }

            Button {
                visible: !calculator.running
                text: qsTr("Start")

                onClicked: calculator.start(cpuCoresSelector.currentValue)
            }
            Button {
                visible: calculator.running
                text: qsTr("Stop")

                onClicked: calculator.stop()
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignCenter

            Label {
                text: root.duration
                font.pixelSize: 50
            }
        }

        Item {
            height: 20
        }
    }

    Component.onCompleted: {
        const cpuCores = []
        for (let i = 0; i < root.cpuCoresCount; i++) {
            cpuCores.push({
                text: i + 1,
                value: i + 1
            })
        }
        cpuCoresSelector.model = cpuCores
        cpuCoresSelector.currentIndex = root.cpuCoresCount - 1
    }
}
