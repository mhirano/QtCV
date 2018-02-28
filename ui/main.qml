import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal loadImageButtonPressed();

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

            Rectangle {
                id: imageForeground
                anchors.fill: parent
                color: "yellow"
                border.color: Qt.darker(color)
                border.width: 4
            }

            state: "unloaded"
            states: [
                State {
                    name: "unloaded"
                    PropertyChanges {
                        target: imageBackground
                        opacity: 1
                    }
                    PropertyChanges {
                        target: imageForeground
                        opacity: 0
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


        Button {
            id: loadImageButton
            text: "Load image"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                image.state = "loaded"
                loadImageButtonPressed()
            }
        }
    }





}
