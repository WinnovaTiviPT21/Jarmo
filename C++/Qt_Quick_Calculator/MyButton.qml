import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Button {
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
}
