/*********************
** Numeron arvauspeli
** Jarmo Vuorinen
** 02.03.2023
*********************/

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15

Window {
    // Puhelimen resoluutio
//    width: 360
//    height: 800
    width: 480
    height: 640
    visible: true
    title: qsTr("Hello World")

    GridLayout {
        id: gridLayout
        anchors.fill: parent
        flow: GridLayout.TopToBottom
        rows: 4

        Text {
            id: text1
            opacity: 1
            visible: true
            text: qsTr("Arvaa luku 0 - 100 väliltä.")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            clip: false
            Layout.fillHeight: false
            Layout.fillWidth: true
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: text2
            text: qsTr("10 arvausta jäljellä.")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: false
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        TextField {
            id: textField
            color: "#000000"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillHeight: false
            Layout.fillWidth: false
            placeholderText: "Arvaus"
            hoverEnabled: true
            font.pointSize: 22
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: button
            width: 117
            text: qsTr("Tarkista")
            font.pointSize: 22
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
