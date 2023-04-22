import QtQuick 2.15
import QtQuick.Layouts 1.11

Rectangle {
    id: myBackground
    width: 480
    height: 640
    clip: true

    visible: {
        if (control.checked === true)
        {
            MyBackground.visible = false
        }
        else
        {
            MyBackground.visible = true
        }
    }

    // New York
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#fff1eb"
        }

        GradientStop {
            position: 1
            color: "#98ddff"
        }
        orientation: Gradient.Vertical
    }
}


/*##^##
Designer {
    D{i:0;height:640;width:480}
}
##^##*/
