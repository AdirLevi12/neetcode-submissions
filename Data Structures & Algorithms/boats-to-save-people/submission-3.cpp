class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1;
        while(l <= r){
            res++;
            int curr_weight = people[l] + people[r];
            if(curr_weight <= limit){
                l++;
            }
            r--;
        }
        return res;
    }
};