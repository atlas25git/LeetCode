class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle)!=string::npos?haystack.find(needle):-1;
    }
};