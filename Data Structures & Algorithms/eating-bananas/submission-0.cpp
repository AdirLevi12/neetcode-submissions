class Solution {
public:
    bool checkRate(vector<int>& p, int h, int k){
        long long totalTime = 0;
        for(int v: p){
            totalTime += ceil(static_cast<double>(v) / k);
        }
        return totalTime <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_rate = INT_MIN;
        for(int n : piles){
            max_rate = max(max_rate,n);
        }
        int res = max_rate;
        int min_rate = 1;
        while(min_rate <= max_rate){
            int k = (min_rate + max_rate) / 2;
            bool result = checkRate(piles,h,k);
            if(result){
                res = k;
                max_rate = k-1;
            }
            else{
                min_rate = k+1;
            }
        }
        return res;
    }
};
