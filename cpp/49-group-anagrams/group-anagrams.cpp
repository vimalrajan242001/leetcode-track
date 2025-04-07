class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0) return ans;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(str);
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};