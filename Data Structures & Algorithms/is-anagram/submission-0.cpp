class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> s_freq;
        for(char c : s){
            s_freq[c]++;
        }
        for(char c : t){
            if(s_freq.find(c) == s_freq.end() || s_freq[c] == 0){
                return false;
            }
            s_freq[c]--;
        }
        return true;
    }

    // time complexity: O(s.size())
    // space complexity: O(s.size()) with 1 map. 

    // there is another solution: create 2 frequency map for each string and them compare
    // between them.
};
