class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_indx = 0;
        for(char c : t){
            if(s[s_indx] == c){
                s_indx++;
            }
            if(s_indx == s.size()){
                return true;
            }
            
        }
        return false;
    }
};