class Solution {
public:
    int strStr(string haystack, string needle) {
        int nSize = needle.size();

        if(nSize > haystack.size() ) return -1;

        for(int i= 0;i<haystack.size() - nSize + 1;i++){
            string temp = haystack.substr(i,nSize);

            if(temp == needle) return i;
        }

        return -1;
    }
};