class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp (n+1, 0);
        
        for(int i = 1; i <= n; ++i){
            int min_val = i;
            int j = 1, sq = 1;
            while(sq <= i){
                min_val = min(min_val, 1 + dp[i-sq]);
                j++;
                sq = j*j;
            }
            dp[i] = min_val;
        }
        
        return dp[n];
        
    }
    
};
