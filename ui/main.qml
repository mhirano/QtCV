import QtQml 2.0
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal loadImageButtonPressed();
    //signal exitButtonPressed();

    Row {
        spacing: 20
        anchors.centerIn: parent

        Item {
            id: image
            width: 400
            height: 400

            Rectangle {
                id: imageBackground
                anchors.fill: parent
                color: "slategray"
                border.color: Qt.darker(color)
                border.width: 4
            }


            Image {
                id: imageForeground
                anchors.fill: parent
                source: "image://imageProvider/red"
            }

//            Connections {
//                target: imageForeground
//                onStateChanged: {
//                    imageForeground.source = "image://imageProvider/red"
//                }
//            }

            state: "unloaded"
            states: [
                State {
                    name: "unloaded"
                    PropertyChanges {
                        target: imageBackground
                        opacity: 0
                    }
                    PropertyChanges {
                        target: imageForeground
                        opacity: 1
                    }
                },
                State {
                    name: "loaded"
                    PropertyChanges {
                        target: imageBackground
                        opacity: 0
                    }
                    PropertyChanges {
                        target: imageForeground
                        opacity: 1
                    }
                }
            ]
            transitions: [
                Transition {
                    from: "*"; to: "*"
                    NumberAnimation { properties: "opacity"; duration: 100 }
                }
            ]
        }


        Column{
            spacing: 40
            Button {
                id: loadImageButton
                text: "Load image"
                // anchors.verticalCenter: parent.verticalCenter
                onClicked: {
                    image.state = "loaded"
                    loadImageButtonPressed()
                    imageForeground.source = "image://imageProvider/red"
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
