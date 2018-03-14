import QtQuick 2.4

Rectangle {
    width: 150
    height: 75
    antialiasing: true
    id: rectangle
    property alias text: textLabel.text
    Accessible.name: text
    Accessible.description: "This button does" + text
    Accessible.role: Accessible.Button

    signal clicked

    color: "#7d7979"
    radius: 6
    transformOrigin: Item.Center

    Text {
        id: textLabel
        text: "Button"
        anchors.centerIn: parent
        font.pixelSize: parent.height * .2
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: parent.clicked
    }
}
