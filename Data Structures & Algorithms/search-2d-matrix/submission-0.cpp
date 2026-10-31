class Solution {
public:
    int findRow(const vector<vector<int>>& matrix, int target){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, down = rows-1;
        while(top <= down){
            int mid = (top+down)/2;
            if(matrix[mid][0] <= target && matrix[mid][cols-1] >= target){
                return mid;
            }
            else if(matrix[mid][0] > target){
                down = mid-1;;
            }
            else{
                top = mid+1;
            }
        }
        return -1;
    }

    int findCol(const vector<int>& matrix, int target){
        int size = matrix.size();
        int left = 0, right = size-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(matrix[mid] == target){
                return mid;
            }
            if(matrix[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        if(row == -1){
            return false;
        }
        int col = findCol(matrix[row], target);
        if(col == -1){
            return false;
        }
        return true;
    }
    // time complexity O(log(m*n))
    // space complexity O(1)
};
