import QtQuick 2.0
import QtQuick.Controls 2.2
import com.qmllist.worker 1.0

ApplicationWindow {
    visible: true
    width: 240
    height: 480
    title: qsTr("Hello World")

    Worker {
        id: worker
    }
    Item {
        anchors.fill: parent
        Component {
            id: myDelegate
            Item {
                width: ListView.view.width
                height: rootItemRow.height+2*rootItemRow.anchors.margins
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: 2
                    color: "#EEE"
                    Row {
                        id: rootItemRow
                        anchors {
                            left: parent.left
                            right: parent.right
                            verticalCenter: parent.verticalCenter
                            margins: 15
                        }
                        spacing: 10
                        Text {
                            text: model.lastName
                            color: "black"
                            font.bold: true
                        }
                        Text {
                            text: model.firstName
                            color: "black"
                        }
                    }
                }
            }
        }

        Text {
            id: headerLbl
            text: qsTr("Total items::%1").arg(listView.count)
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
            }
            horizontalAlignment: Text.AlignHCenter
        }
        ListView {
            id: listView
            anchors {
                top: headerLbl.bottom
                topMargin: 10
                left: parent.left
                right: parent.right
                bottom: btnRow.top
            }
            clip: true
            delegate: myDelegate
            model: worker.items
        }

        Row {
            id: btnRow
            spacing: 10
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
            }

            Button {
                id: addBtn
                text: qsTr("Add new")
                onClicked: worker.addModelItem()
            }

            Button {
                text: qsTr("Remove last")
                onClicked: worker.removeLastModelItem()
            }
        }
    }
}
