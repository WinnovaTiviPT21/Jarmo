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
    contentOrientation: Qt.PortraitOrientation
    flags: Qt.Window
    modality: Qt.ApplicationModal
    title: qsTr("Paska laskin")
    Material.theme: control.position < 1 ? Material.Light : Material.Dark

    Drawer {
        id: drawer
        width: 0.50 * window.width
        height: window.height

        Label {
            id: content
            text: "Copyright © 2023 by Jarmo Vuorinen" // \xa9 All rights reserved.\n
            font.pixelSize: 12
            anchors.margins: 12
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            // transform: Translate {
            // x: drawer.position * content.width * 0.33
            // }
        }

        Switch {
            id: control
            anchors.right: parent.right
            anchors.top: parent.top
            // anchors.margins: 10
            text: "Dark theme"
            checked: false
        }
    }

//    Image{
//        anchors.fill: parent
//        source: "Tausta1.png"
//        clip: false
//    }
//    background: Image {
//        anchors.fill: parent
//        source: "Tausta1.png"
//        clip: true
//    }

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

        // Näyttö
        TextField {
            id: textField
            layer.enabled: false
            font.pointSize: 48
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 0
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.topMargin: 5
            Layout.columnSpan: 6
            Layout.rowSpan: 1
            //Layout.fillHeight: true
            //height: 100
            Layout.minimumHeight: 150
            Layout.fillWidth: true
            placeholderText: qsTr("Hello World")
            text: calculator.display
        }

        // Näppäimet
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


