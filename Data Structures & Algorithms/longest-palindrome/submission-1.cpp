class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
            if(m[c] % 2 == 0){
                res += 2;
            }
        }
        return res < s.size()? res + 1 : res;
    }
};