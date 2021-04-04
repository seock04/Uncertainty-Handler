
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


// below are using BFS
class Solution {
public:
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    vector<pair<int, int>> queue;
    int visited[101][101];
    int N, M;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid.size() == 0 or grid[0].size() == 0) return -1;
        N = grid.size();
        M = grid[0].size();
        //cout << "#size " << N << " " << M << "\n";
        if (grid[0][0] == 1 or grid[N - 1][M - 1] == 1) return -1;

        memset(visited, 0, sizeof visited);

        visited[0][0] = 1;
        queue.push_back({ 0,0 });
        int level = 0;

        while (!queue.empty()) {
            //cout << "level: " << level << "\n";
            int size = queue.size();
            level++;
            for (int i = 0; i < size; i++) {
                int cury = queue.begin()->first;
                int curx = queue.begin()->second;
                queue.erase(queue.begin());
                //cout << "#1 " << cury << " " << curx << "\n";
                if (cury == N - 1 and curx == M - 1) {
                    return level;
                }
                for (int d = 0; d < 8; d++) {
                    int yy = cury + dy[d];
                    int xx = curx + dx[d];

                    if (yy < 0 or yy >= N or xx < 0 or xx >= M) continue;                    
                    if(visited[yy][xx] or grid[yy][xx] == 1) continue;
                    
                    //cout << "#2 " << yy << " " << xx << "\n";
                    queue.push_back({ yy, xx });
                    visited[yy][xx] = 1;
                }
            }

        }

        return -1;

    }
};

