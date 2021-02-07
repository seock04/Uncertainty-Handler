class Solution {
public:
    int N, M;
    int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& mt) {
       
        M = mt.size();
        N = mt[0].size();
        
        for(int i =0;i<N; ++i){
            dp[M-1][i] = mt[M-1][i];
        }
        
        for(int i = M-2; i >= 0; --i){
            for(int j = 0;j < N; ++j){
                
                dp[i][j] = mt[i][j];
                int mn = mt[i+1][j];
                
                if(j-1 >= 0){
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
            result = min(dp[0][i], result);
        }
        
        return result;
    }

};