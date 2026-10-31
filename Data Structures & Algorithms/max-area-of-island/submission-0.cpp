class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        return dfs(grid,i,j+1) + dfs(grid,i,j-1) + dfs(grid,i+1,j) + dfs(grid,i-1,j) + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid,i,j);
                    res = max(res,area);
                }
            }
        }
        return res;
    }
    // time complexity O(M*N)
    // space complexity O(M*N)
};
