class Solution {
public:
    int longestPalindrome(string s) {
        bool has_odd = false;
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        int res = 0;
        for(const auto& [key, val] : m){
            if(val % 2 == 1){
                has_odd = true;
            }
            res += (val / 2)*2;
        }
        return has_odd? res + 1 : res;
    }
};