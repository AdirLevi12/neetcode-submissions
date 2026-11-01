class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size()+1;
        int left = 0;
        int curr_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            while(curr_sum >= target){
                res = min(res,(i-left+1));
                curr_sum -= nums[left];
                left++;
            }
        }
        return res == nums.size()+1? 0 : res;
    }
};