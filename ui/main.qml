import QtQml 2.0
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal loadImageButtonClicked();

    Row {
        spacing: 20
        anchors.centerIn: parent

        Item {
            id: imageLocation
            width: 400
            height: 400

            Image {
                id: currentFrame
                anchors.fill: parent
                source: "image://imageProviderChannel/defaultImage"
            }

            Connections {
                id: currentFrameConnection
                target: imageProvider
                onImageChanged: { 
                    currentFrame.source = "image://imageProviderChannel/currentFrame"
                }
            }
        }

        Column{
            spacing: 40
            Button {
                id: loadImageButton
                text: "Load image"
                onClicked: {
                    imageProvider.onLoadImageButtonClicked()
                }
            }
            Button {
                id: exitButton
                text: "exit"
                onClicked: Qt.quit()
            }
        }
    }

}
