class Solution {
public:
    
    // Brute force - O(N^2)
    int maxProfit2(vector<int> &prices){
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++){
            int profit = 0;
            int buy = prices[i];
            for (int j = i; j < prices.size(); j++){
                int sell = prices[j];
                profit = sell - buy;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
    
    // Time complexity O(N)
    int maxProfit(vector<int>& prices) {
        // return maxProfit2(prices);
        int maxProfit = 0;
        int minBuy = prices[0];
        for (auto price : prices){
            minBuy = min(minBuy, price);
            int sell = price;
            int profit = sell - minBuy;
            if (profit > 0){
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};