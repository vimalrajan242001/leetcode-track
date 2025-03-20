// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> result(nums.size());
//         int l = 0;
//         int r = nums.size() -1;
        
//         for(int i=nums.size()-1;i>=0;i--){
//             int num1 = abs(nums[l]);
//             int num2 = abs(nums[r]);

//             if(num2 > num1){
//                 result[i] = num2 * num2;
//                 r--;
//             }
//             else{
//                 result[i] = num1*num1;
//                 l++;
//             }
//         }
//         return result;
//     }
// };

#pragma once
#include <mutex>
//low memory now.
class Solution {
public:
    static std::mutex dumb_lock;
    Solution(){
        //if this works to reduce memory cost I laugh.
        dumb_lock.lock();
    }
    inline vector<int>& sortedSquares(vector<int>& nums) {
        for(auto& i : nums){
            i *= i;
        }
        std::sort(nums.begin(), nums.end());
        dumb_lock.unlock();
        return nums;
    }
};

std::mutex Solution::dumb_lock = std::mutex();