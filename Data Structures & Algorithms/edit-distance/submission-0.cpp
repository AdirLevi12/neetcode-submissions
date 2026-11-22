class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size2+1, vector<int>(size1+1));
        for(int i = 0; i <= size1; i++){
            dp[size2][i] = size1-i;
        }
        for(int i = 0; i <= size2; i++){
            dp[i][size1] = size2-i;
        }
        for(int i = size2-1; i >= 0; i--){
            for(int j = size1-1; j >= 0; j--){
                if(word2[i] == word1[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
                }
            }
        }
        return dp[0][0];
    }
};