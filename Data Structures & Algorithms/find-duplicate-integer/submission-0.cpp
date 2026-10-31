class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int absVal = abs(nums[i]);
            if(nums[absVal] < 0){
                return absVal;
            }
            nums[absVal] *= -1;
        }
        return 0;
    }
    // time complexity O(N)
    // space complexity O(1)
};
