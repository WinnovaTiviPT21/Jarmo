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
    //width: 360
    //height: 800
    width: 480
    height: 640
    visible: true
    title: qsTr("Numeron arvauspeli")

    GridLayout {
        id: gridLayout1
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
            id: start
            width: 117
            text: qsTr("Aloita")
            font.capitalization: Font.MixedCase
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 22

            onClicked: {
                gridLayout2.visible = true
                gridLayout1.visible = false
                peli.startClicked()
                console.log("Nro on: " + peli.rngNro)
            }
        }
    }

    GridLayout {
        id: gridLayout2
        visible: false
        anchors.fill: parent
        Layout.fillWidth: false
        flow: GridLayout.TopToBottom
        Layout.fillHeight: false
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        rows: 4
        columns: 1

        Text {
            id: text1
            opacity: 1
            visible: true
            text: qsTr("Arvaa luku 0 - 100 väliltä.")
            font.capitalization: Font.MixedCase
            //text: peli.rngNro
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
            id: guessesLeft
            text: qsTr("10 arvausta jäljellä.")
            font.capitalization: Font.MixedCase
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.fillWidth: false
            Layout.fillHeight: false
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        TextField {
            id: display
            color: "#000000"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: false
            hoverEnabled: true
            placeholderText: qsTr("Arvaus")
            //text: peli.display
            font.pointSize: 22
            Layout.fillHeight: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            //background: Rectangle {
            //implicitWidth: 200
            //implicitHeight: 40
            //color: textField.enabled ? "transparent" : "#353637"
            //border.color: textField.enabled ? "#000000" : "transparent"
            //radius: 15
            //}
        }

        Button {
            id: guess
            width: 117
            text: qsTr("Tarkista")
            font.capitalization: Font.MixedCase
            font.pointSize: 22
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                peli.display = display.text;
                peli.guessClicked();
                console.log("Nro on: " + peli.display);
                if (peli.rngNro === peli.display) {
                    gridLayout2.visible = false
                    gridLayout3.visible = true
                }
            }
        }
    }

    GridLayout {
        id: gridLayout3
        visible: false
        anchors.fill: parent
        Text {
            id: text4
            opacity: 1
            visible: true
            text: qsTr("Voitit pelin!")
            font.capitalization: Font.MixedCase
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.family: "MS Shell Dlg 2"
            Layout.topMargin: 0
            Layout.bottomMargin: 0
            font.bold: false
            Layout.fillWidth: true
            Layout.fillHeight: false
            clip: false
        }

        Button {
            id: again
            width: 117
            text: qsTr("Pelaa uudestaan")
            font.capitalization: Font.MixedCase
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            font.pointSize: 22
            Layout.fillWidth: false
            onClicked: {
                    gridLayout2.visible = true
                    gridLayout3.visible = false
                    peli.startClicked()
                    console.log("Nro on: " + peli.rngNro)
                }
        }
        anchors.topMargin: 250
        anchors.bottomMargin: 250
        columns: 1
        rows: 2
    }
}



/*##^##
Designer {
    D{i:0}D{i:9}D{i:0;invisible:true}
}
##^##*/
