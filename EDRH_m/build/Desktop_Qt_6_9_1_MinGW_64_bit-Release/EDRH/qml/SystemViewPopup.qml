import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

ApplicationWindow {
    id: popupWindow
    
    property string systemName: ""
    property string category: ""
    property var systemData: ({})
    property var systemInfo: null
    property bool isClaimedByUser: false
    property string systemDescription: ""
    
    width: 900
    height: 700
    minimumWidth: 800
    minimumHeight: 600
    
    title: "POI: " + systemName
    modality: Qt.ApplicationModal
    
    Material.theme: Material.Dark
    Material.primary: "#FF7F50"
    Material.accent: "#FF7F50"
    Material.background: "#0a0a0a"
    Material.foreground: "#FFFFFF"
    
    background: Rectangle {
        color: "#0a0a0a"
    }
    
    Component.onCompleted: {
        if (systemName) {
            edrhController.getSystemInformationRobust(systemName)
        }
        updateSystemDisplay()
        checkClaimStatus()
    }
    
    Connections {
        target: edrhController
        function onSystemInformationReceived(sysName, sysInfo) {
            if (sysName === systemName) {
                systemInfo = sysInfo
                updateSystemDisplay()
            }
        }
        
        // Note: Claim success signals would be handled here if they existed
    }
    
    function updateSystemDisplay() {
        if (systemInfo && systemInfo.hasInformation) {
            systemInfoText.text = systemInfo.system_info || "No additional system information available"
        } else {
            systemInfoText.text = "Basic system information displayed above. No additional details available in database."
        }
        systemDescription = ""
        checkClaimStatus()
    }
    
    function checkClaimStatus() {
        if (edrhController.isSystemClaimedByCurrentCommander) {
            isClaimedByUser = edrhController.isSystemClaimedByCurrentCommander(systemName)
        } else {
            isClaimedByUser = false
        }
    }
    
    function updateClaimStatus() {
        console.log("Claim status updated for", systemName, ":", isClaimedByUser)
    }
    
    function calculateDistance(x, y, z) {
        if (x === undefined || y === undefined || z === undefined) return "N/A"
        var distance = Math.sqrt(x*x + y*y + z*z)
        return distance.toFixed(2) + " LY"
    }
    
    function getCoordinatesText() {
        if (systemInfo && typeof systemInfo === 'object') {
            var x = systemInfo.x
            var y = systemInfo.y  
            var z = systemInfo.z
            if (x !== undefined && y !== undefined && z !== undefined) {
                return "X: " + x.toFixed(2) + ", Y: " + y.toFixed(2) + ", Z: " + z.toFixed(2)
            }
        }
        return "X: N/A, Y: N/A, Z: N/A"
    }
    
    function getDistanceText() {
        if (systemInfo && typeof systemInfo === 'object') {
            var x = systemInfo.x
            var y = systemInfo.y
            var z = systemInfo.z
            if (x !== undefined && y !== undefined && z !== undefined) {
                return calculateDistance(x, y, z)
            }
        }
        return "N/A"
    }
    
    function getCategoryColor() {
        var categoryColors = {
            "Colliding Rings": "#24499f",
            "Alternative Carousel": "#9b59b6",
            "Extreme close proximity to ring": "#24499f",
            "PVP (tilted moon)": "#ff4444",
            "PVP (black hole gas giant moons)": "#ff4444",
            "PVP (close binary)": "#ff4444",
            "BarycentreWD+ Atmospheric Landable": "#44ff88"
        }
        return categoryColors[category] || "#666666"
    }
    
    function getCategoryImageUrl() {
        var categoryImages = {
            "Colliding Rings": "https://i.imgur.com/CThH6gr.jpeg",
            "Alternative Carousel": "https://i.imgur.com/euTEv9Z.jpeg",
            "Extreme close proximity to ring": "https://i.imgur.com/TZkpip1.jpeg",
            "PVP (tilted moon)": "https://i.imgur.com/CakbwU9.jpeg",
            "PVP (black hole gas giant moons)": "https://i.imgur.com/OsdJiVt.jpeg",
            "PVP (close binary)": "https://i.imgur.com/bGQHoJ9.png",
            "BarycentreWD+ Atmospheric Landable": "https://i.imgur.com/JQxCopB.jpeg"
        }
        return categoryImages[category] || ""
    }
    
    // Main layout with fixed bottom buttons
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 0
        
        // Content area (no scroll here)
        ColumnLayout {
            id: contentColumn
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 20
                
                // Header
                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 120
                    color: "#141414"
                    border.color: "#FF7F50"
                    border.width: 2
                    radius: 15
                    
                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 15
                        
                        Rectangle {
                            Layout.preferredWidth: 80
                            Layout.preferredHeight: 80
                            color: "#0a0a0a"
                            radius: 8
                            
                            Rectangle {
                                anchors.centerIn: parent
                                width: parent.width * 0.8
                                height: parent.height * 0.8
                                color: getCategoryColor()
                                radius: 6
                            }
                        }
                        
                        ColumnLayout {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            spacing: 8
                            
                            Text {
                                text: systemName
                                font.pixelSize: 24
                                font.bold: true
                                color: "#FF7F50"
                                Layout.fillWidth: true
                                elide: Text.ElideRight
                                
                                MouseArea {
                                    anchors.fill: parent
                                    cursorShape: Qt.PointingHandCursor
                                    onClicked: edrhController.copyToClipboard(systemName)
                                    onEntered: parent.color = "#FFD700"
                                    onExited: parent.color = "#FF7F50"
                                }
                            }
                            
                            Text {
                                text: category || "Unknown Category"
                                font.pixelSize: 14
                                color: "#B0B0B0"
                                Layout.fillWidth: true
                                elide: Text.ElideRight
                            }
                        }
                    }
                }
                
                // Tabbed content
                TabBar {
                    id: tabBar
                    Layout.fillWidth: true
                    
                    TabButton {
                        text: "System Info"
                        font.pixelSize: 14
                        font.bold: true
                        
                        background: Rectangle {
                            color: parent.checked ? "#FF7F50" : "#2a2a2a"
                            radius: 8
                            border.width: 1
                            border.color: "#444444"
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font: parent.font
                            color: parent.checked ? "#000000" : "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    
                    TabButton {
                        text: "Images"
                        font.pixelSize: 14
                        font.bold: true
                        
                        background: Rectangle {
                            color: parent.checked ? "#FF7F50" : "#2a2a2a"
                            radius: 8
                            border.width: 1
                            border.color: "#444444"
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font: parent.font
                            color: parent.checked ? "#000000" : "#FFFFFF"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                
                // Tab content
                StackLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    currentIndex: tabBar.currentIndex
                    
                    // System Info tab (with scrolling)
                    Item {
                        Flickable {
                            anchors.fill: parent
                            clip: true
                            contentWidth: width
                            contentHeight: systemInfoColumn.implicitHeight + 40
                            boundsBehavior: Flickable.StopAtBounds
                            
                            ScrollBar.vertical: ScrollBar {
                                active: true
                                policy: ScrollBar.AsNeeded
                            }
                            
                            ColumnLayout {
                                id: systemInfoColumn
                                width: Math.max(parent.width, 800)
                                spacing: 15
                            
                            // System details
                            Repeater {
                                model: [
                                    { label: "System Name:", value: systemName },
                                    { label: "Coordinates:", value: getCoordinatesText() },
                                    { label: "Distance from Sol:", value: getDistanceText() },
                                    { label: "Categories:", value: category || "Unknown" }
                                ]
                                
                                Rectangle {
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 60
                                    color: "#1f1f1f"
                                    radius: 8
                                    
                                    RowLayout {
                                        anchors.fill: parent
                                        anchors.margins: 15
                                        spacing: 10
                                        
                                        Text {
                                            text: modelData.label
                                            font.pixelSize: 14
                                            font.bold: true
                                            color: "#FF7F50"
                                            Layout.preferredWidth: 150
                                        }
                                        
                                        Text {
                                            text: modelData.value
                                            font.pixelSize: 14
                                            color: "#FFFFFF"
                                            Layout.fillWidth: true
                                            wrapMode: Text.WordWrap
                                        }
                                    }
                                }
                            }
                            
                            // System Info
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.minimumHeight: 150
                                Layout.preferredHeight: systemInfoText.implicitHeight + 80
                                color: "#1f1f1f"
                                radius: 8
                                
                                ColumnLayout {
                                    anchors.fill: parent
                                    anchors.margins: 15
                                    spacing: 10
                                    
                                    Text {
                                        text: "System Info:"
                                        font.pixelSize: 14
                                        font.bold: true
                                        color: "#FF7F50"
                                    }
                                    
                                    Text {
                                        id: systemInfoText
                                        text: "Loading system information..."
                                        font.pixelSize: 13
                                        font.family: "Consolas, Courier New, monospace"
                                        color: "#FFFFFF"
                                        wrapMode: Text.WordWrap
                                        Layout.fillWidth: true
                                        lineHeight: 1.3
                                    }
                                }
                            }
                        }
                    }
                    
                    // Images tab
                    Item {
                        Flickable {
                            anchors.fill: parent
                            clip: true
                            contentWidth: width
                            contentHeight: imagesColumn.implicitHeight + 40
                            boundsBehavior: Flickable.StopAtBounds
                            
                            ScrollBar.vertical: ScrollBar {
                                active: true
                                policy: ScrollBar.AsNeeded
                            }
                            
                            ColumnLayout {
                                id: imagesColumn
                                width: Math.max(parent.width, 800)
                                spacing: 15
                            
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.preferredHeight: 40
                                color: "#1f1f1f"
                                radius: 8
                                
                                Text {
                                    anchors.centerIn: parent
                                    text: "Images"
                                    font.pixelSize: 16
                                    font.bold: true
                                    color: "#FF7F50"
                                }
                            }
                            
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.minimumHeight: 200
                                color: "#1f1f1f"
                                radius: 8
                                
                                ColumnLayout {
                                    anchors.fill: parent
                                    anchors.margins: 15
                                    spacing: 10
                                    
                                    Text {
                                        text: "Category Images:"
                                        font.pixelSize: 14
                                        color: "#FF7F50"
                                    }
                                    
                                    Rectangle {
                                        Layout.fillWidth: true
                                        Layout.preferredHeight: 150
                                        color: "#0f0f0f"
                                        radius: 4
                                        
                                        Image {
                                            anchors.fill: parent
                                            anchors.margins: 5
                                            fillMode: Image.PreserveAspectFit
                                            source: getCategoryImageUrl()
                                            
                                            Text {
                                                anchors.centerIn: parent
                                                text: parent.status === Image.Loading ? "Loading..." : 
                                                      parent.status === Image.Error ? "Image not available" : ""
                                                color: "#666666"
                                                font.pixelSize: 12
                                                visible: parent.status !== Image.Ready
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        
        // Fixed bottom buttons
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 70
            color: "#0a0a0a"
            
            RowLayout {
                anchors.fill: parent
                anchors.margins: 15
                spacing: 15
                
                Button {
                    Layout.preferredWidth: 180
                    Layout.preferredHeight: 45
                    text: isClaimedByUser ? "Unclaim System" : "Claim System"
                    font.pixelSize: 14
                    font.bold: true
                    
                    background: Rectangle {
                        color: isClaimedByUser ? "#dc3545" : "#28a745"
                        radius: 8
                        border.color: isClaimedByUser ? "#c82333" : "#218838"
                        border.width: 1
                    }
                    
                    contentItem: Text {
                        text: parent.text
                        color: "#FFFFFF"
                        font: parent.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    
                    onClicked: {
                        if (isClaimedByUser) {
                            edrhController.unclaimSystem(systemName)
                        } else {
                            edrhController.claimSystem(systemName)
                        }
                    }
                }
                
                Item { Layout.fillWidth: true }
                
                Button {
                    Layout.preferredWidth: 100
                    Layout.preferredHeight: 45
                    text: "Close"
                    font.pixelSize: 14
                    font.bold: true
                    
                    background: Rectangle {
                        color: "#FF7F50"
                        radius: 8
                        border.color: "#FF5722"
                        border.width: 1
                    }
                    
                    contentItem: Text {
                        text: parent.text
                        color: "#000000"
                        font: parent.font
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    
                    onClicked: popupWindow.close()
                }
            }
        }
    }
}