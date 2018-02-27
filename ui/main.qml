import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal loadImageButtonSignal();


    Button {
        id: loadImageButton
        text: "Load image"
        anchors.centerIn: parent
        onClicked: loadImageButtonSignal()
    }


}
