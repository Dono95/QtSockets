import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: main

    visible: true
    width: 600
    height: 800
    title: qsTr("Messenger")
    color: "#272727"

    property int margin: 10

    Chat {
        anchors.fill: parent
        anchors.margins: main.margin
        anchors.bottomMargin: parent.height * 1/10 + anchors.margins
        color: "#585858"
        radius: 15
    }

    ChatBox {
        anchors.fill: parent
        anchors.margins: main.margin
        anchors.topMargin: parent.height * 9/10
        color: "#585858"
        radius: 15
    }
}
