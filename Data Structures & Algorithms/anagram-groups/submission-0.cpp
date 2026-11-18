class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group_anagrams;
        for(string& s : strs){
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            group_anagrams[s_copy].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& [key, val] : group_anagrams){
            res.push_back(val);
        }
        return res;
    }
};
