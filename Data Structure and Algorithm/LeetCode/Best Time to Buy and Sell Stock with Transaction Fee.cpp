class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        
        int nostock = 0;
        int onestock = -prices[0];
        for(int i = 1; i < size; ++i){
            nostock = max(nostock, onestock + prices[i] - fee);
            onestock = max(onestock, nostock - prices[i]);
        }
        
        return nostock;
    }
};
