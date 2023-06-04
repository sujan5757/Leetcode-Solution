#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int minimizedStringLength(std::string s) {
        std::unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++)
            map[s[i]] = 1;
        return map.size();
    }
};
