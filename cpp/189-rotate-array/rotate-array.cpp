// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;  // Normalize k
//         vector<int> res;

//         // Append last k elements in correct order
//         for (int i = n - k; i < n; i++) {
//             res.push_back(nums[i]);
//         }

//         // Append first n-k elements
//         for (int i = 0; i < n - k; i++) {
//             res.push_back(nums[i]);
//         }

//         nums = res;
//     }
// };

// Example:-1234567 ,k=3
// 1.first reverse the numbers form index 0 to n-k;
// ->4321 567
// 2.reverse the k elements from the last
// ->4321 765
// 3.now reverse the whole nums;
// ->5671234 Done Answer is here !!!!
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Normalize k

        // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};
