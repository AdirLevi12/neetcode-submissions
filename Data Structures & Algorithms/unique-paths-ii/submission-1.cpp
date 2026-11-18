class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int rows = obstacleGrid.size();
       int cols = obstacleGrid[0].size();
       if(obstacleGrid[rows-1][cols-1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
       }
       obstacleGrid[rows-1][cols-1] = -1;
       for(int i = rows-1; i >= 0; i--){
            for(int j = cols-1; j >= 0; j--){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                int down = 0, right = 0;
                if(!(i+1 == rows || obstacleGrid[i+1][j] == 1)){
                    down = obstacleGrid[i+1][j];
                }
                if(!(j+1 == cols || obstacleGrid[i][j+1] == 1)){
                    right = obstacleGrid[i][j+1];
                }
                obstacleGrid[i][j] += down + right;
            }
       }
       return -obstacleGrid[0][0];
    }
};