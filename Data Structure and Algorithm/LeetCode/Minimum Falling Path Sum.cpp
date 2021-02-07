class Solution {
public:
    int N;
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& mt) {
       
        N = mt[0].size();
        memset(dp, -1, sizeof dp);
        
        for(int i =0;i<N; ++i){
            dp[N-1][i] = mt[N-1][i];
        }
        
        for(int i = N-2; i >= 0; --i){
            for(int j = 0;j < N; ++j){
                
                dp[i][j] = mt[i][j];
                int mn = mt[i+1][j];
                
                if(j-1 > 0){
                    mn = min(mn, mt[i+1][j-1]);
                }
                
                if(j+1 < N){
                    mn = min(mn, mt[i+1][j+1]);
                }
                
                dp[i][j] += mn;
            }
        }
        int result = INT_MAX;
        for(int i = 0; i<N; i++){
            result = (dp[0][i] < result) ? dp[0][i] : result;
        }
        
        return result;
    }

};