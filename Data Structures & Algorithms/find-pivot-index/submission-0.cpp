class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum  = 0;
        for(int v: nums){
            sum += v;
        }
        int left_sum = 0;
        int right_sum = sum;
        for(int i = 0; i < nums.size(); i++){
            right_sum -= nums[i];
            if(left_sum == right_sum){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};