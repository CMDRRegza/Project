import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    
    color: Theme.cardBgColor
    border.color: Theme.borderColor
    border.width: 2
    radius: 15
    
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 25  // Increased from 20 to 25
        spacing: 20  // Increased from 15 to 20
        
        // Header
        RowLayout {
            Layout.fillWidth: true
            
            Text {
                text: "GALAXY ACTIONS"
                font.pixelSize: 15  // Increased from 13 to 15
                font.bold: true
                color: Theme.accentColor
            }
            
            Item { Layout.fillWidth: true }
        }
        
        // Action buttons
        ColumnLayout {
            Layout.fillWidth: true
            spacing: 12  // Increased from 10 to 12
            
            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 50  // Increased from 45 to 50
                text: "Open Galaxy Map"
                
                background: Rectangle {
                    color: parent.pressed ? Theme.accentHover : Theme.accentColor
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 15  // Increased from 14 to 15
                    font.bold: true
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: edrhController.openGalaxyMap()
            }
            
            Button {
                Layout.fillWidth: true
                Layout.preferredHeight: 50  // Increased from 45 to 50
                text: "View Your Systems"
                
                background: Rectangle {
                    color: parent.pressed ? Qt.darker(Theme.successColor, 1.2) : Theme.successColor
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 15  // Increased from 14 to 15
                    font.bold: true
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: edrhController.viewYourSystems()
            }
        }
        
        // Statistics Section
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 360  // Increased from 300 to 360 for better statistics layout
            color: Theme.secondaryBgColor
            radius: 15
            border.width: 1
            border.color: Theme.borderColor
            
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20  // Increased from 15 to 20
                spacing: 15  // Increased from 12 to 15
                
                // Stats Header
                RowLayout {
                    Layout.fillWidth: true
                    
                    Text {
                        text: "STATISTICS"
                        font.pixelSize: 16  // Increased from 14 to 16
                        font.bold: true
                        color: Theme.accentColor
                    }
                    
                    Item { Layout.fillWidth: true }
                }
                
                // Stats grid
                GridLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    columns: 2
                    rowSpacing: 12  // Increased from 8 to 12
                    columnSpacing: 12  // Increased from 8 to 12
                    
                    // Session time stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 75  // Increased from 50 to 75 for better text layout
                        title: "APP UPTIME"
                        value: edrhController.sessionTime
                        icon: ""
                        accentColor: Theme.infoColor
                    }
                    
                    // Jump count stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 75  // Increased from 50 to 75
                        title: "JUMPS THIS SESSION"
                        value: edrhController.jumpCount.toString()
                        icon: ""
                        accentColor: Theme.warningColor
                    }
                    
                    // Map status
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 75  // Increased from 50 to 75
                        title: "MAP STATUS"
                        value: edrhController.mapWindowActive ? "Active" : "Inactive"
                        icon: ""
                        accentColor: edrhController.mapWindowActive ? Theme.successColor : Theme.dangerColor
                    }
                    
                    // Claims stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 75  // Increased from 50 to 75
                        title: "YOUR CLAIMS"
                        value: edrhController.claimsCount.toString()
                        icon: ""
                        accentColor: Theme.warningColor
                    }
                }
            }
        }
    }
} 