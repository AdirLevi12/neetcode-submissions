class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int indx = 0;
        for(int n : nums){
            if(n != val){
                nums[indx] = n;
                indx++;
            }
        }
        return indx;
    }
    // time complexity - O(N);
    // space complexity - O(1);
};