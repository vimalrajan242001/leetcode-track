class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    // If there's no attacks, poisoned time is 0
    if (timeSeries.empty()) return 0;
    
    int totalPoisonedTime = 0;
    
    // Iterate through all attacks except the last one
    for (int i = 0; i < timeSeries.size() - 1; i++) {
        // For each attack, take min of:
        // 1. Full duration of current poison
        // 2. Time difference to next attack
        // This handles overlapping cases
        totalPoisonedTime += min(duration, timeSeries[i + 1] - timeSeries[i]);
    }
    
    // Add the duration of the last attack
    // (it always runs full duration as there's no next attack to overlap)
    totalPoisonedTime += duration;
    
    return totalPoisonedTime;
}
};