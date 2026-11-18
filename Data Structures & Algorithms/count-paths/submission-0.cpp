class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> arr(n,1);
        for(int i = 0; i < m-1; i++){
            for(int j = n-2; j >= 0; j--){
                arr[j] += arr[j+1];
            }
        }
        return arr[0];
    }
};
