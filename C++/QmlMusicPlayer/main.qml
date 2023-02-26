import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs 1.3


ApplicationWindow {
    id: window
    width: 480
    height: 640
    // Puhelimen resoluutio
    //width: 360
    //height: 800
    visible: true
    modality: Qt.ApplicationModal
    title: qsTr("Paska soitin")
    Material.theme: control.position < 1 ? Material.Light : Material.Dark // Teema


    // Avaa tiedoston valintaikkunan
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: ["MP3 files (*.mp3)"]
        folder: shortcuts.music

        onAccepted: {                                        // Kun käyttäjä avaa tiedoston
            console.log("You chose: " + fileDialog.fileUrls) // Kirjoittaa konsoliin valitun tiedoston polun
            console.log("Current media: " + mediaplayer.display)
            mediaplayer.stopClicked()                        // Pysäyttää edeltävän kappaleen toiston
            mediaplayer.playClicked(fileDialog.fileUrls[0])  // Lähetetään valitun tiedoston URL-osoiteen C++:lle
            // Muuttaa nappien näkyvyyden                    // ja aloittaa kappaleen soittamisen
            play.visible = false
            stop.visible = true
            pause.visible = true
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false // Jos true fileDialogi aukeaa jo käynnistyksessä
    }


    // Sivupaneeli
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

        // Teeman valintanappula
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
        columnSpacing: 6
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        columns: 11
        rows: 4


        // Menupalkki
        MenuBar {
            id: menuBar
            anchors.left: parent.left
            anchors.right: parent.right
            Layout.topMargin: -20
            Layout.leftMargin: 0
            anchors.rightMargin: -20
            anchors.leftMargin: -20
            Layout.columnSpan: 11
            leftPadding: 0
            Layout.fillWidth: true

            Menu {
                title: qsTr("File")
                Action {
                    text: qsTr("&Open")
                    onTriggered: fileDialog.open() // Avaa fileDialogin
                }
                Action {
                    text: qsTr("&Url")
                }
                Action {
                    text: qsTr("&Quit")
                    onTriggered: Qt.quit() // Sulkee soittimen
                }
            }
        }


        // Näyttö
        TextField {
            id: display
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 0
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.minimumHeight: 100
            Layout.columnSpan: 11
            Layout.rowSpan: 1
            placeholderText: qsTr("Hello World")
            text: mediaplayer.display
            activeFocusOnPress: false
        }


        // Fillereitä
        Item {
            id: item3
            width: 200
            height: 200
            Layout.rowSpan: 3
            transformOrigin: Item.Center
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 11
        }
        Item {
            id: item7
            width: 200
            height: 200
            Layout.rowSpan: 1
            Layout.columnSpan: 11
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
        Item {
            id: item8
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 11
        }
        Item {
            id: item9
            width: 200
            height: 200
            Layout.rowSpan: 1
            Layout.fillWidth: true
            Layout.columnSpan: 11
            Layout.fillHeight: true
        }
        Item {
            id: item4
            width: 200
            height: 40
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.columnSpan: 1
            Layout.preferredWidth: -1
        }
        Item {
            id: item1
            width: 200
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.columnSpan: 3
            Layout.preferredWidth: -1
            Layout.fillHeight: false
            Layout.fillWidth: true
        }


        // Pause
        Button {
            id: pause
            //text: "Pause"
            visible: false
            Layout.rightMargin: -5
            rightPadding: 0
            leftPadding: 0
            scale: 0.7
            Layout.leftMargin: 0
            transformOrigin: Item.BottomRight
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

            background: Image {
                anchors.fill: parent
                source: {
                    if (control.checked == true){
                        source: "images/darkPause_1.png"
                        //source: "images/darkPause_2.png"
                        //source: "images/darkPause_3.png"
                    }
                    else {
                        source: "images/lightPause.png"
                    }
                }
            }
            onClicked: {
                mediaplayer.pauseClicked()
                play.transformOrigin = Item.BottomRight
                play.Layout.rightMargin = -5
                play.visible = true
                stop.visible = true
                pause.visible = false
            }
        }


        // Play
        Button {
            id: play
            //text: "Play"
            visible: true
            Layout.rightMargin: 0
            rightPadding: 0
            leftPadding: 0
            scale: 0.7
            Layout.leftMargin: 0
            transformOrigin: Item.Bottom
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

            background: Image {
                anchors.fill: parent
                source: {
                    if (control.checked == true){
                        source: "images/darkPlay_1.png"
                        //source: "images/darkPlay_2.png"
                        //source: "images/darkPlay_3.png"
                    }
                    else {
                        source: "images/lightPlay.png"
                    }
                }
            }
            onClicked: {
                mediaplayer.playClicked(fileDialog.fileUrl)
                play.Layout.rightMargin = 0
                play.visible = false
                stop.visible = true
                pause.visible = true
            }
        }

        // Stop
        Button {
            id: stop
            //text: "Stop"
            visible: false
            rightPadding: 0
            leftPadding: 0
            Layout.rightMargin: 0
            Layout.leftMargin: 0
            scale: 0.7
            Layout.fillWidth: false
            transformOrigin: Item.Bottom
            bottomPadding: 6
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

            background: Image {
                anchors.fill: parent
                source: {
                    if (control.checked == true){
                        source: "images/darkStop_1.png"
                        //source: "images/darkStop_2.png"
                        //source: "images/darkStop_3.png"
                    }
                    else {
                        source: "images/lightStop.png"
                    }
                }
            }
            onClicked: {
                mediaplayer.stopClicked()
                play.transformOrigin = Item.Bottom
                play.visible = true
                stop.visible = false
                pause.visible = false
            }
        }


        // Filler
        Item {
            id: item2
            width: 200
            height: 40
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.columnSpan: 3
            Layout.preferredWidth: -1
        }

        //äänenvoimakkuus
        Slider {
            id: slider
            width: 200
            height: 66
            visible: true
            focus: false
            value: 50
            Layout.bottomMargin: 10
            stepSize: 1
            Layout.topMargin: 20
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
            orientation: Qt.Vertical
            Layout.rowSpan: 1
            Layout.fillHeight: true
            rotation: 0
            live: true
            Layout.preferredWidth: -1
            bottomPadding: 5
            padding: 0
            Layout.leftMargin: 0
            Layout.rightMargin: 0
            Layout.columnSpan: 1
            smooth: false
            antialiasing: false
            to: 100
            Layout.fillWidth: false
            wheelEnabled: true

            Connections {
                target: slider
                onMoved: {
                    mediaplayer.volume = slider.value;
                    console.log(slider.value);
                }
            }
        }

        Slider /*ProgressBar*/ {
            id: progressBar
            width: 700
            rightPadding: 20
            leftPadding: 0
            from: 0
            to: 100
            Layout.topMargin: 5
            topPadding: 0
            Layout.rowSpan: 1
            Layout.rightMargin: 60
            Layout.leftMargin: 60
            Layout.margins: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.columnSpan: 11
            value: mediaplayer.position
        }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
