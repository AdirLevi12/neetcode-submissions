class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < size; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int l = i+1, r = size-1;
            while(l < r){
                int curr_sum = nums[i] + nums[l] + nums[r];
                if(curr_sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l-1] == nums[l]){
                        l++;
                    }
                }
                else if(curr_sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return res;
    }
};
