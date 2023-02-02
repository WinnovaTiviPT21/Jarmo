import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import Calculator.Enums 1.0
import QtQuick.Controls.Material 2.15

ApplicationWindow {
    id: window
    width: 480
    height: 640
    visible: true
    contentOrientation: Qt.PortraitOrientation //LandscapeOrientation
    flags: Qt.Window
    modality: Qt.ApplicationModal
    title: qsTr("Hello World")
    Material.theme: control.position < 1 ? Material.Light : Material.Dark

    Drawer {
        id: drawer
        width: 0.50 * window.width
        height: window.height

        Label {
            id: content

            text: "Copyright © 2023 by Jarmo Vuorinen\n" //All rights reserved.\n
            font.pixelSize: 12
            anchors.fill: parent
            verticalAlignment: Label.AlignBottom //AlignVCenter
            horizontalAlignment: Label.AlignHCenter

//            transform: Translate {
//            x: drawer.position * content.width * 0.33
//            }
        }

        SwitchDelegate {
            id: control;
            text: qsTr("Dark Theme")
            checked: false

//            anchors.right: parent.anchors.right

            contentItem: Text {
                rightPadding: control.indicator.width + control.spacing
                text: control.text
                font: control.font
                opacity: enabled ? 1.0 : 0.3
                color: control.down ? "#17a81a" : "#21be2b"
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: SwitchDelegate.left
            }

            indicator: Rectangle {
                implicitWidth: 48
                implicitHeight: 26
                x: control.width - width - control.rightPadding
                y: parent.height / 2 - height / 2
                radius: 13
                color: control.checked ? "#17a81a" : "transparent"
                border.color: control.checked ? "#17a81a" : "#cccccc"

                Rectangle {
                    x: control.checked ? parent.width - width : 0
                    width: 26
                    height: 26
                    radius: 13
                    color: control.down ? "#cccccc" : "#ffffff"
                    border.color: control.checked ? (control.down ? "#17a81a" : "#21be2b") : "#999999"
                }
            }

            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                visible: control.down || control.highlighted
                color: control.down ? "#bdbebf" : "#eeeeee"
            }
        }
    }

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
            text: calculator.display
        }

        MyButton {
            id: backspace
            text: qsTr("Backspace")
            Layout.columnSpan: 2
            onClicked: calculator.backspaceClicked()
        }

        MyButton {
            id: clear
            text: qsTr("Clear")
            Layout.columnSpan: 2
            onClicked: calculator.clear()
        }

        MyButton {
            id: clear_all
            text: qsTr("Clear All")
            Layout.columnSpan: 2
            onClicked: calculator.clearAll()
        }

        MyButton {
            id: mc
            text: qsTr("MC")
            onClicked: calculator.clearMemory()
        }

        MyButton {
            id: num7
            text: qsTr("7")
            onClicked: calculator.digitClicked("7")
        }

        MyButton {
            id: num8
            text: qsTr("8")
            onClicked: calculator.digitClicked("8")
        }

        MyButton {
            id: num9
            text: qsTr("9")
            onClicked: calculator.digitClicked("9")
        }

        MyButton {
            id: jako
            text: qsTr("÷")
            onClicked: calculator.multiplicativeOperatorClicked(Calculator.Division)
        }

        MyButton {
            id: neliojuuri
            text: qsTr("Sqrt")
            onClicked: calculator.unaryOperatorClicked(Calculator.SquareRoot)
        }

        MyButton {
            id: mr
            text: qsTr("MR")
            onClicked: calculator.readMemory()
        }

        MyButton {
            id: num4
            text: qsTr("4")
            onClicked: calculator.digitClicked("4")
        }

        MyButton {
            id: num5
            text: qsTr("5")
            onClicked: calculator.digitClicked("5")
        }

        MyButton {
            id: num6
            text: qsTr("6")
            onClicked: calculator.digitClicked("6")
        }

        MyButton {
            id: kerto
            text: qsTr("×")
            onClicked: calculator.multiplicativeOperatorClicked(Calculator.Multiplication)
        }

        MyButton {
            id: potensi
            text: qsTr("x²")
            onClicked: calculator.unaryOperatorClicked(Calculator.Square)
        }

        MyButton {
            id: ms
            text: qsTr("MS")
            onClicked: calculator.setMemory()
        }

        MyButton {
            id: num1
            text: qsTr("1")
            onClicked: calculator.digitClicked("1")
        }

        MyButton {
            id: num2
            text: qsTr("2")
            onClicked: calculator.digitClicked("2")
        }

        MyButton {
            id: num3
            text: qsTr("3")
            onClicked: calculator.digitClicked("3")
        }

        MyButton {
            id: miinus
            text: qsTr("-")
            onClicked: calculator.additiveOperatorClicked(Calculator.Subtraction)
        }

        MyButton {
            id: yksiKauttaX
            text: qsTr("1/x")
            onClicked: calculator.unaryOperatorClicked(Calculator.Inverse)
        }

        MyButton {
            id: m_plus
            text: qsTr("M+")
            onClicked: calculator.addToMemory()
        }

        MyButton {
            id: num0
            text: qsTr("0")
            onClicked: calculator.digitClicked("0")
        }

        MyButton {
            id: pilkku
            text: qsTr(",")
            onClicked: calculator.pointClicked()
        }

        MyButton {
            id: plusMiinus
            text: qsTr("+/-")
            onClicked: calculator.changeSignClicked()
        }

        MyButton {
            id: plus
            text: qsTr("+")
            onClicked: calculator.additiveOperatorClicked(Calculator.Addition)
        }

        MyButton {
            id: onyhtakuin
            text: qsTr("=")
            onClicked: calculator.equalClicked()
        }


    }
}
