#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        std::istringstream iss(text);
        std::vector<std::string> words;
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }

        int result = words.size();

        // Track broken letters (26 lowercase English letters)
        int broken[26] = {0};
        for (char c : brokenLetters) {
            broken[c - 'a'] = 1;
        }

        for (const auto& w : words) {
            for (char c : w) {
                if (broken[c - 'a']) {
                    result--;
                    break;
                }
            }
        }

        return result;
    }
};
