class Solution {
public:
    int calc_consecutive(const unordered_set<int>& s, const int v){
        int size = 1;
        while(s.find(v+size) != s.end()){
            size++;
        }
        return size;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int v : nums){
            s.insert(v);
        }
        int res = 0;
        for(int v : nums){
            if(s.find(v-1) == s.end()){
                int size = calc_consecutive(s, v);
                res = max(res,size);
            }
        }
        return res;
    }

    // time complexity O(N)
    // space complexity O(N)
};
