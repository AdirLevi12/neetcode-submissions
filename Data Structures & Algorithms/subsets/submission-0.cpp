class Solution {
public:
    void help_func(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(sub);
            return;
        }
        help_func(nums, i+1, sub, res);
        sub.push_back(nums[i]);
        help_func(nums, i+1, sub, res);
        sub.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        help_func(nums, 0, sub, res);
        return res;
    }
};
