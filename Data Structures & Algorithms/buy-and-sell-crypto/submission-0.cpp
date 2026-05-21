class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy=prices[0], maxProfit=0;
        for(int p:prices) {
            bestBuy=min(bestBuy, p);
            maxProfit=max(maxProfit, p-bestBuy);
        }
        return maxProfit;
    }
};
