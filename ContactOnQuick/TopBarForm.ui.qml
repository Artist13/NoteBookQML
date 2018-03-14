import QtQuick 2.4

Item {
    id: topBar
    width: 538
    height: 75

    Rectangle {
        id: rectangle
        color: "#00ffffff"
        radius: 5
        border.width: 2
        anchors.fill: parent

        Button {
            id: file
            y: 0
            height: 60
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 9
        }

        Button {
            id: edit
            x: 170
            y: 0
            height: 60
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: file.right
            anchors.leftMargin: 20
        }

        Button {
            id: help
            x: 340
            y: 0
            height: 60
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: edit.right
            anchors.leftMargin: 20
        }
    }
}
