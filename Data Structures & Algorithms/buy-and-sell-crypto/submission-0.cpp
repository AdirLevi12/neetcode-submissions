class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr_min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > curr_min){
                res = max(res, prices[i] - curr_min);
            }
            else{
                curr_min = prices[i];
            }
        }
        return res;
    }
    // time complexity - O(n)
    // space complexity - O(1)
};
