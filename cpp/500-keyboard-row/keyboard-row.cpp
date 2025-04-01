class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string firstrow = "qwertyuiopQWERTYUIOP";
        string secrow = "asdfghjklASDFGHJKL";
        string thirdrow = "zxcvbnmZXCVBNM";

        for (const string &word : words) {
            bool first = true, second = true, third = true;
            for (char c : word) {
                if (first && firstrow.find(c) == string::npos) {
                    first = false;
                }
                if (second && secrow.find(c) == string::npos) {
                    second = false;
                }
                if (third && thirdrow.find(c) == string::npos) {
                    third = false;
                }
            }
            if (first || second || third)
                ans.push_back(word);
        }
        return ans;
    }
};