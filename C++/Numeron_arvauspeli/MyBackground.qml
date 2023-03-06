import QtQuick 2.15
import QtQuick.Layouts 1.11

    Rectangle {
        id: myBackground
        width: 480
        height: 640
        clip: true
        //visible: true

        visible: {
            if (control.checked == true)
            {
                MyBackground.visible = false
            }
            else
            {
                MyBackground.visible = true
            }
        }

        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#dfe9f3"
            }

            GradientStop {
                position: 1
                color: "#ffffff"
            }
            orientation: Gradient.Vertical
        }
    }


/*##^##
Designer {
    D{i:0;height:640;width:480}
}
##^##*/
