class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto [ch, count] : freq) {
            length += (count / 2) * 2; // take the even part
            if (count % 2 == 1) hasOdd = true; // mark that we have at least one odd
        }

        if (hasOdd) length += 1; // add one odd in the center
        return length;
    }
};

// class Solution {
// public:
//     int longestPalindrome(string s) {
//         int oddCount = 0;
//         unordered_map<char, int> ump;
//         for(char ch : s) {
//             ump[ch]++;
//             if (ump[ch] % 2 == 1)
//                 oddCount++;
//             else    
//                 oddCount--;
//         }
//         if (oddCount > 1)
//             return s.length() - oddCount + 1;
//         return s.length();
//     }
// };