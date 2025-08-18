import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

ApplicationWindow {
    id: mainWindow
    
    // Responsive window sizing
    width: Math.max(1200, Screen.width * 0.7)
    height: Math.max(800, Screen.height * 0.8)
    minimumWidth: 1000
    minimumHeight: 700
    
    visible: splashComplete
    title: "EDRH - Elite Dangerous Records Helper " + edrhController.appVersion
    
    // Material theme configuration
    Material.theme: Material.Dark
    Material.primary: "#FF7F50"  // ACCENT_COLOR
    Material.accent: "#FF7F50"
    Material.background: "#0a0a0a"  // MAIN_BG_COLOR
    Material.foreground: "#FFFFFF"  // TEXT_COLOR
    
    // Custom colors matching the Python version
    readonly property color mainBgColor: "#0a0a0a"
    readonly property color cardBgColor: "#141414"
    readonly property color secondaryBgColor: "#1f1f1f"
    readonly property color tertiaryBgColor: "#2a2a2a"
    readonly property color accentColor: "#FF7F50"
    readonly property color accentHover: "#FF9068"
    readonly property color successColor: "#4ECDC4"
    readonly property color dangerColor: "#E74C3C"
    readonly property color warningColor: "#F39C12"
    readonly property color infoColor: "#3498DB"
    readonly property color textColor: "#FFFFFF"
    readonly property color textSecondary: "#B0B0B0"
    readonly property color textMuted: "#808080"
    readonly property color borderColor: "#2a2a2a"
    
    background: Rectangle {
        color: mainBgColor
        
        // Beautiful space background like Icarus Terminal
        Rectangle {
            anchors.fill: parent
            color: "#0a0a0a"
            
            // Animated nebula-like gradient background
            Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#1a1a2e" }
                    GradientStop { position: 0.3; color: "#16213e" }
                    GradientStop { position: 0.7; color: "#0f172a" }
                    GradientStop { position: 1.0; color: "#0a0a0a" }
                }
                opacity: 0.6
                
                // Subtle pulsing animation
                SequentialAnimation on opacity {
                    loops: Animation.Infinite
                    running: true
                    NumberAnimation { to: 0.4; duration: 8000; easing.type: Easing.InOutQuad }
                    NumberAnimation { to: 0.6; duration: 8000; easing.type: Easing.InOutQuad }
                }
            }
            
            // Distant stars
            Repeater {
                model: 150
                Rectangle {
                    width: Math.random() * 2 + 0.5
                    height: width
                    radius: width / 2
                    color: Qt.rgba(1, 1, 1, Math.random() * 0.8 + 0.2)
                    x: Math.random() * (parent ? parent.width : 1200)
                    y: Math.random() * (parent ? parent.height : 800)
                    
                    // Subtle twinkling
                    SequentialAnimation on opacity {
                        loops: Animation.Infinite
                        NumberAnimation { 
                            to: Math.random() * 0.3 + 0.2
                            duration: (Math.random() * 3000) + 2000
                            easing.type: Easing.InOutQuad 
                        }
                        NumberAnimation { 
                            to: Math.random() * 0.9 + 0.1
                            duration: (Math.random() * 3000) + 2000
                            easing.type: Easing.InOutQuad 
                        }
                    }
                }
            }
            
            // Larger accent stars
            Repeater {
                model: 20
                Rectangle {
                    width: Math.random() * 4 + 2
                    height: width
                    radius: width / 2
                    color: "#FF7F50"
                    opacity: Math.random() * 0.6 + 0.2
                    x: Math.random() * (parent ? parent.width : 1200)
                    y: Math.random() * (parent ? parent.height : 800)
                    
                    // Gentle pulsing
                    SequentialAnimation on scale {
                        loops: Animation.Infinite
                        NumberAnimation { to: 1.3; duration: 4000; easing.type: Easing.InOutQuad }
                        NumberAnimation { to: 1.0; duration: 4000; easing.type: Easing.InOutQuad }
                    }
                }
            }
        }
    }
    
    // Application state management
    property bool splashComplete: false
    property bool appReady: false
    
    // Splash Screen Overlay (separate window)
    Window {
        id: splashWindow
        width: 600
        height: 400
        visible: !splashComplete
        flags: Qt.SplashScreen | Qt.WindowStaysOnTopHint | Qt.FramelessWindowHint | Qt.WindowFullscreenButtonHint
        color: "#000000"
        modality: Qt.ApplicationModal
        
        // Center the splash screen on screen
        x: (Screen.width - width) / 2
        y: (Screen.height - height) / 2
        
        // Ensure it stays on top
        Component.onCompleted: {
            raise()
            requestActivate()
        }
        
        SplashScreen {
            id: splashScreen
            anchors.fill: parent
            
            Component.onCompleted: {
                // Start full database download when splash screen is ready
                edrhController.startFullDatabaseDownload()
                // Start the real initialization process
                initializeApplication()
            }
            
            onSplashComplete: {
                mainWindow.splashComplete = true
                mainWindow.visible = true
                mainContent.visible = true
                mainContent.opacity = 1.0
                splashWindow.close()
                splashWindow.destroy() // Completely remove splash
            }
        }
    }
    
            // Main content area (hidden during splash)
        Item {
            id: mainContent
            anchors.fill: parent
            visible: splashComplete
            opacity: splashComplete ? 1.0 : 0.0
        
        Behavior on opacity {
            NumberAnimation { duration: 500; easing.type: Easing.InOutQuad }
        }
        
        Rectangle {
            anchors.fill: parent
            anchors.margins: 10
            color: "transparent"
            
            // Tab view container - transparent to show space background
            Rectangle {
                id: tabContainer
                anchors.fill: parent
                color: "transparent"
                radius: 15
                border.width: 2
                border.color: borderColor
                
                TabBar {
                    id: tabBar
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 50
                    
                    background: Rectangle {
                        color: secondaryBgColor
                        radius: 15
                    }
                    
                    TabButton {
                        text: "Main"
                        font.pixelSize: 16
                        font.bold: true
                        
                        background: Rectangle {
                            color: parent.checked ? accentColor : tertiaryBgColor
                            radius: 10
                            border.width: 1
                            border.color: borderColor
                        }
                        
                        contentItem: Text {
                            text: parent.text
                            font: parent.font
                            color: parent.checked ? "#000000" : textColor
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                
                // Tab content stack
                StackLayout {
                    id: stackLayout
                    anchors.top: tabBar.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.margins: 10
                    currentIndex: tabBar.currentIndex
                    
                    // Main Tab
                    Item {
                        id: mainTab
                        
                        RowLayout {
                            anchors.fill: parent
                            spacing: 15
                            
                            // Left Panel - Expanded Commander Dashboard
                            ColumnLayout {
                                Layout.preferredWidth: 500  // Increased from 450 to 500
                                Layout.fillHeight: true
                                spacing: 20  // Increased from 15 to 20
                                
                                // Commander Info Card (increased size so text doesn't hit edges)
                                CommanderInfoCard {
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 280  // Increased from 250 to 280
                                    Layout.maximumHeight: 280
                                }
                                
                                // Quick Actions Card
                                QuickActionsCard {
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 120  // Increased from 100 to 120
                                }
                                
                                // Galaxy Actions Card (includes statistics)
                                GalaxyActionsCard {
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    Layout.minimumHeight: 480  // Increased from 420 to 480 for better statistics layout
                                }
                            }
                            
                            // Right Panel - Nearest Systems
                            ColumnLayout {
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                Layout.minimumWidth: 520  // Increased from 500 to 520
                                spacing: 20  // Increased from 15 to 20
                                
                                // Nearest Unclaimed Card  
                                NearestUnclaimedCard {
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 220  // Increased from 200 to 220
                                }
                                
                                // Nearest Systems Panel
                                NearestSystemsPanel {
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    Layout.minimumHeight: 450  // Increased from 400 to 450
                                }
                            }
                        }
                    }
                }
            }
            
            // Version label
            Rectangle {
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                width: versionText.implicitWidth + 20
                height: versionText.implicitHeight + 8
                color: secondaryBgColor
                radius: 6
                
                Text {
                    id: versionText
                    anchors.centerIn: parent
                    text: edrhController.appVersion
                    color: textMuted
                    font.pixelSize: 10
                    font.bold: true
                }
            }
            
            // Admin indicator (if admin)
            Rectangle {
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.margins: 20
                width: adminText.width + 24
                height: adminText.height + 12
                color: dangerColor
                radius: 8
                visible: edrhController.isAdmin
                
                Text {
                    id: adminText
                    anchors.centerIn: parent
                    text: "⚡ ADMIN MODE"
                    color: "#FFFFFF"
                    font.pixelSize: 12
                    font.bold: true
                }
            }
            
            // Refresh button
            Button {
                anchors.top: parent.top
                anchors.right: edrhController.isAdmin ? parent.right : parent.right
                anchors.margins: 20
                anchors.rightMargin: edrhController.isAdmin ? 140 : 20
                
                text: "↻ Refresh"
                font.pixelSize: 12
                font.bold: true
                
                background: Rectangle {
                    color: parent.pressed ? tertiaryBgColor : secondaryBgColor
                    border.width: 1
                    border.color: borderColor
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    font: parent.font
                    color: textColor
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: edrhController.refreshData()
            }
        }
    }
    
    // Message popup (for showing notifications)
    Popup {
        id: messagePopup
        x: (parent.width - width) / 2  // Center horizontally
        y: 50  // Position from top of window
        width: 400
        height: 200
        modal: true
        z: 1000  // Ensure it appears above other popups
        
        property alias title: titleText.text
        property alias message: messageText.text
        
        background: Rectangle {
            color: cardBgColor
            radius: 15
            border.width: 2
            border.color: accentColor
        }
        
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 20
            
            Text {
                id: titleText
                font.pixelSize: 18
                font.bold: true
                color: accentColor
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
            }
            
            Text {
                id: messageText
                font.pixelSize: 14
                color: textColor
                Layout.fillWidth: true
                Layout.fillHeight: true
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            
            Button {
                text: "OK"
                Layout.alignment: Qt.AlignHCenter
                
                background: Rectangle {
                    color: parent.pressed ? accentHover : accentColor
                    radius: 8
                }
                
                contentItem: Text {
                    text: parent.text
                    font.bold: true
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                
                onClicked: messagePopup.close()
            }
        }
    }
    
    // Connect to controller signals
    Connections {
        target: edrhController
        
        function onShowMessage(title, message) {
            messagePopup.title = title
            messagePopup.message = message
            messagePopup.open()
        }
        
        function onShowError(title, message) {
            messagePopup.title = title
            messagePopup.message = message
            messagePopup.open()
        }
        
        function onShowSystemPopup(systemName, systemData) {
            showSystemView(systemName, systemData)
        }
        
        function onDatabaseDownloadProgress(progress, status) {
            if (splashScreen && !mainWindow.splashComplete) {
                splashScreen.updateProgress(progress, status)
            }
        }
        
        function onDatabaseDownloadComplete() {
            if (splashScreen && !mainWindow.splashComplete) {
                splashScreen.complete()
            }
        }
        

    }
    
    // System view popup management
    property var currentSystemPopup: null
    
    function showSystemView(systemName, systemData) {
        // Close existing popup if open
        if (currentSystemPopup) {
            currentSystemPopup.close()
            currentSystemPopup.destroy()
        }
        
        // Create new popup
        var component = Qt.createComponent("SystemViewPopup.qml")
        if (component.status === Component.Ready) {
            currentSystemPopup = component.createObject(mainWindow, {
                "systemName": systemName,
                "systemData": systemData,
                "category": systemData.category || "Unknown"
            })
            
            if (currentSystemPopup) {
                currentSystemPopup.closing.connect(function() {
                    currentSystemPopup.destroy()
                    currentSystemPopup = null
                })
                
                currentSystemPopup.show()
            }
        } else {
            console.error("Failed to create SystemViewPopup:", component.errorString())
        }
    }

    // Application initialization
    function initializeApplication() {
        // Step 1: Load configuration
        splashScreen.updateProgress(0.2, "Loading configuration...")
        
        // Step 2: Connect to database  
        Qt.callLater(function() {
            splashScreen.updateProgress(0.4, "Connecting to Supabase...")
            
            // Trigger actual data loading
            edrhController.refreshData()
            
            // Step 3: Load journal data
            Qt.callLater(function() {
                splashScreen.updateProgress(0.6, "Scanning journal files...")
                
                // Step 4: Load system data
                Qt.callLater(function() {
                    splashScreen.updateProgress(0.8, "Loading system data...")
                    
                    // Step 5: Initialize UI
                    Qt.callLater(function() {
                        splashScreen.updateProgress(1.0, "Ready!")
                        // Mark app as ready after a short delay
                        readyTimer.start()
                    })
                })
            })
        })
    }
    
    Timer {
        id: readyTimer
        interval: 2000  // Show splash for 2 seconds
        onTriggered: {
            appReady = true
            if (splashScreen) {
                splashScreen.complete()
            }
        }
    }
} 