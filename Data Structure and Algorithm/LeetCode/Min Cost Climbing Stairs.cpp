class Solution {
public:
    int fc[1001];
    int N;
    int minCostClimbingStairs(vector<int>& cost) {
        
        N = cost.size();
                
        fc[0] = cost[0];
        fc[1] = cost[1];
                
        for(int i = 2; i < N; i++){
            fc[i] = cost[i] + min(fc[i-1], fc[i-2]);
        }

        return min(fc[N-1], fc[N-2]);
    }
};
