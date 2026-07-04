class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxAmount = prices[n-1];

        int result = 0;
        for (int i=n-2; i>=0; i--) {
            result = max(result, maxAmount - prices[i]);
            maxAmount = max(maxAmount, prices[i]);
        }

        return result;
    }
};
