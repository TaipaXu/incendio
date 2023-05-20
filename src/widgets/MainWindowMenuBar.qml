import QtQuick
import QtQuick.Controls
import utils

MenuBar {
    Menu {
        title: qsTr("&About")

        MenuItem {
            action: Action {
                icon.name: "help-about"
                text: qsTr("&About")
                onTriggered: Qt.openUrlExternally(utils.projectDomain)
            }
        }

        MenuItem {
            action: Action {
                icon.name: "help-about"
                text: qsTr("About &Qt")
                onTriggered: utils.aboutQt()
            }
        }

        MenuSeparator {}

        MenuItem {
            action: Action {
                icon.name: "tools-report-bug"
                text: qsTr("&Report a bug")
                onTriggered: Qt.openUrlExternally(utils.projectIssuesDomain)
            }
        }
    }

    Utils {
        id: utils
    }
}
