import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Material 2.15

/*Application*/Window {
    id: window
    width: 480
    height: 640
    visible: true
    title: qsTr("Paska soitin")
    Material.theme: control.position < 1 ? Material.Light : Material.Dark

    Drawer {
        id: drawer
        width: 0.50 * window.width
        height: window.height

        Label {
            id: content
            text: "Copyright \xa9 2023 by Jarmo Vuorinen" // All rights reserved.\n
            font.pixelSize: 12
            anchors.margins: 12
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Switch {
            id: control
            anchors.right: parent.right
            anchors.top: parent.top
            text: "Dark theme"
            checked: false
        }
    }

    GridLayout {
        id: gridLayout
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        columns: 5
        rows: 5

        TextField {
            id: textField
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 10
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.minimumHeight: 100
            Layout.columnSpan: 5
            Layout.rowSpan: 1
            placeholderText: qsTr("Hello World")
            text: mediaplayer.display
        }

        ScrollView {
            id: scrollView
            width: 200
            height: 200
            Layout.bottomMargin: 0
            Layout.topMargin: 0
            Layout.margins: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 5
        }

        ProgressBar {
            id: progressBar
            Layout.rightMargin: 25
            Layout.leftMargin: 25
            Layout.margins: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.columnSpan: 5
            value: 0.5
        }

        RoundButton {
            id: roundButton5
            text: "+"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        RoundButton {
            id: roundButton6
            text: "+"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        RoundButton {
            id: play
            text: "Play"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
            onClicked: mediaplayer.playClicked()
        }

               RoundButton {
            id: roundButton8
            text: "+"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        RoundButton {
            id: roundButton9
            text: "+"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
        }
    }
}


