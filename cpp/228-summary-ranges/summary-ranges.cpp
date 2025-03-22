class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> res;
        if(nums.empty()){
            return res;
        }
        
        int start = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1] + 1){
                // If there's a range, format it properly
                if(start != nums[i - 1]){
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                } else {
                    res.push_back(to_string(start));
                }
                start = nums[i];
            }
        }

        // Handle the last range
        if(start != nums.back()){
            res.push_back(to_string(start) + "->" + to_string(nums.back()));
        } else {
            res.push_back(to_string(start));
        }

        return res;
    }
};
