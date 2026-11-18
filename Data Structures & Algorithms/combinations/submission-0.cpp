class Solution {
public:
    void backtracking(int i, int n, int k, vector<int>& curr, vector<vector<int>>& res){
        if(curr.size() > k){
            return;
        }

        if(curr.size() == k){
            res.push_back(curr);
            return;
        }
        if(i == n + 1){
            return;
        }
        backtracking(i+1,n,k,curr,res);
        curr.push_back(i);
        backtracking(i+1,n,k,curr,res);
        curr.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(1, n, k, curr, res);
        return res;
    }
};