import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    
    RowLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20
        
        // Left Panel - Statistics
        Rectangle {
            Layout.preferredWidth: 550
            Layout.fillHeight: true
            color: Theme.cardBgColor
            radius: 20
            border.width: 2
            border.color: Theme.borderColor
            
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20
                
                // Header
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 80
                    color: Theme.secondaryBgColor
                    radius: 15
                    
                    Text {
                        anchors.centerIn: parent
                        text: "Statistics"
                        font.pixelSize: 28
                        font.bold: true
                        color: Theme.accentColor
                    }
                }
                
                // Stats grid
                GridLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    columns: 2
                    rowSpacing: 15
                    columnSpacing: 15
                    
                    // Commander stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "COMMANDER"
                        value: edrhController.commanderName
                        icon: ""
                        accentColor: Theme.accentColor
                    }
                    
                    // Current system stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "CURRENT SYSTEM"
                        value: edrhController.currentSystem
                        icon: ""
                        accentColor: Theme.successColor
                    }
                    
                    // Session time stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "APP UPTIME"
                        value: edrhController.sessionTime
                        icon: ""
                        accentColor: Theme.infoColor
                    }
                    
                    // Jump count stat
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "JUMPS THIS SESSION"
                        value: edrhController.jumpCount.toString()
                        icon: ""
                        accentColor: Theme.warningColor
                    }
                    
                    // Map status (placeholder)
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "MAP STATUS"
                        value: edrhController.mapWindowActive ? "Active" : "Inactive"
                        icon: ""
                        accentColor: edrhController.mapWindowActive ? Theme.successColor : Theme.dangerColor
                    }
                    
                    // Claims stat (placeholder)
                    StatCard {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 80
                        title: "YOUR CLAIMS"
                        value: "0" // TODO: Implement claims count
                        icon: ""
                        accentColor: Theme.warningColor
                    }
                }
            }
        }
        
        // Right Panel - Actions
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: Theme.cardBgColor
            radius: 20
            border.width: 2
            border.color: Theme.borderColor
            
            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 30
                spacing: 20
                
                // Header
                Text {
                    text: "Galaxy Actions"
                    font.pixelSize: 24
                    font.bold: true
                    color: Theme.textColor
                    Layout.alignment: Qt.AlignHCenter
                }
                
                // Status indicator
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 120
                    color: Theme.secondaryBgColor
                    radius: 15
                    
                    ColumnLayout {
                        anchors.centerIn: parent
                        spacing: 10
                        
                        Text {
                            text: "Open"
                            font.pixelSize: 32
                            font.bold: true
                            color: Theme.textColor
                            Layout.alignment: Qt.AlignHCenter
                        }
                        
                        Rectangle {
                            width: 60
                            height: 20
                            color: Theme.successColor
                            radius: 10
                            Layout.alignment: Qt.AlignHCenter
                            
                            Text {
                                anchors.centerIn: parent
                                text: "● READY"
                                font.pixelSize: 10
                                font.bold: true
                                color: "#FFFFFF"
                            }
                        }
                    }
                }
                
                // Action buttons
                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 15
                    
                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 50
                        text: "🗺️ Open Galaxy Map"
                        
                        background: Rectangle {
                            color: parent.pressed ? Theme.infoColor : Theme.infoColor
                            radius: 12
                            border.width: 2
                            border.color: Qt.lighter(Theme.infoColor, 1.2)
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 16
                            font.bold: true
                            color: "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        onClicked: edrhController.openGalaxyMap()
                    }
                    
                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 50
                        text: "📊 View Claims"
                        
                        background: Rectangle {
                            color: parent.pressed ? Theme.successColor : Theme.successColor
                            radius: 12
                            border.width: 2
                            border.color: Qt.lighter(Theme.successColor, 1.2)
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 16
                            font.bold: true
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        onClicked: edrhController.viewClaims()
                    }
                    
                    Button {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 50
                        text: "⚙️ Settings"
                        
                        background: Rectangle {
                            color: parent.pressed ? Theme.warningColor : Theme.warningColor
                            radius: 12
                            border.width: 2
                            border.color: Qt.lighter(Theme.warningColor, 1.2)
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font.pixelSize: 16
                            font.bold: true
                            color: "#000000"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        onClicked: edrhController.openSettings()
                    }
                }
                
                // Spacer
                Item { Layout.fillHeight: true }
                
                // Footer info
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60
                    color: Theme.tertiaryBgColor
                    radius: 10
                    
                    Text {
                        anchors.centerIn: parent
                        text: "Galaxy Map integration ready\nClick 'Open Galaxy Map' to launch"
                        font.pixelSize: 12
                        color: Theme.textSecondary
                        horizontalAlignment: Text.AlignHCenter
                        lineHeight: 1.2
                    }
                }
            }
        }
    }
} 