class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1,false);
        dp[size] = true;
        for(int i = size-1; i >= 0; i--){
            for(string& word : wordDict){
                if(i + word.size() - 1 < size){
                    if(dp[i+word.size()] && s.substr(i,word.size()) == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};