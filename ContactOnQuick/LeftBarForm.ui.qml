import QtQuick 2.4

Item {
    id: leftBar
    width: 400
    height: 400

    Rectangle {
        id: listOfStudent
        color: "#d70d0d"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        ListView {
            id: listView
            anchors.bottom: buttonWrapper.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 6
            anchors.topMargin: 5

            model: students
            delegate: Rectangle {
                height: 25
                anchors {
                    left: parent.left
                    leftMargin: 10
                    right: parent.right
                }

                Text {
                    text: modelData
                }
            }
        }

        Rectangle {
            id: buttonWrapper
            y: 316
            width: 400
            height: 85
            color: "#f32bf3"
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Button {
                id: addStudent
                width: 175

                text: "Add Student"
                anchors.top: parent.top
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                anchors.leftMargin: 5
                anchors.bottom: parent.bottom
                anchors.left: parent.left
            }

            Button {
                id: deleteStudent
                width: 175
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                text: "Delete Student"
                anchors.rightMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
                anchors.leftMargin: 225
            }
        }
    }
}
