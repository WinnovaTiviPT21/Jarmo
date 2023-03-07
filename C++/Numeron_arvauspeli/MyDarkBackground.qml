import QtQuick 2.15
import QtQuick.Layouts 1.11

Rectangle {
    id: myDarkBackground
    width: 480
    height: 640
    clip: true

    visible: {
        if (control.checked === true)
        {
            MyDarkBackground.visible = true
        }
        else
        {
            MyDarkBackground.visible = false
        }
    }

    // Premium Dark
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#434343"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
        orientation: Gradient.Vertical
    }
}
