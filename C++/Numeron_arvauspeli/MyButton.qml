import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15

Button {
    id: button
    width: 117
    height: 47
    highlighted: false
    flat: false
    Layout.columnSpan: 1
    Layout.fillHeight: false
    topPadding: 6
    bottomPadding: 6
    font.capitalization: Font.MixedCase
    Layout.fillWidth: false
    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    font.pointSize: 22    
}
