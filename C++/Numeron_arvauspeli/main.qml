import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15

Window {
    id: window
    // Puhelimen resoluutio
    //width: 360
    //height: 800
    width: 480
    height: 640
    visible: true
    title: qsTr("Numeron arvauspeli")

    CustomBackground {
        id: customBackground
        anchors.fill: parent
    }

    GridLayout {
        id: startWindow
        visible: true
        anchors.fill: parent
        columns: 3
        rows: 4

        Item {
            id: spacer1
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }

        Text {
            id: arvausPeli
            opacity: 1
            visible: true
            text: qsTr("Numeron arvauspeli")
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "MS Shell Dlg 2"
            Layout.maximumWidth: 200
            Layout.columnSpan: 3
            font.bold: false
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            transformOrigin: Item.Center
            clip: false
            Layout.rowSpan: 1
            Layout.fillWidth: true
            Layout.maximumHeight: 30
            Layout.bottomMargin: 0
        }

        MyButton {
            id: startGame
            width: 117
            height: 47
            visible: true
            text: qsTr("Aloita")
            Layout.maximumWidth: 120
            Layout.preferredHeight: -1
            onClicked: {
                mainWindow.visible = true
                startWindow.visible = false
                peli.startClicked()
                console.log("Nro on: " + peli.rngNro)
            }
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.maximumHeight: 50
            Layout.preferredWidth: -1
            Layout.minimumHeight: 40
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.minimumWidth: 100
        }

        Item {
            id: spacer2
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }
    }

    GridLayout {
        id: mainWindow
        visible: false
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        Layout.fillWidth: false
        flow: GridLayout.TopToBottom
        Layout.fillHeight: false
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        rows: 7
        columns: 1

        Item {
            id: spacer3
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }

        Text {
            id: guide
            visible: true
            text: peli.guide
            font.capitalization: Font.MixedCase
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.minimumWidth: 0
            Layout.minimumHeight: 5
            Layout.preferredHeight: -1
            Layout.preferredWidth: -1
            clip: false
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: guessesLeft
            visible: true
            text: "Arvauksia jäljellä: " + peli.counter
            font.capitalization: Font.MixedCase
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            Layout.minimumWidth: 0
            Layout.minimumHeight: 25
            clip: false
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
            font.family: "MS Shell Dlg 2"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Item {
            id: spacer4
            height: 86
            opacity: 0
            visible: true
            clip: false
            Layout.preferredWidth: -1
            Layout.preferredHeight: 10
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }

        TextField {
            id: display
            visible: true
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 22
            Layout.minimumHeight: 52
            placeholderTextColor: "#7f353637"
            hoverEnabled: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumHeight: 52
            Layout.maximumWidth: 117
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Arvaus")
            text: ""
        }

        MyButton {
            id: guess
            visible: true
            text: qsTr("Tarkista")
            Layout.topMargin: -10
            highlighted: false
            padding: 6
            leftPadding: 6
            rightPadding: 6
            bottomPadding: 6
            topPadding: 6
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 47
            Layout.maximumHeight: 47
            Layout.maximumWidth: 117
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            onClicked: {
                peli.display = display.text;
                peli.guessClicked();
                if (peli.rngNro === peli.display) {
                    mainWindow.visible = false
                    winWindow.visible = true
                }
                if (peli.counter === 0) {
                    mainWindow.visible = false
                    loseWindow.visible = true
                }
            }
        }


        Item {
            id: spacer5
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }
    }

    GridLayout {
        id: winWindow
        visible: false
        anchors.fill: parent
        columns: 3
        rows: 4
        Item {
            id: spacer6
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }

        Text {
            id: voititPelin
            opacity: 1
            visible: true
            text: qsTr("Voitit pelin!")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.minimumHeight: 25
            Layout.maximumHeight: 35
            Layout.maximumWidth: 147
            font.pointSize: 22
            Layout.columnSpan: 3
            font.family: "MS Shell Dlg 2"
            Layout.topMargin: 0
            font.capitalization: Font.MixedCase
            Layout.fillWidth: true
            clip: false
            font.bold: false
            Layout.bottomMargin: 0
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        MyButton {
            id: playAgain
            text: qsTr("Pelaa uudestaan")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.minimumWidth: 0
            Layout.minimumHeight: 47
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumHeight: 47
            Layout.maximumWidth: 225
            Layout.columnSpan: 3
            onClicked: {
                mainWindow.visible = true
                winWindow.visible = false
                peli.startClicked()
                display.text = ""
                console.log("Nro on: " + peli.rngNro)
            }
        }

        Item {
            id: spacer7
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }
    }

    GridLayout {
        id: loseWindow
        visible: false
        anchors.fill: parent
        columns: 3
        rows: 4
        Item {
            id: spacer8
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }

        Text {
            id: havisitPelin
            opacity: 1
            visible: true
            text: qsTr("Hävisit pelin.")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            Layout.minimumHeight: 25
            Layout.maximumHeight: 35
            Layout.maximumWidth: 165
            font.pointSize: 22
            Layout.columnSpan: 3
            font.family: "MS Shell Dlg 2"
            Layout.topMargin: 0
            font.capitalization: Font.MixedCase
            Layout.fillWidth: true
            clip: false
            font.bold: false
            Layout.bottomMargin: 0
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        MyButton {
            id: tryAgain
            text: qsTr("Yritä uudestaan")
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 47
            Layout.maximumHeight: 47
            Layout.maximumWidth: 216
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.columnSpan: 3
            onClicked: {
                mainWindow.visible = true
                loseWindow.visible = false
                peli.startClicked()
                display.text = ""
                console.log("Nro on: " + peli.rngNro)
            }
        }

        Item {
            id: spacer9
            height: 86
            Layout.preferredWidth: 14
            Layout.preferredHeight: 150
            Layout.minimumHeight: 0
            Layout.fillHeight: true
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            Layout.fillWidth: true
        }
    }
}
