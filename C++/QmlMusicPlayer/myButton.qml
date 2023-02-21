import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Button {
    id: button
    highlighted: flase
    scale: 0.4
    Layout.columnSpan: 1
    transformOrigin: Item.Center
    Layout.margins: 6
    clip: false
    Layout.fillWidth: false
    Layout.fillHeight: false
    Layout.rowSpan: 1

//    background: Rectangle {
//                implicitWidth: 16
//                implicitHeight: 16
//                border.width: control.activeFocus ? 2 : 1
//                border.color: "#888"
//                radius: 0
//                gradient: Gradient {
//                    GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
//                    GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
//                }
//            }

//    // näppäimien animaatio
//    onClicked: {
//        anim.running = true
//    }
//    SequentialAnimation{
//        id: anim
//        NumberAnimation {
//            target: button
//            properties: "scale"
//            from: 1.0
//            to: 0.8
//            duration: 100
//        }
//        NumberAnimation {
//            target: button
//            properties: "scale"
//            from: 0.8
//            to: 1.0
//            duration: 100
//        }
//    }
}
