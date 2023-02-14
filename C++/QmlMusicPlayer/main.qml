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
        columnSpacing: 5
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        columns: 9
        rows: 4

        TextField {
            id: textField
            height: 40
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 0
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.minimumHeight: 100
            Layout.columnSpan: 9
            Layout.rowSpan: 1
            placeholderText: qsTr("Hello World")
            text: mediaplayer.media
        }


        Item {
            id: item3
            width: 200
            height: 200
            transformOrigin: Item.Center
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 9
        }

        Item {
            id: item1
            width: 200
            height: 200
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.rowSpan: 1
            Layout.columnSpan: 2
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        RoundButton {
            id: roundButton5
            text: "<<"
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

        RoundButton {
            id: roundButton9
            text: ">>"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
            Layout.fillWidth: false
            Layout.fillHeight: false
        }

        Slider {
            id: slider
            width: 200
            height: 66
            bottomPadding: 5
            padding: 0
            Layout.leftMargin: 0
            Layout.rightMargin: 0
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.columnSpan: 2
            smooth: false
            antialiasing: false
            to: 100
            Layout.fillWidth: true
            value: mediaplayer.volume

            Connections {
                target: slider
                onMoved: {
                    mediaplayer.volume = slider.value;
                    console.log(slider.value);
                }
            }
        }

        ProgressBar {
            id: progressBar
            Layout.topMargin: 10
            topPadding: 0
            Layout.rowSpan: 1
            Layout.rightMargin: 0
            Layout.leftMargin: 0
            Layout.margins: 0
            Layout.alignment: Qt.AlignRight | Qt.AlignBottom
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.columnSpan: 9
            //value: mediaplayer.duration
        }
    }

    Label {
        id: label
        x: 60
        y: 157
        width: 234
        height: 137
        text: mediaplayer.duration
    }
}
