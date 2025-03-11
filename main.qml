import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import counter 1.0
import History 1.0

Window {
    id: mainWindow
    width: 360
    height: 640
    minimumWidth: 360
    minimumHeight: 640
    visible: true
    title: qsTr("calculator")

    property real buttonWidthFactor: mainWindow.width / 280
    property real buttonHeightFactor: mainWindow.height / 640
    property string textContent: calculator.textContent // Свойство для хранения текста

    DataModel {
        id: historyModel
    }

    Counter {
        id: calculator
        historyModel: historyModel
    }
    ColumnLayout{
        spacing: 10 * buttonWidthFactor
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 60 * buttonHeightFactor
            model: historyModel
            clip: true  // Это свойство обрезает элементы, выходящие за пределы видимости
            delegate: Text {
                        text: itemData
                        font.pixelSize: 14
                    }
            // Добавляем вертикальный ScrollBar
                    ScrollBar.vertical: ScrollBar {
                        id: vbar
                        width: 10
                        policy: ScrollBar.AlwaysOn
                    }
        }
        Text{
            id: displayText
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 60
            text: calculator.textContent
            font.pixelSize: 20 * buttonWidthFactor
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }
        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "C"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: {
                    calculator.textContent = "0"  // Сброс текста
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "+/-"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: {
                    if (calculator.textContent !== "0") {
                        calculator.textContent = calculator.textContent.startsWith("-") ? calculator.textContent.slice(1) : "-" + calculator.textContent
                    }
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "%"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: {calculator.textContent += " % "}
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "/"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                onClicked: {calculator.textContent += " / "}
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "1"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "1"
                    else calculator.textContent += "1"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "2"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "2"
                    else calculator.textContent += "2"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "3"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "3"
                    else calculator.textContent += "3"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "*"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                onClicked: {calculator.textContent += " * "}
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "4"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "4"
                    else calculator.textContent += "4"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "5"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "5"
                    else calculator.textContent += "5"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "6"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "6"
                    else calculator.textContent += "6"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "-"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                onClicked: {calculator.textContent += " - "}
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "7"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "7"
                    else calculator.textContent += "7"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "8"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "8"
                    else calculator.textContent += "8"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "9"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "9"
                    else calculator.textContent += "9"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "+"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                onClicked: {calculator.textContent += " + "}
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Button {
                Layout.preferredWidth: 125 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                Layout.columnSpan: 2
                text: "0"
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent !== "0") calculator.textContent += "0"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "."
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (!calculator.textContent.includes(".")) calculator.textContent += "."
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonWidthFactor
                Layout.preferredHeight: 60 * buttonHeightFactor
                text: "="
                font.pixelSize: 12 * buttonWidthFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                onClicked: calculator.handleButton();
            }
        }
    }
}
