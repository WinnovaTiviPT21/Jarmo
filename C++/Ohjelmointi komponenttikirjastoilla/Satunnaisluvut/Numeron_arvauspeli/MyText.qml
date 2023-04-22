import QtQuick 2.15
import QtQuick.Layouts 1.11

Text {
    id: myText
    opacity: 1
    visible: true
    font.bold: false
    font.pixelSize: 22
    font.family: "MS Shell Dlg 2"
    font.capitalization: Font.MixedCase
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    transformOrigin: Item.Center
    clip: false

    color: {
        if (control.checked == true)
        {
            MyText.color = "#ffffff"
        }
        else
        {
            MyText.color = "#000000"

        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
