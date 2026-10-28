class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int v : nums){
            if(s.find(v) != s.end()){
                return true;
            }
            s.insert(v);
        }
        return false;
    }
};