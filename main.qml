import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Window {
    id: mWindow
    visible: true
    minimumWidth: 640
    minimumHeight: 480
    title: qsTr("Hello World")



    Frame{
        id: tableFrame
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        padding: 0
        implicitWidth: 400

        background: Rectangle{
            id: frameBg
            anchors.fill: parent
            layer.enabled: true
            layer.effect: DropShadow {
                id: frameShadow
                transparentBorder: true
                radius: 10
                samples: 20
                color: "#b0000000"
            }
        }

        MouseArea{
            anchors.fill: parent
            onClicked: focus = true
        }

        ColumnLayout{
            spacing: 5
            anchors.fill: parent

            Rectangle{
                id: frameHeader
                Layout.fillWidth: true
                height: 72
                color: "#6200ee"
                RowLayout{
                    id: row
                    width: parent.width
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.fill: parent
                    anchors.leftMargin: 16
                    anchors.rightMargin: 16
                    Text{
                        text: "Persons"
                        color: "white"
                        font.pixelSize: 20
                        font.bold: true
                    }

                    TextField{
                        id: inputFilter
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        placeholderText: "Поиск..."
                        background: Rectangle {
                                  implicitWidth: 200
                                  implicitHeight: 40
                                  color: "transparent"
                                  border.color: "white"
                              }
                        color: "white"
                        rightPadding: 40
                        opacity: focus ? 1 : 0.5
                        onTextChanged: PersonModel.setFilterText(text)

                    }
                }
            }

            ListView{
                id: listView
                Layout.fillWidth: true
                Layout.fillHeight: true
                model: PersonModel
                focus: true
                clip: true
                headerPositioning: ListView.OverlayHeader
                snapMode: ListView.SnapToItem

                header: Rectangle{
                    width: parent.width
                    height: 36
                    z:5
                    Text {
                        anchors.fill: parent
                        leftPadding: 16
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 14
                        font.bold: true
                        text: "TOTAL : " + PersonModel.rowCount() + " PERSONS"
                    }
                }

                delegate:  Rectangle{
                    width: parent.width
                    height: 72
                    Rectangle{
                        anchors.top: parent.top
                        width: parent.width
                        color: "gray"
                        height: 1
                    }

                    RowLayout {
                        anchors.fill: parent
                        anchors.bottomMargin: 8
                        anchors.topMargin: 8
                        anchors.leftMargin: 8
                        anchors.rightMargin: 16

                        Image {
                            smooth: true
                            source: "./icons/user.png"
                        }

                        Column{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            spacing: 3
                            topPadding: 8
                            Text{
                                text: name
                                font.pixelSize: 16
                                color: "black"
                            }
                            Text{
                                text: post
                                font.pixelSize: 14
                                color: "gray"
                            }

                        }

                        Text{
                            text: index + 1
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                }
            }
        }
    }


}






/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
