import QtQuick 2.4

Item {
    id: rightBar
    width: 400
    height: 400

    Rectangle {
        id: listOfOrders
        color: "#07ca07"
        anchors.fill: parent

        Rectangle {
            id: buttonsWrapper
            y: 320
            height: 85
            color: "#fcfc03"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            Button {
                id: addOrder
                y: 8
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 5
            }

            Button {
                id: deleteOrder
                x: 242
                y: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
            }
        }
    }
}
