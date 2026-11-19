class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int res = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty() && fresh > 0){
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++){
                pair<int,int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                for(const auto& dir : direction){
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row,col});
                    }
                }
            }
        }
        return fresh? -1 : res;       
    }
};
