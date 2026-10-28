class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c_set;
        int res = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while(c_set.find(s[i]) != c_set.end()){
                c_set.erase(s[left]);
                left++;
            }
            c_set.insert(s[i]);
            res = max(res, i - left + 1);
        }
        return res;
    }
    // time complexity = O(n);
    // space complexity = O(n)
};
