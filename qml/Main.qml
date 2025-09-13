import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: root
    width: 400
    height: 300
    visible: true
    title: "LaserCal Demo"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "Run Calibration"
            onClicked: calibrationManager.runLinearTest()
        }

        Text {
            text: "Avg Measurement: " + calibrationManager.averageMeasurement().toFixed(3)
        }
    }
}
