class Solution {
public:
    int climbStairs(int n) {
        int twoStep = 1;
        int oneStep = 1;
        int res = 1;

        for (int i = 2; i <= n; ++i) {
            res = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = res;
        }

        return res;
    }
};