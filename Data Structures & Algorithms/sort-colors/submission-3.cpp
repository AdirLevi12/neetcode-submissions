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
                i--;
            }
        }
    }
};