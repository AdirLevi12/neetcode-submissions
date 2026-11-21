class Solution {
public:
    int climbStairs(int n) {
        int high = 1, low = 1;
        int res = 1;
        while(n-1 > 0){
            res = high + low;
            high = low;
            low = res;
            n--;
        }
        return res;
    }
};
