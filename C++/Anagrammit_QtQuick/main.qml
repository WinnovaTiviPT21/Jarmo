import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TextField {
        id: textField
        x: 15
        y: 20
        width: 243
        height: 40
        placeholderText: qsTr("Text Field")
    }

    ScrollView {
        id: scrollView
        x: 15
        y: 66
        width: 243
        height: 398
    }

    ScrollView {
        id: scrollView1
        x: 272
        y: 297
        width: 352
        height: 167
    }

    Label {
        id: label
        x: 272
        y: 266
        width: 96
        height: 25
        text: qsTr("Anagrams")
        font.pointSize: 16
    }
}
