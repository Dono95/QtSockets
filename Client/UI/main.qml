import QtQuick 2.5
import QtQuick.Window 2.2

Window { // Must be this type to be loaded by QQmlApplicationEngine.
    visible: true
    width: 600   //Accessing global context declared in C++
    height: 800 //Accessing global context declared in C++
    title: qsTr("Messenger")
    color: "#ffffff"

    Chat {
        anchors.fill: parent
        anchors.margins: 10
        anchors.bottomMargin: parent.height * 1/8
        color: "#4ddbe3"
        radius: 15
    }
}
