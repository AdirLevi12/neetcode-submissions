class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        res[0] = 1;
        int prefix = 1;
        for(int i = 0; i < size-1; i++){
            prefix *= nums[i];
            res[i+1] = prefix;
        }
        int suffix = 1;
        for(int i = size-1; i >= 1; i--){
            suffix *= nums[i];
            res[i-1] *= suffix;
        }
        return res;
    }
};
