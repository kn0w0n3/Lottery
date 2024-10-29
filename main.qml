import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 900
    height: 600
    visible: true
    color: "#000000"
    title: qsTr("Lottery")

    //Main Controller Connections
    Connections {
        target: mainController

        onDirPathToQml:{
            dirText.text = _dirPath;
        }

        onThreadStatusToQml:{
            mainWinInfoText.text += _threadStatus + "\n"
        }
    }


    Rectangle {
        id: checkTicketWin
        x: 0
        y: 0
        width: 898
        height: 600
        color: "#000000"

        Text {
            id: windowTitle
            x: 329
            y: 0
            width: 241
            height: 42
            color: "#ffffff"
            text: qsTr("Check Numbers")
            font.pixelSize: 33
        }

        Rectangle {
            id: rectangle1
            x: 155
            y: 90
            width: 600
            height: 275
            color: "#000000"
            border.color: "#ffffff"
        }


        Rectangle {
            id: rectangle3
            x: 294
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle4
            x: 349
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle5
            x: 405
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle6
            x: 461
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle7
            x: 517
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }
        Rectangle {
            id: rectangle2
            x: 239
            y: 449
            width: 37
            height: 32
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle8
            x: 237
            y: 394
            width: 518
            height: 25
            color: "#000000"
            border.color: "#ffffff"
        }

        Button {
            id: button
            x: 155
            y: 394
            width: 71
            height: 26
            text: qsTr("Select File")
        }

        Text {
            id: text2
            x: 239
            y: 374
            width: 233
            height: 21
            color: "#ffffff"
            text: qsTr("Select file containing number combinations")
            font.pixelSize: 12
        }

        Button {
            id: button1
            x: 239
            y: 497
            width: 71
            height: 25
            text: qsTr("Start")
        }

        Text {
            id: text3
            x: 239
            y: 428
            width: 137
            height: 21
            color: "#ffffff"
            text: qsTr("Enter winning numbers")
            font.pixelSize: 12
        }
    }

    Rectangle {
        id: mainWin
        x: 0
        y: 0
        width: 900
        height: 600
        color: "#000000"
        border.color: "#000000"

        Image {
            id: mainBackground
            x: 0
            y: 0
            width: 900
            height: 600

            //For viewing in app
            source: "/images/main-bg-900x600.png"

            //For viewing in editor
            //source: "images/main-bg-900x600.png"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: mainWin_Info_Win
            x: 155
            y: 90
            width: 600
            height: 275
            color: "#000000"
            border.color: "#ffffff"

            ScrollView {
                id: scrollView
                x: 3
                y: 4
                width: 594
                height: 267
                clip: true

                TextArea {
                    id: mainWinInfoText
                    color: "#ffffff"
                    font.pointSize: 10
                    placeholderText: qsTr("Hello World")
                    background: Rectangle {color: "black"}
                }
            }
        }

        Text {
            id: mainWinText
            x: 411
            y: 0
            width: 79
            height: 40
            color: "#ffffff"
            text: qsTr("Main")
            font.pixelSize: 33
        }

        Button {
            id: startBtn
            x: 229
            y: 449
            width: 60
            height: 20
            text: qsTr("Start")
            onClicked: {

                if(lottoType.currentText === " Select Game"){
                    mainWinInfoText.text += "Please select a game..." + "\n"
                }
                else if(lottoType.currentText === " Powerball"){
                    if(dirText.text === ""){
                        mainWinInfoText.text += "Please select a location to save results..." + "\n"
                    }else{
                        mainWinInfoText.text += "Powerball number picks starting..." + "\n"
                        mainController.pickPowerballNums();
                    }
                }
            }
        }

        Rectangle {
            id: numTicketsRect
            x: 229
            y: 423
            width: 77
            height: 20
            color: "#000000"
            border.color: "#ffffff"
        }

        Text {
            id: numTicketsTxtLabel
            x: 229
            y: 405
            width: 165
            height: 20
            color: "#ffffff"
            text: qsTr("Number of tickets to generate")
            font.pixelSize: 12
        }

        Rectangle {
            id: directoryRect
            x: 229
            y: 382
            width: 526
            height: 20
            color: "#000000"
            border.color: "#ffffff"

            Text {
                id: dirText
                x: 3
                y: 2
                width: 520
                height: 16
                color: "#ffffff"
                text: qsTr("")
                font.pixelSize: 12
            }
        }

        Button {
            id: selectDirButton
            x: 155
            y: 382
            width: 60
            height: 20
            text: qsTr("Select")
            onClicked: {
                mainController.selectDirectory();
            }
        }

        Text {
            id: text1
            x: 229
            y: 365
            width: 130
            height: 18
            color: "#ffffff"
            text: qsTr("Select File Save Location")
            font.pixelSize: 12
        }

        ComboBox {
            id: lottoType
            x: 155
            y: 64
            width: 152
            height: 21
            visible: true
            model: [" Select Game", " Powerball", " Mega Millions", " Super Lotto Plus", " Fantasy 5", " Daily 4", " Daily 3"]

            delegate: ItemDelegate {
                width: lottoType.width
                contentItem: Text {
                    text: lottoType.textRole
                          ? (Array.isArray(lottoType.model) ? modelData[lottoType.textRole] : model[lottoType.textRole])
                          : modelData
                    color: "#000000" //Change the text color of the model data in the drop down box.
                    font: lottoType.font
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                }
                highlighted: lottoType.highlightedIndex === index
            }

            indicator: Canvas {
                id: canvasDb
                x: lottoType.width - width - lottoType.rightPadding
                y: lottoType.topPadding + (lottoType.availableHeight - height) / 2
                width: 12
                height: 8
                contextType: "2d"

                Connections {
                    target: lottoType
                    function onPressedChanged() { canvasDb.requestPaint(); }
                }

                //This will change the color of the triangle indicator.
                onPaint: {
                    context.reset();
                    context.moveTo(0, 0);
                    context.lineTo(width, 0);
                    context.lineTo(width / 2, height);
                    context.closePath();
                    context.fillStyle = lottoType.pressed ? "#FFFFFF" : "#FFFFFF";
                    context.fill();
                }
            }
            //The second color is the main color. The first item is what color the changes to once clicked.
            //This will change the text color of main text in the box.
            contentItem: Text {
                leftPadding: 0
                rightPadding: lottoType.indicator.width + lottoType.spacing

                text: lottoType.displayText
                font: lottoType.font
                color: lottoType.pressed ? "#FFFFFF" : "#FFFFFF"
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            //This will change the main box background color, border color,  and the border color when pressed.
            //The second color is the main color. The first item is what color the changes to once clicked.
            background: Rectangle {
                implicitWidth: 120
                implicitHeight: 40
                color: "#000000"
                border.color: lottoType.pressed ? "#FFFFFF" : "#FFFFFF"
                border.width: lottoType.visualFocus ? 2 : 1
                radius: 2
            }

            popup: Popup {
                y: lottoType.height - 1
                width: lottoType.width
                implicitHeight: contentItem.implicitHeight
                padding: 1

                contentItem: ListView {
                    clip: true
                    implicitHeight: contentHeight
                    model: lottoType.popup.visible ? lottoType.delegateModel : null
                    currentIndex: lottoType.highlightedIndex

                    ScrollIndicator.vertical: ScrollIndicator { }
                }

                //This will change the color of the drop down Rectangle
                background: Rectangle {
                    border.color: "#FFFFFF"
                    color: "#FFFFFF"
                    radius: 5
                }
            }
        }


    }

    Rectangle {
        id: sideBar
        x: 0
        y: 0
        width: 52
        height: 600
        opacity: 0.35
        visible: true
        color: "#303030"
        border.color: "#000000"

        Image {
            id: homeBtnImg
            x: 8
            y: 24
            width: 36
            height: 41
            visible: true

            //For viewing in app
            source: "/images/home_btn.png"

            //For viewing in editor
            //source: "images/home_btn.png"
            smooth: true
            layer.textureMirroring: ShaderEffectSource.MirrorVertically
            layer.format: ShaderEffectSource.Alpha
            clip: false
            fillMode: Image.PreserveAspectFit

            MouseArea {
                id: mouseAreaHomeBtn
                x: 0
                y: 0
                width: 36
                height: 41
                onClicked: {
                    checkTicketWin.visible = false
                    mainWin.visible = true
                }
            }
        }

        Image {
            id: checkNumsBtn
            x: 8
            y: 90
            width: 36
            height: 41
            visible: true
            fillMode: Image.PreserveAspectFit
            clip: false
            smooth: true
            layer.format: ShaderEffectSource.Alpha
            layer.textureMirroring: ShaderEffectSource.MirrorVertically

            //For viewing in app
            source: "/images/check-btn.png"

            //For viewing in editor
            //source: "images/check-btn.png"

            MouseArea {
                id: mouseAreaCheckBtn
                width: 36
                height: 41
                onClicked: {
                    checkTicketWin.visible = true
                    mainWin.visible = false
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0}D{i:2;invisible:true}
}
##^##*/
