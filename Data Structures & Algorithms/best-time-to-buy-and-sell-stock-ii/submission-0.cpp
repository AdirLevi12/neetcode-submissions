class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int left = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[left]){
                res += prices[i]-prices[left];
                left = i;
            }
            else{
                left = i;
            }
        }
        return res;
    }
    // time complexity - O(N)
    // space complexity - O(1)
};