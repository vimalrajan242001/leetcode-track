#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        // Count frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        // Create buckets where index = frequency
        // Max frequency can be nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : freqMap) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        // Gather top k frequent elements from buckets (from high freq to low)
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
