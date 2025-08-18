import QtQuick 2.15

Item {
    id: filterManager
    
    // Filter state
    property var selectedCategories: ["All Categories"]
    property string systemTypeFilter: "All Systems"
    
    // Available categories loaded dynamically from EDRHController
    property var availableCategories: edrhController ? edrhController.availableCategories : ["All Categories"]
    
    // System type options
    property var systemTypeFilters: ["All Systems", "Claimed", "Unclaimed", "POI Only"]
    
    // Signals
    signal filtersChanged()
    signal categorySelectionChanged()
    signal requestPresetImages(bool includeRichard)
    
    // Watch for changes in available categories from controller
    Connections {
        target: edrhController
        function onAvailableCategoriesChanged() {
            // Update local property when controller categories change
            filterManager.availableCategories = edrhController.availableCategories
        }
    }
    
    // Filter functions
    function setSelectedCategories(categories) {
        selectedCategories = categories
        categorySelectionChanged()
        filtersChanged()
    }
    
    function setSystemTypeFilter(filter) {
        systemTypeFilter = filter
        filtersChanged()
    }
    
    function toggleCategory(category) {
        var categories = selectedCategories.slice() // Copy array
        
        if (category === "All Categories") {
            categories = ["All Categories"]
        } else {
            // Remove "All Categories" if selecting specific categories
            var allIndex = categories.indexOf("All Categories")
            if (allIndex > -1) {
                categories.splice(allIndex, 1)
            }
            
            // Toggle the specific category
            var index = categories.indexOf(category)
            if (index > -1) {
                categories.splice(index, 1)
            } else {
                categories.push(category)
            }
            
            // If no categories selected, default to "All Categories"
            if (categories.length === 0) {
                categories = ["All Categories"]
            }
        }
        
        setSelectedCategories(categories)
    }
    
    function resetFilters() {
        selectedCategories = ["All Categories"]
        systemTypeFilter = "All Systems"
        filtersChanged()
    }
    
    function matchesFilter(systemData) {
        if (!systemData || typeof systemData !== 'object') {
            return false
        }
        
        // Category filter - updated for multi-category support
        var categoryMatches = false
        if (selectedCategories.includes("All Categories")) {
            categoryMatches = true
        } else {
            // Check if system has categoryList (multi-category support)
            var systemCategoryList = systemData.categoryList || []
            var systemCategory = systemData.category || ""
            
            // If system has multiple categories, check each one
            if (systemCategoryList.length > 0) {
                for (var i = 0; i < selectedCategories.length; i++) {
                    for (var j = 0; j < systemCategoryList.length; j++) {
                        if (systemCategoryList[j] === selectedCategories[i]) {
                            categoryMatches = true
                            break
                        }
                    }
                    if (categoryMatches) break
                }
            } else {
                // Fallback to single category check for backward compatibility
                for (var i = 0; i < selectedCategories.length; i++) {
                    if (systemCategory === selectedCategories[i]) {
                        categoryMatches = true
                        break
                    }
                }
            }
        }
        
        if (!categoryMatches) {
            return false
        }
        
        // System type filter with null safety
        var claimed = systemData.claimed || false
        var claimedBy = systemData.claimedBy || ""
        var done = systemData.done || false
        var poi = systemData.poi || ""
        
        switch (systemTypeFilter) {
            case "All Systems":
                return true
            case "Claimed":
                return claimed
            case "Unclaimed":
                return !claimed
            case "POI Only":
                return poi === "POI"
            default:
                return true
        }
    }
    
    function getSelectedCategoriesText() {
        if (selectedCategories.includes("All Categories") || selectedCategories.length === 0) {
            return "All Categories"
        } else if (selectedCategories.length === 1) {
            return selectedCategories[0]
        } else {
            return selectedCategories.length + " Categories Selected"
        }
    }
    
    function getFilterSummary() {
        var summary = []
        
        if (!selectedCategories.includes("All Categories") && selectedCategories.length > 0) {
            summary.push(selectedCategories.length + " categories")
        }
        
        if (systemTypeFilter !== "All Systems") {
            summary.push(systemTypeFilter)
        }
        
        return summary.length > 0 ? summary.join(", ") : "No filters"
    }
} 