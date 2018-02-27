import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit()
//        }
//    }

    Text {
        id: textField
        text: qsTr("hello world")
        anchors.centerIn: parent
    }


//    Button {
//        text: "Emit Signal!"
//        anchors.centerIn: parent
//        anchors.verticalCenterOffset: 30
//        onClicked: cppSignalSlot.cppSlot("Hello from QML")
//    }

//    Connections{ // Behave like signal receiver
//        target: cppSignalSlot // signal emitter that this module receives
//        onCppSignal: { //Activates when C++ emits singal 'cppSignal()'
//            console.log("received cppSignal:" + text)
//            textField.text = text;
//        }
//    }

}
