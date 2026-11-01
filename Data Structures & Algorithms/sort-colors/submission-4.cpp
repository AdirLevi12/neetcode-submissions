class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for(int i = 0; i <= right; i++){
            if(nums[i] == 0){
                swap(nums,left,i);
                left++;
            }
            else if(nums[i] == 2){
                swap(nums,right,i);
                right--;
                // we decrease the i in this case because we need to check the new number in nums[i], we didnt check it before so we need to decied what to do with him.
                i--;
            }
        }
    }
    // time complexity - O(N)
    // space complexity - O(1)
};