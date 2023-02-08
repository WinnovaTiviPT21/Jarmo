import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Button {
    id: button
    visible: true
    highlighted: false
    font.bold: false
    font.pointSize: 12
    Layout.columnSpan: 1
    transformOrigin: Item.Center
    Layout.margins: 6
    clip: false
    Layout.fillWidth: true
    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    Layout.rowSpan: 1
    Layout.fillHeight: true

    MouseArea {
        id: myMouse
        anchors.fill: button
        onClicked: {
            anim.running = true
        }
    }
    SequentialAnimation{
        id: anim
        NumberAnimation {
            target: button
            properties: "scale"
            from: 1.0
            to: 1.2
            duration: 200
        }
        NumberAnimation {
            target: button
            properties: "scale"
            from: 1.2
            to: 1.0
            duration: 200
        }
    }
}
