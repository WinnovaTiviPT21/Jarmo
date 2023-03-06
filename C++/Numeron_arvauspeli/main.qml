import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    id: window
    width: 480
    height: 640
    visible: true
    title: qsTr("Numeron arvauspeli")
    Material.theme: control.position < 1 ? Material.Light : Material.Dark

    MyBackground {
        //id: myBackground
        anchors.fill: parent
    }

    Drawer {
        id: drawer
        width: 0.50 * window.width
        height: window.height

        MyBackground {
            anchors.fill: parent
        }

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

        MyText {
            id: arvausPeli
            text: qsTr("Numeron arvauspeli")
            Layout.maximumWidth: 200
            Layout.columnSpan: 3
            Layout.fillHeight: true
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
            Layout.columnSpan: 3
            Layout.fillWidth: true
            Layout.maximumHeight: 50
            Layout.preferredWidth: -1
            Layout.minimumHeight: 40
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.minimumWidth: 100

            /*
            ** mietein olisiko koodin sieventämiseksi voinut käyttää (Connections {}) ydistämään uudet pelit tähän,
            ** nopealla yrityksellä näyttäisi onnistuvan, mutta vaatisi funtioiden uudelleen suunnittelemista.
            */
            onClicked: {
                mainWindow.visible = true
                startWindow.visible = false
                peli.startClicked()
                console.log("Arvottu nro on: " + peli.rngNro)
            }
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

        MyText {
            id: guide
            text: peli.guide
            Layout.minimumWidth: 0
            Layout.minimumHeight: 5
            Layout.preferredHeight: -1
            Layout.preferredWidth: -1
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        MyText {
            id: guessesLeft
            text: "Arvauksia jäljellä: " + peli.counter
            Layout.minimumWidth: 0
            Layout.minimumHeight: 25
            Layout.columnSpan: 1
            Layout.fillWidth: true
            Layout.fillHeight: true
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
//            placeholderTextColor: "#7f353637"
            hoverEnabled: true
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumHeight: 52
            Layout.maximumWidth: 117
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            placeholderText: qsTr("Arvaus")
            text: ""


            onPressed: {
                display.placeholderText = ""
                display.text = ""
            }
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

        MyText {
            id: voititPelin
            text: qsTr("Voitit pelin!")
            Layout.minimumHeight: 25
            Layout.maximumHeight: 35
            Layout.maximumWidth: 147
            Layout.columnSpan: 3
            Layout.topMargin: 0
            Layout.fillWidth: true
            Layout.bottomMargin: 0
            Layout.fillHeight: true
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
                display.placeholderText = qsTr("Arvaus")
                console.log("Arvottu nro on: " + peli.rngNro)
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

        MyText {
            id: havisitPelin
            text: qsTr("Hävisit pelin.")
            Layout.minimumHeight: 25
            Layout.maximumHeight: 35
            Layout.maximumWidth: 165
            Layout.columnSpan: 3
            Layout.topMargin: 0
            Layout.fillWidth: true
            Layout.bottomMargin: 0
            Layout.fillHeight: true
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
                display.placeholderText = qsTr("Arvaus")
                console.log("Arvottu nro on: " + peli.rngNro)
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
