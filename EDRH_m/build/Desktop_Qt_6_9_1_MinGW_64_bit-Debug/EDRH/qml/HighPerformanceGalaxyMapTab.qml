import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import EDRH.Components 1.0
import EDRH 1.0

Item {
    id: root
    
    // Navigation properties
    property real zoomLevel: 1.0
    property point panOffset: Qt.point(0, 0)
    property bool isLoading: false
    
    Component.onCompleted: {
        // Connect to real-time updates with safety checks
        try {
            if (edrhController && edrhController.galaxyMapSystemsChanged) {
                edrhController.galaxyMapSystemsChanged.connect(updateSystemsData)
            }
            
            // Add delay to ensure all components are initialized
            timer.setTimeout(function() {
                updateSystemsData()
            }, 100)
            
            // Force initial update after a longer delay to ensure controller is ready
            timer.setTimeout(function() {
                updateSystemsData()
            }, 500)
        } catch (error) {
            console.log("Error in Component.onCompleted:", error)
        }
    }
    
    // Simple timer for delayed execution
    Timer {
        id: timer
        
        function setTimeout(callback, delay) {
            timer.interval = delay
            timer.repeat = false
            timer.triggered.connect(callback)
            timer.start()
        }
    }
    
    function updateSystemsData() {
        updateFilteredSystems()
    }
    
    // Filter Manager instance (same as in NearestSystemsPanel)  
    FilterManager {
        id: filterManager
        
        onFiltersChanged: {
            updateFilteredSystems()
        }

    }
    
    // Filtered systems for the galaxy map
    property var filteredGalaxyMapSystems: []
    
    // Timer for retrying star renderer updates with size checking
    Timer {
        id: retryTimer
        interval: 200
        repeat: true
        running: false
        property int attempts: 0
        onTriggered: {
            attempts++
            
            // Only retry if we have both data AND proper dimensions
            if (filteredGalaxyMapSystems.length > 0 && galaxyRenderer.width > 0 && galaxyRenderer.height > 0) {
                try {
                    galaxyRenderer.starSystems = filteredGalaxyMapSystems
                    stop() // Stop retrying if successful
                } catch (e) {
                    if (attempts >= 20) {
                        stop()
                    }
                }
            } else {
                if (filteredGalaxyMapSystems.length === 0 || attempts >= 20) {
                    stop()
                }
            }
        }
    }
    
    // Additional force timer to ensure data gets set
    Timer {
        id: forceTimer
        interval: 500
        repeat: true
        running: true
        property int attempts: 0
        onTriggered: {
            attempts++
            if (filteredGalaxyMapSystems.length > 0 && galaxyRenderer.width > 0 && galaxyRenderer.height > 0) {
                // Force reload by clearing and setting again
                var currentSystems = galaxyRenderer.starSystems
                galaxyRenderer.starSystems = []
                galaxyRenderer.starSystems = filteredGalaxyMapSystems
                stop()
            } else if (attempts >= 40) { // 20 seconds max
                stop()
            }
        }
    }
    
    // Force update when filtered systems change
    onFilteredGalaxyMapSystemsChanged: {
        // Only start retry if we have data AND renderer has proper size
        if (filteredGalaxyMapSystems.length > 0) {
            // Force immediate update if component is ready
            if (galaxyRenderer.width > 0 && galaxyRenderer.height > 0) {
                galaxyRenderer.starSystems = filteredGalaxyMapSystems
            } else {
                // Start retry timer with reset attempts
                retryTimer.attempts = 0
                retryTimer.restart()
            }
        }
    }
    

    
    function updateFilteredSystems() {
        try {
            var filtered = []
            var sourceData = edrhController.galaxyMapSystems || []
            
            if (!sourceData || sourceData.length === 0) {
                root.filteredGalaxyMapSystems = filtered
                return
            }
            
            // Apply claim status filters FIRST (like v1.4incomplete.py)
            for (var i = 0; i < sourceData.length; i++) {
                var system = sourceData[i]
                
                if (!system) continue  // Skip null/undefined systems
            
            // Check claim status filters (checkboxes) - like v1.4incomplete.py
            var claimed = system.claimed || false
            var claimedBy = system.claimedBy || ""
            var poi = system.poi || ""
            var currentCommander = edrhController.commanderName || "Regza"
            
            // If ANY checkboxes are checked, apply filtering. If NONE are checked, show NO systems.
            var anyClaimFilterActive = showUnclaimedCheck.checked || showYourClaimsCheck.checked || 
                                      showOthersClaimsCheck.checked || showPotentialPOIsCheck.checked ||
                                      showPOIsCheck.checked || showDoneSystemsCheck.checked
            
            if (anyClaimFilterActive) {
                var passesClaimFilter = false
                
                if (showUnclaimedCheck.checked && !claimed) {
                    passesClaimFilter = true
                }
                if (showYourClaimsCheck.checked && claimed && claimedBy === currentCommander) {
                    passesClaimFilter = true
                }
                if (showOthersClaimsCheck.checked && claimed && claimedBy !== currentCommander) {
                    passesClaimFilter = true
                }
                if (showPotentialPOIsCheck.checked && poi === "Potential POI") {
                    passesClaimFilter = true
                }
                if (showPOIsCheck.checked && poi === "POI") {
                    passesClaimFilter = true
                }
                if (showDoneSystemsCheck.checked && (system.status === "Done" || system.done === true)) {
                    passesClaimFilter = true
                }
                
                // If claim filters are active but this system doesn't pass, skip it
                if (!passesClaimFilter) {
                    continue
                }
            } else {
                // If no claim filters are active, skip all systems (show nothing by default)
                continue
            }
            
            // Then check category filters using FilterManager
            if (filterManager.matchesFilter(system)) {
                // Additional check to exclude Richard's categories
                var systemCategory = system.category || ""
                var richardCategories = ["PVP (tilted moon)", "PVP (black hole gas giant moons)", "PVP (close binary)"]
                var isRichardSystem = false
                
                for (var j = 0; j < richardCategories.length; j++) {
                    if (systemCategory === richardCategories[j]) {
                        isRichardSystem = true
                        break
                    }
                }
                
                if (!isRichardSystem) {
                    filtered.push(system)
                }
            }
            }
            
            // Set filtered systems directly
            root.filteredGalaxyMapSystems = filtered
            
            // Update the star renderer safely
            if (galaxyRenderer && typeof galaxyRenderer.starSystems !== "undefined") {
                galaxyRenderer.starSystems = root.filteredGalaxyMapSystems
            }
            
        } catch (error) {
            console.log("Error in updateFilteredSystems:", error)
            // Set empty array on error to prevent crashes
            root.filteredGalaxyMapSystems = []
            if (galaxyRenderer && typeof galaxyRenderer.starSystems !== "undefined") {
                galaxyRenderer.starSystems = []
            }
        }
    }
    

    
    // Galaxy map with high-performance C++ renderer
    GalaxyMapRenderer {
        id: galaxyRenderer
        anchors.fill: parent
        // Fallback explicit dimensions if anchoring fails
        width: parent.width > 0 ? parent.width : 1200
        height: parent.height > 0 ? parent.height : 800
        
        zoomLevel: root.zoomLevel
        panOffset: root.panOffset
        backgroundImage: "assets/E47CDFX.png"
        commanderPosition: Qt.point((edrhController && edrhController.commanderX) ? edrhController.commanderX : 0, 
                                   (edrhController && edrhController.commanderZ) ? edrhController.commanderZ : 0)
        
        // Use default star visibility - filtering is done by claim status, not star type
        showMainSequence: true
        showNeutronStars: true
        showWhiteDwarfs: true
        showBlackHoles: true
        
        // Tooltips enabled with proper positioning and scaling
        tooltipsEnabled: true
        
        // Commander location properties
        showAllCommanders: showAllCommandersCheck.checked
        isAdminMode: edrhController.isAdmin || false
        allCommanderLocations: edrhController.allCommanderLocations || []
        
        // Connect to filtered star data from EDRH controller
        starSystems: root.filteredGalaxyMapSystems || []
        
        // Listen for component completion and size changes
        Component.onCompleted: {
            // Force update when component is ready
            retryDataUpdate()
            
            // Also retry after a short delay to handle timing issues
            Qt.callLater(function() {
                retryDataUpdate()
            })
        }
        
        // Listen for new galaxy map data and immediately update
        Connections {
            target: edrhController
            function onGalaxyMapSystemsChanged() {
                Qt.callLater(updateFilteredSystems)
            }
        }
        
        // Retry when component gets proper dimensions
        onWidthChanged: {
            if (width > 0 && height > 0 && root.filteredGalaxyMapSystems.length > 0) {
                // Force reload since component now has proper size
                var currentSystems = starSystems
                starSystems = []  // Clear first
                starSystems = currentSystems  // Then set again to force loadRealStarSystems()
                retryTimer.stop()
            }
        }
        
        onHeightChanged: {
            if (width > 0 && height > 0 && root.filteredGalaxyMapSystems.length > 0) {
                // Force reload since component now has proper size
                var currentSystems = starSystems
                starSystems = []  // Clear first
                starSystems = currentSystems  // Then set again to force loadRealStarSystems()
                retryTimer.stop()
            }
        }
        
        function retryDataUpdate() {
            try {
                if (root.filteredGalaxyMapSystems && root.filteredGalaxyMapSystems.length > 0 && width > 0 && height > 0) {
                    starSystems = root.filteredGalaxyMapSystems
                    // Stop any running retry timer since we succeeded
                    if (retryTimer) retryTimer.stop()
                } else if (root.filteredGalaxyMapSystems && root.filteredGalaxyMapSystems.length > 0) {
                    // Don't start retry timer immediately - wait for proper sizing
                    if (width > 0 && height > 0) {
                        if (retryTimer) {
                            retryTimer.attempts = 0
                            retryTimer.restart()
                        }
                    }
                }
            } catch (error) {
                console.log("Error in retryDataUpdate:", error)
            }
        }
        
        onSystemRightClicked: (systemName, x, y, z) => {
            // Open system info popup on right-click
            if (systemName && edrhController) {
                // Find the full system data
                var systems = edrhController.galaxyMapSystems || []
                var systemData = null
                
                for (var i = 0; i < systems.length; i++) {
                    if (systems[i].name === systemName) {
                        systemData = systems[i]
                        break
                    }
                }
                
                if (systemData) {
                    edrhController.showSystemPopup(systemName, systemData)
                } else {
                    // Create minimal system data if not found
                    edrhController.showSystemPopup(systemName, {
                        name: systemName,
                        x: x,
                        y: y,
                        z: z
                    })
                }
            }
        }
        
        // Mouse interaction for pan and zoom
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            
            property point lastPanPoint
            property bool isPanning: false
            
            onPressed: (mouse) => {
                if (mouse.button === Qt.LeftButton) {
                    lastPanPoint = Qt.point(mouse.x, mouse.y)
                    isPanning = true
                }
                // Right-click removed - use spacebar to reset view
            }
            
            onPositionChanged: (mouse) => {
                if (isPanning && (mouse.buttons & Qt.LeftButton)) {
                    var delta = Qt.point(mouse.x - lastPanPoint.x, mouse.y - lastPanPoint.y)
                    root.panOffset = Qt.point(root.panOffset.x + delta.x, root.panOffset.y + delta.y)
                    lastPanPoint = Qt.point(mouse.x, mouse.y)
                }
            }
            
            onReleased: (mouse) => {
                if (mouse.button === Qt.LeftButton) {
                    isPanning = false
                }
            }
            
            onWheel: (wheel) => {
                // Mouse-centered zoom with stability improvements for high zoom levels
                var zoomFactor = wheel.angleDelta.y > 0 ? 1.15 : 1.0/1.15
                var newZoomLevel = Math.max(0.1, Math.min(20.0, root.zoomLevel * zoomFactor))
                
                // Skip update if zoom didn't actually change (prevents precision issues)
                if (Math.abs(newZoomLevel - root.zoomLevel) < 0.001) {
                    return
                }
                
                // Get mouse position
                var mouseX = wheel.x
                var mouseY = wheel.y
                
                // Add bounds checking for stability at high zoom levels
                if (mouseX < 0 || mouseX > width || mouseY < 0 || mouseY > height) {
                    root.zoomLevel = newZoomLevel
                    return
                }
                
                // Apply EXACT inverse transformation sequence as in C++ paint():
                // 1. translate(width/2, height/2)
                // 2. translate(panOffset)  
                // 3. scale(zoom)
                // 4. translate(-width/2, -height/2)
                
                // Step 1: Move mouse to origin relative to center
                var step1X = mouseX - width / 2.0
                var step1Y = mouseY - height / 2.0
                
                // Step 2: Remove pan offset
                var step2X = step1X - root.panOffset.x
                var step2Y = step1Y - root.panOffset.y
                
                // Step 3: Remove zoom (inverse scale) with precision check
                if (root.zoomLevel < 0.001) {
                    root.zoomLevel = newZoomLevel
                    return
                }
                var worldX = step2X / root.zoomLevel
                var worldY = step2Y / root.zoomLevel
                
                // Clamp world coordinates to prevent excessive values at high zoom
                var maxWorldCoord = 100000
                worldX = Math.max(-maxWorldCoord, Math.min(maxWorldCoord, worldX))
                worldY = Math.max(-maxWorldCoord, Math.min(maxWorldCoord, worldY))
                
                // Apply zoom change
                root.zoomLevel = newZoomLevel
                
                // Now transform world coordinates back to screen with new zoom
                // Step 3: Apply new zoom
                var newStep2X = worldX * root.zoomLevel
                var newStep2Y = worldY * root.zoomLevel
                
                // Step 2: Calculate new pan offset with bounds checking
                var newPanX = step1X - newStep2X
                var newPanY = step1Y - newStep2Y
                
                // Clamp pan offset to prevent excessive values
                var maxPan = 50000
                newPanX = Math.max(-maxPan, Math.min(maxPan, newPanX))
                newPanY = Math.max(-maxPan, Math.min(maxPan, newPanY))
                
                root.panOffset = Qt.point(newPanX, newPanY)
            }
        }
        
        // Keyboard navigation
        Keys.onPressed: (event) => {
            var panSpeed = 20
            
            switch (event.key) {
                case Qt.Key_Left:
                    root.panOffset = Qt.point(root.panOffset.x + panSpeed, root.panOffset.y)
                    event.accepted = true
                    break
                case Qt.Key_Right:
                    root.panOffset = Qt.point(root.panOffset.x - panSpeed, root.panOffset.y)
                    event.accepted = true
                    break
                case Qt.Key_Up:
                    root.panOffset = Qt.point(root.panOffset.x, root.panOffset.y + panSpeed)
                    event.accepted = true
                    break
                case Qt.Key_Down:
                    root.panOffset = Qt.point(root.panOffset.x, root.panOffset.y - panSpeed)
                    event.accepted = true
                    break
                // Keyboard zoom removed - use mouse wheel for proper mouse-centered zoom
                case Qt.Key_Space:
                case Qt.Key_Home:
                    root.zoomLevel = 1.0
                    root.panOffset = Qt.point(0, 0)
                    event.accepted = true
                    break
            }
        }
        
        focus: true
    }
    
    // Collapsible Filter Panel - Compact Design
    Rectangle {
        id: galaxyFilterPanel
        width: filterPanelExpanded ? 240 : 35
        height: filterPanelExpanded ? 500 : 35
        x: 10
        y: 10
        color: Qt.rgba(0.05, 0.05, 0.1, 0.95)
        radius: 8
        border.width: 1
        border.color: "#FF7F50"
        
        property bool filterPanelExpanded: true  // Start expanded for debugging
        
        Behavior on width { NumberAnimation { duration: 200; easing.type: Easing.OutCubic } }
        Behavior on height { NumberAnimation { duration: 200; easing.type: Easing.OutCubic } }
        
        // Toggle Button (always visible)
        Rectangle {
            id: toggleButton
            width: 30
            height: 30
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 2
            color: toggleMouseArea.pressed ? "#FF9068" : (toggleMouseArea.containsMouse ? "#FF7F50" : "#444444")
            radius: 6
            border.width: 1
            border.color: "#FF7F50"
            
            Text {
                anchors.centerIn: parent
                text: galaxyFilterPanel.filterPanelExpanded ? "X" : "="
                color: "#FFFFFF"
                font.pixelSize: 12
                font.bold: true
            }
            
            MouseArea {
                id: toggleMouseArea
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    galaxyFilterPanel.filterPanelExpanded = !galaxyFilterPanel.filterPanelExpanded
                }
            }
        }
        
        // Filter Content (only visible when expanded)
        Column {
            id: filterContent
            anchors.fill: parent
            anchors.margins: 8
            anchors.topMargin: 38
            spacing: 6
            visible: galaxyFilterPanel.filterPanelExpanded
            
            // Compact Header
            Text {
                text: "FILTERS"
                color: "#FF7F50"
                font.bold: true
                font.pixelSize: 14
            }
            
            Rectangle { width: parent.width; height: 1; color: "#FF7F50"; opacity: 0.3 }
            
            // Compact Claim Status Filters
            Text {
                text: "Claim Status:"
                color: "#FFFFFF"
                font.bold: true
                font.pixelSize: 12
            }
            
            // Individual checkbox controls (safer than component for compatibility)
            Row {
                id: showUnclaimedCheck
                property bool checked: true  // Default to showing unclaimed systems
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "v"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "Unclaimed"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Row {
                id: showYourClaimsCheck
                property bool checked: true  // Default to showing your claims too
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "v"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "Your Claims"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Row {
                id: showOthersClaimsCheck
                property bool checked: false
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "✓"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "Others' Claims"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Row {
                id: showPotentialPOIsCheck
                property bool checked: false
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "✓"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "Potential POIs"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Row {
                id: showPOIsCheck
                property bool checked: false
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "✓"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "POIs"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Row {
                id: showDoneSystemsCheck
                property bool checked: false
                spacing: 8
                height: 20
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FF7F50"
                    border.width: 1
                    color: parent.checked ? "#FF7F50" : "transparent"
                    
                    Text {
                        text: "✓"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
                
                Text {
                    text: "Done Systems"
                    color: "#FFFFFF"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                            updateFilteredSystems()
                        }
                    }
                }
            }
            
            Rectangle { width: parent.width; height: 1; color: "#555555"; opacity: 0.5 }
            
            // Admin Mode Controls
            Text {
                text: "Admin Features:"
                color: "#FFFFFF"
                font.bold: true
                font.pixelSize: 12
                visible: edrhController.isAdmin || false
            }
            
            Row {
                id: showAllCommandersCheck
                property bool checked: false
                spacing: 8
                height: 20
                visible: edrhController.isAdmin || false
                
                Rectangle {
                    width: 14
                    height: 14
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 2
                    border.color: "#FFA500"
                    border.width: 1
                    color: parent.checked ? "#FFA500" : "transparent"
                    
                    Text {
                        text: "✓"
                        color: "#000000"
                        anchors.centerIn: parent
                        visible: parent.parent.checked
                        font.pixelSize: 10
                        font.bold: true
                    }
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                        }
                    }
                }
                
                Text {
                    text: "Show All Commander Locations"
                    color: "#FFA500"
                    font.pixelSize: 11
                    anchors.verticalCenter: parent.verticalCenter
                    
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            parent.parent.checked = !parent.parent.checked
                        }
                    }
                }
            }
            
            Rectangle { width: parent.width; height: 1; color: "#555555"; opacity: 0.5 }
            
            // Compact Categories Filter
            Text {
                text: "Categories:"
                color: "#FFFFFF"
                font.bold: true
                font.pixelSize: 12
            }
            
            // Compact category filter button
            Rectangle {
                id: categoryFilterBtn
                width: parent.width
                height: 24
                color: categoryMouseArea.pressed ? "#404040" : "#363636"
                border.color: "#FF7F50"
                border.width: 1
                radius: 4
                
                Text {
                    anchors.left: parent.left
                    anchors.leftMargin: 8
                    anchors.verticalCenter: parent.verticalCenter
                    text: filterManager.getSelectedCategoriesText()
                    font.pixelSize: 10
                    color: "#FFFFFF"
                    elide: Text.ElideRight
                    width: parent.width - 24
                }
                
                Text {
                    anchors.right: parent.right
                    anchors.rightMargin: 8
                    anchors.verticalCenter: parent.verticalCenter
                    text: categoryDropdown.visible ? "^" : "v"
                    font.pixelSize: 10
                    color: "#FF7F50"
                }
                
                MouseArea {
                    id: categoryMouseArea
                    anchors.fill: parent
                    onClicked: {
                        categoryDropdown.visible = !categoryDropdown.visible
                    }
                }
            }
            
            // Compact category dropdown
            Rectangle {
                id: categoryDropdown
                width: parent.width
                height: visible ? 120 : 0
                visible: false
                color: "#2A2A2A"
                radius: 4
                border.width: 1
                border.color: "#FF7F50"
                
                ScrollView {
                    anchors.fill: parent
                    anchors.margins: 4
                    clip: true
                    
                    Column {
                        width: parent.width
                        spacing: 1
                        
                        Repeater {
                            model: filterManager.availableCategories
                            
                            delegate: Rectangle {
                                readonly property bool isSeparator: modelData === "--- Richard's Stuff ---"
                                
                                width: parent.width
                                height: isSeparator ? 16 : 18
                                color: !isSeparator && categoryItemMouseArea.containsMouse ? "#505050" : "transparent"
                                radius: 2
                                
                                Row {
                                    visible: !isSeparator
                                    anchors.left: parent.left
                                    anchors.verticalCenter: parent.verticalCenter
                                    anchors.leftMargin: 4
                                    spacing: 4
                                    
                                    Rectangle {
                                        width: 10
                                        height: 10
                                        anchors.verticalCenter: parent.verticalCenter
                                        color: "transparent"
                                        border.color: "#FF7F50"
                                        border.width: 1
                                        radius: 1
                                        
                                        Rectangle {
                                            anchors.centerIn: parent
                                            width: 4
                                            height: 4
                                            color: "#FF7F50"
                                            radius: 1
                                            visible: filterManager.selectedCategories.includes(modelData)
                                        }
                                    }
                                    
                                    Text {
                                        text: modelData
                                        color: "#FFFFFF"
                                        font.pixelSize: 10
                                        anchors.verticalCenter: parent.verticalCenter
                                        elide: Text.ElideRight
                                        width: categoryDropdown.width - 20
                                    }
                                }
                                
                                // Separator
                                Rectangle {
                                    visible: isSeparator
                                    anchors.centerIn: parent
                                    width: parent.width - 8
                                    height: 1
                                    color: "#FF7F50"
                                    opacity: 0.5
                                }
                                
                                MouseArea {
                                    id: categoryItemMouseArea
                                    anchors.fill: parent
                                    hoverEnabled: !isSeparator
                                    enabled: !isSeparator
                                    
                                    onClicked: {
                                        if (!isSeparator) {
                                            filterManager.toggleCategory(modelData)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            // Compact System Count Display
            Rectangle { width: parent.width; height: 1; color: "#555555"; opacity: 0.5 }
            
            Text {
                text: "Systems: " + (root.filteredGalaxyMapSystems ? root.filteredGalaxyMapSystems.length : 0) + 
                      " / " + (edrhController && edrhController.galaxyMapSystems ? edrhController.galaxyMapSystems.length : 0)
                color: "#7ED321"
                font.pixelSize: 10
                font.bold: true
            }
            
            // Debug text to help troubleshoot
            Text {
                text: "Debug: Controller=" + (typeof edrhController !== 'undefined' ? "OK" : "Missing") +
                      " Data=" + (edrhController && edrhController.galaxyMapSystems ? "Available" : "Loading...")
                color: "#FFA500"
                font.pixelSize: 9
                visible: true // Set to false once working
            }
            

        }
    }

} 