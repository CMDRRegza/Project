import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: root
    
    property var systemData: ({})
    
    signal systemClicked(string systemName)
    signal systemNameCopyRequested(string systemName)
    
    height: 130  // Increased height from 120 to 130 for better visual impact
    color: "transparent"
    radius: 15
    border.width: 2
    border.color: "#333333"
    clip: true  // Prevent content from overflowing outside the card
    
    // Extract data with safety checks
    readonly property string systemName: (systemData && typeof systemData === 'object' && systemData.name) ? systemData.name : "Unknown System"
    readonly property string category: (systemData && typeof systemData === 'object' && systemData.category) ? systemData.category : "Wolf-Rayet Star"
    readonly property string distance: (systemData && typeof systemData === 'object' && systemData.distance) ? systemData.distance : "N/A"
    readonly property string poi: (systemData && typeof systemData === 'object' && systemData.poi) ? systemData.poi : ""
    readonly property bool isDone: (systemData && typeof systemData === 'object' && systemData.done) ? systemData.done : false
    readonly property string categoryColor: {
        if (systemData && typeof systemData === 'object' && systemData.categoryColor && typeof systemData.categoryColor === 'string' && systemData.categoryColor !== "") {
            return systemData.categoryColor
        }
        var fallbackColor = getCategoryColor()
        return (fallbackColor && typeof fallbackColor === 'string' && fallbackColor !== "") ? fallbackColor : "#FF7F50"
    }
    readonly property string backgroundImage: getBackgroundImage()
    
    // Background image layer
    Rectangle {
        id: backgroundContainer
        anchors.fill: parent
        radius: parent.radius
        color: "#1a1a1a"
        clip: true
        
        // Background image
        Image {
            id: bgImage
            anchors.fill: parent
            source: root.backgroundImage
            fillMode: Image.PreserveAspectCrop
            opacity: 0.6
            
            // Fallback to gradient if image fails to load
            onStatusChanged: {
                if (status === Image.Error) {
                    bgImage.visible = false
                    fallbackGradient.visible = true
                }
            }
            
            // Smooth loading animation
            Behavior on opacity {
                NumberAnimation { duration: 300 }
            }
        }
        
        // Fallback gradient background
        Rectangle {
            id: fallbackGradient
            anchors.fill: parent
            visible: false
            gradient: Gradient {
                GradientStop { 
                    position: 0.0
                    color: root.categoryColor
                }
                GradientStop { 
                    position: 1.0
                    color: Qt.darker(root.categoryColor, 2.0)
                }
            }
            opacity: 0.4
        }
        
        // Dark overlay for text readability
        Rectangle {
            anchors.fill: parent
            color: "#000000"
            opacity: 0.5
            radius: parent.radius
        }
        
        // Subtle noise texture effect
        Rectangle {
            anchors.fill: parent
            radius: parent.radius
            opacity: 0.1
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: 0.0; color: "transparent" }
                GradientStop { position: 0.3; color: "#FFFFFF" }
                GradientStop { position: 0.7; color: "transparent" }
                GradientStop { position: 1.0; color: "#FFFFFF" }
            }
        }
    }
    
    // Main content overlay
    Rectangle {
        anchors.fill: parent
        color: "transparent"
        radius: parent.radius
        
        RowLayout {
            anchors.fill: parent
            anchors.margins: 20  // Increased from 18 to 20
            spacing: 18  // Increased from 15 to 18
            
            // Left side - System info
            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: 8  // Increased from 6 to 8
                
                // System name (clickable)
                Text {
                    id: systemNameText
                    text: root.systemName
                    font.pixelSize: 22  // Increased from 20 to 22
                    font.bold: true
                    color: "#FFFFFF"
                    Layout.fillWidth: true
                    elide: Text.ElideRight
                    
                    // Drop shadow for better readability
                    style: Text.Outline
                    styleColor: "#000000"
                    
                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        
                        onEntered: {
                            parent.color = "#FF7F50"
                            parent.scale = 1.02
                        }
                        onExited: {
                            parent.color = "#FFFFFF"
                            parent.scale = 1.0
                        }
                        onClicked: root.systemNameCopyRequested(root.systemName)
                    }
                    
                    Behavior on color {
                        ColorAnimation { duration: 200 }
                    }
                    
                    Behavior on scale {
                        NumberAnimation { duration: 150; easing.type: Easing.OutQuad }
                    }
                }
                
                // Category
                Text {
                    text: root.category
                    font.pixelSize: 13  // Increased from 12 to 13
                    color: "#E0E0E0"
                    Layout.fillWidth: true
                    elide: Text.ElideRight
                    opacity: 0.9
                    
                    style: Text.Outline
                    styleColor: "#000000"
                }
                
                // Badges row
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10  // Increased from 8 to 10
                    
                    // POI badge
                    Rectangle {
                        visible: root.poi !== ""
                        width: poiText.width + 16
                        height: poiText.height + 8
                        color: root.poi === "POI" ? "#48bb78" : "#f6ad55"
                        radius: 6
                        border.width: 1
                        border.color: Qt.lighter(color, 1.3)
                        
                        // Glow effect (Qt6 compatible)
                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width + 2
                            height: parent.height + 2
                            color: "transparent"
                            border.color: parent.color
                            border.width: 1
                            radius: parent.radius + 1
                            opacity: 0.4
                            z: -1
                        }
                        
                        Text {
                            id: poiText
                            anchors.centerIn: parent
                            text: root.poi === "POI" ? "★ POI" : "◎ POTENTIAL"
                            font.pixelSize: 10
                            font.bold: true
                            color: "#FFFFFF"
                        }
                    }
                    
                    // Done badge
                    Rectangle {
                        visible: root.isDone
                        width: doneText.width + 16
                        height: doneText.height + 8
                        color: "#9f7aea"
                        radius: 6
                        border.width: 1
                        border.color: Qt.lighter(color, 1.3)
                        
                        // Glow effect (Qt6 compatible)
                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width + 2
                            height: parent.height + 2
                            color: "transparent"
                            border.color: parent.color
                            border.width: 1
                            radius: parent.radius + 1
                            opacity: 0.4
                            z: -1
                        }
                        
                        Text {
                            id: doneText
                            anchors.centerIn: parent
                            text: "✓ DONE"
                            font.pixelSize: 10
                            font.bold: true
                            color: "#FFFFFF"
                        }
                    }
                    
                    // Category color indicator
                    Rectangle {
                        width: 12
                        height: 12
                        radius: 6
                        color: root.categoryColor
                        border.width: 1
                        border.color: "#FFFFFF"
                        opacity: 0.8
                        
                        // Subtle glow (Qt6 compatible)
                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width + 2
                            height: parent.height + 2
                            color: "transparent"
                            border.color: parent.color
                            border.width: 1
                            radius: parent.radius + 1
                            opacity: 0.3
                            z: -1
                        }
                    }
                    
                    // Spacer
                    Item { Layout.fillWidth: true }
                }
            }
            
            // Right side - Distance and action button
            ColumnLayout {
                Layout.preferredWidth: 140  // Increased from 130 to 140
                Layout.fillHeight: true
                spacing: 15  // Increased from 12 to 15
                
                // Distance badge
                Rectangle {
                    Layout.alignment: Qt.AlignHCenter
                    width: distanceText.width + 24  // Increased from 20 to 24
                    height: distanceText.height + 16  // Increased from 12 to 16
                    color: "#1a1a1a"
                    radius: 8
                    border.width: 2
                    border.color: "#FF7F50"
                    opacity: 0.9
                    
                    // Background glow (Qt6 compatible)
                    Rectangle {
                        anchors.centerIn: parent
                        width: parent.width + 4
                        height: parent.height + 4
                        color: "transparent"
                        border.color: "#FF7F50"
                        border.width: 1
                        radius: parent.radius + 2
                        opacity: 0.5
                        z: -1
                    }
                    
                    Text {
                        id: distanceText
                        anchors.centerIn: parent
                        text: root.distance
                        font.pixelSize: 13  // Increased from 12 to 13
                        font.bold: true
                        color: "#FFFFFF"
                    }
                }
                
                // View button
                Button {
                    Layout.alignment: Qt.AlignHCenter
                    text: "View"
                    width: 80  // Increased from 70 to 80
                    height: 36  // Increased from 32 to 36
                    
                    background: Rectangle {
                        id: btnBg
                        color: parent.pressed ? "#0ea5c4" : (parent.hovered ? "#17a2b8" : "#138496")
                        radius: 8
                        border.width: 1
                        border.color: Qt.lighter(btnBg.color, 1.2)
                        
                        // Subtle gradient - fixed color reference
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: Qt.lighter(btnBg.color, 1.1) }
                            GradientStop { position: 1.0; color: btnBg.color }
                        }
                        
                        // Button glow on hover (Qt6 compatible)
                        Rectangle {
                            anchors.centerIn: parent
                            width: parent.width + (parent.parent.hovered ? 4 : 0)
                            height: parent.height + (parent.parent.hovered ? 4 : 0)
                            color: "transparent"
                            border.color: parent.color
                            border.width: parent.parent.hovered ? 1 : 0
                            radius: parent.radius + 2
                            opacity: parent.parent.hovered ? 0.6 : 0
                            z: -1
                            
                            Behavior on width {
                                NumberAnimation { duration: 200 }
                            }
                            Behavior on height {
                                NumberAnimation { duration: 200 }
                            }
                            Behavior on opacity {
                                NumberAnimation { duration: 200 }
                            }
                        }
                        
                        Behavior on color {
                            ColorAnimation { duration: 150 }
                        }
                    }
                    
                    contentItem: Text {
                        text: parent.text
                        font.pixelSize: 14  // Increased from 13 to 14
                        font.bold: true
                        color: "#FFFFFF"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    
                    onClicked: root.systemClicked(root.systemName)
                }
            }
        }
    }
    
    // Card hover effect
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents: true
        
        onEntered: {
            root.border.color = "#FF7F50"
            root.border.width = 3
            root.scale = 1.02
            hoverGlow.visible = true
        }
        onExited: {
            root.border.color = "#333333"
            root.border.width = 2
            root.scale = 1.0
            hoverGlow.visible = false
        }
        
        onPressed: function(mouse) { mouse.accepted = false }
        onReleased: function(mouse) { mouse.accepted = false }
        onClicked: function(mouse) { mouse.accepted = false }
    }
    
    // Hover glow effect (Qt6 compatible)
    Rectangle {
        id: hoverGlow
        anchors.centerIn: parent
        width: parent.width + 6
        height: parent.height + 6
        color: "transparent"
        border.color: "#FF7F50"
        border.width: 2
        radius: parent.radius + 3
        opacity: 0.6
        visible: false
        z: -1
        
        Behavior on visible {
            NumberAnimation { duration: 200 }
        }
    }
    
    // Smooth animations
    Behavior on scale {
        NumberAnimation { duration: 200; easing.type: Easing.OutQuad }
    }
    
    Behavior on border.color {
        ColorAnimation { duration: 200 }
    }
    
    Behavior on border.width {
        NumberAnimation { duration: 200 }
    }
    
    // Helper functions
    function getBackgroundImage() {
        if (typeof imageLoader !== 'undefined' && imageLoader && imageLoader.hasPresetImage(root.category)) {
            var url = imageLoader.getPresetImageUrl(root.category)
            var cached = imageLoader.getCachedImagePath(url)
            if (cached && cached !== "") {
                return "file:///" + cached
            } else {
                // Start loading the image
                imageLoader.loadPresetImage(root.category)
                // Return fallback while loading
                return ""
            }
        }
        return ""
    }
    
    function getCategoryColor() {
        // Expanded color mapping for known categories
        var categoryColors = {
            "Wolf-Rayet Star": "#FF6B35",
            "High Metal Content World": "#4ECDC4",
            "Scenic": "#45B7D1",
            "Binary Planets": "#96CEB4",
            "Potential POI": "#FFEAA7",
            "POI": "#FD79A8",
            "Extreme close proximity to ring": "#24499f",
            "Very cool": "#cbd14c",
            "Great system.": "#04e288",
            "Pretty cool system": "#282eac",
            "PVP (tilted moon)": "#ff4444",
            "The Legend (false)": "#f82900",
            "BarycentreWD+ Atmospheric Landable": "#44ff88",
            "Alternative Carousel": "#9b59b6"  // Purple color for Alternative Carousel
        }
        
        // Enhanced safety checks for category property
        var categoryValue = ""
        try {
            // Check if root exists and has category property
            if (typeof root !== 'undefined' && root !== null && 'category' in root) {
                categoryValue = root.category || ""
            }
        } catch (e) {
            console.warn("Error accessing category:", e)
            return "#FF7F50"  // Default accent color
        }
        
        // Additional safety checks
        if (typeof categoryValue !== "string" || categoryValue === "" || categoryValue === null || categoryValue === undefined) {
            return "#FF7F50"  // Default accent color
        }
        
        // Return mapped color or default
        var color = categoryColors[categoryValue];
        return (color !== undefined && color !== null && typeof color === "string") ? color : "#FF7F50";
    }
} 