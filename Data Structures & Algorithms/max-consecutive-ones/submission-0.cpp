class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int curr = 0;
        for(int v : nums){
            if(v == 1){
                curr++;
            }
            if(v == 0){
                res = max(curr,res);
                curr = 0;
            }
        }
        return res > curr? res : curr;
    }
};