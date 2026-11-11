class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size <= 2){
            return size;
        }
        int indx = 2;
        for(int i = 2; i < size; i++){
            if(nums[i] == nums[indx-1] && nums[i] == nums[indx-2]){
                continue;
            }
            nums[indx] = nums[i];
            indx++;
        }
        return indx;
    }
};