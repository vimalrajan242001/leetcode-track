class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Normalize k
        vector<int> res;

        // Append last k elements in correct order
        for (int i = n - k; i < n; i++) {
            res.push_back(nums[i]);
        }

        // Append first n-k elements
        for (int i = 0; i < n - k; i++) {
            res.push_back(nums[i]);
        }

        nums = res;
    }
};
