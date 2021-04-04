class Solution {
public:
    int dp[1001];
    bool divisorGame(int N) {
        
        memset(dp, -1, sizeof dp);
        
        return solve(N);
    }
    
    bool solve(int N)
    {
        if(N == 1) return dp[N] = false;
        else{
            
            if(dp[N] != -1) return dp[N];
            
            for(int i = 1; i < N; i++){
                if(N % i == 0){
                    if(solve(N-1) == false) return dp[N] = 1;
                }
            }
        }
        
        return dp[N] = false;
    }
};
