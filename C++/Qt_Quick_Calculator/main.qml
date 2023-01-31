import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Window {
    id: window
    width: 640
    height: 480
    visible: true
    contentOrientation: Qt.LandscapeOrientation
    flags: Qt.Window
    modality: Qt.ApplicationModal
    property alias windowWidth: window.width
    title: qsTr("Hello World")

    GridLayout {
        id: gridLayout
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        rowSpacing: 0
        columnSpacing: 0
        rows: 6
        columns: 6

        TextField {
            id: textField
            font.pointSize: 18
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 0
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.topMargin: 5
            Layout.columnSpan: 6
            Layout.rowSpan: 1
            Layout.fillHeight: true
            Layout.fillWidth: true
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: backspace
            visible: true
            text: qsTr("Backspace")
            highlighted: false
            font.bold: false
            font.pointSize: 12
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.margins: 6
            Layout.fillWidth: true
            clip: false
            transformOrigin: Item.Center
        }

        Button {
            id: clear
            visible: true
            text: qsTr("Clear")
            flat: false
            highlighted: false
            font.bold: false
            font.pointSize: 12
            Layout.columnSpan: 2
            transformOrigin: Item.Center
            Layout.margins: 6
            clip: false
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.rowSpan: 1
            Layout.fillHeight: true
        }

        Button {
            id: clear_all
            visible: true
            text: qsTr("Clear All")
            flat: false
            highlighted: false
            font.bold: false
            font.pointSize: 12
            Layout.columnSpan: 2
            transformOrigin: Item.Center
            Layout.margins: 6
            clip: false
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.rowSpan: 1
            Layout.fillHeight: true
        }

        Button {
            id: mc
            visible: true
            text: qsTr("MC")
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
        }

        Button {
            id: num7
            visible: true
            text: qsTr("7")
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
        }

        Button {
            id: num8
            visible: true
            text: qsTr("8")
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
        }

        Button {
            id: num9
            visible: true
            text: qsTr("9")
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
        }

        Button {
            id: jako
            visible: true
            text: qsTr("÷")
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
        }

        Button {
            id: neliojuuri
            visible: true
            text: qsTr("Sqrt")
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
        }

        Button {
            id: mr
            visible: true
            text: qsTr("MR")
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
        }

        Button {
            id: num4
            visible: true
            text: qsTr("4")
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
        }

        Button {
            id: num5
            visible: true
            text: qsTr("5")
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
        }

        Button {
            id: num6
            visible: true
            text: qsTr("6")
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
        }

        Button {
            id: kerto
            visible: true
            text: qsTr("×")
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
        }

        Button {
            id: potensi
            visible: true
            text: qsTr("x²")
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
        }

        Button {
            id: ms
            visible: true
            text: qsTr("MS")
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
        }

        Button {
            id: num1
            visible: true
            text: qsTr("1")
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
        }

        Button {
            id: num2
            visible: true
            text: qsTr("2")
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
        }

        Button {
            id: num3
            visible: true
            text: qsTr("3")
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
        }

        Button {
            id: miinus
            visible: true
            text: qsTr("-")
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
        }

        Button {
            id: yksiKauttaX
            visible: true
            text: qsTr("1/x")
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
        }

        Button {
            id: m_plus
            visible: true
            text: qsTr("M+")
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
        }

        Button {
            id: num0
            visible: true
            text: qsTr("0")
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
        }

        Button {
            id: pilkku
            visible: true
            text: qsTr(",")
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
        }

        Button {
            id: plusMiinus
            visible: true
            text: qsTr("+/-")
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
        }

        Button {
            id: plus
            visible: true
            text: qsTr("+")
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
        }

        Button {
            id: onyhtakuin
            visible: true
            text: qsTr("=")
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
        }


    }
}
