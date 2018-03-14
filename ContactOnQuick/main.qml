import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    visible: true
    width: 820
    height: 640
    title: qsTr("Contacts")


    TopBar{
        id: topBar
        anchors{
            top: parent.top
            topMargin: 5
            left: parent.left
            right: parent.right
        }
    }

    LeftBar{
        anchors{
            top: topBar.bottom
            topMargin: 10
            left: parent.left
            bottom: bottomBar.top
            bottomMargin: 5
        }
    }

    RightBar{
        anchors{
            top: topBar.bottom
            topMargin: 10
            right: parent.right
            bottom: bottomBar.top
            bottomMargin: 5
        }
    }

    BottomBar{
        id: bottomBar
        anchors{
            bottom: parent.bottom
        }
    }


}
