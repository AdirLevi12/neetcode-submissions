class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int i = 0, j = size-1;
        int res = 0;
        while(i < j){
            int curr = min(heights[i], heights[j]) * (j-i);
            res = max(res, curr);
            if(heights[i] > heights[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }

    // time complexity - O(n)
    // space complexity - O(1)
};
