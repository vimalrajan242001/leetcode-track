class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        int n = score.size();
        // Use map with greater<int> to sort scores in descending order
        map<int, int, greater<int>> scoreToIndex;
        
        // Fill the map with score -> index pairs
        for(int i = 0; i < n; i++) {
            scoreToIndex[score[i]] = i;
        }
        
        // Initialize result vector
        vector<string> result(n);
        
        // Iterate through the sorted map
        int rank = 0;
        for(const auto& pair : scoreToIndex) {
            int originalIndex = pair.second;
            if(rank == 0) {
                result[originalIndex] = "Gold Medal";
            }
            else if(rank == 1) {
                result[originalIndex] = "Silver Medal";
            }
            else if(rank == 2) {
                result[originalIndex] = "Bronze Medal";
            }
            else {
                result[originalIndex] = to_string(rank + 1);
            }
            rank++;
        }
        
        return result;  
    }
};