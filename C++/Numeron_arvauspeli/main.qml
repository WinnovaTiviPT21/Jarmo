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
    title: qsTr("Numeron arvauspeli")

    GridLayout {
        id: gridLayout1
        visible: false
        anchors.fill: parent
        rows: 4
        Layout.fillWidth: false
        Text {
            id: text1
            opacity: 1
            visible: true
            text: qsTr("Arvaa luku 0 - 100 väliltä.")
            //text: peli.m_rngNro
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            transformOrigin: Item.Center
            Layout.fillWidth: false
            Layout.fillHeight: false
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            clip: false
        }

        Text {
            id: text2
            text: qsTr("10 arvausta jäljellä.")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        TextField {
            id: textField
            color: "#000000"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: false
            hoverEnabled: true
            placeholderText: qsTr("Arvaus")
            font.pointSize: 22
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Button {
            id: button
            width: 117
            text: qsTr("Tarkista")
            font.pointSize: 22
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                peli.rngNro()
                textField.text = peli.m_rngNro
            }
        }
        flow: GridLayout.TopToBottom
        Layout.fillHeight: false
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        columns: 1
    }

    GridLayout {
        id: gridLayout2
        visible: visible
        anchors.fill: parent
        anchors.bottomMargin: 250
        anchors.topMargin: 250
        rows: 2
        columns: 1


        Text {
            id: text3
            opacity: 1
            visible: true
            text: qsTr("Numeron arvauspeli")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.bottomMargin: 0
            Layout.topMargin: 0
            font.bold: false
            Layout.fillWidth: true
            Layout.fillHeight: false
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            clip: false
        }

        Button {
            id: button1
            width: 117
            text: qsTr("Aloita")
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 22

            onClicked: {
                gridLayout1.visible = true
                gridLayout2.visible = false

                peli.rngNro
                console.log("Nro on: " + peli.m_rngNro)
            }
        }
    }
}



/*##^##
Designer {
    D{i:0}D{i:1}D{i:7}D{i:8}D{i:6;invisible:true}
}
##^##*/
