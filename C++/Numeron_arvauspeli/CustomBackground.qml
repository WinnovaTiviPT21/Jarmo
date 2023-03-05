import QtQuick 2.15
import QtQuick.Layouts 1.11

    Rectangle {
        width: 480
        height: 640
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
        clip: true
    }


/*##^##
Designer {
    D{i:0;height:640;width:480}
}
##^##*/
