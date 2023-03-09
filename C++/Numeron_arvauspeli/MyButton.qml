import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15


Button {
    id: button
    width: 117
    height: 47
    spacing: 6
    focusPolicy: Qt.StrongFocus
    hoverEnabled: true
    enabled: true
    flat: false
    Layout.columnSpan: 1
    Layout.fillHeight: false
    topPadding: 6
    bottomPadding: 6
    font.capitalization: Font.MixedCase
    Layout.fillWidth: false
    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
    font.pointSize: 22
    highlighted: false
    //Material.accent: Material.DeepOrange
    //Material.background: Material.DeepOrange

    Material.elevation: {
        mouseArea.containsMouse ? 3 : 1
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {
            button.clicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;height:50;width:120}
}
##^##*/
