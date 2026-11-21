class Solution {
public:
    void backtracking(int open, int close, string& curr, vector<string>& res){
        if(open > close || open < 0){
            return;
        }
        if(!open && !close){
            res.push_back(curr);
            return;
        }
        curr.push_back('(');
        backtracking(open-1,close,curr,res);
        curr.pop_back();
        curr.push_back(')');
        backtracking(open,close-1,curr,res);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtracking(n,n,curr,res);
        return res;
    }
};
