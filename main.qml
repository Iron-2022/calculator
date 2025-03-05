import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import counter
import History

Window {
    id: mainWindow
    width: 360
    height: 640
    visible: true
    title: qsTr("calculator")

    property real buttonSizeFactor: mainWindow.width / 280
    property string textContent: calculator.textContent // Свойство для хранения текста

    DataModel {
        id: historyModel
    }

    Counter {
        id: calculator
        historyModel: historyModel
    }
    ColumnLayout{
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        ListView {
            Layout.fillWidth: true
            Layout.preferredHeight: 100
            model: historyModel
            delegate: Text {
                        text: itemData
                        font.pixelSize: 14
                    }
        }

        Text{
            id: displayText
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            text: calculator.textContent
            font.pixelSize: 20 * buttonSizeFactor
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
        }
        RowLayout {
            Layout.fillWidth: true
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "C"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: {
                    calculator.textContent = "0"  // Сброс текста
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "+/-"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: {
                    if (calculator.textContent !== "0") {
                        calculator.textContent = calculator.textContent.startsWith("-") ? calculator.textContent.slice(1) : "-" + calculator.textContent
                    }
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "%"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#808080" } // Grey
                onClicked: calculator.handleButton(text);
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "/"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                /*onClicked: {
                    // Логика для деления
                }*/
                onClicked: calculator.handleButton(text);
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "1"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "1"
                    else calculator.textContent += "1"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "2"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "2"
                    else calculator.textContent += "2"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "3"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "3"
                    else calculator.textContent += "3"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "*"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                /*onClicked: {
                    // Логика для умножения
                }*/
                onClicked: calculator.handleButton(text);
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "4"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "4"
                    else calculator.textContent += "4"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "5"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "5"
                    else calculator.textContent += "5"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "6"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "6"
                    else calculator.textContent += "6"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "-"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                /*onClicked: {
                    // Логика для вычитания
                }*/
                onClicked: calculator.handleButton(text);
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "7"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "7"
                    else calculator.textContent += "7"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "8"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "8"
                    else calculator.textContent += "8"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "9"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent === "0") calculator.textContent = "9"
                    else calculator.textContent += "9"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "+"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                /*onClicked: {
                    // Логика для сложения
                }*/
                onClicked: calculator.handleButton(text);
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Button {
                Layout.preferredWidth: 125 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                Layout.columnSpan: 2
                text: "0"
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (calculator.textContent !== "0") calculator.textContent += "0"
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "."
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#ADD8E6" } // Light Blue
                onClicked: {
                    if (!calculator.textContent.includes(".")) calculator.textContent += "."
                }
            }
            Button {
                Layout.preferredWidth: 60 * buttonSizeFactor
                Layout.preferredHeight: 40 * buttonSizeFactor
                text: "="
                font.pixelSize: 12 * buttonSizeFactor
                background: Rectangle { color: "#FFDEAD" } // Light Goldenrod Yellow
                /*onClicked: {
                    // Логика для вычисления результата
                }*/
                onClicked: calculator.handleButton(text);
            }
        }
    }
}
