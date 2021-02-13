
//////below are very naive solution, it will give you time limit exceeded error
class Solution {
public:
    
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    int dp[101][101];
    
    int res = INT_MAX;
    int N, M;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid.size() == 0 or grid[0].size() == 0) return -1;
    
        N = grid.size();
        M = grid[0].size();
        
        if(grid[0][0] != 0 or grid[N-1][M-1] != 0) return -1;
        
        //memset(dp, -1, sizeof dp);        
        
        solve(grid, 0, 0, 1);
        
        if(res == INT_MAX) return -1;
        
        return res;
    }
    
    void solve(vector<vector<int>>& grid, int y, int x, int k)
    {
        if(y == N-1 and x == M-1){
            res = min(res, k);
        }
        
        
        
        for(int i = 0;i < 8; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            
            if(yy < 0 or yy >= N or xx < 0 or xx >= M) continue;
            
        
            if(grid[yy][xx] == 0 and k+1 < res){
                solve(grid, yy, xx, k+1);
            }
        }
        
    }
};
