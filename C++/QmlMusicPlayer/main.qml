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

    //    Slider {
    //        id: slider
    //        x: 140
    //        y: 315
    //        from: fromValue
    //        to: toValue
    //        stepSize: 0.01
    //        Layout.minimumWidth: 200
    //        Layout.fillWidth: true
    //        background: Rectangle {
    //            x: slider.leftPadding
    //            y: slider.topPadding + slider.availableHeight / 2 - height / 2
    //            implicitWidth: 200
    //            implicitHeight: 2
    //            width: slider.availableWidth
    //            height: implicitHeight
    //            color: "#606060"
    //            Rectangle {
    //                width: slider.visualPosition * parent.width
    //                height: parent.height
    //                color: "#41cd52"
    //            }
    //        }
    //        handle: Rectangle {
    //            x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
    //            y: slider.topPadding + slider.availableHeight / 2 - height / 2
    //            implicitWidth: 14
    //            implicitHeight: 14
    //            radius: width/2
    //            color: slider.pressed ? "#ffffff" : "#d0d0d0"
    //            border.color: "#d0d0d0"
    //        }
    //    }

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


//        MenuBar {
//            id: menuBar
//            anchors.left: parent.left
//            anchors.right: parent.right

//            Menu {
//                title: qsTr("&File")
//                Action {
//                    text: qsTr("&Open")
//                    onTriggered: fileDialog.open()
//                }
//                Action {
//                    text: qsTr("&Url")
//                }
//            }
//        }


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
            text: mediaplayer.duration
            activeFocusOnPress: false
        }


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

        RoundButton {
            id: open
            text: "open"
            checked: false
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.rowSpan: 1
            Layout.columnSpan: 1
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
        }

        Item {
            id: item1
            width: 200
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.columnSpan: 2
            Layout.preferredWidth: -1
            Layout.fillHeight: false
            Layout.fillWidth: true
        }

        RoundButton {
            id: previous
            text: "<<"
            Layout.columnSpan: 1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        RoundButton {
            id: pause
            text: "Pause"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
            onClicked:  mediaplayer.pauseClicked()
        }

        RoundButton {
            id: play
            text: "Play"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
            onClicked: mediaplayer.playClicked()
        }


        RoundButton {
            id: stop
            text: "Stop"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
            onClicked: mediaplayer.stopClicked()
        }


//        State {
//            name: "playing"
//            when: mediaPlayerState == MediaPlayer.PlayingState
//            PropertyChanges { target: pause; visible: true}
//            PropertyChanges { target: play; visible: false}
//            PropertyChanges { target: stop; visible: true}
//        }
//        State {
//            name: "stopped"
//            when: mediaPlayerState == MediaPlayer.StoppedState
//            PropertyChanges { target: pause; visible: false}
//            PropertyChanges { target: play; visible: true}
//            PropertyChanges { target: stop; visible: false}
//        }
//        State {
//            name: "paused"
//            when: mediaPlayerState == MediaPlayer.PausedState
//            PropertyChanges { target: pause; visible: false}
//            PropertyChanges { target: play; visible: true}
//            PropertyChanges { target: stop; visible: true}
//        }


        RoundButton {
            id: next
            text: ">>"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        Item {
            id: item2
            width: 200
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.columnSpan: 1
            Layout.fillWidth: true
        }

        //äänenvoimakkuus
        Slider {
            id: slider
            width: 200
            height: 66

            visible: true
            Layout.bottomMargin: 10
            stepSize: 2
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
            value: mediaplayer.volume
            wheelEnabled: true

            Connections {
                target: slider
                onMoved: {
                    mediaplayer.volume = slider.value;
                    console.log(slider.value);
                }
            }
        }

        Item {
            id: item4
            width: 200
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: true
            Layout.columnSpan: 1
        }

        Item {
            id: item5
            width: 200
            height: 6
            Layout.fillWidth: true
        }

        ProgressBar {
            id: progressBar
            width: 600
            Layout.topMargin: 5
            topPadding: 0
            Layout.rowSpan: 1
            Layout.rightMargin: 0
            Layout.leftMargin: 0
            Layout.margins: 0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.columnSpan: 8
            //value: mediaplayer.duration
        }

        Item {
            id: item6
            width: 200
            height: 6
            Layout.fillHeight: false
            Layout.fillWidth: true
        }
    }

//    Label {
//        id: label
//        x: 20
//        y: 125
//        width: 234
//        height: 137
//        text: mediaplayer.duration
//    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}
}
##^##*/
