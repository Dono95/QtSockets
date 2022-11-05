import QtQuick 2.5
import QtQuick.Controls 2.3

Rectangle {

    TextField {
        id: iTextField
        anchors.fill: parent
        anchors.margins: 5
        anchors.rightMargin: parent.width * 1/9 + 5
        background: Rectangle {
            radius: 15
        }
        font.pixelSize: 20
    }

    SendButton {
        id: iSendButton
        anchors.fill: parent
        anchors.leftMargin: parent.width * 8/9
        anchors.margins: 5
        buttonRadius: 40

        onClicked: {
            ClientUI.addMessage(2, iTextField.text);
            iTextField.clear();
        }
    }
}
