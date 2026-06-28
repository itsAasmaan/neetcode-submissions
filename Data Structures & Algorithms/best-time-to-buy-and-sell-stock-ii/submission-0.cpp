class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;

        int currentStockPrice = prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (currentStockPrice < prices[i]) {
                result += prices[i] - currentStockPrice;
                currentStockPrice = prices[i];
            } else {
                currentStockPrice = min(currentStockPrice, prices[i]);
            }
        }

        return result;
    }
};