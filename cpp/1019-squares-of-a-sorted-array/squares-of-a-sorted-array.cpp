class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int l = 0;
        int r = nums.size() -1;
        
        for(int i=nums.size()-1;i>=0;i--){
            int num1 = abs(nums[l]);
            int num2 = abs(nums[r]);

            if(num2 > num1){
                result[i] = num2 * num2;
                r--;
            }
            else{
                result[i] = num1*num1;
                l++;
            }
        }
        return result;
    }
};