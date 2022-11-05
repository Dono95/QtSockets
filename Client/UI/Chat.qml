import QtQuick 2.5
import QtQuick.Controls 2.0

Rectangle {
    ListView {
            id: listView
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10
            boundsBehavior: Flickable.StopAtBounds
            verticalLayoutDirection: ListView.BottomToTop
            focus: true
            clip: true

            model: ClientUI.messages
            delegate:
                Rectangle {
                        width: parent.width * 4/5
                        color: "#1548FF"
                        height: modelData.length > 40 ? 80 : 50
                        radius: 50
                        anchors.right: (modelData.typ === 2) ? parent.right : undefined
                        anchors.left: (modelData.typ === 1) ? parent.left : undefined

                        Component.onCompleted: console.log(modelData.length);
                        Text {
                            id: name
                            anchors.fill: parent
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            text: modelData.message
                            color: "#ffffff"
                            font.pixelSize: 20
                            wrapMode: Text.WordWrap
                        }
                     }

            ScrollBar.vertical: scrollBarListView

        }

        ScrollBar {
            id: scrollBarListView
        }
}
