class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> freq;
        for(int v: nums){
            freq[v]++;
        }

        vector<vector<int>> freq_vec(size);
        for(const auto& p : freq){
            freq_vec[p.second - 1].push_back(p.first);
        }

        vector<int> res;
        for(int i = size-1; i >= 0; i--){
            for(int v : freq_vec[i]){
                res.push_back(v);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }

    // time complexity = O(N)
    // space complexity = O(N)
};
