import QtQuick 2.5
import QtQuick.Controls 2.3

Button {
    id: btn
    property int buttonRadius: 15

    background: Rectangle {
        color: "#0055ff"
        radius: buttonRadius
    }
}
