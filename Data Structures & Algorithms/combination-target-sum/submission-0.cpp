class Solution {
public:
    void backtracking(int i, vector<int>& curr, int target, const vector<int>& nums, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        
        if(i == nums.size()){
            if(target == 0){
                res.push_back(curr);
            }
            return;

        }
        backtracking(i+1, curr, target, nums, res);
        curr.push_back(nums[i]);
        backtracking(i, curr, target-nums[i], nums, res);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(0,curr,target,nums,res);
        return res;
    }
};
